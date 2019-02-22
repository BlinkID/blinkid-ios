//
//  MBPaymentCardIssuer.h
//  MicroBlink
//
//  Created by Jura on 07/02/2019.
//

#ifndef MBPaymentCardIssuer_h
#define MBPaymentCardIssuer_h

typedef NS_ENUM(NSUInteger, MBCardIssuer) {
    /* Unidentified Card */
    MBCardIssuerOther = 0,
    /* The American Express Company Card */
    MBCardIssuerAmericanExpress,
    /* The Bank of Montreal ABM Card */
    MBCardIssuerBmoAbm,
    /* China T-Union Transportation Card */
    MBCardIssuerChinaTUnion,
    /* China UnionPay Card */
    MBCardIssuerChinaUnionPay,
    /* Canadian Imperial Bank of Commerce Advantage Debit Card */
    MBCardIssuerCibcAdvantageDebit,
    /* CISS Card */
    MBCardIssuerCiss,
    /* Diners Club International Card */
    MBCardIssuerDinersClubInternational,
    /* Diners Club United States & Canada Card */
    MBCardIssuerDinersClubUsCanada,
    /* Discover Card */
    MBCardIssuerDiscoverCard,
    /* HSBC Bank Canada Card */
    MBCardIssuerHsbc,
    /* RuPay Card */
    MBCardIssuerRuPay,
    /* InterPayment Card */
    MBCardIssuerInterPayment,
    /* InstaPayment Card */
    MBCardIssuerInstaPayment,
    /* The JCB Company Card */
    MBCardIssuerJcb,
    /* Laser Debit Card (deprecated) */
    MBCardIssuerLaser,
    /* Maestro Debit Card */
    MBCardIssuerMaestro,
    /* Dankort Card */
    MBCardIssuerDankort,
    /* MIR Card */
    MBCardIssuerMir,
    /* MasterCard Inc. Card */
    MBCardIssuerMasterCard,
    /* The Royal Bank of Canada Client Card */
    MBCardIssuerRbcClient,
    /* ScotiaBank Scotia Card */
    MBCardIssuerScotiaBank,
    /* TD Canada Trust Access Card */
    MBCardIssuerTdCtAccess,
    /* Troy Card */
    MBCardIssuerTroy,
    /* Visa Inc. Card */
    MBCardIssuerVisa,
    /* Universal Air Travel Plan Inc. Card */
    MBCardIssuerUatp,
    /* Interswitch Verve Card */
    MBCardIssuerVerve
};

#endif /* MBPaymentCardIssuer_h */
