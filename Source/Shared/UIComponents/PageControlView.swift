//  Created by Toni Krešo on 28.11.2024.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI
import UIKit

struct PageControlView: UIViewRepresentable {
    @Binding var currentPage: Int
    var numberOfPages: Int
    var currentPageIndicatorColor: UIColor
    var pageIndicatorColor: UIColor
    
    func makeUIView(context: Context) -> UIPageControl {
        let pageControl = UIPageControl()
        pageControl.numberOfPages = numberOfPages
        pageControl.currentPage = currentPage
        pageControl.currentPageIndicatorTintColor = currentPageIndicatorColor
        pageControl.pageIndicatorTintColor = pageIndicatorColor
        
        pageControl.addTarget(context.coordinator, action: #selector(Coordinator.pageControlChanged), for: .valueChanged)
        
        return pageControl
    }
    
    func updateUIView(_ uiView: UIPageControl, context: Context) {
        uiView.currentPage = currentPage
    }
    
    func makeCoordinator() -> Coordinator {
        return Coordinator(currentPage: $currentPage)
    }
    
    
    class Coordinator: NSObject {
        @Binding var currentPage: Int
        
        init(currentPage: Binding<Int>) {
            _currentPage = currentPage
        }
        
        @objc func pageControlChanged(sender: UIPageControl) {
            currentPage = sender.currentPage
        }
    }
}
