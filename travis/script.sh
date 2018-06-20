#!/bin/sh
set -e

xcodebuild -project Samples/BlinkInput-sample-ObjC/BlinkInput-sample.xcodeproj \
    -scheme BlinkInput-sample \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/BlinkInput-sample-ObjC/BlinkInput-sample.xcodeproj \
    -scheme BlinkInput-sample \
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

 xcodebuild -project Samples/BlinkInput-sample-Swift/BlinkInput-sample-Swift.xcodeproj \
    -scheme BlinkInput-sample-Swift \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/BlinkInput-sample-Swift/BlinkInput-sample-Swift.xcodeproj \
    -scheme BlinkInput-sample-Swift \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build  

 xcodebuild -project Samples/DirectAPI-sample-Swift/DirectAPI-sample-Swift.xcodeproj \
    -scheme DirectAPI-sample-Swift \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/DirectAPI-sample-Swift/DirectAPI-sample-Swift.xcodeproj \
    -scheme DirectAPI-sample-Swift \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build     

 xcodebuild -project Samples/FieldByField-sample-Swift/FieldByField-sample-Swift.xcodeproj \
    -scheme FieldByField-sample-Swift \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/FieldByField-sample-Swift/FieldByField-sample-Swift.xcodeproj \
    -scheme FieldByField-sample-Swift \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build     

 xcodebuild -project Samples/pdf417-sample-Swift/pdf417-sample-Swift.xcodeproj \
    -scheme pdf417-sample-Swift \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/pdf417-sample-Swift/pdf417-sample-Swift.xcodeproj \
    -scheme pdf417-sample-Swift \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build     

 xcodebuild -project Samples/Templating-sample-swift/Templating-sample-swift.xcodeproj \
    -scheme Templating-sample-swift \
    -configuration Debug \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build

xcodebuild -project Samples/Templating-sample-swift/Templating-sample-swift.xcodeproj \
    -scheme Templating-sample-swift \
    -configuration Release \
    -sdk iphonesimulator \
    ONLY_ACTIVE_ARCH=NO \
    clean build     