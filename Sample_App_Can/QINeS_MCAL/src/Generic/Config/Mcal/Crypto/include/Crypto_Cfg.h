/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_Cfg.h                                                 */
/* Version     : v1.00.02                                                     */
/* Contents    : This header file is for AUTOSAR Basic Software module        */
/*               "Crypto Driver".                                             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef CRYPTO_CFG_H
#define CRYPTO_CFG_H
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Crypto_AR.h"
#include "Rte_NvM_Type.h"
 
/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define CRYPTO_70_VENDOR_ID_CFG_H                      (70U)
#define CRYPTO_70_MODULE_ID_CFG_H                      (114U)
 
#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_CFG_H       (22U)
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_CFG_H       (11U)
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_CFG_H    (0U)
 
#define CRYPTO_70_SW_MAJOR_VERSION_CFG_H               (1U)
#define CRYPTO_70_SW_MINOR_VERSION_CFG_H               (0U)
#define CRYPTO_70_SW_PATCH_VERSION_CFG_H               (0U)
 
/*----------------------------------------------------------------------------*/
/* version check                                                              */
/*----------------------------------------------------------------------------*/
#if ( ( ( CRYPTO_AR_RELEASE_MAJOR_VERSION ) != ( CRYPTO_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) )\
   || ( ( CRYPTO_AR_RELEASE_MINOR_VERSION ) != ( CRYPTO_70_AR_RELEASE_MINOR_VERSION_CFG_H ) ) )
#error "AUTOSAR Release Version error between Crypto and the configuration files."
#endif

/*----------------------------------------------------------------------------*/
/* source file version checks                                                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/*
* [ECUC_Crypto_00002] CryptoGeneral : Container for common configuration options
*/

/* [ECUC_Crypto_00006]:
* Switches the development error detection and notification on or off.
*/
#define CRYPTO_DEV_ERROR_DETECT      ( TRUE )

/*
* [ECUC_Crypto_00007]:
* Switches the Crypto_GetVersionInfo() API ON or OFF.
*/
#define CRYPTO_VERSION_INFO_API      ( TRUE )

/*
* [ECUC_Crypto_00040]:
* Instance ID of the crypto driver.
*/
#define CRYPTO_INSTANCE_ID           ( 0U )

/*
* [QINeS] Number of CryptoKeys configured.
*/
#define CRYPTO_70_NUM_OF_KEY                    ( 16U )

/*
* [QINeS] Number of CryptoKeyElements configured.
*/
#define CRYPTO_70_NUM_OF_KEYELEMENT             ( 19U )

/*
* [QINeS] Number of CryptoKeyTypes configured.
*/
#define CRYPTO_70_NUM_OF_KEYTYPE                ( 16U )

/*
* [QINeS] Number of CryptoPrimitives configured.
*/
#define CRYPTO_70_NUM_OF_PRIMITIVE              ( 25U )

/*
* [QINeS] Number of IV of CryptoKeyElements configured.
*/
#define CRYPTO_70_NUM_OF_IV                     ( ( uint32 )3U )

/*
* Size of the queue in the Crypto Driver.
* [0U..16U]
*/
#define CRYPTO_70_SIZE_OF_QUEUE                 ( 16U )

/*
* Using AESEA Security Driver
*/
#define CRYPTO_70_AESEA_ENABLE                  ( TRUE )

/*
* Using SHA Hash Library.
*/
#define CRYPTO_70_HASH_ENABLE                   ( TRUE )

#if ( TRUE == CRYPTO_70_HASH_ENABLE )
/*
* Using RSA Library.
*/
#define CRYPTO_70_RSA_ENABLE                    ( TRUE )
#else
#define CRYPTO_70_RSA_ENABLE                    ( FALSE )
#endif   /* #if ( TRUE == CRYPTO_70_HASH_ENABLE ) */

/*
* Number of RSA Keys.
*/
#define CRYPTO_70_NUM_OF_RSAKEY                 ( 4U )

/*
* CPU Operation Frequency (MHz)
*/
#define CRYPTO_70_FREQUENCY                     ( 40U )

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

#endif /* CRYPTO_CFG_H */

/* EOF Crypto_Cfg.h ***********************************************************/
