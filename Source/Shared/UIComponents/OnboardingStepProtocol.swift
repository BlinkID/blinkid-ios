//  Created by Toni Krešo on 22.11.2024.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

public protocol OnboardingStepProtocol: CaseIterable, Identifiable, Hashable {
    var image: Image { get }
    
    var title: String { get }
    
    var description: String { get }
}
