//  Created by Toni Krešo on 31.01.2025..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import SwiftUI

struct CameraPermissionView: View {
    var body: some View {
        VStack(spacing: 40) {
            Spacer()
            Image.noCameraAccessImage
                .resizable()
                .scaledToFit()
                .frame(width: 100, height: 100)
            Text("mb_camera_permission_required".localizedString)
                .foregroundStyle(.black)
                .font(.system(size: 20))
            Button {
                if let url = URL(string: UIApplication.openSettingsURLString) {
                    UIApplication.shared.open(url)
                }
            } label: {
                Text("mb_enable_camera".localizedString)
                    .foregroundStyle(.white)
                    .font(.system(size: 17))
            }
            .padding(.horizontal, 20)
            .padding(.vertical, 10)
            .background(
                Color.blue
            )
            .cornerRadius(30)
            Spacer()
        }
        .padding()
        .frame(maxWidth: .infinity)
        .background(
            Color.white.ignoresSafeArea()
        )
    }
}

#Preview {
    CameraPermissionView()
}
