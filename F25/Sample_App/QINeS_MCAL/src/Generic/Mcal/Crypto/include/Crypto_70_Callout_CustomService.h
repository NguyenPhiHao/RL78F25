/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_70_Callout_CustomService.h                            */
/* Version     : v1.00.00                                                     */
/* Contents    : Crypto callout function configuration header                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef CRYPTO_70_CALLOUT_CUSTOMSERVICE_H
#define CRYPTO_70_CALLOUT_CUSTOMSERVICE_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Crypto.h"
#include "Crypto_70_Types.h"
#include "Crypto_GeneralTypes.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define CRYPTO_70_VENDOR_ID_CALLOUT_CUSTOMSERVICE_H            (70U)
#define CRYPTO_70_MODULE_ID_CALLOUT_CUSTOMSERVICE_H            (114U)

#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_CALLOUT_CUSTOMSERVICE_H    (22U)
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_CALLOUT_CUSTOMSERVICE_H    (11U)
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_CALLOUT_CUSTOMSERVICE_H (0U)

#define CRYPTO_70_SW_MAJOR_VERSION_CALLOUT_CUSTOMSERVICE_H             (1U)
#define CRYPTO_70_SW_MINOR_VERSION_CALLOUT_CUSTOMSERVICE_H             (0U)
#define CRYPTO_70_SW_PATCH_VERSION_CALLOUT_CUSTOMSERVICE_H             (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */
#if ( ( CRYPTO_70_AR_RELEASE_MAJOR_VERSION_CALLOUT_CUSTOMSERVICE_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( CRYPTO_70_AR_RELEASE_MINOR_VERSION_CALLOUT_CUSTOMSERVICE_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )    \
    )
#   error "AUTOSAR Version Numbers of Crypto_70_Callout_CustomService.h and Std_Types.h are different"
#endif
/* Std_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern Std_ReturnType Crypto_Callout_CustomService(
    Crypto_JobType*    job,
    uint32             dispatchId,
    uint32             keyId,
    uint32             keyElementId,
    uint32             targetKeyId,
    uint32             targetKeyElementId,
    const uint8*       inputPtr,
    uint32             inputLength,
    uint8*             outputPtr,
    uint32*            outputLengthPtr,
    uint8*             secondaryOutputPtr,
    uint32*            secondaryOutputLengthPtr
);

#endif  /* CRYPTO_70_CALLOUT_CUSTOMSERVICE_H */

/* EOF CRYPTO_70_CALLOUT_CUSTOMSERVICE_H /*************************************/
