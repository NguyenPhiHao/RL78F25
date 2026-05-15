/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Spi_Cfg.h                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : SPI Configuration Header                                     */
/*               The SPI Handler/Driver provides services for reading from    */
/*               and writing to devices connected via SPI busses.             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */

#ifndef SPI_CFG_H
#define SPI_CFG_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Spi_70_CfgDef.h"
#include "Mcu.h"
#include "QINeS_Lite.h"
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_CFG_H                      (70U)
#define SPI_70_MODULE_ID_CFG_H                      (83U)

#define SPI_70_AR_RELEASE_MAJOR_VERSION_CFG_H       (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_CFG_H       (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_CFG_H    (0U)

#define SPI_70_SW_MAJOR_VERSION_CFG_H               (1U)
#define SPI_70_SW_MINOR_VERSION_CFG_H               (0U)
#define SPI_70_SW_PATCH_VERSION_CFG_H               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Spi_70_CfgDef.h version check start */

#if ( SPI_70_VENDOR_ID_CFG_H != SPI_70_VENDOR_ID_CFGDEF_H )
    #error "VENDOR ID for Spi_Cfg.h and Spi_70_CfgDef.h are different"
#endif

#if ( SPI_70_MODULE_ID_CFG_H != SPI_70_MODULE_ID_CFGDEF_H )
    #error "MODULE ID for Spi_Cfg.h and Spi_70_CfgDef.h are different"
#endif

#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_CFG_H    != SPI_70_AR_RELEASE_MAJOR_VERSION_CFGDEF_H ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_CFG_H    != SPI_70_AR_RELEASE_MINOR_VERSION_CFGDEF_H ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_CFG_H != SPI_70_AR_RELEASE_REVISION_VERSION_CFGDEF_H ) \
    )
    #error "AUTOSAR Version Numbers of Spi_Cfg.h and Spi_70_CfgDef.h are different"
#endif

#if ( ( SPI_70_SW_MAJOR_VERSION_CFG_H != SPI_70_SW_MAJOR_VERSION_CFGDEF_H ) || \
      ( SPI_70_SW_MINOR_VERSION_CFG_H != SPI_70_SW_MINOR_VERSION_CFGDEF_H ) || \
      ( SPI_70_SW_PATCH_VERSION_CFG_H != SPI_70_SW_PATCH_VERSION_CFGDEF_H ) \
    )
    #error "Software Version Numbers of Spi_Cfg.h and Spi_70_CfgDef.h are different"
#endif

/* Spi_70_CfgDef.h version check end */

/* Mcu.h version check start */

#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_CFG_H != MCU_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_CFG_H != MCU_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Spi_Cfg.h and Mcu.h are different"
#endif

/* Mcu.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/* [ECUC_Spi_00228] */
#define SPI_DEV_ERROR_DETECT            ( TRUE )

/* [ECUC_Spi_00227] */
#define SPI_CHANNEL_BUFFERS_ALLOWED     ( SPI_70_BUFFER_ALLOW_IBEB )

/* [ECUC_Spi_00231] */
#define SPI_LEVEL_DELIVERED             ( SPI_70_LEVEL_2 )

/* [ECUC_Spi_00242] */
#define SPI_MAINFUNCTION_PERIOD         ( 10U )

/* Define what API functions to enable */

/* [ECUC_Spi_00226] */
#define SPI_CANCEL_API                  ( TRUE )
/* [ECUC_Spi_00229] */
#define SPI_HW_STATUS_API               ( TRUE )
/* [ECUC_Spi_00232] */
#define SPI_VERSION_INFO_API            ( TRUE )

/* Total number of external devices configured. */
#define SPI_70_MAX_EX_DEVICE                ( 1U )

/* external device ID */
#define SPI_70_DEV0                      ( 0U )            /* DEV0 */

/* Total number of chip select for external devices configured. */
#define SPI_70_NUM_OF_CS_CONF            ( 1U )

/* SPI Chip-Select ID */
#define SPI_70_CS_DEV0                   ( 0U )            /* DEV0: P3-0 */

/* base clock for baudrate generator from MCU */
#define     SPI_70_FCLK        McuClockReferencePointRef[0].McuClockReferencePointFrequency[1]

/* The number of different SPI hardware microcontroller peripherals. */
#define SPI_70_MAX_HW_UNIT_USING         ( 1U )

/* SPI BUS(HW UNIT) ID */
#define SPI_70_CSIB2                     ( 2U )     /* CSI BUS 0 */

/* [ECUC_Spi_00197] */
#define SPI_MAX_CHANNEL                  ( (Spi_ChannelType)10U )

/* SPI CHANNEL-ID */
#define SPI_70_CH_ID_0                   ( 0U )
#define SPI_70_CH_ID_1                   ( 1U )
#define SPI_70_CH_ID_2                   ( 2U )
#define SPI_70_CH_ID_3                   ( 3U )
#define SPI_70_CH_ID_4                   ( 4U )
#define SPI_70_CH_ID_5                   ( 5U )
#define SPI_70_CH_ID_6                   ( 6U )
#define SPI_70_CH_ID_7                   ( 7U )
#define SPI_70_CH_ID_8                   ( 8U )
#define SPI_70_CH_ID_9                   ( 9U )

/* number of IB channel link information */
#define SPI_70_NUM_OF_CHIBLINK           ( 4U )

/* [ECUC_Spi_00198] */
#define SPI_MAX_JOB                      ( (Spi_JobType)10U )

/* SPI JOB-ID */
#define SPI_70_JOB_ID_0                  ( 0U )
#define SPI_70_JOB_ID_1                  ( 1U )
#define SPI_70_JOB_ID_2                  ( 2U )
#define SPI_70_JOB_ID_3                  ( 3U )
#define SPI_70_JOB_ID_4                  ( 4U )
#define SPI_70_JOB_ID_5                  ( 5U )
#define SPI_70_JOB_ID_6                  ( 6U )
#define SPI_70_JOB_ID_7                  ( 7U )
#define SPI_70_JOB_ID_8                  ( 8U )
#define SPI_70_JOB_ID_9                  ( 9U )

/* number of channels for JOB-ID */
#define SPI_70_CH_NUM_JOB_ID_0           ( 1U )
#define SPI_70_CH_NUM_JOB_ID_1           ( 1U )
#define SPI_70_CH_NUM_JOB_ID_2           ( 1U )
#define SPI_70_CH_NUM_JOB_ID_3           ( 1U )
#define SPI_70_CH_NUM_JOB_ID_4           ( 1U )
#define SPI_70_CH_NUM_JOB_ID_5           ( 1U )
#define SPI_70_CH_NUM_JOB_ID_6           ( 1U )
#define SPI_70_CH_NUM_JOB_ID_7           ( 1U )
#define SPI_70_CH_NUM_JOB_ID_8           ( 1U )
#define SPI_70_CH_NUM_JOB_ID_9           ( 1U )

/* [ECUC_Spi_00199] */
#define SPI_MAX_SEQUENCE                 ( (Spi_SequenceType)11U )

/* SPI SEQUENCE-ID */
#define SPI_70_SEQ_ID_0                  ( 0U )
#define SPI_70_SEQ_ID_1                  ( 1U )
#define SPI_70_SEQ_ID_2                  ( 2U )
#define SPI_70_SEQ_ID_3                  ( 3U )
#define SPI_70_SEQ_ID_4                  ( 4U )
#define SPI_70_SEQ_ID_5                  ( 5U )
#define SPI_70_SEQ_ID_6                  ( 6U )
#define SPI_70_SEQ_ID_7                  ( 7U )
#define SPI_70_SEQ_ID_8                  ( 8U )
#define SPI_70_SEQ_ID_9                  ( 9U )
#define SPI_70_SEQ_ID_10                 ( 10U )

/* number of jobs for SEQUENCE-ID */
#define SPI_70_JOB_NUM_SEQ_ID_0          ( 1U )
#define SPI_70_JOB_NUM_SEQ_ID_1          ( 1U )
#define SPI_70_JOB_NUM_SEQ_ID_2          ( 1U )
#define SPI_70_JOB_NUM_SEQ_ID_3          ( 1U )
#define SPI_70_JOB_NUM_SEQ_ID_4          ( 1U )
#define SPI_70_JOB_NUM_SEQ_ID_5          ( 2U )
#define SPI_70_JOB_NUM_SEQ_ID_6          ( 1U )
#define SPI_70_JOB_NUM_SEQ_ID_7          ( 1U )
#define SPI_70_JOB_NUM_SEQ_ID_8          ( 1U )
#define SPI_70_JOB_NUM_SEQ_ID_9          ( 1U )
#define SPI_70_JOB_NUM_SEQ_ID_10         ( 2U )

#define SPI_70_DEM_SET_EVENT_STATUS        ( TRUE )
#if ( SPI_70_DEM_SET_EVENT_STATUS != FALSE )
/* [ECUC_Spi_00241] */
#define SPI_E_HARDWARE_ERROR             ( DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR )
#endif
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

#endif    /* SPI_CFG_H */

/*************************** EOF Spi_Cfg.h ***********************************/
