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
            url: "https://github.com/BlinkID/blinkid-ios/releases/download/v6.9.1/BlinkID.xcframework.zip",
            checksum: "d834f3c31ea96a8fec28e44720f95fdf92e0e72d6f2a3a3c5bc73124274b65c2")
    ]
)
