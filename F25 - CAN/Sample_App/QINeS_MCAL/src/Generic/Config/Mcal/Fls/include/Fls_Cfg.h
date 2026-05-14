/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Fls_Cfg.h                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : This header file is for AUTOSAR Basic Software module        */
/*               "Flash Driver".                                              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Flash Driver                                              */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef FLS_CFG_H
#define FLS_CFG_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "MemIf.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define FLS_70_VENDOR_ID_CFG_H                      ( 70U )
#define FLS_70_MODULE_ID_CFG_H                      ( 92U )

#define FLS_70_AR_RELEASE_MAJOR_VERSION_CFG_H       ( 22U )
#define FLS_70_AR_RELEASE_MINOR_VERSION_CFG_H       ( 11U )
#define FLS_70_AR_RELEASE_REVISION_VERSION_CFG_H    ( 0U )

#define FLS_70_SW_MAJOR_VERSION_CFG_H               ( 1U )
#define FLS_70_SW_MINOR_VERSION_CFG_H               ( 0U )
#define FLS_70_SW_PATCH_VERSION_CFG_H               ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* MemIf.h version check start */
 
#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_CFG_H != MEMIF_AR_RELEASE_MAJOR_VERSION ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_CFG_H != MEMIF_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Fls_Cfg.h andMemIf.h are different"
#endif

/* MemIf.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/* [ECUC_Fls_00172] FlsGeneral */
#define FLS_BASE_ADDRESS                0xF1000U              /* [ECUC_Fls_00169] (1)(0..4294967295) */
#define FLS_CANCEL_API                  TRUE                  /* [ECUC_Fls_00285] (1) */
#define FLS_COMPARE_API                 TRUE                  /* [ECUC_Fls_00286] (1) */
#define FLS_DEV_ERROR_DETECT            TRUE                  /* [ECUC_Fls_00287] (1) */
#define FLS_GET_JOB_RESULT_API          TRUE                  /* [ECUC_Fls_00289] (1) */
#define FLS_GET_STATUS_API              TRUE                  /* [ECUC_Fls_00290] (1) */
#define FLS_SET_MODE_API                TRUE                  /* [ECUC_Fls_00291] (1) */
#define FLS_TOTAL_SIZE                  0x03FFFUL             /* [ECUC_Fls_00170] (1)(0..4294967295) */
#define FLS_VERSION_INFO_API            TRUE                  /* [ECUC_Fls_00293] (1) */
#define FLS_BLANK_CHECK_API             TRUE                  /* [ECUC_Fls_00319] (1) */
#define FLS_ERASE_VERIFICATION_ENABLED  TRUE                  /* [ECUC_Fls_00321] (1) */
#define FLS_WRITE_VERIFICATION_ENABLED  TRUE                  /* [ECUC_Fls_00320] (1) */
#define FLS_TIMEOUT_SUPERVISION_ENABLED TRUE                  /* [ECUC_Fls_00322] (1) */
#define FLS_MAIN_FUNCTION_PERIOD        0.2F                  /* [ECUC_Fls_00306] (1)(0..1) */
#define FLS_ERASE_TIMEOUT_COUNT         1.2F
#define FLS_WRITE_TIMEOUT_COUNT         1.4F
#define FLS_READ_TIMEOUT_COUNT          0.8F

/* [ECUC_Fls_00174] FlsConfigSet */
#define FLS_AC_ERASE                0U                        /* [ECUC_Fls_00270] (1)(0..4294967295) */
#define FLS_AC_WRITE                0U                        /* [ECUC_Fls_00305] (1)(0..4294967295) */
#define FLS_DEFAULT_MODE            MEMIF_MODE_FAST           /* [ECUC_Fls_00318] (1)(0..1) */
#define FLS_JOB_END_NOTIFICATION    Fee_JobEndNotification    /* [ECUC_Fls_00307] (0..1) */
#define FLS_JOB_ERROR_NOTIFICATION  Fee_JobErrorNotification  /* [ECUC_Fls_00274] (0..1) */
#define FLS_MAX_READ_FAST_MODE      256U                      /* [ECUC_Fls_00275] (1)(0..4294967295) */
#define FLS_MAX_READ_NORMAL_MODE    16U                       /* [ECUC_Fls_00276] (1)(0..4294967295) */
#define FLS_MAX_WRITE_FAST_MODE     256U                      /* [ECUC_Fls_00277] (1)(0..4294967295) */
#define FLS_MAX_WRITE_NORMAL_MODE   16U                       /* [ECUC_Fls_00278] (1)(0..4294967295) */
#define FLS_PROTECTION              0x00000000U               /* [ECUC_Fls_00279] (1)(0..4294967295) */

/* maximum numbers */
#define FLS_70_MAX_NUMBER_SECTOR       ( uint16 )1            /* Maximum number of sector */

/* CPU operation frequency(MHz) */
#define FLS_70_FREQUENCY        40U

/* 10 shifts to the left */
#define FLS_70_LEFT_SHIFT       0x0AU

/* Number of continuous sectors with identical values for FlsSectorSize and FlsPageSize. */
#define FLS_70_NUMBER_OF_SECTORS        ( uint32 )0x400U

/* FlsDriverIndex is the value referenced by Fee */
#define FlsConf_FlsGeneral_FlsGeneral    0U
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
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

#endif /* FLS_CFG_H */
/* EOF Fls_Cfg.h **************************************************************/
