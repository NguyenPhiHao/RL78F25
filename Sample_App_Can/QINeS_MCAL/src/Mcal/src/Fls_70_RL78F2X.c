/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Fls_70_RL78F2X.c                                             */
/* Version     : v1.00.02                                                     */
/* Contents    : FLS Module HW dependent interface                            */
/*               The FLS is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : For RL78/F25                                                 */
/******************************************************************************/
/* Specification of Flash Driver                                              */
/* Release R22-11                                                             */
 
/******************************************************************************
 Expanded function
*******************************************************************************/
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Fls_Cfg.h"
#include "Fls_70_RL78F2X.h"
 
/* Renesas-provided libraries */
#include "r_rfd_common_api.h"
#include "r_rfd_common_control_api.h"
#include "r_rfd_data_flash_api.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define FLS_70_VENDOR_ID_RL78F2X_C                   ( 70U )
#define FLS_70_MODULE_ID_RL78F2X_C                   ( 92U )
 
#define FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    ( 22U )
#define FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    ( 11U )
#define FLS_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C ( 0U )
 
#define FLS_70_SW_MAJOR_VERSION_RL78F2X_C            ( 1U )
#define FLS_70_SW_MINOR_VERSION_RL78F2X_C            ( 0U )
#define FLS_70_SW_PATCH_VERSION_RL78F2X_C            ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/* Fls_Cfg.h version check start */
 
#if ( FLS_70_VENDOR_ID_RL78F2X_C != FLS_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Fls_70_RL78F2X.c and Fls_Cfg.h are different"
#endif
 
#if ( FLS_70_MODULE_ID_RL78F2X_C != FLS_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Fls_70_RL78F2X.c and Fls_Cfg.h are different"
#endif
 
#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C != FLS_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C != FLS_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( FLS_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != FLS_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Fls_70_RL78F2X.c and Fls_Cfg.h are different"
#endif
 
#if ( ( FLS_70_SW_MAJOR_VERSION_RL78F2X_C != FLS_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( FLS_70_SW_MINOR_VERSION_RL78F2X_C != FLS_70_SW_MINOR_VERSION_CFG_H ) || \
      ( FLS_70_SW_PATCH_VERSION_RL78F2X_C != FLS_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Fls_70_RL78F2X.c and Fls_Cfg.h are different"
#endif
 
/* Fls_Cfg.h version check end */
 
/* Fls_70_RL78F2X.h version check start */
 
#if ( FLS_70_VENDOR_ID_RL78F2X_C != FLS_70_VENDOR_ID_RL78F2X_H )
    #error "VENDOR ID for Fls_70_RL78F2X.c and Fls_70_RL78F2X.h are different"
#endif
 
#if ( FLS_70_MODULE_ID_RL78F2X_C != FLS_70_MODULE_ID_RL78F2X_H )
    #error "MODULE ID for Fls_70_RL78F2X.c and Fls_70_RL78F2X.h are different"
#endif
 
#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C != FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) \
    || ( FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C != FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) \
    || ( FLS_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != \
         FLS_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) \
    )
    #error "AUTOSAR Version Numbers of Fls_70_RL78F2X.c and Fls_70_RL78F2X.h are different"
#endif
 
#if ( ( FLS_70_SW_MAJOR_VERSION_RL78F2X_C != FLS_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( FLS_70_SW_MINOR_VERSION_RL78F2X_C != FLS_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( FLS_70_SW_PATCH_VERSION_RL78F2X_C != FLS_70_SW_PATCH_VERSION_RL78F2X_H ) \
    )
    #error "Software Version Numbers of Fls_70_RL78F2X.c and Fls_70_RL78F2X.h are different"
#endif
 
/* Fls_70_RL78F2X.h version check end */
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
 
#define FLS_START_SEC_VAR_NO_INIT_LOCAL_8
#include "Fls_MemMap.h"
 
uint8 g_Fls_CheckErase;
uint8 g_Fls_CheckWrite;
 
#if (FLS_ERASE_VERIFICATION_ENABLED != FALSE)
uint8 g_Fls_VerifyErase;
#endif /* #if (FLS_ERASE_VERIFICATION_ENABLED != FALSE) */
 
#if (FLS_WRITE_VERIFICATION_ENABLED != FALSE)
uint8 g_Fls_VerifyWrite;
#endif /* #if (FLS_WRITE_VERIFICATION_ENABLED != FALSE) */
 
#define FLS_STOP_SEC_VAR_NO_INIT_LOCAL_8
#include "Fls_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
LOCAL_INLINE void  fls_70_RL78F2X_ReadProcess( Fls_70_ControlType* pFlsJobRead );
 
#if ( ( FLS_COMPARE_API != FALSE ) || ( FLS_WRITE_VERIFICATION_ENABLED != FALSE ) )
LOCAL_INLINE uint8  fls_70_RL78F2X_CompareProcess( Fls_70_ControlType* pFlsJobCompare );
#endif /* #if ( ( FLS_COMPARE_API != FALSE ) || ( FLS_WRITE_VERIFICATION_ENABLED != FALSE ) ) */
 
LOCAL_INLINE uint8 fls_70_RL78F2X_CheckSequenceSeqEnd( bool_t Fls_Forcestop );
 
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType
                                      fls_70_RL78F2X_CheckSequenceSeqError( uint8 Fls_70_status );
 
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType
                                  fls_70_RL78F2X_CheckSequence( Fls_70_ControlType* pFlsJobCheck );
 
LOCAL_INLINE void fls_70_RL78F2X_AccessModeEnable( void );
 
LOCAL_INLINE void fls_70_RL78F2X_AccessModeDisable( void );
 
LOCAL_INLINE void fls_70_RL78F2X_Force_Stop( void );
 
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType fls_70_RL78F2X_EraseProcess
                                                        ( Fls_70_ControlType* pFlsJobErase );
 
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType fls_70_RL78F2X_WriteProcess
                                                        ( Fls_70_ControlType* pFlsJobWrite );
 
#if ( FLS_WRITE_VERIFICATION_ENABLED != FALSE )
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType fls_70_RL78F2X_VerifyWriteProcess
                                                ( Fls_70_ControlType* pFlsWriteVerify );
#endif /* #if ( FLS_WRITE_VERIFICATION_ENABLED != FALSE ) */
 
 
#if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE )
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType fls_70_RL78F2X_VerifyEraseProcess
                                                    ( Fls_70_ControlType* pFlsEraseVerify );
#endif /* #if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE ) */
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
 
#define FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_ReadProcess                                   */
/* Param       : (in) pFlsJobRead       Pointer to Job Control variable       */
/* Return      : void                                                         */
/* Contents    : Perform read data from the specific address and length       */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE void  fls_70_RL78F2X_ReadProcess( Fls_70_ControlType* pFlsJobRead )
{
    Fls_AddressType       read_fls_addr;
    uint8 QL_70_FAR *      p_read_buffer;
    uint16_least          lReadcount;
 
    read_fls_addr = ( pFlsJobRead->FlsAddress ) + FLS_BASE_ADDRESS;
    p_read_buffer = ( pFlsJobRead->DataAddress );
    for ( lReadcount = 0U; lReadcount < ( uint16 )( pFlsJobRead->FlsLength ); lReadcount++ ) {
        *p_read_buffer = *( QL_70_FAR uint8* )read_fls_addr;
        read_fls_addr++;
        p_read_buffer = &( p_read_buffer[1U] );
    }
}
 
/* [SWS_Fls_00186] Compiler switch */
#if ( ( FLS_COMPARE_API != FALSE ) || ( FLS_WRITE_VERIFICATION_ENABLED != FALSE ) )
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_CompareProcess                                */
/* Param       : (in)      pFlsJobCompare  Pointer to Job Control variable    */
/* Return      : uint8             FLS_70_E_OK : Data is consistent           */
/*             :                   FLS_70_E_NOT_OK : Data is not consistent   */
/* Contents    : Perform data comparison between the write target and         */
/*             : the write destination                                        */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE uint8  fls_70_RL78F2X_CompareProcess( Fls_70_ControlType* pFlsJobCompare )
{
    uint8              lreturnCompare = FLS_70_E_OK; /* Return Compare data status */
    uint32_least       lComparecount;
    Fls_AddressType    lSourceData;
    uint8 QL_70_FAR *   lBufferData;
 
    lSourceData = FLS_BASE_ADDRESS + ( pFlsJobCompare->FlsAddress );
 
    lBufferData = pFlsJobCompare->DataAddress;
 
    /* Compare SourceData and BufferData in units of 1 byte */
    for ( lComparecount = 0U; lComparecount < ( pFlsJobCompare->FlsLength ) ; lComparecount++ ) {
        if ( *( QL_70_FAR uint8* )lSourceData != *lBufferData ) {
            lreturnCompare = FLS_70_E_NOT_OK;
            break;
        }
        lSourceData++;
        lBufferData = &( lBufferData[1U] );
    }
 
    return lreturnCompare;
}
#endif /* #if ( ( FLS_COMPARE_API != FALSE ) || ( FLS_WRITE_VERIFICATION_ENABLED != FALSE ) ) */
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_AccessModeEnable                              */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Enable to access Data flash memory                           */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE void fls_70_RL78F2X_AccessModeEnable( void )
{
    /* Enable Data flash access */
    R_RFD_SetDataFlashAccessMode( R_RFD_ENUM_DF_ACCESS_ENABLE );
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_AccessModeDisable                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Disable to access Data flash memory                          */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE void fls_70_RL78F2X_AccessModeDisable( void )
{
    /* Disable Data flash access */
    R_RFD_SetDataFlashAccessMode( R_RFD_ENUM_DF_ACCESS_DISABLE );
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_Force_Stop                                    */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Stop the data flash memory sequencer operation forcibly      */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE void fls_70_RL78F2X_Force_Stop( void )
{
    /* Set the value for FSSQ register FSSTP bit */
    R_RFD_REG_U01_FSSQ_FSSTP = R_RFD_VALUE_U01_FSSQ_FSSTP_ON;
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_CheckSequenceSeqEnd                           */
/* Param       : (in) Fls_Forcestop    Input to check Force Stop Data Flash   */
/* Return      : uint8   Stores error information                             */
/* Contents    : Checking completion of the command sequence and handle force */
/*               stop Data flash sequence                                     */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE uint8 fls_70_RL78F2X_CheckSequenceSeqEnd( bool_t Fls_Forcestop )
{
    uint8 lstatus = 0U; /* Return sequence error status */
 
    if ( TRUE == Fls_Forcestop ) {
        /* Handle Force stop Data Flash */
        fls_70_RL78F2X_Force_Stop();
    }
 
    /* Sequencer busy loop step1 */
    while ( R_RFD_ENUM_RET_STS_BUSY == R_RFD_CheckCFDFSeqEndStep1() ) {
        /* do nothing */
        /* possible to write the program for detecting timeout here as necessity requires */
    }
 
    /* Sequencer busy loop step2 */
    while ( R_RFD_ENUM_RET_STS_BUSY == R_RFD_CheckCFDFSeqEndStep2() ) {
        /* do nothing */
        /* possible to write the program for detecting timeout here as necessity requires */
    }
 
    /* Get error status */
    R_RFD_GetSeqErrorStatus( &lstatus );
 
    /* Clear sequencer registers */
    R_RFD_ClearSeqRegister();
 
    return lstatus;
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_CheckSequenceSeqError                         */
/* Param       : (in) Fls_70_status    Get Sequence status                    */
/* Return      : fls_70_RL78F2X_CheckCFDFSeqEndStatusType                     */
/*               FLS_70_CHECKCFDFSEQEND_OK : Sequence No Error                */
/*               FLS_70_CHECKCFDFSEQEND_ERR_CFDF_SEQUENCER : Sequence Error   */
/*               FLS_70_CHECKCFDFSEQEND_ERR_ERASE : Erase Error               */
/*               FLS_70_CHECKCFDFSEQEND_ERR_WRITE : Write Error               */
/*               FLS_70_CHECKCFDFSEQEND_ERR_BLANKCHECK : Blank Check Error    */
/* Contents    : Get Sequence Error information                               */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType
                                       fls_70_RL78F2X_CheckSequenceSeqError( uint8 Fls_70_status )
{
    fls_70_RL78F2X_CheckCFDFSeqEndStatusType lretError = FLS_70_CHECKCFDFSEQEND_OK;
 
    /* Check error status */
    /* No error */
    if ( FLS_RL78F2X_SEQ_ERR_NONE == ( FLS_RL78F2X_SEQ_ERR_ALL & Fls_70_status ) ) {
        lretError = FLS_70_CHECKCFDFSEQEND_OK;
    }
    else { /* Error occur */
        /* CFDF sequencer error */
        if ( FLS_RL78F2X_SEQ_ERR_CFDF_SEQUENCER_BIT ==
           ( FLS_RL78F2X_SEQ_ERR_CFDF_SEQUENCER_BIT & Fls_70_status ) ) {
            lretError = FLS_70_CHECKCFDFSEQEND_ERR_CFDF_SEQUENCER;
        } else if ( FLS_RL78F2X_SEQ_ERR_ERASE_BIT ==
                ( FLS_RL78F2X_SEQ_ERR_ERASE_BIT & Fls_70_status ) ) {
            /* Erase error */
            lretError = FLS_70_CHECKCFDFSEQEND_ERR_ERASE;
        } else if ( FLS_RL78F2X_SEQ_ERR_WRITE_BIT ==
                                               ( FLS_RL78F2X_SEQ_ERR_WRITE_BIT & Fls_70_status ) ) {
            /* Write error */
            lretError = FLS_70_CHECKCFDFSEQEND_ERR_WRITE;
        } else if ( FLS_RL78F2X_SEQ_ERR_BLANKCHECK_BIT ==
                ( FLS_RL78F2X_SEQ_ERR_BLANKCHECK_BIT & Fls_70_status ) ) {
            /* Blank check error */
            lretError = FLS_70_CHECKCFDFSEQEND_ERR_BLANKCHECK;
        } else {
            /* Do nothing */
        }
    }
 
    return lretError;
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_CheckSequence                                 */
/* Param       : (in) pFlsJobCheck     Pointer to Job Control variable        */
/* Return      : fls_70_RL78F2X_CheckCFDFSeqEndStatusType                     */
/*               FLS_70_CHECKCFDFSEQEND_OK : Sequence No Error                */
/*               FLS_70_CHECKCFDFSEQEND_ERR_CFDF_SEQUENCER : Sequence Error   */
/*               FLS_70_CHECKCFDFSEQEND_ERR_ERASE : Erase Error               */
/*               FLS_70_CHECKCFDFSEQEND_ERR_WRITE : Write Error               */
/*               FLS_70_CHECKCFDFSEQEND_ERR_BLANKCHECK : Blank Check Error    */
/* Contents    : Check Sequence End and get Sequence Error information        */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType
                                    fls_70_RL78F2X_CheckSequence( Fls_70_ControlType* pFlsJobCheck )
{
    fls_70_RL78F2X_CheckCFDFSeqEndStatusType lSeqStatus; /* Return status */
    uint8                                    lCheckSeq; /* Sequence end check */
 
    /* Check Sequence End */
    lCheckSeq = fls_70_RL78F2X_CheckSequenceSeqEnd( pFlsJobCheck->FlsForceStop );
 
    /* Check Sequence Error */
    lSeqStatus = fls_70_RL78F2X_CheckSequenceSeqError( lCheckSeq );
 
    return lSeqStatus;
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_EraseProcess                                  */
/* Param       : (in) pFlsJobErase   Pointer to Erase job Control variable    */
/* Return      : fls_70_RL78F2X_CheckCFDFSeqEndStatusType                     */
/*               FLS_70_CHECKCFDFSEQEND_OK : Sequence No Error                */
/*               FLS_70_CHECKCFDFSEQEND_ERR_CFDF_SEQUENCER : Sequence Error   */
/*               FLS_70_CHECKCFDFSEQEND_ERR_ERASE : Erase Error               */
/* Contents    : Erase the specific address                                   */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType fls_70_RL78F2X_EraseProcess
                                                        ( Fls_70_ControlType* pFlsJobErase )
{
    fls_70_RL78F2X_CheckCFDFSeqEndStatusType     lErasestatus; /* Return status */  
 
    R_RFD_EraseDataFlashReq( pFlsJobErase->FlsBlockNumber );
 
    /* Check Sequence End and Error */
    lErasestatus = fls_70_RL78F2X_CheckSequence( pFlsJobErase );
 
    if ( FLS_70_CHECKCFDFSEQEND_OK != lErasestatus ) {
        /* Update Erase status */
        g_Fls_CheckErase = FLS_70_E_NOT_OK;
 
    } else {
        /* Update Erase status */
        g_Fls_CheckErase = FLS_70_E_OK;
    }
 
    return lErasestatus;
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_WriteProcess                                  */
/* Param       : (in) pFlsJobWrite   Pointer to Write job Control variable    */
/* Return      : fls_70_RL78F2X_CheckCFDFSeqEndStatusType                     */
/*               FLS_70_CHECKCFDFSEQEND_OK : Sequence No Error                */
/*               FLS_70_CHECKCFDFSEQEND_ERR_CFDF_SEQUENCER : Sequence Error   */
/*               FLS_70_CHECKCFDFSEQEND_ERR_WRITE : Write Error               */
/*               FLS_70_CHECKCFDFSEQEND_ERR_BLANKCHECK : Blank Check Error    */
/* Contents    : Write data with the specific address and length value        */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType fls_70_RL78F2X_WriteProcess
                                                        ( Fls_70_ControlType* pFlsJobWrite )
{
    /* Declare return variable with enumaration type */
    fls_70_RL78F2X_CheckCFDFSeqEndStatusType     lWritestatus = FLS_70_CHECKCFDFSEQEND_OK; /* Return status */
    Fls_AddressType                              write_fls_addr;
    uint8*                                       p_write_data;
    uint16_least                                 lCnt;
 
/* Check whether flash area is erased completely */
#if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE )
    /* Conduct blank check before writting */
    /* Check the block has been completely erased */
    R_RFD_BlankCheckDataFlashReq( ( ( pFlsJobWrite->FlsAddress ) +  FLS_BASE_ADDRESS ),
                                  ( ( uint16 ) pFlsJobWrite->FlsLength ) );
 
    lWritestatus = fls_70_RL78F2X_CheckSequence( pFlsJobWrite );
 
    if ( FLS_70_CHECKCFDFSEQEND_OK == lWritestatus ) {
        /* Set Verify Erase status into FLS_70_E_OK */
        g_Fls_VerifyErase = FLS_70_E_OK;
#endif /* #if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE ) */
        /* Set address */
        write_fls_addr = pFlsJobWrite->FlsAddress + FLS_BASE_ADDRESS;
        p_write_data   = pFlsJobWrite->DataAddress;
        g_Fls_CheckWrite = FLS_70_E_OK;
 
        /* Write data */
        for ( lCnt = 0U; lCnt < ( uint16 )( pFlsJobWrite->FlsLength ); lCnt++ ) {
            R_RFD_WriteDataFlashReq( write_fls_addr, p_write_data );
 
            /* Check Sequence End and Error */
            lWritestatus = fls_70_RL78F2X_CheckSequence( pFlsJobWrite );
 
            if ( FLS_70_CHECKCFDFSEQEND_OK != lWritestatus ) {
                /* If the status is not OK, stop writing and send error */
                g_Fls_CheckWrite = FLS_70_E_NOT_OK;
                break;
            }
            write_fls_addr++;
            p_write_data = &( p_write_data[1U] );
        }
 
#if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE )
    } else {
        /* Update Verify Erase status */
        g_Fls_VerifyErase = FLS_70_E_NOT_OK;
    }
#endif /* #if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE ) */
 
    return lWritestatus;
}
 
#if ( FLS_WRITE_VERIFICATION_ENABLED != FALSE )
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_VerifyWriteProcess                            */
/* Param       : (in) pFlsWriteVerify  Pointer to Job Control variable        */
/* Return      : fls_70_RL78F2X_CheckCFDFSeqEndStatusType                     */
/*               FLS_70_CHECKCFDFSEQEND_OK : Sequence No Error                */
/*               FLS_70_CHECKCFDFSEQEND_ERR_MARGIN : Margin Error             */
/* Contents    : Check and verify Write data previously                       */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType fls_70_RL78F2X_VerifyWriteProcess
                                                ( Fls_70_ControlType* pFlsWriteVerify )
{
    fls_70_RL78F2X_CheckCFDFSeqEndStatusType   lVerifyWritestatus; /* Return status */
    uint8                                      lVerifyData; /* Verify data status */
 
    lVerifyWritestatus = FLS_70_CHECKCFDFSEQEND_OK;
 
    /* Conduct compare data after writting */
    lVerifyData = fls_70_RL78F2X_CompareProcess( pFlsWriteVerify );
 
    if ( FLS_70_E_OK != lVerifyData ) {
        /* Update Verify Write state */
        g_Fls_VerifyWrite = FLS_70_E_NOT_OK;
 
        /* Update return value */
        lVerifyWritestatus = FLS_70_CHECKCFDFSEQEND_ERR_MARGIN;
    } else {
        /* Keep Verify Write status */
        g_Fls_VerifyWrite = FLS_70_E_OK;
    }
 
    return lVerifyWritestatus;
}
#endif /* #if ( FLS_WRITE_VERIFICATION_ENABLED != FALSE ) */
 
#if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE )
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : fls_70_RL78F2X_VerifyEraseProcess                            */
/* Param       : (in) pFlsEraseVerify   Pointer to Job Control variable       */
/* Return      : fls_70_RL78F2X_CheckCFDFSeqEndStatusType                     */
/*               FLS_70_CHECKCFDFSEQEND_OK : Sequence No Error                */
/*               FLS_70_CHECKCFDFSEQEND_ERR_CFDF_SEQUENCER : Sequence Error   */
/*               FLS_70_CHECKCFDFSEQEND_ERR_BLANKCHECK : Blank Check Error    */
/* Contents    : Check and verify whether erase data flash memory completely  */
/* Author      : --                                                           */
/* Note        : Local function                                               */
/******************************************************************************/
LOCAL_INLINE fls_70_RL78F2X_CheckCFDFSeqEndStatusType fls_70_RL78F2X_VerifyEraseProcess
                                                    ( Fls_70_ControlType* pFlsEraseVerify )
{
    fls_70_RL78F2X_CheckCFDFSeqEndStatusType     lVerifyErasestatus; /* Return status */
 
    /* Check the block has been completely erased */
    R_RFD_BlankCheckDataFlashReq( ( pFlsEraseVerify->FlsAddress + FLS_BASE_ADDRESS ),
                                                                  FLS_RL78F2X_VERIFY_ERASE_LENGTH );
 
    /* Check Sequence End and Error */
    lVerifyErasestatus = fls_70_RL78F2X_CheckSequence( pFlsEraseVerify );
 
    /* Check Blank status */
    if ( FLS_70_CHECKCFDFSEQEND_OK != lVerifyErasestatus ) {
        /* Update verify Erase status */
        g_Fls_VerifyErase = FLS_70_E_NOT_OK;
    } else {
        /* Keep verify Erase status */
        g_Fls_VerifyErase = FLS_70_E_OK;
    }
 
    return lVerifyErasestatus;
}
#endif /* #if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : Fls_70_RL78F2X_Init                                          */
/* Param       : void                                                         */
/* Return      : uint8                                                        */
/*               FLS_70_E_OK : Init success                                   */
 
/*               FLS_70_E_NOT_OK : Init fail                                  */
/* Contents    : Inital Hardware Register                                     */
/* Author      : --                                                           */
/* Note        : Public function                                              */
/******************************************************************************/
uint8 Fls_70_RL78F2X_Init( void )
{
    e_rfd_ret_t    df_nonprg_mode_chk;
    e_rfd_ret_t    status;
    uint8          lucReturnCode;
 
    /* Nonprogrammable mode check */
    df_nonprg_mode_chk = R_RFD_CheckFlashMemoryMode(
                         R_RFD_ENUM_FLASH_MODE_NONPROGRAMMABLE );
 
    /* Initialize flash library parameter */
    /* Check HIO (highspeed on chip oscillator) running */
    if ( HIOSTOP_STATE_RUN == FLS_70_RL78F2X_HIOSTOP ) {
        /* Check nonprogrammable mode */
        if ( R_RFD_ENUM_RET_STS_OK == df_nonprg_mode_chk ) {
            /* [SWS_Fls_00014] Initialize register */
            status = R_RFD_Init( FLS_70_FREQUENCY );
        } else {
            /* Update status with mismatch mode */
            status = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
        }
    } else {
        status = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
    }
 
    if ( R_RFD_ENUM_RET_STS_OK != status ) {
        lucReturnCode = FLS_70_E_NOT_OK;
    } else {
        lucReturnCode = FLS_70_E_OK;
    }
 
    return lucReturnCode;
}
 
/******************************************************************************/
/* ModuleID    : FLS_MODULE_ID (092)                                          */
/* ServiceID   : --                                                           */
/* Name        : Fls_70_RL78F2X_Execute                                       */
/* Param       : (in)  pFlsJobControl   Pointer to Job Control variable       */
/* Return      : fls_70_RL78F2X_CheckCFDFSeqEndStatusType                     */
/*               FLS_70_CHECKCFDFSEQEND_OK : Sequence No Error                */
/*               FLS_70_CHECKCFDFSEQEND_ERR_CFDF_SEQUENCER : Sequence Error   */
/*               FLS_70_CHECKCFDFSEQEND_ERR_ERASE : Erase Error               */
/*               FLS_70_CHECKCFDFSEQEND_ERR_WRITE : Write Error               */
/*               FLS_70_CHECKCFDFSEQEND_ERR_MARGIN : Margin Error             */
/*               FLS_70_CHECKCFDFSEQEND_ERR_BLANKCHECK : Blank Check Error    */
/* Contents    : Execute Asynchronous Jobs                                    */
/* Author      : --                                                           */
/* Note        : Public function                                              */
/******************************************************************************/
fls_70_RL78F2X_CheckCFDFSeqEndStatusType
                                        Fls_70_RL78F2X_Execute( Fls_70_ControlType* pFlsJobControl )
{
    /* Declare return variable with enumaration type */
    bool_t                                       lCheckJobControl;
    fls_70_RL78F2X_CheckCFDFSeqEndStatusType     lstatus; /* Return status */
    uint8                                      lCompareData = FLS_70_E_OK;
 
    lstatus          = FLS_70_CHECKCFDFSEQEND_OK;
    lCheckJobControl = FALSE;
 
    if ( NULL_PTR == pFlsJobControl ) {
        lstatus = FLS_70_CHECKCFDFSEQEND_NULL;
        lCheckJobControl = TRUE;
    } else {
        /* Check Flash execute flag */
        if ( FALSE != ( pFlsJobControl->FlsExecuteFlg ) ) {
            /* Not check non-programmable mode because after Fls_70_RL78F2X_Init(),
             * Flash memory mode is non-programmable mode
             */
            /* Enable data flash access */
            fls_70_RL78F2X_AccessModeEnable();
 
            /* [SWS_Fls_00037] Execute data flash library */
            /* Read data flash job */
            if ( FLS_70_JOB_READ == ( pFlsJobControl->FlsJobType ) ) {
                /* Set Non-programming mode */
                ( void ) R_RFD_SetFlashMemoryMode( R_RFD_ENUM_FLASH_MODE_NONPROGRAMMABLE );
 
                /* Conduct Read data operation */
                fls_70_RL78F2X_ReadProcess( pFlsJobControl );
            } else {
                /* Erase, Write, Compare, Blank check job */
                /* Set programming mode */
                ( void ) R_RFD_SetFlashMemoryMode( R_RFD_ENUM_FLASH_MODE_DATA_PROGRAMMING );
 
                switch ( pFlsJobControl->FlsJobType ) {
 
                /* [SWS_Fls_00220] Execute Erase job */
                case FLS_70_JOB_ERASE :
                    lstatus = fls_70_RL78F2X_EraseProcess( pFlsJobControl );
                    break;
 
                /* [SWS_Fls_00225] Execute Write job */
                case FLS_70_JOB_WRITE :
                    lstatus = fls_70_RL78F2X_WriteProcess( pFlsJobControl );
                    break;
 
                /* [SWS_Fls_00186] Compiler switch */
#if (FLS_COMPARE_API != FALSE)
                /* [SWS_Fls_00243] Execute Compare job */
                case FLS_70_JOB_COMPARE :
                    /* Set nonprogrammable mode */
                    ( void ) R_RFD_SetFlashMemoryMode
                                                ( R_RFD_ENUM_FLASH_MODE_NONPROGRAMMABLE );
 
                    /* Conduct Read and Compare data */
                    lCompareData = fls_70_RL78F2X_CompareProcess( pFlsJobControl );
                    break;
#endif /* #if (FLS_COMPARE_API != FALSE) */
 
                /* [SWS_Fls_00378] Execute Blank check job */
                case FLS_70_JOB_BLANKCHECK :
                    R_RFD_BlankCheckDataFlashReq( ( pFlsJobControl->FlsAddress + FLS_BASE_ADDRESS ),
                                                  ( uint16 )( pFlsJobControl->FlsLength ) );
 
                    break;
 
                /* [SWS_Fls_00039] No process */
                default :
                    /* No process */
                    break;
                }
            }
        }
    }
 
    if ( ( TRUE != lCheckJobControl ) && ( FLS_70_JOB_NONE != ( pFlsJobControl->FlsJobType ) ) ) {
        /* End confirmation processing */
        switch ( pFlsJobControl->FlsJobType ) {
        case FLS_70_JOB_READ :
            lstatus = FLS_70_CHECKCFDFSEQEND_OK;
            break;
 
        case FLS_70_JOB_COMPARE :
            if ( FLS_70_E_OK != lCompareData ) {
                lstatus = FLS_70_CHECKCFDFSEQEND_ERR_MARGIN;
            } else {
                lstatus = FLS_70_CHECKCFDFSEQEND_OK;
            }
            break;
 
        case FLS_70_JOB_ERASE :
            /* [SWS_Fls_00022] Conduct check the block has been completely erased */
#if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE )
            if ( FLS_70_CHECKCFDFSEQEND_OK == lstatus ) {
                /* Check the block has been completely erased */
                lstatus = fls_70_RL78F2X_VerifyEraseProcess( pFlsJobControl );
            }
#endif /* #if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE ) */
 
            /* Set Non-programmable mode */
            ( void ) R_RFD_SetFlashMemoryMode( R_RFD_ENUM_FLASH_MODE_NONPROGRAMMABLE );
 
            break;
 
        case FLS_70_JOB_WRITE :
            /* Set Non-programmable mode */
            ( void ) R_RFD_SetFlashMemoryMode( R_RFD_ENUM_FLASH_MODE_NONPROGRAMMABLE );
 
#if ( FLS_WRITE_VERIFICATION_ENABLED != FALSE )
            if ( FLS_70_E_NOT_OK != g_Fls_CheckWrite ) {
                /* [SWS_Fls_00056] Conduct compare data after writting */
                lstatus = fls_70_RL78F2X_VerifyWriteProcess( pFlsJobControl );
            }
#endif /* #if ( FLS_WRITE_VERIFICATION_ENABLED != FALSE ) */
            break;
 
        case FLS_70_JOB_BLANKCHECK:
            /* Check Sequence End and Error */
            lstatus = fls_70_RL78F2X_CheckSequence( pFlsJobControl );
 
            /* Set Non-programmable mode */
            ( void ) R_RFD_SetFlashMemoryMode( R_RFD_ENUM_FLASH_MODE_NONPROGRAMMABLE );
 
            break;
 
        default :
            /* Do not busy loop because it takes time to process */
            /* Check Sequence End and Error */
            lstatus = fls_70_RL78F2X_CheckSequence( pFlsJobControl );
 
            break;
        }
 
        /* Disable Data flash access */
        fls_70_RL78F2X_AccessModeDisable();
    }
 
    return lstatus;
}
 
#define FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
 
/* EOF Fls_70_RL78F2X.c *******************************************************/
 
