/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Lin_70_RL78F2X.h                                             */
/* Version     : v1.00.02                                                     */
/* Contents    : LIN  Module HW dependent header                              */
/*               The LIN is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef Lin_70_RL78F2X_H
#define Lin_70_RL78F2X_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Lin.h"
#include "Lin_70_RL78F2X_HwReg.h"
#include "Lin_70_Types.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_70_VENDOR_ID_RL78F2X_H                      ( 70U )
#define LIN_70_MODULE_ID_RL78F2X_H                      ( 82U )

#define LIN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H       ( 22U )
#define LIN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H       ( 11U )
#define LIN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H    ( 0U )

#define LIN_70_SW_MAJOR_VERSION_RL78F2X_H               ( 1U )
#define LIN_70_SW_MINOR_VERSION_RL78F2X_H               ( 0U )
#define LIN_70_SW_PATCH_VERSION_RL78F2X_H               ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*--------------------Lin_70_RL78F2X_HwReg.h version check start-------------------*/
#if ( LIN_70_VENDOR_ID_RL78F2X_H != LIN_70_VENDOR_ID_RL78F2X_HWREG_H )
    #error "VENDOR ID for Lin_70_RL78F2X.h and Lin_70_RL78F2X_HwReg.h are different"
#endif

#if ( LIN_70_MODULE_ID_RL78F2X_H != LIN_70_MODULE_ID_RL78F2X_HWREG_H )
    #error "MODULE ID for Lin_70_RL78F2X.h and Lin_70_RL78F2X_HwReg.h are different"
#endif

#if ( ( LIN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    != \
        LIN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_HWREG_H ) || \
      ( LIN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    != \
        LIN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_HWREG_H ) || \
      ( LIN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != \
        LIN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_HWREG_H ) \
    )
    #error "AUTOSAR Version Numbers of Lin_70_RL78F2X.h and Lin_70_RL78F2X_HwReg.h are different"
#endif

#if ( ( LIN_70_SW_MAJOR_VERSION_RL78F2X_H != LIN_70_SW_MAJOR_VERSION_RL78F2X_HWREG_H ) || \
      ( LIN_70_SW_MINOR_VERSION_RL78F2X_H != LIN_70_SW_MINOR_VERSION_RL78F2X_HWREG_H ) || \
      ( LIN_70_SW_PATCH_VERSION_RL78F2X_H != LIN_70_SW_PATCH_VERSION_RL78F2X_HWREG_H ) \
    )
    #error "Software Version Numbers of Lin_70_RL78F2X.h and Lin_70_RL78F2X_HwReg.h are different"
#endif

/*--------------------Lin_70_Types.h version check start-------------------*/
#if ( LIN_70_VENDOR_ID_RL78F2X_H != LIN_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Lin_70_RL78F2X.h and Lin_70_Types.h are different"
#endif

#if ( LIN_70_MODULE_ID_RL78F2X_H != LIN_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Lin_70_RL78F2X.h and Lin_70_Types.h are different"
#endif

#if ( ( LIN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != LIN_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( LIN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != LIN_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( LIN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != \
        LIN_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Lin_70_RL78F2X.h and Lin_70_Types.h are different"
#endif

#if ( ( LIN_70_SW_MAJOR_VERSION_RL78F2X_H != LIN_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( LIN_70_SW_MINOR_VERSION_RL78F2X_H != LIN_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( LIN_70_SW_PATCH_VERSION_RL78F2X_H != LIN_70_SW_PATCH_VERSION_TYPES_H ) \
    )
    #error "Software Version Numbers of Lin_70_RL78F2X.h and Lin_70_Types.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

 /* Macros for setting bits of Hw registers */

#define LIN_70_GO_TO_SLEEP_ID            ( ( uint8 ) 0x3CU )

/* Go-to-sleep command length */
#define LIN_70_GO_TO_SLEEP_LENGTH        ( ( uint8 ) 0x08U )

 /* masking the length of the response field data */
#define LIN_70_MASK_LENGTH               ( ( uint8 ) 0x0FU )

/*** LDFCn ***/
/* Bit settings for configuring the LIN Data Field Configuration Register */
/* RFT(4) */
#define LIN_70_LDFC_RFT                  ( ( uint8 ) 0x10U )
/* CSM(5) */
#define LIN_70_LDFC_CSM                  ( ( uint8 ) 0x20U )
/* FSM(6) */
#define LIN_70_LDFC_FSM                  ( ( uint8 ) 0x40U )
/* LSS(7) */
#define LIN_70_LDFC_LSS                  ( ( uint8 ) 0x80U )

/*** LESTn ***/
#define LIN_70_LEST_FTER                 ( ( uint8 ) 0x04U )

/* Bit setting LIN Status Register */
/* FTC(0) */
#define LIN_70_LST_FTC                   ( ( uint8 ) 0x01U )
/* FRC(1) */
#define LIN_70_LST_FRC                   ( ( uint8 ) 0x02U )
/* ERR(3) */
#define LIN_70_LST_ERR                   ( ( uint8 ) 0x08U )
/* D1RC(6) */
#define LIN_70_LST_D1RC                  ( ( uint8 ) 0x40U )
/* HTRC(7) */
#define LIN_70_LST_HTRC                  ( ( uint8 ) 0x80U )

/* Bit settings for transmission Control Register */
/* FTS(0) for starting the LIN Communication */
#define LIN_70_LTRC_FTS                  ( ( uint8 ) 0x01U )
/* RTS(1) for starting transmission/Reception response */
#define LIN_70_LTRC_RTS                  ( ( uint8 ) 0x02U )
/* LNRR(2) for no response against reception id */
#define LIN_70_LTRC_LNRR                 ( ( uint8 ) 0x04U )

/*** LWUPn ***/
/* WUTL(7-4): Wake-up Transmission Low Width Select */
#define LIN_70_LWUP_WUTL_1               ( ( uint8 ) 0x00U )
#define LIN_70_LWUP_WUTL_2               ( ( uint8 ) 0x10U )
#define LIN_70_LWUP_WUTL_3               ( ( uint8 ) 0x20U )
#define LIN_70_LWUP_WUTL_4               ( ( uint8 ) 0x30U )
#define LIN_70_LWUP_WUTL_5               ( ( uint8 ) 0x40U )
#define LIN_70_LWUP_WUTL_6               ( ( uint8 ) 0x50U )
#define LIN_70_LWUP_WUTL_7               ( ( uint8 ) 0x60U )
#define LIN_70_LWUP_WUTL_8               ( ( uint8 ) 0x70U )
#define LIN_70_LWUP_WUTL_9               ( ( uint8 ) 0x80U )
#define LIN_70_LWUP_WUTL_10              ( ( uint8 ) 0x90U )
#define LIN_70_LWUP_WUTL_11              ( ( uint8 ) 0xA0U )
#define LIN_70_LWUP_WUTL_12              ( ( uint8 ) 0xB0U )
#define LIN_70_LWUP_WUTL_13              ( ( uint8 ) 0xC0U )
#define LIN_70_LWUP_WUTL_14              ( ( uint8 ) 0xD0U )
#define LIN_70_LWUP_WUTL_15              ( ( uint8 ) 0xE0U )
#define LIN_70_LWUP_WUTL_16              ( ( uint8 ) 0xF0U )

/*** LSCn ***/
/* IBSH(2-0): Inter-Byte Space (Header) */
#define LIN_70_LSC_IBSH_0                ( ( uint8 ) 0x00U )
#define LIN_70_LSC_IBSH_1                ( ( uint8 ) 0x01U )
#define LIN_70_LSC_IBSH_2                ( ( uint8 ) 0x02U )
#define LIN_70_LSC_IBSH_3                ( ( uint8 ) 0x03U )
#define LIN_70_LSC_IBSH_4                ( ( uint8 ) 0x04U )
#define LIN_70_LSC_IBSH_5                ( ( uint8 ) 0x05U )
#define LIN_70_LSC_IBSH_6                ( ( uint8 ) 0x06U )
#define LIN_70_LSC_IBSH_7                ( ( uint8 ) 0x07U )
/* IBS(5-4) */
#define LIN_70_LSC_IBS_0                 ( ( uint8 ) 0x00U )
#define LIN_70_LSC_IBS_1                 ( ( uint8 ) 0x01U )
#define LIN_70_LSC_IBS_2                 ( ( uint8 ) 0x02U )
#define LIN_70_LSC_IBS_3                 ( ( uint8 ) 0x03U )

/*** LBFCn ***/
/* BLT(3-0): set the break width of the transmission frame header */
#define LIN_70_LBFC_BLT_13               ( ( uint8 ) 0x00U )
#define LIN_70_LBFC_BLT_14               ( ( uint8 ) 0x01U )
#define LIN_70_LBFC_BLT_15               ( ( uint8 ) 0x02U )
#define LIN_70_LBFC_BLT_16               ( ( uint8 ) 0x03U )
#define LIN_70_LBFC_BLT_17               ( ( uint8 ) 0x04U )
#define LIN_70_LBFC_BLT_18               ( ( uint8 ) 0x05U )
#define LIN_70_LBFC_BLT_19               ( ( uint8 ) 0x06U )
#define LIN_70_LBFC_BLT_20               ( ( uint8 ) 0x07U )
#define LIN_70_LBFC_BLT_21               ( ( uint8 ) 0x08U )
#define LIN_70_LBFC_BLT_22               ( ( uint8 ) 0x09U )
#define LIN_70_LBFC_BLT_23               ( ( uint8 ) 0x0AU )
#define LIN_70_LBFC_BLT_24               ( ( uint8 ) 0x0BU )
#define LIN_70_LBFC_BLT_25               ( ( uint8 ) 0x0CU )
#define LIN_70_LBFC_BLT_26               ( ( uint8 ) 0x0DU )
#define LIN_70_LBFC_BLT_27               ( ( uint8 ) 0x0EU )
#define LIN_70_LBFC_BLT_28               ( ( uint8 ) 0x0FU )
/* BDT(5-4): set the break delimiter width of the transmission frame header */
#define LIN_70_LBFC_BDT_1                ( ( uint8 ) 0x00U )
#define LIN_70_LBFC_BDT_2                ( ( uint8 ) 0x10U )
#define LIN_70_LBFC_BDT_3                ( ( uint8 ) 0x20U )
#define LIN_70_LBFC_BDT_4                ( ( uint8 ) 0x30U )

/*** LMDn ***/
/* LMD(1-0) */
#define LIN_70_LMD_MASTER                ( ( uint8 ) 0x00U )
#define LIN_70_LMD_AUTO                  ( ( uint8 ) 0x02U )
/* LCKS(3-2) */
/* Clock generated by baud rate prescaler 0 */
#define LIN_70_LMD_LCKS_FA               ( ( uint8 ) 0x00U )
/* LIOS(4): Transmission, successful reception and reception status interrupt are used*/
#define LIN_70_LMD_LIOS                  ( ( uint8 ) 0x10U )

#define LIN_70_LMD_VALUE           ( LIN_70_LMD_MASTER | LIN_70_LMD_LCKS_FA | LIN_70_LMD_LIOS )

/* [LIN207] */
/* LPRS(3-1) */
#define LIN_70_LWBR_LPRS_1_1             ( ( uint8 ) 0x00U )
#define LIN_70_LWBR_LPRS_1_2             ( ( uint8 ) 0x02U )
#define LIN_70_LWBR_LPRS_1_4             ( ( uint8 ) 0x04U )
#define LIN_70_LWBR_LPRS_1_8             ( ( uint8 ) 0x06U )
#define LIN_70_LWBR_LPRS_1_16            ( ( uint8 ) 0x08U )
#define LIN_70_LWBR_LPRS_1_32            ( ( uint8 ) 0x0AU )
#define LIN_70_LWBR_LPRS_1_64            ( ( uint8 ) 0x0CU )
#define LIN_70_LWBR_LPRS_1_128           ( ( uint8 ) 0x0EU )
/* NSPB(7-4) */
#define LIN_70_LWBR_NSPB_16              ( ( uint8 ) 0x00U )
#define LIN_70_LWBR_NSPB_4               ( ( uint8 ) 0x30U )      /* 4 sampling */

#define LIN_70_LWBR_VALUE        ( LIN_70_LWBR_LWBR0 | LIN_70_LWBR_LPRS_1_1 | LIN_70_LWBR_NSPB_16 )


/*** LIEn ***/
/* FTCIE(0): Enables successful frame/wake-up transmission interrupt. */
#define LIN_70_LIE_FTCIE                 ( 0x01U )
/* FRCIE(1): Enables successful frame/wake-up reception interrupt. */
#define LIN_70_LIE_FRCIE                 ( 0x02U )
/* ERRIE(2): Enables error detection interrupt */
#define LIN_70_LIE_ERRIE                 ( 0x04U )
/* SHIE(3): Enables successful header transmission interrupt */
#define LIN_70_LIE_SHIE                  ( 0x08U )

#define LIN_70_LIE_VALUE (LIN_70_LIE_FTCIE | LIN_70_LIE_FRCIE | LIN_70_LIE_ERRIE | LIN_70_LIE_SHIE)


/*** LEDEn ***/
/* BERE(0): Enables bit error detection */
#define LIN_70_LEDE_BERE                 ( 0x01U )
/* PBERE(1): Enables physical bus error detection */
#define LIN_70_LEDE_PBERE                ( 0x02U )
/* FTERE(2): Enables frame/response timeout error detection */
#define LIN_70_LEDE_FTERE                ( 0x04U )
/* FERE(3): Enables framing error detection */
#define LIN_70_LEDE_FERE                 ( 0x08U )
/* LTES(7): Response timeout error */
#define LIN_70_LEDE_LTES                 ( 0x80U )

#define LIN_70_LEDE_VALUE                ( LIN_70_LEDE_BERE | LIN_70_LEDE_PBERE | LIN_70_LEDE_FTERE \
                                         | LIN_70_LEDE_FERE | LIN_70_LEDE_LTES )

#define LIN_70_SET_TRANSMISSION          ( 2 )
#define LIN_70_SET_RECEPTION             ( 1 )
#define LIN_70_SET_ERRSTATUS             ( 0 )

/* maximum value for LIN channel prescalar */
#define LIN_70_MAX_VALUE_PRESCALAR       ( 0xFFU )

/* LIN sleep command 0xFF value */
#define LIN_SLEEP_COMMAND_255U           ( 0xFFU )
/* LIN sleep command 0x00 value */
#define LIN_SLEEP_COMMAND_0U             ( 0x00U )


/* Q-Lite Phase1 Lin */
#define LIN_70_RL78F2X_ISC_ISC3_INTP12      (0x00U)
#define LIN_70_RL78F2X_ISC_ISC3_LRXD1       (0x08U)
#define LIN_70_RL78F2X_ISC_ISC2_INTP11      (0x00U)
#define LIN_70_RL78F2X_ISC_ISC2_LRXD0       (0x04U)
#define LIN_70_RL78F2X_ISC_ISC0_INTP0       (0x00U)
#define LIN_70_RL78F2X_ISC_ISC0_RXD0        (0x01U)

/* Lin channel ID */
#define LIN_70_CH0                          (0U)
#define LIN_70_CH1                          (1U)
#define LIN_70_CH2                          (2U)


/* Kind of Lin master and slave node */
#define LIN_70_MASTER                       ( 0U )
#define LIN_70_SLAVE                        ( 1U )

/* CKSEL mode */
#define LIN_70_LIN1MCKE        (0x20U)
#define LIN_70_LIN0MCKE        (0x10U)
#define LIN_70_LIN1MCK_FCLK    (0x00U)
#define LIN_70_LIN1MCK_FMX     (0x02U)
#define LIN_70_LIN0MCK_FCLK    (0x00U)
#define LIN_70_LIN0MCK_FMX     (0x01U)

/* Interrupt mask flag register MKxL, MKxH for Lin */
#define LIN_70_LIN0STAMK       (0x02U)  /* MK1L */
#define LIN_70_LIN0RVCMK       (0x01U)  /* MK1L */
#define LIN_70_LIN0MK          (0x02U)  /* MK1L */
#define LIN_70_LIN0TRMMK       (0x80U)  /* MK0H */
#define LIN_70_LIN0WUPMK       (0x04U)  /* MK2L */
#define LIN_70_LIN1STAMK       (0x08U)  /* MK3L */
#define LIN_70_LIN1RVCMK       (0x04U)  /* MK3L */
#define LIN_70_LIN1TRMMK       (0x02U)  /* MK3L */
#define LIN_70_LIN1WUPMK       (0x01U)  /* MK3L */
#define LIN_70_LIN1MK          (0x08U)  /* MK3L */

/*** LESTn Master ***/
#define LIN_70_MST_LEST_RPER    ( 0x80 )
#define LIN_70_MST_LEST_CSER    ( 0x20 )
#define LIN_70_MST_LEST_FER     ( 0x08 )
#define LIN_70_MST_LEST_FTER    ( 0x03 )
#define LIN_70_MST_LEST_PBER    ( 0x02 )
#define LIN_70_MST_LEST_BER     ( 0x01 )

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_MstInit ( const uint8 chIndex, const uint16 baudRatePrescaler );
uint8 Lin_70_RL78F2X_ReadModeStatusReg( void );
void Lin_70_RL78F2X_SetFrameId( const Lin_PduType* PduInfoPtr );
void Lin_70_RL78F2X_SetFrameType ( const uint8 frameType );
void Lin_70_RL78F2X_GoToSleep( void );
void Lin_70_RL78F2X_SetWakeupTranMode( void );
uint8 Lin_70_RL78F2X_ClrInt_ChkErr( const uint8 mode );
uint8 Lin_70_RL78F2X_CheckTransFlags( void );
uint8 Lin_70_RL78F2X_TimeoutErrCheck( void );
void Lin_70_RL78F2X_ReadReceivedData( uint8* LinFrameBufPtr );
Std_ReturnType Lin_70_RL78F2X_ModeChange( const uint8 modeChange, const uint16 timeout );
void Lin_70_RL78F2X_StartCommunication (void);
void Lin_70_RL78F2X_StartResponse (void);
void Lin_70_RL78F2X_DisableInterrupts ( const uint8 Channel );
void Lin_70_RL78F2X_EnableInterrupts ( const uint8 Channel );
void Lin_70_RL78F2X_ClearInterrupts ( const uint8 Channel );
void Lin_70_RL78F2X_ChangeChannel( const uint8 chIndex );
void lin_setMKxx( const uint8 chIndex );

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

#endif /* Lin_70_RL78F2X_H */
/* EOF Lin_70_RL78F2X.h *******************************************************/
