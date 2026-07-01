/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_70_RL78F2X.h                                             */
/* Version     : v1.00.01                                                     */
/* Contents    : ADC Module HW dependent header                               */
/*               The ADC is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef ADC_70_RL78F2X_H
#define ADC_70_RL78F2X_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc_Cfg.h"
#include "Adc_70_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_RL78F2X_H                ( 70U )
#define ADC_70_MODULE_ID_RL78F2X_H                (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ( 22U )
#define ADC_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ( 11U )
#define ADC_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ( 0U )

#define ADC_70_SW_MAJOR_VERSION_RL78F2X_H         (  1U )
#define ADC_70_SW_MINOR_VERSION_RL78F2X_H         (  0U )
#define ADC_70_SW_PATCH_VERSION_RL78F2X_H         (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Adc_Cfg.h version check start */
#if ( ADC_70_VENDOR_ID_RL78F2X_H != ADC_70_VENDOR_ID_CFG_H )
  #error "VENDOR ID for Adc_70_RL78F2X.h and Adc_Cfg.h are different"
#endif

#if ( ADC_70_MODULE_ID_RL78F2X_H != ADC_70_MODULE_ID_CFG_H )
  #error "MODULE ID for Adc_70_RL78F2X.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != ADC_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != ADC_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != ADC_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
  #error "AUTOSAR Version Numbers of Adc_70_RL78F2X.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_RL78F2X_H  != ADC_70_SW_MAJOR_VERSION_CFG_H )  || \
      ( ADC_70_SW_MINOR_VERSION_RL78F2X_H  != ADC_70_SW_MINOR_VERSION_CFG_H )  || \
      ( ADC_70_SW_PATCH_VERSION_RL78F2X_H  != ADC_70_SW_PATCH_VERSION_CFG_H )   )
  #error "Software Version Numbers of Adc_70_RL78F2X.h and Adc_Cfg.h are different"
#endif
/* Adc_Cfg.h version check end */

/* Adc_70_Types.h version check start */
#if ( ADC_70_VENDOR_ID_RL78F2X_H  != ADC_70_VENDOR_ID_RL78F2X_TYPES_H )
  #error "VENDOR ID for Adc_70_RL78F2X.h and Adc_70_RL78F2X_Types.h are different"
#endif

#if ( ADC_70_MODULE_ID_RL78F2X_H  != ADC_70_MODULE_ID_RL78F2X_TYPES_H )
  #error "MODULE ID for Adc_70_RL78F2X.h and Adc_70_RL78F2X_Types.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H  != ADC_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H  != ADC_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H!= ADC_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H ) )
  #error "AUTOSAR Version Numbers of Adc_70_RL78F2X.h and Adc_70_RL78F2X_Types.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_RL78F2X_H  != ADC_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( ADC_70_SW_MINOR_VERSION_RL78F2X_H  != ADC_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( ADC_70_SW_PATCH_VERSION_RL78F2X_H  != ADC_70_SW_PATCH_VERSION_RL78F2X_TYPES_H ) )
  #error "Software Version Numbers of Adc_70_RL78F2X.h and Adc_70_RL78F2X_Types.h are different"
#endif
/* Adc_70_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                     */
/*----------------------------------------------------------------------------*/
#define ADC_70_WAIT_10US                ( 100U )

/*----------------------------------------------------------------------------*/
/* H/W dependent definitions */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external constant */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern void Adc_70_RL78F2X_Init(const Adc_HwUnitType* hwDefPtr);

#if (ADC_DEINIT_API != FALSE)
extern void Adc_70_RL78F2X_DeInit(const Adc_HwUnitType* hwDefPtr);
#endif /* if (ADC_DEINIT_API != FALSE) */

extern void Adc_70_RL78F2X_StartConvert(
    const Adc_70_GroupInfoType*       gpPtr,
    const Adc_GroupConfigurationType* gpDefPtr
);

extern void Adc_70_RL78F2X_StopConvert(
    const Adc_70_GroupInfoType*       gpPtr,
    const Adc_GroupConfigurationType* gpDefPtr
);

extern void Adc_70_RL78F2X_HwStopConvert(
    const Adc_70_GroupInfoType*       gpPtr,
    const Adc_GroupConfigurationType* gpDefPtr
);

extern Adc_ValueGroupType Adc_70_RL78F2X_GetAdcValue(Adc_ChannelType hwChannelId);

/*----------------------------------------------------------------------------*/
/* functions and function style macros                         */
/*----------------------------------------------------------------------------*/

#endif /* ADC_70_RL78F2X_H */

/* EOF ADC_70_RL78F2X.h **********************************************/
