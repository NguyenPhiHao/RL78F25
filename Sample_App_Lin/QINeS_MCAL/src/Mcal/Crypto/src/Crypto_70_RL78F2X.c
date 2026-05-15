/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_70_RL78F2X.c                                          */
/* Version     : v1.00.01                                                     */
/* Contents    : Crypto Module HW dependent interface                         */
/*               This file covers Hw dependent functionality for Crypto       */
/*               module.                                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* Expanded function                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Crypto.h"
#include "Crypto_70_HW.h"
#include "Crypto_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* source file version information                                            */
/*----------------------------------------------------------------------------*/
#define CRYPTO_70_VENDOR_ID_RL78F2X_C                   ( 70U )
#define CRYPTO_70_MODULE_ID_RL78F2X_C                   ( 114U )

#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C     ( 22U )
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C     ( 11U )
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C  ( 0U )

#define CRYPTO_70_SW_MAJOR_VERSION_RL78F2X_C             ( 1U )
#define CRYPTO_70_SW_MINOR_VERSION_RL78F2X_C             ( 0U )
#define CRYPTO_70_SW_PATCH_VERSION_RL78F2X_C             ( 0U )

/*----------------------------------------------------------------------------*/
/* source file version checks                                                 */
/*----------------------------------------------------------------------------*/
/* Crypto_70_RL78F2X.h version check start */
#if ( CRYPTO_70_VENDOR_ID_RL78F2X_C != CRYPTO_70_VENDOR_ID_RL78F2X_H )
  #error "VENDOR ID for Crypto_70_RL78F2X.c and Crypto_70_RL78F2X.h is different"
#endif

#if ( CRYPTO_70_MODULE_ID_RL78F2X_C != CRYPTO_70_MODULE_ID_RL78F2X_H )
  #error "MODULE ID for Crypto_70_RL78F2X.c and Crypto_70_RL78F2X.h is different"
#endif

#if ( ( CRYPTO_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C != CRYPTO_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( CRYPTO_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C != CRYPTO_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) || \
      ( CRYPTO_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != CRYPTO_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) )
  #error "AUTOSAR Version Numbers of Crypto_70_RL78F2X.c and Crypto_70_RL78F2X.h are different"
#endif

#if ( ( CRYPTO_70_SW_MAJOR_VERSION_RL78F2X_C != CRYPTO_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( CRYPTO_70_SW_MINOR_VERSION_RL78F2X_C != CRYPTO_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( CRYPTO_70_SW_PATCH_VERSION_RL78F2X_C != CRYPTO_70_SW_PATCH_VERSION_RL78F2X_H ) )
  #error "Software Version Numbers of Crypto_70_RL78F2X.c and Crypto_70_RL78F2X.h are different"
#endif
/* Crypto_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

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
/* global variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"

#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
/*----------------------------------------------------------------------------*/
/* ModuleID  : CRYPTO_MODULE_ID (114)                                         */
/* ServiceID : --                                                             */
/* Name      : Crypto_70_RL78F2X_ClearProcessStatus                           */
/* Param     : void                                                           */
/* Return    : uint8                                                          */
/* Contents  : This function will clear AESA processing status.               */
/* Author    : m.ishikawa                                                     */
/* Note      : --                                                             */
/*----------------------------------------------------------------------------*/
uint8 Crypto_70_RL78F2X_ClearProcessStatus( const uint8 clearStatus )
{
    uint8 secstVal;

    CRYPTO_70_RL78F2X_SECST &= (uint8)~((uint32)clearStatus);
    secstVal = CRYPTO_70_RL78F2X_SECST;

    return (secstVal);
}

/*----------------------------------------------------------------------------*/
/* ModuleID  : CRYPTO_MODULE_ID (114)                                         */
/* ServiceID : --                                                             */
/* Name      : Crypto_70_RL78F2X_GetErrorStatus                               */
/* Param     : void                                                           */
/* Return    : uint8                                                          */
/* Contents  : This function will get AESA error status.                      */
/*             After execute this function, AESA error is cleared.            */
/* Author    : m.ishikawa                                                     */
/* Note      : --                                                             */
/*----------------------------------------------------------------------------*/
uint16 Crypto_70_RL78F2X_GetErrorStatus( void )
{
    const uint16 secerVal = CRYPTO_70_RL78F2X_SECER;

    CRYPTO_70_RL78F2X_SECER = (uint16_least)0x0000U;

    return (secerVal);
}
#endif /*#if ( TRUE == CRYPTO_70_AESEA_ENABLE )*/

#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"

/* EOF Crypto_70_RL78F2X.c ****************************************************/