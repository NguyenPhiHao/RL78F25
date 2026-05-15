/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_70_Hw.h                                               */
/* Version     : v1.00.01                                                     */
/* Contents    : Wrapper header file for Crypto driver                        */
/*               This header file is for isolation between AUTOSAR based      */
/*               and Microcontroller (HW) based level.                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

#ifndef CRYPTO_70_HW_H
#define CRYPTO_70_HW_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Crypto_70_Types.h"

/*----------------------------------------------------------------------------*/
/* source file version information                                            */
/*----------------------------------------------------------------------------*/
/*[SWS_BSW_00059] Version Check parameters. */
#define CRYPTO_70_VENDOR_ID_HW_H                   (70U)
#define CRYPTO_70_MODULE_ID_HW_H                   (114U)

#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_HW_H    (22U)
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_HW_H    (11U)
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_HW_H (0U)

#define CRYPTO_70_SW_MAJOR_VERSION_HW_H            (1U)
#define CRYPTO_70_SW_MINOR_VERSION_HW_H            (0U)
#define CRYPTO_70_SW_PATCH_VERSION_HW_H            (0U)

/*----------------------------------------------------------------------------*/
/* source file version checks                                                 */
/*----------------------------------------------------------------------------*/
/* Check if current file and Crypto_70_MCN.h file are of the same Vendor ID */
#if ( CRYPTO_70_VENDOR_ID_HW_H != CRYPTO_70_VENDOR_ID_MCN_H )
#error "Vendor ID for Crypto_70_Hw.h and Crypto_70_MCN.h are different"
#endif

#if ( CRYPTO_70_MODULE_ID_HW_H != CRYPTO_70_MODULE_ID_MCN_H )
#error "Module ID for Crypto_70_Hw.h and Crypto_70_MCN.h are different"
#endif

#if ( ( CRYPTO_70_SW_MAJOR_VERSION_HW_H != CRYPTO_70_SW_MAJOR_VERSION_MCN_H ) || \
      ( CRYPTO_70_SW_MINOR_VERSION_HW_H != CRYPTO_70_SW_MINOR_VERSION_MCN_H ) || \
      ( CRYPTO_70_SW_PATCH_VERSION_HW_H != CRYPTO_70_SW_PATCH_VERSION_MCN_H )    \
    )
#error "Software Version Numbers of Crypto_70_Hw.h and Crypto_70_MCN.h are different"
#endif

#if ( ( CRYPTO_70_AR_RELEASE_MAJOR_VERSION_HW_H    != CRYPTO_70_AR_RELEASE_MAJOR_VERSION_MCN_H )    || \
      ( CRYPTO_70_AR_RELEASE_MINOR_VERSION_HW_H    != CRYPTO_70_AR_RELEASE_MINOR_VERSION_MCN_H )    || \
      ( CRYPTO_70_AR_RELEASE_REVISION_VERSION_HW_H != CRYPTO_70_AR_RELEASE_REVISION_VERSION_MCN_H ) \
    )
#error "AUTOSAR Version Numbers of Crypto_70_Hw.h and Crypto_70_MCN.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macro function declarations                                                */
/*----------------------------------------------------------------------------*/
#define RND_BYTE_LENGTH           (0x10U)
#define AES_KEY_BLOCK_NUM         (14U)
#define AES_BLOCK_SIZE_BYTE       (16U)
#define AES_BLOCK_SIZE_BIT        (128U)
#define HASH_SHA256_LENGTH        (0x20U)

#define CRYPTO_MGF_MSG_BUFF_LEN       (227U)
#define CRYPTO_MGF_HASH_LENGTH        HASH_SHA256_LENGTH
#define OAEP_DATA_BLOCK_LENGTH        (223U)
#define OAEP_SEED_LENGTH              (32U)
#define OAEP_ENCODED_BUFF_LEN         (256U)
#define OAEP_DECODED_BUFF_LEN         (256U)
#define MASKED_SEED_INDEX             (1U)
#define MASKED_DB_INDEX               (33U)

#define Crypto_70_HW_HashDigest       R_SHA_256HashDigest

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/*
 * Buffer for MGF
 */
typedef struct {
    uint8 M_i[ CRYPTO_MGF_MSG_BUFF_LEN ];
    uint8 T_i[ CRYPTO_MGF_HASH_LENGTH ];
} Crypto_70_MgfBufType;

/*
 * Buffer for OAEP processing
 */
typedef struct {
    uint8 dataBlock[ OAEP_DATA_BLOCK_LENGTH ];
    uint8 seed[ OAEP_SEED_LENGTH ];
    uint8 dbMask[ OAEP_DATA_BLOCK_LENGTH ];
    uint8 seedMask[ OAEP_SEED_LENGTH ];
} Crypto_70_OaepBufType;

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

Std_ReturnType Crypto_70_HW_Init( void );
Std_ReturnType Crypto_70_HW_CancelJob( const Crypto_JobPrimitiveInfoType* jobPrimitive );
#if ( TRUE == CRYPTO_70_HASH_ENABLE )
Std_ReturnType Crypto_70_HW_Hash( Crypto_JobType* job );
#endif  /* if( TRUE == CRYPTO_70_HASH_ENABLE ) */
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
Std_ReturnType Crypto_70_HW_MacGenerate( Crypto_JobType* job );
Std_ReturnType Crypto_70_HW_MacVerify( Crypto_JobType* job );
Std_ReturnType Crypto_70_HW_Encrypt( Crypto_JobType* job, const uint8* iv, Crypto_70_RsaKeyType* pRsaKey );
#endif  /* if( TRUE == CRYPTO_70_AESEA_ENABLE ) */
Std_ReturnType Crypto_70_HW_Decrypt( Crypto_JobType* job, const uint8* iv, Crypto_70_RsaKeyType* pRsaKey );
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
Std_ReturnType Crypto_70_HW_SignatureGenerate( Crypto_JobType* job, Crypto_70_RsaKeyType* p_key );
Std_ReturnType Crypto_70_HW_SignatureVerify( Crypto_JobType* job, Crypto_70_RsaKeyType* p_key );
#endif  /* #if( TRUE == CRYPTO_70_HASH_ENABLE ) */
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
Std_ReturnType Crypto_70_HW_RandomGenerate( Crypto_JobType* job );
Std_ReturnType Crypto_70_HW_RandomSeedExtend( const uint8* seedPtr );
uint8          Crypto_70_HW_GetProcessStatus( void );
uint16         Crypto_70_HW_GetErrorStatus( void );
uint8          Crypto_70_HW_ClearProcessStatus( const uint8 clearStatus );
#endif  /* #if( TRUE == CRYPTO_70_AESEA_ENABLE ) */

/*----------------------------------------------------------------------------*/
/* end of functions and function style macros declaration                     */
/*----------------------------------------------------------------------------*/

#endif  /* CRYPTO_70_HW_H */

/* EOF Crypto_70_Hw.h *********************************************************/