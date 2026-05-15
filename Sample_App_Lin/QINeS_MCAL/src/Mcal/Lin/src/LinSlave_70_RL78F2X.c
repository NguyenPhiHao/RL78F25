/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : LinSlave_70_RL78F2X.c                                        */
/* Version     : v1.00.02                                                     */
/* Contents    : LIN  Slave Module API source                                 */
/*             : This specification specifies the functionality, API and the  */
/*               configuration of the AUTOSAR Basic Software module           */
/*               LIN Interface (LinIf) and the LIN Transport Protocol (LinTp).*/
/*               The LIN TP is a part of the LIN Interface.                   */
/*                                                                            */
/*               The base for this document is the LIN 2.1 specification.     */
/*               It is assumed that the reader is familiar with this          */
/*               specification. This document will not describe LIN 2.1       */
/*               functionality again but it will try to follow the same order */
/*               as the LIN 2.1 specification.                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Lin.h"
#include "Lin_70_RL78F2X.h"
#include "Lin_Slave_70_RL78F2X.h"
#include "LinIf.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_SLAVE_70_VENDOR_ID_RL78F2X_C                      ( 70U )
#define LIN_SLAVE_70_MODULE_ID_RL78F2X_C                      ( 82U )
 
#define LIN_SLAVE_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C       ( 22U )
#define LIN_SLAVE_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C       ( 11U )
#define LIN_SLAVE_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C    ( 0U )
 
#define LIN_SLAVE_70_SW_MAJOR_VERSION_RL78F2X_C               ( 1U )
#define LIN_SALVE_70_SW_MINOR_VERSION_RL78F2X_C               ( 0U )
#define LIN_SLAVE_70_SW_PATCH_VERSION_RL78F2X_C               ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/*---------------Lin.h -------------------------------------------------------*/
/* Check if current file and Lin.h header file are of the same Vendor ID */
#if (LIN_SLAVE_70_VENDOR_ID_RL78F2X_C    != LIN_VENDOR_ID)
    #error "Vendor ID of Lin.c and Lin.h are different"
#endif
 
#if (LIN_SLAVE_70_MODULE_ID_RL78F2X_C    != LIN_MODULE_ID)
    #error "Module ID of Lin.c and Lin.h are different"
#endif
 
/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_SLAVE_70_SW_MAJOR_VERSION_RL78F2X_C    != LIN_SW_MAJOR_VERSION) ||\
     (LIN_SALVE_70_SW_MINOR_VERSION_RL78F2X_C    != LIN_SW_MINOR_VERSION) ||\
     (LIN_SLAVE_70_SW_PATCH_VERSION_RL78F2X_C    != LIN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lin.c and Lin.h are different"
#endif
 
/* Check if current file and Lin.h header file are of the same Autosar version */
#if ((LIN_SLAVE_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != LIN_AR_RELEASE_MAJOR_VERSION)   ||\
     (LIN_SLAVE_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != LIN_AR_RELEASE_MINOR_VERSION)   ||\
     (LIN_SLAVE_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lin.c and Lin.h are different"
#endif
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/*** LCUCn ***/
#define LCUC_OM0                        (0x01)      /* 0: LIN reset mode 1: Not LIN reset mode */
#define LCUC_OM1                        (0x02)      /* 0:LIN wake-up mode 1:LIN operation mode */
/*** LESTn ***/
#define LEST_BER                        (0x01)      /* 0: Bit error not detected 1: Bit error detected */
#define LEST_PBER                       (0x02)      /* 0: Physical bus error not detected 1: Physical bus error detected */
#define LEST_FTER                       (0x04)      /* 0: Frame/response timeout error not detected 1: Frame/response timeout error detected */
#define LEST_FER                        (0x08)      /* 0: Framing error not detected 1: Framing error detected */
#define LEST_CSER                       (0x20)      /* 0: Checksum error not detected 1: Checksum error detected */
#define LEST_RPER                       (0x80)      /* 0: Response preparation error not detected 1: Response preparation error detected */
/*** LDFCn ***/
#define LDFC_RFT                        (0x10)      /* 0:Receive 1:Send */
#define LDFC_CSM                        (0x20)      /* 0: Classic 1: Enhance */
#define LDFC_FSM                        (0x40)      /* 0: Not frame separate mode 1: Frame separate mode */
#define LDFC_LSS                        (0x80)      /* 0: The next data group to be sent and received is the last. 1: The next data group to be sent or received is not the final one. */
#define LDFC_RCD                        (0x10)      /* 0:Receive 1:Send in slave */
 
/* Error bit of LEST */
#define LIN_70_SLV_LEST_RPER    (0x80)
#define LIN_70_SLV_LEST_IPER    (0x40)
#define LIN_70_SLV_LEST_CSER    (0x20)
#define LIN_70_SLV_LEST_SFER    (0x10)
#define LIN_70_SLV_LEST_FER     (0x08)
#define LIN_70_SLV_LEST_TER     (0x04)
#define LIN_70_SLV_LEST_BER     (0x01)
 
/* Error bit of LRSS */
#define LIN_70_SLV_LRSS_RSDD    (0x01)
 
 
/* LDFC LCS checksum type */
#define LIN_70_ENHANCED_LCS  (0x20)
#define LIN_70_CLASSIC_LCS   (0x00)
 
/* LDFC RCDS TX/RX */
#define LIN_70_LDFC_RCDS_RX  (0x00)
#define LIN_70_LDFC_RCDS_TX  (0x10)
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
 
#if ( LIN_70_SLAVE_LRSS_ERROR == TRUE )
static void Lin_70_RL78F2X_SlaveLrssError( uint8 channelId );
#endif /* ( LIN_70_SLAVE_LRSS_ERROR == TRUE ) */
static void lin_WriteLDBBuffer( uint8* buf, uint8 len );
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
extern volatile LIN_70_RL78Type* s_lin_reg;
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#define LIN_START_SEC_VAR_NO_INIT_GLOBAL_UNSPECIFIED
#include "Lin_MemMap.h"
 
 
/* Rx buffer of LDBn register is 8byte */
static  uint8   s_rcvBuff[8];
 
/* LDFC LCS checksum */
static  uint8   linChecksum;
 
/* Lin_Pdu */
static Lin_PduType  lin_pdu;
 
/* Return value of LinIf_HeaderIndication */
static Std_ReturnType  s_Lin_LinIfHedIndStat;
 
#define LIN_STOP_SEC_VAR_NO_INIT_GLOBAL_UNSPECIFIED
#include "Lin_MemMap.h"
 
#define LIN_START_SEC_CODE_LOCAL
#include "Lin_MemMap.h"
 
 
#if ( LIN_70_SLAVE_LRSS_ERROR == TRUE )
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_SlaveLrssError                                */
/* Param       : (in) channelId                                               */
/* Return      : -                                                            */
/* Contents    : Check LRSS register and repot error to LinIf .               */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
static void Lin_70_RL78F2X_SlaveLrssError( uint8 channelId )
{
    uint8   lrss;
   
    /* reading Response Space Dominant Detection Status Register */
    lrss = s_lin_reg->LRSS_REG;
 
    /* if Response Space Dominant Detection Status is true, calling LinIf. */
    if ( LIN_70_SLV_LRSS_RSDD == (lrss & LIN_70_SLV_LRSS_RSDD) ) {
        /* [SWS_Lin_00281] Call LinIf_ErrorIndication */
        LinIf_LinErrorIndication( channelId, LIN_ERR_INC_RESP );
    }
}
#endif /* ( LIN_70_SLAVE_LRSS_ERROR == TRUE ) */
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : lin_WriteLDBBuffer                                           */
/* Param       : (in) *buf    :  buffer                                       */
/*                    len     :  buffer size                                  */
/* Return      : -                                                            */
/* Contents    : Write tx data to LDB rester                                  */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
static void    lin_WriteLDBBuffer( uint8* buf, uint8 len )
{
    uint8  i;
   
    for ( i = 0U; i < len; i++ ) {
        s_lin_reg->LDB_REG[i]  = buf[i];
    }
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : LinSlave_Init                                                */
/* Param       : (in) channelId  :  Lin channel ID <0|1>                      */
/* Return      : -                                                            */
/* Contents    : Initializes the LIN Slave.                                   */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_SlvInit( uint8 channelId )
{
    /* Baud rate configure */
    s_lin_reg->LWBR_REG = (uint8)(LIN_70_LWBR_LPRS_1_1 | LIN_70_LWBR_NSPB_4);
 
    /* LIN mode register configuration */
    s_lin_reg->LMD_REG  = (uint8)(LIN_70_LMD_AUTO | LIN_70_LMD_LCKS_FA | LIN_70_LMD_LIOS);
 
    /* setting MK1L,MK0H,MK2L,MK3L registers to enable interrupts of Lin. */
    lin_setMKxx( channelId );
 
    /* setting lin Interrupt register */
    s_lin_reg->LIE_REG = (uint8)(LIN_70_LIE_FTCIE | LIN_70_LIE_FRCIE | LIN_70_LIE_ERRIE | LIN_70_LIE_SHIE);
 
 
    /* Error detect enable */
    /* Configuration of Error Detection Enable register  */
    /* Original bit are all zero./ all error are disable */
    /* Error detect enable */
    s_lin_reg->LEDE_REG = (uint8)0;
 
    /* setting break field in transmission frame header */
    /* original bit are all zero. */
    /* Frame configuration parameter configure */
    s_lin_reg->LBFC_REG = (uint8)0;
 
    /* setting Inter byte space of transmission frame header */
    /* ( LIN_70_INTERBYTE_SPACE_HEADER | LIN_70_INTERBYTE_SPACE ) ->  all zero. */
    s_lin_reg->LSC_REG = (uint8)( LIN_70_INTERBYTE_SPACE_HEADER | LIN_70_INTERBYTE_SPACE );
 
   
    /* set the low width of the wake-up signal transmission */
    /* mastaer is 0xf0 */
    /* Wakeup signal width >> 16Tbit */
    s_lin_reg->LWUP_REG = (uint8)LIN_70_WAKEUP_WIDTH;
   
    LIN_70_RL78F2X_ISC = (uint8)( LIN_70_RL78F2X_ISC_ISC4 | LIN_70_RL78F2X_ISC_ISC3 | LIN_70_RL78F2X_ISC_ISC2 | LIN_70_RL78F2X_ISC_ISC0 );
 
    /* Transition  LIN operational mode */
    (void)lin_chModeChange( (uint8)(LCUC_OM0 | LCUC_OM1) );
 
    /* LTRCn = LTRC_FTS; */
    Lin_70_RL78F2X_StartCommunication();
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_SlaveIsrTx                                    */
/* Param       : (in) channelId  :  Lin channel ID <0|1>                      */
/* Return      : -                                                            */
/* Contents    : Transmit interrupt process.                                  */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_SlaveIsrTx( uint8 channelId )
{
    Std_ReturnType  stdResult = E_NOT_OK;
    uint8           chIndex;
   
    stdResult = Lin_searchChIndex( channelId, &chIndex );
    if ( stdResult == E_OK ) {
        /* change channel */
        Lin_70_RL78F2X_ChangeChannel( channelId );
       
        /* If wakeup occured, set lin mode to Lin communication */
        if (s_Lin_Status[chIndex].WakeupStatus) {
            s_Lin_Status[chIndex].ChannelStatus = LIN_CH_OPERATIONAL;
            (void)lin_chModeChange( (uint8)(LCUC_OM0 | LCUC_OM1) );
 
            /* LTRCn = LTRC_FTS; */
            Lin_70_RL78F2X_StartCommunication();
            s_Lin_Status[chIndex].WakeupStatus = FALSE;
        } else {
            /* check header */
            if ( E_OK == s_Lin_LinIfHedIndStat ) {
                /* check slave response(tx) */
                if ( LIN_FRAMERESPONSE_TX == lin_pdu.Drc){
                    /* [SWS_LinIf_91006] */
                    LinIf_TxConfirmation ( channelId );
                } else {
                    /* do nothing */
                } /* for winAMS C1 MC/DC */
            } else {
                /* do nothing */
            } /* for winAMS C1 MC/DC */
        }
        /* set LIN status register that response or wakeup transmission incomplete */
        s_lin_reg->LST_REG &= (uint8)~(LIN_70_LST_FTC);
    }
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_Isr_SlvRx                                             */
/* Param       : (in) channelId  :  Lin channel ID <0|1>                      */
/* Return      : -                                                            */
/* Contents    : Reception interrupt process.                                 */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_SlaveIsrRx( uint8 channelId )
{
    Std_ReturnType  stdResult = E_NOT_OK;
    uint8           chIndex;
 
    stdResult = Lin_searchChIndex( channelId, &chIndex );
    if ( stdResult == E_OK ) {
       
        /* change channel */
        Lin_70_RL78F2X_ChangeChannel( channelId );
 
    #if ( LIN_70_SLAVE_LRSS_ERROR == TRUE )
        /* checking LRSS register */
        Lin_70_RL78F2X_SlaveLrssError( channelId );
    #endif /* ( LIN_70_SLAVE_LRSS_ERROR == TRUE ) */
 
        switch ( s_Lin_Status[chIndex].ChannelStatus ) {
        case LIN_CH_OPERATIONAL:
            /* Check header */
            if (s_Lin_Status[chIndex].FrameStatus == LIN_SEND_HEADER) {
 
                /* s_lin_reg->LIDB_REG : PID */
                /* SWS_Lin_00280 */
                lin_pdu.Pid    = s_lin_reg->LIDB_REG;
                lin_pdu.SduPtr = s_rcvBuff;
 
                /* [SWS_Lin_00235] */
                s_Lin_LinIfHedIndStat = LinIf_HeaderIndication ( channelId, &lin_pdu );
               
                /* when rx data is a lin frame header */
                if (E_OK == s_Lin_LinIfHedIndStat) {
                    /* Lin pdu is occured */
 
                    /* checksum */
                    if ( LIN_ENHANCED_CS == lin_pdu.Cs ) {
                        linChecksum = LIN_70_ENHANCED_LCS;
                    } else {
                        linChecksum = LIN_70_CLASSIC_LCS;
                    }
 
                    if (( LIN_FRAMERESPONSE_RX     == lin_pdu.Drc) ||
                        ( LIN_FRAMERESPONSE_IGNORE == lin_pdu.Drc)) {
                        /* rx data is a master response */
 
                        /* LIN2.x frame      */
                        s_lin_reg->LDFC_REG = ((uint8)(lin_pdu.Dl) | linChecksum | LIN_70_LDFC_RCDS_RX );
 
                        /* setting status to a lin frame response */
                        s_Lin_Status[chIndex].FrameStatus = LIN_SEND_RESPONSE;
                    } else if ( LIN_FRAMERESPONSE_TX == lin_pdu.Drc){
                        /* slave responce */
                        /* rx data is a slave response */
                        lin_WriteLDBBuffer( lin_pdu.SduPtr, lin_pdu.Dl );
                       
                        /* LIN2.x frame      */
                        /* set tx with enhanced encoding  */
                        s_lin_reg->LDFC_REG = ((uint8)(lin_pdu.Dl) | linChecksum | LIN_70_LDFC_RCDS_TX );
                    } else{
                        /* do nothing */
                    }  /* for winAMS C1 MC/DC */
                    /* Start sending and receiving responses */
                    s_lin_reg->LTRC_REG = (uint8)LIN_70_LTRC_RTS;
                } else {
                    /* No header */
                    s_lin_reg->LTRC_REG = (uint8)LIN_70_LTRC_LNRR;
                }
            } else { /* s_Lin_Status[chIndex].FrameStatus == LIN_SEND_RESPONSE */
                /* Lin Slave Response frame */
                if (E_OK == s_Lin_LinIfHedIndStat) {
                    /* Header is no error */
                    if (LIN_FRAMERESPONSE_RX == lin_pdu.Drc) {
                        /* rx data is a master response */
 
                        /* read rx data */
                        Lin_70_RL78F2X_ReadReceivedData( s_rcvBuff );
 
                        /* [SWS_LinIf_91005] */
                        LinIf_RxIndication ( channelId, s_rcvBuff );
                    } else if (LIN_FRAMERESPONSE_IGNORE == lin_pdu.Drc) {
                        /* do nothing */
                    } else {
                        /* do nothing */
                    }
                } else {
                    /* No responce */
                }
                /* setting status to a lin frame header */
                s_Lin_Status[chIndex].FrameStatus = LIN_SEND_HEADER;
            }
            break;
 
        case LIN_CH_SLEEP:
            /* receive wakeup */
            (void)lin_chModeChange( LCUC_OM0 | LCUC_OM1 );
 
            /* header reception/wake-up transmission/reception starting */
            s_lin_reg->LTRC_REG = LIN_70_LTRC_FTS;
            s_Lin_Status[chIndex].ChannelStatus = LIN_CH_OPERATIONAL;
            break;
 
        default:
            break;
        }
 
        /* clearing the frame/wake-up reception completion flag, data 1 reception-  */
        /* completion flag, and header reception completion flag. */
        s_lin_reg->LST_REG &= (uint8)~(LIN_70_LST_FRC | LIN_70_LST_D1RC | LIN_70_LST_HTRC);
    }
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_SlaveIsrError                                 */
/* Param       : (in) channelId  :  Lin channel ID <0|1>                      */
/* Return      : -                                                            */
/* Contents    : Error interrupt process.                                     */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_SlaveIsrError( uint8 channelId )
{
    uint8               errStat = 0U;
    Lin_SlaveErrorType  slaveErrStat = LIN_ERR_NONE;
    Std_ReturnType      stdResult = E_NOT_OK;
    uint8               chIndex;
 
    stdResult = Lin_searchChIndex( channelId, &chIndex );
    if ( stdResult == E_OK ) {
 
        /* change channel */
        Lin_70_RL78F2X_ChangeChannel( channelId );
 
        /* saving error bit */
        s_Lin_Status[chIndex].ErrorStatus = s_lin_reg->LEST_REG;
        errStat = s_Lin_Status[chIndex].ErrorStatus;
 
        /* clearing status register */
        s_lin_reg->LST_REG = (uint8)0;
 
        if (s_Lin_Status[chIndex].FrameStatus == LIN_SEND_HEADER)
        /* header */
        {
            slaveErrStat = LIN_ERR_HEADER;
        } else
        /* except header */
        {
            if ( (errStat & LIN_70_SLV_LEST_RPER) == LIN_70_SLV_LEST_RPER ){
                /* RPER Response Preparation Error */
                slaveErrStat = LIN_ERR_RESP_CHKSUM;
            } else if ( (errStat & LIN_70_SLV_LEST_IPER) == LIN_70_SLV_LEST_IPER )
            /* IPER ID Parity error */
            {
                slaveErrStat = LIN_ERR_RESP_CHKSUM;
            } else if ( (errStat & LIN_70_SLV_LEST_CSER) == LIN_70_SLV_LEST_CSER )
            /* CSER Checksum Error */
            {
                slaveErrStat = LIN_ERR_RESP_CHKSUM;
            } else if ( (errStat & LIN_70_SLV_LEST_SFER) == LIN_70_SLV_LEST_SFER )
            /* SFER Sink field error */
            {
                slaveErrStat = LIN_ERR_INC_RESP;
            } else if ( (errStat & LIN_70_SLV_LEST_FER) == LIN_70_SLV_LEST_FER )
            /* FER Framing Error */
            {
                slaveErrStat = LIN_ERR_INC_RESP;
            } else if ( (errStat & LIN_70_SLV_LEST_TER) == LIN_70_SLV_LEST_TER )
            /* TER timeout error */
            {
                slaveErrStat = LIN_ERR_NO_RESP;
            } else if ( (errStat & LIN_70_SLV_LEST_BER) == LIN_70_SLV_LEST_BER )
            /* BER bit error */
            {
                slaveErrStat = LIN_ERR_RESP_DATABIT;
            }
        }
 
        /* Error notification */
        if ( slaveErrStat != LIN_ERR_NONE ) {
            /* [SWS_Lin_00281] Call LinIf_ErrorIndication */
            LinIf_LinErrorIndication( channelId, slaveErrStat );
        }
    }
}

#define LIN_STOP_SEC_CODE_LOCAL
#include "Lin_MemMap.h"

/* EOF LinSlave_70_RL78F2X.c **************************************************/