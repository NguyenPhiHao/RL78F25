/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto.c                                                     */
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
/* Note        : --                                                           */
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
#include "Crypto.h"
#include "CryIf_Cbk.h"
#include "Crypto_70_HW.h"
#include "Crypto_70_Callout_CustomService.h"
#include "Crypto_KeyManagement.h"
#include "SchM_Crypto.h"

#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
#include "Det.h"

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
#if ( ( CRYIF_CBK_AR_RELEASE_MAJOR_VERSION != CRYPTO_AR_RELEASE_MAJOR_VERSION )\
   || ( CRYIF_CBK_AR_RELEASE_MINOR_VERSION != CRYPTO_AR_RELEASE_MINOR_VERSION ) )
#error "AUTOSAR Release Version error between CryIf_Cbk and Crypto."
#endif /* ( ( CRYIF_AR_RELEASE_MAJOR_VERSION != CRYPTO_AR_RELEASE_MAJOR_VERSION ) */
      /* || ( CRYIF_AR_RELEASE_MINOR_VERSION != CRYPTO_AR_RELEASE_MINOR_VERSION ) ) */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
#if ( ( DET_AR_RELEASE_MAJOR_VERSION != CRYPTO_AR_RELEASE_MAJOR_VERSION )\
   || ( DET_AR_RELEASE_MINOR_VERSION != CRYPTO_AR_RELEASE_MINOR_VERSION ) )
#error "AUTOSAR Release Version error between Det and Crypto."
#endif /* ( ( DET_AR_RELEASE_MAJOR_VERSION != CRYPTO_AR_RELEASE_MAJOR_VERSION ) */
      /* || ( DET_AR_RELEASE_MINOR_VERSION != CRYPTO_AR_RELEASE_MINOR_VERSION ) ) */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

#endif /* CRYPTO_DEV_ERROR_DETECT != FALSE */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CONST_16
#include "Crypto_MemMap.h"
/* future reconsideration :
* These values below are not required.
* Because Crypto has only pre-compile time configuration.
*/
/* Global configuration pointer : pointer to the configuration structure. */
static const Crypto_DriverObjectsType* const s_CryptoDriverObjectsCfgPtr = &Crypto_DriverObjectsCfg;
static const Crypto_KeysType* const          s_CryptoKeysCfgPtr          = &Crypto_KeysCfg;
#define CRYPTO_STOP_SEC_CONST_16
#include "Crypto_MemMap.h"

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
bool_t Crypto_CancelReq = FALSE;
#define CRYPTO_STOP_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/
/*
 * This variable holds the state of the driver. After reset is UNINIT.
 * The output of Crypto_Init() function should set this variable into IDLE state.
 */
#define CRYPTO_START_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
CRYPTO_70_DriverStatusType Crypto_DriverStatus = CRYPTO_UNINIT;
#define CRYPTO_STOP_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
/*
 * This variable holds the state of the ObjectId.
 * The output of Crypto_Init() function should set this variable into "CRYPTO_OBJECT_IDLE" state.
 */
#define CRYPTO_START_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
CRYPTO_70_ObjectStatusType Crypto_ObjectStatus = CRYPTO_OBJECT_UNINIT;
#define CRYPTO_STOP_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
 
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
/*
 * This variable holds the state of the Random Generator.
 * The output of Crypto_Init() function should set this variable into "CRYPTO_70_RNG_INIT" state.
 */
#define CRYPTO_START_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
Crypto_70_RngStatusType Crypto_RngStatus = CRYPTO_70_RNG_UNINIT;
#define CRYPTO_STOP_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
/*
 * This variable holds the queue that used for queueing operation.
 */
#define CRYPTO_START_SEC_VAR_NO_INIT_LOCAL_8
#include "Crypto_MemMap.h"
static Crypto_70_AsyncQueueType Crypto_AsyncQueue;
#define CRYPTO_START_SEC_VAR_NO_INIT_LOCAL_8
#include "Crypto_MemMap.h"
 
/*
 * This variable holds the queued jobs.
 */
#define CRYPTO_START_SEC_VAR_NO_INIT_LOCAL_32
#include "Crypto_MemMap.h"
static Crypto_JobType* Crypto_QueuedJobs[CRYPTO_70_QUEUE_SIZE];
#define CRYPTO_STOP_SEC_VAR_NO_INIT_LOCAL_32
#include "Crypto_MemMap.h"
#endif  /* #if ( 0U == CRYPTO_70_SIZE_OF_QUEUE ) */
 
/*
 * This variable holds the active job.
 */
#define CRYPTO_START_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
static Crypto_JobType* Crypto_ActiveJob = NULL_PTR;
#define CRYPTO_STOP_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
 
#define CRYPTO_START_SEC_VAR_NO_INIT_LOCAL_8
#include "Crypto_MemMap.h"
CRYPTO_70_KeyInfoType Crypto_KeyInfo[CRYPTO_70_NUM_OF_KEY];
#define CRYPTO_STOP_SEC_VAR_NO_INIT_LOCAL_8
#include "Crypto_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
static Std_ReturnType crypto_initKey( void );
 
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
static Std_ReturnType crypto_getRsaKeyData( const Crypto_KeyElementType* pKeyElement, uint8 keyElementNum, Crypto_70_RsaKeyType** pRsaKey );
 
static Std_ReturnType crypto_checkRsaKeyData( Crypto_70_RsaKeyType* pRsaKey );
#endif
 
static Std_ReturnType crypto_execQueueing( Crypto_JobType* job );
 
static Std_ReturnType crypto_execService( Crypto_JobType* job );
 
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
static void crypto_initQueue( void );
 
static void crypto_enqueue( Crypto_JobType* job );
 
static uint8 crypto_dequeue( void );
 
static void crypto_deleteQueue( uint8 deleteIndex );
#endif  /* #if ( 0U != CRYPTO_70_SIZE_OF_QUEUE ) */
 
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
static Std_ReturnType crypto_getRsaKey( const Crypto_JobType* job, Crypto_70_RsaKeyType** pRsaKey );
#endif
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_INIT_ID (0x00)                                        */
/* Name        : Crypto_Init                                                  */
/* Param       : (in) configPtr     This pointer shall always have a null     */
/*                                  pointer value.                            */
/* Return      : void                                                         */
/* Contents    : Initializes the Crypto Driver.                               */
/* Author      : --                                                           */
/* Note        : [SWS_Crypto_91000][SWS_Crypto_00045][SWS_Crypto_00126]       */
/*               [SWS_Crypto_00040][SWS_Crypto_00018][SWS_Crypto_00019]       */
/*----------------------------------------------------------------------------*/
void Crypto_Init( const Crypto_ConfigType* configPtr )
{
    Std_ReturnType  retValue;
    uint32          numOfObject;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
     * The Crypto Driver shall use an AUTOSAR DET module for development error notification.
     */
    /* [SWS_Crypto_00215] :
     * The Configuration pointer configPtr is currently not used
     * and shall therefore be set to null pointer value.
     */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
    if ( ( (Crypto_ConfigType*)NULL_PTR != configPtr ) || ( CRYPTO_IDLE == Crypto_DriverStatus ) ) {
        /* [SWS_Crypto_00045] : If the initialization of the Crypto Driver fails,
         * the Crypto shall report CRYPTO_E_INIT_FAILED to the DET.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_INIT_ID, ( uint8 ) CRYPTO_E_INIT_FAILED );
    } else if ( ( (Crypto_DriverObjectsType*)NULL_PTR == s_CryptoDriverObjectsCfgPtr )
     || ( (Crypto_KeysType*)NULL_PTR == s_CryptoKeysCfgPtr ) ) {
        /* [SWS_Crypto_00045] : If the initialization of the Crypto Driver fails,
         * the Crypto shall report CRYPTO_E_INIT_FAILED to the DET.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_INIT_ID, ( uint8 ) CRYPTO_E_INIT_FAILED );
    } else
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
    {
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
        /* init Queue */
        crypto_initQueue( );
#endif
 
        /* init Key Info */
        retValue = crypto_initKey( );
        if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Crypto_00045] : If the initialization of the Crypto Driver fails,
             * the Crypto shall report CRYPTO_E_INIT_FAILED to the DET.
             */
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_INIT_ID, ( uint8 ) CRYPTO_E_INIT_FAILED );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return;
        }
 
        /* initialization process */
        retValue = Crypto_70_HW_Init( );
        if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Crypto_00045] : If the initialization of the Crypto Driver fails,
             * the Crypto shall report CRYPTO_E_INIT_FAILED to the DET.
             */
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_INIT_ID, ( uint8 ) CRYPTO_E_INIT_FAILED );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            return;
        } else {
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
            Crypto_RngStatus = CRYPTO_70_RNG_INIT;
#endif  /* ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
            numOfObject = s_CryptoDriverObjectsCfgPtr->CryptoNumOfDriverObject;
 
            if ( 1U != numOfObject ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
                /* [SWS_Crypto_00045] : If the initialization of the Crypto Driver fails,
                 * the Crypto shall report CRYPTO_E_INIT_FAILED to the DET.
                 */
                ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                             ( uint8 ) CRYPTO_INIT_ID, ( uint8 ) CRYPTO_E_INIT_FAILED );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
                return;
            } else {
                /* [SWS_Crypto_00018] : If no errors are detected by Crypto Driver,
                 * set Crypto driver object status to "CRYPTO_OBJECT_IDLE".
                 */
                Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
 
                /* [SWS_Crypto_00019][SWS_BSW_00071] : The crypto driver is already in "idle" state. */
                Crypto_DriverStatus = CRYPTO_IDLE;
            }
        }
    }
}
 
#if ( CRYPTO_VERSION_INFO_API != FALSE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_GETVERSION_INFO_ID (0x01)                             */
/* Name        : Crypto_GetVersionInfo                                        */
/* Param       : (in) versioninfo   Pointer to where to store the version     */
/*                                  information of this module.               */
/* Return      : void                                                         */
/* Contents    : Returns the version information of this module.              */
/* Author      : --                                                           */
/* Note        : [SWS_Crypto_91001][SWS_Crypto_00047][SWS_Crypto_00126]       */
/*               [SWS_Crypto_00040]                                           */
/*----------------------------------------------------------------------------*/
void Crypto_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
     * The Crypto Driver shall use an AUTOSAR DET module for development error notification.
     */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
    if ( NULL_PTR == versioninfo ) {
        /* [SWS_Crypto_00047] : If the parameter versioninfo is a null pointer and
         * if default error detection for the Crypto Driver is enabled, the function
         * Crypto_GetVersionInfo shall report CRYPTO_E_PARAM_POINTER to the DET.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_GETVERSION_INFO_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
    } else
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Crypto_91001][SWS_BSW_00052] : The function Crypto_GetVersionInfo shall return
         * the version information of this module. The version information includes :
         * Module Id, Vendor Id, Vendor specific version numbers.
         */
        versioninfo->vendorID         = ( uint16 ) CRYPTO_VENDOR_ID;
        versioninfo->moduleID         = ( uint16 ) CRYPTO_MODULE_ID;
        versioninfo->sw_major_version = ( uint8 ) CRYPTO_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = ( uint8 ) CRYPTO_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = ( uint8 ) CRYPTO_SW_PATCH_VERSION;
    }
}
#endif /*( CRYPTO_VERSION_INFO_API != FALSE )*/
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_PROCESS_JOB_ID (0x03)                                 */
/* Name        : Crypto_ProcessJob                                            */
/* Param       : (in) objectId      Holds the identifier of the Crypto Driver */
/*                                  Object.                                   */
/*               (inout) job        Pointer to the configuration of the job.  */
/*                                  Contains structures with job and          */
/*                                  primitive relevant information but also   */
/*                                  pointer to result buffers.                */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful.                               */
/*                    E_NOT_OK: Request Failed.                               */
/*                    CRYPTO_E_BUSY: Request failed,                          */
/*                                   Crypro Driver Objectis Busy.             */
/*                    CRYPTO_E_KEY_NOT_VALID: Request failed,                 */
/*                                            the key is not valid.           */
/*                    CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key       */\
/*                                                element has the wrong size. */
/*                    CRYPTO_E_KEY_READ_FAIL: Request failed because key      */
/*                                         element extraction is not allowed. */
/*                    CRYPTO_E_KEY_WRITE_FAIL: Request failed because         */
/*                                             the writing access failed.     */
/*                                             Load key command failed        */
/*                    CRYPTO_E_KEY_NOT_AVAILABLE: Request failed,             */
/*                                                Load key command failed     */
/*                    CRYPTO_E_ENTROPY_EXHAUSTED: Request failed, the entropy */
/*                                                is exhausted.               */
/*                    CRYPTO_E_JOB_CANCELED: Request failed because           */
/*                                     the synchronous Job has been canceled. */
/*                    CRYPTO_E_KEY_EMPTY: Request failed because of           */
/*                                        uninitialized source key element.   */
/*                    CRYPTO_E_CUSTOM_ERROR: Custom processing failed         */
/* Contents    : Performs the crypto primitive, that is configured in the     */
/*               job parameter.                                               */
/* Author      : --                                                           */
/* Note        : [SWS_Crypto_91003][SWS_Crypto_00013][SWS_Crypto_00014]       */
/*               [SWS_Crypto_00118][SWS_Crypto_00025][SWS_Crypto_00026]       */
/*               [SWS_Crypto_00031][SWS_Crypto_00034][SWS_Crypto_00039]       */
/*               [SWS_Crypto_00194][SWS_Crypto_00195][SWS_Crypto_00057]       */
/*               [SWS_Crypto_00058][SWS_Crypto_00059][SWS_Crypto_00064]       */
/*               [SWS_Crypto_00065][SWS_Crypto_00067][SWS_Crypto_00070]       */
/*               [SWS_Crypto_00142][SWS_Crypto_00071][SWS_Crypto_00072]       */
/*               [SWS_Crypto_00073][SWS_Crypto_00134][SWS_Crypto_00135]       */
/*               [SWS_Crypto_00136][SWS_Crypto_00141][SWS_Crypto_00040]       */
/*               [SWS_Crypto_00126][SWS_Crypto_00017][SWS_Crypto_00020]       */
/*               [SWS_Crypto_00023][SWS_Crypto_00121]                         */
/*----------------------------------------------------------------------------*/
Std_ReturnType Crypto_ProcessJob( uint32 objectId, Crypto_JobType* job )
{
    Std_ReturnType                      retValue;
    const Crypto_JobPrimitiveInfoType*  pPrimitive;
    Crypto_JobPrimitiveInputOutputType* pPrimitiveInOut;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
     * The Crypto Driver shall use an AUTOSAR DET module for development error notification.
     */
    /* check driver and object status */
    if ( ( CRYPTO_IDLE != Crypto_DriverStatus ) || ( CRYPTO_OBJECT_UNINIT == Crypto_ObjectStatus ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00057] : If the module is not initialized and if default error
         * detection for the Crypto Driver is enabled, the function Crypto_ProcessJob
         * shall report CRYPTO_E_UNINIT to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* check object ID */
    if ( objectId != *(&(s_CryptoDriverObjectsCfgPtr->CryptoDriverObject)->CryptoDriverObjectId) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00058] : If the parameter objectId is out of range and if development error detection
         * for the Crypto Driver is enabled, the function Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE
         * to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* check the job pointer */
    if ( ( (Crypto_JobType*)NULL_PTR == job ) || ( (Crypto_JobPrimitiveInfoType*)NULL_PTR == job->jobPrimitiveInfo ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00059] : If the parameter job is a null pointer and if default error
         * detection for the Crypto Driver is enabled, the function Crypto_ProcessJob shall
         * report CRYPTO_E_PARAM_POINTER to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    if ( ( CRYPTO_OBJECT_ACTIVE == Crypto_ObjectStatus )
             && ( CRYPTO_PROCESSING_SYNC == job->jobPrimitiveInfo->processingType ) ) {
        /* [SWS_Crypto_00121] : If Crypto_ProcessJob() is called and the Job is in "ACTIVE" state,
         * the Crypto_ProcessJob()shall check if the requested job matches the current job in
         * the Crypto Driver Object and if yes, bypass it from queueing.
         */
        if ( job->jobId != Crypto_ActiveJob->jobId ) {
            /* [SWS_Crypto_00034] : If Crypto_ProcessJob() is called with synchronous job processing
             * and the queue is not full, but the Crypto Driver Object is busy, the Crypto Driver Object
             * shall not queue the job and return CRYPTO_E_BUSY. No job shall be put in any queue.
             */
            return ( CRYPTO_E_BUSY );
        }
    }
 
    if ( ( CRYPTO_JOBSTATE_IDLE == job->state )
             && ( CRYPTO_OPERATIONMODE_START != ( CRYPTO_OPERATIONMODE_START & job->PrimitiveInputOutput.mode ) ) ) {
        /* [SWS_Crypto_00118] : If Crypto_ProcessJob() is called while the job is in state "Idle" and the "START"
         * flag in the operation mode is not set, the function shall return with E_NOT_OK.
         */
        retValue = E_NOT_OK;
    } else {
        pPrimitive = job->jobPrimitiveInfo;
        pPrimitiveInOut = &job->PrimitiveInputOutput;
 
        /* error check for each service */
        retValue = crypto_jobErrorCheck( job );
 
        if ( E_OK == retValue ) {
            Crypto_ObjectStatus = CRYPTO_OBJECT_ACTIVE;
 
            if ( CRYPTO_PROCESSING_ASYNC == pPrimitive->processingType ) {
                retValue = crypto_execQueueing( job );
            } else if ( CRYPTO_PROCESSING_SYNC == pPrimitive->processingType ) {
                retValue = crypto_execService( job );
            } else {
                /* error */
                retValue = E_NOT_OK;
            }
 
            if ( E_OK == retValue ) {
                if ( CRYPTO_PROCESSING_ASYNC == pPrimitive->processingType ) {
                    Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
                } else {    /*  CRYPTO_PROCESSING_SYNC == pPrimitive->processingType    */
                    if ( CRYPTO_OPERATIONMODE_FINISH == ( CRYPTO_OPERATIONMODE_FINISH & pPrimitiveInOut->mode ) ) {
                        Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
                    }
                }
            } else {
                /* [SWS_Crypto_00119] : If an internal error occurs while processing an asynchronous job,
                 * the corresponding job state shall be set to "Idle" and all input data and intermediate
                 * results shall be discarded. Further, the callback notification shall be called with an appropriate error code.
                 */
                crypto_memSet( ( uint8* )pPrimitiveInOut->outputPtr, 0U, *(pPrimitiveInOut->outputLengthPtr) );
                crypto_memSet( ( uint8* )pPrimitiveInOut->secondaryOutputPtr, 0U, *(pPrimitiveInOut->secondaryOutputLengthPtr) );
                *(pPrimitiveInOut->outputLengthPtr) = 0U;
                *(pPrimitiveInOut->secondaryOutputLengthPtr) = 0U;
 
                if ( CRYPTO_E_ENTROPY_EXHAUSTED == retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
                    /* [SWS_Crypto_00141] : If the random generator service is chosen and the corresponding entropy, the function shall
                     * return CRYPTO_E_ENTROPY_EXHAUSTED. The function Crypto_ProcessJob shall additionally report the runtime error
                     * CRYPTO_E_RE_ENTROPY_EXHAUSTED.
                     */
                    ( void ) Det_ReportRuntimeError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                                    ( uint8 ) CRYPTO_PROCESS_JOB_ID, ( uint8 ) CRYPTO_E_RE_ENTROPY_EXHAUSTED );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
                }
 
                /* When CRYPTO_E_BUSY is returned, the process is still running. */
                /* Otherwise, the process has stopped. */
                if ( CRYPTO_E_BUSY != retValue ) {
                    /* [SWS_Crypto_00018] : When error occurs, Crypto Driver Object is set to "Idle". */
                    Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
                }
            }
        }
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_CANCEL_JOB_ID (0x0E)                                  */
/* Name        : Crypto_CancelJob                                             */
/* Param       : (in) objectId      Holds the identifier of the Crypto Driver */
/*                                  Object.                                   */
/*               (inout) job        Pointer to the configuration of the job.  */
/*                                  Contains structures with job and          */
/*                                  primitive relevant information.           */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful, job has been removed.         */
/*                    E_NOT_OK: Request Failed, job couldn't be removed.      */
/*                    CRYPTO_E_JOB_CANCELED: The job has been cancelled but   */
/*                                           is still processed. No results   */
/*                                           will be returned to              */
/*                                           the application.                 */
/* Contents    : This interface removes the provided job from the queue and   */
/*               cancels the processing of the job if possible.               */
/* Author      : --                                                           */
/* Note        : [SWS_Crypto_00122][SWS_Crypto_00123][SWS_Crypto_00124]       */
/*               [SWS_Crypto_00125][SWS_Crypto_00143][SWS_Crypto_00183]       */
/*               [SWS_Crypto_00040][SWS_CRYPTO_00126]                         */
/*----------------------------------------------------------------------------*/
 
Std_ReturnType Crypto_CancelJob( uint32 objectId, Crypto_JobType* job )
{
    Std_ReturnType                  retValue;
    Crypto_ServiceInfoType          serviceInfo;
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
    uint8_least                     jobCnt;
    uint8_least                     jobIndex = CRYPTO_70_QUEUE_EMPTY;
    const Crypto_PrimitiveInfoType* pPrimitiveInfo;
#endif  /* #if ( 0U != CRYPTO_70_SIZE_OF_QUEUE ) */
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
     * The Crypto Driver shall use an AUTOSAR DET module for development error notification.
     */
    /* check driver and object status */
    if ( ( CRYPTO_IDLE != Crypto_DriverStatus ) || ( CRYPTO_OBJECT_UNINIT == Crypto_ObjectStatus ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00123] : If default error detection for the Crypto Driver is
         * enabled: The function Crypto_CancelJob shall raise the error CRYPTO_E_UNINIT
         * and return E_NOT_OK if the module is not yet initialized.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_CANCEL_JOB_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* check job pointer */
    if ( ( (Crypto_JobType*)NULL_PTR == job )
             || ( (Crypto_JobPrimitiveInfoType*)NULL_PTR == job->jobPrimitiveInfo )
             || ( (Crypto_PrimitiveInfoType*)NULL_PTR == job->jobPrimitiveInfo->primitiveInfo ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00125] : If default error detection for the Crypto Driver is enabled:
         * The function Crypto_CancelJob shall raise the error CRYPTO_E_PARAM_POINTER and
         * return E_NOT_OK if the parameter job is a null pointer.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_CANCEL_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* check object ID */
    if ( objectId != *(&(s_CryptoDriverObjectsCfgPtr->CryptoDriverObject)->CryptoDriverObjectId) ) {
        /* object id check */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00124] : If default error detection for the Crypto Driver is enabled:
         * The function Crypto_CancelJob shall raise the error CRYPTO_E_PARAM_HANDLE and
         * return E_NOT_OK if the parameter objectId is out or range.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_CANCEL_JOB_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* reject custom service */
    if ( CRYPTO_CUSTOM_SERVICE == job->jobPrimitiveInfo->primitiveInfo->service ) {
        /* constraints */
        return ( E_NOT_OK );
    }
 
    serviceInfo = job->jobPrimitiveInfo->primitiveInfo->service;
 
    /* cancel request set */
    Crypto_CancelReq = TRUE;
 
    /* check the processing job */
    if( CRYPTO_OBJECT_ACTIVE == Crypto_ObjectStatus ) {
        if ( serviceInfo == Crypto_ActiveJob->jobPrimitiveInfo->primitiveInfo->service ) {
            /* same job is processing */
            if ( ( CRYPTO_KEYSETVALID == serviceInfo ) || ( CRYPTO_KEYSETINVALID == serviceInfo ) ) {
                return ( E_OK );
            } else {
                /* [SWS_Crypto_00183] : If no errors are detected by Crypto Driver and the driver is not able to cancel the job
                 * (e.g. due to hardware limitations), the service Crypto_CancelJob() shall return CRYPTO_E_JOB_CANCELED.
                 */
                retValue = Crypto_70_HW_CancelJob( job->jobPrimitiveInfo );
                return ( retValue );
            }
        }
    }
 
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
    /* exclusive interval start */
    SchM_Enter_Crypto_QueueOperation();
 
    /* search same service in queue */
    for ( jobCnt=0U; jobCnt<Crypto_AsyncQueue.size; jobCnt++ ) {
        pPrimitiveInfo = Crypto_QueuedJobs[Crypto_AsyncQueue.queue[jobCnt]]->jobPrimitiveInfo->primitiveInfo;
        if ( serviceInfo == pPrimitiveInfo->service ) {
            jobIndex = jobCnt;
            break; /* break the loop */
        }
    }
 
    if ( CRYPTO_70_QUEUE_EMPTY != jobIndex ) {
        /* delete queue from Crypto_AsyncQueue */
        /* [SWS_Crypto_00143] : If no errors are detected by Crypto Driver and the driver is able to
         * cancel the job immediately, the service Crypto_CancelJob() shall remove the job from the
         * queue and cancel the job in the hardware.
         * If the cancellation is successful E_OK shall be returned, otherwise it shall return E_NOT_OK.
         */
        crypto_deleteQueue( (uint8)jobIndex );
    } else {
        /* [SWS_Crypto_00214] : If no errors are detected by Crypto Driver and the driver does currently
         * not process this job, the service Crypto_CancelJob() shall return E_OK without any processing.
         */
    }
 
    /* exclusive interval end */
    SchM_Exit_Crypto_QueueOperation();
#endif  /* #if ( 0U == CRYPTO_70_SIZE_OF_QUEUE ) */
 
    retValue = E_OK;
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : Crypto_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_RANDOM_SEED_ID                                        */
/* Name        : Crypto_RandomSeed                                            */
/* Param       : (in) cryptoKeyId                                             */
/*               (in) seedPtr                                                 */
/*               (in) seedLength                                              */
/* Return      : Std_ReturnType                                               */
/*                  E_OK: Request successful.                                 */
/*                  E_NOT_OK: Request failed.                                 */
/*                  CRYPTO_E_KEY_NOT_VALID: Request failed, the key state of  */
/*                                          the key identified by cryIfKeyId  */
/*                                          is "invalid".                     */
/* Contents    : This function generates the internal seed state using the    */
/*               provided entropy source. Furthermore, this function can be   */
/*               used to update the seed state with new entropy.              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_RandomSeed( uint32 cryptoKeyId, const uint8* seedPtr, uint32 seedLength )
{
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    Std_ReturnType  retValue;
    uint32          cryptoKeyIndex;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
    * The Crypto Driver shall use an AUTOSAR DET module for development error notification. */
    if ( (CRYPTO_IDLE != Crypto_DriverStatus ) || ( CRYPTO_70_RNG_UNINIT == Crypto_RngStatus ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /*
         * [SWS_Crypto_00128] : If the module is not yet initialized and if development error detection
         * for the Crypto Driver is enabled, the function Crypto_RandomSeed shall report CRYPTO_E_UNINIT
         * to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_RANDOM_SEED_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else if ( (uint8*)NULL_PTR == seedPtr ) {
        /* seedPtr check */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /*
         * [SWS_Crypto_00130] : If the parameter seedPtr is a null pointer and if development error
         * detection for the Crypto Driver is enabled, the function Crypto_RandomSeed shall report
         * CRYPTO_E_PARAM_POINTER to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_RANDOM_SEED_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else if ( 0U == seedLength ) {
        /* seedLength check */
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /*
         * [SWS_Crypto_00131] : If seedLength is zero and if development error detection for the Crypto
         * Driver is enabled, the function Crypto_RandomSeed shall report CRYPTO_E_PARAM_VALUE to
         * the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_RANDOM_SEED_ID, ( uint8 ) CRYPTO_E_PARAM_VALUE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else {
        /* crypto key ID check */
        retValue = crypto_chkCryptoKeyId( cryptoKeyId, &cryptoKeyIndex );
        if ( E_OK != retValue ){
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /*
             * [SWS_Crypto_00129] : If the parameter cryptoKeyId is out of range and if development
             * error detection for the Crypto Driver is enabled, the function Crypto_RandomSeed shall
             * report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.
             */
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                             ( uint8 ) CRYPTO_RANDOM_SEED_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            /* key status check */
            if ( CRYPTO_KEYSTATUS_VALID == Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus ) {
                retValue = Crypto_70_HW_RandomSeedExtend( seedPtr );
            } else {
                retValue = CRYPTO_E_KEY_NOT_VALID;
            }
        }
    }
    return ( retValue );
#else
    return ( E_NOT_OK );
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
}
 
/******************************************************************************/
/* ModuleID    : Crypto_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_CUSTOM_SYNC_ID                                        */
/* Name        : Crypto_CustomSync                                            */
/* Param       : (in) dispatchId                                              */
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
/*                  CRYPTO_E_BUSY : The service request failed because        */
/*                                  the service is still busy.                */
/*                  CRYPTO_E_CUSTOM_ERROR : Callout function failed.          */
/* Contents    : Requests the execution of a function that is specified by    */
/*               the given dispatch id.                                       */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_CustomSync( uint32 dispatchId, uint32 keyId, uint32 keyElementId, uint32 targetKeyId,
                                  uint32 targetKeyElementId, const uint8* inputPtr, uint32 inputLength,
                                  uint8* outputPtr, uint32* outputLengthPtr, uint8* secondaryOutputPtr,
                                  uint32* secondaryOutputLengthPtr )
{
    Std_ReturnType  retValue;
    uint32          keyIndex;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
    * The Crypto Driver shall use an AUTOSAR DET module for development error notification. */
    if (( CRYPTO_IDLE != Crypto_DriverStatus ) || ( CRYPTO_OBJECT_UNINIT == Crypto_ObjectStatus )) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /*
         * [SWS_Crypto_00256] : If the module is not yet initialized and if development error detection
         * for the Crypto Driver is enabled, the function Crypto_CustomSync shall report CRYPTO_E_UNINIT
         * to the DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_CUSTOM_SYNC_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else if ( CRYPTO_OBJECT_ACTIVE == Crypto_ObjectStatus ) {
        retValue = CRYPTO_E_BUSY;
    } else {
        /* keyId check */
        retValue = crypto_chkCryptoKeyId( keyId, &keyIndex );
        if ( E_OK != retValue ){
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /*
             * [SWS_Crypto_00257] : If the parameter cryptoKeyId is out of range and if development error
             * detection for the Crypto Driver is enabled, the function Crypto_CustomSync shall report
             * CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                             ( uint8 ) CRYPTO_CUSTOM_SYNC_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            Crypto_ObjectStatus = CRYPTO_OBJECT_ACTIVE;
            retValue = Crypto_Callout_CustomService( NULL_PTR, dispatchId, keyId, keyElementId,
                                                     targetKeyId, targetKeyElementId, inputPtr,
                                                     inputLength, outputPtr, outputLengthPtr,
                                                     secondaryOutputPtr, secondaryOutputLengthPtr );
            Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
        }
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : Crypto_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_MAIN_FUNCTION_ID                                      */
/* Name        : Crypto_MainFunction                                          */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : If asynchronous job processing is configured and there are   */
/*               job queues, the function is called cyclically to process     */
/*               queued jobs.                                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Crypto_MainFunction( void )
{
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
    Std_ReturnType                      retValue;
    uint8                               jobIndex;
    Crypto_JobType*                     pAsyncJob;
    Crypto_JobPrimitiveInputOutputType* pPrimitiveInOut;
 
    if ( ( CRYPTO_UNINIT != Crypto_DriverStatus ) && ( CRYPTO_OBJECT_IDLE == Crypto_ObjectStatus ) ) {
        /* Exclusive interval start */
        SchM_Enter_Crypto_QueueOperation();
 
        /* dequeue the job index value */
        jobIndex = crypto_dequeue();
 
        /* Exclusive interval end */
        SchM_Exit_Crypto_QueueOperation();
 
        if ( CRYPTO_70_QUEUE_EMPTY != jobIndex ) {
            Crypto_ObjectStatus = CRYPTO_OBJECT_ACTIVE;
            pAsyncJob = Crypto_QueuedJobs[jobIndex];
            pPrimitiveInOut = &pAsyncJob->PrimitiveInputOutput;
 
            retValue = crypto_execService( pAsyncJob );
            if ( E_OK != retValue ) {
                /* [SWS_Crypto_00119] : If an internal error occurs while processing an asynchronous job,
                 * the corresponding job state shall be set to "Idle" and all input data and intermediate
                 * results shall be discarded. Further, the callback notification shall be called with an appropriate error code.
                 */
                crypto_memSet( (uint8*)pPrimitiveInOut->outputPtr, 0U, *(pPrimitiveInOut->outputLengthPtr) );
                crypto_memSet( (uint8*)pPrimitiveInOut->secondaryOutputPtr, 0U, *(pPrimitiveInOut->secondaryOutputLengthPtr) );
                *(pPrimitiveInOut->outputLengthPtr) = 0U;
                *(pPrimitiveInOut->secondaryOutputLengthPtr) = 0U;
            } else {
                /* do nothing */
            }
 
            /* [SWS_Crypto_00028] : For each asynchronous request the Crypto Driver shall notify CRYIF about the completion of the job
             * by calling the CRYIF_CallbackNotification function passing on the job information and the result of cryptographic operation.
             */
            CryIf_CallbackNotification( pAsyncJob, ( Crypto_ResultType )retValue );
 
            Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
        } else {
            /* no job in queue : do nothing */
        }
    } else {
        /* uninitialized crypto driver */
    }
#endif
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_memCopy                                               */
/* Param       : (in)  srcPtr Source data pointer.                            */
/*               (in)  length Length of setting data.                         */
/*               (out) dstPtr Destination data pointer.                       */
/* Return      : void                                                         */
/* Contents    : Copy the data to destination pointer from source pointer.    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void crypto_memCopy( const uint8 QL_70_FAR * srcPtr, uint8* dstPtr, uint32 length )
{
    uint32_least dataIndex;
   
    for ( dataIndex = 0x0U; dataIndex < length; dataIndex++ ) {
        dstPtr[dataIndex] = srcPtr[dataIndex];
    }
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_memSet                                                */
/* Param       : (out) dstPtr Source data pointer.                            */
/*               (in)  setVal set value.                                      */
/*               (in)  length Length of setting data.                         */
/* Return      : void                                                         */
/* Contents    : Set the value to destination pointer.                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void crypto_memSet( uint8* dstPtr, uint8 setVal, uint32 length )
{
    uint32_least dataIndex;
 
    for ( dataIndex = 0x0U; dataIndex < length; dataIndex++ ) {
        dstPtr[dataIndex] = setVal;
    }
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_chkCryptoKeyId                                        */
/* Param       : (in)  cryptoKeyId   Holds the identifier of the key which    */
/*                                   shall be set to valid.                   */
/*             : (out) pKeyIdIndex   Pointer to the index of the key which    */
/*                                   shall be set to valid.                   */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful.                               */
/*                    E_NOT_OK: Request Failed.                               */
/* Contents    : Check cryptoKeyId is out of range                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType crypto_chkCryptoKeyId( uint32 cryptoKeyId, uint32* pKeyIdIndex )
{
    Std_ReturnType          retValue = E_NOT_OK;
    const Crypto_KeyType*   pCryptoKey;
    uint32                  numOfKey;
    uint32_least            cryptoKeyIndex;
 
    numOfKey = s_CryptoKeysCfgPtr->CryptoNumOfKey;
    if ( 0U == numOfKey ) {
        retValue = E_NOT_OK;
    } else {
        for( cryptoKeyIndex = 0U; cryptoKeyIndex < numOfKey; cryptoKeyIndex++ ) {
            pCryptoKey = &s_CryptoKeysCfgPtr->CryptoKey[cryptoKeyIndex];
            if( pCryptoKey->CryptoKeyId == cryptoKeyId ) {
                *( pKeyIdIndex ) = cryptoKeyIndex;
                retValue = E_OK;
                break;
            }
        }
    }
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_chkElementId                                          */
/* Param         (in) keyElementId   Holds the identifier of the key element  */
/*                                   which shall be set.                      */
/*               (in)  pKey          Pointer to Key configuration container.  */
/*             : (out) pElementIndex Pointer to the index of the KeyElement   */
/*                                   which shall be set to valid.             */
/* Return      : Std_ReturnType                                               */
/*                  E_OK: Request successful.                                 */
/*                  E_NOT_OK: Request Failed.                                 */
/*                  CRYPTO_E_KEY_EMPTY: pKey->CryptoKeyTypeRef or             */
/*                    pKey->CryptoKeyTypeRef->CryptoKeyElementRef is NULL_PTR */
/*                  CRYPTO_E_KEY_NOT_AVAILABLE: Selected key element is not   */
/*                    available in pKey.                                      */
/* Contents    : Check KeyElementId is out of range                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType crypto_chkElementId( uint32 keyElementId, const Crypto_KeyType* pKey, uint32* pElementIndex )
{
    Std_ReturnType                  retValue = E_NOT_OK;
    const Crypto_KeyTypeType*       pKeyType;
    const Crypto_KeyElementType*    pKeyElement;
    uint32                          numKeyElementRef;
    uint32_least                    cryptoKeyElementIndex;
 
    if ( ( (Crypto_KeyTypeType*)NULL_PTR == pKey->CryptoKeyTypeRef )
      || ( (Crypto_KeyElementType*)NULL_PTR == pKey->CryptoKeyTypeRef->CryptoKeyElementRef ) ) {
        retValue = CRYPTO_E_KEY_EMPTY;
    } else {
        pKeyType = pKey->CryptoKeyTypeRef;
        numKeyElementRef = pKeyType->CryptoNumOfKeyElementRef;
        if ( 0U == numKeyElementRef ) {
            retValue = CRYPTO_E_KEY_EMPTY;
        } else {
            for( cryptoKeyElementIndex = 0x0U; cryptoKeyElementIndex < numKeyElementRef; cryptoKeyElementIndex++ ) {
                pKeyElement = &pKeyType->CryptoKeyElementRef[cryptoKeyElementIndex];
                if( pKeyElement->CryptoKeyElementId == keyElementId ) {
                    retValue = E_OK;
                    *pElementIndex = cryptoKeyElementIndex;
                    break;
                }
            }
 
            if ( E_OK != retValue ) {
                retValue = CRYPTO_E_KEY_NOT_AVAILABLE;
            }
        }
    }
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_initKey                                               */
/* Param       : void                                                         */
/* Return      : Std_ReturnType                                               */
/*                  E_OK: Request successful.                                 */
/*                  E_NOT_OK: Request Failed.                                 */
/*                            The configured RSA key data is invalid.         */
/* Contents    : Initialize variables.                                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_initKey( void )
{
    uint32_least    cryptoKeyIndex;
    uint32_least    ivCnt;
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
    Std_ReturnType          retValue;
    const Crypto_KeyType*       pKeyType;
    const Crypto_KeyTypeType*   pKeyTypeType;
    Crypto_70_RsaKeyType*   pRsaKey;
#endif
 
    /* initialize key info */
    for ( cryptoKeyIndex=0U; cryptoKeyIndex<CRYPTO_70_NUM_OF_KEY; cryptoKeyIndex++ ) {
        Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus = CRYPTO_KEYSTATUS_INVALID;
        for ( ivCnt=0U; ivCnt<CRYPTO_70_CBC_IV_LENGTH; ivCnt++ ) {
            Crypto_KeyInfo[cryptoKeyIndex].aesCbcIV[ivCnt] = 0U;
        }
    }
 
    /* check RSA key data */
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
    for ( cryptoKeyIndex=0U; cryptoKeyIndex<CRYPTO_70_NUM_OF_KEY; cryptoKeyIndex++ ) {
        /* get RSA key data */
        pKeyType = &s_CryptoKeysCfgPtr->CryptoKey[cryptoKeyIndex];
        pKeyTypeType = pKeyType->CryptoKeyTypeRef;
        retValue = crypto_getRsaKeyData( pKeyTypeType->CryptoKeyElementRef, (uint8)pKeyTypeType->CryptoNumOfKeyElementRef, &pRsaKey );
 
        if ( E_OK == retValue ) {
            /* check RSA key data */
            retValue = crypto_checkRsaKeyData( pRsaKey );
 
            if ( E_NOT_OK == retValue ) {
                /* If the RSA key contains 0x0000, E_NOT_OK is returned because a division by zero error may occur. */
                return E_NOT_OK;
            }
        }
    }
#endif /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
 
    return E_OK;
}
 
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_getRsaKeyData                                         */
/* Param       : (in)  keyElement                                             */
/*               (in)  elementNum                                             */
/*               (out) pRsaKey                                                */
/* Return      : Std_ReturnType                                               */
/*                  E_OK: Get RSA key.                                        */
/*                  E_NOT_OK: Rsa key is not exist.                           */
/* Contents    : Get RSA key.                                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
 
static Std_ReturnType crypto_getRsaKeyData( const Crypto_KeyElementType* pKeyElement, uint8 keyElementNum, Crypto_70_RsaKeyType** pRsaKey )
{
    uint8_least elementIndex;
 
    for ( elementIndex=0U; elementIndex<keyElementNum; elementIndex++ ) {
        if ( ( CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY == pKeyElement[elementIndex].CryptoKeyElementFormat )
          || ( CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY == pKeyElement[elementIndex].CryptoKeyElementFormat ) ) {
            /* Retrieve the RSA key into pRsaKey. */
            *pRsaKey = (Crypto_70_RsaKeyType *)((void *)pKeyElement[elementIndex].CryptoKeyElementValue);
 
            return E_OK;
        } else {
            /* If the key is the RSA key, do nothing. */
        }
    }
 
    return E_NOT_OK;
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_checkRsaKeyData                                       */
/* Param       : (in) pRsaKey                                                 */
/* Return      : Std_ReturnType                                               */
/*                  E_OK: RSA key has no error.                               */
/*                  E_NOT_OK: RSA key contains 0x0000.                        */
/* Contents    : Check if the RSA key contains 0x0000.                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_checkRsaKeyData( Crypto_70_RsaKeyType* pRsaKey )
{
    uint8 QL_70_FAR *   pKeyData;
    uint16              keyLen;
    uint16              dataIndex;
    uint16              adjVal;
 
    /* get modulus N */
    pKeyData = pRsaKey->key_n.p_adr;
    keyLen = pRsaKey->key_n.len;
    adjVal = (uint16)(keyLen % 2U);
 
    /* check modulus N */
    for ( dataIndex=(uint16)0U; dataIndex<(keyLen+adjVal); dataIndex+=(uint16)2U ) {
        if ( 0x0000U == *(uint16*)((void*)&pKeyData[dataIndex]) ) {
            return E_NOT_OK;
        }
    }
 
    /* get public exponent e or private exponent d */
    pKeyData = pRsaKey->key_ed.p_adr;
    keyLen = pRsaKey->key_ed.len;
    adjVal = (uint16)(keyLen % 2U);
 
    /* check public exponent e or private exponent d */
    for ( dataIndex=(uint16)0U; dataIndex<(keyLen+adjVal); dataIndex+=(uint16)2U ) {
        if ( 0x0000U == *(uint16*)((void*)&pKeyData[dataIndex]) ) {
            return E_NOT_OK;
        }
    }
 
    return E_OK;
}
#endif /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_initQueue                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    :                                                              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
static void crypto_initQueue( void )
{
    uint32_least    queueCnt;
 
    /* initialize queue */
    Crypto_AsyncQueue.size = 0U;
    for ( queueCnt=0U; queueCnt<CRYPTO_70_QUEUE_SIZE; queueCnt++ ) {
        Crypto_AsyncQueue.queue[queueCnt] = 0U;
        Crypto_AsyncQueue.priorities[queueCnt] = 0U;
        Crypto_QueuedJobs[queueCnt] = NULL_PTR;
    }
}
#endif  /* #if ( 0U == CRYPTO_70_SIZE_OF_QUEUE ) */
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_execQueueing                                          */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_BUSY                                             */
/*                  CRYPTO_E_KEY_NOT_VALID                                    */
/* Contents    : This function execute queueing operation.                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_execQueueing( Crypto_JobType* job )
{
    Std_ReturnType  retValue;
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
    uint8_least     jobCnt;
    uint8_least     queueCnt;
#endif  /* #if ( 0U != CRYPTO_70_SIZE_OF_QUEUE ) */
 
    if ( ( CRYPTO_JOBSTATE_ACTIVE == Crypto_ActiveJob->state )
      && ( CRYPTO_OPERATIONMODE_START == ( CRYPTO_OPERATIONMODE_START & job->PrimitiveInputOutput.mode ) ) ) {
        /* [SWS_Crypto_00020] : If Crypto_ProcessJob() is called while in "Idle" or "Active" state
         * and with the operation mode "START", the previous request shall be cancelled. That means,
         * that all previously buffered data for this job shall be reset, and the job shall switch
         * to "Active" state and process the new one.
         */
        /* processing service check */
        if ( Crypto_ActiveJob->jobPrimitiveInfo->primitiveInfo->service
          == job->jobPrimitiveInfo->primitiveInfo->service ) {
            crypto_memCopy( (const uint8*)&( job->PrimitiveInputOutput ),
                            (uint8*)&( Crypto_ActiveJob->PrimitiveInputOutput ),
                            (uint32)sizeof( Crypto_JobPrimitiveInputOutputType ) );
        }
        retValue = E_OK;
    } else {
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
        /* exclusive interval start */
        SchM_Enter_Crypto_QueueOperation();
 
        /* Is queue full? */
        if ( CRYPTO_70_QUEUE_SIZE <= Crypto_AsyncQueue.size ) {
            /* [SWS_Crypto_00032] : If Crypto_ProcessJob() is called and the queue is full, the function
             * shall return with CRYPTO_E_BUSY.
             */
            retValue = CRYPTO_E_BUSY;
        } else {
            /* check the same service request in job array */
            for ( jobCnt=0U; jobCnt<CRYPTO_70_QUEUE_SIZE; jobCnt++ ) {
                if ( job->jobPrimitiveInfo->primitiveInfo->service
                  == Crypto_QueuedJobs[jobCnt]->jobPrimitiveInfo->primitiveInfo->service ) {
                    /* check the same service in queue */
                    for ( queueCnt=0U; queueCnt<Crypto_AsyncQueue.size; queueCnt++ ) {
                        if ( jobCnt == Crypto_AsyncQueue.queue[queueCnt] ) {
                            crypto_deleteQueue( (uint8)jobCnt );
                            break;  /* break the loop */
                        }
                    }
                    break;  /* break the loop */
                }
            }
 
            /* [SWS_Crypto_00033] : If Crypto_ProcessJob() is called with asynchronous job processing
             * and the queue is not full, but the Crypto Driver Object is busy and if the job has the
             * operation mode "START", the Crypto Driver Object shall put the job into the queue and
             * return E_OK.*/
            crypto_enqueue( job );
 
            retValue = E_OK;
        }
 
        /* exclusive interval end */
        SchM_Exit_Crypto_QueueOperation();
#else
        /* Crypto driver has no queue */
        retValue = E_NOT_OK;
#endif  /* #if ( 0U != CRYPTO_70_SIZE_OF_QUEUE ) */
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_execService                                           */
/* Param       : (in) job                                                     */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/*                  CRYPTO_E_BUSY                                             */
/*                  CRYPTO_E_KEY_NOT_VALID                                    */
/*                  CRYPTO_E_KEY_SIZE_MISMATCH                                */
/*                  CRYPTO_E_KEY_NOT_AVAILABLE                                */
/*                  CRYPTO_E_KEY_EMPTY                                        */
/*                  CRYPTO_E_ENTROPY_EXHAUSTED                                */
/*                  CRYPTO_E_JOB_CANCELED                                     */
/*                  CRYPTO_CUSTOM_ERROR                                       */
/* Contents    : This function execute service operation.                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_execService( Crypto_JobType* job )
{
    Std_ReturnType                              retValue = E_NOT_OK;
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    uint8                                       secstVal;
    uint16                                      secerVal;
    const uint8*                                seedPtr;
    uint32                                      cryptoKeyElementIndex = 0U;
    uint32                                      dataIndex;
    const Crypto_KeyType*                       pCryptoKey;
    const Crypto_KeyTypeType*                   pKeyType;
    const Crypto_KeyElementType*                pKeyElement;
    const Crypto_JobPrimitiveInputOutputType*   pActiveInOut;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
    uint32                                      cryptoKeyIndex = 0U;
    Crypto_70_RsaKeyType*                       pRsaKey = NULL_PTR;
    Crypto_JobPrimitiveInputOutputType*         pPrimitiveInOut;
    const Crypto_PrimitiveInfoType*             pPrimitiveInfo;
    Crypto_ServiceInfoType                      serviceInfo;
    Crypto_OperationModeType                    opMode;
 
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    /* cancel request check */
    secstVal = Crypto_70_HW_GetProcessStatus();
    if ( CRYPTO_70_HSM_CANCEL_REQ == (CRYPTO_70_HSM_CANCEL_REQ & secstVal) ) {
        /* cancel request clear */
        secstVal = Crypto_70_HW_ClearProcessStatus( CRYPTO_70_HSM_CANCEL_REQ );
        Crypto_CancelReq = FALSE;
 
        if ( CRYPTO_70_HSM_CANCEL_REQ == (CRYPTO_70_HSM_CANCEL_REQ & secstVal) ) {
            return E_NOT_OK;
        }
    }
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
    Crypto_ActiveJob = job;
    pPrimitiveInOut = &Crypto_ActiveJob->PrimitiveInputOutput;
    pPrimitiveInfo = Crypto_ActiveJob->jobPrimitiveInfo->primitiveInfo;
    serviceInfo = pPrimitiveInfo->service;
    opMode = pPrimitiveInOut->mode;
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    pActiveInOut = &Crypto_ActiveJob->PrimitiveInputOutput;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
    /* [SWS_Crypto_00017][SWS_Crypto_00018][SWS_Crypto_00020] */
    if ( CRYPTO_OPERATIONMODE_START == (CRYPTO_OPERATIONMODE_START & opMode) ) {
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
        /* In the case of AES-CBC, perform the initialization process for the IV. */
        if ( ( CRYPTO_ALGOFAM_AES == pPrimitiveInfo->algorithm.family )
          && ( CRYPTO_ALGOMODE_CBC == pPrimitiveInfo->algorithm.mode ) ) {
            /* cryptoKeyId check */
            retValue = crypto_chkCryptoKeyId( Crypto_ActiveJob->cryptoKeyId, &cryptoKeyIndex );
            if ( E_OK == retValue ) {
                pCryptoKey = &s_CryptoKeysCfgPtr->CryptoKey[cryptoKeyIndex];
 
                /* keyElementId check */
                retValue = crypto_chkElementId( CRYPTO_KE_CIPHER_IV, pCryptoKey, &cryptoKeyElementIndex );
                if ( E_OK == retValue ) {
                    pKeyType = pCryptoKey->CryptoKeyTypeRef;
                    pKeyElement = &pKeyType->CryptoKeyElementRef[cryptoKeyElementIndex];
                    /* Initialize the IV with the value held in the key element. */
                    crypto_memCopy( ( const uint8* )pKeyElement->CryptoKeyElementInitValue,
                                    &Crypto_KeyInfo[cryptoKeyIndex].aesCbcIV[0],
                                    CRYPTO_70_CBC_IV_LENGTH );
                } else {
                    /* There is no key element corresponding to CRYPTO_KE_CIPHER_IV. */
                    return ( CRYPTO_E_KEY_NOT_AVAILABLE );
                }
            } else {
                /* It has already been error-checked within crypto_encryptErrorCheck() or */
                /* crypto_decryptErrorCheck(), but it will be implemented as a precaution. */
                return ( CRYPTO_E_KEY_NOT_AVAILABLE );
            }
        }
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
 
        Crypto_ActiveJob->state = CRYPTO_JOBSTATE_ACTIVE;
        retValue = E_OK;
    }
 
    if ( CRYPTO_OPERATIONMODE_UPDATE == (CRYPTO_OPERATIONMODE_UPDATE & opMode) ) {
        switch( serviceInfo ) {
#if ( TRUE == CRYPTO_70_HASH_ENABLE )
        case CRYPTO_HASH:
            retValue = Crypto_70_HW_Hash( Crypto_ActiveJob );
            break;
#endif  /* #if ( TRUE == CRYPTO_70_HASH_ENABLE ) */
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
        case CRYPTO_MACGENERATE:
            retValue = Crypto_70_HW_MacGenerate( Crypto_ActiveJob );
            break;
        case CRYPTO_MACVERIFY:
            retValue = Crypto_70_HW_MacVerify( Crypto_ActiveJob );
            break;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
        case CRYPTO_ENCRYPT:
            /* Algorithm family check */
            if ( CRYPTO_ALGOFAM_AES == pPrimitiveInfo->algorithm.family ) {
                /* If AES is specified as the algorithm family, verify the crypto key ID. */
                retValue = crypto_chkCryptoKeyId( Crypto_ActiveJob->cryptoKeyId, &cryptoKeyIndex );
            }
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
            else if ( CRYPTO_ALGOFAM_RSA == pPrimitiveInfo->algorithm.family ) {
                /* If RSA is specified as the algorithm family, get the RSA key. */
                retValue = crypto_getRsaKey( Crypto_ActiveJob, &pRsaKey );
            }
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
            else {
                retValue = E_NOT_OK;
            }
 
            if ( E_OK == retValue ) {
                retValue = Crypto_70_HW_Encrypt( Crypto_ActiveJob,
                                                 &Crypto_KeyInfo[cryptoKeyIndex].aesCbcIV[0],
                                                 pRsaKey );
 
                if ( E_OK == retValue ) {
                    if ( ( CRYPTO_ALGOFAM_AES == pPrimitiveInfo->algorithm.family )
                      && ( CRYPTO_ALGOMODE_CBC == pPrimitiveInfo->algorithm.mode )
                      && ( CRYPTO_OPERATIONMODE_FINISH
                        != ( CRYPTO_OPERATIONMODE_FINISH & opMode) ) ) {
                        dataIndex = pPrimitiveInOut->inputLength - CRYPTO_70_AES_BLOCK_SIZE;
                        crypto_memCopy( &pPrimitiveInOut->outputPtr[dataIndex],
                                        &Crypto_KeyInfo[cryptoKeyIndex].aesCbcIV[0],
                                        CRYPTO_70_AES_BLOCK_SIZE );
                    }
                }
            }
            break;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
        case CRYPTO_DECRYPT:
            /* Algorithm family check */
#if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) && ( TRUE == CRYPTO_70_RSA_ENABLE ) )
            if ( CRYPTO_ALGOFAM_AES == pPrimitiveInfo->algorithm.family ) {
                /* If AES is specified as the algorithm family, verify the crypto key ID. */
                retValue = crypto_chkCryptoKeyId( Crypto_ActiveJob->cryptoKeyId, &cryptoKeyIndex );
            } else if (CRYPTO_ALGOFAM_RSA == pPrimitiveInfo->algorithm.family ) {
                /* If RSA is specified as the algorithm family, get the RSA key. */
                retValue = crypto_getRsaKey( Crypto_ActiveJob, &pRsaKey );
            } else {
                retValue = E_NOT_OK;
            }
#elif ( TRUE == CRYPTO_70_AESEA_ENABLE )
            if ( CRYPTO_ALGOFAM_AES == pPrimitiveInfo->algorithm.family ) {
                /* If AES is specified as the algorithm family, verify the crypto key ID. */
                retValue = crypto_chkCryptoKeyId( Crypto_ActiveJob->cryptoKeyId, &cryptoKeyIndex );
            } else {
                retValue = E_NOT_OK;
            }
#elif ( TRUE == CRYPTO_70_RSA_ENABLE )
            if (CRYPTO_ALGOFAM_RSA == pPrimitiveInfo->algorithm.family ) {
                /* If RSA is specified as the algorithm family, get the RSA key. */
                retValue = crypto_getRsaKey( Crypto_ActiveJob, &pRsaKey );
            } else {
                retValue = E_NOT_OK;
            }
#else
            retValue = E_NOT_OK;
#endif  /*  #if ( ( TRUE == CRYPTO_70_AESEA_ENABLE ) && ( TRUE == CRYPTO_70_RSA_ENABLE ) ) */
 
            if ( E_OK == retValue ) {
                retValue = Crypto_70_HW_Decrypt( Crypto_ActiveJob,
                                                 &Crypto_KeyInfo[cryptoKeyIndex].aesCbcIV[0],
                                                 pRsaKey );
 
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
                if ( E_OK == retValue ) {
                    if ( ( CRYPTO_ALGOFAM_AES == pPrimitiveInfo->algorithm.family )
                      && ( CRYPTO_ALGOMODE_CBC == pPrimitiveInfo->algorithm.mode )
                      && ( CRYPTO_OPERATIONMODE_FINISH
                        != ( CRYPTO_OPERATIONMODE_FINISH & opMode) ) ) {
                        dataIndex = pPrimitiveInOut->inputLength - CRYPTO_70_AES_BLOCK_SIZE;
                        crypto_memCopy( &pPrimitiveInOut->inputPtr[dataIndex],
                                        &Crypto_KeyInfo[cryptoKeyIndex].aesCbcIV[0],
                                        CRYPTO_70_AES_BLOCK_SIZE );
                    }
                }
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
            }
            break;
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
        case CRYPTO_SIGNATUREGENERATE:
            retValue = crypto_getRsaKey( Crypto_ActiveJob, &pRsaKey );
            if ( E_OK == retValue ) {
                retValue = Crypto_70_HW_SignatureGenerate( Crypto_ActiveJob, pRsaKey );
            }
            break;
        case CRYPTO_SIGNATUREVERIFY:
            retValue = crypto_getRsaKey( Crypto_ActiveJob, &pRsaKey );
            if ( E_OK == retValue ) {
                retValue = Crypto_70_HW_SignatureVerify( Crypto_ActiveJob, pRsaKey );
            }
            break;
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
        case CRYPTO_RANDOMGENERATE:
            retValue = Crypto_70_HW_RandomGenerate( Crypto_ActiveJob );
            break;
        case CRYPTO_RANDOMSEED:
            seedPtr = (uint8 QL_70_NEAR *)pActiveInOut->inputPtr;
            retValue = Crypto_70_HW_RandomSeedExtend( seedPtr );
            break;
#endif  /* #if ( TRUE == CRYPTO_70_AESEA_ENABLE ) */
        case CRYPTO_CUSTOM_SERVICE:
            retValue = Crypto_Callout_CustomService( Crypto_ActiveJob, 0U, 0U, 0U, 0U, 0U, NULL_PTR, 0U,
                                                  NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR );
            break;
        case CRYPTO_KEYSETVALID:
            retValue = crypto_chkCryptoKeyId( Crypto_ActiveJob->cryptoKeyId, &cryptoKeyIndex );
            if ( E_OK == retValue ) {
                Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus = CRYPTO_KEYSTATUS_VALID;
            }
            break;
        case CRYPTO_KEYSETINVALID:
            retValue = crypto_chkCryptoKeyId( Crypto_ActiveJob->cryptoKeyId, &cryptoKeyIndex );
            if ( E_OK == retValue ) {
                Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus = CRYPTO_KEYSTATUS_INVALID;
            }
            break;
        default:
            /* Unsupported services */
            retValue = E_NOT_OK;
            break;
        }
    }
 
    /* [SWS_Crypto_00023] */
    if ( ( CRYPTO_OPERATIONMODE_FINISH == (CRYPTO_OPERATIONMODE_FINISH & opMode) ) ) {
#if ( TRUE == CRYPTO_70_HASH_ENABLE )
        if ( CRYPTO_HASH == serviceInfo ) {
            retValue = Crypto_70_HW_Hash( Crypto_ActiveJob );
        } else {
            /* If CRYPTO_OPERATIONMODE_UPDATE is not included in the operation mode, */
            /* update the return value. */
            if ( CRYPTO_OPERATIONMODE_UPDATE != (CRYPTO_OPERATIONMODE_UPDATE & opMode) ) {
                retValue = E_OK;
            }
        }
#else
        /* If CRYPTO_OPERATIONMODE_UPDATE is not included in the operation mode, */
        /* update the return value. */
        if ( CRYPTO_OPERATIONMODE_UPDATE != (CRYPTO_OPERATIONMODE_UPDATE & opMode) ) {
            retValue = E_OK;
        }
#endif  /* #if ( TRUE == CRYPTO_70_HASH_ENABLE ) */
    }
 
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
    /* SECER check */
    secerVal = Crypto_70_HW_GetErrorStatus();
    if ( ( E_OK == retValue ) && ( 0U != secerVal ) ) {
        if ( CRYPTO_70_HSM_KEYNOTAVAILABLE == ( CRYPTO_70_HSM_KEYNOTAVAILABLE & secerVal ) ) {
            retValue = CRYPTO_E_KEY_NOT_AVAILABLE;
        } else if ( CRYPTO_70_HSM_KEY_INVALID == ( CRYPTO_70_HSM_KEY_INVALID & secerVal ) ) {
            retValue = CRYPTO_E_KEY_NOT_VALID;
        } else if ( CRYPTO_70_HSM_KEY_EMPTY == ( CRYPTO_70_HSM_KEY_EMPTY & secerVal ) ) {
            retValue = CRYPTO_E_KEY_EMPTY;
        } else if ( CRYPTO_70_HSM_SECER_BUSY == ( CRYPTO_70_HSM_SECER_BUSY & secerVal ) ) {
            retValue = CRYPTO_E_BUSY;
        } else {
            /* No errors. retValue = E_OK */
        }
    }
#endif
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_enqueue                                               */
/* Param       : (in) job                                                     */
/* Return      : void                                                         */
/* Contents    : This function will be queueing the job index value.          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
static void crypto_enqueue( Crypto_JobType* job)
{
    uint8_least     searchCnt;
    sint8_least     queueCnt;
    uint8           searchStart;
    uint8           emptyIndex = CRYPTO_70_QUEUE_FULL;
    const uint32    priority = job->jobInfo->jobPriority;
 
    /* find the empty index in job array */
    for ( searchCnt=0U; searchCnt<CRYPTO_70_QUEUE_SIZE; searchCnt++ ) {
        for ( queueCnt=0; queueCnt<(sint8_least)Crypto_AsyncQueue.size; queueCnt++ ) {
            if ( searchCnt == Crypto_AsyncQueue.queue[queueCnt] ) {
                break;  /* break the loop */
            }
        }
 
        if ( queueCnt == ( sint8_least )Crypto_AsyncQueue.size ) {
            /* serchCnt is not found in queue, so Crypto_QueuedJobs[serchCnt] is empty */
            emptyIndex = (uint8)searchCnt;
            break;
        }
    }
 
    if ( CRYPTO_70_QUEUE_FULL != emptyIndex ) {
        /* store the job */
        Crypto_QueuedJobs[emptyIndex] = job;
 
        /* check the job priority and find the queueing index */
        if ( 0U != Crypto_AsyncQueue.size ) {
            searchStart = Crypto_AsyncQueue.size - 1U;
            for ( queueCnt=(sint8_least)searchStart; queueCnt>=0; queueCnt-- ) {
                if ( priority > Crypto_AsyncQueue.priorities[queueCnt] ) {
                    Crypto_AsyncQueue.queue[queueCnt+1] = Crypto_AsyncQueue.queue[queueCnt];
                    Crypto_AsyncQueue.priorities[queueCnt+1] = Crypto_AsyncQueue.priorities[queueCnt];
                } else {
                    /* the priority of the queue to be inserted is the same or lower */
                    break;
                }
            }
            queueCnt++;
        }
 
 
 
        /* enqueue the job index value */
        Crypto_AsyncQueue.queue[queueCnt] = emptyIndex;
        Crypto_AsyncQueue.priorities[queueCnt] = (uint8)priority;
        Crypto_AsyncQueue.size++;
    }
}
#endif  /* #if ( 0U != CRYPTO_70_SIZE_OF_QUEUE ) */
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_dequeue                                               */
/* Param       : void                                                         */
/* Return      : uint8                                                        */
/* Contents    : This function will dequeue the job index value.              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
static uint8 crypto_dequeue( void )
{
    uint8       jobIndex = CRYPTO_70_QUEUE_EMPTY;
    uint8       replaceLimit;
    uint8_least queueCnt;
    uint8_least srcIndex;
 
    if ( 0U != Crypto_AsyncQueue.size ) {
        jobIndex = Crypto_AsyncQueue.queue[0];
        replaceLimit = Crypto_AsyncQueue.size - 1U;
 
        for ( queueCnt=0U; queueCnt<(uint8_least)replaceLimit; queueCnt++ ) {
            srcIndex = queueCnt + 1U;
            Crypto_AsyncQueue.queue[queueCnt] = Crypto_AsyncQueue.queue[srcIndex];
            Crypto_AsyncQueue.priorities[queueCnt] = Crypto_AsyncQueue.priorities[srcIndex];
        }
        Crypto_AsyncQueue.size--;
    }
 
    return ( jobIndex );
}
#endif  /* #if ( 0U != CRYPTO_70_SIZE_OF_QUEUE ) */
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_deleteQueue                                           */
/* Param       : (in) deleteIndex                                             */
/* Return      : void                                                         */
/* Contents    : This function will delete specified queue.                   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( 0U != CRYPTO_70_SIZE_OF_QUEUE )
static void crypto_deleteQueue( uint8 deleteIndex )
{
    uint8           replaceLimit;
    uint8_least     srcIndex;
    uint8_least     queueCnt;
    uint8_least     justifyCnt;
 
    if ( 0U != Crypto_AsyncQueue.size ) {
        replaceLimit = Crypto_AsyncQueue.size - 1U;
 
        for ( queueCnt=0U; queueCnt<Crypto_AsyncQueue.size; queueCnt++ ) {
            if ( Crypto_AsyncQueue.queue[queueCnt] == deleteIndex ) {
                for ( justifyCnt=queueCnt; justifyCnt<(uint8_least)replaceLimit; justifyCnt++ ) {
                    srcIndex = justifyCnt + 1U;
                    Crypto_AsyncQueue.queue[justifyCnt] = Crypto_AsyncQueue.queue[srcIndex];
                    Crypto_AsyncQueue.priorities[justifyCnt] = Crypto_AsyncQueue.priorities[srcIndex];
                }
                Crypto_AsyncQueue.size--;
                break;  /* break the loop */
            }
        }
    }
}
#endif  /* #if ( 0U != CRYPTO_70_SIZE_OF_QUEUE ) */
 
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_getRsaKey                                             */
/* Param       : (in) job                                                     */
/*               (out) pRsaKey                                                */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  E_NOT_OK                                                  */
/* Contents    : This function will get Rsa key.                              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_getRsaKey( const Crypto_JobType* job, Crypto_70_RsaKeyType** pRsaKey )
{
    Std_ReturnType                              retValue;
    uint32                                      rsaKeyId;
    uint32_least                                rsaKeyIndex;
    uint32_least                                elementIndex;
    void*                                       keyElementPtr;
    const Crypto_KeyType*                       pCryptoKey;
    const Crypto_KeyElementType*                pKeyElement;
    const Crypto_JobRedirectionInfoType*        pRedirect;
    Crypto_InputOutputRedirectionConfigType     redirectCfg;
    const Crypto_JobPrimitiveInputOutputType*   pPrimitiveInOut;
 
    pRedirect = job->jobRedirectionInfoRef;
    redirectCfg = pRedirect->redirectionConfig;
    pPrimitiveInOut = &job->PrimitiveInputOutput;
 
    if ( CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT == (CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT & redirectCfg) ) {
        /* key length check */
        if ( CRYPTO_70_RSA_LENGTH == pPrimitiveInOut->secondaryInputLength ) {
            /* key element is stored in secondary input */
            *pRsaKey = ( Crypto_70_RsaKeyType* ) ( ( void* ) pPrimitiveInOut->secondaryInputPtr );
            retValue = E_OK;
        } else {
            retValue = E_NOT_OK;
        }
    } else if ( CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT == (CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT & redirectCfg) ) {
        /* key length check */
        if ( CRYPTO_70_RSA_LENGTH == pPrimitiveInOut->tertiaryInputLength ) {
            /* key element is stored in tertiary input */
            *pRsaKey = ( Crypto_70_RsaKeyType* ) ( ( void* ) pPrimitiveInOut->tertiaryInputPtr );
            retValue = E_OK;
        } else {
            retValue = E_NOT_OK;
        }
    } else {
        /* key element is specified by inputKeyElementId */
        rsaKeyId = job->cryptoKeyId;
 
        /* check crypto key ID */
        retValue = crypto_chkCryptoKeyId( rsaKeyId, &rsaKeyIndex );
        if ( E_OK == retValue ) {
            /* check key element ID */
            pCryptoKey = &s_CryptoKeysCfgPtr->CryptoKey[rsaKeyIndex];
            retValue = crypto_chkElementId( CRYPTO_KE_CIPHER_KEY, pCryptoKey, &elementIndex );
            if ( E_OK == retValue ) {
                /* get RSA key */
                pKeyElement = &(pCryptoKey->CryptoKeyTypeRef->CryptoKeyElementRef[elementIndex]);
                keyElementPtr = pKeyElement->CryptoKeyElementValue;
                *pRsaKey = ( Crypto_70_RsaKeyType* ) keyElementPtr;
            }
        }
    }
 
    return ( retValue );
}
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */
 
#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
 
/* EOF Crypto.c ******************************************************************/
 
 