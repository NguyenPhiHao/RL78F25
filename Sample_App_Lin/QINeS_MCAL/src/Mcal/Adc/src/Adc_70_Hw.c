/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_70_Hw.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : ADC Module wrapper                                           */
/*               The ADC is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc_70_Hw.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_HW_C                    (70U)
#define ADC_70_MODULE_ID_HW_C                    (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_HW_C     (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_HW_C     (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_HW_C  (0U)

#define ADC_70_SW_MAJOR_VERSION_HW_C             (1U)
#define ADC_70_SW_MINOR_VERSION_HW_C             (0U)
#define ADC_70_SW_PATCH_VERSION_HW_C             (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Adc_70_Hw.h version check start */
#if ( ADC_70_VENDOR_ID_HW_C != ADC_70_VENDOR_ID_HW_H )
#error "VENDOR ID for Adc_70_Hw.c and Adc_70_Hw.h are different"
#endif

#if ( ADC_70_MODULE_ID_HW_C != ADC_70_MODULE_ID_HW_H )
#error "MODULE ID for Adc_70_Hw.c and Adc_70_Hw.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_HW_C    != ADC_70_AR_RELEASE_MAJOR_VERSION_HW_H    ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_HW_C    != ADC_70_AR_RELEASE_MINOR_VERSION_HW_H    ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_HW_C != ADC_70_AR_RELEASE_REVISION_VERSION_HW_H )    \
    )
#error "AUTOSAR Version Numbers of Adc_70_Hw.c and Adc_70_Hw.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_HW_C    != ADC_70_SW_MAJOR_VERSION_HW_H ) || \
      ( ADC_70_SW_MINOR_VERSION_HW_C    != ADC_70_SW_MINOR_VERSION_HW_H ) || \
      ( ADC_70_SW_PATCH_VERSION_HW_C    != ADC_70_SW_PATCH_VERSION_HW_H )    \
    )
#error "Software Version Numbers of Adc_70_Hw.c and Adc_70_Hw.h are different"
#endif
/* Adc_70_Hw.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define ADC_START_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

#define ADC_STOP_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define ADC_START_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

#define ADC_STOP_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

/* EOF Adc_70_Hw.c ************************************************************/