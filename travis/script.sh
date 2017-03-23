#!/bin/sh
set -e

xcodebuild -project Samples/DirectAPI-sample/DirectAPI-sample.xcodeproj \
    -scheme DirectAPI-Sample \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/DirectAPI-sample/DirectAPI-sample.xcodeproj \
    -scheme DirectAPI-Sample \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/Templating-Sample/Templating-Sample.xcodeproj \
    -scheme Templating-Sample \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/Templating-Sample/Templating-Sample.xcodeproj \
    -scheme Templating-Sample \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/BlinkOCR-sample/BlinkOCR-sample.xcodeproj \
	-scheme BlinkOCR-sample \
	-configuration Debug \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xcodebuild -project Samples/BlinkOCR-sample/BlinkOCR-sample.xcodeproj \
	-scheme BlinkOCR-sample \
	-configuration Release \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xcodebuild -project Samples/BlinkID-sample/BlinkID-sample.xcodeproj \
	-scheme BlinkID-sample \
	-configuration Debug \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xcodebuild -project Samples/BlinkID-sample/BlinkID-sample.xcodeproj \
	-scheme BlinkID-sample \
	-configuration Release \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xcodebuild -project Samples/BlinkID-sample-Swift/BlinkID-sample-Swift.xcodeproj \
	-scheme BlinkID-sample-Swift \
	-configuration Debug \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xcodebuild -project Samples/BlinkID-sample-Swift/BlinkID-sample-Swift.xcodeproj \
	-scheme BlinkID-sample-Swift \
	-configuration Release \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xcodebuild -project Samples/Detector-sample/Detector-sample.xcodeproj \
	-scheme Detector-sample \
	-configuration Debug \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xcodebuild -project Samples/Detector-sample/Detector-sample.xcodeproj \
	-scheme Detector-sample \
	-configuration Release \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xcodebuild -project Samples/pdf417-sample/pdf417-sample.xcodeproj \
    -scheme pdf417-sample \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/pdf417-sample/pdf417-sample.xcodeproj \
    -scheme pdf417-sample \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/AutodetectID-sample/AutodetectID-sample.xcodeproj \
    -scheme AutodetectID-sample \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/AutodetectID-sample/AutodetectID-sample.xcodeproj \
    -scheme AutodetectID-sample \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build
