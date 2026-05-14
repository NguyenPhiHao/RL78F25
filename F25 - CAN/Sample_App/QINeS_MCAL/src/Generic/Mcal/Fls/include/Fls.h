/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Fls.h                                                        */
/* Version     : v1.00.01                                                     */
/* Contents    : This header file is for AUTOSAR Basic Software module        */
/*               "Flash Driver".                                              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Flash Driver                                              */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef FLS_H
#define FLS_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Fls_Cfg.h"
#include "Fls_70_HW.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/

#define FLS_VENDOR_ID                   (70U)
#define FLS_MODULE_ID                   (92U)

#define FLS_AR_RELEASE_MAJOR_VERSION    (22U)    /* [SWS_BSW_00059] */
#define FLS_AR_RELEASE_MINOR_VERSION    (11U)    /* [SWS_BSW_00059] */
#define FLS_AR_RELEASE_REVISION_VERSION (0U)     /* [SWS_BSW_00059] */

#define FLS_SW_MAJOR_VERSION            (1U)
#define FLS_SW_MINOR_VERSION            (0U)
#define FLS_SW_PATCH_VERSION            (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Std_Types.h version check start */
#if ( ( FLS_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( FLS_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION )   \
    )
  #error "AUTOSAR Version Numbers of Fls.h and Std_Types.h are different"
#endif
/* Std_Types.h version check end */

/* Fls_Cfg.h version check start */

#if ( FLS_VENDOR_ID != FLS_70_VENDOR_ID_CFG_H )
  #error "VENDOR ID for Fls.h and Fls_Cfg.h are different"
#endif

#if ( FLS_MODULE_ID != FLS_70_MODULE_ID_CFG_H )
  #error "MODULE ID for Fls.h and Fls_Cfg.h are different"
#endif

#if ( ( FLS_AR_RELEASE_MAJOR_VERSION    != FLS_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( FLS_AR_RELEASE_MINOR_VERSION    != FLS_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( FLS_AR_RELEASE_REVISION_VERSION != FLS_70_AR_RELEASE_REVISION_VERSION_CFG_H )   \
    )
  #error "AUTOSAR Version Numbers of Fls.h and Fls_Cfg.h are different"
#endif

#if ( ( FLS_SW_MAJOR_VERSION != FLS_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( FLS_SW_MINOR_VERSION != FLS_70_SW_MINOR_VERSION_CFG_H ) || \
      ( FLS_SW_PATCH_VERSION != FLS_70_SW_PATCH_VERSION_CFG_H )       \
    )
  #error "Software Version Numbers of Fls.h and Fls_Cfg.h are different"
#endif

/* Fls_Cfg.h version check end */

/* Fls_70_HW.h version check start */

#if ( FLS_VENDOR_ID != FLS_70_VENDOR_ID_HW_H )
  #error "VENDOR ID for Fls.h and Fls_70_HW.h are different"
#endif

#if ( FLS_MODULE_ID != FLS_70_MODULE_ID_HW_H )
  #error "MODULE ID for Fls.h and Fls_70_HW.h are different"
#endif

#if ( ( FLS_AR_RELEASE_MAJOR_VERSION    != FLS_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( FLS_AR_RELEASE_MINOR_VERSION    != FLS_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( FLS_AR_RELEASE_REVISION_VERSION != FLS_70_AR_RELEASE_REVISION_VERSION_HW_H )   \
    )
  #error "AUTOSAR Version Numbers of Fls.h and Fls_70_HW.h are different"
#endif

#if ( ( FLS_SW_MAJOR_VERSION != FLS_70_SW_MAJOR_VERSION_HW_H ) || \
      ( FLS_SW_MINOR_VERSION != FLS_70_SW_MINOR_VERSION_HW_H ) || \
      ( FLS_SW_PATCH_VERSION != FLS_70_SW_PATCH_VERSION_HW_H )       \
    )
  #error "Software Version Numbers of Fls.h and Fls_70_HW.h are different"
#endif

/* Fls_70_HW.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/* Flash Instance ID */
#define FLS_70_INSTANCE_ID               0x0U

/* Development Errors */
#define FLS_E_PARAM_CONFIG               0x01U   /* [SWS_Fls_00004] */
#define FLS_E_PARAM_ADDRESS              0x02U   /* [SWS_Fls_00004] */
#define FLS_E_PARAM_LENGTH               0x03U   /* [SWS_Fls_00004] */
#define FLS_E_PARAM_DATA                 0x04U   /* [SWS_Fls_00004] */
#define FLS_E_UNINIT                     0x05U   /* [SWS_Fls_00004] */
#define FLS_E_PARAM_POINTER              0x0AU   /* [SWS_Fls_00004] */
#define FLS_E_ALREADY_INITIALIZED        0x0BU   /* [SWS_Fls_00004] */
#define FLS_70_E_PFDL_NOT_OPEN           0x0CU

/* Runtime Errors */
#define FLS_E_BUSY                       0x06U   /* [SWS_Fls_91001] */
#define FLS_E_VERIFY_ERASE_FAILED        0x07U   /* [SWS_Fls_91001] */
#define FLS_E_VERIFY_WRITE_FAILED        0x08U   /* [SWS_Fls_91001] */
#define FLS_E_TIMEOUT                    0x09U   /* [SWS_Fls_91001] */

/* Transient Faults */
#define FLS_E_ERASE_FAILED               0x01U   /* [SWS_Fls_91002] */
#define FLS_E_WRITE_FAILED               0x02U   /* [SWS_Fls_91002] */

/* ServiceID */
#define FLS_INIT_ID                      0x00U
#define FLS_ERASE_ID                     0x01U
#define FLS_WRITE_ID                     0x02U
#define FLS_CANCEL_ID                    0x03U
#define FLS_GETJOBRESULT_ID              0x05U
#define FLS_MAINFUNCTION_ID              0x06U
#define FLS_READ_ID                      0x07U
#define FLS_COMPARE_ID                   0x08U
#define FLS_SETMODE_ID                   0x09U
#define FLS_GETVERSIONINFO_ID            0x10U
#define FLS_BLANKCHECK_ID                0x0AU

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
/* pointer to config data */
extern const Fls_ConfigType FlsConfigData;

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/* [SWS_Fls_00248][SWS_Fls_00323] Fls module status */
extern MemIf_StatusType      Fls_Status;

/* [SWS_Fls_00248] Fls job result */
extern MemIf_JobResultType   Fls_JobResult;
extern MemIf_ModeType        Fls_Mode;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
/* external functions */
extern void               Fls_Init( const Fls_ConfigType* ConfigPtr );
extern Std_ReturnType     Fls_Erase( Fls_AddressType TargetAddress,
                                     Fls_LengthType  Length );
extern Std_ReturnType     Fls_Write( Fls_AddressType TargetAddress,
                                     const uint8*   SourceAddressPtr,
                                     Fls_LengthType  Length );

/* [SWS_Fls_00183] Compiler switch */
#if ( FLS_CANCEL_API != FALSE )
extern void               Fls_Cancel( void );
#endif

/* [SWS_Fls_00184] Compiler switch */
#if ( FLS_GET_STATUS_API != FALSE )
extern MemIf_StatusType      Fls_GetStatus( void );
#endif

/* [SWS_Fls_00185] Compiler switch */
#if ( FLS_GET_JOB_RESULT_API != FALSE )
extern MemIf_JobResultType   Fls_GetJobResult( void );
#endif

extern Std_ReturnType     Fls_Read( Fls_AddressType SourceAddress,
                                    uint8*          TargetAddressPtr,
                                    Fls_LengthType  Length );

/* [SWS_Fls_00186] Compiler switch */
#if ( FLS_COMPARE_API != FALSE )
extern Std_ReturnType     Fls_Compare( Fls_AddressType SourceAddress,
                                       const uint8*    TargetAddressPtr,
                                       Fls_LengthType  Length );
#endif

/* [SWS_Fls_00187] Compiler switch */
#if ( FLS_SET_MODE_API != FALSE )
extern void               Fls_SetMode( MemIf_ModeType Mode );
#endif

/* [ECUC_Fls_00293] Compiler switch */
#if ( FLS_VERSION_INFO_API != FALSE )
extern void Fls_GetVersionInfo( Std_VersionInfoType* VersioninfoPtr );
#endif

/* [ECUC_Fls_00319] Compiler switch */
#if ( FLS_BLANK_CHECK_API != FALSE )
extern Std_ReturnType Fls_BlankCheck( Fls_AddressType TargetAddress, Fls_LengthType Length );
#endif

#endif /* FLS_H */
/* EOF Fls.h ******************************************************/
