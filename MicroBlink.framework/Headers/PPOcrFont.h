//
//  PPOcrFont.h
//  BlinkOcrFramework
//
//  Created by Jura on 29/07/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#ifndef BlinkOcrFramework_PPOcrFont_h
#define BlinkOcrFramework_PPOcrFont_h

/**
 * A list of fonts supported by BlinkOCR
 */
typedef NS_ENUM(NSUInteger, PPOcrFont) {

    /** Akzidenz Grotesk font */
    PP_OCR_FONT_AKZIDENZ_GROTESK,

    /** Arial font */
    PP_OCR_FONT_ARIAL,

    /** Arial black font */
    PP_OCR_FONT_ARIAL_BLACK,

    /** Arnhem font */
    PP_OCR_FONT_ARNHEM,

    /** Avant garde font */
    PP_OCR_FONT_AVANT_GARDE,

    /** Bembo font */
    PP_OCR_FONT_BEMBO,

    /** Bodoni font */
    PP_OCR_FONT_BODONI,

    /** Calibri font */
    PP_OCR_FONT_CALIBRI,

    /** Calibri bold font */
    PP_OCR_FONT_CALIBRI_BOLD,

    /** Chainprinter font */
    PP_OCR_FONT_CHAINPRINTER,

    /** Comic sans font */
    PP_OCR_FONT_COMIC_SANS,

    /** Concerto rounded SG font */
    PP_OCR_FONT_CONCERTO_ROUNDED_SG,

    /** Courier font */
    PP_OCR_FONT_COURIER,

    /** Courier bold font */
    PP_OCR_FONT_COURIER_BOLD,

    /** Courier medium bold */
    PP_OCR_FONT_COURIER_MEDIUM_BOLD,

    /** Courier new bold */
    PP_OCR_FONT_COURIER_NEW_BOLD,

    /** Courier new ce font */
    PP_OCR_FONT_COURIER_NEW_CE,

    /** Courier censored font */
    PP_OCR_FONT_COURIER_CONDENSED,

    /** Dejavu sans mono font */
    PP_OCR_FONT_DEJAVU_SANS_MONO,

    /** Din font */
    PP_OCR_FONT_DIN,

    /** Europa grotesk no 2 SB bold font */
    PP_OCR_FONT_EUROPA_GROTESK_NO_2_SB_BOLD,

    /** Eurostile font */
    PP_OCR_FONT_EUROSTILE,

    /** F25 bank printer bold font */
    PP_OCR_FONT_F25_BANK_PRINTER_BOLD,

    /** Franklin gothic font */
    PP_OCR_FONT_FRANKLIN_GOTHIC,

    /** Frutiger font */
    PP_OCR_FONT_FRUTIGER,

    /** Futura font */
    PP_OCR_FONT_FUTURA,

    /** Futura bold font */
    PP_OCR_FONT_FUTURA_BOLD,

    /** Garamond font */
    PP_OCR_FONT_GARAMOND,

    /** Georgia font */
    PP_OCR_FONT_GEORGIA,

    /** Gill sans font */
    PP_OCR_FONT_GILL_SANS,

    /** Helvetica font */
    PP_OCR_FONT_HELVETICA,

    /** Helvetica bold font */
    PP_OCR_FONT_HELVETICA_BOLD,
    
    /** Helvetica condensed light font */
    PP_OCR_FONT_HELVETICA_CONDENSED_LIGHT,

    /** Hypermarket font */
    PP_OCR_FONT_HYPERMARKET,

    /** Interstate font */
    PP_OCR_FONT_INTERSTATE,

    /** Latin modern math font */
    PP_OCR_FONT_LATIN_MODERN,

    /** Latin modern italic font */
    PP_OCR_FONT_LATIN_MODERN_ITALIC,

    /** Letter gothic font */
    PP_OCR_FONT_LETTER_GOTHIC,

    /** Lucida font */
    PP_OCR_FONT_LUCIDA,

    /** Lucida sans font */
    PP_OCR_FONT_LUCIDA_SANS,

    /** Matrix font */
    PP_OCR_FONT_MATRIX,

    /** Meta font */
    PP_OCR_FONT_META,

    /** Minion font */
    PP_OCR_FONT_MINION,

    /** OCR A font */
    PP_OCR_FONT_OCRA,

    /** OCR B font */
    PP_OCR_FONT_OCRB,

    /** Officina font */
    PP_OCR_FONT_OFFICINA,

    /** Optima font */
    PP_OCR_FONT_OPTIMA,

    /** Printf font */
    PP_OCR_FONT_PRINTF,

    /** Rockwell font */
    PP_OCR_FONT_ROCKWELL,

    /** Rotis sans serif font */
    PP_OCR_FONT_ROTIS_SANS_SERIF,

    /** Rotis serif font */
    PP_OCR_FONT_ROTIS_SERIF,

    /** Sabon font */
    PP_OCR_FONT_SABON,

    /** Stone font */
    PP_OCR_FONT_STONE,

    /** SV basic manual font */
    PP_OCR_FONT_SV_BASIC_MANUAL,

    /** Tahoma font */
    PP_OCR_FONT_TAHOMA,

    /** Tex gyre termes font */
    PP_OCR_FONT_TEX_GYRE_TERMES,

    /** Tex gyre termes italic font */
    PP_OCR_FONT_TEX_GYRE_TERMES_ITALIC,

    /** Sans mono condensed black font */
    PP_OCR_FONT_THE_SANS_MONO_CONDENSED_BLACK,

    /** Thesis font */
    PP_OCR_FONT_THESIS,

    /** Ticket de caisse font */
    PP_OCR_FONT_TICKET_DE_CAISSE,

    /** Times new roman font */
    PP_OCR_FONT_TIMES_NEW_ROMAN,

    /** Trajan font */
    PP_OCR_FONT_TRAJAN,

    /** Trinite font */
    PP_OCR_FONT_TRINITE,

    /** Univers font */
    PP_OCR_FONT_UNIVERS,

    /** Verdana font */
    PP_OCR_FONT_VERDANA,

    /** Voltaire font */
    PP_OCR_FONT_VOLTAIRE,

    /** Walbum font */
    PP_OCR_FONT_WALBAUM,

    /** Europa gro sb font */
    PP_OCR_FONT_EUROPA_GRO_SB,

    /** Europa gro sb light font */
    PP_OCR_FONT_EUROPA_GRO_SB_LIGHT,

    // SPECIAL FONTS

    /** MICR font */
    PP_OCR_FONT_MICR,

    /** Unknown font */
    PP_OCR_FONT_UNKNOWN,

    /** Any of the other listed fonts */
    PP_OCR_FONT_ANY,

    /** Unknown math font */
    PP_OCR_FONT_UNKNOWN_MATH,

    /** Font found on UKDL licenses */
    PP_OCR_FONT_UKDL_LIGHT,

    /** Must be last as it holds the number of available fonts */
    PP_OCR_FONT_COUNT,
};

#endif
