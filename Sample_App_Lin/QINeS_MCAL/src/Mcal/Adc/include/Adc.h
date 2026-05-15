/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc.h                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    : This header file is for AUTOSAR Basic Software               */
/*               module "ADC Driver"                                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
#ifndef ADC_H_
#define ADC_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc_Cfg.h"
#include "Adc_70_Types.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_VENDOR_ID                       (70U)
#define ADC_MODULE_ID                       (123U)

#define ADC_AR_RELEASE_MAJOR_VERSION        (22U)
#define ADC_AR_RELEASE_MINOR_VERSION        (11U)
#define ADC_AR_RELEASE_REVISION_VERSION     (0U)

#define ADC_SW_MAJOR_VERSION                (1U)
#define ADC_SW_MINOR_VERSION                (0U)
#define ADC_SW_PATCH_VERSION                (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Adc_Cfg.h version check start */
#if ( ADC_VENDOR_ID != ADC_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Adc.h and Adc_Cfg.h are different"
#endif

#if ( ADC_MODULE_ID != ADC_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Adc.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_AR_RELEASE_MAJOR_VERSION    != ADC_70_AR_RELEASE_MAJOR_VERSION_CFG_H    ) || \
      ( ADC_AR_RELEASE_MINOR_VERSION    != ADC_70_AR_RELEASE_MINOR_VERSION_CFG_H    ) || \
      ( ADC_AR_RELEASE_REVISION_VERSION != ADC_70_AR_RELEASE_REVISION_VERSION_CFG_H )    \
    )
    #error "AUTOSAR Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_SW_MAJOR_VERSION != ADC_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( ADC_SW_MINOR_VERSION != ADC_70_SW_MINOR_VERSION_CFG_H ) || \
      ( ADC_SW_PATCH_VERSION != ADC_70_SW_PATCH_VERSION_CFG_H )    \
    )
    #error "Software Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif
/* Adc_Cfg.h version check end */

/* Adc_70_Types.h version check start */
#if ( ADC_VENDOR_ID   != ADC_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Adc.h and Adc_70_Types.h are different"
#endif

#if ( ADC_MODULE_ID   != ADC_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Adc.h and Adc_70_Types.h are different"
#endif

#if ( ( ADC_AR_RELEASE_MAJOR_VERSION    != ADC_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    ) || \
      ( ADC_AR_RELEASE_MINOR_VERSION    != ADC_70_AR_RELEASE_MINOR_VERSION_TYPES_H    ) || \
      ( ADC_AR_RELEASE_REVISION_VERSION != ADC_70_AR_RELEASE_REVISION_VERSION_TYPES_H )    \
    )
    #error "AUTOSAR Version Numbers of Adc.h and Adc_70_Types.h are different"
#endif

#if ( ( ADC_SW_MAJOR_VERSION != ADC_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( ADC_SW_MINOR_VERSION != ADC_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( ADC_SW_PATCH_VERSION != ADC_70_SW_PATCH_VERSION_TYPES_H )    \
    )
    #error "Software Version Numbers of Adc.h and Adc_70_Types.h are different"
#endif
/* Adc_70_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* configuration checks                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

#define ADC_70_INSTANCE_ID                   (0U)   /* Adc module instance ID */

/* --- DET ERROR CODE DEFINE ------------------------------------------------ */
/* Development Errors */
#define ADC_E_UNINIT                         (0x0AU)
#define ADC_E_ALREADY_INITIALIZED            (0x0DU)
#define ADC_E_PARAM_POINTER                  (0x14U)
#define ADC_E_PARAM_GROUP                    (0x15U)
#define ADC_E_WRONG_CONV_MODE                (0x16U)
#define ADC_E_WRONG_TRIGG_SRC                (0x17U)
#define ADC_E_NOTIF_CAPABILITY               (0x18U)
#define ADC_E_BUFFER_UNINIT                  (0x19U)

/* Runtime Errors */
#define ADC_E_BUSY                           (0x0BU)
#define ADC_E_IDLE                           (0x0CU)

/* ADC Service ID */
#define ADC_70_INIT_ID                       (0x00U)       /* [SWS_Adc_00365] */
#define ADC_70_DEINIT_ID                     (0x01U)       /* [SWS_Adc_00366] */
#define ADC_70_START_GROUP_CONVERSION_ID     (0x02U)       /* [SWS_Adc_00367] */
#define ADC_70_STOP_GROUP_CONVERSION_ID      (0x03U)       /* [SWS_Adc_00368] */
#define ADC_70_READ_GROUP_ID                 (0x04U)       /* [SWS_Adc_00369] */
#define ADC_70_ENABLE_HARDWARE_TRIGGER_ID    (0x05U)       /* [SWS_Adc_00370] */
#define ADC_70_DISABLE_HARDWARE_TRIGGER_ID   (0x06U)       /* [SWS_Adc_00371] */
#define ADC_70_ENABLE_GROUP_NOTIFICATION_ID  (0x07U)       /* [SWS_Adc_00372] */
#define ADC_70_DISABLE_GROUP_NOTIFICATION_ID (0x08U)       /* [SWS_Adc_00373] */
#define ADC_70_GET_GROUP_STATUS_ID           (0x09U)       /* [SWS_Adc_00374] */
#define ADC_70_GET_VERSION_INFO_ID           (0x0AU)       /* [SWS_Adc_00376] */
#define ADC_70_GET_STREAM_LAST_POINTER_ID    (0x0BU)       /* [SWS_Adc_00375] */
#define ADC_70_SETUP_RESULT_BUFFER_ID        (0x0CU)       /* [SWS_Adc_00419] */

/*----------------------------------------------------------------------------*/
/* external data                                                              */
/*----------------------------------------------------------------------------*/
#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

extern const Adc_ConfigType Adc_Config;

#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define ADC_START_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

extern void Adc_Init( const Adc_ConfigType* ConfigPtr );
extern Std_ReturnType Adc_SetupResultBuffer( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr );

#if ( ADC_DEINIT_API != FALSE )
extern void Adc_DeInit( void );
#endif /* #if ( ADC_DEINIT_API != FALSE ) */

#if ( ADC_ENABLE_START_STOP_GROUP_API != FALSE )
extern void Adc_StartGroupConversion( Adc_GroupType Group );
extern void Adc_StopGroupConversion(  Adc_GroupType Group );
#endif /* #if ( ADC_ENABLE_START_STOP_GROUP_API != FALSE ) */

#if ( ADC_READ_GROUP_API != FALSE )
extern Std_ReturnType Adc_ReadGroup( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr );
#endif /* #if ( ADC_READ_GROUP_API != FALSE ) */

#if ( ADC_HW_TRIGGER_API != FALSE )
extern void Adc_EnableHardwareTrigger(  Adc_GroupType Group );
extern void Adc_DisableHardwareTrigger( Adc_GroupType Group );
#endif /* #if ( ADC_HW_TRIGGER_API != FALSE ) */

#if ( ADC_GRP_NOTIF_CAPABILITY != FALSE )
extern void Adc_EnableGroupNotification(  Adc_GroupType Group );
extern void Adc_DisableGroupNotification( Adc_GroupType Group );
extern Adc_StatusType Adc_GetGroupStatus( Adc_GroupType Group );
extern Adc_StreamNumSampleType Adc_GetStreamLastPointer( Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr );
#endif /* #if ( ADC_GRP_NOTIF_CAPABILITY != FALSE ) */

#if ( ADC_VERSION_INFO_API != FALSE )
extern void Adc_GetVersionInfo( Std_VersionInfoType* VersionInfo );
#endif /* #if ( ADC_VERSION_INFO_API != FALSE ) */

extern void Adc_70_Isr_Common( Adc_70_HwUnitIdType hwUnitId, Adc_70_IntGrpIdType intGrpId );

#define ADC_STOP_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

#endif /* ADC_H */

/* EOF Adc.h ******************************************************************/