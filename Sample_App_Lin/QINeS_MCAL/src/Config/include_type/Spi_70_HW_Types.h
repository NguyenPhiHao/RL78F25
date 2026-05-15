/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Spi_70_HW_Types.h                                            */
/* Version     : v1.00.00                                                     */
/* Contents    : The SPI Handler/Driver provides services for                 */
/*               reading from and writing to devices connected via            */
/*               SPI busses. SPI module wrapper type definition header file   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */

#ifndef SPI_70_HW_TYPES_H_
#define SPI_70_HW_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Spi_Cfg.h"
#include "Spi_70_RL78F2X_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_HW_TYPES_H                (70U)
#define SPI_70_MODULE_ID_HW_TYPES_H                (83U)

#define SPI_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H (0U)

#define SPI_70_SW_MAJOR_VERSION_HW_TYPES_H         (1U)
#define SPI_70_SW_MINOR_VERSION_HW_TYPES_H         (0U)
#define SPI_70_SW_PATCH_VERSION_HW_TYPES_H         (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Spi_Cfg.h version check start */
#if ( SPI_70_VENDOR_ID_HW_TYPES_H != SPI_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Spi_70_HW_Types.h and Spi_Cfg.h are different"
#endif

#if ( SPI_70_MODULE_ID_HW_TYPES_H != SPI_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Spi_70_HW_Types.h and Spi_Cfg.h are different"
#endif

#if (( SPI_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H != SPI_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
     ( SPI_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H != SPI_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
     ( SPI_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H != SPI_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
    #error "AutoSar Version Numbers of Spi_70_HW_Types.h and Spi_Cfg.h are different"
#endif

#if (( SPI_70_SW_MAJOR_VERSION_HW_TYPES_H != SPI_70_SW_MAJOR_VERSION_CFG_H ) || \
     ( SPI_70_SW_MINOR_VERSION_HW_TYPES_H != SPI_70_SW_MINOR_VERSION_CFG_H ) || \
     ( SPI_70_SW_PATCH_VERSION_HW_TYPES_H != SPI_70_SW_PATCH_VERSION_CFG_H ) )
    #error "Software Version Numbers of Spi_70_HW_Types.h and Spi_Cfg.h are different"
#endif

/* Spi_Cfg.h version check end */

/* Spi_70_RL78F2X_Types.h version check start */

#if ( SPI_70_VENDOR_ID_HW_TYPES_H != SPI_70_VENDOR_ID_RL78F2X_TYPES_H )
    #error "VENDOR ID for Spi_70_Hw_Types.h and Spi_70_RL78F2X_Types.h are different"
#endif

#if ( SPI_70_MODULE_ID_HW_TYPES_H != SPI_70_MODULE_ID_RL78F2X_TYPES_H )
    #error "MODULE ID for Spi_70_Hw_Types.h and Spi_70_RL78F2X_Types.h are different"
#endif

#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    != SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    != SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H != SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Spi_70_Hw_Types.h and Spi_70_RL78F2X_Types.h are different"
#endif

#if ( ( SPI_70_SW_MAJOR_VERSION_HW_TYPES_H  != SPI_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( SPI_70_SW_MINOR_VERSION_HW_TYPES_H  != SPI_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( SPI_70_SW_PATCH_VERSION_HW_TYPES_H  != SPI_70_SW_PATCH_VERSION_RL78F2X_TYPES_H ) \
    )
    #error "Software Version Numbers of Spi_70_Hw_Types.h and Spi_70_RL78F2X_Types.h are different"
#endif

/* Spi_70_RL78F2X_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/* [QINeS_SWS_SPI_00050] */
typedef uint8 Spi_70_HW_ChStatusType;
#define SPI_70_CH_UNINIT    (uint8)(0U)
#define SPI_70_CH_STOP      (uint8)(1U)
#define SPI_70_CH_START     (uint8)(2U)
#define SPI_70_CH_TX        (uint8)(3U)
#define SPI_70_CH_RX        (uint8)(4U)

/* [QINeS_SWS_SPI_00041] */
typedef Spi_70_RL78F2X_IdleLevelType   Spi_70_HW_IdleLevelType;
#define SPI_70_HW_IDLE_HIGH    (SPI_70_RL78F2X_IDLE_HIGH)
#define SPI_70_HW_IDLE_LOW     (SPI_70_RL78F2X_IDLE_LOW)

/* [QINeS_SWS_SPI_00031] */
typedef Spi_70_RL78F2X_HwUnitConfType   Spi_70_HW_HwUnitConfType;

/* [QINeS_SWS_SPI_00032] */
typedef Spi_70_RL78F2X_CsConfType       Spi_70_HW_CsConfType;

/*----------------------------------------------------------------------------*/
/* external constant                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

#endif    /* #ifndef SPI_70_HW_TYPES_H */

/*************** End Of File Spi_70_Hw_Types.h ****************/
