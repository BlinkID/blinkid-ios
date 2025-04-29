//
//  Toast.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 02.04.2025..
//
import SwiftUI

struct Toast: View {
    let message: String
    let isShowing: Bool
    let duration: Double
    let backgroundColor: Color
    let textColor: Color
    let onDismiss: () -> Void
    
    @State private var opacity: Double = 0
    
    init(
        message: String,
        isShowing: Bool,
        duration: Double = 3.0,
        backgroundColor: Color = Color.black.opacity(0.8),
        textColor: Color = .white,
        onDismiss: @escaping () -> Void
    ) {
        self.message = message
        self.isShowing = isShowing
        self.duration = duration
        self.backgroundColor = backgroundColor
        self.textColor = textColor
        self.onDismiss = onDismiss
    }
    
    var body: some View {
        ZStack {
            if isShowing {
                VStack {
                    Spacer()
                    
                    HStack {
                        Text(message)
                            .padding()
                            .foregroundColor(textColor)
                            .multilineTextAlignment(.leading)
                    }
                    .background(
                        Rectangle()
                            .fill(backgroundColor)
                            .cornerRadius(4)
                    )
                    .padding(.horizontal, 20)
                    .padding(.bottom, 20)
                    .opacity(opacity)
                    .onAppear {
                        withAnimation(.easeIn(duration: 0.3)) {
                            self.opacity = 1.0
                        }
                        
                        DispatchQueue.main.asyncAfter(deadline: .now() + duration) {
                            withAnimation(.easeOut(duration: 0.3)) {
                                self.opacity = 0.0
                            }
                            
                            DispatchQueue.main.asyncAfter(deadline: .now() + 0.3) {
                                self.onDismiss()
                            }
                        }
                    }
                }
            }
        }
        .animation(.easeInOut, value: isShowing)
    }
}

struct ToastModifier: ViewModifier {
    @Binding var isShowing: Bool
    let message: String
    let duration: Double
    let backgroundColor: Color
    let textColor: Color
    
    func body(content: Content) -> some View {
        ZStack {
            content
            
            Toast(
                message: message,
                isShowing: isShowing,
                duration: duration,
                backgroundColor: backgroundColor,
                textColor: textColor
            ) {
                isShowing = false
            }
        }
    }
}

extension View {
    func toast(
        isShowing: Binding<Bool>,
        message: String,
        duration: Double = 3.0,
        backgroundColor: Color = Color.black.opacity(0.8),
        textColor: Color = .white
    ) -> some View {
        self.modifier(
            ToastModifier(
                isShowing: isShowing,
                message: message,
                duration: duration,
                backgroundColor: backgroundColor,
                textColor: textColor
            )
        )
    }
}
