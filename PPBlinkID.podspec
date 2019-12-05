Pod::Spec.new do |s|
  
  s.name        = "PPBlinkID"
  s.version     = "5.0.2"
  s.summary     = "A delightful component for barcode scanning"
  s.homepage    = "http://microblink.com"
  
  s.description = <<-DESC
        BlinkID SDK is a delightful component for quick and easy scanning of ID cards, passports and drivers licenses. The SDK is powered with         [MicroBlink's](http://www.microblink.com) industry-proven and world leading OCR and barcode scanning technology, and offers:

        - integrated camera management
        - layered API, allowing everything from simple integration to complex UX customizations.
        - lightweight and no internet connection required
        - enteprise-level security standards
        - data parsing from ID barcode standards

        BlinkID is a part of family of SDKs developed by [MicroBlink](http://www.microblink.com) for optical text recognition, barcode scanning, ID document scanning and many others. 
        DESC
  
  s.license     = { 
        :type => 'commercial',
        :text => <<-LICENSE
                © 2013-2015 MicroBlink Ltd. All rights reserved.
                LICENSE
        }

  s.authors     = {
        "MicroBlink" => "info@microblink.com",
        "Jurica Cerovec" => "jurica.cerovec@microblink.com",
        "Jura Skrlec" => "jura.skrlec@microblink.com"
  }

  s.source      = { 
        :http => 'https://github.com/BlinkID/blinkid-ios/releases/download/v5.0.2/blinkid-ios_v5.0.2.tar.gz'
  }

  s.platform     = :ios

  # ――― MULTI-PLATFORM VALUES ――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.ios.deployment_target = '8.0.0'
  s.ios.resources = "Microblink.bundle"
  s.ios.requires_arc = false
  s.ios.vendored_frameworks = 'Microblink.framework'
  s.ios.frameworks = 'Accelerate', 'AVFoundation', 'AudioToolbox', 'AssetsLibrary', 'CoreMedia'
  s.ios.libraries = 'c++', 'iconv', 'z'

end
