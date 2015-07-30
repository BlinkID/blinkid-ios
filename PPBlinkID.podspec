Pod::Spec.new do |s|
  
  s.name        = "PPBlinkID"
  s.version     = "1.0.1"
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
        "Jurica Cerovec" => "jurica.cerovec@microblink.com"
  }

  s.source      = { 
        :git => 'https://github.com/BlinkID/blinkid-ios.git', 
        :tag => 'v1.0.1'
  }
  
  s.preserve_paths = 'MicroBlink.embeddedframework/*'

  s.platform     = :ios

  # ――― MULTI-PLATFORM VALUES ――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.ios.deployment_target = '6.0.0'
  s.ios.source_files = 'MicroBlink.embeddedframework/MicroBlink.framework/Versions/A/Headers/*.{h}'
  s.ios.header_dir = 'MicroBlink'
  s.ios.public_header_files = "MicroBlink.embeddedframework/MicroBlink.framework/Versions/A/Headers/*.h"
  s.ios.resources = "MicroBlink.embeddedframework/MicroBlink.framework/Versions/A/Resources/*.{strings,wav,png,zzip}"
  s.ios.requires_arc = false
  
  s.ios.xcconfig = { 
        'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/PPBlinkID/MicroBlink.embeddedframework"'
  }

  s.ios.frameworks = 'MicroBlink', 'AVFoundation', 'AudioToolbox', 'CoreMedia'
  s.ios.libraries = 'c++', 'iconv'

end
