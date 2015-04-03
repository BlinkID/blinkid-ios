## BlinkOCR results

In this guide you will learn more how to obtain generic OCR results from the scanning library. The guide assumes you completed 01 - Obtaining scanning results guide.

> BlinkOCR a product which is dealing with generic OCR on camera video frames. It's responsible for controlling the camera, capturing video frames and recognizing text written on each frame.

### Initializing the scanner for OCR

To initialize OCR scanning use `PPOcrRecognizerSettings` recognizer settings. As always, you need to add `PPOcrRecognizerSettings` object to `settings.scanSettings`.

```objective-c
// 1. To specify we want to perform OCR recognition, initialize the OCR recognizer settings
PPOcrRecognizerSettings *ocrRecognizerSettings = [[PPOcrRecognizerSettings alloc] init];

// 2. Add at least one OCR Parser
[ocrRecognizerSettings addOcrParser:[[PPRawOcrParserFactory alloc] init] name:@"Raw ocr"];

// 3. Add the recognizer setting to a list of used recognizer
[settings.scanSettings addRecognizerSettings:ocrRecognizerSettings];
```

### Obtaining OCR scanning results

After initializing the library and presenting the scanning view controller, scanning results will be passed to the `scanningViewController:didOutputResults:` method. This method will receive an array of `PPRecognizerResult` object. Specifically, OCR scanning results will be of type `PPOcrRecognizerResult`.

To obtain the OCR result use the following code. 

```objective-c
- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
              didOutputResults:(NSArray *)results {

    // Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.
    // Perform your logic here

    for (PPRecognizerResult *result in results) {
        if ([result isKindOfClass:[PPOcrRecognizerResult class]]) {
            PPOcrRecognizerResult* ocrRecognizerResult = (PPOcrRecognizerResult*)result;
            // process ocr recognizer result
        }
    };
}
```

### OCR Parsers

Parsers are the most important feature the OCR engine and they are make reading and extracting data out of OCR results extremely simple. Using Parsers allows you to use OCR engine without the need to implement complex postprocessing algorithms, and at the same time to use additional error-reducing methods in the Parser algorithms.

To add OCR parsers, use the method `addOcrParser:` on `OcrRecognizerSettings` instance. For example, to add Raw OCR Parser, use:

```objective-c
[ocrRecognizerSettings addOcrParser:[[PPRawOcrParserFactory alloc] init] name:@"Raw ocr"];
```

Each Ocr Parser is identified with a `PPOcrParserFactory` object responsible for creating the parser, and an unique name which you can define yourself. 

> Parsers allow you to simply access data written in the OCR results. Important: if you need raw OCR results, use PPRawOcrParserFactory. 

To collect Parser results from `PPOcrRecognizerResult` object, use the following code:

```objective-c
PPOcrRecognizerResult* ocrRecognizerResult = (PPOcrRecognizerResult*)result;

// The name has to be the same as given in the PPOcrRecognizerSettings initialization
NSLog(@"Raw ocr: %@", [ocrRecognizerResult parsedResultForName:@"Raw ocr"]);
```

Available `PPOcrParserFactory` subclasses are listed in the following table.

**Generic parsers** 
 
| `OcrParserFactory` class                 |  Data                                 | Example                        |
|:-----------------------------------------|:-------------------------------------:|:------------------------------:|
| `PPRawOcrParserFactory`                  |  The whole text on the image          | ABC\n\n123.45\n123123          |
| `PPPriceOcrParserFactory`                |  Price                                | 23,45                          |
| `PPIbanOcrParserFactory`                 |  IBAN                                 | DE89 3704 0044 0532 0130 00    |

**Croatian payment slips**

| `OcrParserFactory` class                 |  Data                                 | Example                        |
|:-----------------------------------------|:-------------------------------------:|:------------------------------:|
| `PPCroReferenceOcrParserFactory`         |  Reference model & number             | HR01 142342469-101872364       |

**Swedish payment slips**

| `OcrParserFactory` class                 |  Data                                 | Example                        |
|:-----------------------------------------|:-------------------------------------:|:------------------------------:|
| `PPSwedenAmountOcrParserFactory`         |  Amount for payment                   | 287,68                         |
| `PPSwedenBankGiroNumberOcrParserFactory` |  Bank Giro Number                     | 9912346                        |
| `PPSwedenReferenceOcrParserFactory`      |  Reference Number                     | 9717721774                     |
| `PPSwedenSlipCodeOcrParserFactory`       |  Slip code                            | 42                             |


### OCR Parser groups

Ocr Parsers are internally grouped in one or more parser groups. Each parser group uses one OCR engine pass on the image, using one set of OCR parameters (character whitelist, font list, etc.). This allows for reusing of OCR results between different parsers.

However, some parsers are intrinsically very different, for example, `PPRawOcrParserFactory` and `PPPriceOcrParserFactory`. Price parser requires OCR to recognize just digits, punctuation and currency sighs, while Raw ocr parser uses the whole character list. It makes sense to use these parsers in two separate groups.

To do that, use the following code:

```objective-c
// To specify we want to perform OCR recognition, initialize the OCR recognizer settings
PPOcrRecognizerSettings *ocrRecognizerSettings = [[PPOcrRecognizerSettings alloc] init];

// We want raw OCR parsing
[ocrRecognizerSettings addOcrParser:[[PPRawOcrParserFactory alloc] init] name:@"Raw OCR" group:@"Raw OCR group"];

// We want to parse prices from raw OCR result as well
[ocrRecognizerSettings addOcrParser:[[PPPriceOcrParserFactory alloc] init] name:@"Price" group:@"Price group"];

// Add the recognizer setting to a list of used recognizer
[settings.scanSettings addRecognizerSettings:ocrRecognizerSettings];
```

> By default, when parser group is not specified, parsers are added in in default group with name "defaultParserGroup"

You can obtain Parser results from different groups using the following code:

```objective-c
PPOcrRecognizerResult* ocrRecognizerResult = (PPOcrRecognizerResult*)result;

// The name and groups have to be the same as given in the PPOcrRecognizerSettings initialization
NSLog(@"Raw ocr: %@", [ocrRecognizerResult parsedResultForName:@"Raw OCR" parserGroup:@"Raw OCR group"]);
NSLog(@"Price: %@", [ocrRecognizerResult parsedResultForName:@"Price" parserGroup:@"Price group"];
```
