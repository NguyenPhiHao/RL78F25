/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Fls.c                                                        */
/* Version     : v1.00.01                                                     */
/* Contents    : This document specifies the functionality, API and the       */
/*               configuration of the AUTOSAR Basic Software module Flash     */
/*               Driver.                                                      */
/*               This specification is applicable to drivers for both         */
/*               internal and external flash memory.                          */
/*               The flash driver provides services for reading, writing and  */
/*               erasing flash memory and a configuration interface for       */
/*               setting / resetting the write / erase protection if          */
/*               supported by the underlying hardware.                        */
/*               In application mode of the ECU, the flash driver is only to  */
/*               be used by the Flash EEPROM emulation module for writing     */
/*               data. It is not intended to write program code to flash      */
/*               memory in application mode. This shall be done in boot mode  */
/*               which is out of scope of AUTOSAR.                            */
/*               A driver for an internal flash memory accesses the           */
/*               microcontroller hardware directly and is located in the      */
/*               Microcontroller Abstraction Layer. An external flash memory  */
/*               is usually connected via the microcontroller's data /        */
/*               address busses (memory mapped access), the flash driver then */
/*               uses the handlers / drivers for those busses to access the   */
/*               external flash memory device. The driver for an external     */
/*               flash memory device is located in the ECU Abstraction Layer. */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Flash Driver                                              */
/* R22-11                                                                     */
/******************************************************************************/
 
/*----------------------------------------------------------------------------*/
/*Expanded function                                                           */
/*----------------------------------------------------------------------------*/
/* #pragma sfr     SFR(specific flock register)field application declaration */
/* #pragma NOP     CPU control order (NOP )application declaration */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Fls.h"
#include "Det.h"
#include "SchM_Fls.h"
#include "Fee.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define FLS_70_VENDOR_ID_C                   ( 70U )
#define FLS_70_MODULE_ID_C                   ( 92U )
 
#define FLS_70_AR_RELEASE_MAJOR_VERSION_C    ( 22U )
#define FLS_70_AR_RELEASE_MINOR_VERSION_C    ( 11U )
#define FLS_70_AR_RELEASE_REVISION_VERSION_C ( 0U )
 
#define FLS_70_SW_MAJOR_VERSION_C            ( 1U )
#define FLS_70_SW_MINOR_VERSION_C            ( 0U )
#define FLS_70_SW_PATCH_VERSION_C            ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/* Fls.h version check start */
 
#if ( FLS_70_VENDOR_ID_C != FLS_VENDOR_ID )
    #error "VENDOR ID for Fls.c and Fls.h are different"
#endif
 
#if ( FLS_70_MODULE_ID_C != FLS_MODULE_ID )
    #error "MODULE ID for Fls.c and Fls.h are different"
#endif
 
#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION ) || \
      ( FLS_70_AR_RELEASE_REVISION_VERSION_C != FLS_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Fls.c and Fls.h are different"
#endif
 
#if ( ( FLS_70_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION ) || \
      ( FLS_70_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION ) || \
      ( FLS_70_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Fls.c and Fls.h are different"
#endif
 
/* Fls.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Det.h version check start */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Fls.c and Det.h are different"
#endif
#endif  /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Fls.h version check start */
 
#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_C != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_C != RTE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Fls.c and SchM_Fls.h are different"
#endif
 
/* SchM_Fls.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Fee.h version check start */
 
#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_C != FEE_AR_RELEASE_MAJOR_VERSION ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_C != FEE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Fls.c and Fee.h are different"
#endif
 
/* Fee.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
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
#define FLS_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Fls_MemMap.h"
 
/* Pointer to config data */
static const Fls_ConfigType* s_FlsConfig = NULL_PTR;
 
/* [SWS_Fls_00248][SWS_Fls_00323] Fls module status */
MemIf_StatusType Fls_Status = MEMIF_UNINIT;
 
/* [SWS_Fls_00248] Fls job result */
MemIf_JobResultType Fls_JobResult = MEMIF_JOB_OK;
MemIf_ModeType Fls_Mode = MEMIF_MODE_SLOW;
 
/* Job parameter buffer */
static Fls_70_ControlType s_FlsJobControl = { 0U };
static Fls_LengthType s_ReadSize = 0U;
static Fls_LengthType s_WriteSize = 0U;
static Fls_LengthType s_LengthCount = 0U;
static uint8 s_FlsNumberOfErase = 0U;
 
/* [SWS_Fls_00272] Count number of time to check timeout */
#if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE )
static uint16 s_Fls_TimeoutCounter = 0U;
#endif /* #if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE ) */
 
#define FLS_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Fls_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* inline function prototype declarations                                     */
/*----------------------------------------------------------------------------*/
 
LOCAL_INLINE void fls_70_Initialisation( void );
 
#if ( FLS_DEV_ERROR_DETECT != FALSE )
LOCAL_INLINE uint8 fls_70_CheckFlashAddress( const Fls_AddressType address );
LOCAL_INLINE uint8 fls_70_CheckFlashAddressLength( const Fls_AddressType address,
                                                   const Fls_LengthType length, uint8 job );
#endif /* FLS_DEV_ERROR_DETECT != FALSE */
 
LOCAL_INLINE void fls_70_ExecuteReportErr( void );
LOCAL_INLINE void fls_70_Execute( Fls_70_HW_ExecuteStatusType enRetStatus );
LOCAL_INLINE Fls_70_HW_ExecuteStatusType fls_70_ClassifyError
                                                ( fls_70_HW_CheckCFDFSeqEndStatusType enRStatus );
#if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE )
LOCAL_INLINE void fls_70_TimeOutCheckAndProcessing ( void );
#endif /* #if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE ) */
 
#define FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*----------------------------------------------------------------------------*/
/* inline functions                                                           */
/*----------------------------------------------------------------------------*/
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_Initialisation                                        */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Software initialisation part of Fls_Init                     */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/*----------------------------------------------------------------------------*/
LOCAL_INLINE void fls_70_Initialisation( void )
{
    /* [SWS_Fls_00323] Set job status */
    Fls_Status = MEMIF_IDLE;
    /* [SWS_Fls_00324] Set job result */
    Fls_JobResult = MEMIF_JOB_OK;
    /* [SWS_Fls_00086] Initialize global variables */
    /* Get default Mode */
    Fls_Mode = s_FlsConfig->FlsConfigSet.FlsDefaultMode;
    /* Mode by setting access size */
    if ( MEMIF_MODE_SLOW == Fls_Mode ) {
        s_ReadSize = s_FlsConfig->FlsConfigSet.FlsMaxReadNormalMode;
        s_WriteSize = s_FlsConfig->FlsConfigSet.FlsMaxWriteNormalMode;
    } else {
        s_ReadSize = s_FlsConfig->FlsConfigSet.FlsMaxReadFastMode;
        s_WriteSize = s_FlsConfig->FlsConfigSet.FlsMaxWriteFastMode;
    }
    /* Initialize job parameter */
    s_FlsJobControl.FlsJobType = FLS_70_JOB_NONE;
    s_FlsJobControl.FlsBlockNumber = 0U;
    s_FlsJobControl.FlsAddress = 0U;
    s_FlsJobControl.FlsLength = 0U;
    s_FlsJobControl.DataAddress = NULL_PTR;
    s_FlsJobControl.FlsExecuteFlg = FALSE;
    s_FlsJobControl.FlsForceStop = FALSE;
    s_FlsNumberOfErase = 0U;
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_CheckFlashAddress                                     */
/* Param       : (in) address        Address offset to flash memory area      */
/* Return      : uint8                                                        */
/*               FLS_70_E_OK : address is available                           */
/*               FLS_E_PARAM_ADDRESS : not available                          */
/* Contents    : check flash address                                          */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/*----------------------------------------------------------------------------*/
#if ( FLS_DEV_ERROR_DETECT != FALSE )
LOCAL_INLINE uint8 fls_70_CheckFlashAddress( const Fls_AddressType address )
{
    uint8 lucReturnCode = FLS_E_PARAM_ADDRESS; /* Return code */
 
    /* Check if the start address is aligned to a flash boundary and lies
     * within the specified lower and upper flash address boundaries.
     */
    if ( ( FLS_BASE_ADDRESS + address ) < ( FLS_BASE_ADDRESS + FLS_TOTAL_SIZE ) ) {
        /* Flash address is available */
        lucReturnCode = FLS_70_E_OK;
    }
 
    return lucReturnCode;
}
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_CheckFlashAddressLength                               */
/* Param       : (in)  address        Address offset to flash memory area     */
/*               (in)  length         Length size                             */
/*               (in)  job            Job type                                */
/* Return      : uint8                                                        */
/*               FLS_70_E_OK : Address length is available                    */
/*               FLS_E_PARAM_LENGTH : not available                           */
/* Contents    : Check flash address and length                               */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/*----------------------------------------------------------------------------*/
#if ( FLS_DEV_ERROR_DETECT != FALSE )
LOCAL_INLINE uint8 fls_70_CheckFlashAddressLength( const Fls_AddressType address,
                                                   const Fls_LengthType length,
                                                   uint8 job )
{
    uint8            lucReturnCode = FLS_E_PARAM_LENGTH; /* Return code */
    Fls_AddressType  address_physical; /* Convert address input into physical address */
 
    address_physical = ( address + FLS_BASE_ADDRESS + length );
 
    /* Check if the length is greater than 0 and that the end address (start address + length)
     * lies within the specified upper flash address boundary and the end address aligned to a
     * flash sector boundary
     */
    if ( ( 0x00UL < length )
     && ( address_physical  <= ( FLS_BASE_ADDRESS + FLS_TOTAL_SIZE ) ) ) {
        if ( ( FLS_70_JOB_ERASE != job )
         || ( ( Fls_AddressType ) FLS_70_ZERO == ( address_physical &
                                                 ( FLS_70_NUMBER_OF_SECTORS - FLS_70_ONE ) ) ) ) {
            /* Flash address and length is available with Erase job */
            lucReturnCode = FLS_70_E_OK;
        }
    }
 
    return lucReturnCode;
}
#endif /* FLS_DEV_ERROR_DETECT != FALSE */
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_ExecuteReportErr                                      */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Report errors for fls_70_Execute                             */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/*----------------------------------------------------------------------------*/
LOCAL_INLINE void fls_70_ExecuteReportErr( void )
{
    /* [SWS_Fls_00346] Set job status */
    Fls_Status = MEMIF_IDLE;
    s_FlsJobControl.FlsExecuteFlg = FALSE;
    /* Notice error to FEE */
    if ( NULL_PTR != s_FlsConfig->FlsConfigSet.FlsJobErrorNotification ) {
        s_FlsConfig->FlsConfigSet.FlsJobErrorNotification();
    }
 
    /* Fls job type */
    switch ( s_FlsJobControl.FlsJobType ) {
 
    /* Check Erase Verification is enabled */
    case FLS_70_JOB_ERASE :
        if ( FLS_70_E_OK != g_Fls_CheckErase ) {
            /* [SWS_Fls_00104][SWS_Fls_00315] */
            /* Report error FLS_E_ERASE_FAILED when a flash erase job fails */
            ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                    ( uint8 ) FLS_MAINFUNCTION_ID, ( uint8 ) FLS_E_ERASE_FAILED );
        } else {
#if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE )
            if ( FLS_70_E_OK != g_Fls_VerifyErase ) {
                /* [SWS_Fls_00022] Report error FLS_E_VERIFY_ERASE_FAILED */
                ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID,
                                        ( uint8 ) FLS_70_INSTANCE_ID, ( uint8 ) FLS_MAINFUNCTION_ID,
                                        ( uint8 ) FLS_E_VERIFY_ERASE_FAILED );
            } else {
                /* Do Nothing */
            }
#endif /* #if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE ) */
        }
        break;
 
    case FLS_70_JOB_WRITE :
#if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE )
        if ( FLS_70_E_OK != g_Fls_VerifyErase ) {
            /* [SWS_Fls_00055] Report error FLS_E_VERIFY_ERASE_FAILED */
            ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                             ( uint8 ) FLS_MAINFUNCTION_ID,
                                             ( uint8 ) FLS_E_VERIFY_ERASE_FAILED );
        } else {
#endif /* #if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE ) */
            if ( FLS_70_E_OK != g_Fls_CheckWrite ) {
                /* [SWS_Fls_00105][SWS_Fls_00316] */
                /* Report error FLS_E_WRITE_FAILED when a flash write job fails */
                ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID,
                                                 ( uint8 ) FLS_70_INSTANCE_ID,
                                                 ( uint8 ) FLS_MAINFUNCTION_ID,
                                                 ( uint8 ) FLS_E_WRITE_FAILED );
            }
#if ( FLS_WRITE_VERIFICATION_ENABLED != FALSE )
            else if ( FLS_70_E_OK != g_Fls_VerifyWrite ) {
                /* [SWS_Fls_00056] Report error FLS_E_VERIFY_WRITE_FAILED */
                ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID,
                                                 ( uint8 ) FLS_70_INSTANCE_ID,
                                                 ( uint8 ) FLS_MAINFUNCTION_ID,
                                                 ( uint8 ) FLS_E_VERIFY_WRITE_FAILED );
            } else {
                    /* Do nothing */
            }
#endif /* #if ( FLS_WRITE_VERIFICATION_ENABLED != FALSE ) */
#if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE )
        }
#endif /* #if ( ( FLS_ERASE_VERIFICATION_ENABLED != FALSE ) || \
                ( FLS_WRITE_VERIFICATION_ENABLED != FALSE ) ) */
        break;
 
    case FLS_70_JOB_READ :
    case FLS_70_JOB_COMPARE :
    case FLS_70_JOB_BLANKCHECK:
    default :
        /* No process */
        break;
    }
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_Execute                                               */
/* Param       : (in) enRetStatus   Status from Hardware                      */
/* Return      : void                                                         */
/* Contents    : Check Job complete, handle if any error and notify to FEE    */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/*----------------------------------------------------------------------------*/
LOCAL_INLINE void fls_70_Execute( Fls_70_HW_ExecuteStatusType enRetStatus )
{
    uint8 job_complete_flag = FALSE; /* Job complete check flag */
 
    switch( s_FlsJobControl.FlsJobType ) {
    case FLS_70_JOB_WRITE :
        /* Next acsess area set */
        if ( ( uint32 )FLS_70_ZERO == s_LengthCount ) {
            /* Complete write command */
            job_complete_flag = TRUE;
        } else if ( s_LengthCount <= s_WriteSize ) {
            s_FlsJobControl.FlsLength = s_LengthCount;
            s_FlsJobControl.FlsAddress = s_FlsJobControl.FlsAddress + s_WriteSize;
            s_FlsJobControl.DataAddress = &( s_FlsJobControl.DataAddress[ s_WriteSize ] );
            s_LengthCount = 0U;
        } else {
            s_FlsJobControl.FlsLength = s_WriteSize;
            s_FlsJobControl.FlsAddress = s_FlsJobControl.FlsAddress + s_WriteSize;
            s_FlsJobControl.DataAddress = &( s_FlsJobControl.DataAddress[ s_WriteSize ] );
            s_LengthCount = s_LengthCount - s_WriteSize;
        }
        break;
 
    case FLS_70_JOB_READ :
        /* PFDF_Handler () is not required in the case of READ */
        /* Next acsess area set */
        if ( ( uint32 )FLS_70_ZERO == s_LengthCount ) {
            /* Complete read command */
            job_complete_flag = TRUE;
        } else if ( s_LengthCount <= s_ReadSize ) {
            s_FlsJobControl.FlsLength = s_LengthCount;
            s_FlsJobControl.FlsAddress = s_FlsJobControl.FlsAddress + s_ReadSize;
            s_FlsJobControl.DataAddress = &( s_FlsJobControl.DataAddress[ s_ReadSize ] );
            s_LengthCount = 0U;
        } else {
            s_FlsJobControl.FlsLength = s_ReadSize;
            s_FlsJobControl.FlsAddress = s_FlsJobControl.FlsAddress + s_ReadSize;
            s_FlsJobControl.DataAddress = &( s_FlsJobControl.DataAddress[ s_ReadSize ] );
            s_LengthCount = s_LengthCount - s_ReadSize;
        }
        break;
 
    case FLS_70_JOB_ERASE :
        /* Erase next block */
        if ( FLS_70_ONE == s_FlsNumberOfErase ) {
            /* Complete read command */
            job_complete_flag = TRUE;
        } else {
            /* Erase next block */
            s_FlsJobControl.FlsBlockNumber = s_FlsJobControl.FlsBlockNumber + FLS_70_ONE;
            /* Decrease number of erasing */
            s_FlsNumberOfErase = s_FlsNumberOfErase - FLS_70_ONE;
            /* Increase Address align with a block */
#if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE )
            s_FlsJobControl.FlsAddress = s_FlsJobControl.FlsAddress + FLS_70_NUMBER_OF_SECTORS;
#endif
        }
 
        break;
 
    case FLS_70_JOB_BLANKCHECK:
    case FLS_70_JOB_COMPARE :
    default :
        job_complete_flag = TRUE;
        break;
    }
    switch ( enRetStatus ) {
    case FLS_70_EXEC_OK :
        if ( FALSE != job_complete_flag ) {
            if ( MEMIF_JOB_PENDING == Fls_JobResult ) {
                /* [SWS_Fls_00345] Set job result */
                Fls_JobResult = MEMIF_JOB_OK;
            }
 
            /* Notice end to FEE */
            if ( NULL_PTR != s_FlsConfig->FlsConfigSet.FlsJobEndNotification ) {
                s_FlsConfig->FlsConfigSet.FlsJobEndNotification();
            }
 
             /* [SWS_Fls_00346] Set job status */
            s_FlsJobControl.FlsExecuteFlg = FALSE;
            Fls_Status = MEMIF_IDLE;
        }
        break;
 
    case FLS_70_EXEC_ERR_MARGIN :
        /* Update Job result */
        Fls_JobResult = MEMIF_BLOCK_INCONSISTENT;
 
        /* Report errors */
        fls_70_ExecuteReportErr();
        break;
 
    case FLS_70_EXEC_ERR_WRITE :
    case FLS_70_EXEC_ERR_ERASE :
    case FLS_70_EXEC_ERR_BLANKCHECK :
        /* Update Job result */
        Fls_JobResult = MEMIF_JOB_FAILED;
 
        /* Report errors */
        fls_70_ExecuteReportErr();
        break;
 
    case FLS_70_EXEC_ERR_PARAMETER :
    default :
        /* Do nothing */
        break;
    }
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_ClassifyError                                         */
/* Param       : (in) enRStatus   Status from Hardware                        */
/* Return      : Fls_70_HW_ExecuteStatusType                                  */
/* Contents    : Classify error from executing Jobs                           */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/*----------------------------------------------------------------------------*/
LOCAL_INLINE Fls_70_HW_ExecuteStatusType fls_70_ClassifyError
                                                ( fls_70_HW_CheckCFDFSeqEndStatusType enRStatus )
{
    Fls_70_HW_ExecuteStatusType lenReturnCode = FLS_70_EXEC_OK; /* Return code */
 
    /* Check return status */
    switch ( enRStatus )
    {
    case FLS_70_CHECKCFDFSEQEND_NULL:
        lenReturnCode = FLS_70_EXEC_ERR_PARAMETER;
        break;
 
    case FLS_70_CHECKCFDFSEQEND_ERR_ERASE:
        lenReturnCode = FLS_70_EXEC_ERR_ERASE;
        break;
 
    case FLS_70_CHECKCFDFSEQEND_ERR_MARGIN:
        lenReturnCode = FLS_70_EXEC_ERR_MARGIN;
        break;
 
    case FLS_70_CHECKCFDFSEQEND_ERR_WRITE:
        lenReturnCode = FLS_70_EXEC_ERR_WRITE;
        break;
 
    case FLS_70_CHECKCFDFSEQEND_ERR_BLANKCHECK:
        lenReturnCode = FLS_70_EXEC_ERR_BLANKCHECK;
        break;
 
    case FLS_70_CHECKCFDFSEQEND_OK:
        lenReturnCode = FLS_70_EXEC_OK;
        break;
 
    default:
        break;
    }
 
    return lenReturnCode;
}
 
#if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE )
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_TimeOutCheckAndProcessing                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Check and process Timeout                                    */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/*----------------------------------------------------------------------------*/
 
LOCAL_INLINE void fls_70_TimeOutCheckAndProcessing ( void )
{
    /* Check number of the Timeout counter */
    if ( 0U == s_Fls_TimeoutCounter ) {
        /* Cancel the ongoing job in case of Timeout */
        s_FlsJobControl.FlsJobType = FLS_70_JOB_NONE;
        s_FlsJobControl.FlsAddress = 0U;
        s_FlsJobControl.DataAddress = NULL_PTR;
        s_FlsJobControl.FlsLength = 0U;
        s_FlsJobControl.FlsExecuteFlg = FALSE;
        s_FlsJobControl.FlsBlockNumber = 0U;
        s_FlsNumberOfErase = 0U;
 
        /* Update Job result into Cancel */
        Fls_JobResult = MEMIF_JOB_CANCELED;
 
        /* Update status into IDLE */
        Fls_Status = MEMIF_IDLE;
 
        /* Report runtime error FLS_E_TIMEOUT to DET */
        ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID , ( uint8 ) FLS_70_INSTANCE_ID,
                                         ( uint8 ) FLS_MAINFUNCTION_ID, ( uint8 ) FLS_E_TIMEOUT );
    } else {
        /* Decrement the TimeOut Counter */
        s_Fls_TimeoutCounter--;
    }
}
#endif /* #if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_INIT_ID (0x00)                                           */
/* Name        : Fls_Init                                                     */
/* Param       : (in) ConfigPtr     Pointer to flash driver configuration set */
/* Return      : void                                                         */
/* Contents    : Initializes the Flash Driver                                 */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00249]                                              */
/*----------------------------------------------------------------------------*/
void Fls_Init( const Fls_ConfigType* ConfigPtr )
{
    uint8 lucCheckStatus = FLS_70_E_OK; /* Check status */
 
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
    uint8 lucRetHwStatus; /* Check hardware return status */
#endif /* ( FLS_DEV_ERROR_DETECT != FALSE ) */
 
    /* Fls module status */
    switch ( Fls_Status ) {
    case MEMIF_UNINIT :
        if ( NULL_PTR == ConfigPtr ) {
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Fls_00004][SWS_Fls_00015] Report error FLS_E_PARAM_CONFIG */
            ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                      ( uint8 ) FLS_INIT_ID, ( uint8 ) FLS_E_PARAM_CONFIG );
 
            /* Update status */
            lucCheckStatus = FLS_70_E_NOT_OK;
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        } else {
            /* [SWS_Fls_00191] Store the pointer to config data */
            s_FlsConfig = ConfigPtr;
        }
 
        /* Check status */
        if ( FLS_70_E_OK == lucCheckStatus ) {
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Fls_00014] HW initialsation */
            lucRetHwStatus = Fls_70_HW_Init();
            /* If there is no error from hardware */
            if ( FLS_70_E_OK == lucRetHwStatus ) {
                /* SW initialsation */
                fls_70_Initialisation();
            } else {
                /* Report error to DET */
                ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                          ( uint8 ) FLS_INIT_ID, ( uint8 ) FLS_70_E_PFDL_NOT_OPEN );
            }
#else
            /* [SWS_Fls_00014] HW initialisation */
            /* When DET off, Fls_70_HW_Init always return as FLS_70_E_OK.
             * Therefore, Don't need to check its return value.
             */
            ( void ) Fls_70_HW_Init();
            /* SW initialsation */
            fls_70_Initialisation();
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        }
        break;
 
    case MEMIF_BUSY :
    case MEMIF_BUSY_INTERNAL :
        /* Do Nothing */
        break;
 
    case MEMIF_IDLE :
        /* [SWS_Fls_00268] Report error FLS_E_ALREADY_INTIALIZED */
        ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                       ( uint8 ) FLS_INIT_ID, ( uint8 ) FLS_E_ALREADY_INITIALIZED );
        break;
 
    default :
        break;
    }
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_ERASE_ID (0x01)                                          */
/* Name        : Fls_Erase                                                    */
/* Param       : (in) TargetAddress Target address in flash memory. This      */
/*                                  address offset will be added to the flash */
/*                                  memory base address.                      */
/*                                  Min : 0                                   */
/*                                  Max : FLS_SIZE - 1                        */
/*               (in) Length        Number of bytes to erase                  */
/*                                  Min : 1                                   */
/*                                  Max : FLS_SIZE - TargetAddress            */
/* Return      : Std_ReturnType     E_OK : erase command has been accepted    */
/*                                  E_NOT_OK : erase command has not been     */
/*                                  accepted                                  */
/* Contents    : Erases flash sector(s).                                      */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00250]                                              */
/*----------------------------------------------------------------------------*/
Std_ReturnType Fls_Erase(
    Fls_AddressType TargetAddress, Fls_LengthType Length )
{
    Std_ReturnType  lretvalue = E_NOT_OK; /* Return value */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
    Fls_AddressType lremainder; /* Check alignment with block size */
    /* Declare variables to store DET error ID
     * FLS_70_E_OK: No DET error
     * Others: DET error ID
     * lucRetAdd stores DET error ID when checking address
     * lucRetLen stores DET error ID when checking address length
     * lucRetCheck stores the results of address and address length checking
     */
    uint8 lucRetAdd;
    uint8 lucRetLen;
    uint8 lucRetCheck = FLS_70_E_OK;
#endif /* ( FLS_DEV_ERROR_DETECT != FALSE ) */
 
    /* Fls module status */
    switch ( Fls_Status ) {
    case MEMIF_IDLE :
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        lremainder = ( ( TargetAddress + FLS_BASE_ADDRESS ) &
                        ( Fls_AddressType ) FLS_70_BLOCK_SIZE );
 
        /* [SWS_Fls_00020][SWS_Fls_00021] Argument check */
        lucRetAdd = fls_70_CheckFlashAddress( TargetAddress );
        /* Check DET error for FLS's address */
        if ( ( FLS_70_E_OK != lucRetAdd ) || ( ( Fls_AddressType ) FLS_70_ZERO != lremainder ) ) {
            /* Update DET error ID for lucRetCheck */
            lucRetCheck = FLS_E_PARAM_ADDRESS;
            ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                      ( uint8 ) FLS_ERASE_ID, FLS_E_PARAM_ADDRESS );
        } else {
            lucRetLen = fls_70_CheckFlashAddressLength( TargetAddress, Length, FLS_70_JOB_ERASE );
            /* Check DET error for FLS's address length */
            if ( FLS_70_E_OK != lucRetLen ) {
                /* Update DET error ID for lucRetCheck */
                lucRetCheck = lucRetLen;
                ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                          ( uint8 ) FLS_ERASE_ID, lucRetLen );
            } else {
                /* Do nothing */
            }
        }
 
        /* TargetAddress,Length FLS_70_E_OK */
        if ( FLS_70_E_OK == lucRetCheck ) {
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
 
            /* [SWS_Fls_00328] Set job status */
            Fls_Status = MEMIF_BUSY;
            /* [SWS_Fls_00329] Set job result */
            Fls_JobResult = MEMIF_JOB_PENDING;
 
            /* [SWS_Fls_00327][SWS_Fls_00220] Set job parameter */
            s_FlsJobControl.FlsJobType = FLS_70_JOB_ERASE;
            s_FlsJobControl.FlsAddress = TargetAddress;
            s_FlsJobControl.DataAddress = NULL_PTR;
            s_FlsJobControl.FlsLength = Length;
            s_FlsJobControl.FlsExecuteFlg = TRUE;
            s_FlsJobControl.FlsForceStop = FALSE;
            s_FlsJobControl.FlsBlockNumber = ( uint8 )( TargetAddress >> FLS_70_LEFT_SHIFT );
            s_FlsNumberOfErase = ( uint8 )( Length >> FLS_70_LEFT_SHIFT );
            s_LengthCount = 0U;
 
            /* [SWS_Fls_00330] Return OK */
            lretvalue = E_OK;
 
            /* Calculate check Erase Job timeout */
#if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE )
            s_Fls_TimeoutCounter =
                                  ( uint16 ) ( FLS_ERASE_TIMEOUT_COUNT / FLS_MAIN_FUNCTION_PERIOD );
#endif /* #if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE ) */
 
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        }
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    case MEMIF_BUSY :
    case MEMIF_BUSY_INTERNAL :
        /* [SWS_Fls_00023] Report Error FLS_E_BUSY */
        ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                         ( uint8 ) FLS_ERASE_ID, ( uint8 ) FLS_E_BUSY );
        break;
 
    case MEMIF_UNINIT :
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00065] Report error FLS_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                  ( uint8 ) FLS_ERASE_ID, ( uint8 ) FLS_E_UNINIT );
#endif /* ( FLS_DEV_ERROR_DETECT != FALSE )  */
        break;
 
    default :
        /* No process */
        break;
    }
 
    return lretvalue;
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_WRITE_ID (0x02)                                          */
/* Name        : Fls_Write                                                    */
/* Param       : (in) TargetAddress Target address in flash memory. This      */
/*                                  address offset will be added to the flash */
/*                                  memory base address.                      */
/*                                  Min : 0                                   */
/*                                  Max : FLS_SIZE - 1                        */
/*               (in) SourceAddressPtr                                        */
/*                                  Pointer to source data buffer             */
/*               (in) Length        Number of bytes to write                  */
/*                                  Min : 1                                   */
/*                                  Max : FLS_SIZE - TargetAddress            */
/* Return      : Std_ReturnType     E_OK : Erase command has been accepted    */
/*                                  E_NOT_OK : Erase command has not been     */
/*                                  accepted                                  */
/* Contents    : Writes one or more complete flash pages.                     */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00251]                                              */
/*----------------------------------------------------------------------------*/
Std_ReturnType Fls_Write(
    Fls_AddressType TargetAddress, const uint8* SourceAddressPtr, Fls_LengthType Length )
{
    Std_ReturnType lretvalue = E_NOT_OK; /* Return value */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
    /* Declare variables to store DET error ID
     * FLS_70_E_OK: No DET error
     * Others: DET error ID
     * lucRetAdd stores DET error ID when checking address
     * lucRetLen stores DET error ID when checking address length
     * lucRetCheck stores the results of address and address length checking
     */
    uint8 lucRetAdd;
    uint8 lucRetLen;
    uint8 lucRetCheck = FLS_70_E_OK;
#endif /* ( FLS_DEV_ERROR_DETECT != FALSE ) */
 
    /* Fls module status */
    switch ( Fls_Status ) {
    case MEMIF_IDLE :
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00026][SWS_Fls_00027] Argument check */
        lucRetAdd = fls_70_CheckFlashAddress( TargetAddress );
        /* Check DET error for FLS's address */
        if ( FLS_70_E_OK != lucRetAdd ) {
            /* Update DET error ID for lucRetCheck */
            lucRetCheck = lucRetAdd;
            ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                      ( uint8 ) FLS_WRITE_ID, lucRetAdd );
        } else {
            lucRetLen = fls_70_CheckFlashAddressLength( TargetAddress, Length, FLS_70_JOB_WRITE );
            /* Check DET error for FLS's address length */
            if ( FLS_70_E_OK != lucRetLen ) {
                /* Update DET error ID for lucRetCheck */
                lucRetCheck = lucRetLen;
                ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                          ( uint8 ) FLS_WRITE_ID, lucRetLen );
            } else {
                /* Do nothing */
            }
        }
 
        /* TargetAddress, Length FLS_70_E_OK */
        if ( FLS_70_E_OK == lucRetCheck ) {
            /* [SWS_Fls_00157] Null check */
            if ( NULL_PTR != SourceAddressPtr ) {
#endif  /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
                /* [SWS_Fls_00332] Set job status */
                Fls_Status = MEMIF_BUSY;
 
                /* [SWS_Fls_00333] Set job result */
                Fls_JobResult = MEMIF_JOB_PENDING;
 
                /* [SWS_Fls_00225][SWS_Fls_00331] Set job parameter */
                s_FlsJobControl.FlsJobType = FLS_70_JOB_WRITE;
                s_FlsJobControl.FlsAddress = TargetAddress;
                s_FlsJobControl.DataAddress = (uint8 *) SourceAddressPtr;
                if ( Length < s_WriteSize ) {
                    s_FlsJobControl.FlsLength = Length;
                    s_LengthCount = 0U;
                } else {
                    s_FlsJobControl.FlsLength = s_WriteSize;
                    s_LengthCount = Length - s_WriteSize;
                }
                s_FlsJobControl.FlsExecuteFlg = TRUE;
                s_FlsJobControl.FlsForceStop = FALSE;
                s_FlsJobControl.FlsBlockNumber = 0U;
                s_FlsNumberOfErase = 0U;
 
                /* [SWS_Fls_00334] Return OK */
                lretvalue = E_OK;
 
                /* Calculate check Write Job timeout */
#if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE )
                s_Fls_TimeoutCounter =
                                  ( uint16 ) ( FLS_WRITE_TIMEOUT_COUNT / FLS_MAIN_FUNCTION_PERIOD );
#endif /* #if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE ) */
 
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
            } else {
                /* [SWS_Fls_00157] Report error FLS_E_PARAM_DATA */
                ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                          ( uint8 ) FLS_WRITE_ID, ( uint8 ) FLS_E_PARAM_DATA );
            }
        }
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    case MEMIF_BUSY :
    case MEMIF_BUSY_INTERNAL :
        /* [SWS_Fls_00030] Report error FLS_E_BUSY */
        ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                         ( uint8 ) FLS_WRITE_ID, ( uint8 ) FLS_E_BUSY );
        break;
 
    case MEMIF_UNINIT :
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00066] Report error FLS_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                  ( uint8 ) FLS_WRITE_ID, ( uint8 ) FLS_E_UNINIT );
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    default :
        /* No process */
        break;
    }
 
    return lretvalue;
}
 
/* [SWS_Fls_00183] FlsCancelApi ON/OFF control */
#if ( FLS_CANCEL_API != FALSE )
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_CANCEL_ID (0x03)                                         */
/* Name        : Fls_Cancel                                                   */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Cancels an ongoing job.                                      */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00252]                                              */
/*----------------------------------------------------------------------------*/
void Fls_Cancel( void )
{
    /* Fls module status */
    switch ( Fls_Status ) {
    case MEMIF_IDLE :
    case MEMIF_BUSY :
    case MEMIF_BUSY_INTERNAL :
 
        /* [SWS_Fls_00033] Job result check */
        if ( MEMIF_JOB_PENDING == Fls_JobResult ) {
            /* Force stop Data Flash only with the Erase and Blank Check job */
            if ( ( FLS_70_JOB_ERASE == s_FlsJobControl.FlsJobType ) ||
                 ( FLS_70_JOB_BLANKCHECK == s_FlsJobControl.FlsJobType ) ) {
                /* Update Force stop variable to handle force stop Data Flash */
                s_FlsJobControl.FlsForceStop = TRUE;
            }
            /* [SWS_Fls_00336] Set job status */
            Fls_Status = MEMIF_IDLE;
 
            /* [SWS_Fls_00033] Set job result */
            Fls_JobResult = MEMIF_JOB_CANCELED;
 
            /* [SWS_Fls_00335] Set job parameter */
            s_FlsJobControl.FlsJobType = FLS_70_JOB_NONE;
            s_FlsJobControl.FlsAddress = 0U;
            s_FlsJobControl.DataAddress = NULL_PTR;
            s_FlsJobControl.FlsLength = 0U;
            s_FlsJobControl.FlsExecuteFlg = FALSE;
            s_FlsJobControl.FlsBlockNumber = 0U;
            s_FlsNumberOfErase = 0U;
        }
 
        /* [SWS_Fls_00147] Notice error to FEE */
        if ( NULL_PTR != s_FlsConfig->FlsConfigSet.FlsJobErrorNotification ) {
            s_FlsConfig->FlsConfigSet.FlsJobErrorNotification();
        }
        break;
 
    case MEMIF_UNINIT :
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00356] Report error FLS_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                  ( uint8 ) FLS_CANCEL_ID, ( uint8 ) FLS_E_UNINIT );
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    default :
        /* No process */
        break;
    }
}
#endif /* #if ( FLS_CANCEL_API != FALSE ) */
 
/* [SWS_Fls_00184] FlsGetStatusApi ON/OFF control */
#if ( FLS_GET_STATUS_API != FALSE )
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_GETSTATUS_ID (0x04)                                      */
/* Name        : Fls_GetStatus                                                */
/* Param       : void                                                         */
/* Return      : MemIf_StatusType   Status of Fls module                      */
/* Contents    : Returns the driver state.                                    */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00253]                                              */
/*----------------------------------------------------------------------------*/
MemIf_StatusType Fls_GetStatus( void )
{
    /* [SWS_Fls_00034] */
    MemIf_StatusType status = Fls_Status; /* Return current Fls status */
 
    return status;
}
#endif /* #if ( FLS_GET_STATUS_API != FALSE ) */
 
/* [SWS_Fls_00185] FlsGetJobResultApi ON/OFF control */
#if ( FLS_GET_JOB_RESULT_API != FALSE )
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_GETJOBRESULT_ID (0x05)                                   */
/* Name        : Fls_GetJobResult                                             */
/* Param       : void                                                         */
/* Return      : MemIf_StatusType   Status of Fls module                      */
/* Contents    : Returns the result of the last job.                          */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00254]                                              */
/*----------------------------------------------------------------------------*/
MemIf_JobResultType Fls_GetJobResult( void )
{
    MemIf_JobResultType result = MEMIF_JOB_FAILED; /* Return Job result */
 
    /* Fls module status */
    switch ( Fls_Status ) {
    case MEMIF_IDLE :
    case MEMIF_BUSY :
    case MEMIF_BUSY_INTERNAL :
        /* [SWS_Fls_00035] Return current Fls result */
        result = Fls_JobResult;
        break;
 
    case MEMIF_UNINIT :
        /* [SWS_Fls_00358] Report error FLS_E_UNINIT */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                  ( uint8 ) FLS_GETJOBRESULT_ID, ( uint8 ) FLS_E_UNINIT );
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    default :
        /* No process */
        break;
    }
    return result;
}
 
#endif /* #if ( FLS_GET_JOB_RESULT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_MAINFUNCTION_ID (0x06)                                   */
/* Name        : Fls_MainFunction                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Performs the processing of jobs.                             */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00255]                                              */
/*----------------------------------------------------------------------------*/
void Fls_MainFunction( void )
{
    fls_70_HW_CheckCFDFSeqEndStatusType lenRetStatus; /* Return Sequece state */
    Fls_70_HW_ExecuteStatusType         lenRetError; /* Return Error */
 
    /* Check Fls module status */
    switch ( Fls_Status ) {
    case MEMIF_BUSY :
        /* [SWS_Fls_00037] Process the flash read, write, erase, compare and blank check jobs */
        if ( FLS_70_JOB_NONE != s_FlsJobControl.FlsJobType ) {
            /* Execute Jobs */
            lenRetStatus = Fls_70_HW_Execute( &s_FlsJobControl );
 
            /* Classify Error base on the return status */
            lenRetError = fls_70_ClassifyError( lenRetStatus );
 
            /* Check status and report error if have */
            fls_70_Execute( lenRetError );
        }
 
        /* Check Timeout Monitoring */
#if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE )
        if ( ( s_FlsJobControl.FlsJobType == FLS_70_JOB_ERASE ) ||
             ( s_FlsJobControl.FlsJobType == FLS_70_JOB_WRITE ) ||
             ( s_FlsJobControl.FlsJobType == FLS_70_JOB_READ ) ) {
            fls_70_TimeOutCheckAndProcessing();
        } else {
            /* Do Nothing */
        }
#endif /* #if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE ) */
        break;
 
    case MEMIF_UNINIT :
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00004] Report error FLS_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                  ( uint8 ) FLS_MAINFUNCTION_ID, ( uint8 ) FLS_E_UNINIT );
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    /* [SWS_Fls_00039] No process */
    case MEMIF_IDLE :
    case MEMIF_BUSY_INTERNAL :
    default :
        break;
    }
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_READ_ID (0x07)                                           */
/* Name        : Fls_Read                                                     */
/* Param       : (in) SourceAddress Source address in flash memory. This      */
/*                                  address offset will be added to the flash */
/*                                  memory base address.                      */
/*                                  Min : 0                                   */
/*                                  Max : FLS_SIZE - 1                        */
/*               (in) Length        Number of bytes to read                   */
/*                                  Min : 1                                   */
/*                                  Max : FLS_SIZE - SourceAddress            */
/*               (out) TargetAddressPtr                                       */
/*                                  Pointer to target data buffer             */
/* Return      : Std_ReturnType     E_OK : Read command has been accepted     */
/*                                  E_NOT_OK : Read command has not been      */
/*                                  accepted                                  */
/* Contents    : Reads from flash memory.                                     */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00256]                                              */
/*----------------------------------------------------------------------------*/
Std_ReturnType Fls_Read(
    Fls_AddressType SourceAddress, uint8* TargetAddressPtr, Fls_LengthType Length )
{
    Std_ReturnType lretvalue = E_NOT_OK; /* Return value */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
    /* Declare variables to store DET error ID
     * FLS_70_E_OK: No DET error
     * Others: DET error ID
     * lucRetAdd stores DET error ID when checking address
     * lucRetLen stores DET error ID when checking address length
     * lucRetCheck stores the results of address and address length checking
     */
    uint8 lucRetAdd;
    uint8 lucRetLen;
    uint8 lucRetCheck = FLS_70_E_OK;
#endif /* ( FLS_DEV_ERROR_DETECT != FALSE ) */
    /* Check Fls module status */
    switch ( Fls_Status ) {
    case MEMIF_IDLE :
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00097][SWS_Fls_00098] Argument check */
        lucRetAdd = fls_70_CheckFlashAddress( SourceAddress );
        /* Check DET error for FLS's address */
        if ( FLS_70_E_OK != lucRetAdd ) {
            /* Update DET error ID for lucRetCheck */
            lucRetCheck = lucRetAdd;
            ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                      ( uint8 ) FLS_READ_ID, lucRetAdd );
        } else {
            lucRetLen = fls_70_CheckFlashAddressLength( SourceAddress, Length, FLS_70_JOB_READ );
            /* Check DET error for FLS's address length */
            if ( FLS_70_E_OK != lucRetLen ) {
                /* Update DET error ID for lucRetCheck */
                lucRetCheck = lucRetLen;
                ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                          ( uint8 ) FLS_READ_ID, lucRetLen );
            } else {
                /* Do nothing */
            }
        }
 
        /* TargetAddress, Length FLS_70_E_OK */
        if ( FLS_70_E_OK == lucRetCheck ) {
            /* [SWS_Fls_00158] Null check */
            if ( NULL_PTR != TargetAddressPtr ) {
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
                /* [SWS_Fls_00338] Set job status */
                Fls_Status = MEMIF_BUSY;
                /* [SWS_Fls_00339] Set job result */
                Fls_JobResult = MEMIF_JOB_PENDING;
 
                /* [SWS_Fls_00337][SWS_Fls_00238] Set job parameter */
                s_FlsJobControl.FlsJobType = FLS_70_JOB_READ;
                s_FlsJobControl.FlsAddress = SourceAddress;
                s_FlsJobControl.DataAddress = (uint8 *) TargetAddressPtr;
                if( Length < s_ReadSize ) {
                    s_FlsJobControl.FlsLength = Length;
                    s_LengthCount = 0U;
                } else {
                    s_FlsJobControl.FlsLength = s_ReadSize;
                    s_LengthCount = Length - s_ReadSize;
                }
                s_FlsJobControl.FlsExecuteFlg = TRUE;
                s_FlsJobControl.FlsForceStop = FALSE;
                s_FlsJobControl.FlsBlockNumber = 0U;
                s_FlsNumberOfErase = 0U;
 
                /* [SWS_Fls_00340] Return OK */
                lretvalue = E_OK;
 
                /* Calculate check Read Job timeout */
#if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE )
                s_Fls_TimeoutCounter =
                                   ( uint16 ) ( FLS_READ_TIMEOUT_COUNT / FLS_MAIN_FUNCTION_PERIOD );
#endif /* #if ( FLS_TIMEOUT_SUPERVISION_ENABLED != FALSE ) */
 
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
            } else {
                /* [SWS_Fls_00158] Report error FLS_E_PARAM_DATA */
                ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                          ( uint8 ) FLS_READ_ID, ( uint8 ) FLS_E_PARAM_DATA );
            }
        }
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    case MEMIF_BUSY :
    case MEMIF_BUSY_INTERNAL :
        /* [SWS_Fls_00100] Report error FLS_E_BUSY */
        ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                         ( uint8 ) FLS_READ_ID, ( uint8 ) FLS_E_BUSY );
        break;
 
    case MEMIF_UNINIT :
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00099][SWS_Fls_00240] Reprot error FLS_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                  ( uint8 ) FLS_READ_ID, ( uint8 ) FLS_E_UNINIT );
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    default :
        /* No process */
        break;
    }
 
    return lretvalue;
}
 
/* [SWS_Fls_00186] Compiler switch */
#if ( FLS_COMPARE_API != FALSE )
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_COMPARE_ID (0x08)                                        */
/* Name        : Fls_Compare                                                  */
/* Param       : (in) SourceAddress Source address in flash memory. This      */
/*                                  address offset will be added to the flash */
/*                                  memory base address.                      */
/*                                  Min : 0                                   */
/*                                  Max : FLS_SIZE - 1                        */
/*               (in) TargetAddressPtr                                        */
/*                                  Pointer to target data buffer             */
/*               (in) Length        Number of bytes to read                   */
/*                                  Min : 1                                   */
/*                                  Max : FLS_SIZE - SourceAddress            */
/* Return      : Std_ReturnType     E_OK : Compare command has been accepted  */
/*                                  E_NOT_OK : Compare command has not been   */
/*                                  accepted                                  */
/* Contents    : Compares the contents of an area of flash memory with that   */
/*               of an application data buffer.                               */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00257]                                              */
/*----------------------------------------------------------------------------*/
Std_ReturnType Fls_Compare( Fls_AddressType SourceAddress, const uint8* TargetAddressPtr,
    Fls_LengthType Length )
{
    Std_ReturnType lretvalue = E_NOT_OK; /* Return value */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
    /* Declare variables to store DET error ID
     * FLS_70_E_OK: No DET error
     * Others: DET error ID
     * LucRetAdd stores DET error ID when checking address
     * LucRetLen stores DET error ID when checking address length
     * lucRetCheck stores the results of address and address length checking
     */
    uint8 lucRetAdd;
    uint8 lucRetLen;
    uint8 lucRetCheck = FLS_70_E_OK;
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
    /* Fls module status */
    switch ( Fls_Status ) {
    case MEMIF_IDLE :
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00150][SWS_Fls_00151] Argument check */
        lucRetAdd = fls_70_CheckFlashAddress( SourceAddress );
        /* Check DET error for FLS's address */
        if ( FLS_70_E_OK != lucRetAdd ) {
            /* Update DET error ID for lucRetCheck */
            lucRetCheck = lucRetAdd;
            ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                      ( uint8 ) FLS_COMPARE_ID, lucRetAdd );
        } else {
            lucRetLen = fls_70_CheckFlashAddressLength( SourceAddress, Length, FLS_70_JOB_COMPARE );
            /* Check DET error for FLS's address length */
            if ( FLS_70_E_OK != lucRetLen ) {
                /* Update DET error ID for lucRetCheck */
                lucRetCheck = lucRetLen;
                ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                          ( uint8 ) FLS_COMPARE_ID, lucRetLen );
            } else {
                /* Do nothing */
            }
        }
 
        /* TargetAddress, Length E_OK */
        if ( FLS_70_E_OK == lucRetCheck ) {
            /* [SWS_Fls_00273] Null check */
            if ( NULL_PTR != TargetAddressPtr ) {
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
                /* [SWS_Fls_00342] Set job status */
                Fls_Status = MEMIF_BUSY;
                /* [SWS_Fls_00343] Set job result */
                Fls_JobResult = MEMIF_JOB_PENDING;
 
                /* [SWS_Fls_00341][SWS_Fls_00243] Set job parameter */
                s_FlsJobControl.FlsJobType = FLS_70_JOB_COMPARE;
                s_FlsJobControl.FlsAddress = SourceAddress;
                s_FlsJobControl.DataAddress = (uint8 *) TargetAddressPtr;
                s_FlsJobControl.FlsLength = Length;
                s_FlsJobControl.FlsExecuteFlg = TRUE;
                s_FlsJobControl.FlsForceStop = FALSE;
                s_FlsJobControl.FlsBlockNumber = 0U;
                s_FlsNumberOfErase = 0U;
                s_LengthCount = 0U;
 
                /* [SWS_Fls_00344] Return OK */
                lretvalue = E_OK;
 
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
            } else {
                /* [SWS_Fls_00273] Report error FLS_E_PARAM_DATA */
                ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                          ( uint8 ) FLS_COMPARE_ID, ( uint8 ) FLS_E_PARAM_DATA );
            }
        }
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    case MEMIF_BUSY :
    case MEMIF_BUSY_INTERNAL :
        /* [SWS_Fls_00153] Report error FLS_E_BUSY */
        ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                         ( uint8 ) FLS_COMPARE_ID, ( uint8 ) FLS_E_BUSY );
        break;
 
    case MEMIF_UNINIT :
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00152] Report error FLS_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                  ( uint8 ) FLS_COMPARE_ID, ( uint8 ) FLS_E_UNINIT );
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    default :
        /* No process */
        break;
    }
 
    return lretvalue;
}
#endif /* #if ( FLS_COMPARE_API != FALSE ) */
 
/* [SWS_Fls_00187] Compiler switch */
#if ( FLS_SET_MODE_API != FALSE )
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_SETMODE_ID (0x09)                                        */
/* Name        : Fls_SetMode                                                  */
/* Param       : (in) Mode          MEMIF_MODE_SLOW: Slow read access /       */
/*                                  normal SPI access.                        */
/*                                  MEMIF_MODE_FAST: Fast read access / SPI   */
/*                                  burst access.                             */
/* Return      : void                                                         */
/* Contents    : Sets the flash driver's operation mode.                      */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00258]                                              */
/*----------------------------------------------------------------------------*/
void Fls_SetMode( MemIf_ModeType Mode )
{
    /* Fls module status */
    switch ( Fls_Status ) {
    case MEMIF_IDLE :
        Fls_Mode = Mode;
        if ( MEMIF_MODE_SLOW == Fls_Mode ) {
            s_ReadSize = s_FlsConfig->FlsConfigSet.FlsMaxReadNormalMode;
            s_WriteSize = s_FlsConfig->FlsConfigSet.FlsMaxWriteNormalMode;
        } else {
            s_ReadSize = s_FlsConfig->FlsConfigSet.FlsMaxReadFastMode;
            s_WriteSize = s_FlsConfig->FlsConfigSet.FlsMaxWriteFastMode;
        }
        break;
 
    case MEMIF_BUSY :
    case MEMIF_BUSY_INTERNAL :
        /* [SWS_Fls_00156] Report error FLS_E_BUSY */
        ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                         ( uint8 ) FLS_SETMODE_ID, ( uint8 ) FLS_E_BUSY );
        break;
 
    case MEMIF_UNINIT :
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00004] Report error FLS_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                  ( uint8 ) FLS_SETMODE_ID, ( uint8 ) FLS_E_UNINIT );
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    default :
        /* No process */
        break;
    }
}
#endif /* #if (FLS_SET_MODE_API != FALSE) */
 
/* Compiler switch */
#if ( FLS_VERSION_INFO_API != FALSE )
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_GETVERSIONINFO_ID (0x10)                                 */
/* Name        : Fls_GetVersionInfo                                           */
/* Param       : (out) VersioninfoPtr                                         */
/*                                  Pointer to where to store the version     */
/*                                  information of this module.               */
/* Return      : void                                                         */
/* Contents    : Returns the version information of this module.              */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00259]                                              */
/*----------------------------------------------------------------------------*/
void Fls_GetVersionInfo( Std_VersionInfoType* VersioninfoPtr )
{
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Fls_00363] Null check */
    if ( NULL_PTR == VersioninfoPtr ) {
        /* Report error FLS_E_PARAM_POINTER */
        ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                  ( uint8 ) FLS_GETVERSIONINFO_ID, ( uint8 ) FLS_E_PARAM_POINTER );
    } else
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Set version information */
        VersioninfoPtr->vendorID         = ( uint16 ) FLS_VENDOR_ID;        /* Vendor ID */
        VersioninfoPtr->moduleID         = ( uint16 ) FLS_MODULE_ID;        /* Module ID */
        VersioninfoPtr->sw_major_version = ( uint8 )  FLS_SW_MAJOR_VERSION; /* Software Major Version */
        VersioninfoPtr->sw_minor_version = ( uint8 )  FLS_SW_MINOR_VERSION; /* Software Minor Version */
        VersioninfoPtr->sw_patch_version = ( uint8 )  FLS_SW_PATCH_VERSION; /* Software Patch Version */
    }
}
#endif /* #if ( FLS_VERSION_INFO_API != FALSE ) */
 
#if ( FLS_BLANK_CHECK_API != FALSE )
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : FLS_BLANKCHECK_ID (0x0A)                                     */
/* Name        : Fls_BlankCheck                                               */
/* Param       : (in) TargetAddress Address in flash memory from which the    */
/*                                  blank check should be started.            */
/*                                  Min : 0                                   */
/*                                  Max : FLS_SIZE - 1                        */
/*               (in) Length        Number of bytes to be checked for erase   */
/*                                  pattern.                                  */
/*                                  Min : 1                                   */
/*                                  Max : FLS_SIZE - TargetAddress            */
/* Return      : Std_ReturnType     E_OK : Erase command has been accepted    */
/*                                  E_NOT_OK : Erase command has not been     */
/*                                  accepted                                  */
/* Contents    : Verify, whether a given memory area has been erased but not  */
/*               (yet) programmed. The function shall limit the maximum number*/
/*               of checked flash cells per main function cycle to the        */
/*               configured value FlsMaxReadNormalMode or FlsMaxReadFastMode  */
/*               respectively.                                                */
/* Author      : --                                                           */
/* Note        : [SWS_Fls_00371]                                              */
/*----------------------------------------------------------------------------*/
Std_ReturnType Fls_BlankCheck( Fls_AddressType TargetAddress, Fls_LengthType Length )
{
    Std_ReturnType  lretvalue = E_NOT_OK; /* Return value */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
    /* Declare variables to store DET error ID
     * FLS_70_E_OK: No DET error
     * Others: DET error ID
     * lucRetAdd stores DET error ID when checking address
     * LucRetLen stores DET error ID when checking address length
     * LucRetCheck stores the results of address and address length checking
     */
    uint8 lucRetAdd;
    uint8 lucRetLen;
    uint8 lucRetCheck = FLS_70_E_OK;
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
 
    /* Fls module status */
    switch ( Fls_Status ) {
    case MEMIF_IDLE :
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00379] Check flash memory area starting from
         * ( Base address + TargetAddress ) of size Length is erased
         */
        /* [SWS_Fls_00380] Argument Address check */
        lucRetAdd = fls_70_CheckFlashAddress( TargetAddress );
        /* Check DET error for FLS's address */
        if ( FLS_70_E_OK != lucRetAdd ) {
            /* Update DET error ID for lucRetCheck */
            lucRetCheck = lucRetAdd;
            ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                      ( uint8 ) FLS_BLANKCHECK_ID, lucRetAdd );
        } else {
            /* [SWS_Fls_00381] Argument Length check */
            lucRetLen = fls_70_CheckFlashAddressLength( TargetAddress, Length,
                                                        FLS_70_JOB_BLANKCHECK );
            /* Check DET error for FLS's address length */
            if ( FLS_70_E_OK != lucRetLen ) {
                /* Update DET error ID for lucRetCheck */
                lucRetCheck = lucRetLen;
                ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                          ( uint8 ) FLS_BLANKCHECK_ID, lucRetLen );
            } else {
                /* Do nothing */
            }
        }
 
        /* There is no error */
        if ( FLS_70_E_OK == lucRetCheck ) {
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
            /* [SWS_Fls_00375] Set job status into MEMIF_BUSY */
            Fls_Status = MEMIF_BUSY;
 
            /* [SWS_Fls_00376] Set job result into MEMIF_JOB_PENDING */
            Fls_JobResult = MEMIF_JOB_PENDING;
 
            /* [SWS_Fls_00374] Set job parameter */
            s_FlsJobControl.FlsJobType = FLS_70_JOB_BLANKCHECK;
            s_FlsJobControl.FlsAddress = TargetAddress;
            s_FlsJobControl.DataAddress = NULL_PTR;            
            s_FlsJobControl.FlsLength = Length;
            s_FlsJobControl.FlsExecuteFlg = TRUE;
            s_FlsJobControl.FlsForceStop = FALSE;
            s_FlsJobControl.FlsBlockNumber = 0U;
            s_FlsNumberOfErase = 0U;
            s_LengthCount = 0U;
 
            /* [SWS_Fls_00377] Return OK */
            lretvalue = E_OK;
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        }
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    case MEMIF_BUSY :
    case MEMIF_BUSY_INTERNAL :
        /* [SWS_Fls_00383] Report Error FLS_E_BUSY */
        ( void ) Det_ReportRuntimeError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                         ( uint8 ) FLS_BLANKCHECK_ID, ( uint8 ) FLS_E_BUSY );
        break;
 
    case MEMIF_UNINIT :
/* Development error detection is enabled */
#if ( FLS_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Fls_00382] Report error FLS_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) FLS_MODULE_ID, ( uint8 ) FLS_70_INSTANCE_ID,
                                  ( uint8 ) FLS_BLANKCHECK_ID, ( uint8 ) FLS_E_UNINIT );
#endif /* #if ( FLS_DEV_ERROR_DETECT != FALSE ) */
        break;
 
    default :
        /* No process */
        break;
    }
 
    return lretvalue;
}
#endif /* #if ( FLS_BLANK_CHECK_API != FALSE ) */
 
#define FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
 
/* EOF Fls.c ******************************************************************/
 
 