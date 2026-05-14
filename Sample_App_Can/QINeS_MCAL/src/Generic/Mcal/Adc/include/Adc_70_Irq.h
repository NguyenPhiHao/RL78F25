/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_70_Irq.h                                                 */
/* Version     : v1.00.00                                                     */
/* Contents    : ADC Driver IRQ header                                        */
/*               The ADC is a basic software module at the service            */
/*               layer of the standardized basic software                     */
/*               architecture of AUTOSAR.                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef ADC_70_IRQ_H
#define ADC_70_IRQ_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc_Cfg.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_IRQ_H                  (70U)
#define ADC_70_MODULE_ID_IRQ_H                  (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_IRQ_H   (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_IRQ_H   (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_IRQ_H (0U)

#define ADC_70_SW_MAJOR_VERSION_IRQ_H           (1U)
#define ADC_70_SW_MINOR_VERSION_IRQ_H           (0U)
#define ADC_70_SW_PATCH_VERSION_IRQ_H           (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Adc_Cfg.h version check start */
#if ( ADC_70_VENDOR_ID_IRQ_H != ADC_70_VENDOR_ID_CFG_H )
  #error "VENDOR ID for Adc_70_Irq.h and Adc_Cfg.h are different"
#endif

#if ( ADC_70_MODULE_ID_IRQ_H != ADC_70_MODULE_ID_CFG_H )
  #error "MODULE ID for Adc_70_Irq.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_IRQ_H    != ADC_70_AR_RELEASE_MAJOR_VERSION_CFG_H    ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_IRQ_H    != ADC_70_AR_RELEASE_MINOR_VERSION_CFG_H    ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_IRQ_H != ADC_70_AR_RELEASE_REVISION_VERSION_CFG_H )    \
    )
  #error "AUTOSAR Version Numbers of Adc_70_Irq.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_IRQ_H != ADC_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( ADC_70_SW_MINOR_VERSION_IRQ_H != ADC_70_SW_MINOR_VERSION_CFG_H ) || \
      ( ADC_70_SW_PATCH_VERSION_IRQ_H != ADC_70_SW_PATCH_VERSION_CFG_H )    \
    )
  #error "Software Version Numbers of Adc_70_Irq.h and Adc_Cfg.h are different"
#endif
/* Adc_Cfg.h version check end */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern void Adc_70_Isr_INTAD( void );
extern void Adc_70_Isr_INTADBG( void );

#endif /* ADC_70_IRQ_H */

/* EOF Adc_70_Irq.h ***********************************************/
