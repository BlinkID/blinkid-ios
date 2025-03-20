#!/bin/sh

xcodebuild -project Samples/DownloadResources/BlinkIDSample.xcodeproj -sdk iphoneos archive -archivePath size-report/app.xcarchive -scheme BlinkIDSample

xcodebuild -exportArchive -archivePath size-report/app.xcarchive -exportPath size-report/app.ipa -exportOptionsPlist size-report/exportOptions.plist -allowProvisioningUpdates

cp "size-report/app.ipa/App Thinning Size Report.txt" "size-report"
