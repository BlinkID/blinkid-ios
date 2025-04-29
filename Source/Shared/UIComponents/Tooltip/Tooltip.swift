//
//  Tooltip.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 01.04.2025..
//

import SwiftUI

struct ToolTipView: View {
    var message: String
    var foregroundColor: Color
    var backgroundColor: Color
    
    var body: some View {
        VStack(alignment: .trailing, spacing: 0) {
            Text(message)
                .foregroundColor(foregroundColor)
                .padding(8)
                .background(backgroundColor)
                .cornerRadius(4)
                .fixedSize(horizontal: false, vertical: true)
            HStack {
                Spacer()
                ReverseArrowShape()
                    .fill(backgroundColor)
                    .frame(width: 14, height: 10)
                Spacer()
                    .frame(width: 4)
            }

        }
    }
}

struct ArrowShape: Shape {
    func path(in rect: CGRect) -> Path {
        var path = Path()
        
        path.move(to: CGPoint(x: rect.midX, y: rect.minY))
        path.addLine(to: CGPoint(x: rect.maxX, y: rect.maxY))
        path.addLine(to: CGPoint(x: rect.minX, y: rect.maxY))
        path.closeSubpath()
        
        return path
    }
}

struct ReverseArrowShape: Shape {
    func path(in rect: CGRect) -> Path {
        var path = Path()
        
        path.move(to: CGPoint(x: rect.midX, y: rect.maxY))
        path.addLine(to: CGPoint(x: rect.maxX, y: rect.minY))
        path.addLine(to: CGPoint(x: rect.minX, y: rect.minY))
        path.closeSubpath()
        
        return path
    }
}
