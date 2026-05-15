/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_70_HW.c                                               */
/* Version     : v1.00.02                                                     */
/* Contents    : Wrapper source file for Crypto driver                        */
/*               This source file is for isolation between AUTOSAR based      */
/*               and Microcontroller (HW) based level.                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/*Expanded function                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Crypto.h"
#include "Crypto_70_HW.h"
#include "Crypto_70_RL78F2X.h"
#include "Crypto_KeyManagement.h"

#include "r_rfd_common_api.h"

/*----------------------------------------------------------------------------*/
/* source file version information                                            */
/*----------------------------------------------------------------------------*/
#define CRYPTO_70_VENDOR_ID_HW_C                    ( 70U )
#define CRYPTO_70_MODULE_ID_HW_C                    ( 114U )

#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_HW_C     ( 22U )
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_HW_C     ( 11U )
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_HW_C  ( 0U )

#define CRYPTO_70_SW_MAJOR_VERSION_HW_C             ( 1U )
#define CRYPTO_70_SW_MINOR_VERSION_HW_C             ( 0U )
#define CRYPTO_70_SW_PATCH_VERSION_HW_C             ( 0U )

/*----------------------------------------------------------------------------*/
/* source file version checks                                                 */
/*----------------------------------------------------------------------------*/

/* Crypto_70_HW.h version check start */
#if ( CRYPTO_70_VENDOR_ID_HW_C != CRYPTO_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Crypto_70_HW.c and Crypto_70_HW.h is different"
#endif

#if ( CRYPTO_70_MODULE_ID_HW_C != CRYPTO_70_MODULE_ID_HW_H )
    #error "MODULE ID for Crypto_70_HW_.c and Crypto_70_HW.h is different"
#endif

#if ( ( CRYPTO_70_AR_RELEASE_MAJOR_VERSION_HW_C    != CRYPTO_70_AR_RELEASE_MAJOR_VERSION_HW_H )  || \
      ( CRYPTO_70_AR_RELEASE_MINOR_VERSION_HW_C    != CRYPTO_70_AR_RELEASE_MINOR_VERSION_HW_H )  || \
      ( CRYPTO_70_AR_RELEASE_REVISION_VERSION_HW_C != CRYPTO_70_AR_RELEASE_REVISION_VERSION_HW_H ) )
    #error "AUTOSAR Version Numbers of Crypto_70_HW.c and Crypto_70_HW.h are different"
#endif

#if ( ( CRYPTO_70_SW_MAJOR_VERSION_HW_C != CRYPTO_70_SW_MAJOR_VERSION_HW_H ) || \
      ( CRYPTO_70_SW_MINOR_VERSION_HW_C != CRYPTO_70_SW_MINOR_VERSION_HW_H ) || \
      ( CRYPTO_70_SW_PATCH_VERSION_HW_C != CRYPTO_70_SW_PATCH_VERSION_HW_H ) )
    #error "Software Version Numbers of Crypto_70_HW.c and Crypto_70_HW.h are different"
#endif
/* Crypto_70_HW.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
#define CRYPTO_START_SEC_CONST_8
#include "Crypto_MemMap.h"
/* Hash value of zero (SHA256) */
static const uint8 s_crypto_70_hashZero_sha256[HASH_SHA256_LENGTH] = {
    0xe3U, 0xb0U, 0xc4U, 0x42U, 0x98U, 0xfcU, 0x1cU, 0x14U, 0x9aU, 0xfbU, 0xf4U, 0xc8U, 0x99U, 0x6fU, 0xb9U, 0x24U,
    0x27U, 0xaeU, 0x41U, 0xe4U, 0x64U, 0x9bU, 0x93U, 0x4cU, 0xa4U, 0x95U, 0x99U, 0x1bU, 0x78U, 0x52U, 0xb8U, 0x55U
};
#define CRYPTO_STOP_SEC_CONST_8
#include "Crypto_MemMap.h"
#endif /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/
#if ( TRUE == CRYPTO_70_HASH_ENABLE )
#define CRYPTO_START_SEC_VAR_NO_INIT_LOCAL_32
#include "Crypto_MemMap.h"
static Crypto_70_Sha256HandleType s_ShaWork;
#define CRYPTO_STOP_SEC_VAR_NO_INIT_LOCAL_32
#include "Crypto_MemMap.h"
#endif  /* #if ( TRUE == CRYPTO_70_HASH_ENABLE ) */

#if ( TRUE == CRYPTO_70_RSA_ENABLE )
#define CRYPTO_START_SEC_VAR_NO_INIT_LOCAL_8
#include "Crypto_MemMap.h"
static Crypto_70_OaepBufType    s_OaepBuf;
static uint8                    s_DecryptedMsg[OAEP_DECODED_BUFF_LEN];
static Crypto_70_MgfBufType     s_MgfBuf;
#define CRYPTO_STOP_SEC_VAR_NO_INIT_LOCAL_8
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_NO_INIT_LOCAL_32
#include "Crypto_MemMap.h"
static Crypto_70_RsaWorkAreaType s_RSAWorkArea;
#define CRYPTO_STOP_SEC_VAR_NO_INIT_LOCAL_32
#include "Crypto_MemMap.h"
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */

#if ( ( TRUE == CRYPTO_70_AESEA_ENABLE) && ( TRUE == CRYPTO_70_RSA_ENABLE ) )
#define CRYPTO_START_SEC_VAR_NO_INIT_LOCAL_8
#include "Crypto_MemMap.h"
static uint8                    s_EncodedMsg[OAEP_ENCODED_BUFF_LEN];
#define CRYPTO_STOP_SEC_VAR_NO_INIT_LOCAL_8
#include "Crypto_MemMap.h"
#endif  /* #if ( ( TRUE == CRYPTO_70_AESEA_ENABLE) && ( TRUE == CRYPTO_70_RSA_ENABLE ) ) */

#if ( TRUE == CRYPTO_70_HASH_ENABLE )
#define CRYPTO_START_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
static bool_t   s_DataInput = FALSE;
#define CRYPTO_STOP_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
#endif  /* #if ( TRUE == CRYPTO_70_HASH_ENABLE ) */

#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
#define CRYPTO_START_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
static uint8    s_PreRnd[RND_BYTE_LENGTH] = {
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U
};
#define CRYPTO_STOP_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#if ( TRUE == CRYPTO_70_AESEA_ENABLE)
static Std_ReturnType crypto_70_HW_AesEnc ( Crypto_JobType* job , const uint8* iv );
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */

#if ( ( TRUE == CRYPTO_70_RSA_ENABLE ) && ( TRUE == CRYPTO_70_AESEA_ENABLE ) )
static Std_ReturnType crypto_70_HW_RsaEnc ( Crypto_JobType* job, Crypto_70_RsaKeyType* pRsaKey );
#endif  /* #if ( ( TRUE == CRYPTO_70_RSA_ENABLE ) && ( TRUE == CRYPTO_70_AESEA_ENABLE ) ) */

#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
static Std_ReturnType crypto_70_HW_AesDec ( Crypto_JobType* job , const uint8* iv );
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */

#if ( TRUE == CRYPTO_70_RSA_ENABLE )
static Std_ReturnType crypto_70_HW_RsaDec ( Crypto_JobType* job, Crypto_70_RsaKeyType* pRsaKey );

#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
static Std_ReturnType crypto_70_HW_oaepEncode ( uint32 mLen, const uint8* pMsg, uint8* pEncodedMsg );
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */

static Std_ReturnType crypto_70_HW_oaepDecode ( const uint8* pEncodedMsg, uint32* mLen, uint8* pMsg );

#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
static void crypto_70_HW_generateDB ( const uint8* pMsg, uint32 mLen, uint8* pDB, uint32* dbLen );

static Std_ReturnType crypto_70_HW_generateRNG ( uint32 length, uint8* pRng );
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */

static Std_ReturnType crypto_70_HW_MGF ( uint32 mgfDataLen, const uint8* mgfData, uint32 maskLen, uint8* mask );

static void crypto_70_HW_processXOR ( const uint8* arrayA, const uint8* arrayB, uint8* resArray, uint32 length );
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_Init                                            */
/* Param       : void                                                         */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful.                               */
/*                    E_NOT_OK: Request Failed.                               */
/* Contents    : Initializes the Crypto Driver.                               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_70_HW_Init( void )
{
    Std_ReturnType          retValue;
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    Crypto_70_AesReturnType ans;
    e_rfd_ret_t             rfdRet;
 
    /* Initialize RFD */
    rfdRet = R_RFD_Init( CRYPTO_70_FREQUENCY );
 
    if ( R_RFD_ENUM_RET_STS_OK != rfdRet ) {
        /* CPU operation frequency is out of range */
        retValue = E_NOT_OK;
    } else {
        /* Initialize random number generator */
        ans = R_FUNC_INIT_RNG( 0U );
 
        if ( CRYPTO_70_HSM_OK != ans ) {
            retValue = E_NOT_OK;
        } else {
            retValue = E_OK;
        }
    }
#else
    retValue = E_OK;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
    return ( retValue );
}

/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_CancelJob                                       */
/* Param         (inout) jobPrimitive  Pointer to the job primitive.          */
/*                                  Contains primitive relevant information.  */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful, job has been removed.         */
/*                    CRYPTO_E_JOB_CANCELED: Request successful, but job is   */
/*                                           still processing.                */
/* Contents    : Set the cancel request to Libraries.                         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_70_HW_CancelJob( const Crypto_JobPrimitiveInfoType* jobPrimitive )
{
    Std_ReturnType                  retValue;
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    Crypto_70_AesReturnType         ansAESEA;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
    uint8                           ansRSA;
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
    const Crypto_PrimitiveInfoType* pPrimitiveInfo;
 
    pPrimitiveInfo = jobPrimitive->primitiveInfo;
 
    switch ( pPrimitiveInfo->service ) {
    case CRYPTO_HASH:
        /* Processing in "SHA hash function Library" */
        retValue = CRYPTO_E_JOB_CANCELED;
        break;
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    case CRYPTO_MACGENERATE:
    case CRYPTO_MACVERIFY:
    case CRYPTO_RANDOMGENERATE:
    case CRYPTO_RANDOMSEED:
        /* Processing in "AESEA Sample Security Driver" */
        ansAESEA = R_FUNC_CANCEL();
        if ( CRYPTO_70_HSM_OK == ansAESEA ) {
            retValue = CRYPTO_E_JOB_CANCELED;
        } else {
            retValue = E_OK;
        }
        break;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
    case CRYPTO_ENCRYPT:
    case CRYPTO_DECRYPT:
#if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) && ( TRUE == CRYPTO_70_RSA_ENABLE ) )
        if ( CRYPTO_ALGOFAM_AES == pPrimitiveInfo->algorithm.family ) {
            /* Processing in "AESEA Sample Security Driver" */
            ansAESEA = R_FUNC_CANCEL();
            if ( CRYPTO_70_HSM_OK == ansAESEA ) {
                retValue = CRYPTO_E_JOB_CANCELED;
            } else {
                retValue = E_OK;
            }
        } else {
            /* Processing in "RSA Library" */
            ansRSA = R_RSA_CancelReq();
            if ( CRYPTO_70_RSA_OK == ansRSA ) {
                retValue = CRYPTO_E_JOB_CANCELED;
            } else {
                retValue = E_OK;
            }
        }
        break;
#elif ( TRUE == CRYPTO_70_AESEA_ENABLE )
        ansAESEA = R_FUNC_CANCEL();
        if ( CRYPTO_70_HSM_OK == ansAESEA ) {
            retValue = CRYPTO_E_JOB_CANCELED;
        } else {
            retValue = E_OK;
        }
        break;
#elif ( TRUE == CRYPTO_70_RSA_ENABLE )
        ansRSA = R_RSA_CancelReq();
        if ( CRYPTO_70_RSA_OK == ansRSA ) {
            retValue = CRYPTO_E_JOB_CANCELED;
        } else {
            retValue = E_OK;
        }
        break;
#else
        /* unsupported service */
        retValue = E_OK;
        break;
#endif  /* #if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) && ( TRUE == CRYPTO_70_RSA_ENABLE ) ) */
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
    case CRYPTO_SIGNATUREGENERATE:
    case CRYPTO_SIGNATUREVERIFY:
        /* Processing in "RSA Library" */
        ansRSA = R_RSA_CancelReq();
        if ( CRYPTO_70_RSA_OK == ansRSA ) {
            retValue = CRYPTO_E_JOB_CANCELED;
        } else {
            retValue = E_OK;
        }
        break;
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
    default:
        /* unsupported service */
        retValue = E_OK;
        break;
    }
 
    return ( retValue );
}

#if ( TRUE == CRYPTO_70_HASH_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_Hash                                            */
/* Param       : (inout) job                                                  */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function calculates hash value.                         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_70_HW_Hash( Crypto_JobType* job )
{
    Std_ReturnType                      retValue = E_NOT_OK;
    uint16                              mLen;
    uint8                               shaCtrlFlg = 0x00U;
    uint8                               resSha = CRYPTO_70_SHA_E_UNEXEC;
    Crypto_JobPrimitiveInputOutputType* pPrimitiveInOut;
    Crypto_OperationModeType            jobState;
 
    /* set input/output address */
    pPrimitiveInOut = &job->PrimitiveInputOutput;
    jobState = pPrimitiveInOut->mode;
    mLen = (uint16)pPrimitiveInOut->inputLength;
 
    /* set shaCtrlFlg */
    if ( CRYPTO_OPERATIONMODE_UPDATE == ( CRYPTO_OPERATIONMODE_UPDATE & jobState ) ) {
        if ( FALSE == s_DataInput ) {
            /* first time */
            shaCtrlFlg = CRYPTO_70_SHA_CTRL_INIT;
            s_DataInput = TRUE;
        } else {
            /* add data */
            shaCtrlFlg = CRYPTO_70_SHA_CTRL_ADD;
        }
        retValue = E_OK;
    }
 
    if ( CRYPTO_OPERATIONMODE_FINISH == ( CRYPTO_OPERATIONMODE_FINISH & jobState ) ) {
        /* last time */
        shaCtrlFlg = (uint8)( (uint32)shaCtrlFlg | (uint32)CRYPTO_70_SHA_CTRL_FINISH );
        s_DataInput = FALSE;
        retValue = E_OK;
    }
 
    /* calculate hash value */
    if ( E_OK == retValue ) {
        resSha = Crypto_70_HW_HashDigest( pPrimitiveInOut->inputPtr, pPrimitiveInOut->outputPtr,
                                          mLen, shaCtrlFlg, &s_ShaWork );
    }
 
    /* check result */
    if ( CRYPTO_70_SHA_OK == resSha ) {
        retValue = E_OK;
    } else {
        retValue = E_NOT_OK;
    }
 
    /* check cancel request */
    if ( TRUE == Crypto_CancelReq ) {
        if ( TRUE == s_DataInput ) {
            resSha = Crypto_70_HW_HashDigest( NULL_PTR, pPrimitiveInOut->outputPtr,
                                              0U, CRYPTO_70_SHA_CTRL_FINISH, &s_ShaWork );
            s_DataInput = FALSE;
 
            if ( CRYPTO_70_SHA_OK == resSha ) {
                retValue = E_OK;
            } else {
                retValue = E_NOT_OK;
            }
        }
 
        if ( E_OK == retValue ) {
            retValue = CRYPTO_E_JOB_CANCELED;
        }
    }
 
    return ( retValue );
}
#endif  /* #if ( TRUE == CRYPTO_70_HASH_ENABLE ) */

#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_MacGenerate                                     */
/* Param       : (inout) job        Pointer to the configuration of the job.  */
/*                                  Contains structures with job and          */
/*                                  primitive relevant information but also   */
/*                                  pointer to result buffers.                */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful.                               */
/*                    E_NOT_OK: Request Failed.                               */
/*                    CRYPTO_E_BUSY: job is processing.                       */
/*                    CRYPTO_E_JOB_CANCELED: Job Canceled                     */
/* Contents    : Performs the crypto primitive, that is configured as         */
/*               MacGenerate service in the job parameter.                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_70_HW_MacGenerate( Crypto_JobType* job )
{
    Std_ReturnType                      retValue;
    uint16                              msgBitSize;
    uint8                               keyId;
    uint8                               keyExp;
    Crypto_JobPrimitiveInputOutputType* pPrimitiveInOut;
    Crypto_70_AesReturnType             resAESEA;
 
    /* set keyId and keyExp */
    keyExp = (uint8)( job->cryptoKeyId / AES_KEY_BLOCK_NUM );
    keyId = (uint8)( job->cryptoKeyId - ( (uint32)keyExp * 10U ) );
 
    /* set input address */
    pPrimitiveInOut = &job->PrimitiveInputOutput;
    msgBitSize = (uint16)( pPrimitiveInOut->inputLength * (uint32)CRYPTO_70_BYTE2BIT );
 
    /* generate mac */
    resAESEA = R_FUNC_GENERATE_MAC( keyId, keyExp, msgBitSize,
                                    pPrimitiveInOut->inputPtr, pPrimitiveInOut->outputPtr );
 
    /* check result */
    switch ( resAESEA ) {
    case CRYPTO_70_HSM_OK:
        retValue = E_OK;
        break;
    case CRYPTO_70_HSM_BUSY:
        retValue = CRYPTO_E_BUSY;
        break;
    case CRYPTO_70_HSM_CANCELED:
        retValue = CRYPTO_E_JOB_CANCELED;
        break;
    case CRYPTO_70_HSM_NG:
    default:
        retValue = E_NOT_OK;
        break;
    }
 
    return ( retValue );
}

/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_MacVerify                                       */
/* Param       : (inout) job        Pointer to the configuration of the job.  */
/*                                  Contains structures with job and          */
/*                                  primitive relevant information but also   */
/*                                  pointer to result buffers.                */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful.                               */
/*                    E_NOT_OK: Request Failed.                               */
/*                    CRYPTO_E_BUSY: job is processing.                       */
/*                    CRYPTO_E_JOB_CANCELED: Job Canceled                     */
/* Contents    : Performs the crypto primitive, that is configured as         */
/*               MacVerify service in the job parameter.                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_70_HW_MacVerify( Crypto_JobType* job )
{
    Std_ReturnType                      retValue;
    uint16                              msgBitSize;
    uint8                               macBitSize;
    uint8                               secstVal;
    uint8                               keyId;
    uint8                               keyExp;
    Crypto_JobPrimitiveInputOutputType* pPrimitiveInOut;
    Crypto_VerifyResultType*            pVerify;
    Crypto_70_AesReturnType             resAESEA;
 
    /* set keyId and keyExp */
    keyExp = (uint8)( job->cryptoKeyId / AES_KEY_BLOCK_NUM );
    keyId = (uint8)( job->cryptoKeyId - ( (uint32)keyExp * 10U ) );
 
    /* set input address */
    pPrimitiveInOut = &job->PrimitiveInputOutput;
    pVerify = pPrimitiveInOut->verifyPtr;
    msgBitSize = (uint16)( pPrimitiveInOut->inputLength * (uint32)CRYPTO_70_BYTE2BIT );
    macBitSize = (uint8)pPrimitiveInOut->secondaryInputLength;
 
    /* check macBitSize */
    if ( AES_BLOCK_SIZE_BIT == macBitSize ) {
        macBitSize = 0x00U;
    }
 
    /* verify MAC */
    resAESEA = R_FUNC_VERIFY_MAC( keyId, keyExp, msgBitSize, pPrimitiveInOut->inputPtr,
                                  macBitSize, pPrimitiveInOut->secondaryInputPtr );
 
    /* check result */
    switch ( resAESEA ) {
    case CRYPTO_70_HSM_OK:
        secstVal = R_FUNC_GET_STATUS();
        if ( CRYPTO_70_HSM_MAC_VERIFY == ( CRYPTO_70_HSM_MAC_VERIFY & secstVal ) ) {
            *pVerify = CRYPTO_E_VER_OK;
        } else {
            *pVerify = CRYPTO_E_VER_NOT_OK;
        }
        retValue = E_OK;
        break;
    case CRYPTO_70_HSM_BUSY:
        *pVerify = CRYPTO_E_VER_NOT_OK;
        retValue = CRYPTO_E_BUSY;
        break;
    case CRYPTO_70_HSM_CANCELED:
        *pVerify = CRYPTO_E_VER_NOT_OK;
        retValue = CRYPTO_E_JOB_CANCELED;
        break;
    case CRYPTO_70_HSM_NG:
    default:
        *pVerify = CRYPTO_E_VER_NOT_OK;
        retValue = E_NOT_OK;
        break;
    }
 
    return ( retValue );
}

/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_Encrypt                                         */
/* Param       : (inout) job        Pointer to the configuration of the job.  */
/*                                  Contains structures with job and          */
/*                                  primitive relevant information but also   */
/*                                  pointer to result buffers.                */
/*             : (inout) iv         Initial Vector.                           */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful.                               */
/*                    E_NOT_OK: Request Failed.                               */
/*                    CRYPTO_E_SMALL_BUFFER: The provided buffer is           */
/*                                           too small to store the result.   */
/*                    CRYPTO_E_BUSY: job is processing.                       */
/*                    CRYPTO_E_KEY_NOT_VALID: Key is not valid to use         */
/*                    CRYPTO_E_KEY_WRITE_FAIL: Load key command failed        */
/*                    CRYPTO_E_KEY_NOT_AVAILABLE: Load key command failed     */
/*                    CRYPTO_E_JOB_CANCELED: Job Canceled                     */
/* Contents    : Performs the crypto primitive, that is configured as         */
/*               Encrypt service in the job parameter.                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_70_HW_Encrypt( Crypto_JobType* job, const uint8* iv, Crypto_70_RsaKeyType* pRsaKey )
{
    Std_ReturnType  retValue;
 
    /* check encryption algorithm */
    switch ( job->jobPrimitiveInfo->primitiveInfo->algorithm.family ) {
    case CRYPTO_ALGOFAM_AES:
        retValue = crypto_70_HW_AesEnc( job, iv );
        break;
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
    case CRYPTO_ALGOFAM_RSA:
        retValue = crypto_70_HW_RsaEnc( job, pRsaKey );
        break;
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
    default:
        retValue = E_NOT_OK;
        break;
    }
 
    return ( retValue );
}
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */

/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_Decrypt                                         */
/* Param       : (inout) job        Pointer to the configuration of the job.  */
/*                                  Contains structures with job and          */
/*                                  primitive relevant information but also   */
/*                                  pointer to result buffers.                */
/*             : (in) keyId         key id                                    */
/*             : (in) messageBitSize Bit size of input message data.          */
/*                                  This value must be multiple of 1 block.   */
/*                                  Note that one block = 128 bit.            */
/*             : (inout) iv         Initial Vector.                           */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful.                               */
/*                    E_NOT_OK: Request Failed.                               */
/*                    CRYPTO_E_SMALL_BUFFER: The provided buffer is           */
/*                                           too small to store the result.   */
/*                    CRYPTO_E_BUSY: job is processing.                       */
/*                    CRYPTO_E_KEY_NOT_VALID: Key is not valid to use         */
/*                    CRYPTO_E_KEY_WRITE_FAIL: Load key command failed        */
/*                    CRYPTO_E_KEY_NOT_AVAILABLE: Load key command failed     */
/*                    CRYPTO_E_JOB_CANCELED: Job Canceled                     */
/* Contents    : Performs the crypto primitive, that is configured as         */
/*               Decrypt service in the job parameter.                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_70_HW_Decrypt( Crypto_JobType* job, const uint8* iv, Crypto_70_RsaKeyType* pRsaKey  )
{
    Std_ReturnType  retValue;
 
    /* check decryption algorithm */
    switch ( job->jobPrimitiveInfo->primitiveInfo->algorithm.family ) {
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    case CRYPTO_ALGOFAM_AES:
        retValue = crypto_70_HW_AesDec( job, iv );
        break;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
    case CRYPTO_ALGOFAM_RSA:
        retValue = crypto_70_HW_RsaDec( job, pRsaKey );
        break;
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
    default:
        retValue = E_NOT_OK;
        break;
    }
 
    return ( retValue );
}

#if ( TRUE == CRYPTO_70_RSA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_SignatureGenerate                               */
/* Param       : (in) job                                                     */
/*               (in) p_key                                                   */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function generates the signature.                       */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_70_HW_SignatureGenerate( Crypto_JobType* job, Crypto_70_RsaKeyType* p_key )
{
    Std_ReturnType                      retValue;
    Crypto_70_Rom_BignumRsa2048Type     message;
    Crypto_70_BignumRsa2048Type         signature;
    uint8                               hashType;
    uint8                               resRsa;
    Crypto_JobPrimitiveInputOutputType* pPrimitiveInOut;
 
    /* set input/output address */
    pPrimitiveInOut = &job->PrimitiveInputOutput;
    message.p_adr = (QL_70_FAR uint8*)pPrimitiveInOut->inputPtr;
    message.len = (uint16)pPrimitiveInOut->inputLength;
    signature.p_adr = pPrimitiveInOut->outputPtr;
    signature.len = (uint16) *(pPrimitiveInOut->outputLengthPtr);
 
    /* check Hash algorithm */
    if ( CRYPTO_ALGOFAM_SHA2_256 == job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily ) {
        hashType = RSA_HASH_SHA256;
        retValue = E_OK;
    } else {
        retValue = E_NOT_OK;
    }
 
    if ( E_OK == retValue ) {
        /* generate the signature */
        resRsa = R_RSA_SignatureGeneratePkcs( &message, &signature, p_key, hashType, &s_RSAWorkArea );
 
        if ( CRYPTO_70_RSA_OK == resRsa ) {
            retValue = E_OK;
            *(pPrimitiveInOut->outputLengthPtr) = (uint32)CRYPTO_70_RSA_LENGTH;
        } else if ( CRYPTO_70_RSA_CANCEL_RTN == resRsa ) {
            retValue = CRYPTO_E_JOB_CANCELED;
        } else {
            retValue = E_NOT_OK;
        }
    }
 
    return ( retValue );
}

/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_SignatureVerify                                 */
/* Param       : (in) job                                                     */
/*               (in) p_key                                                   */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function verifies the signature.                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_70_HW_SignatureVerify( Crypto_JobType* job, Crypto_70_RsaKeyType* p_key )
{
    Std_ReturnType                      retValue;
    Crypto_VerifyResultType*            pVerify;
    Crypto_70_Rom_BignumRsa2048Type     message;
    Crypto_70_BignumRsa2048Type         signature;
    uint8                               hashType;
    uint8                               resRsa;
    Crypto_JobPrimitiveInputOutputType* pPrimitiveInOut;
 
    /* set input/output address */
    pPrimitiveInOut = &job->PrimitiveInputOutput;
    message.p_adr = (QL_70_FAR uint8*)pPrimitiveInOut->inputPtr;
    message.len = (uint16)pPrimitiveInOut->inputLength;
    signature.p_adr = (uint8*)pPrimitiveInOut->secondaryInputPtr;
    signature.len = (uint16)pPrimitiveInOut->secondaryInputLength;
    pVerify = pPrimitiveInOut->verifyPtr;
 
    /* check Hash algorithm */
    if ( CRYPTO_ALGOFAM_SHA2_256 == job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily ) {
        hashType = RSA_HASH_SHA256;
        retValue = E_OK;
    } else {
        retValue = E_NOT_OK;
    }
 
    if ( E_OK == retValue ) {
        /* verify the signature */
        resRsa = R_RSA_SignatureVerifyPkcs( &signature, &message, p_key, hashType, &s_RSAWorkArea );
 
        if ( CRYPTO_70_RSA_OK == resRsa ) {
            *pVerify = CRYPTO_E_VER_OK;
            retValue = E_OK;
        } else if ( CRYPTO_70_RSA_SIG_VERIFY_NG == resRsa ) {
            *pVerify = CRYPTO_E_VER_NOT_OK;
            retValue = E_OK;
        } else if (CRYPTO_70_RSA_CANCEL_RTN == resRsa ) {
            *pVerify = CRYPTO_E_VER_NOT_OK;
            retValue = CRYPTO_E_JOB_CANCELED;
        } else {
            *pVerify = CRYPTO_E_VER_NOT_OK;
            retValue = E_NOT_OK;
        }
    }
 
    return ( retValue );
}
#endif

#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_RandomGenerate                                  */
/* Param       : (inout) job        Pointer to the configuration of the job.  */
/*                                  Contains structures with job and          */
/*                                  primitive relevant information but also   */
/*                                  pointer to result buffers.                */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful.                               */
/*                    E_NOT_OK: Request Failed.                               */
/*                    CRYPTO_E_BUSY: job is processing.                       */
/*                    CRYPTO_E_JOB_CANCELED: Job Canceled                     */
/*                    CRYPTO_E_ENTROPY_EXHAUSTED: the entropy is exhausted.   */
/* Contents    : Performs the crypto primitive, that is configured as         */
/*               RandomGenerate service in the job parameter.                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_70_HW_RandomGenerate( Crypto_JobType* job )
{
    uint8                               rndVal[RND_BYTE_LENGTH];
    Std_ReturnType                      retValue;
    uint8                               rndLen;
    uint8_least                         cnt;
    uint8                               entropyChk = 0U;
    Crypto_70_AesReturnType             resRnd;
    Crypto_JobPrimitiveInputOutputType* pPrimitiveInOut;
 
    /* get output buffer length */
    pPrimitiveInOut = &job->PrimitiveInputOutput;
    rndLen = (uint8)*(pPrimitiveInOut->outputLengthPtr);
    
    /* check output buffer length */
    if ( RND_BYTE_LENGTH < rndLen ) {
        /* [SWS_Csm_01543] */
        /* resultLengthPtr shall contaion the size of the buffer provided by resultPtr. */
        /* When the buffer is larger than RND_BYTE_LENGTH, the length of the random number */
        /* will be RND_BYTE_LENGTH. */
        rndLen = RND_BYTE_LENGTH;
    }
    
    /* generate random number */
    resRnd = R_FUNC_RND( &rndVal[0] );
    
    /* error check */
    switch ( resRnd ) {
    case CRYPTO_70_HSM_OK:
        retValue = E_OK;
        break;
    case CRYPTO_70_HSM_BUSY:
        retValue = CRYPTO_E_BUSY;
        break;
    case CRYPTO_70_HSM_CANCELED:
        retValue = CRYPTO_E_JOB_CANCELED;
        break;
    case CRYPTO_70_HSM_NG:
    default:
        retValue = E_NOT_OK;
        break;
    }
 
    /* entropy check */
    if ( E_OK == retValue ) {
        /* If the generated random number is equal to the previous value, */
        /* it is considered that the entropy is exhausted. */
        for ( cnt=0U; cnt<RND_BYTE_LENGTH; cnt++ ){
            if ( s_PreRnd[cnt] == rndVal[cnt] ) {
                entropyChk++;
            }
        }
 
        if ( RND_BYTE_LENGTH > entropyChk ) {
            /* When the entropy is not exhausted, update the previous value. */
            crypto_memCopy( &rndVal[0], &s_PreRnd[0], RND_BYTE_LENGTH );
 
            /* Copy the generated random number to the output buffer. */
            /* [SWS_Csm_01543] */
            /* If the provided length information is smaller than the total length of */
            /* the random number result, the resultPtr will contain the truncated random number. */
            crypto_memCopy( &rndVal[0], pPrimitiveInOut->outputPtr, (uint32)rndLen );
 
            /* [SWS_Csm_01543] */
            /* When the request has finished, the actual length of the returned random number */
            /* shall be stored. */
            *(pPrimitiveInOut->outputLengthPtr) = rndLen;
        } else {
            retValue = CRYPTO_E_ENTROPY_EXHAUSTED;
        }
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_RandomSeedExtend                                */
/* Param       : (in) seedPtr                                                 */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function will extend the random seed value.             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_70_HW_RandomSeedExtend( const uint8* seedPtr )
{
    Std_ReturnType          retValue;
    Crypto_70_AesReturnType ans;
 
    ans = R_FUNC_EXTEND_SEED( seedPtr );
 
    switch( ans ) {
    case CRYPTO_70_HSM_OK:
        retValue = E_OK;
        break;
    case CRYPTO_70_HSM_BUSY:
        retValue = CRYPTO_E_BUSY;
        break;
    case CRYPTO_70_HSM_CANCELED:
        retValue = CRYPTO_E_JOB_CANCELED;
        break;
    case CRYPTO_70_HSM_NG:
    default:
        retValue = E_NOT_OK;
        break;
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_GetProcessStatus                                */
/* Param       : void                                                         */
/* Return      : uint8                                                        */
/*                                                                            */
/* Contents    : This function will get AESEA prcessing status.               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
uint8 Crypto_70_HW_GetProcessStatus( void )
{
    uint8   secstVal;
 
    /* get processing status */
    secstVal = R_FUNC_GET_STATUS();
 
    return ( secstVal );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_GetErrorStatus                                  */
/* Param       : void                                                         */
/* Return      : uint16                                                       */
/*                                                                            */
/* Contents    : This function will get AESEA error status.                   */
/*               After execute this function, AESEA error is cleared.         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
uint16 Crypto_70_HW_GetErrorStatus( void )
{
    uint16  secerVal;
 
    /* get error status */
    secerVal = Crypto_70_RL78F2X_GetErrorStatus();
 
    return ( secerVal );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : Crypto_70_HW_ClearProcessStatus                              */
/* Param       : (in) clearStatus                                             */
/*                                                                            */
/* Return      : uint8                                                        */
/*                                                                            */
/* Contents    : This function will clear AESEA prcessing status.             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
uint8 Crypto_70_HW_ClearProcessStatus( const uint8 clearStatus )
{
    uint8   secerVal;
 
    /* clear processing status */
    secerVal = Crypto_70_RL78F2X_ClearProcessStatus( clearStatus );
 
    return ( secerVal );
}
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_70_HW_AesEnc                                          */
/* Param       : (inout) job                                                  */
/*               (in) iv                                                      */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_BUSY                                             */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function encrypts the message by AES                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_70_HW_AesEnc ( Crypto_JobType* job , const uint8* iv )
{
    Std_ReturnType                      retValue;
    uint32                              blockNum;
    const uint8*                        pMsg;
    uint8*                              cText;
    uint32                              mLen;
    uint32*                             cLen;
    uint8                               paddingVal;
    uint8                               keyId;
    uint8                               keyExp;
    Crypto_70_AesReturnType             resAESEA;
    Crypto_JobPrimitiveInputOutputType* pPrimitiveInOut;
    Crypto_AlgorithmModeType            algoMode;
 
    pPrimitiveInOut = &job->PrimitiveInputOutput;
    pMsg = (uint8 QL_70_NEAR *)pPrimitiveInOut->inputPtr;
    cText = pPrimitiveInOut->outputPtr;
    mLen = pPrimitiveInOut->inputLength;
    cLen = pPrimitiveInOut->outputLengthPtr;
    algoMode = job->jobPrimitiveInfo->primitiveInfo->algorithm.mode;
 
    /* set keyId and keyExp */
    keyExp = (uint8)( job->cryptoKeyId / AES_KEY_BLOCK_NUM );
    keyId = (uint8)( job->cryptoKeyId - ( (uint32)keyExp * 10U ) );
 
    /* calculate block num */
    blockNum = ( mLen / (uint32)AES_BLOCK_SIZE_BYTE ) + 1UL;
 
    /* add padding (PKCS#7) */
    if ( CRYPTO_OPERATIONMODE_FINISH == ( CRYPTO_OPERATIONMODE_FINISH & pPrimitiveInOut->mode ) ) {
        paddingVal = AES_BLOCK_SIZE_BYTE - (uint8)( mLen % (uint32)AES_BLOCK_SIZE_BYTE );
        crypto_memSet( (uint8*)&pMsg[mLen], paddingVal, (uint32)paddingVal );
        *cLen = mLen + paddingVal;
    }
 
    /* encryption */
    if ( CRYPTO_ALGOMODE_ECB == algoMode ) {
        resAESEA = R_FUNC_ENC_ECB( keyId, keyExp, (uint16)blockNum, pMsg, cText );
    } else if ( CRYPTO_ALGOMODE_CBC == algoMode ) {
        resAESEA = R_FUNC_ENC_CBC( keyId, keyExp, iv, (uint16)blockNum, pMsg, cText );
    } else {
        resAESEA = CRYPTO_70_HSM_NG;
    }
 
    /* error check */
    switch ( resAESEA ) {
    case CRYPTO_70_HSM_OK:
        retValue = E_OK;
        break;
    case CRYPTO_70_HSM_BUSY:
        retValue = CRYPTO_E_BUSY;
        break;
    case CRYPTO_70_HSM_CANCELED:
        retValue = CRYPTO_E_JOB_CANCELED;
        break;
    case CRYPTO_70_HSM_NG:
    default:
        retValue = E_NOT_OK;
        break;
    }
 
    return ( retValue );
}
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
#if ( ( TRUE == CRYPTO_70_RSA_ENABLE ) && ( TRUE == CRYPTO_70_AESEA_ENABLE ) )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_70_HW_RsaEnc                                          */
/* Param       : (inout) job                                                  */
/*               (in) pRsaKey                                                 */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function encrypts the message by RSA-OAEP.              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
 
static Std_ReturnType crypto_70_HW_RsaEnc ( Crypto_JobType* job, Crypto_70_RsaKeyType* pRsaKey )
{
    Std_ReturnType                              retValue;
    Crypto_70_BignumRsa2048Type                 input;
    Crypto_70_BignumRsa2048Type                 output;
    const uint8*                                pMsg;
    uint32                                      mLen;
    uint8                                       resRsa;
    const Crypto_JobPrimitiveInputOutputType*   pPrimitiveInOut;
 
    pPrimitiveInOut = &job->PrimitiveInputOutput;
    mLen = pPrimitiveInOut->inputLength;
    pMsg = (uint8 QL_70_NEAR *)pPrimitiveInOut->inputPtr;
 
    retValue = crypto_70_HW_oaepEncode( mLen, pMsg, &s_EncodedMsg[0] );
 
    if ( E_OK == retValue ) {
        /* set input address */
        input.p_adr = &s_EncodedMsg[0];
        input.len = OAEP_ENCODED_BUFF_LEN;
 
        /* set output address */
        output.p_adr = pPrimitiveInOut->outputPtr;
        output.len = OAEP_ENCODED_BUFF_LEN;
 
        /* RSA encryption */
        resRsa = R_RSA_ModExp( &input, &output, pRsaKey, &s_RSAWorkArea );
        if ( CRYPTO_70_RSA_OK == resRsa ) {
            *pPrimitiveInOut->outputLengthPtr = output.len;
            retValue = E_OK;
        } else if ( CRYPTO_70_RSA_CANCEL_RTN == resRsa ) {
            retValue = CRYPTO_E_JOB_CANCELED;
        } else {
            retValue = E_NOT_OK;
        }
    }
 
    return ( retValue );
}
#endif  /* #if ( ( TRUE == CRYPTO_70_RSA_ENABLE ) && ( TRUE == CRYPTO_70_AESEA_ENABLE ) ) */
 
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_70_HW_AesDec                                          */
/* Param       : (inout) job                                                  */
/*               (in) iv                                                      */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_BUSY                                             */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function decrypts the encrypted message by AES.         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_70_HW_AesDec ( Crypto_JobType* job , const uint8* iv )
{
    Std_ReturnType                              retValue;
    uint32                                      blockNum;
    const uint8 QL_70_FAR *                     cText;
    uint8*                                      pMsg;
    uint32                                      cLen;
    uint32*                                     mLen;
    uint8                                       paddingVal;
    uint8                                       keyId;
    uint8                                       keyExp;
    Crypto_70_AesReturnType                     resAESEA;
    const Crypto_JobPrimitiveInputOutputType*   pPrimitiveInOut;
    Crypto_AlgorithmModeType                    algoMode;
 
    pPrimitiveInOut = &job->PrimitiveInputOutput;
    cText = pPrimitiveInOut->inputPtr;
    pMsg = pPrimitiveInOut->outputPtr;
    cLen = pPrimitiveInOut->inputLength;
    mLen = pPrimitiveInOut->outputLengthPtr;
    algoMode = job->jobPrimitiveInfo->primitiveInfo->algorithm.mode;
 
    /* set keyId and keyExp */
    keyExp = (uint8)( job->cryptoKeyId / AES_KEY_BLOCK_NUM );
    keyId = (uint8)( job->cryptoKeyId - ( (uint32)keyExp * 10U ) );
 
    /* calculate block num */
    blockNum = cLen / AES_BLOCK_SIZE_BYTE;
 
    /* decryption */
    if ( CRYPTO_ALGOMODE_ECB == algoMode ) {
        resAESEA = R_FUNC_DEC_ECB( keyId, keyExp, (uint16)blockNum, cText, pMsg );
    } else if ( CRYPTO_ALGOMODE_CBC == algoMode ) {
        resAESEA = R_FUNC_DEC_CBC( keyId, keyExp, iv, (uint16)blockNum, cText, pMsg );
    } else {
        resAESEA = CRYPTO_70_HSM_NG;
    }
 
    /* error check */
    switch( resAESEA ) {
    case CRYPTO_70_HSM_OK:
        retValue = E_OK;
        break;
    case CRYPTO_70_HSM_BUSY:
        retValue = CRYPTO_E_BUSY;
        break;
    case CRYPTO_70_HSM_CANCELED:
        retValue = CRYPTO_E_JOB_CANCELED;
        break;
    case CRYPTO_70_HSM_NG:
    default:
        retValue = E_NOT_OK;
        break;
    }
 
    if ( E_OK == retValue ) {
        if ( CRYPTO_OPERATIONMODE_FINISH == ( CRYPTO_OPERATIONMODE_FINISH & pPrimitiveInOut->mode ) ) {
            /* remove padding (PKCS#7) */
            paddingVal = pMsg[cLen-1U];
            crypto_memSet( &pMsg[cLen-paddingVal], 0x00U, (uint32)paddingVal );
            *mLen -= (uint32)paddingVal ;
        }
    } else {
        /* do nothing */
    }
 
    return ( retValue );
}
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_70_HW_RsaDec                                          */
/* Param       : (inout) job                                                  */
/*               (in) pRsaKey                                                 */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function decrypts the encrypted message by RSA_OAEP.    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_70_HW_RsaDec ( Crypto_JobType* job, Crypto_70_RsaKeyType* pRsaKey )
{
    Std_ReturnType                              retValue;
    Crypto_70_BignumRsa2048Type                 input;
    Crypto_70_BignumRsa2048Type                 output;
    uint8*                                      pMsg;
    uint32*                                     mLen;
    uint8                                       resRsa;
    const Crypto_JobPrimitiveInputOutputType*   pPrimitiveInOut;
 
    pPrimitiveInOut = &job->PrimitiveInputOutput;
 
    /* set input address */
    input.len = (uint16)pPrimitiveInOut->inputLength;
    input.p_adr = (uint8 QL_70_NEAR *)pPrimitiveInOut->inputPtr;
 
    /* set output address */
    output.p_adr = &s_DecryptedMsg[0];
    output.len = OAEP_DECODED_BUFF_LEN;
    pMsg = pPrimitiveInOut->outputPtr;
    mLen = pPrimitiveInOut->outputLengthPtr;
 
    /* RSA decryption */
    resRsa = R_RSA_ModExp( &input, &output, pRsaKey, &s_RSAWorkArea );
    if ( CRYPTO_70_RSA_OK == resRsa ) {
        /* OAEP decode */
        retValue = crypto_70_HW_oaepDecode( &s_DecryptedMsg[0], mLen, pMsg );
    } else if ( CRYPTO_70_RSA_CANCEL_RTN == resRsa ) {
        retValue = CRYPTO_E_JOB_CANCELED;
    } else {
        retValue = E_NOT_OK;
    }
 
    return ( retValue );
}
 
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_70_HW_oaepEncode                                      */
/* Param       : (in) mLen                                                    */
/*               (in) pMsg                                                    */
/*               (out) pEncodedMsg                                            */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function generates DB and encodes DB by EME_OAEP.       */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_70_HW_oaepEncode ( uint32 mLen, const uint8* pMsg, uint8* pEncodedMsg )
{
    Std_ReturnType  retValue;
    uint32          dbLen;
 
    /* generate DB */
    /*      +-------+----+---------+---+ */
    /* DB = | lHash | PS | X(0x01) | M | */
    /*      +-------+----+---------+---+ */
    crypto_70_HW_generateDB( pMsg, mLen, &s_OaepBuf.dataBlock[0], &dbLen );
 
    /* generate Seed */
    retValue = crypto_70_HW_generateRNG( (uint32)OAEP_SEED_LENGTH, &s_OaepBuf.seed[0] );
    if ( E_OK == retValue ) {
        /* masking */
        /* generate mask for DB from Seed */
        retValue = crypto_70_HW_MGF( (uint32)OAEP_SEED_LENGTH, &s_OaepBuf.seed[0],
                                     dbLen, &s_OaepBuf.dbMask[0] );
        if ( E_OK == retValue ) {
            /* get masked DB */
            /*      +----------------------+----------+ */
            /* EM = |       -Empty-        | maskedDB | */
            /*      +----------------------+----------+ */
            crypto_70_HW_processXOR( &s_OaepBuf.dataBlock[0], &s_OaepBuf.dbMask[0],
                                     &pEncodedMsg[MASKED_DB_INDEX], dbLen );
 
            /* generate mask for Seed from masked DB */
            retValue = crypto_70_HW_MGF( dbLen, &pEncodedMsg[MASKED_DB_INDEX],
                                         (uint32)OAEP_SEED_LENGTH, &s_OaepBuf.seedMask[0] );
            if ( E_OK == retValue ) {
                /* get masked Seed */
                /*      +---------+------------+----------+ */
                /* EM = | -Empty- | maskedSeed | maskedDB | */
                /*      +---------+------------+----------+ */
                crypto_70_HW_processXOR( &s_OaepBuf.seed[0], &s_OaepBuf.seedMask[0],
                                         &pEncodedMsg[MASKED_SEED_INDEX], (uint32)OAEP_SEED_LENGTH );
 
                /* packing Y(0x00) */
                /*      +---------+------------+----------+ */
                /* EM = | Y(0x00) | maskedSeed | maskedDB | */
                /*      +---------+------------+----------+ */
                pEncodedMsg[0] = 0x00U;
            }
        }
    }
   
    return ( retValue );
}
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_70_HW_oaepDecode                                      */
/* Param       : (in) pEncodedMsg                                             */
/*               (inout) mLen                                                 */
/*               (out) pMsg                                                   */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function decodes data that is encoded by EME_OAEP.      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_70_HW_oaepDecode ( const uint8* pEncodedMsg, uint32* mLen, uint8* pMsg )
{
    Std_ReturnType  retValue;
    uint8           dbIndex;
    uint8_least     cnt;
    bool_t          loopEnd = FALSE;
 
    /*      +---------+------------+----------+ */
    /* EM = | Y(0x00) | maskedSeed | maskedDB | */
    /*      +---------+------------+----------+ */
    /* check Y(0x00) */
    if ( 0x00U == pEncodedMsg[0] ) {
        /* generate mask for Seed from masked DB */
        retValue = crypto_70_HW_MGF( (uint32)OAEP_DATA_BLOCK_LENGTH, &pEncodedMsg[MASKED_DB_INDEX],
                                     (uint32)OAEP_SEED_LENGTH, &s_OaepBuf.seedMask[0] );
    } else {
        /* the first data is not Y(0x00) */
        return ( E_NOT_OK );
    }
 
    if ( E_OK == retValue ) {
        /* get Seed = maskedSeed XOR seedMask */
        crypto_70_HW_processXOR( &pEncodedMsg[MASKED_SEED_INDEX], &s_OaepBuf.seedMask[0],
                                 &s_OaepBuf.seed[0], (uint32)OAEP_SEED_LENGTH);
 
        /* generate mask for DB from seed */
        retValue = crypto_70_HW_MGF( (uint32)OAEP_SEED_LENGTH, &s_OaepBuf.seed[0],
                                     (uint32)OAEP_DATA_BLOCK_LENGTH, &s_OaepBuf.dbMask[0] );
    } else if ( CRYPTO_E_JOB_CANCELED == retValue ) {
        /* canceled */
        return ( CRYPTO_E_JOB_CANCELED );
    } else {
        /* failed to generate the mask for Seed */
        return ( E_NOT_OK );
    }
 
    if ( E_OK == retValue ) {
        /* get DB = maskedDB XOR dbMask */
        crypto_70_HW_processXOR( &pEncodedMsg[MASKED_DB_INDEX], &s_OaepBuf.dbMask[0],
                                 &s_OaepBuf.dataBlock[0], (uint32)OAEP_DATA_BLOCK_LENGTH );
 
        /*                +-------+----+---------+---+ */
        /* unpacking DB = | lHash | PS | X(0x01) | M | */
        /*                +-------+----+---------+---+ */
        /* check the lHash */
        for ( cnt=0U; cnt<CRYPTO_MGF_HASH_LENGTH; cnt++ ) {
            if ( s_crypto_70_hashZero_sha256[cnt] != s_OaepBuf.dataBlock[cnt] ) {
                retValue = E_NOT_OK;
                break; /* break the loop */
            }
        }
    } else if ( CRYPTO_E_JOB_CANCELED == retValue ) {
        /* canceled */
        return ( CRYPTO_E_JOB_CANCELED );
    } else {
        /* failed to generate the mask for DB */
        return ( E_NOT_OK );
    }
 
    if ( E_OK == retValue ) {
        /* find X(0x01) */
        for ( cnt=CRYPTO_MGF_HASH_LENGTH; cnt<OAEP_DATA_BLOCK_LENGTH; cnt++ ) {
            if ( 0x00U == s_OaepBuf.dataBlock[cnt] ) {
                /* padding character, continue */
            } else if ( 0x01U == s_OaepBuf.dataBlock[cnt] ) {
                /* find X(0x01), decoding succeeded */
                /* set message length */
                dbIndex = (uint8)( cnt + 1U );
                *mLen = OAEP_DATA_BLOCK_LENGTH - (uint32)dbIndex;
                /* unpacking message */
                crypto_memCopy( &s_OaepBuf.dataBlock[dbIndex], pMsg, *mLen );
                loopEnd = TRUE;
                retValue = E_OK;
            } else {
                /* not padding character and X, decoding failed */
                loopEnd = TRUE;
                retValue = E_NOT_OK;
            }
 
            /* when unpacked message or error detected */
            if ( TRUE == loopEnd ) {
                break;  /* break the loop */
            }
        }
    }
 
    return ( retValue );
}
 
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_70_HW_generateDB                                      */
/* Param       : (in) pMsg                                                    */
/*               (in) mLen                                                    */
/*               (out) pDB                                                    */
/*               (inout) dbLen                                                */
/* Return      : void                                                         */
/* Contents    : This function generates DB for RSA-OAEP.                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void crypto_70_HW_generateDB ( const uint8* pMsg, uint32 mLen, uint8* pDB, uint32* dbLen )
{
    uint16          dbIndex;
    uint8           psLen;
    uint8_least     psCnt;
 
    /* Concatenate lHash, PS, a single octet with hexadecimal value 0x01,         */
    /* and the message M to form a data block DB of length k - hLen - 1 octets as */
    /*      +-------+----+---------+---+ */
    /* DB = | lHash | PS | X(0x01) | M | */
    /*      +-------+----+---------+---+ */
 
    /* store the lHash */
    crypto_memCopy( &s_crypto_70_hashZero_sha256[0], pDB, HASH_SHA256_LENGTH );
 
    dbIndex = HASH_SHA256_LENGTH;
 
    /* generate PS */
    psLen = (uint8)( CRYPTO_70_RSA_LENGTH - mLen - ( HASH_SHA256_LENGTH * 2U ) - 2U );
    for ( psCnt=0U; psCnt<psLen; psCnt++ ) {
        pDB[dbIndex+psCnt] = 0x00U;
    }
    dbIndex += psLen;
 
    /* packing X(0x01) */
    pDB[dbIndex] = 0x01U;
    dbIndex++;
 
    /* packing message */
    crypto_memCopy( pMsg, &pDB[dbIndex], mLen );
    *dbLen = dbIndex + mLen;
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_70_HW_generateRNG                                     */
/* Param       : (in) length                                                  */
/*               (out) pRng                                                   */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_BUSY                                             */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function generates random number of arbitrary           */
/*               byte length.                                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_70_HW_generateRNG ( uint32 length, uint8* pRng )
{
    Std_ReturnType          retValue;
    Crypto_70_AesReturnType resRng = CRYPTO_70_HSM_NG;
    uint32                  index = 0U;
    uint32                  remainLength;
    uint8                   oRnd[RND_BYTE_LENGTH];
 
    remainLength = length;
 
    while ( 0U != remainLength ) {
        /* get random number */
        resRng = R_FUNC_RND( &oRnd[0] );
        if ( CRYPTO_70_HSM_OK != resRng ) {
            break;
        }
 
        if ( RND_BYTE_LENGTH <= remainLength ) {
            crypto_memCopy( &oRnd[0], &pRng[index], (uint32)RND_BYTE_LENGTH );
            index += RND_BYTE_LENGTH;
            remainLength -= RND_BYTE_LENGTH;
        } else {
            crypto_memCopy( &oRnd[0], &pRng[index], remainLength );
            remainLength = 0U;
        }
    }
 
 
    switch( resRng ) {
    case CRYPTO_70_HSM_OK:
        retValue = E_OK;
        break;
    case CRYPTO_70_HSM_BUSY:
        retValue = CRYPTO_E_BUSY;
        break;
    case CRYPTO_70_HSM_CANCELED:
        retValue = CRYPTO_E_JOB_CANCELED;
        break;
    case CRYPTO_70_HSM_NG:
    default:
        retValue = E_NOT_OK;
        break;
    }
 
    return ( retValue );
}
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_70_HW_MGF                                             */
/* Param       : (in) mgfDataLen                                              */
/*               (in) mgfData                                                 */
/*               (in) maskLen                                                 */
/*               (out) mask                                                   */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/* Contents    : This function will generate mask for RSA-OAEP.               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_70_HW_MGF ( uint32 mgfDataLen, const uint8* mgfData, uint32 maskLen, uint8* mask )
{
    uint32_least                cnt;
    uint32                      numBlock;
    uint32                      mskIndex = 0U;
    uint32                      copyRemainLen;
    uint8*                      outPtr;
    uint8                       resHash;
 
    /* packing the hash values T_i of mgfData and cnt                */
    /* +-------------------+-------------------+-------------------+ */
    /* | T_0 = Hash( M_0 ) | T_1 = Hash( M_1 ) | T_2 = Hash( M_2 ) | */
    /* +-------------------+-------------------+-------------------+ */
    /* |                                            |                */
    /* +--------------------------------------------+                */
    /* |                    mask                    |                */
    /* +--------------------------------------------+                */
 
    /* calculate block size */
    numBlock = ( ( maskLen + CRYPTO_MGF_HASH_LENGTH ) - 1U ) / CRYPTO_MGF_HASH_LENGTH;
 
    crypto_memCopy( mgfData, &s_MgfBuf.M_i[0], mgfDataLen );
 
    for ( cnt=0U; cnt<numBlock; cnt++ ) {
        /*               +---------+-----+ */
        /* packing M_i = | mgfData | cnt | */
        /*               +---------+-----+ */
        s_MgfBuf.M_i[mgfDataLen]    = (uint8)( ( cnt & 0xFF000000UL ) >> 24U );
        s_MgfBuf.M_i[mgfDataLen+1U] = (uint8)( ( cnt & 0x00FF0000UL ) >> 16U );
        s_MgfBuf.M_i[mgfDataLen+2U] = (uint8)( ( cnt & 0x0000FF00UL ) >> 8U );
        s_MgfBuf.M_i[mgfDataLen+3U] = (uint8)  ( cnt & 0x000000FFUL );
 
        /* T_i = Hash( M_i ) */
        copyRemainLen = maskLen - mskIndex;
        if ( (uint32)CRYPTO_MGF_HASH_LENGTH <= copyRemainLen ) {
            outPtr = &mask[mskIndex];
        } else {
            outPtr = &s_MgfBuf.T_i[0];
        }
 
        if ( TRUE == Crypto_CancelReq ) {
            return ( CRYPTO_E_JOB_CANCELED );
        }
 
        resHash = R_SHA_256HashDigest( &s_MgfBuf.M_i[0], outPtr, (uint16)(mgfDataLen+4U),
                                       (CRYPTO_70_SHA_CTRL_INIT | CRYPTO_70_SHA_CTRL_FINISH), &s_ShaWork);
        if ( CRYPTO_70_SHA_OK != resHash ) {
            return ( E_NOT_OK );
        }
 
        if ( (uint32)CRYPTO_MGF_HASH_LENGTH <= copyRemainLen ) {
            mskIndex += (uint32)CRYPTO_MGF_HASH_LENGTH;
        } else {
            crypto_memCopy( &s_MgfBuf.T_i[0], &mask[mskIndex], copyRemainLen );
            mskIndex = maskLen;
        }
    }
 
    return ( E_OK );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_70_HW_processXOR                                      */
/* Param       : (in) arrayA                                                  */
/*               (in) arrayB                                                  */
/*               (out) resArray                                               */
/*               (in) length                                                  */
/* Return      : void                                                         */
/* Contents    : This function stores XOR of arrayA and arrayB in resArray.   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void crypto_70_HW_processXOR ( const uint8* arrayA, const uint8* arrayB, uint8* resArray, uint32 length )
{
    uint32_least    dataIndex;
 
    /* calculate XOR */
    for ( dataIndex=0UL; dataIndex<length; dataIndex++ ) {
        resArray[dataIndex] = arrayA[dataIndex] ^ arrayB[dataIndex];
    }
}
#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
 
 
/* EOF Crypto_70_HW.c *********************************************************/