#!/bin/sh

xcodebuild -project ../Samples/BlinkID-sample-Swift/BlinkID-sample-Swift.xcodeproj/ -sdk iphoneos archive -archivePath app.xcarchive -scheme BlinkID-sample-Swift

xcodebuild -exportArchive -archivePath app.xcarchive -exportPath app.ipa -exportOptionsPlist exportOptions.plist -allowProvisioningUpdates

cp "app.ipa/App Thinning Size Report.txt" .
