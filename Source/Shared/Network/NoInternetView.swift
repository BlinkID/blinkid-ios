//
//  NoInternetView.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 09.01.2025..
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

public struct NoInternetView: View {
    let retryAction: () -> Void
    
    public init(retryAction: @escaping () -> Void) {
        self.retryAction = retryAction
    }
    
    public var body: some View {
        VStack(spacing: 20) {
            Image(systemName: "wifi.slash")
                .font(.system(size: 60))
                .foregroundColor(.gray)
                .accessibilityHidden(true)
            
            Text("No Internet Connection".localizedString)
                .font(.title2)
                .fontWeight(.semibold)
                .accessibilityAddTraits(.isHeader)
            
            Text("Please check your internet connection and try again".localizedString)
                .font(.body)
                .foregroundColor(.gray)
                .multilineTextAlignment(.center)
                .padding(.horizontal, 32)
            
            Button(action: {
                UIImpactFeedbackGenerator(style: .medium).impactOccurred()
                retryAction()
            }) {
                HStack(spacing: 12) {
                    Image(systemName: "arrow.clockwise")
                        .accessibilityHidden(true)
                    Text("Retry".localizedString)
                }
                .padding(.horizontal, 24)
                .padding(.vertical, 12)
                .background(Color.blue)
                .foregroundColor(.white)
                .cornerRadius(8)
            }
            .padding(.top, 8)
            .accessibilityLabel("Retry connection")
            .accessibilityHint("Double tap to attempt reconnecting to the internet")
            .minimumScaleFactor(0.5)
        }
        .dynamicTypeSize(...DynamicTypeSize.accessibility3)
        .padding(.horizontal, 24)
        .accessibilityElement(children: .contain)
        .accessibilityLabel("No Internet Connection Screen")
    }
}
