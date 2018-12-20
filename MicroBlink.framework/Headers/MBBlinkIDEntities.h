//
//  MicroBlink.h
//  MicroBlinkFramework
//
//  Created by Dino Gustin on 06/06/18.
//  Copyright (c) 2012 MicroBlink Ltd. All rights reserved.
//

#import "MBBlinkInputEntities.h"

// Australia
#import "MBAustraliaDlFrontRecognizer.h"
#import "MBAustraliaDlFrontRecognizerResult.h"
#import "MBAustraliaDlBackRecognizer.h"
#import "MBAustraliaDlBackRecognizerResult.h"

// Austria
#import "MBAustriaIdBackRecognizer.h"
#import "MBAustriaIdBackRecognizerResult.h"
#import "MBAustriaIdFrontRecognizer.h"
#import "MBAustriaIdFrontRecognizerResult.h"
#import "MBAustriaCombinedRecognizer.h"
#import "MBAustriaCombinedRecognizerResult.h"
#import "MBAustriaPassportRecognizer.h"
#import "MBAustriaPassportRecognizerResult.h"
#import "MBAustriaDlFrontRecognizer.h"
#import "MBAustriaDlFrontRecognizerResult.h"

#import "MBBruneiIdFrontRecognizer.h"
#import "MBBruneiIdFrontRecognizerResult.h"

// Colombia
#import "MBColombiaIdBackRecognizer.h"
#import "MBColombiaIdBackRecognizerResult.h"
#import "MBColombiaIdFrontRecognizer.h"
#import "MBColombiaIdFrontRecognizerResult.h"
#import "MBColombiaDlFrontRecognizer.h"
#import "MBColombiaDlFrontRecognizerResult.h"

// Croatia
#import "MBCroatiaIdFrontRecognizer.h"
#import "MBCroatiaIdFrontRecognizerResult.h"
#import "MBCroatiaIdBackRecognizer.h"
#import "MBCroatiaIdBackRecognizerResult.h"
#import "MBCroatiaCombinedRecognizer.h"
#import "MBCroatiaCombinedRecognizerResult.h"

// Cyprus
#import "MBCyprusIdFrontRecognizer.h"
#import "MBCyprusIdFrontRecognizerResult.h"
#import "MBCyprusIdBackRecognizer.h"
#import "MBCyprusIdBackRecognizerResult.h"
#import "MBCyprusOldIdFrontRecognizer.h"
#import "MBCyprusOldIdFrontRecognizerResult.h"
#import "MBCyprusOldIdBackRecognizer.h"
#import "MBCyprusOldIdBackRecognizerResult.h"

// Czechia
#import "MBCzechiaIdBackRecognizer.h"
#import "MBCzechiaIdBackRecognizerResult.h"
#import "MBCzechiaIdFrontRecognizer.h"
#import "MBCzechiaIdFrontRecognizerResult.h"
#import "MBCzechiaCombinedRecognizer.h"
#import "MBCzechiaCombinedRecognizerResult.h"

// DocumentFace
#import "MBDocumentFaceRecognizer.h"
#import "MBDocumentFaceRecognizerResult.h"

// Egypt
#import "MBEgyptIdFrontRecognizer.h"
#import "MBEgyptIdFrontRecognizerResult.h"

// Europe Driver's License
#import "MBEudlRecognizer.h"
#import "MBEudlRecognizerResult.h"

// Germany
#import "MBGermanyIdBackRecognizer.h"
#import "MBGermanyIdBackRecognizerResult.h"
#import "MBGermanyIdFrontRecognizer.h"
#import "MBGermanyIdFrontRecognizerResult.h"
#import "MBGermanyCombinedRecognizer.h"
#import "MBGermanyCombinedRecognizerResult.h"
#import "MBGermanyPassportRecognizer.h"
#import "MBGermanyPassportRecognizerResult.h"
#import "MBGermanyOldIdRecognizer.h"
#import "MBGermanyOldIdRecognizerResult.h"
#import "MBGermanyDlBackRecognizer.h"
#import "MBGermanyDlBackRecognizerResult.h"

// Hong Kong
#import "MBHongKongIdFrontRecognizer.h"
#import "MBHongKongIdFrontRecognizerResult.h"

// Indonesia
#import "MBIndonesiaIdFrontRecognizer.h"
#import "MBIndonesiaIdFrontRecognizerResult.h"

// Ireland
#import "MBIrelandDlFrontRecognizer.h"
#import "MBIrelandDlFrontRecognizerResult.h"

// Italy
#import "MBItalyDlFrontRecognizer.h"
#import "MBItalyDlFrontRecognizerResult.h"

// Kuwait
#import "MBKuwaitIdFrontRecognizer.h"
#import "MBKuwaitIdFrontRecognizerResult.h"
#import "MBKuwaitIdBackRecognizer.h"
#import "MBKuwaitIdBackRecognizerResult.h"

// Jordan
#import "MBJordanIdBackRecognizer.h"
#import "MBJordanIdBackRecognizerResult.h"
#import "MBJordanIdFrontRecognizer.h"
#import "MBJordanIdFrontRecognizerResult.h"
#import "MBJordanCombinedRecognizer.h"
#import "MBJordanCombinedRecognizerResult.h"

// Malaysia
#import "MBMalaysiaMyKadBackRecognizer.h"
#import "MBMalaysiaMyKadBackRecognizerResult.h"
#import "MBMalaysiaMyKadFrontRecognizer.h"
#import "MBMalaysiaMyKadFrontRecognizerResult.h"
#import "MBMalaysiaIkadFrontRecognizer.h"
#import "MBMalaysiaIkadFrontRecognizerResult.h"
#import "MBMalaysiaMyTenteraFrontRecognizer.h"
#import "MBMalaysiaMyTenteraFrontRecognizerResult.h"
#import "MBMalaysiaDlFrontRecognizer.h"
#import "MBMalaysiaDlFrontRecognizerResult.h"
#import "MBMalaysiaMyPrFrontRecognizer.h"
#import "MBMalaysiaMyPrFrontRecognizerResult.h"
#import "MBMalaysiaMyKasFrontRecognizer.h"
#import "MBMalaysiaMyKasFrontRecognizerResult.h"

// Mexico
#import "MBMexicoVoterIdFrontRecognizer.h"
#import "MBMexicoVoterIdFrontRecognizerResult.h"

// Morocco
#import "MBMoroccoIdFrontRecognizer.h"
#import "MBMoroccoIdFrontRecognizerResult.h"
#import "MBMoroccoIdBackRecognizer.h"
#import "MBMoroccoIdBackRecognizerResult.h"

// Mrtd
#import "MBMrtdRecognizer.h"
#import "MBMrtdRecognizerResult.h"
#import "MBMrtdCombinedRecognizer.h"
#import "MBMrtdCombinedRecognizerResult.h"

// New Zealand
#import "MBNewZealandDlFrontRecognizer.h"
#import "MBNewZealandDlFrontRecognizerResult.h"

// Payment Card
#import "MBPaymentCardBackRecognizer.h"
#import "MBPaymentCardBackRecognizerResult.h"
#import "MBPaymentCardFrontRecognizer.h"
#import "MBPaymentCardFrontRecognizerResult.h"
#import "MBPaymentCardCombinedRecognizer.h"
#import "MBPaymentCardCombinedRecognizerResult.h"
#import "MBElitePaymentCardBackRecognizer.h"
#import "MBElitePaymentCardBackRecognizerResult.h"
#import "MBElitePaymentCardFrontRecognizer.h"
#import "MBElitePaymentCardFrontRecognizerResult.h"
#import "MBElitePaymentCardCombinedRecognizer.h"
#import "MBElitePaymentCardCombinedRecognizerResult.h"

// Poland
#import "MBPolandIdBackRecognizer.h"
#import "MBPolandIdBackRecognizerResult.h"
#import "MBPolandIdFrontRecognizer.h"
#import "MBPolandIdFrontRecognizerResult.h"
#import "MBPolandCombinedRecognizer.h"
#import "MBPolandCombinedRecognizerResult.h"

// Romania
#import "MBRomaniaIdFrontRecognizer.h"
#import "MBRomaniaIdFrontRecognizerResult.h"

// Serbia
#import "MBSerbiaIdBackRecognizer.h"
#import "MBSerbiaIdBackRecognizerResult.h"
#import "MBSerbiaIdFrontRecognizer.h"
#import "MBSerbiaIdFrontRecognizerResult.h"
#import "MBSerbiaCombinedRecognizer.h"
#import "MBSerbiaCombinedRecognizerResult.h"

// Singapore
#import "MBSingaporeIdBackRecognizer.h"
#import "MBSingaporeIdBackRecognizerResult.h"
#import "MBSingaporeIdFrontRecognizer.h"
#import "MBSingaporeIdFrontRecognizerResult.h"
#import "MBSingaporeCombinedRecognizer.h"
#import "MBSingaporeCombinedRecognizerResult.h"
#import "MBSingaporeDlFrontRecognizer.h"
#import "MBSingaporeDlFrontRecognizerResult.h"
#import "MBSingaporeChangiEmployeeIdRecognizer.h"
#import "MBSingaporeChangiEmployeeIdRecognizerResult.h"

// Slovakia
#import "MBSlovakiaIdBackRecognizer.h"
#import "MBSlovakiaIdBackRecognizerResult.h"
#import "MBSlovakiaIdFrontRecognizer.h"
#import "MBSlovakiaIdFrontRecognizerResult.h"
#import "MBSlovakiaCombinedRecognizer.h"
#import "MBSlovakiaCombinedRecognizerResult.h"

// Slovenia
#import "MBSloveniaIdBackRecognizer.h"
#import "MBSloveniaIdBackRecognizerResult.h"
#import "MBSloveniaIdFrontRecognizer.h"
#import "MBSloveniaIdFrontRecognizerResult.h"
#import "MBSloveniaCombinedRecognizer.h"
#import "MBSloveniaCombinedRecognizerResult.h"

// Spain
#import "MBSpainDlFrontRecognizer.h"
#import "MBSpainDlFrontRecognizerResult.h"

// Sweden
#import "MBSwedenDlFrontRecognizer.h"
#import "MBSwedenDlFrontRecognizerResult.h"

// Switzerland
#import "MBSwitzerlandIdBackRecognizer.h"
#import "MBSwitzerlandIdBackRecognizerResult.h"
#import "MBSwitzerlandIdFrontRecognizer.h"
#import "MBSwitzerlandIdFrontRecognizerResult.h"
#import "MBSwitzerlandPassportRecognizer.h"
#import "MBSwitzerlandPassportRecognizerResult.h"
#import "MBSwitzerlandDlFrontRecognizer.h"
#import "MBSwitzerlandDlFrontRecognizerResult.h"

// United Arab Emirates
#import "MBUnitedArabEmiratesIdBackRecognizer.h"
#import "MBUnitedArabEmiratesIdBackRecognizerResult.h"
#import "MBUnitedArabEmiratesIdFrontRecognizer.h"
#import "MBUnitedArabEmiratesIdFrontRecognizerResult.h"
#import "MBUnitedArabEmiratesDlFrontRecognizer.h"
#import "MBUnitedArabEmiratesDlFrontRecognizerResult.h"

// USDL
#import "MBUsdlCombinedRecognizer.h"
#import "MBUsdlCombinedRecognizerResult.h"
