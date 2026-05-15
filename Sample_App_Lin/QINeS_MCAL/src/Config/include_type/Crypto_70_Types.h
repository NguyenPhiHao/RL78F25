/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_70_Types.h                                            */
/* Version     : v1.00.00                                                     */
/* Contents    : Crypto Module type definition header                         */
/*                 This header file is for AUTOSAR Basic Software             */
/*                 module "Crypto Driver".                                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */
#ifndef CRYPTO_70_TYPES_H_
#define CRYPTO_70_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Crypto_Cfg.h"
#include "Crypto_70_HW_Types.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define CRYPTO_70_MODULE_ID_TYPES_H               ( 114U )
#define CRYPTO_70_VENDOR_ID_TYPES_H               (  70U )

#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_TYPES_H   ( 22U )
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_TYPES_H   ( 11U )
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_TYPES_H(  0U )

#define CRYPTO_70_SW_MAJOR_VERSION_TYPES_H        ( 1U )
#define CRYPTO_70_SW_MINOR_VERSION_TYPES_H        ( 0U )
#define CRYPTO_70_SW_PATCH_VERSION_TYPES_H        ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#if ( ( CRYPTO_70_AR_RELEASE_MAJOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( CRYPTO_70_AR_RELEASE_MINOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION ) )
# error "AUTOSAR Version Numbers of CRYPTO_70_Types.h and Std_Types.h are different"
#endif

/* CRYPTO_Cfg.h version check start */
#if ( CRYPTO_70_VENDOR_ID_TYPES_H != CRYPTO_70_VENDOR_ID_CFG_H )
# error "CRYPTO_70_Types.h and CRYPTO_Cfg.h have different vendor ids"
#endif

#if ( CRYPTO_70_MODULE_ID_TYPES_H != CRYPTO_70_MODULE_ID_CFG_H )
# error "CRYPTO_70_Types.h and CRYPTO_Cfg.h have different module ids"
#endif

#if ( ( CRYPTO_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != CRYPTO_70_AR_RELEASE_MAJOR_VERSION_CFG_H   ) || \
      ( CRYPTO_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != CRYPTO_70_AR_RELEASE_MINOR_VERSION_CFG_H   ) || \
      ( CRYPTO_70_AR_RELEASE_REVISION_VERSION_TYPES_H != CRYPTO_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
# error "AUTOSAR Version Numbers of CRYPTO_70_Types.h and CRYPTO_Cfg.h are different"
#endif

#if ( ( CRYPTO_70_SW_MAJOR_VERSION_TYPES_H != CRYPTO_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( CRYPTO_70_SW_MINOR_VERSION_TYPES_H != CRYPTO_70_SW_MINOR_VERSION_CFG_H ) || \
      ( CRYPTO_70_SW_PATCH_VERSION_TYPES_H != CRYPTO_70_SW_PATCH_VERSION_CFG_H ) )
# error "Software Version Numbers of CRYPTO_70_Types.h and CRYPTO_Cfg.h are different"
#endif
/* CRYPTO_Cfg.h version check end */

/* CRYPTO_70_HW_Types.h version check start */
#if ( CRYPTO_70_VENDOR_ID_TYPES_H != CRYPTO_70_VENDOR_ID_HW_TYPES_H )
# error "CRYPTO_70_Types.h and CRYPTO_70_HW_Types.h have different vendor ids"
#endif

#if ( CRYPTO_70_MODULE_ID_TYPES_H != CRYPTO_70_MODULE_ID_HW_TYPES_H )
# error "CRYPTO_70_Types.h and CRYPTO_70_HW_Types.h have different module ids"
#endif

#if ( ( CRYPTO_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != CRYPTO_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H   ) || \
      ( CRYPTO_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != CRYPTO_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H   ) || \
      ( CRYPTO_70_AR_RELEASE_REVISION_VERSION_TYPES_H != CRYPTO_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H ) )
# error "AUTOSAR Version Numbers of CRYPTO_70_Types.h and CRYPTO_70_HW_Types.h are different"
#endif

#if ( ( CRYPTO_70_SW_MAJOR_VERSION_TYPES_H != CRYPTO_70_SW_MAJOR_VERSION_HW_TYPES_H ) || \
      ( CRYPTO_70_SW_MINOR_VERSION_TYPES_H != CRYPTO_70_SW_MINOR_VERSION_HW_TYPES_H ) || \
      ( CRYPTO_70_SW_PATCH_VERSION_TYPES_H != CRYPTO_70_SW_PATCH_VERSION_HW_TYPES_H ) )
# error "Software Version Numbers of CRYPTO_70_Types.h and CRYPTO_70_HW_Types.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define CRYPTO_70_AES_BLOCK_SIZE    AES_BLOCK_SIZE_BYTE

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

#endif /* #ifndef CRYPTO_70_TYPES_H_ */

/* EOF Crypto_70_Types.h ****************************************/
