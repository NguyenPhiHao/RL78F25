/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_70_HW_Types.h                                            */
/* Version     : v1.00.00                                                     */
/* Contents    : ADC Module type definition header                            */
/*               The ADC is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef ADC_70_HW_TYPES_H_
#define ADC_70_HW_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc_Cfg.h"
#include "Adc_70_RL78F2X_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_HW_TYPES_H             (70U)
#define ADC_70_MODULE_ID_HW_TYPES_H             (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H   (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H   (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H (0U)

#define ADC_70_SW_MAJOR_VERSION_HW_TYPES_H      (1U)
#define ADC_70_SW_MINOR_VERSION_HW_TYPES_H      (0U)
#define ADC_70_SW_PATCH_VERSION_HW_TYPES_H      (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
#if ( ADC_70_VENDOR_ID_HW_TYPES_H != ADC_70_VENDOR_ID_CFG_H )
  #error "VENDOR ID for Adc_70_HW_Types.h and Adc_Cfg.h are different"
#endif

#if ( ADC_70_MODULE_ID_HW_TYPES_H != ADC_70_MODULE_ID_CFG_H )
  #error "MODULE ID for Adc_70_HW_Types.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H   != ADC_70_AR_RELEASE_MAJOR_VERSION_CFG_H   ) \
   || ( ADC_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H   != ADC_70_AR_RELEASE_MINOR_VERSION_CFG_H   ) \
   || ( ADC_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H != ADC_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
  #error "AUTOSAR Version Numbers of Adc_70_HW_Types.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_HW_TYPES_H != ADC_70_SW_MAJOR_VERSION_CFG_H ) \
   || ( ADC_70_SW_MINOR_VERSION_HW_TYPES_H != ADC_70_SW_MINOR_VERSION_CFG_H ) \
   || ( ADC_70_SW_PATCH_VERSION_HW_TYPES_H != ADC_70_SW_PATCH_VERSION_CFG_H ) )
  #error "Software Version Numbers of Adc_70_HW_Types.h and Adc_Cfg.h are different"
#endif
/* Adc_Cfg.h version check end */

/* Adc_70_RL78F2X_Types.h version check start */
#if ( ADC_70_VENDOR_ID_HW_TYPES_H   != ADC_70_VENDOR_ID_RL78F2X_TYPES_H )
  #error "VENDOR ID for Adc_70_HW_Types.h and Adc_70_RL78F2X_Types.h are different"
#endif

#if ( ADC_70_MODULE_ID_HW_TYPES_H   != ADC_70_MODULE_ID_RL78F2X_TYPES_H )
  #error "MODULE ID for Adc_70_HW_Types.h and Adc_70_RL78F2X_Types.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H   != ADC_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H   ) \
   || ( ADC_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H   != ADC_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H   ) \
   || ( ADC_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H != ADC_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H ) )
  #error "AUTOSAR Version Numbers of Adc_70_HW_Types.h and Adc_70_RL78F2X_Types.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_HW_TYPES_H != ADC_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) \
   || ( ADC_70_SW_MINOR_VERSION_HW_TYPES_H != ADC_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) \
   || ( ADC_70_SW_PATCH_VERSION_HW_TYPES_H != ADC_70_SW_PATCH_VERSION_RL78F2X_TYPES_H ) )
  #error "Software Version Numbers of Adc_70_HW_Types.h and Adc_70_RL78F2X_Types.h are different"
#endif
/* Adc_70_RL78F2X_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* number of ADC HW unit */
#define ADC_70_HW_NUM_OF_HWUNIT  ( ADC_70_RL78F2X_NUM_OF_HWUNIT )

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* 8.2.5 Adc_PrescaleType : Type of clock prescaler factor. */
typedef Adc_70_RL78F2X_PrescaleType   Adc_70_HW_PrescaleType;

/* 8.2.10 Adc_TriggerSourceType : 
   Type for configuring the trigger source for an ADC Channel group. */
typedef Adc_70_RL78F2X_TriggerSourceType   Adc_70_HW_TriggerSourceType;

/* Configuration type for ADC channel groups */
typedef Adc_70_RL78F2X_GroupConfigType   Adc_70_HW_GroupConfigType;

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
/* (none) */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
/* (none) */

#endif /* ADC_70_HW_TYPES_H_ */

/* EOF Adc_70_HW_Types.h ***********************************************/
