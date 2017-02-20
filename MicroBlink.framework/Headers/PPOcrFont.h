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

    /** Akzidenz Grotesk font
     @see http://www.identifont.com/samples2/berthold/AkzidenzGrotesk.gif
     */
    PP_OCR_FONT_AKZIDENZ_GROTESK,

    /** Arial font
     @see http://www.identifont.com/samples2/monotype/Arial.gif
     */
    PP_OCR_FONT_ARIAL,

    /** Arial black font
     @see http://www.identifont.com/samples2/monotype/ArialBlack.gif
     */
    PP_OCR_FONT_ARIAL_BLACK,

    /** Arnhem font
     @see http://www.identifont.com/samples2/ourtype/Arnhem.gif
     */
    PP_OCR_FONT_ARNHEM,

    /** Avant garde font
     @see http://www.identifont.com/samples2/adobe/AvantGardeGothicBook.gif
     */
    PP_OCR_FONT_AVANT_GARDE,

    /** Bembo font
     @see http://www.identifont.com/samples2/adobe/Bembo.gif
     */
    PP_OCR_FONT_BEMBO,

    /** Bodoni font
     @see http://www.identifont.com/samples2/adobe/Bodoni.gif
     */
    PP_OCR_FONT_BODONI,

    /** Calibri font
     @see http://www.identifont.com/samples2/microsoft/Calibri.gif
     */
    PP_OCR_FONT_CALIBRI,

    /** Calibri bold font
     @see http://www.identifont.com/samples2/microsoft/CalibriBold.gif
     */
    PP_OCR_FONT_CALIBRI_BOLD,

    /** Chainprinter font
     @see http://www.identifont.com/samples2/typodermic/Chainprinter.gif
     */
    PP_OCR_FONT_CHAINPRINTER,

    /** Comic sans font
     @see http://www.identifont.com/samples2/microsoft/ComicSans.gif
     */
    PP_OCR_FONT_COMIC_SANS,

    /** Concerto rounded SG font
     @see http://www.identifont.com/samples/spiece/ConcertoRounded.gif
     */
    PP_OCR_FONT_CONCERTO_ROUNDED_SG,

    /** Courier font
     @see http://www.identifont.com/samples2/adobe/Courier.gif
     */
    PP_OCR_FONT_COURIER,

    /** Courier bold font
     @see http://www.identifont.com/samples2/adobe/CourierBold.gif
     */
    PP_OCR_FONT_COURIER_BOLD,

    /** Courier medium bold
     @see http://www.identifont.com/samples2/urw/CourierMBold.gif
     */
    PP_OCR_FONT_COURIER_MEDIUM_BOLD,

    /** Courier new bold
     @see http://www.identifont.com/samples2/monotype/CourierNewBold.gif
     */
    PP_OCR_FONT_COURIER_NEW_BOLD,

    /** Courier new ce font
     @see http://allfont.net/cache/img/abc-7635_f48bc1d33aadcf311a97d18a895ad3b7.png
     */
    PP_OCR_FONT_COURIER_NEW_CE,

    /** Courier censored font */
    PP_OCR_FONT_COURIER_CONDENSED,

    /** Dejavu sans mono font
     @see http://www.pickafont.com/images/fonts/large/d/DejaVu-Sans-Mono.ttf.png
     */
    PP_OCR_FONT_DEJAVU_SANS_MONO,

    /** Din font
     @see http://www.identifont.com/samples2/fontfont/DIN.gif
     */
    PP_OCR_FONT_DIN,

    /** Europa grotesk no 2 SB bold font
     @see https://s-media-cache-ak0.pinimg.com/564x/bd/a1/17/bda117fbc13e47940ebce7f7c1ee5240.jpg
     */
    PP_OCR_FONT_EUROPA_GROTESK_NO_2_SB_BOLD,

    /** Eurostile font
     @see http://www.identifont.com/samples2/adobe/Eurostile.gif
     */
    PP_OCR_FONT_EUROSTILE,

    /** F25 bank printer bold font
     @see http://www.cufonfonts.com/font_preview/14545/f25-bank-printer/large_preview
     */
    PP_OCR_FONT_F25_BANK_PRINTER_BOLD,

    /** Franklin gothic font
     @see http://www.identifont.com/samples2/adobe/ITCFranklinGothic.gif
     */
    PP_OCR_FONT_FRANKLIN_GOTHIC,

    /** Frutiger font
     @see http://www.identifont.com/samples2/adobe/Frutiger.gif
     */
    PP_OCR_FONT_FRUTIGER,

    /** Futura font
     @see http://www.identifont.com/samples2/adobe/Futura.gif
     */
    PP_OCR_FONT_FUTURA,

    /** Futura bold font
     @see http://www.identifont.com/samples2/adobe/FuturaBold.gif
     */
    PP_OCR_FONT_FUTURA_BOLD,

    /** Garamond font
     @see http://www.identifont.com/samples2/microsoft/Garamond.gif
     */
    PP_OCR_FONT_GARAMOND,

    /** Georgia font
     @see http://www.identifont.com/samples2/microsoft/Georgia.gif
     */
    PP_OCR_FONT_GEORGIA,

    /** Gill sans font
     @see http://www.identifont.com/samples2/adobe/GillSans.gif
     */
    PP_OCR_FONT_GILL_SANS,

    /** Handwritten font */
    PP_OCR_FONT_HANDWRITTEN,

    /** Helvetica font
     @see http://www.identifont.com/samples2/adobe/Helvetica.gif
     */
    PP_OCR_FONT_HELVETICA,

    /** Helvetica bold font
     @see http://www.identifont.com/samples2/adobe/HelveticaBold.gif
     */
    PP_OCR_FONT_HELVETICA_BOLD,

    /** Helvetica condensed light font
     @see http://www.pickafont.com/images/fonts/large/h/Helvetica_Condensed_Light_Li.ttf.png
     */
    PP_OCR_FONT_HELVETICA_CONDENSED_LIGHT,

    /** Hypermarket font
     @see http://www.identifont.com/samples2/green-type/Hypermarket.gif
     */
    PP_OCR_FONT_HYPERMARKET,

    /** Interstate font
     @see http://www.identifont.com/samples2/font-bureau/Interstate.gif
     */
    PP_OCR_FONT_INTERSTATE,

    /** Latin modern math font
     @see http://luc.devroye.org/BoguslawJackowski+PiotrStrzelczyk+PiotrPianowski-LatinModernMath-2013.png
     */
    PP_OCR_FONT_LATIN_MODERN,

    /** Latin modern italic font */
    PP_OCR_FONT_LATIN_MODERN_ITALIC,

    /** Letter gothic font
     @see http://www.identifont.com/samples2/adobe/LetterGothic.gif
     */
    PP_OCR_FONT_LETTER_GOTHIC,

    /** Lucida font
     @see http://www.identifont.com/samples2/adobe/LucidaSerif.gif
     */
    PP_OCR_FONT_LUCIDA,

    /** Lucida sans font
     @see http://www.identifont.com/samples2/adobe/LucidaSans.gif
     */
    PP_OCR_FONT_LUCIDA_SANS,

    /** Matrix font
     @see ??? http://img.fontspace.com/preview/charmap/7a1c7e3676f2df686a37def576bb7575.png
     */
    PP_OCR_FONT_MATRIX,

    /** Meta font
     @see http://www.identifont.com/samples2/fontfont/MetaNormal.gif
     */
    PP_OCR_FONT_META,

    /** Minion font
     @see http://www.identifont.com/samples2/adobe/MinionPro.gif
     */
    PP_OCR_FONT_MINION,

    /** OCR A font
     @see http://www.identifont.com/samples2/adobe/OCRA.gif
     */
    PP_OCR_FONT_OCRA,

    /** OCR B font
     @see http://www.identifont.com/samples2/adobe/OCRB.gif
     */
    PP_OCR_FONT_OCRB,

    /** Officina font */
    PP_OCR_FONT_OFFICINA,

    /** Optima font
     @see http://www.identifont.com/samples2/adobe/Optima.gif
     */
    PP_OCR_FONT_OPTIMA,

    /** Printf font
     @see http://www.identifont.com/samples2/typodermic/Printf.gif
     */
    PP_OCR_FONT_PRINTF,

    /** Rockwell font
     @see http://www.identifont.com/samples2/adobe/Rockwell.gif
     */
    PP_OCR_FONT_ROCKWELL,

    /** Rotis sans serif font
     @see http://www.identifont.com/samples2/adobe/RotisSansSerif.gif
     */
    PP_OCR_FONT_ROTIS_SANS_SERIF,

    /** Rotis serif font
     @see http://www.identifont.com/samples2/adobe/RotisSerif.gif
     */
    PP_OCR_FONT_ROTIS_SERIF,

    /** Sabon font
     @see http://www.identifont.com/samples2/adobe/Sabon.gif
     */
    PP_OCR_FONT_SABON,

    /** Stone font */
    PP_OCR_FONT_STONE,

    /** SV basic manual font
     @see http://www.fontriver.com/i/fonts/sv_basic_manual/svbasicmanual_specimen.jpg
     */
    PP_OCR_FONT_SV_BASIC_MANUAL,

    /** Tahoma font
     @see http://www.identifont.com/samples2/microsoft/Tahoma.gif
     */
    PP_OCR_FONT_TAHOMA,

    /** Tahoma bold font
     @see http://www.identifont.com/samples2/ascender/TahomaBold.gif
     */
    PP_OCR_FONT_TAHOMA_BOLD,

    /** Tex gyre termes font
     @see http://www.cufonfonts.com/font_preview/908/texgyretermes-regular/large_preview
     */
    PP_OCR_FONT_TEX_GYRE_TERMES,

    /** Tex gyre termes italic font
     @see http://fontsov.com/data/font_face/texgyretermes-italic.png
     */
    PP_OCR_FONT_TEX_GYRE_TERMES_ITALIC,

    /** Sans mono condensed black font
     @see http://www.identifont.com/samples2/lucasfonts/TheSansMonoCondensedBlack.gif
     */
    PP_OCR_FONT_THE_SANS_MONO_CONDENSED_BLACK,

    /** Thesis font */
    PP_OCR_FONT_THESIS,

    /** Ticket de caisse font
     @see http://www.identifont.com/samples2/t26/TicketDeCaisse.gif
     */
    PP_OCR_FONT_TICKET_DE_CAISSE,

    /** Times new roman font
     @see http://www.identifont.com/samples2/adobe/TimesNewRoman.gif
     */
    PP_OCR_FONT_TIMES_NEW_ROMAN,

    /** Trajan font
     @see http://www.identifont.com/samples2/adobe/TrajanPro.gif
     */
    PP_OCR_FONT_TRAJAN,

    /** Trinite font
     @see http://luc.devroye.org/BramDeDoes-TriniteNo2MediumCondensed-1991.png
     */
    PP_OCR_FONT_TRINITE,

    /** Univers font
     @see http://www.identifont.com/samples2/linotype/Univers.gif
     */
    PP_OCR_FONT_UNIVERS,

    /** Verdana font
     @see http://www.identifont.com/samples2/microsoft/Verdana.gif
     */
    PP_OCR_FONT_VERDANA,

    /** Voltaire font
     @see http://www.identifont.com/samples2/google/Voltaire.gif
     */
    PP_OCR_FONT_VOLTAIRE,

    /** Walbaum font
     @see http://www.identifont.com/samples2/linotype/Walbaum.gif
     */
    PP_OCR_FONT_WALBAUM,

    /** Europa gro sb font
     http://www.identifont.com/samples/scangraphic/EuropaGroteskSB.gif
     */
    PP_OCR_FONT_EUROPA_GRO_SB,

    /** Europa gro sb light font
     @see https://cdnimg.fonts.net/CatalogImages/23/387088.png
     */
    PP_OCR_FONT_EUROPA_GRO_SB_LIGHT,


    // SPECIAL FONTS

    /** MICR font */
    PP_OCR_FONT_MICR,

    /** Arabic font */
    PP_OCR_FONT_ARABIC_NILE,

    /** Unknown font */
    PP_OCR_FONT_UNKNOWN,

    /** XITS Math font */
    PP_OCR_FONT_XITS_MATH,

    /** Any of the other listed fonts */
    PP_OCR_FONT_ANY,

    /** Unknown math font */
    PP_OCR_FONT_UNKNOWN_MATH,

    /** Font found on UKDL licenses */
    PP_OCR_FONT_UKDL_LIGHT,

    /** Must be last as it holds the number of available fonts */
    PP_OCR_FONT_COUNT,

    /** German license plate font **/
    PP_OCR_FONT_FE_SCHRIFT,
};

#endif
