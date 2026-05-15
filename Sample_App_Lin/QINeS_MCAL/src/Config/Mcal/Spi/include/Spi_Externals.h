/*----------------------------------------------------------------------------*/
/* Copyright    : 2023 SCSK Corporation                                       */
/* System Name   : QINeS-Lite MCAL                                            */
/* File Name     : Spi_Externals.h                                            */
/* Version       : v1.00.00                                                   */
/* Contents      : SPI External Header                                        */
/*                  The SPI Handler/Driver provides services for reading from */
/*                  and writing to devices connected via SPI busses.          */
/* Author        : h.shishido s.nitao                                         */
/* Note          : --                                                         */
/* History       : --                                                         */
/*----------------------------------------------------------------------------*/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */

#ifndef SPI_EXTERNAL_H
#define SPI_EXTERNAL_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_VENDOR_ID_EXTERNAL_H                    (70U)
#define SPI_MODULE_ID_EXTERNAL_H                    (83U)

#define SPI_AR_RELEASE_MAJOR_VERSION_EXTERNAL_H     (22U)
#define SPI_AR_RELEASE_MINOR_VERSION_EXTERNAL_H     (11U)
#define SPI_AR_RELEASE_REVISION_VERSION_EXTERNAL_H  (0U)

#define SPI_SW_MAJOR_VERSION_EXTERNAL_H             (1U)
#define SPI_SW_MINOR_VERSION_EXTERNAL_H             (0U)
#define SPI_SW_PATCH_VERSION_EXTERNAL_H             (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */
#if ( ( SPI_AR_RELEASE_MAJOR_VERSION_EXTERNAL_H    != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_AR_RELEASE_MINOR_VERSION_EXTERNAL_H    != STD_TYPES_AR_RELEASE_MINOR_VERSION ) || \
      ( SPI_AR_RELEASE_REVISION_VERSION_EXTERNAL_H != STD_TYPES_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Spi_Externals.h and Std_Types.h are different"
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
extern void Spi_SeqEndNotification_0( void );
extern void Spi_SeqEndNotification_1( void );
extern void Spi_SeqEndNotification_2( void );
extern void Spi_SeqEndNotification_3( void );
extern void Spi_SeqEndNotification_4( void );
extern void Spi_SeqEndNotification_5( void );
extern void Spi_SeqEndNotification_6( void );
extern void Spi_SeqEndNotification_7( void );
extern void Spi_SeqEndNotification_8( void );
extern void Spi_SeqEndNotification_9( void );

extern void Spi_JobEndNotification_0( void );
extern void Spi_JobEndNotification_1( void );
extern void Spi_JobEndNotification_2( void );
extern void Spi_JobEndNotification_3( void );
extern void Spi_JobEndNotification_4( void );
extern void Spi_JobEndNotification_5( void );
extern void Spi_JobEndNotification_6( void );
extern void Spi_JobEndNotification_7( void );
extern void Spi_JobEndNotification_8( void );
extern void Spi_JobEndNotification_9( void );

#endif /* SPI_EXTERNAL_H */

/* EOF Spi_Externals.h ****************************************************/  
