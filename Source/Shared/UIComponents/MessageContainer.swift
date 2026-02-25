//  Created by Toni Krešo on 11.11.2024.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

struct MessageContainer<ReticleStateMachineType: ReticleStateMachineProtocol>: View {
    private let theme: any UXThemeProtocol
    @ObservedObject private var stateMachine: ReticleStateMachineType
    
    init(theme: any UXThemeProtocol, stateMachine: ReticleStateMachineType){
        self.theme = theme
        self.stateMachine = stateMachine
    }
    
    var body: some View {
        if let text = stateMachine.reticleState.text?.localizedString {
            Text(text)
                .bold()
                .font(theme.reticleTooltipFont)
                .dynamicTypeSize(.medium ... .xxxLarge)
                .multilineTextAlignment(.center)
                .lineSpacing(4)
                .padding(.horizontal, 12)
                .padding(.vertical, 8)
                .foregroundStyle(Color.white)
                .background(Color(red: 102.0/255.0, green: 102.0/255.0, blue: 102.0/255.0, opacity: 0.3))
                .clipShape(
                    RoundedRectangle(cornerRadius: 8.0)
                )
                .accessibilityLabel(text)
                .accessibilitySortPriority(4)
        }
    }
}
