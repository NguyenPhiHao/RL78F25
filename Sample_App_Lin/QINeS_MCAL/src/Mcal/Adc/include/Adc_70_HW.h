/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_70_HW.h                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : ADC Module wrapper header                                    */
/*               The ADC is a basic software module at the service            */
/*               layer of the standardized basic software                     */
/*               architecture of AUTOSAR.                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */

#ifndef ADC_70_HW_H
#define ADC_70_HW_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Adc_Cfg.h"
#include "Adc_70_Types.h"
#include "Adc_70_RL78F2x.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_HW_H                   (70U)
#define ADC_70_MODULE_ID_HW_H                   (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_HW_H    (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_HW_H    (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_HW_H (0U)

#define ADC_70_SW_MAJOR_VERSION_HW_H            (1U)
#define ADC_70_SW_MINOR_VERSION_HW_H            (0U)
#define ADC_70_SW_PATCH_VERSION_HW_H            (0U)

/* file version checks */

/* Adc_Cfg.h version check start */
#if ( ADC_70_VENDOR_ID_HW_H != ADC_70_VENDOR_ID_CFG_H )
  #error "VENDOR ID for Adc_70_Hw.h and Adc_Cfg.h are different"
#endif

#if ( ADC_70_MODULE_ID_HW_H != ADC_70_MODULE_ID_CFG_H )
  #error "MODULE ID for Adc_70_Hw.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_HW_H    != ADC_70_AR_RELEASE_MAJOR_VERSION_CFG_H    ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_HW_H    != ADC_70_AR_RELEASE_MINOR_VERSION_CFG_H    ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_HW_H != ADC_70_AR_RELEASE_REVISION_VERSION_CFG_H )    \
    )
  #error "AUTOSAR Version Numbers of Adc_70_Hw.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_HW_H != ADC_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( ADC_70_SW_MINOR_VERSION_HW_H != ADC_70_SW_MINOR_VERSION_CFG_H ) || \
      ( ADC_70_SW_PATCH_VERSION_HW_H != ADC_70_SW_PATCH_VERSION_CFG_H )    \
    )
  #error "Software Version Numbers of Adc_70_Hw.h and Adc_Cfg.h are different"
#endif
/* Adc_Cfg.h version check end */

/* Adc_70_Types.h version check start */
#if ( ADC_70_VENDOR_ID_HW_H != ADC_70_VENDOR_ID_TYPES_H )
  #error "VENDOR ID for Adc_70_Hw.h and Adc_70_Types.h are different"
#endif

#if ( ADC_70_MODULE_ID_HW_H != ADC_70_MODULE_ID_TYPES_H )
  #error "MODULE ID for Adc_70_Hw.h and Adc_70_Types.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_HW_H    != ADC_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_HW_H    != ADC_70_AR_RELEASE_MINOR_VERSION_TYPES_H    ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_HW_H != ADC_70_AR_RELEASE_REVISION_VERSION_TYPES_H )    \
    )
  #error "AUTOSAR Version Numbers of Adc_70_Hw.h and Adc_70_Types.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_HW_H != ADC_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( ADC_70_SW_MINOR_VERSION_HW_H != ADC_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( ADC_70_SW_PATCH_VERSION_HW_H != ADC_70_SW_PATCH_VERSION_TYPES_H )    \
    )
  #error "Software Version Numbers of Adc_70_Hw.h and Adc_70_Types.h are different"
#endif
/* Adc_70_Types.h version check end */

/* Adc_70_RL78F2X.h version check start */
#if ( ADC_70_VENDOR_ID_HW_H != ADC_70_VENDOR_ID_RL78F2X_H )
  #error "VENDOR ID for Adc_70_Hw.h and Adc_70_RL78F2x.h are different"
#endif

#if ( ADC_70_MODULE_ID_HW_H != ADC_70_MODULE_ID_RL78F2X_H )
  #error "MODULE ID for Adc_70_Hw.h and Adc_70_RL78F2x.h are different"
#endif

/* Adc_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define Adc_70_HW_Init( hwDefPtr )                  Adc_70_RL78F2X_Init( ( hwDefPtr ) )

#if ( ADC_DEINIT_API != FALSE )
#define Adc_70_HW_DeInit( hwDefPtr )                Adc_70_RL78F2X_DeInit( ( hwDefPtr ) )
#endif /* if ( ADC_DEINIT_API != FALSE ) */

#define Adc_70_HW_StartConvert( gpPtr, gpDefPtr )   Adc_70_RL78F2X_StartConvert( ( gpPtr ), ( gpDefPtr ) )
#define Adc_70_HW_StopConvert( gpPtr, gpDefPtr )    Adc_70_RL78F2X_StopConvert( ( gpPtr ), ( gpDefPtr ) )
#define Adc_70_HW_HwStopConvert( gpPtr, gpDefPtr )  Adc_70_RL78F2X_HwStopConvert( ( gpPtr ), ( gpDefPtr ) )
#define Adc_70_HW_GetAdcValue( hwChannelId )        Adc_70_RL78F2X_GetAdcValue( ( hwChannelId ) )

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

#endif /* ADC_70_HW_H */

/* EOF Adc_70_HW.h ************************************************************/