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
            url: "https://github.com/BlinkID/blinkid-ios/releases/download/v6.7.0/BlinkID.xcframework.zip",
            checksum: "f00e8e241e4e8b974baf7cb3a11e2d59df41e7f1e5c2288f0303c6cf8cab789a")
    ]
)
