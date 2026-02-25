//  Created by Toni Krešo on 13.02.2026..
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import Combine
import Foundation

public class ReticleStateMachine: ReticleStateMachineProtocol {
    public typealias ReticleStateType = ReticleState
    
    @Published public var reticleState: ReticleState
    public var fallbackState: ReticleState
    public var lastReticleStateChange: TimeInterval
    public var eventCounter: [ReticleState : Int]
    public var reticleStateIsInterruptible: Bool
    private var lastPassportErrorOrientation: PassportOrientation
    
    public init() {
        self.reticleState = .initialState
        self.fallbackState = .initialState
        self.lastReticleStateChange = Date().timeIntervalSince1970
        self.eventCounter = [:]
        self.reticleStateIsInterruptible = false
        self.lastPassportErrorOrientation = .none
    }
    
    public func calculateState(using mostFrequentState: ReticleState) -> ReticleState {
        if mostFrequentState == .error("mb_scanning_wrong_page_top") {
            lastPassportErrorOrientation = .none
        } else if mostFrequentState == .error("mb_scanning_wrong_page_left") {
            lastPassportErrorOrientation = .left90
        } else if mostFrequentState == .error("mb_scanning_wrong_page_right") {
            lastPassportErrorOrientation = .right90
        }

        if case .passport(let message) = mostFrequentState {
            if message == "mb_instructions_scan_barcode_last_page".localizedString {
                return ReticleState.passport("mb_instructions_scan_barcode_last_page".localizedString)
            } else {
                switch lastPassportErrorOrientation {
                case .none:
                    return ReticleState.passport("mb_top_page_instructions".localizedString)
                case .left90:
                    return ReticleState.passport("mb_left_page_instructions".localizedString)
                case .right90:
                    return ReticleState.passport("mb_right_page_instructions".localizedString)
                }
            }
        } else {
            return mostFrequentState
        }
    }
}
