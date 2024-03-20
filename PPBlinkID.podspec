Pod::Spec.new do |s|
  
  s.name        = "PPBlinkID"
  s.version     = "6.6.0"
  s.summary     = "A delightful component for barcode scanning"
  s.homepage    = "http://microblink.com"
  
  s.description = <<-DESC
        BlinkID SDK is a delightful component for quick and easy scanning of ID cards, passports and drivers licenses. The SDK is powered with         [Microblink's](http://www.microblink.com) industry-proven and world leading OCR and barcode scanning technology, and offers:

        - integrated camera management
        - layered API, allowing everything from simple integration to complex UX customizations.
        - lightweight and no internet connection required
        - enteprise-level security standards
        - data parsing from ID barcode standards

        BlinkID is a part of family of SDKs developed by [Microblink](http://www.microblink.com) for optical text recognition, barcode scanning, ID document scanning and many others. 
        DESC
  
  s.license     = { 
        :type => 'commercial',
        :text => <<-LICENSE
                © 2013-2024 Microblink Ltd. All rights reserved.
                LICENSE
        }

  s.authors     = {
        "Microblink" => "info@microblink.com",
        "Jurica Cerovec" => "jurica.cerovec@microblink.com",
        "Jura Skrlec" => "jura.skrlec@microblink.com"
  }

  s.source      = { 
        :http => 'https://github.com/BlinkID/blinkid-ios/releases/download/v6.6.0/blinkid-ios_v6.6.0.tar.gz'
  }

  s.platform     = :ios

  # ――― MULTI-PLATFORM VALUES ――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.ios.deployment_target = '13.0.0'
  s.ios.requires_arc = false
  s.ios.vendored_frameworks = 'BlinkID.xcframework'
  s.ios.frameworks = 'Accelerate', 'AVFoundation', 'AudioToolbox', 'AssetsLibrary', 'CoreMedia', 'ImageIO'
  s.ios.libraries = 'c++', 'iconv', 'z'

end
