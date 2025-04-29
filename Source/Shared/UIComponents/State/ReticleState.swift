//  Created by Toni Krešo on 13.11.2024.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

protocol ReticleStateProtocol: Equatable {
    var text: String? { get }
    var duration: Double { get }
    var shouldExpire: Bool { get }
}

public enum ReticleState: ReticleStateProtocol {
    case front
    case back
    case barcode
    case detecting
    case flip
    case error(String)
    case inactive
    case passport(String)
    case inactiveWithMessage(String)
    
    var text: String? {
        switch self {
        case .front:
            return "mb_front_instructions"
        case .back:
            return "mb_back_instructions"
        case .barcode:
            return "mb_back_instructions_barcode"
        case .flip:
            return "mb_camera_flip_document"
        case .error(let message):
            return message
        case .detecting, .inactive:
            return nil
        case .passport(let message):
            return message
        case .inactiveWithMessage(let message):
            return message
        }
    }
    
    var duration: Double {
        switch self {
        case .front, .back, .barcode:
            1.0
        case .detecting:
            1.5
        case .error(_):
            2.0
        case .flip, .inactive:
            0.0
        case .passport(_), .inactiveWithMessage(_):
            2.0
        }
    }
    
    var shouldExpire: Bool {
        switch self {
        case .front, .back, .detecting, .inactive, .flip, .barcode:
            return false
        case .error(_):
            return true
        case .passport(_), .inactiveWithMessage(_):
            return false
        }
    }
}
