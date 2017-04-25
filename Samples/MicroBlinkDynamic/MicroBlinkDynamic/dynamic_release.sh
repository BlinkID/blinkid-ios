#!/bin/sh

xcodebuild -project MicroBlinkDynamic.xcodeproj \
-scheme MicroBlinkDynamic \
-configuration Release \
-sdk iphonesimulator \
ONLY_ACTIVE_ARCH=NO \
clean build

xcodebuild -project MicroBlinkDynamic.xcodeproj \
-scheme MicroBlinkDynamic \
-configuration Release \
-sdk iphoneos \
ONLY_ACTIVE_ARCH=NO \
clean build

rm -rf Release
mkdir -p Release

mkdir -p Release/device
mkdir -p Release/all

cp -R ${BUILD_DIR}/Release-iphoneos/MicroBlinkDynamic.framework Release/all/MicroBlinkDynamic.framework

lipo -create -output Release/all/MicroBlinkDynamic.framework/MicroBlinkDynamic ${BUILD_DIR}/Release-iphoneos/MicroBlinkDynamic.framework/MicroBlinkDynamic ${BUILD_DIR}/Release-iphonesimulator/MicroBlinkDynamic.framework/MicroBlinkDynamic

cp -R ${BUILD_DIR}/Release-iphoneos/MicroBlinkDynamic.framework Release/device/MicroBlinkDynamic.framework
