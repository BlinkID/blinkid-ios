// swift-tools-version:5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "BlinkID",
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "BlinkID",
            targets: ["BlinkID"]
            )
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "BlinkID",
            url: "https://github.com/BlinkID/blinkid-ios/releases/download/v6.11.0/BlinkID.xcframework.zip",
            checksum: "ce3e60c7b92539de5d5ac59faf68905bb815c73264abfa2c0253ff4bd15d4512")
    ]
)
