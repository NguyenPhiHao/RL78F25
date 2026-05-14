/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Spi_70_RL78F2X_Types.h                                       */
/* Version     : v1.00.01                                                     */
/* Contents    : SPI module Hw Dependent type definitions header file         */
/*               The SPI Handler/Driver provides services for reading         */
/*               from and writing to devices connected via SPI busses         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef SPI_70_RL78F2X_TYPES_H_
#define SPI_70_RL78F2X_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Port.h"
#include "QiNeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_RL78F2X_TYPES_H           (70U)
#define SPI_70_MODULE_ID_RL78F2X_TYPES_H           (83U)

#define SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H    (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H    (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H (0U)

#define SPI_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H    (1U)
#define SPI_70_SW_MINOR_VERSION_RL78F2X_TYPES_H    (0U)
#define SPI_70_SW_PATCH_VERSION_RL78F2X_TYPES_H    (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Port.h version check start */
#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H != PORT_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H != PORT_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Spi_70_RL78F2X_Types.h and Port.h are different"
#endif
/* Port.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/* RL78F2X native CSI unit & channel ID */
typedef uint8 Spi_70_RL78F2X_HwUnitChType;
#define SPI_70_RL78F2X_CSIB0_0           (uint8)(0U)   /* CSI Unit0-0 */
#define SPI_70_RL78F2X_CSIB0_1           (uint8)(1U)   /* CSI Unit0-1 */
#define SPI_70_RL78F2X_CSIB1_0           (uint8)(2U)   /* CSI Unit1-0 */
#define SPI_70_RL78F2X_CSIB1_1           (uint8)(3U)   /* CSI Unit1-1 */
#define SPI_70_RL78F2X_DEFAULT_HW_UNIT   (uint8)(0U)   /* Default SPI HW Unit number */
#define SPI_70_RL78F2X_HW_UNIT_NUM       (4U)          /* The Number of SPI HW Units */

typedef uint8 Spi_70_RL78F2X_IdleLevelType;
#define SPI_70_RL78F2X_IDLE_HIGH         (uint8)(1U)
#define SPI_70_RL78F2X_IDLE_LOW          (uint8)(0U)

/* HW Register */
typedef struct {
    volatile uint16 SSR;
    volatile uint16 pad1;
    volatile uint16 SIR;
    volatile uint16 pad2;
    volatile uint16 SMR;
    volatile uint16 pad3;
    volatile uint16 SCR;
} Spi_70_RL78F2X_ChannelRegType;

typedef uint16 Spi_70_RL78F2X_SDRType;

typedef struct {
    volatile uint16 SE;
    volatile uint16 SS;
    volatile uint16 ST;
    volatile uint16 SPS;
    volatile uint16 SO;
    volatile uint16 SOE;
    volatile uint16 pad1;
    volatile uint16 pad2;
    volatile uint16 SOL;
    volatile uint16 SSE;
} Spi_70_RL78F2X_UnitRegType;

typedef uint8 Spi_70_RL78F2X_MKType;

typedef uint8 Spi_70_RL78F2X_NFENType;

typedef uint8 Spi_70_RL78F2X_ISCType;

typedef uint8 Spi_70_RL78F2X_UTSELType;

typedef struct {
    volatile Spi_70_RL78F2X_ChannelRegType* ChannelReg;
    volatile Spi_70_RL78F2X_SDRType*            SDR;
    volatile Spi_70_RL78F2X_UnitRegType*       UnitReg;
    uint8                                      UnitRegShift;
    volatile Spi_70_RL78F2X_MKType*            MK;
    uint8                                      MKShift;
    volatile Spi_70_RL78F2X_NFENType*          NFEN;
    uint8                                      NFENShift;
    volatile Spi_70_RL78F2X_ISCType*           ISCR;
    uint8                                      ISCShift;
    volatile Spi_70_RL78F2X_UTSELType*         UTSEL;
    uint8                                      UTSELShift;
} Spi_70_RL78F2X_HwUnitRegInfoType;

/* CS port configuration */
typedef struct {
    uint8 SpiCsIdentifier;  /* ECUC_Spi_00209] Chip Select (CS) */
    uint8 SpiCsPort;        /* Port number for CS output */
    uint8 SpiCsBitPos;      /* Bit position for CS output */
} Spi_70_RL78F2X_CsConfType;

typedef struct {
    Spi_70_RL78F2X_HwUnitChType SpiHwUnitCh;  /* HW native unit/channel ID */
    Port_PinType               SpiPortClock; /* SPI clock port */
    Port_PinType               SpiPortIn;    /* SPI input port */
    Port_PinType               SpiPortOut;   /* SPI output port */
} Spi_70_RL78F2X_HwUnitConfType;

typedef struct {
    uint16 valPRS;  /* values for set baudrate */
    uint16 valSDR;  /* value for SDR */
} Spi_70_RL78F2X_ExDevInfoType;

/*----------------------------------------------------------------------------*/
/* external constant                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

#endif    /* #ifndef SPI_70_RL78F2X_TYPES_H_ */

/******************** End Of File Spi_70_RL78F2X_Types.h ********************/
