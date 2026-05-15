/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Wdg_Irq.h                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : Wdg Driver Layer IRQ Header                                  */
/*               The WDG is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of WDG Driver                                                */
/* R22-11                                                                     */
#ifndef WDG_IRQ_H
#define WDG_IRQ_H

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define WDG_70_VENDOR_ID_IRQ_H                   ( 70U )
#define WDG_70_MODULE_ID_IRQ_H                   (102U )

#define WDG_70_AR_RELEASE_MAJOR_VERSION_IRQ_H    ( 22U )
#define WDG_70_AR_RELEASE_MINOR_VERSION_IRQ_H    ( 11U )
#define WDG_70_AR_RELEASE_REVISION_VERSION_IRQ_H ( 00U )

#define WDG_70_SW_MAJOR_VERSION_IRQ_H            ( 1U )
#define WDG_70_SW_MINOR_VERSION_IRQ_H            ( 0U )
#define WDG_70_SW_PATCH_VERSION_IRQ_H            ( 0U )

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern void Wdg_70_TimerIsr( void );

#endif  /* WDG_IRQ_H */

/* EOF Wdg_Irq.h **************************************************************/