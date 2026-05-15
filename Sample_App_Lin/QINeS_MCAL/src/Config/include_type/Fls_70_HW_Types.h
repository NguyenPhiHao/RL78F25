/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Fls_70_HW_Types.h                                            */
/* Version     : v1.00.00                                                     */
/* Contents    : This header file is for HW Renesas Types Software            */
/*               module "Flash Driver".                                       */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
#ifndef FLS_70_HW_TYPES_H_
#define FLS_70_HW_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Fls_70_RL78F2X_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define FLS_70_VENDOR_ID_HW_TYPES_H             ( 70U )
#define FLS_70_MODULE_ID_HW_TYPES_H             ( 92U )

#define FLS_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    ( 22U )
#define FLS_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    ( 11U )
#define FLS_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H (  0U )

#define FLS_70_SW_MAJOR_VERSION_HW_TYPES_H       ( 1U )
#define FLS_70_SW_MINOR_VERSION_HW_TYPES_H       ( 0U )
#define FLS_70_SW_PATCH_VERSION_HW_TYPES_H       ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Fls_70_RL78F2X_Types.h version check start */
#if ( FLS_70_VENDOR_ID_HW_TYPES_H != FLS_70_VENDOR_ID_RL78F2X_TYPES_H )
# error "VENDOR ID for Fls_70_HW_Types.h and Fls_70_RL78F2X_Types.h are different"
#endif

#if ( FLS_70_MODULE_ID_HW_TYPES_H != FLS_70_MODULE_ID_RL78F2X_TYPES_H )
# error "MODULE ID for Fls_70_HW_Types.h and Fls_70_RL78F2X_Types.h are different"
#endif

#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    != FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H   ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    != FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H   ) || \
      ( FLS_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H != FLS_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H ) )
# error "AUTOSAR Version Numbers of Fls_70_HW_Types.h and Fls_70_RL78F2X_Types.h are different"
#endif

#if ( ( FLS_70_SW_MAJOR_VERSION_HW_TYPES_H   != FLS_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( FLS_70_SW_MINOR_VERSION_HW_TYPES_H   != FLS_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( FLS_70_SW_PATCH_VERSION_HW_TYPES_H   != FLS_70_SW_PATCH_VERSION_RL78F2X_TYPES_H ) )
# error "Software Version Numbers of Fls_70_HW_Types.h and Fls_70_RL78F2X_Types.h are different"
#endif

/* Fls_70_RL78F2X_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef Fls_70_RL78F2X_ExecuteStatusType      Fls_70_HW_ExecuteStatusType;
typedef Fls_70_RL78F2X_CheckCfDSeqEndStatusType Fls_70_HW_CheckCfDSeqEndStatusType;

#endif /* FLS_70_HW_TYPES_H_ */

/* EOF Fls_70_HW_Types.h ****************************************/
