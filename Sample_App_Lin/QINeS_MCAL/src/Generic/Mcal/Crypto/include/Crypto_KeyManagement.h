/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_KeyManagement.h                                       */
/* Version     : v1.00.02                                                     */
/* Contents    : Key management header file for Crypto driver                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef CRYPTO_KEYMANAGEMENT_H
#define CRYPTO_KEYMANAGEMENT_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"              /* [SWS_Crypto_00042] */
#include "Crypto_Cfg.h"             /* [SWS_Crypto_00008] */
#include "Crypto_70_Types.h"
#include "Crypto_GeneralTypes.h"
#include "Rte_Csm_Type.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* source file version information                                            */
/*----------------------------------------------------------------------------*/
/*[SWS_BSW_00059] Version Check parameters. */
#define CRYPTO_70_VENDOR_ID_KEYMANAGEMENT_H                (70U)
#define CRYPTO_70_MODULE_ID_KEYMANAGEMENT_H                (114U)

#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_KEYMANAGEMENT_H (22U)
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_KEYMANAGEMENT_H (11U)
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_KEYMANAGEMENT_H (0U)

#define CRYPTO_70_SW_MAJOR_VERSION_KEYMANAGEMENT_H         (1U)
#define CRYPTO_70_SW_MINOR_VERSION_KEYMANAGEMENT_H         (0U)
#define CRYPTO_70_SW_PATCH_VERSION_KEYMANAGEMENT_H         (2U)

/*----------------------------------------------------------------------------*/
/* source file version checks                                                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macro function declarations                                                */
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
#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"

void crypto_memCopy( const uint8 QL_70_FAR * srcPtr, uint8* dstPtr, uint32 length );
void crypto_memSet ( uint8* dstPtr, uint8 setVal,   uint32 length );
Std_ReturnType crypto_chkCryptoKeyId( uint32 cryptoKeyId,    uint32* pKeyIdIndex );
Std_ReturnType crypto_chkElementId    ( uint32 keyElementId,  const Crypto_KeyType* pKey, uint32* pElementIndex );
Std_ReturnType crypto_jobErrorCheck   ( Crypto_JobType* job );

#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"

/*----------------------------------------------------------------------------*/
/* end of functions and function style macros declaration                     */
/*----------------------------------------------------------------------------*/

#endif  /* CRYPTO_KEYMANAGEMENT_H */

/* EOF Crypto_KeyManagement.h ***********************************************/

