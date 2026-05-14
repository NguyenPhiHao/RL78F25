/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcu_70_Irq.h                                                 */
/* Version     : v1.00.00                                                     */
/* Contents    : Mcu Driver Ram State IRQ header                              */
/*               The MCU is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of MCU Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef MCU_IRQ_H
#define MCU_IRQ_H

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define MCU_70_MODULE_ID_IRQ_H                ( 101U )
#define MCU_70_VENDOR_ID_IRQ_H                (  70U )

#define MCU_70_AR_RELEASE_MAJOR_VERSION_IRQ_H ( 22U )
#define MCU_70_AR_RELEASE_MINOR_VERSION_IRQ_H ( 11U )
#define MCU_70_AR_RELEASE_REVISION_VERSION_IRQ_H ( 00U )

#define MCU_70_SW_MAJOR_VERSION_IRQ_H         (  1U )
#define MCU_70_SW_MINOR_VERSION_IRQ_H         (  0U )
#define MCU_70_SW_PATCH_VERSION_IRQ_H         (  0U )

/*----------------------------------------------------------------------------*/
/* function prototype declarations                             */
/*----------------------------------------------------------------------------*/
#if ( MCU_GET_RAM_STATE_API != FALSE )
/* SWS Mcu 00207 */
extern void Mcu_70_RamStateIsr( void );
#endif /* #if ( MCU_GET_RAM_STATE_API != FALSE ) */

#endif /* #ifndef MCU_IRQ_H */

/* EOF Mcu_70_Irq.h ****************************************************/
