#!/bin/sh
set -e

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