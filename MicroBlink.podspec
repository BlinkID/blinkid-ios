Pod::Spec.new do |s|
	s.name = 'MicroBlink'
	s.version = '0.1.0'
	s.summary = 'MicroBlink\'s scanning libraries are the easiest way to scan payment slips, barcodes, ID documents, or to perform OCR on mobile devices'
	s.homepage = 'https://microblink.com'
	s.license = { type => 'Copyright', text => 'Copyright (c) 2015 MicroBlink Ltd' }
	s.author = { 'Jurica Cerovec' => 'jcerovec@gmail.com' }

	s.source = { git => 'https://github.com/BlinkID/blinkid-ios.git', tag => "v#{s.version}" }

	s.requires_arc = true
	s.ios.deployment_target = '6.0'

	s.vendored_frameworks = 'MicroBlink.embeddedframework/MicroBlink.framework'
	s.resources = 'MicroBlink.embeddedframework/Resources/*'

	s.frameworks = 'AVFoundation', 'AudioToolbox', 'CoreMedia'
	s.libraries = 'c++', 'iconv'
end
