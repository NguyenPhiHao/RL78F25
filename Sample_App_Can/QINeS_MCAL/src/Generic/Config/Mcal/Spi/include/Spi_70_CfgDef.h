/*----------------------------------------------------------------------------*/
/* Copyright    : 2023 SCSK Corporation                                       */
/* System Name   : QINeS-Lite MCAL                                            */
/* File Name     : Spi_70_CfgDef.h                                            */
/* Version       : v1.00.00                                                   */
/* Contents      : SPI module type definition header file (Spi_Cfg.h)         */
/*                  The SPI Handler/Driver provides services for reading from */
/*                  and writing to devices connected via SPI busses.          */
/* Author        : k.sawada h.shishido s.nitao                                */
/* Note          : --                                                         */
/* History       : --                                                         */
/*----------------------------------------------------------------------------*/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef SPI_70_CFGDEF_H
#define SPI_70_CFGDEF_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_CFGDEF_H               (70U)
#define SPI_70_MODULE_ID_CFGDEF_H               (83U)

#define SPI_70_AR_RELEASE_MAJOR_VERSION_CFGDEF_H (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_CFGDEF_H (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_CFGDEF_H (0U)

#define SPI_70_SW_MAJOR_VERSION_CFGDEF_H        (1U)
#define SPI_70_SW_MINOR_VERSION_CFGDEF_H        (0U)
#define SPI_70_SW_PATCH_VERSION_CFGDEF_H        (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* [ECUC_Spi_00227] */
#define SPI_70_BUFFER_ALLOW_IB    (0U)
#define SPI_70_BUFFER_ALLOW_EB    (1U)
#define SPI_70_BUFFER_ALLOW_IBEB  (2U)

/* [ECUC_Spi_00231] */
#define SPI_70_LEVEL_0            (0U)
#define SPI_70_LEVEL_1            (1U)
#define SPI_70_LEVEL_2            (2U)

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

#endif /* SPI_70_CFGDEF_H */

/***************** End Of File Spi_70_CfgDef.h ***********************/
