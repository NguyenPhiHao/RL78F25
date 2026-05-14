/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_Cfg.c                                                 */
/* Version     : v1.00.02                                                     */
/* Contents    : This document specifies the functionality, API and the       */
/*               configuration of the AUTOSAR Basic Software module Crypto    */
/*               Driver.                                                      */
/*               The Crypto Drivers are located in the Microcontroller        */
/*               Abstraction Layer, which is below the Crypto Hardware        */
/*               Abstraction Layer (Crypto Interface) and the upper service   */
/*               layer (Crypto Service Manager). The Crypto Driver is a       */
/*               driver for a specific device, that is only abstracting the   */
/*               features supported by the hardware.                          */
/*               The Crypto Drivers allow defining of different Crypto        */
/*               Driver Objects (i.e. AES accelerator, SW component, etc),    */
/*               which shall be used for concurrent requests in different     */
/*               buffers. For each hardware object a priority-dependent job   */
/*               processing shall be supported. A crypto software solution    */
/*               (i.e. software-based CDD) can define interfaces identical    */
/*               to the Crypto Drivers for interacting with the upper layers, */
/*               which shall provide an interface to the applications.        */
/* Author      : --                                                           */
/* Note        : Configuration structures for PreCompile.                     */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/*Expanded function                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Crypto_Cfg.h"
#include "Crypto.h"

#if( CRYPTO_DEV_ERROR_DETECT != FALSE )
#include "Det.h"
#endif      /* #if( CAN_DEV_ERROR_DETECT != FALSE ) */

#include "SampleCrypto.h"

/*----------------------------------------------------------------------------*/
/* version check                                                              */
/*----------------------------------------------------------------------------*/
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
#if ( ( ( CRYPTO_AR_RELEASE_MAJOR_VERSION ) != ( 22U ) )\
   || ( ( CRYPTO_AR_RELEASE_MINOR_VERSION ) != ( 11U ) ) )
#error "AUTOSAR Release Version error between Crypto and the configuration files."
#endif
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
static const Crypto_PrimitiveType Crypto_Primitive[ CRYPTO_70_NUM_OF_PRIMITIVE ] =
{
    {
        CRYPTO_ALGOFAM_RNG,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_NOT_SET,            /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_RANDOMGENERATE,              /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        0U                                  /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_RNG,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_NOT_SET,            /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_RANDOMSEED,                  /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        0U                                  /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CBC,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_ENCRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        128U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CBC,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_DECRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        128U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CBC,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_ENCRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        196U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CBC,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_DECRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        196U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CBC,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_ENCRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        256U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CBC,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_DECRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        256U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_ECB,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_ENCRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        128U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_ECB,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_DECRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        128U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_ECB,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_ENCRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        196U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_ECB,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_DECRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        196U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_ECB,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_ENCRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        256U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_ECB,                /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_DECRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        256U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CMAC,               /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_MACGENERATE,                 /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        128U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CMAC,               /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_MACGENERATE,                 /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        192U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CMAC,               /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_MACGENERATE,                 /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        256U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CMAC,               /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_MACVERIFY,                   /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        128U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CMAC,               /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_MACVERIFY,                   /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        192U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_AES,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_CMAC,               /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_MACVERIFY,                   /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        256U                                /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_RSA,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_RSAES_OAEP,         /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_SHA2_256,            /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_ENCRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        2048U                               /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_RSA,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_RSAES_OAEP,         /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_SHA2_256,            /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_DECRYPT,                     /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        2048U                               /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_RSA,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5,  /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_SHA2_256,            /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_SIGNATUREGENERATE,           /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        2048U                               /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_RSA,                 /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5,  /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_SHA2_256,            /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_SIGNATUREVERIFY,             /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        2048U                               /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    },
    {
        CRYPTO_ALGOFAM_SHA2_256,            /* [ECUC_Crypto_00035] Crypto_PrimitiveAlgorithmFamily */
        CRYPTO_ALGOMODE_NOT_SET,            /* [ECUC_Crypto_00036] Crypto_PrimitiveAlgorithmMode */
        CRYPTO_ALGOFAM_NOT_SET,             /* [ECUC_Crypto_00037] Crypto_PrimitiveAlgorithmSecondaryFamily */
        CRYPTO_HASH,                        /* [ECUC_Crypto_00034] Crypto_PrimitiveService */
        0U                                  /* [QINeS] The key length in bits to be used with that algorithm. CryptoPrimitiveAlgorithmKeyLength */
    }
};
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
const Crypto_PrimitivesType Crypto_PrimitivesCfg =
{
    CRYPTO_70_NUM_OF_PRIMITIVE,     /* [QINeS] Number of configured Crypto Primitves : CryptoNumOfPrimitive */
    &Crypto_Primitive[0]            /* [ECUC_Crypto_00033] CryptoPrimitive */
};
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
static const Crypto_DriverObjectType Crypto_DriverObject =
{
    CRYPTO_INSTANCE_ID,             /* [ECUC_Crypto_00009] CryptoDriverObjectId */
    CRYPTO_70_SIZE_OF_QUEUE,        /* [ECUC_Crypto_00019] CryptoQueueSize */
    CRYPTO_70_NUM_OF_PRIMITIVE,     /* [QINeS] Number of configured CryptoPrimitiveRef : CryptoNumOfPrimitiveRef */
    &Crypto_Primitive[0]            /* [ECUC_Crypto_00018] CryptoPrimitiveRef */
};
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
const Crypto_DriverObjectsType Crypto_DriverObjectsCfg =
{
    1U,                       /* [QINeS] Number of Configured Driver Objects : CryptoNumOfDriverObject */
    &Crypto_DriverObject      /* [ECUC_Crypto_00008] CryptoDriverObject */
};
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#if ( TRUE == CRYPTO_70_RSA_ENABLE )
#define CRYPTO_START_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
static Crypto_70_RsaKeyType Crypto_RsaKeys[ CRYPTO_70_NUM_OF_RSAKEY ] =
{
    {   /* RSASSA-PKCS#1-V1_5 : Signature Generation, private key 1 */
        {
            &SampleCrypto_RsaKeyN[0][0],
            256U
        },
        {
            &SampleCrypto_RsaKeyED[0][0],
            256U
        }
    },
    {   /* RSASSA-PKCS#1-V1_5 : Signature Verification, public key 1 */
        {
            &SampleCrypto_RsaKeyN[1][0],
            256U
        },
        {
            &SampleCrypto_RsaKeyED[1][0],
            3U
        }
    },
    {   /* RSA-OAEP : Encryption, public key 2 */
        {
            &SampleCrypto_RsaKeyN[2][0],
            256U
        },
        {
            &SampleCrypto_RsaKeyED[2][0],
            3U
        }
    },
    {   /* RSA-OAEP : Decryption, private key 2 */
        {
            &SampleCrypto_RsaKeyN[3][0],
            256U
        },
        {
            &SampleCrypto_RsaKeyED[3][0],
            256U
        }
    }
};
#define CRYPTO_STOP_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
#endif /* #if ( TRUE == Crypto_70_RSA_ENABLE ) */

/* Configuration for Crypto key Element. */
#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
static const Crypto_KeyElementType Crypto_KeyElement[ CRYPTO_70_NUM_OF_KEYELEMENT ] =
{
    {   /* AES-CBC128:CRYPTO_KE_CIPHER_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_CIPHER_KEY,                       /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN128,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* AES-CBC:CRYPTO_KE_CIPHER_IV */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_CIPHER_IV,                        /* [ECUC_Crypto_00021] CryptoKeyElementId */
        ( uint8* )&SampleCrypto_AesCbcIV[0][0],     /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_ALLOWED,                          /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN128,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_ALLOWED,                          /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* AES-CBC192:CRYPTO_KE_CIPHER_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_CIPHER_KEY,                       /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN192,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* AES-CBC:CRYPTO_KE_CIPHER_IV */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_CIPHER_IV,                        /* [ECUC_Crypto_00021] CryptoKeyElementId */
        ( uint8* )&SampleCrypto_AesCbcIV[1][0],     /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_ALLOWED,                          /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN128,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_ALLOWED,                          /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* AES-CBC256:CRYPTO_KE_CIPHER_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_CIPHER_KEY,                       /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN256,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* AES-CBC:CRYPTO_KE_CIPHER_IV */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_CIPHER_IV,                        /* [ECUC_Crypto_00021] CryptoKeyElementId */
        ( uint8* )&SampleCrypto_AesCbcIV[2][0],     /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_ALLOWED,                          /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN128,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_ALLOWED,                          /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* AES-ECB128:CRYPTO_KE_CIPHER_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_CIPHER_KEY,                       /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN128,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* AES-ECB192:CRYPTO_KE_CIPHER_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_CIPHER_KEY,                       /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN192,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* AES-ECB256:CRYPTO_KE_CIPHER_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_CIPHER_KEY,                       /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN256,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* CMAC-GEN128:CRYPTO_KE_MAC_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_MAC_KEY,                          /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN128,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* CMAC-GEN192:CRYPTO_KE_MAC_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_MAC_KEY,                          /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN192,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* CMAC-GEN256:CRYPTO_KE_MAC_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_MAC_KEY,                          /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN256,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* CMAC-VERIFY128:CRYPTO_KE_MAC_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_MAC_KEY,                          /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN128,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* CMAC-VERIFY192:CRYPTO_KE_MAC_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_MAC_KEY,                          /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN192,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* CMAC-VERIFY256:CRYPTO_KE_MAC_KEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_70_KE_FORMAT_BIN_AES_KEY,            /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_MAC_KEY,                          /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_HSM_KEYLEN256,                    /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_DENIED,                           /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
    },
    {   /* RSA-SIGGEN:CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY,        /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_SIGNATURE_KEY,                    /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_RSA_LENGTH,                       /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_ALLOWED,                          /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
        ( uint8* )&Crypto_RsaKeys[0]                          /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
#else
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
#endif /* ( TRUE == CRYPTO_70_RSA_ENABLE )*/
    },
    {   /* RSA-SIGVERIFY:CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY */
        ( uint8 ) TRUE,                             /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY,         /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_SIGNATURE_KEY,                    /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_ALLOWED,                          /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_RSA_LENGTH,                       /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_ALLOWED,                          /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
        ( uint8* )&Crypto_RsaKeys[1]                          /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
#else
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
#endif /* ( TRUE == CRYPTO_70_RSA_ENABLE )*/
    },
    {   /* RSA-ENCRYPT:CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY */
        ( uint8 ) TRUE,                             /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY,         /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_CIPHER_KEY,                       /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_ALLOWED,                          /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_RSA_LENGTH,                       /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_ALLOWED,                          /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
        ( uint8* )&Crypto_RsaKeys[3]                          /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
#else
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
#endif /* ( TRUE == CRYPTO_70_RSA_ENABLE )*/
    },
    {   /* RSA-DECRYPT:CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00025] CryptoKeyElementAllowPartialAccess */
        CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY,        /* [ECUC_Crypto_00041] CryptoKeyElementFormat */
        CRYPTO_KE_CIPHER_KEY,                       /* [ECUC_Crypto_00021] CryptoKeyElementId */
        NULL_PTR,                                   /* [ECUC_Crypto_00023] CryptoKeyElementInitValue */
        ( uint8 ) FALSE,                            /* [ECUC_Crypto_00026] CryptoKeyElementPersist */
        CRYPTO_RA_DENIED,                           /* [ECUC_Crypto_00024] CryptoKeyElementReadAccess */
        CRYPTO_70_RSA_LENGTH,                       /* [ECUC_Crypto_00022] CryptoKeyElementSize */
        CRYPTO_WA_ALLOWED,                          /* [ECUC_Crypto_00027] CryptoKeyElementWriteAccess */
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
        ( uint8* )&Crypto_RsaKeys[2]                          /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
#else
        NULL_PTR                                    /* [QINeS_ECUC_Crypto_00012] CryptoKeyElementValue */
#endif /* ( TRUE == CRYPTO_70_RSA_ENABLE )*/
    }
};

#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
/* Crypto Key configuration data */
const Crypto_KeyElementsType Crypto_KeyElementsCfg =
{
    CRYPTO_70_NUM_OF_KEYELEMENT,      /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElement */
    &Crypto_KeyElement[0]             /* [ECUC_Crypto_00014] CryptoKeyElement */
};
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
/* Configuration for Crypto Key types for Crypto key element */
static const Crypto_KeyTypeType Crypto_KeyTypeID[ CRYPTO_70_NUM_OF_KEYTYPE ] =
{
    {   /* AES-CBC : 128bit */
        0x00000002UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[0]               /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* AES-CBC : 192bit */
        0x00000002UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[2]               /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* AES-CBC : 256bit */
        0x00000002UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[4]               /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* AES-ECB : 128bit */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[6]               /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* AES-ECB : 192bit */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[7]               /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* AES-ECB : 256bit */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[8]               /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* CMAC Generation : 128bit */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[9]               /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* CMAC Generation : 192bit */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[10]              /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* CMAC Generation : 256bit */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[11]              /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* CMAC Verify : 128bit */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[12]              /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* CMAC Verify : 192bit */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[13]              /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* CMAC Verify : 256bit */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[14]              /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* RSASSA-PKCS#1-V1_5 Generation */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[15]              /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* RSASSA-PKCS#1-V1_5 Verify */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[16]              /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* RSA-OAEP Encoding */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[17]              /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    },
    {   /* RSA-OAEP Decoding */
        0x00000001UL,                       /* [QINeS] Number of configured Crypto Key Elements : CryptoNumOfKeyElementRef */
        &Crypto_KeyElement[18]              /* [ECUC_Crypto_00014] CryptoKeyElementRef */
    }
};
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
const Crypto_KeyTypesType Crypto_KeyTypesCfg =
{
    CRYPTO_70_NUM_OF_KEYTYPE,           /* [QINeS] Number of configured Crypto Key types : CryptoNumOfKeyType */
    &Crypto_KeyTypeID[0]                /* [ECUC_Crypto_00030] Configuration for Crypto Key Types : CryptoKeyType */
};
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
static Crypto_KeyType Crypto_Key[ CRYPTO_70_NUM_OF_KEY ] =
{
    {   /* AES-CBC 128bit */
        4U,                             /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[0],           /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* AES-CBC 192bit */
        5U,                             /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[1],           /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* AES-CBC 256bit */
        6U,                             /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[2],           /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* AES-ECB 128bit */
        7U,                             /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[3],           /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* AES-ECB 192bit */
        8U,                             /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[4],           /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* AES-ECB 256bit */
        9U,                             /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[5],           /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* CMAC Generation 128bit */
        10U,                            /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[6],           /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* CMAC Generation 192bit */
        11U,                            /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[7],           /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* CMAC Generation 256bit */
        12U,                            /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[8],           /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* CMAC Verify 128bit */
        13U,                            /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[9],           /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* CMAC Verify 192bit */
        14U,                            /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[10],          /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* CMAC Verify 256bit */
        15U,                            /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[11],          /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* RSASSA-PKCS#1-V1_5 Signature Generation */
        24U,                            /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[12],          /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* RSASSA-PKCS#1-V1_5 Signature Verify */
        25U,                            /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[13],          /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* RSA-OAEP Encryption */
        26U,                            /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[14],          /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    },
    {   /* RSA-OAEP Decryption */
        27U,                            /* [ECUC_Crypto_00012] CryptoKeyId */
        &Crypto_KeyTypeID[15],          /* [ECUC_Crypto_00020] CryptoKeyTypeRef */
        NULL_PTR                        /* [ECUC_Crypto_00059] CryptoKeyNvBlockRef */
    }
};
#define CRYPTO_STOP_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
const Crypto_KeysType Crypto_KeysCfg =
{
    CRYPTO_70_NUM_OF_KEY,      /* [QINeS] Number of configured Crypto Key */
    &Crypto_Key[0]             /* [ECUC_Crypto_00011] CryptoKey */
};
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

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

/* EOF Crypto_Cfg.c ******************************************************************/
