/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Fls_70_RL78F2X.h                                             */
/* Version     : v1.00.02                                                     */
/* Contents    : FLS Module HW dependent header                               */
/*                The FLS is a basic software module at the service           */
/*                layer of the standardized basic software                    */
/*                architecture of AUTOSAR.                                    */
/* Author      : --                                                           */
/* Note        : --                                                           */-                                                          */
/******************************************************************************/
/* Specification of Flash Driver                                              */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef FLS_70_RL78F2X_H
#define FLS_70_RL78F2X_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Fls_70_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define FLS_70_VENDOR_ID_RL78F2X_H                 (70U)
#define FLS_70_MODULE_ID_RL78F2X_H                 (92U)

#define FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H  (22U)
#define FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H  (11U)
#define FLS_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H (0U)

#define FLS_70_SW_MAJOR_VERSION_RL78F2X_H          (1U)
#define FLS_70_SW_MINOR_VERSION_RL78F2X_H          (0U)
#define FLS_70_SW_PATCH_VERSION_RL78F2X_H          (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Std_Types.h version check start */
#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )    \
    )
  #error "AUTOSAR Version Numbers of Fls_70_RL78F2X.h and Std_Types.h are different"
#endif
/* Std_Types.h version check end */

/* Fls_70_Types.h version check start */

#if ( FLS_70_VENDOR_ID_RL78F2X_H != FLS_70_VENDOR_ID_TYPES_H )
  #error "VENDOR ID for Fls_70_RL78F2X.h and Fls_70_Types.h are different"
#endif

#if ( FLS_70_MODULE_ID_RL78F2X_H != FLS_70_MODULE_ID_TYPES_H )
  #error "MODULE ID for Fls_70_RL78F2X.h and Fls_70_Types.h are different"
#endif

#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    != FLS_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    != FLS_70_AR_RELEASE_MINOR_VERSION_TYPES_H    ) || \
      ( FLS_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != FLS_70_AR_RELEASE_REVISION_VERSION_TYPES_H )    \
    )
  #error "AUTOSAR Version Numbers of Fls_70_RL78F2X.h and Fls_70_Types.h are different"
#endif

#if ( ( FLS_70_SW_MAJOR_VERSION_RL78F2X_H   != FLS_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( FLS_70_SW_MINOR_VERSION_RL78F2X_H   != FLS_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( FLS_70_SW_PATCH_VERSION_RL78F2X_H   != FLS_70_SW_PATCH_VERSION_TYPES_H )    \
    )
  #error "Software Version Numbers of Fls_70_RL78F2X.h and Fls_70_Types.h are different"
#endif

/* Fls_70_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define Fls_70_RL78F2X_CSC         (*(volatile uint8 QL_70_NEAR *)0xFFA1 )
#define Fls_70_RL78F2X_HIOSTOP     ( Fls_70_RL78F2X_CSC & 0x01U )

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
/* HIOSTOP parameter */
/* HIOSTOP is no. 0 bit of CRC register, defined in line 4738 on iodefine.h */
#define HIOSTOP_STATE_RUN          ( 0U )    /* Highspeed on chip oscillator is on */

/* sequencer error bit */
/* refer to page 50 of the file below */
/* r20ut5009j0100-r178.pdf ( RL78F24 flash library manual ) */
#define FLS_RL78F2X_SEQ_ERR_NONE               ( 0x00U )  /* No error */
#define FLS_RL78F2X_SEQ_ERR_ERASE_BIT          ( 0x01U )  /* Bit0, Erase error */
#define FLS_RL78F2X_SEQ_ERR_WRITE_BIT          ( 0x02U )  /* Bit1, Write error */
#define FLS_RL78F2X_SEQ_ERR_VERIFY_BIT         ( 0x04U )  /* Bit2, Verify error */
#define FLS_RL78F2X_SEQ_ERR_BLANKCHECK_BIT     ( 0x08U )  /* Bit3, Blankcheck error */
#define FLS_RL78F2X_SEQ_ERR_CPDF_SEQUENCER_BIT ( 0x10U )  /* Bit4, CPDF area sequencer error */
#define FLS_RL78F2X_SEQ_ERR_EXTRA_SEQUENCER_BIT ( 0x20U ) /* Bit5, Extra area sequencer error */
#define FLS_RL78F2X_SEQ_ERR_ALL  ( FLS_RL78F2X_SEQ_ERR_ERASE_BIT       | \
                                 FLS_RL78F2X_SEQ_ERR_WRITE_BIT       | \
                                 FLS_RL78F2X_SEQ_ERR_VERIFY_BIT      | \
                                 FLS_RL78F2X_SEQ_ERR_BLANKCHECK_BIT  | \
                                 FLS_RL78F2X_SEQ_ERR_CPDF_SEQUENCER_BIT | \
                                 FLS_RL78F2X_SEQ_ERR_EXTRA_SEQUENCER_BIT )

/* Length to check verify erase job completely after erased */
#define FLS_RL78F2X_VERIFY_ERASE_LENGTH    ( uint16 )( 1024U )

/* external variables                                                         */ */
extern uint8 g_Fls_CheckErase;
extern uint8 g_Fls_CheckWrite;

#if ( FLS_ERASE_VERIFICATION_ENABLED != FALSE )
extern uint8 g_Fls_VerifyErase;
#endif /* FLS_ERASE_VERIFICATION_ENABLED != FALSE */

#if ( FLS_WRITE_VERIFICATION_ENABLED != FALSE )
extern uint8 g_Fls_VerifyWrite;
#endif /* FLS_WRITE_VERIFICATION_ENABLED != FALSE */

/* static variables                                                           */ */

/* function prototype declarations                                            */
extern uint8 Fls_70_RL78F2X_Init( void );
extern Fls_70_RL78F2X_CheckCDFDSeqEndStatusType Fls_70_RL78F2X_Execute( Fls_70_ControlType* pFlsJobControl );

/* functions and function style macros */

#endif /* FLS_70_RL78F2X_H */

/* EOF Fls_70_RL78F2X.h ***************************************************/
