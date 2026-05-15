/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcu_Irq.c                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : Mcu Driver Ram State IRQ implementation                      */
/*               The MCU is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of MCU Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Mcu.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define MCU_VENDOR_ID_IRQ_C                 ( 70U )
#define MCU_MODULE_ID_IRQ_C                 ( 101U )

#define MCU_AR_RELEASE_MAJOR_VERSION_IRQ_C  ( 22U )
#define MCU_AR_RELEASE_MINOR_VERSION_IRQ_C  ( 11U )
#define MCU_AR_RELEASE_REVISION_VERSION_IRQ_C ( 00U )

#define MCU_SW_MAJOR_VERSION_IRQ_C          ( 1U )
#define MCU_SW_MINOR_VERSION_IRQ_C          ( 0U )
#define MCU_SW_PATCH_VERSION_IRQ_C          ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Mcu.h version check start */
#if ( MCU_VENDOR_ID_IRQ_C != MCU_VENDOR_ID )
  #error "VENDOR ID for Mcu_Irq.c and Mcu.h is different"
#endif

#if ( MCU_MODULE_ID_IRQ_C != MCU_MODULE_ID )
  #error "MODULE ID for Mcu_Irq.c and Mcu.h is different"
#endif

#if ( ( MCU_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCU_AR_RELEASE_MAJOR_VERSION ) || \
      ( MCU_AR_RELEASE_MINOR_VERSION_IRQ_C != MCU_AR_RELEASE_MINOR_VERSION ) || \
      ( MCU_AR_RELEASE_REVISION_VERSION_IRQ_C != MCU_AR_RELEASE_REVISION_VERSION ) )
  #error "AUTOSAR Version Numbers of Mcu_Irq.c and Mcu.h are different"
#endif
/* Mcu.h version check end */

#if ( ( MCU_SW_MAJOR_VERSION_IRQ_C != MCU_SW_MAJOR_VERSION ) || \
      ( MCU_SW_MINOR_VERSION_IRQ_C != MCU_SW_MINOR_VERSION ) || \
      ( MCU_SW_PATCH_VERSION_IRQ_C != MCU_SW_PATCH_VERSION ) )
  #error "Software Version Numbers of Mcu_Irq.c and Mcu.h are different"
#endif
/* Mcu.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"

/***********************************************
 * ModuleID    : MCU_MODULE_ID (101)
 * ServiceID   : Mcu_70_RamStateIsr
 * Param       : void
 * Return      : void
 * Contents    : Mcu Ram State Error interrupt.
 * Author      : h.kiryu DuchT2
 * Note        : [SWS_Mcu_00207]
 *               1bit or 2bit Error interrupt.
 ***********************************************/
#if ( MCU_GET_RAM_STATE_API != FALSE )
void Mcu_70_RamStateIsr( void )
{
    /* mcu get ram state isr by hardware. */
    Mcu_70_HW_RamStateIsr();
}
#endif /* #if ( MCU_GET_RAM_STATE_API != FALSE ) */

#define MCU_STOP_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"

/* EOF Mcu_70_Irq.c ***********************************************************/