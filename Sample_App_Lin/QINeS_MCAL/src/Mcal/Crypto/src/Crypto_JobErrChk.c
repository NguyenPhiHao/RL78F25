/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_JobErrChk.c                                           */
/* Version     : v1.00.00                                                     */
/* Contents    : Key management source file for Crypto driver                 */
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
#include "Crypto_KeyManagement.h"
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
#include "Det.h"
#endif /* CRYPTO_DEV_ERROR_DETECT != FALSE */

/*----------------------------------------------------------------------------*/
/* source file version information                                            */
/*----------------------------------------------------------------------------*/
/*[SWS_BSW_00059] Version Check parameters. */
#define CRYPTO_70_VENDOR_ID_JOBERRCHK_C                      ( 70U )
#define CRYPTO_70_MODULE_ID_JOBERRCHK_C                      ( 114U )
#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_JOBERRCHK_C       ( 22U )
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_JOBERRCHK_C       ( 11U )
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_JOBERRCHK_C    ( 0U )
#define CRYPTO_70_SW_MAJOR_VERSION_JOBERRCHK_C               ( 1U )
#define CRYPTO_70_SW_MINOR_VERSION_JOBERRCHK_C               ( 0U )
#define CRYPTO_70_SW_PATCH_VERSION_JOBERRCHK_C               ( 0U )

/*----------------------------------------------------------------------------*/
/* source file version checks                                                 */
/*----------------------------------------------------------------------------*/
/* Check if current file and Crypto_KeyManagement.h file is of the same Vendor ID */
#if ( CRYPTO_70_VENDOR_ID_JOBERRCHK_C != CRYPTO_VENDOR_ID )
    #error "Vendor ID of Crypto_JobErrChk.c and Crypto_KeyManagement.h is different"
#endif
/* Check if current file and Crypto_KeyManagement.h file is of the same Module ID */
#if ( CRYPTO_70_MODULE_ID_JOBERRCHK_C != CRYPTO_MODULE_ID )
    #error "Module ID of Crypto_KeyManagement.c and Crypto.h is different"
#endif
/* Check if current file and Crypto_KeyManagement.h file are of the same Autosar version */
#if ( ( CRYPTO_70_AR_RELEASE_MAJOR_VERSION_JOBERRCHK_C    != CRYPTO_AR_RELEASE_MAJOR_VERSION ) || \
      ( CRYPTO_70_AR_RELEASE_MINOR_VERSION_JOBERRCHK_C    != CRYPTO_AR_RELEASE_MINOR_VERSION ) || \
      ( CRYPTO_70_AR_RELEASE_REVISION_VERSION_JOBERRCHK_C != CRYPTO_AR_RELEASE_REVISION_VERSION ) )
    #error "AutoSar Version Numbers of Crypto_KeyManagement.c and Crypto_KeyManagement.h are different"
#endif
/* Check if current file and Crypto_KeyManagement.h file are of the same Software version */
#if ( ( CRYPTO_70_SW_MAJOR_VERSION_JOBERRCHK_C != CRYPTO_SW_MAJOR_VERSION ) || \
      ( CRYPTO_70_SW_MINOR_VERSION_JOBERRCHK_C != CRYPTO_SW_MINOR_VERSION ) || \
      ( CRYPTO_70_SW_PATCH_VERSION_JOBERRCHK_C != CRYPTO_SW_PATCH_VERSION ) )
    #error "Software Version Numbers of Crypto_KeyManagement.c and Crypto_KeyManagement.h are different"
#endif

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
#if ( TRUE == CRYPTO_70_HASH_ENABLE )
static Std_ReturnType crypto_hashErrorCheck( const Crypto_JobType* job );
#endif  /* #if ( TRUE == CRYPTO_70_HASH_ENABLE ) */

#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
static Std_ReturnType crypto_macGenErrorCheck( const Crypto_JobType* job );

static Std_ReturnType crypto_macVerifyErrorCheck( const Crypto_JobType* job );

static Std_ReturnType crypto_encryptErrorCheck( const Crypto_JobType* job );
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */

#if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) || ( TRUE == CRYPTO_70_RSA_ENABLE ) )
static Std_ReturnType crypto_decryptErrorCheck( const Crypto_JobType* job );
#endif  /* #if ( ( TRUE == CRYPTO_70_ARSEA_ENABLE ) || ( TRUE == CRYPTO_70_RSA_ENABLE ) ) */

#if ( TRUE == CRYPTO_70_RSA_ENABLE )
static Std_ReturnType crypto_signGenErrorCheck( const Crypto_JobType* job );

static Std_ReturnType crypto_signVerifyErrorCheck( const Crypto_JobType* job );
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */

#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
static Std_ReturnType crypto_rndGenErrorCheck( Crypto_JobType* job );

static Std_ReturnType crypto_rndSeedErrorCheck( Crypto_JobType* job );
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */

static Std_ReturnType crypto_keySetErrorCheck( Crypto_JobType* job );

static Std_ReturnType crypto_customErrorCheck( const Crypto_JobType* job );

static Std_ReturnType crypto_unsupportedServiceErrorCheck( void );

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_jobErrorCheck                                         */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about corresponding job service.  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType crypto_jobErrorCheck( Crypto_JobType* job )
{
    Std_ReturnType                  retValue;
    const Crypto_ServiceInfoType    jobService = job->jobPrimitiveInfo->primitiveInfo->service;
 
    /* check error about each service */
    switch ( jobService ) {
#if ( TRUE == CRYPTO_70_HASH_ENABLE )
    case CRYPTO_HASH:
        retValue = crypto_hashErrorCheck( job );
        break;
#endif  /* #if ( TRUE == CRYPTO_70_HASH_ENABLE ) */
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    case CRYPTO_MACGENERATE:
        retValue = crypto_macGenErrorCheck( job );
        break;
    case CRYPTO_MACVERIFY:
        retValue = crypto_macVerifyErrorCheck( job );
        break;
    case CRYPTO_ENCRYPT:
        retValue = crypto_encryptErrorCheck( job );
        break;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
#if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) || ( TRUE == CRYPTO_70_RSA_ENABLE ) )
    case CRYPTO_DECRYPT:
        retValue = crypto_decryptErrorCheck( job );
        break;
#endif  /* #if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) || ( TRUE == CRYPTO_70_RSA_ENABLE ) ) */
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
    case CRYPTO_SIGNATUREGENERATE:
        retValue = crypto_signGenErrorCheck( job );
        break;
    case CRYPTO_SIGNATUREVERIFY:
        retValue = crypto_signVerifyErrorCheck( job );
        break;
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    case CRYPTO_RANDOMGENERATE:
        retValue = crypto_rndGenErrorCheck( job );
        break;
    case CRYPTO_RANDOMSEED:
        retValue = crypto_rndSeedErrorCheck( job );
        break;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
    case CRYPTO_KEYSETVALID:
    case CRYPTO_KEYSETINVALID:
        retValue = crypto_keySetErrorCheck( job );
        break;
    case CRYPTO_CUSTOM_SERVICE:
        retValue = crypto_customErrorCheck( job );
        break;
    case CRYPTO_AEADENCRYPT:
    case CRYPTO_AEADDECRYPT:
    case CRYPTO_KEYGENERATE:
    case CRYPTO_KEYDERIVE:
    case CRYPTO_KEYEXCHANGECALCPUBVAL:
    case CRYPTO_KEYEXCHANGECALCSECRET:
    default:
        /* unsupported services */
        retValue = crypto_unsupportedServiceErrorCheck();
        break;
    }
 
    return ( retValue );
}

#if ( TRUE == CRYPTO_70_HASH_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_hashErrorCheck                                        */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about Hash service.               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_hashErrorCheck( const Crypto_JobType* job )
{
    const Crypto_JobPrimitiveInputOutputType*   pPrimitiveInOut;
 
    pPrimitiveInOut = &job->PrimitiveInputOutput;
 
    /* algorithm check */
    if ( CRYPTO_ALGOFAM_SHA2_256 != job->jobPrimitiveInfo->primitiveInfo->algorithm.family ) {
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* inputPtr check */
    if ( CRYPTO_OPERATIONMODE_UPDATE == (CRYPTO_OPERATIONMODE_UPDATE & pPrimitiveInOut->mode) ) {
        if ( (uint8*)NULL_PTR == pPrimitiveInOut->inputPtr ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    /* outputPtr/outputLengthPtr check */
    if ( CRYPTO_OPERATIONMODE_FINISH == (CRYPTO_OPERATIONMODE_FINISH & pPrimitiveInOut->mode) ) {
        if ( ( NULL_PTR == pPrimitiveInOut->outputPtr )
          || ( NULL_PTR == pPrimitiveInOut->outputLengthPtr ) ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        if ( CRYPTO_70_HASH_LENGTH > *(pPrimitiveInOut->outputLengthPtr) ) {
            /* [SWS_Crypto_00195] : If a Crypto Driver API is called and any buffer addressed during the operation is
             * too small, then the operation shall not be performed. If development error detection for the Crypto Driver
             * is enabled, then the API function shall report CRYPTO_E_SMALL_BUFFER to the DET, else return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_SMALL_BUFFER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    return ( E_OK );
}
#endif  /* #if ( TRUE == CRYPTO_70_HASH_ENABLE ) */
 
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_macGenErrorCheck                                      */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about Mac generation service.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_macGenErrorCheck( const Crypto_JobType* job )
{
    Std_ReturnType                              retValue;
    const Crypto_AlgorithmInfoType*             pAlgoInfo;
    const Crypto_JobPrimitiveInputOutputType*   pPrimitiveInOut;
    uint32_least                                cryptoKeyIndex;
 
    pAlgoInfo = &job->jobPrimitiveInfo->primitiveInfo->algorithm;
    pPrimitiveInOut = &job->PrimitiveInputOutput;
 
    /* cryptoKeyId check */
    /* [SWS_Crypto_00072] : All crypto services listed in Crypto_ServiceInfoType except of CRYPTO_HASH, and CRYPTO_RANDOMGENERATE
     * require a key represented as a key identifier.*/
    retValue = crypto_chkCryptoKeyId( job->cryptoKeyId, &cryptoKeyIndex );
    if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00217] : The crypto Driver shall check if job->cryptoKeyId and, if applicable, job->targetCryptoKeyId
         * are in range, before it executes a job. If the check fails, the function Crypto_ProcessJob() shall report CRYPTO_E_PARAM_HANDLE
         * to DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* key status check */
    if ( CRYPTO_KEYSTATUS_INVALID == (Crypto_KeyStatusType)Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus ) {
        /* the key is invalid */
        return ( CRYPTO_E_KEY_NOT_VALID );
    }
 
    /* algorithm family check */
    if ( CRYPTO_ALGOFAM_AES != pAlgoInfo->family ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* algorithm mode check */
    if ( CRYPTO_ALGOMODE_CMAC != pAlgoInfo->mode ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* keylength check */
    if ( ( CRYPTO_70_128BIT != pAlgoInfo->keyLength )
         && ( CRYPTO_70_192BIT != pAlgoInfo->keyLength )
         && ( CRYPTO_70_256BIT != pAlgoInfo->keyLength ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* inputPtr check */
    if (  CRYPTO_OPERATIONMODE_UPDATE == (CRYPTO_OPERATIONMODE_UPDATE & pPrimitiveInOut->mode)  ) {
        if ( (uint8*)NULL_PTR == pPrimitiveInOut->inputPtr ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    /* outputPtr/outputLengthPtr check */
    if ( CRYPTO_OPERATIONMODE_FINISH == (CRYPTO_OPERATIONMODE_FINISH & pPrimitiveInOut->mode) ) {
        if ( ( NULL_PTR == pPrimitiveInOut->outputPtr ) || ( NULL_PTR == pPrimitiveInOut->outputLengthPtr ) ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
   
        if ( CRYPTO_70_AES_BLOCK_SIZE > *(pPrimitiveInOut->outputLengthPtr) ) {
            /* [SWS_Crypto_00195] : If a Crypto Driver API is called and any buffer addressed during the operation is
             * too small, then the operation shall not be performed. If development error detection for the Crypto Driver
             * is enabled, then the API function shall report CRYPTO_E_SMALL_BUFFER to the DET, else return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_SMALL_BUFFER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    return ( E_OK );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_macVerifyErrorCheck                                   */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about Mac verification service.   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_macVerifyErrorCheck( const Crypto_JobType* job )
{
    Std_ReturnType                              retValue;
    const Crypto_AlgorithmInfoType*             pAlgoInfo;
    const Crypto_JobPrimitiveInputOutputType*   pPrimitiveInOut;
    uint32_least                                cryptoKeyIndex;
 
    pAlgoInfo = &job->jobPrimitiveInfo->primitiveInfo->algorithm;
    pPrimitiveInOut = &job->PrimitiveInputOutput;
 
    /* cryptoKeyId check */
    /* [SWS_Crypto_00072] : All crypto services listed in Crypto_ServiceInfoType except of CRYPTO_HASH, and CRYPTO_RANDOMGENERATE
     * require a key represented as a key identifier.*/
    retValue = crypto_chkCryptoKeyId( job->cryptoKeyId, &cryptoKeyIndex );
    if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00217] : The crypto Driver shall check if job->cryptoKeyId and, if applicable, job->targetCryptoKeyId
         * are in range, before it executes a job. If the check fails, the function Crypto_ProcessJob() shall report CRYPTO_E_PARAM_HANDLE
         * to DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* key status check */
    if ( CRYPTO_KEYSTATUS_INVALID == (Crypto_KeyStatusType)Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus ) {
        retValue = CRYPTO_E_KEY_NOT_VALID;
    }
 
    /* algorithm family check */
    if ( CRYPTO_ALGOFAM_AES != pAlgoInfo->family ) {
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* algorithm mode check */
    if ( CRYPTO_ALGOMODE_CMAC != pAlgoInfo->mode ) {
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* keylength check */
    if ( ( CRYPTO_70_128BIT != pAlgoInfo->keyLength )
          && ( CRYPTO_70_192BIT != pAlgoInfo->keyLength )
          && ( CRYPTO_70_256BIT != pAlgoInfo->keyLength ) ) {
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* inputPtr check */
    if ( CRYPTO_OPERATIONMODE_UPDATE == (CRYPTO_OPERATIONMODE_UPDATE & pPrimitiveInOut->mode) ) {
        if ( (uint8*)NULL_PTR == pPrimitiveInOut->inputPtr ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    /* secondaryInputPtr/secondaryInputLength/verifyPtr check */
    if ( ( CRYPTO_OPERATIONMODE_FINISH == (CRYPTO_OPERATIONMODE_FINISH & pPrimitiveInOut->mode) ) ) {
        if ( ( (uint8*)NULL_PTR == pPrimitiveInOut->secondaryInputPtr )
          || ( (Crypto_VerifyResultType*)NULL_PTR == pPrimitiveInOut->verifyPtr ) ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        if ( 0U == pPrimitiveInOut->secondaryInputLength ) {
            /* [SWS_Crypto_00142] : If a length information is required for processing a service request,
             * either as variable or pointer, but the indicated length value is zero, and if development error
             * detection for the Crypto Driver is enabled, the Crypto_ProcessJob() function report CRYPTO_E_PARAM_VALUE
             * to the DET and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_VALUE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_encryptErrorCheck                                     */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about Encryption service.         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_encryptErrorCheck( const Crypto_JobType* job )
{
    Std_ReturnType                              retValue;
    const Crypto_AlgorithmInfoType*             pAlgoInfo;
    const Crypto_JobPrimitiveInputOutputType*   pPrimitiveInOut;
    uint32_least                                cryptoKeyIndex;
 
    pAlgoInfo = &job->jobPrimitiveInfo->primitiveInfo->algorithm;
    pPrimitiveInOut = &job->PrimitiveInputOutput;
 
    /* cryptoKeyId check */
    /* [SWS_Crypto_00072] : All crypto services listed in Crypto_ServiceInfoType except of CRYPTO_HASH, and CRYPTO_RANDOMGENERATE
     * require a key represented as a key identifier.*/
    retValue = crypto_chkCryptoKeyId( job->cryptoKeyId, &cryptoKeyIndex );
    if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00217] : The crypto Driver shall check if job->cryptoKeyId and, if applicable, job->targetCryptoKeyId
         * are in range, before it executes a job. If the check fails, the function Crypto_ProcessJob() shall report CRYPTO_E_PARAM_HANDLE
         * to DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* key status check */
    if ( CRYPTO_KEYSTATUS_INVALID == (Crypto_KeyStatusType)Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus ) {
        /* the key is invalid */
        return ( CRYPTO_E_KEY_NOT_VALID );
    }
 
    if ( CRYPTO_ALGOFAM_AES == pAlgoInfo->family ) {
        /* AES parameter check */
        /* algorithm mode check */
        if ( ( CRYPTO_ALGOMODE_ECB != pAlgoInfo->mode ) && ( CRYPTO_ALGOMODE_CBC != pAlgoInfo->mode ) ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
 
        /* keylength check */
        if ( ( CRYPTO_70_128BIT != pAlgoInfo->keyLength )
          && ( CRYPTO_70_192BIT != pAlgoInfo->keyLength )
          && ( CRYPTO_70_256BIT != pAlgoInfo->keyLength ) ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
    else if ( CRYPTO_ALGOFAM_RSA == pAlgoInfo->family ) {
        /* rsa parameter check */
        /* algorithm mode check */
        if ( CRYPTO_ALGOMODE_RSAES_OAEP != pAlgoInfo->mode ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* secondary algorithm check */
        if ( CRYPTO_ALGOFAM_SHA2_256 != pAlgoInfo->secondaryFamily ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* keylength check */
        if ( CRYPTO_70_RSA_BIT_LEN != pAlgoInfo->keyLength ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
    else {
        /* unsupported algorithm */
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* check input settings */
    if ( CRYPTO_OPERATIONMODE_UPDATE == ( CRYPTO_OPERATIONMODE_UPDATE & pPrimitiveInOut->mode ) ) {
        /* NULL_PTR check */
        if ( ( (uint8*)NULL_PTR == pPrimitiveInOut->inputPtr )
          || ( (uint8*)NULL_PTR == pPrimitiveInOut->outputPtr )
          || ( (uint32*)NULL_PTR == pPrimitiveInOut->outputLengthPtr ) ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* inputLength check */
        if ( 0U == pPrimitiveInOut->inputLength ) {
            /* [SWS_Crypto_00142] : If a length information is required for processing a service request,
             * either as variable or pointer, but the indicated length value is zero, and if development error
             * detection for the Crypto Driver is enabled, the Crypto_ProcessJob() function report CRYPTO_E_PARAM_VALUE
             * to the DET and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_VALUE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        if ( pPrimitiveInOut->inputLength > *(pPrimitiveInOut->outputLengthPtr) ) {
            /* [SWS_Crypto_00195] : If a Crypto Driver API is called and any buffer addressed during the operation is
             * too small, then the operation shall not be performed. If development error detection for the Crypto Driver
             * is enabled, then the API function shall report CRYPTO_E_SMALL_BUFFER to the DET, else return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_SMALL_BUFFER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    /* check output settings */
    if ( CRYPTO_OPERATIONMODE_FINISH == ( CRYPTO_OPERATIONMODE_FINISH & pPrimitiveInOut->mode ) ) {
        /* NULL_PTR check */
        if ( ( NULL_PTR == pPrimitiveInOut->outputPtr )
          || ( NULL_PTR == pPrimitiveInOut->outputLengthPtr ) ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    return ( E_OK );
}
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
#if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) || ( TRUE == CRYPTO_70_RSA_ENABLE ) )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_decryptErrorCheck                                     */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about Decryption service.         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_decryptErrorCheck( const Crypto_JobType* job )
{
    Std_ReturnType                              retValue;
    const Crypto_AlgorithmInfoType*             pAlgoInfo;
    const Crypto_JobPrimitiveInputOutputType*   pPrimitiveInOut;
    uint32_least                                cryptoKeyIndex;
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    uint8                                       lenCheck = 0U;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
    pAlgoInfo = &job->jobPrimitiveInfo->primitiveInfo->algorithm;
    pPrimitiveInOut = &job->PrimitiveInputOutput;
 
    /* cryptoKeyId check */
    /* [SWS_Crypto_00072] : All crypto services listed in Crypto_ServiceInfoType except of CRYPTO_HASH, and CRYPTO_RANDOMGENERATE
     * require a key represented as a key identifier.*/
    retValue = crypto_chkCryptoKeyId( job->cryptoKeyId, &cryptoKeyIndex );
    if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00217] : The crypto Driver shall check if job->cryptoKeyId and, if applicable, job->targetCryptoKeyId
         * are in range, before it executes a job. If the check fails, the function Crypto_ProcessJob() shall report CRYPTO_E_PARAM_HANDLE
         * to DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* key status check */
    if ( CRYPTO_KEYSTATUS_INVALID == (Crypto_KeyStatusType)Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus ) {
        /* the key is invalid */
        return ( CRYPTO_E_KEY_NOT_VALID );
    }
 
#if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) && ( TRUE == CRYPTO_70_RSA_ENABLE ) )
    if ( CRYPTO_ALGOFAM_AES == pAlgoInfo->family ) {
        /* AES parameter check */
        /* algorithm mode check */
        if ( ( CRYPTO_ALGOMODE_ECB != pAlgoInfo->mode ) && ( CRYPTO_ALGOMODE_CBC != pAlgoInfo->mode ) ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* keylength check */
        if ( ( CRYPTO_70_128BIT != pAlgoInfo->keyLength )
          && ( CRYPTO_70_192BIT != pAlgoInfo->keyLength )
          && ( CRYPTO_70_256BIT != pAlgoInfo->keyLength ) ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* data length check */
        lenCheck = (uint8)( pPrimitiveInOut->inputLength % CRYPTO_70_AES_BLOCK_SIZE );
    } else if ( CRYPTO_ALGOFAM_RSA == pAlgoInfo->family ) {
        /* rsa parameter check */
        /* algorithm mode check */
        if ( CRYPTO_ALGOMODE_RSAES_OAEP != pAlgoInfo->mode ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* secondary algorithm check */
        if ( CRYPTO_ALGOFAM_SHA2_256 != pAlgoInfo->secondaryFamily ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* keylength check */
        if ( CRYPTO_70_RSA_BIT_LEN != pAlgoInfo->keyLength ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    } else {
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
#elif ( TRUE == CRYPTO_70_AESEA_ENABLE )
    /* AES parameter check */
    /* algorithm mode check */
    if ( ( CRYPTO_ALGOMODE_ECB != pAlgoInfo->mode ) && ( CRYPTO_ALGOMODE_CBC != pAlgoInfo->mode ) ) {
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* keylength check */
    if ( ( CRYPTO_70_128BIT != pAlgoInfo->keyLength )
      && ( CRYPTO_70_192BIT != pAlgoInfo->keyLength )
      && ( CRYPTO_70_256BIT != pAlgoInfo->keyLength ) ) {
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* data length check */
    lenCheck = (uint8)( pPrimitiveInOut->inputLength % CRYPTO_70_AES_BLOCK_SIZE );
#elif ( TRUE == CRYPTO_70_RSA_ENABLE )
    /* rsa parameter check */
    /* algorithm mode check */
    if ( CRYPTO_ALGOMODE_RSAES_OAEP != pAlgoInfo->mode ) {
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* secondary algorithm check */
    if ( CRYPTO_ALGOFAM_SHA2_256 != pAlgoInfo->secondaryFamily ) {
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* keylength check */
    if ( CRYPTO_70_RSA_BIT_LEN != pAlgoInfo->keyLength ) {
        /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
         * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
         * Object and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
#else
    /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
     * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
     * Object and if development error detection for the Crypto Driver is enabled, the function
     * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
    ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                 ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
    return ( E_NOT_OK );
#endif  /* #if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) && ( TRUE == CRYPTO_70_RSA_ENABLE ) )*/
 
#if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) || ( TRUE == CRYPTO_70_RSA_ENABLE ) )
    /* check input settings */
    if ( CRYPTO_OPERATIONMODE_UPDATE == ( CRYPTO_OPERATIONMODE_UPDATE & pPrimitiveInOut->mode ) ) {
        /* NULL_PTR check */
        if ( ( (uint8*)NULL_PTR == pPrimitiveInOut->inputPtr )
          || ( (uint8*)NULL_PTR == pPrimitiveInOut->outputPtr )
          || ( (uint32*)NULL_PTR == pPrimitiveInOut->outputLengthPtr ) ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* inputLength check */
        if ( 0U == pPrimitiveInOut->inputLength ) {
            /* [SWS_Crypto_00142] : If a length information is required for processing a service request,
             * either as variable or pointer, but the indicated length value is zero, and if development error
             * detection for the Crypto Driver is enabled, the Crypto_ProcessJob() function report CRYPTO_E_PARAM_VALUE
             * to the DET and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_VALUE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
        /* inputLength check for AES decryption */
        if ( ( CRYPTO_ALGOFAM_AES == pAlgoInfo->family ) && ( 0U != lenCheck ) ) {
            /* input data length is not a multiple of AES block size */
            return ( E_NOT_OK );
        }
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
        if ( pPrimitiveInOut->inputLength > *(pPrimitiveInOut->outputLengthPtr) ) {
            /* [SWS_Crypto_00195] : If a Crypto Driver API is called and any buffer addressed during the operation is
             * too small, then the operation shall not be performed. If development error detection for the Crypto Driver
             * is enabled, then the API function shall report CRYPTO_E_SMALL_BUFFER to the DET, else return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_SMALL_BUFFER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    /* check output settings */
    if ( CRYPTO_OPERATIONMODE_FINISH == ( CRYPTO_OPERATIONMODE_FINISH & pPrimitiveInOut->mode ) ) {
        /* NULL_PTR check */
        if ( ( NULL_PTR == pPrimitiveInOut->outputPtr )
          || ( NULL_PTR == pPrimitiveInOut->outputLengthPtr ) ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    return ( E_OK );
#endif  /* #if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) || ( TRUE == CRYPTO_70_RSA_ENABLE ) ) */
}
#endif  /* #if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) || ( TRUE == CRYPTO_70_RSA_ENABLE ) ) */
 
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_signGenErrorCheck                                     */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about Signature generation        */
/*               service.                                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_signGenErrorCheck( const Crypto_JobType* job )
{
    Std_ReturnType                              retValue;
    const Crypto_AlgorithmInfoType*             pAlgoInfo;
    const Crypto_JobPrimitiveInputOutputType*   pPrimitiveInOut;
    uint32_least                                cryptoKeyIndex;
 
    pAlgoInfo = &job->jobPrimitiveInfo->primitiveInfo->algorithm;
    pPrimitiveInOut = &job->PrimitiveInputOutput;
 
    /* cryptoKeyId check */
    /* [SWS_Crypto_00072] : All crypto services listed in Crypto_ServiceInfoType except of CRYPTO_HASH, and CRYPTO_RANDOMGENERATE
     * require a key represented as a key identifier.*/
    retValue = crypto_chkCryptoKeyId( job->cryptoKeyId, &cryptoKeyIndex );
    if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00217] : The crypto Driver shall check if job->cryptoKeyId and, if applicable, job->targetCryptoKeyId
         * are in range, before it executes a job. If the check fails, the function Crypto_ProcessJob() shall report CRYPTO_E_PARAM_HANDLE
         * to DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* key status check */
    if ( CRYPTO_KEYSTATUS_INVALID == (Crypto_KeyStatusType)Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus ) {
        /* the key is invalid */
        return ( CRYPTO_E_KEY_NOT_VALID );
    }
 
 
 
    /* algorithm family check */
    if ( CRYPTO_ALGOFAM_RSA == pAlgoInfo->family ) {
        /* algorithm mode check */
        if ( CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 != pAlgoInfo->mode ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* secondary algorithm check */
        if ( CRYPTO_ALGOFAM_SHA2_256 != pAlgoInfo->secondaryFamily ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* keyLength check */
        if ( CRYPTO_70_RSA_BIT_LEN != pAlgoInfo->keyLength ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    if ( CRYPTO_OPERATIONMODE_UPDATE == (CRYPTO_OPERATIONMODE_UPDATE & pPrimitiveInOut->mode) ) {
        /* NULL_PTR check */
        if ( (uint8*)NULL_PTR == pPrimitiveInOut->inputPtr ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    /* outputPtr/outputLengthPtr check */
    if ( ( CRYPTO_OPERATIONMODE_FINISH == ( CRYPTO_OPERATIONMODE_FINISH & pPrimitiveInOut->mode) ) ) {
        /* NULL_PTR check */
        if ( ( NULL_PTR == pPrimitiveInOut->outputPtr )
          || ( NULL_PTR == pPrimitiveInOut->outputLengthPtr ) ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        if ( CRYPTO_70_RSA_LENGTH > *(pPrimitiveInOut->outputLengthPtr) ) {
            /* [SWS_Crypto_00195] : If a Crypto Driver API is called and any buffer addressed during the operation is
             * too small, then the operation shall not be performed. If development error detection for the Crypto Driver
             * is enabled, then the API function shall report CRYPTO_E_SMALL_BUFFER to the DET, else return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                        ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_SMALL_BUFFER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    return ( E_OK );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_signVerifyErrorCheck                                  */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about Signature verification      */
/*               service.                                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_signVerifyErrorCheck( const Crypto_JobType* job )
{
    Std_ReturnType                              retValue;
    const Crypto_AlgorithmInfoType*             pAlgoInfo;
    const Crypto_JobPrimitiveInputOutputType*   pPrimitiveInOut;
    uint32_least                                cryptoKeyIndex;
 
    pAlgoInfo = &job->jobPrimitiveInfo->primitiveInfo->algorithm;
    pPrimitiveInOut = &job->PrimitiveInputOutput;
 
    /* cryptoKeyId check */
    /* [SWS_Crypto_00072] : All crypto services listed in Crypto_ServiceInfoType except of CRYPTO_HASH, and CRYPTO_RANDOMGENERATE
     * require a key represented as a key identifier.*/
    retValue = crypto_chkCryptoKeyId( job->cryptoKeyId, &cryptoKeyIndex );
    if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00217] : The crypto Driver shall check if job->cryptoKeyId and, if applicable, job->targetCryptoKeyId
         * are in range, before it executes a job. If the check fails, the function Crypto_ProcessJob() shall report CRYPTO_E_PARAM_HANDLE
         * to DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                    ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* key status check */
    if ( CRYPTO_KEYSTATUS_INVALID == (Crypto_KeyStatusType)Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus ) {
        /* the key is invalid */
        return ( CRYPTO_E_KEY_NOT_VALID );
    }
 
    /* algorithm family check */
    if ( CRYPTO_ALGOFAM_RSA == pAlgoInfo->family ) {
        /* algorithm mode check */
        if ( CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 != pAlgoInfo->mode ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                        ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* secondary algorithm check */
        if ( CRYPTO_ALGOFAM_SHA2_256 != pAlgoInfo->secondaryFamily ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                        ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        /* keyLength check */
        if ( CRYPTO_70_RSA_BIT_LEN != pAlgoInfo->keyLength ) {
            /* [SWS_Crypto_00067] : If the parameter job->jobPrimitiveInfo->primitiveInfo->algorithm
             * (with its variation in family, keyLength and mode) is not supported by the Crypto Driver
             * Object and if development error detection for the Crypto Driver is enabled, the function
             * Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                        ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    if ( CRYPTO_OPERATIONMODE_FINISH == ( CRYPTO_OPERATIONMODE_FINISH & pPrimitiveInOut->mode ) ) {
        /* NULL_PTR check */
        if ( ( (uint8*)NULL_PTR == pPrimitiveInOut->secondaryInputPtr )
          || ( (Crypto_VerifyResultType*)NULL_PTR == pPrimitiveInOut->verifyPtr ) ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
 
        if ( 0U == pPrimitiveInOut->secondaryInputLength ) {
            /* [SWS_Crypto_00142] : If a length information is required for processing a service request,
             * either as variable or pointer, but the indicated length value is zero, and if development error
             * detection for the Crypto Driver is enabled, the Crypto_ProcessJob() function report CRYPTO_E_PARAM_VALUE
             * to the DET and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_VALUE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return ( E_NOT_OK );
        }
    }
 
    return ( E_OK );
}
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
 
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_rndGenErrorCheck                                      */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about Random generation service.  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_rndGenErrorCheck( Crypto_JobType* job )
{
    Std_ReturnType                      retValue;
    Crypto_JobPrimitiveInputOutputType* pPrimitiveInOut;
 
    pPrimitiveInOut = &job->PrimitiveInputOutput;
 
    /* random generator initialization check */
    if ( CRYPTO_70_RNG_UNINIT == Crypto_RngStatus ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00057] : If the module is not initialized and if default error
         * detection for the Crypto Driver is enabled, the function Crypto_ProcessJob
         * shall report CRYPTO_E_UNINIT to the DET and return E_NOT_OK. */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                    ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else {
        /* outputPtr/outputLengthPtr check */
        if ( ( NULL_PTR == pPrimitiveInOut->outputPtr )
          || ( NULL_PTR == pPrimitiveInOut->outputLengthPtr ) ) {
            /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
             * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
             * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                        ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            retValue = E_OK;
 
            /* set SINGLECALL to mode when no error detected */
            pPrimitiveInOut->mode = CRYPTO_OPERATIONMODE_SINGLECALL;
        }
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_rndSeedErrorCheck                                     */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about Random seed extend service. */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_rndSeedErrorCheck( Crypto_JobType* job )
{
    Std_ReturnType                      retValue;
    Crypto_JobPrimitiveInputOutputType* pPrimitiveInOut;
    uint32_least                        cryptoKeyIndex;
 
    pPrimitiveInOut = &job->PrimitiveInputOutput;
 
    /* random generator initialization check */
    if ( CRYPTO_70_RNG_UNINIT == Crypto_RngStatus ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00057] : If the module is not initialized and if default error
         * detection for the Crypto Driver is enabled, the function Crypto_ProcessJob
         * shall report CRYPTO_E_UNINIT to the DET and return E_NOT_OK. */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                    ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else {
        /* cryptoKeyId check */
        /* [SWS_Crypto_00072] : All crypto services listed in Crypto_ServiceInfoType except of CRYPTO_HASH, and CRYPTO_RANDOMGENERATE
         * require a key represented as a key identifier.*/
        retValue = crypto_chkCryptoKeyId( job->cryptoKeyId, &cryptoKeyIndex );
        if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Crypto_00217] : The crypto Driver shall check if job->cryptoKeyId and, if applicable, job->targetCryptoKeyId
             * are in range, before it executes a job. If the check fails, the function Crypto_ProcessJob() shall report CRYPTO_E_PARAM_HANDLE
             * to DET and return E_NOT_OK.*/
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                        ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            /* key status check */
            if ( CRYPTO_KEYSTATUS_INVALID == (Crypto_KeyStatusType)Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus ) {
                retValue = CRYPTO_E_KEY_NOT_VALID;
            } else {
                /* inputPtr check */
                if ( (uint8*)NULL_PTR == pPrimitiveInOut->inputPtr ) {
                    /* [SWS_Crypto_00070] : If a pointer to a buffer is required as an argument, but it is a null pointer,
                     * the Crypto_ProcessJob() function shall report CRYPTO_E_PARAM_POINTER to the DET if development error
                     * detection for the Crypto Driver is enabled, and return E_NOT_OK. */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
                    ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                                 ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
                    retValue = E_NOT_OK;
                } else {
                    retValue = E_OK;
 
                    /* set SINGLECALL to mode when no error detected */
                    pPrimitiveInOut->mode = CRYPTO_OPERATIONMODE_SINGLECALL;
                }
            }
        }
    }
 
    return ( retValue );
}
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_keySetErrorCheck                                      */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about set key status service.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_keySetErrorCheck( Crypto_JobType* job )
{
    Std_ReturnType  retValue;
    uint32_least    cryptoKeyIndex;
 
    /* cryptoKeyId check */
    /* [SWS_Crypto_00072] : All crypto services listed in Crypto_ServiceInfoType except of CRYPTO_HASH, and CRYPTO_RANDOMGENERATE
     * require a key represented as a key identifier.*/
    retValue = crypto_chkCryptoKeyId( job->cryptoKeyId, &cryptoKeyIndex );
    if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00217] : The crypto Driver shall check if job->cryptoKeyId and, if applicable, job->targetCryptoKeyId
         * are in range, before it executes a job. If the check fails, the function Crypto_ProcessJob() shall report CRYPTO_E_PARAM_HANDLE
         * to DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else {
        retValue = E_OK;
 
        /* set SINGLECALL to mode when no error detected */
        job->PrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_customErrorCheck                                      */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about custom service.             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_customErrorCheck( const Crypto_JobType* job )
{
    Std_ReturnType  retValue;
    uint32_least    cryptoKeyIndex;
 
    /* cryptoKeyId check */
    /* [SWS_Crypto_00072] : All crypto services listed in Crypto_ServiceInfoType except of CRYPTO_HASH, and CRYPTO_RANDOMGENERATE
     * require a key represented as a key identifier.*/
    retValue = crypto_chkCryptoKeyId( job->cryptoKeyId, &cryptoKeyIndex );
    if ( E_OK != retValue ) {
        /* crypto key error */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00217] : The crypto Driver shall check if job->cryptoKeyId and, if applicable, job->targetCryptoKeyId
         * are in range, before it executes a job. If the check fails, the function Crypto_ProcessJob() shall report CRYPTO_E_PARAM_HANDLE
         * to DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else if ( CRYPTO_KEYSTATUS_INVALID == (Crypto_KeyStatusType)Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus ) {
        /* key status error */
        retValue = CRYPTO_E_KEY_NOT_VALID;
    } else {
        /* crypto key has no error. retValue = E_OK */
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_unsupportedServiceErrorCheck                          */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_NOT_OK                                                  */
/* Contents    : This function check errors about unsupported services.       */
/*               This function always return E_NOT_OK.                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_unsupportedServiceErrorCheck( void )
{
    /* Unsupported services */
    /* [SWS_Crypto_00064] : If the parameter job->jobPrimitiveInfo->primitiveInfo->service
     * is not supported by the Crypto Driver Object and if development error detection for
     * the Crypto Driver is enabled, the function Crypto_ProcessJob shall report
     * CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
    ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                 ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* #if ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
 
    return ( E_NOT_OK );
}
 
#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
 
/* EOF Crypto_JobErrChk.c *****************************************************/