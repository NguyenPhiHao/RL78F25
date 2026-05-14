/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_70_Callout_CustomService.c                            */
/* Version     : v1.00.01                                                     */
/* Contents    : Crypto callout function.                                     */
/*               User shall implement the custom function in this file.       */
/* Author      : --                                                           */
/* Note        : -                                                            */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Crypto_70_Callout_CustomService.h"
#include "Crypto_GeneralTypes.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define CRYPTO_70_VENDOR_ID_CALLOUT_CUSTOMSERVICE_C                      ( 70U )
#define CRYPTO_70_MODULE_ID_CALLOUT_CUSTOMSERVICE_C                      ( 114U )

#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_CALLOUT_CUSTOMSERVICE_C       ( 22U )
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_CALLOUT_CUSTOMSERVICE_C       ( 11U )
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_CALLOUT_CUSTOMSERVICE_C    ( 0U )

#define CRYPTO_70_SW_MAJOR_VERSION_CALLOUT_CUSTOMSERVICE_C               ( 1U )
#define CRYPTO_70_SW_MINOR_VERSION_CALLOUT_CUSTOMSERVICE_C               ( 0U )
#define CRYPTO_70_SW_PATCH_VERSION_CALLOUT_CUSTOMSERVICE_C               ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Crypto_70_Callout_CustomService.h version check start */

#if ( CRYPTO_70_VENDOR_ID_CALLOUT_CUSTOMSERVICE_C != CRYPTO_70_VENDOR_ID_CALLOUT_CUSTOMSERVICE_H )
    #error "VENDOR ID for Crypto_70_Callout_CustomService.c and Crypto_70_Callout_CustomService.h are different"
#endif

#if ( CRYPTO_70_MODULE_ID_CALLOUT_CUSTOMSERVICE_C != CRYPTO_70_MODULE_ID_CALLOUT_CUSTOMSERVICE_H )
    #error "MODULE ID for Crypto_70_Callout_CustomService.c and Crypto_70_Callout_CustomService.h are different"
#endif

#if ( ( CRYPTO_70_AR_RELEASE_MAJOR_VERSION_CALLOUT_CUSTOMSERVICE_C    != CRYPTO_70_AR_RELEASE_MAJOR_VERSION_CALLOUT_CUSTOMSERVICE_H ) || \
      ( CRYPTO_70_AR_RELEASE_MINOR_VERSION_CALLOUT_CUSTOMSERVICE_C    != CRYPTO_70_AR_RELEASE_MINOR_VERSION_CALLOUT_CUSTOMSERVICE_H ) || \
      ( CRYPTO_70_AR_RELEASE_REVISION_VERSION_CALLOUT_CUSTOMSERVICE_C != CRYPTO_70_AR_RELEASE_REVISION_VERSION_CALLOUT_CUSTOMSERVICE_H ) \
    )
    #error "AUTOSAR Version Numbers of Crypto_70_Callout_CustomService.c and Crypto_70_Callout_CustomService.h are different"
#endif

#if ( ( CRYPTO_70_SW_MAJOR_VERSION_CALLOUT_CUSTOMSERVICE_C != CRYPTO_70_SW_MAJOR_VERSION_CALLOUT_CUSTOMSERVICE_H ) || \
      ( CRYPTO_70_SW_MINOR_VERSION_CALLOUT_CUSTOMSERVICE_C != CRYPTO_70_SW_MINOR_VERSION_CALLOUT_CUSTOMSERVICE_H ) || \
      ( CRYPTO_70_SW_PATCH_VERSION_CALLOUT_CUSTOMSERVICE_C != CRYPTO_70_SW_PATCH_VERSION_CALLOUT_CUSTOMSERVICE_H ) \
    )
    #error "Software Version Numbers of Crypto_70_Callout_CustomService.c and Crypto_70_Callout_CustomService.h are different"
#endif

/* Crypto_70_Callout_CustomService.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"

/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID(114)                                        */
/* ServiceID   : --                                                           */
/* Name        : Crypto_Callout_CustomService                                 */
/* Param       : (in) job                                                     */
/*               (in) dispatchId                                              */
/*               (in) keyId                                                   */
/*               (in) keyElementId                                            */
/*               (in) targetKeyId                                             */
/*               (in) targetKeyElementId                                      */
/*               (in) inputPtr                                                */
/*               (in) inputLength                                             */
/*               (out) outputPtr                                              */
/*               (out) outputLengthPtr                                        */
/*               (out) secondaryOutputPtr                                     */
/*               (out) secondaryOutputLengthPtr                               */
/* Return      : Std_ReturnType                                               */
/*                  E_OK : Request successful.                                */
/*                  E_NOT_OK : Request failed.                                */
/*                  CRYPTO_E_CUSTOM_ERROR : Callout function failed.          */
/* Contents    : Callout function for Crypto_CustomSync.                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_Callout_CustomService( Crypto_JobType* job, uint32 dispatchId, uint32 keyId,
                                             uint32 keyElementId, uint32 targetKeyId,
                                             uint32 targetKeyElementId, const uint8* inputPtr,
                                             uint32 inputLength, uint8* outputPtr,
                                             uint32* outputLengthPtr, uint8* secondaryOutputPtr,
                                             uint32* secondaryOutputLengthPtr )
{
    Std_ReturnType  retValue = CRYPTO_E_CUSTOM_ERROR;
 
    /* This function is defined by user. */
    /* When parameter "job" is NULL_PTR, this function is called by Crypto_CustomSync() function. */
    /* "job" is not NULL_PTR, this function is called by Crypto_ProcessJob() function. */
 
    return ( retValue );
}
#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
/* EOF Crypto_70_Callout_CustomService.c ***********************************************/
