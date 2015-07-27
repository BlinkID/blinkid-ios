#!/bin/sh
set -e

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

xctool -project Samples/NoCamera-sample/NoCamera-sample.xcodeproj \
	-scheme NoCamera-sample \
	-configuration Debug \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build

xctool -project Samples/NoCamera-sample/NoCamera-sample.xcodeproj \
	-scheme NoCamera-sample \
	-configuration Release \
	-sdk iphonesimulator \
	ONLY_ACTIVE_ARCH=NO \
 	clean build