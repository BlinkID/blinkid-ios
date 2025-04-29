//
//  CameraFrameAnalyzer.swift
//  BlinkIDUX
//
//  Created by Jura Skrlec on 23.01.2025..
//

import Foundation
import AVFoundation
import CoreVideo

#if canImport(BlinkIDVerify)
import BlinkIDVerify
#elseif canImport(BlinkID)
import BlinkID
#endif

import UIKit

public actor BlinkIDEventStream: EventStream {
    private let events: AsyncStream<[UIEvent]>
    private let continuation: AsyncStream<[UIEvent]>.Continuation
    
    public init() {
        var continuation: AsyncStream<[UIEvent]>.Continuation!
        self.events = AsyncStream { continuation = $0 }
        self.continuation = continuation
    }
    
    /// Sends UI events to the stream.
    /// - Parameter events: Array of UI events to be processed
    public func send(_ events: [UIEvent]) {
        continuation.yield(events)
    }
    
    /// The underlying async stream of UI events.
    public var stream: AsyncStream<[UIEvent]> {
        events
    }
}

/// Protocol used to accept or reject classes based on country, region, and document type
public protocol BlinkIDClassFilter {
    func classAllowed(classInfo: BlinkIDSDK.DocumentClassInfo) -> Bool
}

public actor BlinkIDAnalyzer: CameraFrameAnalyzer {
    
    public typealias Event = UIEvent
    
    public typealias Result = ScanningResult<BlinkIDScanningResult, BlinkIDScanningAlertType>
    public typealias Frame = CameraFrame
    
    private let session: BlinkIDSession
    private let eventStream: BlinkIDEventStream
    private let translator: BlinkIDUXTranslator = BlinkIDUXTranslator()
    private var scanningDone = false
    private var paused = false
    private var resultContinuation: CheckedContinuation<Result, Never>?
    private var stepTimeoutDuration: TimeInterval
    private var timerTask: Task<Void, Never>?
    private var classFilter: (any BlinkIDClassFilter)?
    
    /// Creates a new document verification analyzer.
    /// - Parameters:
    ///   - sdk: The document verification SDK instance
    ///   - captureSessionSettings: Settings for the capture session
    ///   - eventStream: Stream to receive UI events during scanning
    ///   - classFilter: Class filter to filter document classes based on country, region, and document type
    public init(
        sdk: BlinkIDSdk,
        blinkIdSessionSettings: BlinkIDSessionSettings = BlinkIDSessionSettings(inputImageSource: .video),
        eventStream: BlinkIDEventStream,
        classFilter: (any BlinkIDClassFilter)? = nil
    ) async throws {
        self.session = try await sdk.createScanningSession(sessionSettings: blinkIdSessionSettings)
        self.eventStream = eventStream
        self.stepTimeoutDuration = blinkIdSessionSettings.stepTimeoutDuration
        self.classFilter = classFilter
    }
        
    /// Processes a camera frame for document analysis.
    /// - Parameter image: The camera frame to analyze
    public func analyze(image: Frame) async {
        guard !paused else { return }
        
        if timerTask == nil {
            startTimer(stepTimeoutDuration)
        }
        
        let inputImage = InputImage(cameraFrame: image)
        
        let frameProcessResult = await session.process(inputImage: inputImage)
        
        if let classInfo = frameProcessResult.processResult?.inputImageAnalysisResult.documentClassInfo,
            !classInfo.isEmpty(),
           let filter = classFilter {
            if !filter.classAllowed(classInfo: classInfo) {
                /// - Note: scanInterrupted returns alert type in continuation which results in presenting an alert.
                ///         Presening an alert results in paused scanning, which is resumed and reset on alert dismiss.
                ///                                                          (4.3.2025. Toni Kreso)
                scanInterrupted(with: .disallowedClass)
                return
            }
        }
        
        let events = translator.translate(frameProcessResult: frameProcessResult, session: session)
        if events.contains(.requestDocumentSide(side: .back)) {
            timerTask?.cancel()
        }
        
        await eventStream.send(events)
        
        if frameProcessResult.processResult?.resultCompleteness.scanningStatus == .documentScanned {
            guard !scanningDone else { return }
            scanningDone = true
            Task { @ProcessingActor in
                let sessionResult = session.getResult()
                await finishScanning(with: .completed(sessionResult))
            }
        }
        
    }
    
    private func finishScanning(with result: ScanningResult<BlinkIDScanningResult, BlinkIDScanningAlertType>) {
        timerTask?.cancel()
        resultContinuation?.resume(returning: result)
        resultContinuation = nil
    }
    
    /// Cancels the current document scanning session.
    public func cancel() {
        self.session.cancelActiveProcessing()
    }
    
    /// Returns the final result of the scanning session.
    public func result() async -> ScanningResult<BlinkIDScanningResult, BlinkIDScanningAlertType> {
        await withCheckedContinuation { continuation in
            self.resultContinuation = continuation
        }
    }
    
    /// Pauses the document analysis.
    public func pause() {
        self.paused = true
        self.cancel()
        timerTask?.cancel()
    }
    
    /// Resumes the document analysis after being paused.
    public func resume() {
        self.paused = false
        self.session.resumeActiveProcessing()
        startTimer(stepTimeoutDuration)
    }
    
    /// Restarts the document analysis after being paused.
    public func restart() throws {
        Task { @ProcessingActor in
            try self.session.reset()
        }
        translator.resetState()
        resume()
    }
    
    public func end() async {
        pause()
        resultContinuation?.resume(returning: .ended)
        resultContinuation = nil
    }
    
    /// Stream of UI events generated during document analysis.
    nonisolated public var events: any EventStream<UIEvent> {
        eventStream
    }
    
    private func startTimer(_ interval: TimeInterval) {
        guard interval > 0.0 else { return }
        timerTask = Task() { [weak self] in
            while !Task.isCancelled {
                guard let self else { return }
                let nanoseconds = UInt64(interval * Double(NSEC_PER_SEC))
                try? await Task.sleep(nanoseconds: nanoseconds)
                if !Task.isCancelled {
                    await scanInterrupted(with: .timeout)
                }
            }
        }
    }
    
    private func scanInterrupted(with alertType: BlinkIDScanningAlertType) {
        pause()
        resultContinuation?.resume(returning: .interrupted(alertType))
        resultContinuation = nil
    }
}

