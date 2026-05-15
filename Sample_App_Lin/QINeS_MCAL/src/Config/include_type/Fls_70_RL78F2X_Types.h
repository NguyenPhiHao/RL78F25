/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Fls_70_RL78F2X_Types.h                                       */
/* Version     : v1.00.00                                                     */
/* Contents    : FLS Module type definition header                            */
/*               The FLS is a basic software module at the service            */
/*               layer of the standardized basic software                     */
/*               architecture of AUTOSAR                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
#ifndef FLS_70_RL78F2X_TYPES_H_
#define FLS_70_RL78F2X_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define FLS_70_VENDOR_ID_RL78F2X_TYPES_H           ( 70U )
#define FLS_70_MODULE_ID_RL78F2X_TYPES_H           ( 92U )

#define FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H   ( 22U )
#define FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H   ( 11U )
#define FLS_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H(  0U )

#define FLS_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H     ( 1U )
#define FLS_70_SW_MINOR_VERSION_RL78F2X_TYPES_H     ( 0U )
#define FLS_70_SW_PATCH_VERSION_RL78F2X_TYPES_H     ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

typedef enum
{
    /* operation related status */
    FLS_70_EXEC_IDLE            = ( 0x00u ), /* 0x00, RFD: Ready to receive requests */
    FLS_70_EXEC_OK              = ( 0x01u ), /* 0x01, Command finished without problems */
    FLS_70_EXEC_BUSY            = ( 0x02u ), /* 0x02, Command is being processed */

    /* flash related status */
    FLS_70_EXEC_ERR_PROTECTION  = ( 0x03u ), /* 0x03, Protection error (access right conflict) */
    FLS_70_EXEC_ERR_ERASE       = ( 0x04u ), /* 0x04, Erase error */
    FLS_70_EXEC_ERR_MARGIN      = ( 0x05u ), /* 0x05, Verify margin violated */
    FLS_70_EXEC_ERR_WRITE       = ( 0x06u ), /* 0x06, Write error */
    FLS_70_EXEC_ERR_PARAMETER   = ( 0x07u ), /* 0x07, Parameter error */
    FLS_70_EXEC_ERR_BLANKCHECK  = ( 0x08u )  /* 0x08, Blankcheck violated */
} Fls_70_RL78F2X_ExecuteStatusType;

typedef enum
{
    /* operation related status */
    FLS_70_CHECKCFDSEQEND_OK              = ( 0x00u ), /* 0x00, Successful completion */
    FLS_70_CHECKCFDSEQEND_IDLE            = ( 0x01u ), /* 0x01, CF/DF sequencer idle */
    FLS_70_CHECKCFDSEQEND_BUSY            = ( 0x02u ), /* 0x02, CF/DF sequencer busy */

    /* CF/DF sequencer related status */
    FLS_70_CHECKCFDSEQEND_ERR_CFDF_SEQUENCER = ( 0x03u ), /* 0x03, CF/DF sequencer error */
    FLS_70_CHECKCFDSEQEND_ERR_ERASE          = ( 0x04u ), /* 0x04, Erase error */
    FLS_70_CHECKCFDSEQEND_ERR_WRITE          = ( 0x05u ), /* 0x05, Write error */
    FLS_70_CHECKCFDSEQEND_ERR_MARGIN         = ( 0x06u ), /* 0x06, Verify margin violated */
    FLS_70_CHECKCFDSEQEND_ERR_BLANKCHECK     = ( 0x07u ), /* 0x07, Blankcheck violated */

    /* CF/DF Check Job control */
    FLS_70_CHECKCFDSEQEND_NULL           = ( 0x08u )  /* 0x08, Job control is NULL pointer */
} Fls_70_RL78F2X_CheckCfDSeqEndStatusType;


#endif /* FLS_70_RL78F2X_TYPES_H_ */

/* EOF Fls_70_RL78F2X_Types.h ****************************************/
