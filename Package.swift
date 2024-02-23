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
            url: "https://github.com/BlinkID/blinkid-ios/releases/download/v6.5.1/BlinkID.xcframework.zip",
            checksum: "7061dc52f87bd9362d128f79c5e37fe0ca95120e0836838f0ca192c42727b01e")
    ]
)
