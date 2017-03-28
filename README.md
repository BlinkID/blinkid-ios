<p align="center" >
  <img src="https://raw.githubusercontent.com/wiki/blinkid/blinkid-ios/Images/logo-microblink.png" alt="MicroBlink" title="MicroBlink">
</p>

[![Build Status](https://travis-ci.org/BlinkID/blinkid-ios.png)](https://travis-ci.org/BlinkID/blinkid-ios.png)
[![Pod Version](http://img.shields.io/cocoapods/v/PPBlinkID.svg?style=flat)](http://cocoadocs.org/docsets/PPBlinkID/)

# BlinkID SDK for ID scanning

BlinkID SDK is a delightful component for quick and easy scanning of ID cards, passports and drivers licenses. The SDK is powered with [MicroBlink's](http://www.microblink.com) industry-proven and world leading OCR and barcode scanning technology, and offers:

- integrated camera management
- layered API, allowing everything from simple integration to complex UX customizations.
- lightweight and no internet connection required
- enteprise-level security standards
- data parsing from ID barcode standards

BlinkID is a part of family of SDKs developed by [MicroBlink](http://www.microblink.com) for optical text recognition, barcode scanning, ID document scanning and many others. 

<p align="center" >
  <a href="https://www.youtube.com/watch?v=3sEyQLaxLKA" target="_blank">
    <img src="https://raw.githubusercontent.com/wiki/blinkid/blinkid-ios/Images/blinkid.gif" alt="BlinkID SDK">
  </a>
</p>

## How to get started

- [Download BlinkID SDK](https://github.com/BlinkID/blinkid-ios/releases) and try out the included iOS sample apps (Download .zip or .tar.gz file starting with BlinkID. DO NOT download Source Code as GitHub does not fully support Git Large File Storage)
- Read the ["Getting Started" guide](https://github.com/BlinkID/blinkid-ios/wiki/Getting-started) to integrate the SDK in your app(s)
- [Generate](https://microblink.com/login?url=/customer/generatedemolicence) a **free demo license key** to start using the SDK in your app (registration required)
- [Contact us](http://www.microblink.com) to get pricing info
- Check out the [comprehensive documentation](http://cocoadocs.org/docsets/PPBlinkID/) of all APIs available in BlinkID SDK

### Installation with CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like BlinkID in your projects. See the ["Getting Started" guide for more information](https://github.com/BlinkID/blinkid-ios/wiki/Getting-started).

- If you wish to use version v1.4.0 or above, you need to install [Git Large File Storage](https://git-lfs.github.com) by running these comamnds:
```shell
brew install git-lfs
git lfs install
```

- **Be sure to restart your console after installing Git LFS**

- If you're using CocoaPods, you can easily try our sample apps by running the following command in your terminal window:

```shell
pod try PPBlinkID
```

#### Podfile

```ruby
platform :ios, '8.0'

target 'TargetName' do
  pod 'PPBlinkID', '~> 2.7.1'
end
```

## Requirements

SDK package contains MicroBlink framework and one or more sample apps which demonstrate framework integration. Framework can be deployed on iOS 6.0 or later, iPhone 3GS or newer and iPad 2 or newer. 

SDK performs significantly better when the images obtained from the camera are focused. Because of that, the SDK can have lower perfomance on iPad 2 and iPod Touch 4th gen devices, which [don't have camera with autofocus](http://www.adweek.com/socialtimes/ipad-2-rear-camera-has-tap-for-auto-exposure-not-auto-focus/12536).

## Important documents:

### ["Getting started" guide](https://github.com/BlinkID/blinkid-ios/wiki/Getting-started) or ["Getting started" in Swift](https://github.com/BlinkID/blinkid-ios/wiki/Getting-started-in-Swift)

See the steps for integrating the SDK in your apps. 

### [Release notes](https://github.com/BlinkID/blinkid-ios/blob/master/Release%20notes.md)

See what's new in each new SDK version.

### [Transition guide](https://github.com/BlinkID/blinkid-ios/blob/master/Transition%20guide.md)

See detailed description for transition from older version of the SDK.

## References

Partial list of companies using BlinkID SDK can be found [here](https://microblink.com/#references).

## Contact

1. Obtaining **free demo license key** (registration required):
[www.microblink.com/login](https://microblink.com/login?url=/customer/generatedemolicence)
2. Asking for technical help: [help.microblink.com](http://help.microblink.com)
3. [Contact us](http://www.microblink.com) to get pricing info

Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
