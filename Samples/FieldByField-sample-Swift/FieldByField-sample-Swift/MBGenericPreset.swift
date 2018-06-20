//
//  MBGenericPreset.swift
//  FieldByField-sample-Swift
//
//  Created by Jura Skrlec on 10/05/2018.
//  Copyright © 2018 Jura Skrlec. All rights reserved.
//

import Foundation
import MicroBlink

class MBGenericPreset {
    
    class func getPreset() -> [MBScanElement]? {
        var scanElements = [MBScanElement]()
        
        let rawElement = MBScanElement(identifier: "Raw", parser: MBRawParser())
        rawElement.localizedTitle = "Raw Text"
        rawElement.localizedTooltip = "Scan text"
        scanElements.append(rawElement)
        
        let ibanElement = MBScanElement(identifier: "IBAN", parser: MBIbanParser())
        ibanElement.localizedTitle = "IBAN"
        ibanElement.localizedTooltip = "Scan IBAN"
        scanElements.append(ibanElement)
        
        let priceElement = MBScanElement(identifier: "Price", parser: MBAmountParser())
        priceElement.localizedTitle = "Amount"
        priceElement.localizedTooltip = "Scan amount to pay"
        scanElements.append(priceElement)
        
        let dateElement = MBScanElement(identifier: "Date", parser: MBDateParser())
        dateElement.localizedTitle = "Date"
        dateElement.localizedTooltip = "Scan date"
        scanElements.append(dateElement)
        
        return scanElements
    }
}
