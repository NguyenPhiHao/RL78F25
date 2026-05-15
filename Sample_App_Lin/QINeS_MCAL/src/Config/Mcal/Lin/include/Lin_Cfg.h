/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Lin_Cfg.h                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is LIN Driver Post-build Time Configuration Source */
/*               and it contains different configuration sets, if supported   */
/*               by hardware                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
#ifndef LIN_CFG_H
#define LIN_CFG_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "EcuM.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_70_VENDOR_ID_CFG_H                       ( 70U )
#define LIN_70_MODULE_ID_CFG_H                       ( 82U )

#define LIN_70_AR_RELEASE_MAJOR_VERSION_CFG_H        ( 22U )
#define LIN_70_AR_RELEASE_MINOR_VERSION_CFG_H        ( 11U )
#define LIN_70_AR_RELEASE_REVISION_VERSION_CFG_H     ( 0U )

#define LIN_70_SW_MAJOR_VERSION_CFG_H                ( 1U )
#define LIN_70_SW_MINOR_VERSION_CFG_H                ( 0U )
#define LIN_70_SW_PATCH_VERSION_CFG_H                ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Check if header file and Std types header file are of the same Autosar version */
/*--------------------Std_Types.h version ------------------------------------*/
#if ( ( LIN_70_AR_RELEASE_MAJOR_VERSION_CFG_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( LIN_70_AR_RELEASE_MINOR_VERSION_CFG_H != STD_TYPES_AR_RELEASE_MINOR_VERSION ) || \
      ( LIN_70_AR_RELEASE_REVISION_VERSION_CFG_H != STD_TYPES_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Lin_Cfg.h and Std_Types.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* Error report about LRSS */
#define LIN_70_SLAVE_LRSS_ERROR         ( FALSE )

/* [LIN066_Conf] */
#define LIN_DEV_ERROR_DETECT             ( TRUE)

/* [LIN179_Conf] */
#define LIN_INDEX                        ( 0 )

/* [LIN093_Conf] */
#define LIN_TIMEOUT_DURATION             ( 0xFFFFU )

/* [LIN067_Conf] [LIN219] */
#define LIN_VERSION_INFO_API             ( TRUE )

/* [LIN182_Conf] */
#define LIN_CHANNEL_WAKE_UP_SUPPORT      ( TRUE )

/* [LIN185_Conf] */
#define LIN_CHANNEL_ECUM_WAKEUP_SOURCE   ( ECUM_WKSOURCE_POWER )

#define LIN_70_DEM_REPORT_ERROR_STATUS   ( TRUE )

/* Maximum number of LIN channels configured */
#define LIN_70_NUM_OF_CHANNEL            ( 1 )

/* Macro for configuration of Breakfield length and Breakfield delimiter */
/* Breakfield length can be set from 13 bits to 28 bits by using the macros
 * LIN_70_LBFC_BLT_13 - LIN_70_LBFC_BLT_28 */
#define LIN_70_BREAKFIELD_LENGTH         ( LIN_70_LBFC_BLT_13 )

/* Similarly Breakfield Delimiter value is set to 1 to 4 using the macros
 * LIN_70_LBFC_BDT_1 - LIN_70_LBFC_BDT_4 */
#define LIN_70_BREAKFIELD_DELIMITER      ( LIN_70_LBFC_BDT_1 )

/* Macro for configuration of InterByte space */
/* Interbyte space for header can be set from 0 bits 7 bits by using the macros
 * LIN_70_LSC_IBSH_0 - LIN_70_LSC_IBSH_7 */
#define LIN_70_INTERBYTE_SPACE_HEADER    ( LIN_70_LSC_IBSH_0 )

/* Similarly Interbyte space for header can be set from 0 bits 3 bits by using the macros
 * LIN_70_LSC_IBS_0 - LIN_70_LSC_IBS_0 */
#define LIN_70_INTERBYTE_SPACE           ( LIN_70_LSC_IBS_0 )

/* Macro to set the low width of the wake-up signal */
/* Wakeup width can be selected from 1Tbit to 16Tbits by using the macros
 * LIN_70_LWUP_WUTL_1 - LIN_70_LWUP_WUTL_16 */
#define LIN_70_WAKEUP_WIDTH                ( LIN_70_LWUP_WUTL_16 )

/* Slave node config data */
#define LIN_NUM_OF_PDU                  ( ( uint8 )4 )
 
/* LIN 1.3 or 2.x */
/*** LWBRn ***/
/* LWBR0(0): when LIN 2.x is used set this bit to 1,  */
#define LIN_70_LWBR_LWBR0                ( ( uint8 ) 0x01U ) /* LIN2.x:0x01 / LIN1.3:0x00 */

/* Peripheral Enable Register */
#define LIN_Q_ISC_USE_LIN0EN             ( TRUE )
#define LIN_Q_ISC_USE_LIN1EN             ( FALSE )
#define LIN_Q_ISC_USE_LIN2EN             ( FALSE )

/* [LIN181_Conf] */
#if (LIN_Q_ISC_USE_LIN0EN == TRUE)
    #define LIN_CHANNEL_ID0                  ( 0U )
#endif

#if (LIN_Q_ISC_USE_LIN1EN == TRUE)
    #define LIN_CHANNEL_ID1                  ( 0U )
#endif

#if (LIN_Q_ISC_USE_LIN2EN == TRUE)
    #define LIN_CHANNEL_ID2                  ( 0U )
#endif

#if ( LIN_Q_ISC_USE_LIN0EN == TRUE )  /* Lin0 enable */
#define LIN_70_RL78F2X_ISC_ISC0          ( 0x1U )
#define LIN_70_RL78F2X_ISC_ISC2          ( 0x4U )
#else
#define LIN_70_RL78F2X_ISC_ISC0          ( 0U )
#define LIN_70_RL78F2X_ISC_ISC2          ( 0U )
#endif

#if ( LIN_Q_ISC_USE_LIN1EN == TRUE )  /* Lin1 enable */
#define LIN_70_RL78F2X_ISC_ISC3          ( 0x8U )
#else
#define LIN_70_RL78F2X_ISC_ISC3          ( 0U )
#endif

#if ( LIN_Q_ISC_USE_LIN2EN == TRUE )  /* Lin2 enable */
#define LIN_70_RL78F2X_ISC_ISC4          ( 0x10U )
#else
#define LIN_70_RL78F2X_ISC_ISC4          ( 0U )
#endif

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
extern const Lin_ConfigType Lin_Config;

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

#endif /* LIN_CFG_H */
/* EOF Lin_Cfg.h **************************************************************/
