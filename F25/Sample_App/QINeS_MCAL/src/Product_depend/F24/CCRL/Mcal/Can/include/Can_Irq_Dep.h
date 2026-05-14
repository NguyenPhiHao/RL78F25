/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Can_Irq_Dep.h                                                */
/* Version     : v1.00.00                                                     */
/* Contents    : This module provides services for initiating                 */
/*               transmissions and calls the callback functions of            */
/*               the CanIf module for notifying events, independently         */
/*               from the hardware. Also it provides services to              */
/*               control the behavior and state of the CAN controllers        */
/*               that belong to the same CAN Hardware Unit.                   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of CAN Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef CAN_IRQ_DEP_H
#define CAN_IRQ_DEP_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define CAN_70_VENDOR_ID_IRQ_DEP_H               ( 70U )
#define CAN_70_MODULE_ID_IRQ_DEP_H               ( 80U )

#define CAN_70_AR_RELEASE_MAJOR_VERSION_IRQ_DEP_H ( 22U )
#define CAN_70_AR_RELEASE_MINOR_VERSION_IRQ_DEP_H ( 11U )
#define CAN_70_AR_RELEASE_REVISION_VERSION_IRQ_DEP_H ( 0U )

#define CAN_70_SW_MAJOR_VERSION_IRQ_DEP_H        ( 1U )
#define CAN_70_SW_MINOR_VERSION_IRQ_DEP_H        ( 0U )
#define CAN_70_SW_PATCH_VERSION_IRQ_DEP_H        ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define CAN_START_SEC_CODE_LOCAL
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_LOCAL
#include "Can_MemMap.h"

extern void Can_70_Isr_Reception_CAN0( void );
extern void Can_70_Isr_Reception_CAN1( void );
extern void Can_70_Isr_GlobalError_CAN0( void );
extern void Can_70_Isr_GlobalError_CAN1( void );
extern void Can_70_Isr_Transmission_CAN0( void );
extern void Can_70_Isr_Transmission_CAN1( void );
extern void Can_70_Isr_ChannelError_CAN0( void );
extern void Can_70_Isr_ChannelError_CAN1( void );
extern void Can_70_Isr_Wakeup_CAN0( void );
extern void Can_70_Isr_Wakeup_CAN1( void );

#define CAN_STOP_SEC_CODE_LOCAL
#include "Can_MemMap.h"

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

#endif  /* CAN_IRQ_DEP_H */
/* EOF Can_Irq_Dep.h ********************************************/
