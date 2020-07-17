//
//  MBOcrFont.h
//  BlinkOcrFramework
//
//  Created by Jura on 29/07/15.
//  Copyright (c) 2015 Microblink Ltd. All rights reserved.
//

#ifndef BlinkOcrFramework_PPOcrFont_h
#define BlinkOcrFramework_PPOcrFont_h

/**
 * A list of fonts supported by BlinkOCR
 */
typedef NS_ENUM(NSInteger, MBOcrFont) {

    /** Akzidenz Grotesk font
     @see http://www.identifont.com/samples2/berthold/AkzidenzGrotesk.gif
     */
    MB_OCR_FONT_AKZIDENZ_GROTESK,

    /** Arial font
     @see http://www.identifont.com/samples2/monotype/Arial.gif
     */
    MB_OCR_FONT_ARIAL,

    /** Arial black font
     @see http://www.identifont.com/samples2/monotype/ArialBlack.gif
     */
    MB_OCR_FONT_ARIAL_BLACK,

    /** Arnhem font
     @see http://www.identifont.com/samples2/ourtype/Arnhem.gif
     */
    MB_OCR_FONT_ARNHEM,

    /** Avant garde font
     @see http://www.identifont.com/samples2/adobe/AvantGardeGothicBook.gif
     */
    MB_OCR_FONT_AVANT_GARDE,

    /** Bembo font
     @see http://www.identifont.com/samples2/adobe/Bembo.gif
     */
    MB_OCR_FONT_BEMBO,

    /** Bodoni font
     @see http://www.identifont.com/samples2/adobe/Bodoni.gif
     */
    MB_OCR_FONT_BODONI,

    /** Calibri font
     @see http://www.identifont.com/samples2/microsoft/Calibri.gif
     */
    MB_OCR_FONT_CALIBRI,

    /** Calibri bold font
     @see http://www.identifont.com/samples2/microsoft/CalibriBold.gif
     */
    MB_OCR_FONT_CALIBRI_BOLD,

    /** Chainprinter font
     @see http://www.identifont.com/samples2/typodermic/Chainprinter.gif
     */
    MB_OCR_FONT_CHAINPRINTER,

    /** Comic sans font
     @see http://www.identifont.com/samples2/microsoft/ComicSans.gif
     */
    MB_OCR_FONT_COMIC_SANS,

    /** Concerto rounded SG font
     @see http://www.identifont.com/samples/spiece/ConcertoRounded.gif
     */
    MB_OCR_FONT_CONCERTO_ROUNDED_SG,

    /** Courier font
     @see http://www.identifont.com/samples2/adobe/Courier.gif
     */
    MB_OCR_FONT_COURIER,

    /** Courier bold font
     @see http://www.identifont.com/samples2/adobe/CourierBold.gif
     */
    MB_OCR_FONT_COURIER_BOLD,

    /** Courier medium bold
     @see http://www.identifont.com/samples2/urw/CourierMBold.gif
     */
    MB_OCR_FONT_COURIER_MEDIUM_BOLD,

    /** Courier new bold
     @see http://www.identifont.com/samples2/monotype/CourierNewBold.gif
     */
    MB_OCR_FONT_COURIER_NEW_BOLD,

    /** Courier new ce font
     @see http://allfont.net/cache/img/abc-7635_f48bc1d33aadcf311a97d18a895ad3b7.png
     */
    MB_OCR_FONT_COURIER_NEW_CE,

    /** Courier censored font */
    MB_OCR_FONT_COURIER_CONDENSED,

    /** Dejavu sans mono font
     @see http://www.pickafont.com/images/fonts/large/d/DejaVu-Sans-Mono.ttf.png
     */
    MB_OCR_FONT_DEJAVU_SANS_MONO,

    /** Din font
     @see http://www.identifont.com/samples2/fontfont/DIN.gif
     */
    MB_OCR_FONT_DIN,

    /** Europa grotesk no 2 SB bold font
     @see https://s-media-cache-ak0.pinimg.com/564x/bd/a1/17/bda117fbc13e47940ebce7f7c1ee5240.jpg
     */
    MB_OCR_FONT_EUROPA_GROTESK_NO_2_SB_BOLD,

    /** Eurostile font
     @see http://www.identifont.com/samples2/adobe/Eurostile.gif
     */
    MB_OCR_FONT_EUROSTILE,

    /** F25 bank printer bold font
     @see http://www.cufonfonts.com/font_preview/14545/f25-bank-printer/large_preview
     */
    MB_OCR_FONT_F25_BANK_PRINTER_BOLD,

    /** Franklin gothic font
     @see http://www.identifont.com/samples2/adobe/ITCFranklinGothic.gif
     */
    MB_OCR_FONT_FRANKLIN_GOTHIC,

    /** Frutiger font
     @see http://www.identifont.com/samples2/adobe/Frutiger.gif
     */
    MB_OCR_FONT_FRUTIGER,

    /** Futura font
     @see http://www.identifont.com/samples2/adobe/Futura.gif
     */
    MB_OCR_FONT_FUTURA,

    /** Futura bold font
     @see http://www.identifont.com/samples2/adobe/FuturaBold.gif
     */
    MB_OCR_FONT_FUTURA_BOLD,

    /** Garamond font
     @see http://www.identifont.com/samples2/microsoft/Garamond.gif
     */
    MB_OCR_FONT_GARAMOND,

    /** Georgia font
     @see http://www.identifont.com/samples2/microsoft/Georgia.gif
     */
    MB_OCR_FONT_GEORGIA,

    /** Gill sans font
     @see http://www.identifont.com/samples2/adobe/GillSans.gif
     */
    MB_OCR_FONT_GILL_SANS,

    /** Handwritten font */
    MB_OCR_FONT_HANDWRITTEN,

    /** Helvetica font
     @see http://www.identifont.com/samples2/adobe/Helvetica.gif
     */
    MB_OCR_FONT_HELVETICA,

    /** Helvetica bold font
     @see http://www.identifont.com/samples2/adobe/HelveticaBold.gif
     */
    MB_OCR_FONT_HELVETICA_BOLD,

    /** Helvetica condensed light font
     @see http://www.pickafont.com/images/fonts/large/h/Helvetica_Condensed_Light_Li.ttf.png
     */
    MB_OCR_FONT_HELVETICA_CONDENSED_LIGHT,

    /** Hypermarket font
     @see http://www.identifont.com/samples2/green-type/Hypermarket.gif
     */
    MB_OCR_FONT_HYPERMARKET,

    /** Interstate font
     @see http://www.identifont.com/samples2/font-bureau/Interstate.gif
     */
    MB_OCR_FONT_INTERSTATE,

    /** Latin modern math font
     @see http://luc.devroye.org/BoguslawJackowski+PiotrStrzelczyk+PiotrPianowski-LatinModernMath-2013.png
     */
    MB_OCR_FONT_LATIN_MODERN,

    /** Latin modern italic font */
    MB_OCR_FONT_LATIN_MODERN_ITALIC,

    /** Letter gothic font
     @see http://www.identifont.com/samples2/adobe/LetterGothic.gif
     */
    MB_OCR_FONT_LETTER_GOTHIC,

    /** Lucida font
     @see http://www.identifont.com/samples2/adobe/LucidaSerif.gif
     */
    MB_OCR_FONT_LUCIDA,

    /** Lucida sans font
     @see http://www.identifont.com/samples2/adobe/LucidaSans.gif
     */
    MB_OCR_FONT_LUCIDA_SANS,

    /** Matrix font
     @see ??? http://img.fontspace.com/preview/charmap/7a1c7e3676f2df686a37def576bb7575.png
     */
    MB_OCR_FONT_MATRIX,

    /** Meta font
     @see http://www.identifont.com/samples2/fontfont/MetaNormal.gif
     */
    MB_OCR_FONT_META,

    /** Minion font
     @see http://www.identifont.com/samples2/adobe/MinionPro.gif
     */
    MB_OCR_FONT_MINION,

    /** OCR A font
     @see http://www.identifont.com/samples2/adobe/OCRA.gif
     */
    MB_OCR_FONT_OCRA,

    /** OCR B font
     @see http://www.identifont.com/samples2/adobe/OCRB.gif
     */
    MB_OCR_FONT_OCRB,

    /** Officina font */
    MB_OCR_FONT_OFFICINA,

    /** Optima font
     @see http://www.identifont.com/samples2/adobe/Optima.gif
     */
    MB_OCR_FONT_OPTIMA,

    /** Printf font
     @see http://www.identifont.com/samples2/typodermic/Printf.gif
     */
    MB_OCR_FONT_PRINTF,

    /** Rockwell font
     @see http://www.identifont.com/samples2/adobe/Rockwell.gif
     */
    MB_OCR_FONT_ROCKWELL,

    /** Rotis sans serif font
     @see http://www.identifont.com/samples2/adobe/RotisSansSerif.gif
     */
    MB_OCR_FONT_ROTIS_SANS_SERIF,

    /** Rotis serif font
     @see http://www.identifont.com/samples2/adobe/RotisSerif.gif
     */
    MB_OCR_FONT_ROTIS_SERIF,

    /** Sabon font
     @see http://www.identifont.com/samples2/adobe/Sabon.gif
     */
    MB_OCR_FONT_SABON,

    /** Stone font */
    MB_OCR_FONT_STONE,

    /** SV basic manual font
     @see http://www.fontriver.com/i/fonts/sv_basic_manual/svbasicmanual_specimen.jpg
     */
    MB_OCR_FONT_SV_BASIC_MANUAL,

    /** Tahoma font
     @see http://www.identifont.com/samples2/microsoft/Tahoma.gif
     */
    MB_OCR_FONT_TAHOMA,

    /** Tahoma bold font
     @see http://www.identifont.com/samples2/ascender/TahomaBold.gif
     */
    MB_OCR_FONT_TAHOMA_BOLD,

    /** Tex gyre termes font
     @see http://www.cufonfonts.com/font_preview/908/texgyretermes-regular/large_preview
     */
    MB_OCR_FONT_TEX_GYRE_TERMES,

    /** Tex gyre termes italic font
     @see http://fontsov.com/data/font_face/texgyretermes-italic.png
     */
    MB_OCR_FONT_TEX_GYRE_TERMES_ITALIC,

    /** Sans mono condensed black font
     @see http://www.identifont.com/samples2/lucasfonts/TheSansMonoCondensedBlack.gif
     */
    MB_OCR_FONT_THE_SANS_MONO_CONDENSED_BLACK,

    /** Thesis font */
    MB_OCR_FONT_THESIS,

    /** Ticket de caisse font
     @see http://www.identifont.com/samples2/t26/TicketDeCaisse.gif
     */
    MB_OCR_FONT_TICKET_DE_CAISSE,

    /** Times new roman font
     @see http://www.identifont.com/samples2/adobe/TimesNewRoman.gif
     */
    MB_OCR_FONT_TIMES_NEW_ROMAN,

    /** Trajan font
     @see http://www.identifont.com/samples2/adobe/TrajanPro.gif
     */
    MB_OCR_FONT_TRAJAN,

    /** Trinite font
     @see http://luc.devroye.org/BramDeDoes-TriniteNo2MediumCondensed-1991.png
     */
    MB_OCR_FONT_TRINITE,

    /** Univers font
     @see http://www.identifont.com/samples2/linotype/Univers.gif
     */
    MB_OCR_FONT_UNIVERS,

    /** Verdana font
     @see http://www.identifont.com/samples2/microsoft/Verdana.gif
     */
    MB_OCR_FONT_VERDANA,

    /** Voltaire font
     @see http://www.identifont.com/samples2/google/Voltaire.gif
     */
    MB_OCR_FONT_VOLTAIRE,

    /** Walbaum font
     @see http://www.identifont.com/samples2/linotype/Walbaum.gif
     */
    MB_OCR_FONT_WALBAUM,

    /** Europa gro sb font
     http://www.identifont.com/samples/scangraphic/EuropaGroteskSB.gif
     */
    MB_OCR_FONT_EUROPA_GRO_SB,

    /** Europa gro sb light font
     @see https://cdnimg.fonts.net/CatalogImages/23/387088.png
     */
    MB_OCR_FONT_EUROPA_GRO_SB_LIGHT,

    /** Antonio regular font
     @see http://allfont.net/cache/img/abc-10116_02d993c053756333957f0eed2629cd07.png
     */
    MB_OCR_FONT_ANTONIO_REGULAR,

    /** Corporate S Light font
     @see http://www.fontsplace.com/free/images/c/corporate_s_light_font_preview_characters.gif
     */
    MB_OCR_FONT_CORPORATE_LIGHT,


    // SPECIAL FONTS

    /** MICR font */
    MB_OCR_FONT_MICR,

    /** Arabic font */
    MB_OCR_FONT_ARABIC_NILE,

    /** Unknown font */
    MB_OCR_FONT_UNKNOWN,

    /** XITS Math font */
    MB_OCR_FONT_XITS_MATH,

    /** Any of the other listed fonts */
    MB_OCR_FONT_ANY,

    /** Unknown math font */
    MB_OCR_FONT_UNKNOWN_MATH,

    /** Font found on UKDL licenses */
    MB_OCR_FONT_UKDL_LIGHT,

    /** Must be last as it holds the number of available fonts */
    MB_OCR_FONT_COUNT,

    /** German license plate font **/
    MB_OCR_FONT_FE_SCHRIFT
};

#endif
