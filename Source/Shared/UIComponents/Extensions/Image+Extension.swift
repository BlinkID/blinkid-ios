//  Created by Toni Krešo on 22.11.2024.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

// custom images
extension Image {
    static var checkmarkImage: Image {
        Image("mb_checkmark", bundle: Bundle.frameworkBundle)
    }
    
    static var noCameraAccessImage: Image {
        Image("no_camera_access", bundle: Bundle.frameworkBundle)
    }
    
    static var demoOverlayImage: Image {
        Image("demo_overlay", bundle: Bundle.frameworkBundle)
    }
    
    static var productionOverlayImage: Image {
        Image("production_overlay", bundle: Bundle.frameworkBundle)
    }
}

// custom modifiers
extension Image {
    func OnboardingImageModifier() -> some View {
        self
            .resizable()
            .aspectRatio(1.0, contentMode: .fit)
            .clipShape(Circle())
    }
}
