/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_Irq.c                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : ADC Driver IRQ implementation                                */
/*               The ADC is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc.h"
#include "Adc_70_Irq.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_IRQ_C                    (70U)
#define ADC_70_MODULE_ID_IRQ_C                    (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_IRQ_C     (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_IRQ_C     (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_IRQ_C  (0U)

#define ADC_70_SW_MAJOR_VERSION_IRQ_C             (1U)
#define ADC_70_SW_MINOR_VERSION_IRQ_C             (0U)
#define ADC_70_SW_PATCH_VERSION_IRQ_C             (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Adc.h version check start */
#if ( ADC_70_VENDOR_ID_IRQ_C != ADC_VENDOR_ID )
#error "VENDOR ID for Adc_Irq.c and Adc.h are different"
#endif

#if ( ADC_70_MODULE_ID_IRQ_C != ADC_MODULE_ID )
#error "MODULE ID for Adc_Irq.c and Adc.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_IRQ_C    != ADC_AR_RELEASE_MAJOR_VERSION    ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_IRQ_C    != ADC_AR_RELEASE_MINOR_VERSION    ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_AR_RELEASE_REVISION_VERSION )    \
    )
#error "AUTOSAR Version Numbers of Adc_Irq.c and Adc.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_IRQ_C    != ADC_SW_MAJOR_VERSION    ) || \
      ( ADC_70_SW_MINOR_VERSION_IRQ_C    != ADC_SW_MINOR_VERSION    ) || \
      ( ADC_70_SW_PATCH_VERSION_IRQ_C    != ADC_SW_PATCH_VERSION    )    \
    )
#error "Software Version Numbers of Adc_Irq.c and Adc.h are different"
#endif
/* Adc.h version check end */

/* Adc_70_Irq.h version check start */
#if ( ADC_70_VENDOR_ID_IRQ_C    != ADC_70_VENDOR_ID_IRQ_H    )
#error "VENDOR ID for Adc_Irq.c and Adc_70_Irq.h are different"
#endif

#if ( ADC_70_MODULE_ID_IRQ_C    != ADC_70_MODULE_ID_IRQ_H    )
#error "MODULE ID for Adc_Irq.c and Adc_70_Irq.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_IRQ_C    != ADC_70_AR_RELEASE_MAJOR_VERSION_IRQ_H    ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_IRQ_C    != ADC_70_AR_RELEASE_MINOR_VERSION_IRQ_H    ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_70_AR_RELEASE_REVISION_VERSION_IRQ_H )    \
    )
#error "AUTOSAR Version Numbers of Adc_Irq.c and Adc_70_Irq.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_IRQ_C    != ADC_70_SW_MAJOR_VERSION_IRQ_H ) || \
      ( ADC_70_SW_MINOR_VERSION_IRQ_C    != ADC_70_SW_MINOR_VERSION_IRQ_H ) || \
      ( ADC_70_SW_PATCH_VERSION_IRQ_C    != ADC_70_SW_PATCH_VERSION_IRQ_H )    \
    )
#error "Software Version Numbers of Adc_Irq.c and Adc_70_Irq.h are different"
#endif
/* Adc_70_Irq.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

#define ADC_START_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

/******************************************************************************/
/* ModuleID   : MODULE_ID_ADC(123)                                            */
/* ServiceID  : --                                                            */
/* Name       : Adc_70_Isr_INTAD                                              */
/* Param      : None                                                          */
/* Return     : None                                                          */
/* Contents    : interrupt Handler for ADC of Group A                          */
/* Author     : TamNA4                                                        */
/* Note       : --                                                            */
/******************************************************************************/
void Adc_70_Isr_INTAD( void )
{
    /* [SWS_Adc_00078] isr is responsible for resetting the interrupt flag */
    /*                                            and invoking the notification function. */
    Adc_70_Isr_Common( ADC_70_HWUNIT_INTERNAL, ADC_70_RL78F2X_INTAD );
}

/******************************************************************************/
/* ModuleID   : MODULE_ID_ADC(123)                                            */
/* ServiceID  : --                                                            */
/* Name       : Adc_70_Isr_INTADGB                                            */
/* Param      : None                                                          */
/* Return     : None                                                          */
/* Contents    : interrupt Handler for ADC of Group B                          */
/* Author     : TamNA4                                                        */
/* Note       : --                                                            */
/******************************************************************************/
void Adc_70_Isr_INTADGB( void )
{
    /* [SWS_Adc_00078] isr is responsible for resetting the interrupt flag */
    /*                                            and invoking the notification function. */
    Adc_70_Isr_Common( ADC_70_HWUNIT_INTERNAL, ADC_70_RL78F2X_INTADGB );
}

#define ADC_STOP_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

/* EOF Adc_Irq.c ***************************************************/
