# MicroBlink scanning libraries

MicroBlink's scanning libraries are responsible for the easiest way to scan payment slips, barcodes, ID documents, or to perform OCR on mobile devices.

Some of the features of MicroBlink products:
- real time state of the art OCR
- no requirement for internet connection
- enteprise-level security standards
- layered API, allowing everything from simple integration to complex UX customizations.

SDK package contains MicroBlink framework and one or more sample apps which demonstrate framework integration. Framework can be deployed on iOS 6.0 or later, iPhone 3GS or newer and iPad 2 or newer. 

Integration documentation consists of the following guides located in the Docs folder:

### Getting started

This guide describes initial steps required to perform the scanning and to integrate MicroBlink framework in your project.

### Release notes

See what's new in each new framework version

### Transition guide

See detailed description for transition from older version of the framework

### Guides

**01 - Obtaining scanning results** 
This guide describes in more detail how you can obtain scanning results and use them in the business logic of your app.

**01a - BlinkOCR results**
See how to use generic OCR capability of the framework.

**01b - PhotoPay Germany results**
Learn the steps for scanning German Überweisungsträger payment slips.

**01c - PhotoPay Croatia results**
Learn the steps for scanning Croatian HUB1 and HUB3 payment slips.

**01d - PhotoPay Austria results**
Learn the steps for scanning Austrian Überweisungsträger payment slips.

**01e - PhotoPay Slovenia results**
Learn the steps for scanning Slovenian UPN payment slips.

**02 - Communicating with the scanner**
See detailed description of the API for communication with MicroBlink scanning library.

**03 - Customizing Camera UI**
In this guide you can learn how to develop a custom Overlay View Controller which can be placed on top of the camera view to completely customize the look and feel of the scanner.

**04 - Scanner initialization settings**
See how you can completely customize things like camera session parameters, camera resolution, default UI, scanning properties, etc.

**05 - Obtaining scanning metadata**
MicroBlink scanning library can return various metadata besides simple scanning results. See what are the options in this guide. 

Note: some of the guides are still in development. 