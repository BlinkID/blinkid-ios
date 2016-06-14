#!/bin/sh
set -e

xctool -project Samples/DirectAPI-sample/DirectAPI-sample.xcodeproj \
    -scheme DirectAPI-Sample \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xctool -project Samples/DirectAPI-sample/DirectAPI-sample.xcodeproj \
    -scheme DirectAPI-Sample \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xctool -project Samples/Templating-Sample/Templating-Sample.xcodeproj \
    -scheme Templating-Sample \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xctool -project Samples/Templating-Sample/Templating-Sample.xcodeproj \
    -scheme Templating-Sample \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xctool -project Samples/BlinkOCR-sample/BlinkOCR-sample.xcodeproj \
	-scheme BlinkOCR-sample \
	-configuration Debug \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xctool -project Samples/BlinkOCR-sample/BlinkOCR-sample.xcodeproj \
	-scheme BlinkOCR-sample \
	-configuration Release \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xctool -project Samples/BlinkID-sample/BlinkID-sample.xcodeproj \
	-scheme BlinkID-sample \
	-configuration Debug \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xctool -project Samples/BlinkID-sample/BlinkID-sample.xcodeproj \
	-scheme BlinkID-sample \
	-configuration Release \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xctool -project Samples/BlinkID-sample-Swift/BlinkID-sample-Swift.xcodeproj \
	-scheme BlinkID-sample-Swift \
	-configuration Debug \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xctool -project Samples/BlinkID-sample-Swift/BlinkID-sample-Swift.xcodeproj \
	-scheme BlinkID-sample-Swift \
	-configuration Release \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xctool -project Samples/Detector-sample/Detector-sample.xcodeproj \
	-scheme Detector-sample \
	-configuration Debug \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xctool -project Samples/Detector-sample/Detector-sample.xcodeproj \
	-scheme Detector-sample \
	-configuration Release \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xctool -project Samples/pdf417-sample/pdf417-sample.xcodeproj \
    -scheme pdf417-sample \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xctool -project Samples/pdf417-sample/pdf417-sample.xcodeproj \
    -scheme pdf417-sample \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xctool -project Samples/pdf417-sample-Swift/pdf417-sample-Swift.xcodeproj \
    -scheme pdf417-sample-Swift \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xctool -project Samples/pdf417-sample-Swift/pdf417-sample-Swift.xcodeproj \
    -scheme pdf417-sample-Swift \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build
