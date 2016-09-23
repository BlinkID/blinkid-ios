//
//  PPCameraOverlayViewController.swift
//  pdf417-sample-Swift
//
//  Created by Dino on 18/12/15.
//  Copyright © 2015 Dino. All rights reserved.
//

import MicroBlink

class PPCameraOverlayViewController : PPOverlayViewController {

    var torchOn: Bool = false;

    override func viewDidLoad() {
        self.scanningRegion = CGRect(origin: CGPoint(x: 0.15, y: 0.4), size: CGSize(width: 0.7, height: 0.2))
    }
    
    @IBAction func didTapClose(_ sender: AnyObject) {
        (self.containerViewController as! PPOverlayContainerViewController).overlayViewControllerWillCloseCamera(self)
    }

    @IBAction func didTapTorch(_ sender: AnyObject) {
        self.torchOn = (self.containerViewController as! PPOverlayContainerViewController).isTorchOn()
        self.torchOn = !self.torchOn
        if((self.containerViewController as! PPOverlayContainerViewController).overlayViewControllerShouldDisplayTorch(self)) {
            (self.containerViewController as! PPOverlayContainerViewController).overlayViewController(self, willSetTorch: self.torchOn)
        }
    }
}
