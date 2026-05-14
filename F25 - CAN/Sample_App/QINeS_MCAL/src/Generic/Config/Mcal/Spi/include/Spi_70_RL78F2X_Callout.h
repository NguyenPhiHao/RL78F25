/*----------------------------------------------------------------------------*/
/* Copyright    : 2023 SCSK Corporation                                       */
/* System Name   : QINeS-Lite MCAL                                            */
/* File Name     : Spi_70_RL78F2X_Callout.h                                   */
/* Version       : v1.00.00                                                   */
/* Contents      : Spi callout function configuration header                  */
/*                  The SPI Handler/Driver provides services for reading from */
/*                  and writing to devices connected via SPI busses.          */
/* Author        : k.sawada h.shishido s.nitao                                */
/* Note          : --                                                         */
/* History       : --                                                         */
/*----------------------------------------------------------------------------*/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef SPI_70_RL78F2X_CALLOUT_H
#define SPI_70_RL78F2X_CALLOUT_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_RL78F2X_CALLOUT_H              (70U)
#define SPI_70_MODULE_ID_RL78F2X_CALLOUT_H              (83U)

#define SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_CALLOUT_H   (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_CALLOUT_H   (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_CALLOUT_H (0U)

#define SPI_70_SW_MAJOR_VERSION_RL78F2X_CALLOUT_H        (1U)
#define SPI_70_SW_MINOR_VERSION_RL78F2X_CALLOUT_H        (0U)
#define SPI_70_SW_PATCH_VERSION_RL78F2X_CALLOUT_H        (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */
#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_CALLOUT_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_CALLOUT_H != STD_TYPES_AR_RELEASE_MINOR_VERSION ) )
    #error "AUTOSAR Version Numbers of Spi_70_RL78F2X_Callout.h and Std_Types.h are different"
#endif
/* Std_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern void Spi_70_RL78F2X_WaitClk2Cs_Callout( uint32 timeClk2Cs );
extern void Spi_70_RL78F2X_WaitCs2Clk_Callout( uint32 timeCs2Clk );
extern void Spi_70_RL78F2X_WaitCs2Cs_Callout( uint32 timeClk2Cs );

#endif  /* #ifndef SPI_70_RL78F2X_CALLOUT_H */

/* EOF Spi_70_RL78F2X_Callout.h *******************************************/