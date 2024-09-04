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
            url: "https://github.com/BlinkID/blinkid-ios/releases/download/v6.10.0/BlinkID.xcframework.zip",
            checksum: "78b6f4bd4ddb8e7791e3b30a9732cbf9607f6ea9c0f1befe04d8c3ad30e31867")
    ]
)
