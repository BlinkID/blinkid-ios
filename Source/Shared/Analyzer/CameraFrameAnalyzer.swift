//  Created by Jura Skrlec on 13.02.2025.
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.

public protocol ScanningResultProtocol: Sendable {
    associatedtype Result: Sendable
    nonisolated var scanResult: Result? { get }
}

/// Result of a document scanning session.
public enum ScanningResult<T: Sendable, U: Sendable>: ScanningResultProtocol {
        
    public typealias Result = T
    
    /// Scanning completed successfully with captured document data.
    case completed(T)
    /// Scanning was interrupted.
    case interrupted(U)
    /// Scanning was cancelled by the user or system.
    case cancelled
    /// Scanning has ended.
    case ended
    
    public var scanResult: T? {
        switch self {
        case .completed(let result): return result
        case .interrupted(_), .cancelled, .ended: return nil
        }
    }
}

/// Protocol for streaming events during document processing.
public protocol EventStream<Event>: Sendable {
    associatedtype Event: Sendable
    /// Asynchronous stream of UI events
    var stream: AsyncStream<[Event]> { get async }
}

/// A protocol that represents the interface to the features of Microblink's analyzer.
public protocol CameraFrameAnalyzer<Frame, Event> : Sendable {
    
    associatedtype Result: ScanningResultProtocol
    associatedtype Frame: Sendable
    associatedtype Event: Sendable
    
    /// Analyze the ``CameraFrame``
    func analyze(image: Frame) async
    
    /// Cancel ``CameraFrame`` analyzation.
    func cancel() async
    
    /// Pause ``CameraFrame`` analyzation.
    func pause() async
    
    /// Resume ``CameraFrame`` analyzation.
    func resume() async
    
    /// Restart ``CameraFrame`` analyzation.
    func restart() async throws
    
    /// End ``CameraFrame`` analyzation.
    func end() async
    
    /// Get analyzer result when analyzer is finished.
    func result() async -> Result
    
    /// Get stream of UI Events.
    var events: any EventStream<Event> { get }
}

/// Represents passport rotation orientation depending on View interface and a document card rotation property.
///
/// See ``DocumentRotation``.
public enum PassportOrientation: Sendable, Equatable {
    case none
    case left90
    case right90
}

/// Represents different sides of a document during the scanning process.
public enum DocumentSide: Sendable, Equatable {
    /// Front side of the document
    case front
    /// Back side of the document
    case back
    /// Barcode region of the document
    case barcode
    /// Document is passport
    case passport(PassportOrientation)
}
