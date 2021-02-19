#!/bin/sh

if [ "$#" -ne 2 ]
then
  echo "Usage: $0 PATH_TO_SAMPLES PROJECT_NAME"
  echo "Example: $0 blinkid-ios/Samples BlinkID-sample-Swift"
  exit 1
fi

PATH_TO_SAMPLES=$1
PROJECT_NAME=$2

PATH_TO_SIZE_REPORT=$PATH_TO_SAMPLES/../size-report

if [ -d "$PATH_TO_SAMPLES" ]; then

  if [ $PROJECT_NAME == "Pdf417Mobi" ]; then
    PROJECT_NAME = "pdf417"
  fi

  xcodebuild -project $PATH_TO_SAMPLES/$PROJECT_NAME-sample-Swift/$PROJECT_NAME-sample-Swift.xcodeproj -sdk iphoneos archive -archivePath $PATH_TO_SIZE_REPORT/app.xcarchive -scheme $PROJECT_NAME-sample-Swift

  xcodebuild -exportArchive -archivePath $PATH_TO_SIZE_REPORT/app.xcarchive -exportPath $PATH_TO_SIZE_REPORT/app.ipa -exportOptionsPlist $PATH_TO_SIZE_REPORT/exportOptions.plist -allowProvisioningUpdates

  cp "$PATH_TO_SIZE_REPORT/app.ipa/App Thinning Size Report.txt" "$PATH_TO_SIZE_REPORT"
fi