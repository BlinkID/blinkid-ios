//
//  NetworkMonitor.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 07.01.2025..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import Network
import Combine

/// Monitors network connectivity status using NWPathMonitor.
@MainActor
public class NetworkMonitor: ObservableObject {
    private let monitor = NWPathMonitor()
    private let queue = DispatchQueue(label: "com.microblink.networkmonitor")
    
    /// Current network connection status.
    /// True if the device has an active internet connection.
    @Published public var isConnected = true
    
    /// Indicates if the device is currently offline.
    /// True when there is no active internet connection.
    public var isOffline: Bool {
        !isConnected
    }
    
    public init() {
        setupMonitor()
    }
    
    deinit {
        monitor.cancel()
    }
    
    private func setupMonitor() {
        monitor.pathUpdateHandler = { [weak self] path in
            guard let self else { return }
            Task { @MainActor in
                self.isConnected = path.status == .satisfied
            }
        }
        
        monitor.start(queue: queue)
    }
}
