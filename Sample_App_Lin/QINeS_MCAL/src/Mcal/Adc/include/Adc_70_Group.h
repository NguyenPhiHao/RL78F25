/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_70_Group.h                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : ADC Module start/stop for group header                       */
/*               The ADC is a basic software module at the service            */
/*               layer of the standardized basic software                     */
/*               architecture of AUTOSAR.                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef ADC_70_GROUP_H
#define ADC_70_GROUP_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc_Cfg.h"
#include "Adc_70_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_GROUP_H                           ( 70U  )
#define ADC_70_MODULE_ID_GROUP_H                           ( 123U )

#define ADC_70_AR_RELEASE_MAJOR_VERSION_GROUP_H            ( 22U  )
#define ADC_70_AR_RELEASE_MINOR_VERSION_GROUP_H            ( 11U  )
#define ADC_70_AR_RELEASE_REVISION_VERSION_GROUP_H         ( 0U   )

#define ADC_70_SW_MAJOR_VERSION_GROUP_H                    ( 1U )
#define ADC_70_SW_MINOR_VERSION_GROUP_H                    ( 0U )
#define ADC_70_SW_PATCH_VERSION_GROUP_H                    ( 0U )

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Adc_Cfg.h version check start                                              */
/*----------------------------------------------------------------------------*/

#if ( ADC_70_VENDOR_ID_GROUP_H != ADC_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Adc_70_Group.h and Adc_Cfg.h are different"
#endif

#if ( ADC_70_MODULE_ID_GROUP_H != ADC_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Adc_70_Group.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_GROUP_H   != ADC_70_AR_RELEASE_MAJOR_VERSION_CFG_H    ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_GROUP_H   != ADC_70_AR_RELEASE_MINOR_VERSION_CFG_H    ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_GROUP_H!= ADC_70_AR_RELEASE_REVISION_VERSION_CFG_H )    \
    )
    #error "AUTOSAR Version Numbers of Adc_70_Group.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_GROUP_H != ADC_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( ADC_70_SW_MINOR_VERSION_GROUP_H != ADC_70_SW_MINOR_VERSION_CFG_H ) || \
      ( ADC_70_SW_PATCH_VERSION_GROUP_H != ADC_70_SW_PATCH_VERSION_CFG_H )    \
    )
  #error "Software Version Numbers of Adc_70_Group.h and Adc_Cfg.h are different"
#endif
/* Adc_Cfg.h version check end */

/* Adc_70_Types.h version check start */
#if ( ADC_70_VENDOR_ID_GROUP_H != ADC_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Adc_70_Group.h and Adc_70_Types.h are different"
#endif

#if ( ADC_70_MODULE_ID_GROUP_H != ADC_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Adc_70_Group.h and Adc_70_Types.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_GROUP_H    != ADC_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_GROUP_H    != ADC_70_AR_RELEASE_MINOR_VERSION_TYPES_H    ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_GROUP_H != ADC_70_AR_RELEASE_REVISION_VERSION_TYPES_H )    \
    )
    #error "AUTOSAR Version Numbers of Adc_70_Group.h and Adc_70_Types.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_GROUP_H != ADC_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( ADC_70_SW_MINOR_VERSION_GROUP_H != ADC_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( ADC_70_SW_PATCH_VERSION_GROUP_H != ADC_70_SW_PATCH_VERSION_TYPES_H )    \
    )
    #error "Software Version Numbers of Adc_70_Group.h and Adc_70_Types.h are different"
#endif
/* Adc_70_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external constant                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define ADC_START_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

extern void Adc_70_Group_StartConversion(
    Adc_70_HwInfoType*        hwInfoPtr,
    Adc_70_GroupInfoType*     gpPtr,
    Adc_StatusType            status
);

extern void Adc_70_Group_StopConversion(
    Adc_70_HwInfoType*        hwInfoPtr,
    Adc_70_GroupInfoType*     gpPtr,
    Adc_StatusType            status
);

#define ADC_STOP_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

#endif /* #ifndef ADC_70_GROUP_H */

/* EOF Adc_70_Group.h ********************************************/
