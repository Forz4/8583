#include "8583.h"
/*
 CONSTANTS
 */
ISO8583_FILED_DEF_t ISO8583_FIELDS_DEF[128] = {
    /* FIELD 1 */  {"Bit Map                             ", 16 , 0 , ISO8583_FIELDTYPE_BIN},
    /* FIELD 2 */  {"Primary Account Number (PAN)        ", 19 , 2 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 3 */  {"Processing Code                     ", 6  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 4 */  {"Amount, Transaction                 ", 12 , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 5 */  {"Amount, Settlement                  ", 12 , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 6 */  {"Amount, Cardholder Billing          ", 12 , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 7 */  {"Transaction Date/Time               ", 10 , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 8 */  {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 9 */  {"Conversion Rate, Settlement         ", 8  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 10 */ {"Conversion Rate, Cardholder Billing ", 8  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 11 */ {"System Trace Audit Number           ", 6  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 12 */ {"Time, Local Transaction             ", 6  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 13 */ {"Date, Local Transaction             ", 4  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 14 */ {"Date, Expiration                    ", 4  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 15 */ {"Date, Settlement                    ", 4  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 16 */ {"Date, Conversion                    ", 4  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 17 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 18 */ {"Merchant's Type                     ", 4  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 19 */ {"Merchant Country Code               ", 3  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 20 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 21 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 22 */ {"Point Of Service Entry Mode Code    ", 3  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 23 */ {"Card Sequence Number                ", 3  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 24 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 25 */ {"Point Of Service Condition Code     ", 2  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 26 */ {"Point Of Service PIN Capture Code   ", 2  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 27 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 28 */ {"Amount,Transaction Fee              ", 9  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 29 */ {""                                    , 9  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 30 */ {""                                    , 9  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 31 */ {""                                    , 9  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 32 */ {"Acquiring Institution Id. Code      ", 11 , 2 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 33 */ {"Forwarding Institution Id. Code     ", 11 , 2 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 34 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 35 */ {"Track 2 Data                        ", 37 , 2 , ISO8583_FIELDTYPE_BIN},
    /* FIELD 36 */ {"Track 3 Data                        ", 104, 3 , ISO8583_FIELDTYPE_BIN},
    /* FIELD 37 */ {"Retrieval Reference Number          ", 12 , 0 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 38 */ {"Authorization Id. Response          ", 6  , 0 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 39 */ {"Response Code                       ", 2  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 40 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 41 */ {"Card Acceptor Terminal Id           ", 8  , 0 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 42 */ {"Card Acceptor Identification Code.  ", 15 , 0 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 43 */ {"Card Acceptor Name/Location         ", 40 , 0 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 44 */ {"Additional Response Data            ", 25 , 2 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 45 */ {"Track 1 Data                        ", 76 , 2 , ISO8583_FIELDTYPE_BIN},
    /* FIELD 46 */ {""                                    , 0  , 3 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 47 */ {""                                    , 0  , 3 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 48 */ {"Additional Data Private             ", 512, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 49 */ {"Currency Code, Transaction          ", 3  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 50 */ {"Currency Code, Settlement"           , 3  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 51 */ {"Currency Code, Cardholder Billing   ", 3  , 0 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 52 */ {"Pin Data                            ", 8  , 0 , ISO8583_FIELDTYPE_BIN},
    /* FIELD 53 */ {"Security Related Control Information", 16 , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 54 */ {"Addtional Amounts                   ", 40 , 3 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 55 */ {"ICC System Related Data             ", 255, 3 , ISO8583_FIELDTYPE_BIN},
    /* FIELD 56 */ {"Additional Data                     ", 512, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 57 */ {"Additional Data Private             ", 100, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 58 */ {""                                    , 0. , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 59 */ {"Detail Inquiring                    ", 600, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 60 */ {"Reserved                            ", 100, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 61 */ {"Cardholder Authentication Info      ", 200, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 62 */ {"Switching Data                      ", 200, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 63 */ {"Finacial Network Data               ", 512, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 64 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 65 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 66 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 67 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 68 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 69 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 70 */ {"Network Management Information Code ", 3  , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 71 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 72 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 73 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 74 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 75 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 76 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 77 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 78 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 79 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 80 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 81 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 82 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 83 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 84 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 85 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 86 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 87 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 88 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 89 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 90 */ {"Original Data Elements              ", 42 , 0 , ISO8583_FIELDTYPE_NUM},
    /* FIELD 91 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 92 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 93 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 94 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 95 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 96 */ {"Message Security Code               ", 8  , 0 , ISO8583_FIELDTYPE_BIN},
    /* FIELD 97 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 98 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 99 */ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 100*/ {"Receiving Institution Id Code       ", 11 , 2 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 101*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 102*/ {"Account Identification 1            ", 28 , 2 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 103*/ {"Account Identification 2            ", 28 , 2 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 104*/ {"Additional Data                     ", 512, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 105*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 106*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 107*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 108*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 109*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 110*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 111*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 112*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 113*/ {"Additional Data                     ", 512, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 114*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 115*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 116*/ {"Additional Data                     ", 512, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 117*/ {"Additional Data                     ", 256, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 118*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 119*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 120*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 121*/ {"CUPS Reserved                       ", 100, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 122*/ {"Acquiring Institution Reserved      ", 100, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 123*/ {"Issuer Institution Reserved         ", 100, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 124*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 125*/ {"Reserved                            ", 256, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 126*/ {"Reserved                            ", 256, 3 , ISO8583_FIELDTYPE_ASC},
    /* FIELD 127*/ {""                                    , 0  , 0 , ISO8583_FIELDTYPE_DEF},
    /* FIELD 128*/ {"Message Authentication Code         ", 8  , 0 , ISO8583_FIELDTYPE_BIN}
};

/*
 Parse message from pchBuf , a pointer to CUPS_MESSGE_t is returned if succeeded
 NULL is returned if failed and error message is written to pchErrmsg.
 */
CUPS_MESSAGE_t *CUPS8583_parseMessage( BYTE *pchBuf , char *pchErrmsg )
{
    /* allocate memory */
    CUPS_MESSAGE_t  *pmessage = (CUPS_MESSAGE_t *)malloc(sizeof(CUPS_MESSAGE_t));
    if ( pmessage == NULL ){
        if ( pchErrmsg )    sprintf( pchErrmsg , "malloc fail");
        return NULL;        
    }
    memset( pmessage , 0x00 , sizeof(CUPS_MESSAGE_t));

    int ret = 0;
    /* parse header */
    ret = CUPS8583_parseHeader( pchBuf, &(pmessage->header) );
    if ( ret != CUPS_HEADER_LENGTH + 4 ){
        if ( pchErrmsg )    sprintf( pchErrmsg , "parse header fail");
        free( pmessage );
        return NULL;
    }
    pchBuf += ret;

    /* parse bitmap */
    ret = CUPS8583_parseBitmap(pchBuf, &(pmessage->bitmap));
    pchBuf += ret;

    /* parse fields */
    ret = CUPS8583_parseFields(pchBuf , &(pmessage->bitmap) , pmessage->fields);

    return pmessage;
}

/* 
 Parse header from pchBuf
 returns total offset if succeeded ,for CUPS header offset should be 50
 returns -1 if failed.
*/
int CUPS8583_parseHeader( BYTE *pchBuf , CUPS_HEADER_t *pheader )
{
    int     offset = 0;

    /* Header Legnth */
    memcpy( pheader->pbytHeaderLength , pchBuf+offset , 1);
    if ( pheader->pbytHeaderLength[0] != CUPS_HEADER_LENGTH )   return -1;
    offset += 1;

    /* Header Flag and Version */
    memcpy( pheader->pbytHeaderFlagVersion , pchBuf+offset , 1);
    offset += 1;

    /* Total Message Length */
    memcpy( pheader->pbytTotalMessageLength , pchBuf+offset , 4);
    offset += 4;

    /* Destination ID */
    memcpy( pheader->pbytDestID , pchBuf+offset , 11 );
    offset += 11;

    /* Source ID */
    memcpy( pheader->pbytSourID , pchBuf+offset , 11 );
    offset += 11;    

    /* Reserved */
    memcpy( pheader->pbytReserved , pchBuf+offset , 3 );
    offset += 3;

    /* Batch Number */
    memcpy( pheader->pbytBatchNum , pchBuf+offset , 1);
    offset += 1;

    /* Trasaction Information */
    memcpy( pheader->pbytTransactionInfo , pchBuf+offset , 8 );
    offset += 8;

    /* User Information */
    memcpy( pheader->pbytUserInfo , pchBuf+offset , 1);
    offset += 1;

    /* Reject Code */
    memcpy( pheader->pbytRejectCode , pchBuf+offset , 5 );
    offset += 5;

    /* Message Type */
    memcpy( pheader->pbytMsgtype , pchBuf+offset , 4 );
    offset += 4;

    return offset;
}
/* 
 Parse bitmap from pchBuf
*/
int CUPS8583_parseBitmap( BYTE *pchBuf , CUPS_BITMAP_t *pbitmap )
{
    int offset = 0;
    int i = 0;
    int j = 0;
    /* check extended flag */
    if ( pchBuf[0] & 0x80 ) {
        pbitmap->bytIsExtend = 1;
        offset = 16;
    } else {
        pbitmap->bytIsExtend = 0;
        offset = 8;
    }
    for ( i = 0 ; i < offset ; i ++ )
        for ( j = 0 ; j < 8 ; j ++ )
            pbitmap->pbytFlags[i*8+j] = (pchBuf[i] & 1<<(7-j) ) == 0 ? '0' : '1';
    return offset;
}

/*
 Parse fields from pchBuf
 */
int CUPS8583_parseFields( BYTE *pchBuf , CUPS_BITMAP_t *bitmap , CUPS_FIELD_t  *pfields )
{
    int  i = 0;
    char temp[4];
    int  var = 0;
    for ( i = 1 ; i < 128 ; i ++ ){
        if ( bitmap->pbytFlags[i] == '1' ){
            /* check if field has variable length */
            if ( ISO8583_FIELDS_DEF[i].intVarFlag != 0 ){
                memset( temp , 0x00 , sizeof(temp));
                memcpy( temp , pchBuf , ISO8583_FIELDS_DEF[i].intVarFlag );
                int varLen = atoi(temp);
                if ( varLen > ISO8583_FIELDS_DEF[i].intMaxLengthInBytes ){
                    return -1;
                } else {
                    pfields[i].intDataLength = varLen;
                    pchBuf += ISO8583_FIELDS_DEF[i].intVarFlag;
                }
            } else {
                pfields[i].intDataLength  = ISO8583_FIELDS_DEF[i].intMaxLengthInBytes;
            }
            pfields[i].pchData = (BYTE *)malloc(pfields->intDataLength);
            memcpy( pfields[i].pchData , pchBuf , pfields[i].intDataLength);
            pchBuf += pfields[i].intDataLength;
        }
    }
    return 0;
}
/*
 Print message
 */
void CUPS8583_printMessage( CUPS_MESSAGE_t *pmessage)
{
    printf("==================   Header      ==================\n");
    CUPS8583_printHex( pmessage->header.pbytHeaderLength,       1  , "HEADER LENGTH"        , 1);
    CUPS8583_printHex( pmessage->header.pbytHeaderFlagVersion,  1  , "HEADER FLAG VERSION"  , 2);
    CUPS8583_printHex( pmessage->header.pbytTotalMessageLength, 4  , "TOTAL MESSAGE LENGTH" , 3);
    CUPS8583_printHex( pmessage->header.pbytDestID,             11 , "DESTINATION ID"       , 4);
    CUPS8583_printHex( pmessage->header.pbytSourID,             11 , "SOURCE ID"            , 5);
    CUPS8583_printHex( pmessage->header.pbytReserved,           3  , "RESERVED"             , 6);
    CUPS8583_printHex( pmessage->header.pbytBatchNum,           1  , "BATCH NUMBER"         , 7);
    CUPS8583_printHex( pmessage->header.pbytTransactionInfo,    8  , "TRASACTION INFORMATION",8);
    CUPS8583_printHex( pmessage->header.pbytUserInfo,           1  , "USER INFORMATION"     , 9);
    CUPS8583_printHex( pmessage->header.pbytRejectCode,         5  , "REJECT CODE"          , 10);

    printf("==================  Msg Type     ==================\n");
    CUPS8583_printHex( pmessage->header.pbytMsgtype,            4  , "MSGTYPE"              , 0);

    printf("==================   Bit Map     ==================\n");
    for( int i = 0 ; i < (pmessage->bitmap.bytIsExtend == 1 ? 128 : 64) ; i ++){
        printf("%c" , pmessage->bitmap.pbytFlags[i]);
        if ( (i+1) % 8 == 0 )   printf(" ");
        if ( (i+1) % 32 == 0 )   printf("\n");
    }

    printf("==================  Body Fields  ==================\n");
    for( int i = 1 ; i < (pmessage->bitmap.bytIsExtend == 1 ? 128 : 64) ; i ++){
        if ( pmessage->bitmap.pbytFlags[i] == '1' ){
            CUPS8583_printHex( pmessage->fields[i].pchData , pmessage->fields[i].intDataLength  , ISO8583_FIELDS_DEF[i].pbytInfo , i+1 );
        }
    }
    return;
}
void CUPS8583_printHex( BYTE *buf , int size , char *info , int index)
{
    int i = 0;
    int j = 0;
    char ch = 0;
    for ( i = 0 ; i <= size/16 ; i ++){
        printf( "FIELD[%3d][LEN:%3d][%-40s]< " , index , size , info);
        for ( j = 0 ; j+i*16 < size && j < 16 ;j ++){
            ch = (unsigned char)buf[j+i*16];
            printf( "%02X " , ch);
        }
        while ( j++ < 16 ){
            printf( "   ");
        }
        printf( " > ");
        for ( j = 0 ; j+i*16 < size && j < 16 ; j ++ ){
            int pos = j+i*16;
            if ( (buf[pos] >= 32 && buf[pos] <= 126) ){
                printf( "%c" , buf[pos]);
            } else {
                printf( ".");
            }
        }
        printf( "\n");
   }
   return;
}



