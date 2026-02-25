//  Created by Toni Krešo on 13.02.2026.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import Combine
import Foundation

internal let stateCountingDuration = 1.5

public protocol ReticleStateMachineProtocol: ObservableObject {
    associatedtype ReticleStateType: ReticleStateProtocol
    
    var reticleState: ReticleStateType { get set }
    var fallbackState: ReticleStateType { get set }
    var lastReticleStateChange: TimeInterval { get set }
    var eventCounter: [ReticleStateType: Int] { get set }
    var reticleStateIsInterruptible: Bool { get set }
    func nextState(state: ReticleStateType, force: Bool) -> Bool
    func calculateState(using mostFrequentState: ReticleStateType) -> ReticleStateType
    func setInitialState()
    func calculateRemainingTime(stateDuration: Double?) -> Double
}

extension ReticleStateMachineProtocol {
    public func nextState(state: ReticleStateType, force: Bool = false) -> Bool {
        let timeLeft = calculateRemainingTime()
        
        guard timeLeft < 0 || force else {
            if timeLeft <= stateCountingDuration {
                eventCounter[state, default: 0] += 1
            }
            return false
        }
        
        let newState: ReticleStateType
        
        if !force,
           let (mostFrequentState, _) = eventCounter.max(by: { $0.value < $1.value }) {
            newState = calculateState(using: mostFrequentState)
        } else {
            newState = state
        }
        
        reticleState = newState
        reticleStateIsInterruptible = !force
        
        if reticleState.canBeFallback {
            fallbackState = reticleState
        }
        
        lastReticleStateChange = Date().timeIntervalSince1970
        eventCounter.removeAll()
        
        return true
    }
    
    public func calculateRemainingTime(stateDuration: Double? = nil) -> Double {
        let currentTime = Date().timeIntervalSince1970
        let elapsedTime = currentTime - lastReticleStateChange
        
        if reticleStateIsInterruptible,
           let stateDuration = stateDuration {
            return stateDuration - elapsedTime
        } else {
            return reticleState.duration - elapsedTime
        }
    }
    
    public func setInitialState() {
        reticleState = .initialState
        reticleStateIsInterruptible = false
        fallbackState = reticleState
        lastReticleStateChange = Date().timeIntervalSince1970
        eventCounter.removeAll()
    }
}
