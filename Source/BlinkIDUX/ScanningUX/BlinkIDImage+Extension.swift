//  Created by Toni Kreso on 11.02.2026..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import SwiftUI

// custom images
extension Image {
    static var frontIdImage: Image {
        Image("front_id", bundle: Bundle.frameworkBundle)
    }
    
    static var backIdImage: Image {
        Image("back_id", bundle: Bundle.frameworkBundle)
    }
    
    static var allDetailsVisibleImage: Image {
        Image("all_details_visible", bundle: Bundle.frameworkBundle)
    }
    
    static var allFieldsVisibleImage: Image {
        Image("all_fields_visible", bundle: Bundle.frameworkBundle)
    }
    
    static var harshLightImage: Image {
        Image("harsh_light", bundle: Bundle.frameworkBundle)
    }
    
    static var keepStillImage: Image {
        Image("keep_still", bundle: Bundle.frameworkBundle)
    }
    
    static var passportBottomImage: Image {
        Image("passport_bottom", bundle: Bundle.frameworkBundle)
    }
    
    static var passportHighlightImage: Image {
        Image("passport_highlight", bundle: Bundle.frameworkBundle)
    }
    
    static var passportTopImage: Image {
        Image("passport_top", bundle: Bundle.frameworkBundle)
    }
}
