//
//  SwiftCxxBridge.hpp
//  BlinkID
//
//  Created by Jura Skrlec on 20.01.2025..
//

#pragma once

// missing in Inputs.hpp within runner, so until fixed package gets propagated, this include is needed here
#include <tuple>

#import "Frame/InputImage.hpp"
#import "BlinkID/NativeBlinkIDScanningSession.hpp"
#import "NativeBlinkId.hpp"
#import "License/NativeLicenseProvider.hpp"
