/*----------------------------------------------------------------------------*/
/* Copyright    : 2023 SCSK Corporation                                       */
/* System Name   : QINeS-Lite MCAL                                            */
/* File Name     : Spi_70_RL78F2X_Callout.c                                   */
/* Version       : v1.00.00                                                   */
/* Contents      : Spi callout function configuration                         */
/*                  The SPI Handler/Driver provides services for reading from */
/*                  and writing to devices connected via SPI busses.          */
/* Author        : k.sawada h.shishido s.nitao                                */
/* Note          : --                                                         */
/* History       : --                                                         */
/*----------------------------------------------------------------------------*/
/* Specification of SPI Handler/Driver
 * R22-11
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Spi_70_RL78F2X_Callout.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_RL78F2X_CALLOUT_C              (70U)
#define SPI_70_MODULE_ID_RL78F2X_CALLOUT_C              (83U)

#define SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_CALLOUT_C   (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_CALLOUT_C   (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_CALLOUT_C (0U)

#define SPI_70_SW_MAJOR_VERSION_RL78F2X_CALLOUT_C        (1U)
#define SPI_70_SW_MINOR_VERSION_RL78F2X_CALLOUT_C        (0U)
#define SPI_70_SW_PATCH_VERSION_RL78F2X_CALLOUT_C        (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Spi_70_RL78F2X_Callout.h version check start */
#if ( SPI_70_VENDOR_ID_RL78F2X_CALLOUT_C != SPI_70_VENDOR_ID_RL78F2X_CALLOUT_H )
    #error "VENDOR ID for Spi_70_RL78F2X_Callout.c and Spi_70_RL78F2X_Callout.h are different"
#endif

#if ( SPI_70_MODULE_ID_RL78F2X_CALLOUT_C != SPI_70_MODULE_ID_RL78F2X_CALLOUT_H )
    #error "MODULE ID for Spi_70_RL78F2X_Callout.c and Spi_70_RL78F2X_Callout.h are different"
#endif

#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_CALLOUT_C != SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_CALLOUT_H ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_CALLOUT_C != SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_CALLOUT_H ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_CALLOUT_C != SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_CALLOUT_H ) )
    #error "AUTOSAR Version Numbers of Spi_70_RL78F2X_Callout.c and Spi_70_RL78F2X_Callout.h are different"
#endif

#if ( ( SPI_70_SW_MAJOR_VERSION_RL78F2X_CALLOUT_C != SPI_70_SW_MAJOR_VERSION_RL78F2X_CALLOUT_H ) || \
      ( SPI_70_SW_MINOR_VERSION_RL78F2X_CALLOUT_C != SPI_70_SW_MINOR_VERSION_RL78F2X_CALLOUT_H ) || \
      ( SPI_70_SW_PATCH_VERSION_RL78F2X_CALLOUT_C != SPI_70_SW_PATCH_VERSION_RL78F2X_CALLOUT_H ) )
    #error "Software Version Numbers of Spi_70_RL78F2X_Callout.c and Spi_70_RL78F2X_Callout.h are different"
#endif

/* Spi_70_RL78F2X_Callout.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define SPI_70_WAIT_1US      (3U)    /* loop times for wait 1us (fCLK=32MHz) */

/*------------------------------------------------------------------------*/
/* variables                                                              */
/*------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*/
/* functions and function style macros                                    */
/*------------------------------------------------------------------------*/
#define SPI_START_SEC_CALLOUT_CODE_LOCAL
#include "Spi_MemMap.h"

/*----------------------------------------------------------------------------*/
/* ModuleID        : ADC_MODULE_ID(123)                                       */
/* ServiceID       : --                                                       */
/* Name            : Spi_70_RL78F2X_WaitClk2Cs_Callout                        */
/* Param (in)      : timeClk2Cs  wait time in us                              */
/* Return          : None                                                     */
/* Contents        : wait for 1 us                                            */
/* Author          : k.sawada                                                 */
/* Note            : [QINeS_SWS_ADC_00044]                                    */
/*----------------------------------------------------------------------------*/
void Spi_70_RL78F2X_WaitClk2Cs_Callout( uint32 timeClk2Cs )
{
    /* DO NOTHING */
}

void Spi_70_RL78F2X_WaitCs2Clk_Callout( uint32 timeClk2Cs )
{
    /* DO NOTHING */
}

void Spi_70_RL78F2X_WaitCs2Cs_Callout( uint32 timeClk2Cs )
{
    /* DO NOTHING */
}

#define SPI_STOP_SEC_CALLOUT_CODE
#include "Spi_MemMap.h"

/*EOF Spi_70_RL78F2X_Callout.c**********************************************/
