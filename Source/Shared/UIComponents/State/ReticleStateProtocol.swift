//  Created by Toni Krešo on 13.02.2026..
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

public protocol ReticleStateProtocol: Equatable, Hashable {
    var text: String? { get }
    var duration: Double { get }
    var shouldExpire: Bool { get }
    var canBeFallback: Bool { get }
    var isErrorState: Bool { get }
    static var initialState: Self { get }
    static var inactiveState: Self { get }
    var reticleStateAppearance: ReticleStateAppearance { get }
}
