/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Spi_70_HW.h                                                  */
/* Version     : v1.00.01                                                     */
/* Contents    : SPI Module wrapper header file                               */
/*               The SPI Handler/Driver provides services for reading         */
/*               from and writing to devices connected via SPI busses.        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */
#ifndef SPI_70_HW_H
#define SPI_70_HW_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Spi_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_HW_H                 ( 70U )
#define SPI_70_MODULE_ID_HW_H                 ( 83U )

#define SPI_70_AR_RELEASE_MAJOR_VERSION_HW_H  ( 22U )
#define SPI_70_AR_RELEASE_MINOR_VERSION_HW_H  ( 11U )
#define SPI_70_AR_RELEASE_REVISION_VERSION_HW_H ( 00U )

#define SPI_70_SW_MAJOR_VERSION_HW_H          (  1U )
#define SPI_70_SW_MINOR_VERSION_HW_H          (  0U )
#define SPI_70_SW_PATCH_VERSION_HW_H          (  1U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Spi_70_RL78F2X.h version check start */
#if ( SPI_70_VENDOR_ID_HW_H != SPI_70_VENDOR_ID_RL78F2X_H )
  #error "VENDOR ID for Spi_70_HW.h and Spi_70_RL78F2X.h are different"
#endif

#if ( SPI_70_MODULE_ID_HW_H != SPI_70_MODULE_ID_RL78F2X_H )
  #error "MODULE ID for Spi_70_HW.h and Spi_70_RL78F2X.h are different"
#endif

#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_HW_H != SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_HW_H != SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_HW_H != SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) )
  #error "AUTOSAR Version Numbers of Spi_70_HW.h and Spi_70_RL78F2X.h are different"
#endif

#if ( ( SPI_70_SW_MAJOR_VERSION_HW_H != SPI_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( SPI_70_SW_MINOR_VERSION_HW_H != SPI_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( SPI_70_SW_PATCH_VERSION_HW_H != SPI_70_SW_PATCH_VERSION_RL78F2X_H ) )
  #error "Software Version Numbers of Spi_70_HW.h and Spi_70_RL78F2X.h are different"
#endif
/* Spi_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define Spi_70_HW_Init                    Spi_70_RL78F2X_Init
#define Spi_70_HW_DeInit                  Spi_70_RL78F2X_DeInit

#define Spi_70_HW_TransmitChannel         Spi_70_RL78F2X_TransmitChannel
#define Spi_70_HW_ReceiveChannel          Spi_70_RL78F2X_ReceiveChannel
#define Spi_70_HW_PutChipSelect           Spi_70_RL78F2X_PutChipSelect
#define Spi_70_HW_StartChannel            Spi_70_RL78F2X_StartChannel
#define Spi_70_HW_StopChannel             Spi_70_RL78F2X_StopChannel
#define Spi_70_HW_GetHWErrorStatus        Spi_70_RL78F2X_GetHWErrorStatus
#define Spi_70_HW_DisableInterrupts       Spi_70_RL78F2X_DisableInterrupts
#define Spi_70_HW_EnableInterrupts        Spi_70_RL78F2X_EnableInterrupts
#define Spi_70_HW_SelectUnit              Spi_70_RL78F2X_SelectUnit

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

#endif  /* #ifndef SPI_70_HW_H */

/* EOF Spi_70_HW.h ************************************************************/