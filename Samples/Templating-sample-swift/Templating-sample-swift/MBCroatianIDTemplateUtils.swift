//
//  MBCroatianIDTemplateUtils.swift
//  Templating-sample-swift
//
//  Created by Jura Skrlec on 10/05/2018.
//  Copyright © 2018 Microblink. All rights reserved.
//

import UIKit
import MicroBlink

class MBCroatianIDTemplateUtils: NSObject {
    
    class func croatianCharsWhitelist() -> Set<MBOcrCharKey> {
        // initialize new char whitelist
        var charWhitelist = Set<MBOcrCharKey>()
        // Add chars 'A'-'Z'
        for val in UnicodeScalar("A").value...UnicodeScalar("Z").value {
            charWhitelist.insert(MBOcrCharKey(code: Int32(val), font: MBOcrFont.OCR_FONT_ANY))
        }
        
        charWhitelist.insert(MBOcrCharKey(code: Int32(UnicodeScalar("Š").value), font:  MBOcrFont.OCR_FONT_ANY))
        charWhitelist.insert(MBOcrCharKey(code: Int32(UnicodeScalar("Ž").value), font:  MBOcrFont.OCR_FONT_ANY))
        charWhitelist.insert(MBOcrCharKey(code: Int32(UnicodeScalar("Č").value), font:  MBOcrFont.OCR_FONT_ANY))
        charWhitelist.insert(MBOcrCharKey(code: Int32(UnicodeScalar("Ć").value), font:  MBOcrFont.OCR_FONT_ANY))
        charWhitelist.insert(MBOcrCharKey(code: Int32(UnicodeScalar("Đ").value), font:  MBOcrFont.OCR_FONT_ANY))
        
        return charWhitelist
    }

}
