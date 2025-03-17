//
//  BlinkIDResultState.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 19.02.2025..
//


#if canImport(BlinkIDVerify)
import BlinkIDVerify
#elseif canImport(BlinkID)
import BlinkID
#endif

public struct BlinkIDResultState {
    public let scanningResult: BlinkIDScanningResult?
}
