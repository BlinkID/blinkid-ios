//  Created by Toni Krešo on 11.11.2024.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

struct MessageContainer: View {
    private let theme: any UXThemeProtocol
    var text: String
    
    init(theme: any UXThemeProtocol, text: String ){
        self.theme = theme
        self.text = text
    }
    
    var body: some View {
        Text(text)
            .bold()
            .font(theme.reticleTooltipFont)
            .dynamicTypeSize(.medium ... .xxxLarge)
            .multilineTextAlignment(.center)
            .lineSpacing(4)
            .padding(.horizontal, 12)
            .padding(.vertical, 8)
            .foregroundStyle(Color.white)
            .background(Color(red: 102.0/255.0, green: 102.0/255.0, blue: 102.0/255.0, opacity: 0.9))
            .clipShape(
                RoundedRectangle(cornerRadius: 8.0)
            )
            .frame(maxWidth: 192.0)
    }
}
