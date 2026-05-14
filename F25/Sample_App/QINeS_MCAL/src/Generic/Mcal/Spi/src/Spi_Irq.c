/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Spi_Irq.c                                                    */
/* Version     : v1.00.01                                                     */
/* Contents    : This file implements the ISR for SPI module                  */
/*               The SPI Handler/Driver provides services for reading from    */
/*               and writing to devices connected via SPI busses.             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */
/******************************************************************************/
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Spi.h"                                    /* [SPI276] */
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_IRQ_C                      (70U)
#define SPI_70_MODULE_ID_IRQ_C                      (83U)
 
#define SPI_70_AR_RELEASE_MAJOR_VERSION_IRQ_C       (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_IRQ_C       (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_IRQ_C    (0U)
 
#define SPI_70_SW_MAJOR_VERSION_IRQ_C               (1U)
#define SPI_70_SW_MINOR_VERSION_IRQ_C               (0U)
#define SPI_70_SW_PATCH_VERSION_IRQ_C               (0U)
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Spi.h version check start */
 
#if ( SPI_70_VENDOR_ID_IRQ_C != SPI_VENDOR_ID )
    #error "VENDOR ID for Spi_Irq.c and Spi.h are different"
#endif
 
#if ( SPI_70_MODULE_ID_IRQ_C != SPI_MODULE_ID )
    #error "MODULE ID for Spi_Irq.c and Spi.h are different"
#endif
 
#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MINOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_IRQ_C != SPI_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Spi_Irq.c and Spi.h are different"
#endif
 
#if ( ( SPI_70_SW_MAJOR_VERSION_IRQ_C != SPI_SW_MAJOR_VERSION ) || \
      ( SPI_70_SW_MINOR_VERSION_IRQ_C != SPI_SW_MINOR_VERSION ) || \
      ( SPI_70_SW_PATCH_VERSION_IRQ_C != SPI_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Spi_Irq.c and Spi.h are different"
#endif
 
/* Spi.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/*  static variables                                                          */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define SPI_START_SEC_CODE_LOCAL
#include "Spi_MemMap.h"
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_Isr_HW00_SndRcvIntr                                   */
/* Param       : None                                                         */
/* Return      : void                                                         */
/* Contents    : function called by ISR(correspond to channel id 0)           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_70_Isr_HW00_SndRcvIntr( void )
{
    Spi_70_SndRcvIntr( 0U );
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_Isr_HW01_SndRcvIntr                                   */
/* Param       : None                                                         */
/* Return      : void                                                         */
/* Contents    : function called by ISR(correspond to channel id 1)           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_70_Isr_HW01_SndRcvIntr( void )
{
    Spi_70_SndRcvIntr( 1U );
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_Isr_HW10_SndRcvIntr                                   */
/* Param       : None                                                         */
/* Return      : void                                                         */
/* Contents    : function called by ISR(correspond to channel id 2)           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_70_Isr_HW10_SndRcvIntr( void )
{
    Spi_70_SndRcvIntr( 2U );
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_Isr_HW11_SndRcvIntr                                   */
/* Param       : None                                                         */
/* Return      : void                                                         */
/* Contents    : function called by ISR(correspond to channel id 3)           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_70_Isr_HW11_SndRcvIntr( void )
{
    Spi_70_SndRcvIntr( 3U );
}
#define SPI_STOP_SEC_CODE_LOCAL
#include "Spi_MemMap.h"
/************************* End Of File Spi_Irq.c *****************************/
