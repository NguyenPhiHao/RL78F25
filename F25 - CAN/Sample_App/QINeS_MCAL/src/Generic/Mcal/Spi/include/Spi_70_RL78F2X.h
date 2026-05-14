/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Spi_70_RL78F2X.h                                             */
/* Version     : v1.00.01                                                     */
/* Contents    : SPI module HW dependent header file                          */
/*               The SPI Handler/Driver provides services for reading         */
/*               from and writing to devices connected via SPI busses.        */
/* Author      : --                                                           */
/* Note        : For F24/F25                                                  */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef SPI_70_RL78F2X_H
#define SPI_70_RL78F2X_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Spi_Cfg.h"
#include "Mcu_Cfg.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_RL78F2X_H                ( 70U )
#define SPI_70_MODULE_ID_RL78F2X_H                ( 83U )

#define SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ( 22U )
#define SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ( 11U )
#define SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ( 00U )

#define SPI_70_SW_MAJOR_VERSION_RL78F2X_H         ( 1U )
#define SPI_70_SW_MINOR_VERSION_RL78F2X_H         ( 0U )
#define SPI_70_SW_PATCH_VERSION_RL78F2X_H         ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Std_Types.h version check start */
#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )   \
    )
  #error "AUTOSAR Version Numbers of Spi_70_RL78F2X.h and Std_Types.h are different"
#endif
/* Std_Types.h version check end */

/* Spi_Cfg.h version check start */
#if ( SPI_70_VENDOR_ID_RL78F2X_H != SPI_70_VENDOR_ID_CFG_H )
  #error "VENDOR ID for Spi_70_RL78F2X.h and Spi_Cfg.h are different"
#endif

#if ( SPI_70_MODULE_ID_RL78F2X_H != SPI_70_MODULE_ID_CFG_H )
  #error "MODULE ID for Spi_70_RL78F2X.h and Spi_Cfg.h are different"
#endif

#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != SPI_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != SPI_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != SPI_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
  #error "AUTOSAR Version Numbers of Spi_70_RL78F2X.h and Spi_Cfg.h are different"
#endif

#if ( ( SPI_70_SW_MAJOR_VERSION_RL78F2X_H != SPI_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( SPI_70_SW_MINOR_VERSION_RL78F2X_H != SPI_70_SW_MINOR_VERSION_CFG_H ) || \
      ( SPI_70_SW_PATCH_VERSION_RL78F2X_H != SPI_70_SW_PATCH_VERSION_CFG_H ) \
    )
  #error "Software Version Numbers of Spi_70_RL78F2X.h and Spi_Cfg.h are different"
#endif
/* Spi_Cfg.h version check end */

/* Mcu_Cfg.h version check start */
#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != MCU_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != MCU_70_AR_RELEASE_MINOR_VERSION_CFG_H )   \
    )
  #error "AUTOSAR Version Numbers of Spi_70_RL78F2X.h and Mcu_Cfg.h are different"
#endif
/* Mcu_Cfg.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                     */
/*----------------------------------------------------------------------------*/
#define SPI_70_CLK2CS                 ( 0x00U )
#define SPI_70_CS2CLK                 ( 0x01U )
#define SPI_70_CS2CS                  ( 0x02U )

/*----------------------------------------------------------------------------*/
/* type definitions                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external constant                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* H/W dependent functions.                                  */
/*----------------------------------------------------------------------------*/
extern void Spi_70_RL78F2X_Init(const Spi_ConfigType* ConfigPtr);
extern void Spi_70_RL78F2X_DeInit(const Spi_ConfigType* ConfigPtr);
extern Std_ReturnType Spi_70_RL78F2X_StartChannel(
    Spi_HWUnitType               hwUnit,
    uint8                        devId,
    uint8                        dataWidth,
    Spi_70_TransferStartType     transferStart,
    Spi_70_DataShiftEdgeType     dataShiftEdge,
    uint8                        shiftClockIdleLevel
);
extern Std_ReturnType Spi_70_RL78F2X_TransmitChannel(
    Spi_HWUnitType hwUnit,
    const uint8*   txData,
    uint8          len
);
extern Std_ReturnType Spi_70_RL78F2X_ReceiveChannel(
    Spi_HWUnitType hwUnit,
    uint8*         rxData,
    uint8*         len
);
extern void Spi_70_RL78F2X_StopChannel(
    Spi_HWUnitType hwUnit,
    uint8          shiftClockIdleLevel
);
extern void Spi_70_RL78F2X_PutChipSelect(
    uint8                     csId,
    bool_t                    flgAssert,
    Spi_70_PolarityType       csPolarity,
    void (* const calloutPtr)(uint32 timeParam),
    uint32                    timeParam,
    uint8                     timing
);
extern bool_t Spi_70_RL78F2X_GetHWErrorStatus(Spi_HWUnitType hwUnit);
extern void Spi_70_RL78F2X_DisableInterrupts(void);
extern void Spi_70_RL78F2X_EnableInterrupts(void);
extern void Spi_70_RL78F2X_SelectUnit(Spi_HWUnitType hwUnit);

#endif  /* #ifndef SPI_70_RL78F2X_H */

/********** End Of File Spi_70_RL78F2X.h **********/
