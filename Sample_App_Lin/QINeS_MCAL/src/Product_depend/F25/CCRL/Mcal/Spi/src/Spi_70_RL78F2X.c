/******************************************************************************/
/* Copyright   : 2023 SCSK Corporation                                        */
/* System Name : QINeS-Lite MCAL                                              */
/* File Name   : Spi_70_RL78F2X.c                                             */
/* Version     : v1.00.02                                                     */
/* Contents    : SPI module Hw dependent functionality                        */
/*               The SPI Handler/Driver provides services for reading from    */
/*               and writing to devices connected via SPI busses.             */
/* Author      : h.tsunoda                                                    */
/* Note        : For F25                                                      */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Spi.h"
#include "Spi_70_RL78F2X_HwReg.h"
#include "Port.h"
#include "SchM_Spi.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_RL78F2X_C                      (70U)
#define SPI_70_MODULE_ID_RL78F2X_C                      (83U)
 
#define SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C       (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C       (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C    (0U)
 
#define SPI_70_SW_MAJOR_VERSION_RL78F2X_C               (1U)
#define SPI_70_SW_MINOR_VERSION_RL78F2X_C               (0U)
#define SPI_70_SW_PATCH_VERSION_RL78F2X_C               (0U)
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/* Spi.h version check start */
 
#if ( SPI_70_VENDOR_ID_RL78F2X_C != SPI_VENDOR_ID )
    #error "VENDOR ID for Spi_70_RL78F2X.c and Spi.h are different"
#endif
 
#if ( SPI_70_MODULE_ID_RL78F2X_C != SPI_MODULE_ID )
    #error "MODULE ID for Spi_70_RL78F2X.c and Spi.h are different"
#endif
 
#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != SPI_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != SPI_AR_RELEASE_MINOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != SPI_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Spi_70_RL78F2X.c and Spi.h are different"
#endif
 
#if ( ( SPI_70_SW_MAJOR_VERSION_RL78F2X_C != SPI_SW_MAJOR_VERSION ) || \
      ( SPI_70_SW_MINOR_VERSION_RL78F2X_C != SPI_SW_MINOR_VERSION ) || \
      ( SPI_70_SW_PATCH_VERSION_RL78F2X_C != SPI_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Spi_70_RL78F2X.c and Spi.h are different"
#endif
 
/* Spi.h version check end */
 
/* Spi_70_RL78F2X_HwReg.h version check start */
 
#if ( SPI_70_VENDOR_ID_RL78F2X_C != SPI_70_VENDOR_ID_RL78F2X_HWREG_H )
    #error "VENDOR ID for Spi_70_RL78F2X.c and Spi_70_RL78F2X_HwReg.h are different"
#endif
 
#if ( SPI_70_MODULE_ID_RL78F2X_C != SPI_70_MODULE_ID_RL78F2X_HWREG_H )
    #error "MODULE ID for Spi_70_RL78F2X.c and Spi_70_RL78F2X_HwReg.h are different"
#endif
 
#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_HWREG_H ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_HWREG_H ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_HWREG_H ) \
    )
    #error "AUTOSAR Version Numbers of Spi_70_RL78F2X.c and Spi_70_RL78F2X_HwReg.h are different"
#endif
 
#if ( ( SPI_70_SW_MAJOR_VERSION_RL78F2X_C != SPI_70_SW_MAJOR_VERSION_RL78F2X_HWREG_H ) || \
      ( SPI_70_SW_MINOR_VERSION_RL78F2X_C != SPI_70_SW_MINOR_VERSION_RL78F2X_HWREG_H ) || \
      ( SPI_70_SW_PATCH_VERSION_RL78F2X_C != SPI_70_SW_PATCH_VERSION_RL78F2X_HWREG_H ) \
    )
    #error "Software Version Numbers of Spi_70_RL78F2X.c and Spi_70_RL78F2X_HwReg.h are different"
#endif
 
/* Spi_70_RL78F2X_HwReg.h version check end */
 
/* Port.h version check start */
 
#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C != PORT_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C != PORT_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Spi_70_RL78F2X.c and Port.h are different"
#endif
 
/* Port.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define SPI_START_SEC_CONST_8
#include "Spi_MemMap.h"
 
/* UTSEL(*1) is available only F22,F25. */
static Spi_70_RL78F2X_HwUnitRegInfoType const s_HwUnitRegInfo[SPI_70_RL78F2X_HW_UNIT_NUM] = {
    {
        ( ( volatile Spi_70_RL78F2X_ChannelRegType QL_70_NEAR *)0x0100U ),     /* ChannelReg */
        ( ( volatile Spi_70_RL78F2X_SDRType QL_70_NEAR *)0xFF10U ),            /* SDR */
        ( ( volatile Spi_70_RL78F2X_UnitRegType QL_70_NEAR *)0x0110U ),        /* UnitReg */
        0U,                                                                    /* UnitRegShift */
        ( ( volatile Spi_70_RL78F2X_MKType QL_70_NEAR *)0xFFE5U ),             /* MK */
        1U,                                                                    /* MKShift */
        ( ( volatile Spi_70_RL78F2X_NFENType QL_70_NEAR *)0x0070U ),           /* NFEN */
        0U,                                                                    /* NFENShift */
        ( ( volatile Spi_70_RL78F2X_ISCType QL_70_NEAR *)0x0073U ),            /* ISC */
        0U,                                                                    /* ISCShift */
        ( ( volatile Spi_70_RL78F2X_UTSELType QL_70_NEAR *)0x01F0U ),          /* UTSEL(*1) */
        2U                                                                     /* UTSELShift */
    },
    {
        ( ( volatile Spi_70_RL78F2X_ChannelRegType QL_70_NEAR *)0x0102U ),     /* ChannelReg */
        ( ( volatile Spi_70_RL78F2X_SDRType QL_70_NEAR *)0xFF12U ),            /* SDR */
        ( ( volatile Spi_70_RL78F2X_UnitRegType QL_70_NEAR *)0x0110U ),        /* UnitReg */
        1U,                                                                    /* UnitRegShift */
        ( ( volatile Spi_70_RL78F2X_MKType QL_70_NEAR *)0xFFE5U ),             /* MK */
        2U,                                                                    /* MKShift */
        ( ( volatile Spi_70_RL78F2X_NFENType QL_70_NEAR *)0x0070U ),           /* NFEN */
        0U,                                                                    /* NFENShift */
        ( ( volatile Spi_70_RL78F2X_ISCType QL_70_NEAR *)0x0073U ),            /* ISC */
        0U,                                                                    /* ISCShift */
        ( ( volatile Spi_70_RL78F2X_UTSELType QL_70_NEAR *)0x01F0U ),          /* UTSEL(*1) */
        2U                                                                     /* UTSELShift */
    },
    {
        ( ( volatile Spi_70_RL78F2X_ChannelRegType QL_70_NEAR *)0x0100U ),     /* ChannelReg */
        ( ( volatile Spi_70_RL78F2X_SDRType QL_70_NEAR *)0xFF48U ),            /* SDR */
        ( ( volatile Spi_70_RL78F2X_UnitRegType QL_70_NEAR *)0x0110U ),        /* UnitReg */
        0U,                                                                    /* UnitRegShift */
        ( ( volatile Spi_70_RL78F2X_MKType QL_70_NEAR *)0xFFE7U ),             /* MK */
        5U,                                                                    /* MKShift */
        ( ( volatile Spi_70_RL78F2X_NFENType QL_70_NEAR *)0x0070U ),           /* NFEN */
        2U,                                                                    /* NFENShift */
        ( ( volatile Spi_70_RL78F2X_ISCType QL_70_NEAR *)0x0073U ),            /* ISC */
        0U,                                                                    /* ISCShift */
        ( ( volatile Spi_70_RL78F2X_UTSELType QL_70_NEAR *)0x01F0U ),          /* UTSEL(*1) */
        2U                                                                     /* UTSELShift */
    },
    {
        ( ( volatile Spi_70_RL78F2X_ChannelRegType QL_70_NEAR *)0x0102U ),     /* ChannelReg */
        ( ( volatile Spi_70_RL78F2X_SDRType QL_70_NEAR *)0xFF4AU ),            /* SDR */
        ( ( volatile Spi_70_RL78F2X_UnitRegType QL_70_NEAR *)0x0110U ),        /* UnitReg */
        1U,                                                                    /* UnitRegShift */
        ( ( volatile Spi_70_RL78F2X_MKType QL_70_NEAR *)0xFFE7U ),             /* MK */
        6U,                                                                    /* MKShift */
        ( ( volatile Spi_70_RL78F2X_NFENType QL_70_NEAR *)0x0070U ),           /* NFEN */
        2U,                                                                    /* NFENShift */
        ( ( volatile Spi_70_RL78F2X_ISCType QL_70_NEAR *)0x0073U ),            /* ISC */
        0U,                                                                    /* ISCShift */
        ( ( volatile Spi_70_RL78F2X_UTSELType QL_70_NEAR *)0x01F0U ),          /* UTSEL(*1) */
        2U                                                                     /* UTSELShift */
    }
};
 
#define SPI_STOP_SEC_CONST_8
#include "Spi_MemMap.h"
 
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#define SPI_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Spi_MemMap.h"
 
static const Spi_70_HW_HwUnitConfType* s_HwUnitConfPtr = NULL_PTR;
static const Spi_70_HW_CsConfType* s_CsConfPtr = NULL_PTR;
 
#define SPI_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Spi_MemMap.h"
 
#define SPI_START_SEC_VAR_INIT_LOCAL_16
#include "Spi_MemMap.h"
 
static Spi_70_RL78F2X_ExDevInfoType s_ExDevInfo[SPI_70_MAX_EX_DEVICE] = { 0 };
 
#define SPI_STOP_SEC_VAR_INIT_LOCAL_16
#include "Spi_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* static function prototype                                                  */
/*----------------------------------------------------------------------------*/
static void spi_hwPutChipSelect( bool_t csValue, uint8 csPort, uint8 csBitPos );
static Std_ReturnType spi_checkTransmitStart( Spi_HWUnitType hwUnit );
 
/*----------------------------------------------------------------------------*/
/*  static variables                                                          */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define SPI_START_SEC_CODE_LOCAL
#include "Spi_MemMap.h"
 
/* H/W dependent functions. */
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_RL78F2X_Init                                          */
/* Param       : (in) ConfigPtr: pointer to configuration.                    */
/* Return      : void                                                         */
/* Contents    : HW dependent initialize.                                     */
/* Author      : k.sawada h.shishido s.nitao                                  */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_70_RL78F2X_Init( const Spi_ConfigType* ConfigPtr )
{
    const Spi_DriverType*                driverPtr;
    const Spi_70_HW_HwUnitConfType* hwConfPtr;
    const Spi_ExternalDeviceType* exDevCfgPtr;
    const Spi_70_HW_CsConfType* csCfgPtr = NULL_PTR;
    uint16_least exDevCnt;
    uint16_least csCnt;
    uint8_least hwUnitCnt;
    uint8 level;
    uint8 n;
    uint8 i;
    uint16 prs;
    uint16 sdr;
    uint32 fClk;
    uint32 fMck;
    uint32 fTclk;
    volatile Spi_70_RL78F2X_MKType* mkReg;
    volatile Spi_70_RL78F2X_UnitRegType* unitReg;
    volatile Spi_70_RL78F2X_SDRType* sdrReg;
    volatile Spi_70_RL78F2X_ChannelRegType* channelReg;
    volatile Spi_70_RL78F2X_NFENType* nfen;
    volatile Spi_70_RL78F2X_ISCType* isc;
    volatile Spi_70_RL78F2X_UTSELType* utsel;
    uint8 unitRegShift;
    uint8 mkShift;
   
    /* Get configuration */
    driverPtr = &( ConfigPtr->SpiDriver );
    s_HwUnitConfPtr = driverPtr->Spi_70_HwUnitConfPtr;
    s_CsConfPtr = driverPtr->Spi_70_CsConfPtr;
    fClk = SPI_70_FCLK;
   
    for ( exDevCnt = 0U; exDevCnt < SPI_70_MAX_EX_DEVICE; exDevCnt++ ) {
        exDevCfgPtr = &(driverPtr->SpiExternalDevice[exDevCnt]);
       
        /* Negate chip select */
        if ( TRUE == exDevCfgPtr->SpiEnableCs ) {
            /* Get negate level */
            if ( SPI_70_POLARITY_HIGH == exDevCfgPtr->SpiCsPolarity ) {
                level = STD_LOW;
            } else {
                level = STD_HIGH;
            }
           
            /* Get chip select config */
            for ( csCnt = 0U; csCnt < SPI_70_NUM_OF_CS_CONF; csCnt++ ) {
                if ( exDevCfgPtr->SpiCsIdentifier == s_CsConfPtr[csCnt].SpiCsIdentifier ) {
                    csCfgPtr = &(s_CsConfPtr[csCnt]);
                    break;
                }
            }
           
            /* Set chip select */
            spi_hwPutChipSelect( level, csCfgPtr->SpiCsPort, csCfgPtr->SpiCsBitPos );
        }
       
        /* Calculate baud rate */
        /* The maximum value of 4 bits (PRSmk3 - PRSmk0) is 1011(11 in hexadecimal) */
        for ( prs = 0U; prs < 12U; prs++ )  {
            /* The value 0000 represents 1 division */
            /* The value 0001 represents 2 division */
            /* The value 0010 represents 4 division */
            n = 1U;
            for ( i = 0U; i < prs; i++ ) {
                n = n * 2U;
            }
            fMck = ( fClk / (uint32)n );
           
            /* The maximum value of 7 bits (SDRmn[15:9]) is 1111111(127 in hexadecimal) */
            for ( sdr = 0U; sdr < 128U; sdr++ ) {
                /* The value 0000000 represents 2 division               */
                /* The value 0000001 represents 4 division               */
                /* The value 0000010 represents 6 division               */
                /* ...                                                   */
                /* Therefore, Therefore, divide by the following formula */
                fTclk = ( fMck / ( ( (uint32)sdr + 1U ) * 2U ) );
               
                /* Check if the calculation result matches the baud rate */
                if ( fTclk == exDevCfgPtr->SpiBaudrate ) {
                    /* SDRmn[15:9] */
                    s_ExDevInfo[exDevCnt].valSDR = sdr << 9U;
                    break;
                }
            }
           
            /* Check if the calculation result matches the baud rate */
            if ( fTclk == exDevCfgPtr->SpiBaudrate ) {
                /* PRSmk3 - PRSmk0 */
                s_ExDevInfo[exDevCnt].valPRS = prs;
                break;
            }
        }
       
        /* If the baud rate is smaller than the configurable baud rate */
        if ( ( 12U <= prs ) && ( 128U <= sdr ) ) {
            /* set the HW minimum baud rate */
            s_ExDevInfo[exDevCnt].valPRS = 0x000BU;
            s_ExDevInfo[exDevCnt].valSDR = (uint16)0x007FU << 9U;
        }
    }
   
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
   
    for ( hwUnitCnt = 0U ; hwUnitCnt < SPI_70_MAX_HW_UNIT_USING; hwUnitCnt++ ) {
        hwConfPtr    = &(s_HwUnitConfPtr[hwUnitCnt]);
 
        /* Select SPI hardware unit */
        Spi_70_RL78F2X_SelectUnit( hwConfPtr->SpiHwUnitCh );
   
        /* Get register information */
        mkReg        = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].MK;
        unitReg      = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].UnitReg;
        sdrReg       = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].SDR;
        channelReg   = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].ChannelReg;
        unitRegShift = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].UnitRegShift;
        mkShift      = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].MKShift;
        nfen         = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].NFEN;
        isc          = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].ISCR;
        utsel        = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].UTSEL;
       
        /* Disable interrupt */
        *mkReg |= (uint8)( SPI_70_RL78F2X_MKx_CSIMKmn << mkShift );
       
        /* Stop HW unit */
        /* Set ST bit  to 1 */
        unitReg->ST  |= ( SPI_70_RL78F2X_ST_ST << unitRegShift );
        /* Set SOE bit to 0 */
        unitReg->SOE &= ~( SPI_70_RL78F2X_SOE_SOE << unitRegShift);
       
        /* Disable port for SFR setting */
        /* Set port pin direction to input */
        Port_70_HW_SetPinDirection( hwConfPtr->SpiPortClock, PORT_PIN_IN );
        Port_70_HW_SetPinDirection( hwConfPtr->SpiPortOut,   PORT_PIN_IN );
       
        unitReg->SPS    = 0x0000U; /* SPSm  divide by 1 */
        *sdrReg         = 0x0000U; /* SDRmn divide by 2 */
        channelReg->SMR = 0x0020U; /* SMRmn CSI mode, transfer complete interrupt */
        channelReg->SCR = 0xC087U; /* SMRmn LSB first, 8bit data length */
        channelReg->SIR = 0x0007U; /* SIRmn Clear error */
        unitReg->SOE    = 0x0000U; /* SOEm  Stop output by serial*/
        unitReg->SO     = 0x0000U; /* SOm   SCKmn low, SOmn low */
       
        /* Enable port after SFR setting */
        /* Set port pin direction to output */
        Port_70_HW_SetPinDirection( hwConfPtr->SpiPortClock, PORT_PIN_OUT );
        Port_70_HW_SetPinDirection( hwConfPtr->SpiPortOut,   PORT_PIN_OUT );
       
        /* Unused registers */
        /* Set reset value */
        *nfen        = 0x00U;   /* NFEN */
        *isc         = 0x00U;   /* ISC */
        *utsel       = 0x00U;   /* UTSEL */
        unitReg->SOL = 0x0000U; /* SOLm */
        unitReg->SSE = 0x0000U; /* SSEm */
    }
   
    /* Interrupts are disabled during register acceses operations. */
     /* Enable interrupt. */
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
   
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_RL78F2X_DeInit                                        */
/* Param       : (in) ConfigPtr: pointer to configuration.                    */
/* Return      : void                                                         */
/* Contents    : HW dependent de-initialize.                                  */
/* Author      : k.sawada h.shishido s.nitao                                  */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_70_RL78F2X_DeInit( const Spi_ConfigType* ConfigPtr  )
{
    const Spi_DriverType*         driverPtr;        /* pointer to SPI driver */
    const Spi_70_RL78F2X_HwUnitConfType*    hwConfPtr;      /* pointer to HW unit configuration */
    const Spi_ExternalDeviceType* exDevCfgPtr;
    const Spi_70_RL78F2X_CsConfType* csCfgPtr = NULL_PTR;
    volatile Spi_70_RL78F2X_MKType* mkReg;
    volatile Spi_70_RL78F2X_UnitRegType* unitReg;
    uint8 unitRegShift;
    volatile Spi_70_RL78F2X_SDRType* sdrReg;
    volatile Spi_70_RL78F2X_ChannelRegType* channelReg;
    volatile Spi_70_RL78F2X_NFENType* nfen;
    volatile Spi_70_RL78F2X_ISCType* isc;
    volatile Spi_70_RL78F2X_UTSELType* utsel;
    uint8 mkShift;
    uint16_least exDevCnt;
    uint16_least csCnt;
    uint8_least hwUnitCnt;
    uint8 level;
   
    /* Get configuration */
    driverPtr = &( ConfigPtr->SpiDriver );
   
    /* Interrupts are disabled during register acceses operations. */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
   
    for ( hwUnitCnt = 0U ; hwUnitCnt < SPI_70_MAX_HW_UNIT_USING; hwUnitCnt++ ) {
        hwConfPtr    = &(s_HwUnitConfPtr[hwUnitCnt]);
   
        /* Select SPI hardware unit */
        Spi_70_RL78F2X_SelectUnit(  hwConfPtr->SpiHwUnitCh );
 
        /* Get register information */
        mkReg        = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].MK;
        unitReg      = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].UnitReg;
        sdrReg       = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].SDR;
        channelReg   = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].ChannelReg;
        unitRegShift = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].UnitRegShift;
        mkShift      = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].MKShift;
        nfen         = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].NFEN;
        isc          = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].ISCR;
        utsel        = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].UTSEL;
       
        /* Disable interrupt */
        *mkReg |= (uint8)( SPI_70_RL78F2X_MKx_CSIMKmn << mkShift );
       
        /* Stop HW unit */
        /* Set ST bit  to 1 */
        unitReg->ST  |= ( SPI_70_RL78F2X_ST_ST << unitRegShift );
        /* Set SOE bit to 0 */
        unitReg->SOE &= ~( SPI_70_RL78F2X_SOE_SOE << unitRegShift );
       
        /* Disable port for SFR setting */
        /* Set port pin direction to input */
        Port_70_HW_SetPinDirection( hwConfPtr->SpiPortClock, PORT_PIN_IN );
        Port_70_HW_SetPinDirection( hwConfPtr->SpiPortOut,   PORT_PIN_IN );
       
        unitReg->SPS    = 0x0000U; /* SPSm  divide by 1 */
        *sdrReg         = 0x0000U; /* SDRmn divide by 2 */
        channelReg->SMR = 0x0020U; /* SMRmn CSI mode, transfer complete interrupt */
        channelReg->SCR = 0x0087U; /* SMRmn LSB first, 8bit data length */
        channelReg->SIR = 0x0007U; /* SIRmn Clear error */
        unitReg->SOE    = 0x0000U; /* SOEm  Stop output by serial*/
        unitReg->SO     = 0x0303U; /* SOm   SCKmn high, SOmn high */
       
        /* Unused registers */
        /* Set reset value */
        *nfen        = 0x00U;   /* NFEN */
        *isc         = 0x00U;   /* ISC */
        *utsel       = 0x00U;   /* UTSEL */
        unitReg->SOL = 0x0000U; /* SOLm */
        unitReg->SSE = 0x0000U; /* SSEm */
    }
 
    /* Enable interrupt. */
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
   
    for ( exDevCnt = 0U; exDevCnt < SPI_70_MAX_EX_DEVICE; exDevCnt++ ) {
        exDevCfgPtr = &(driverPtr->SpiExternalDevice[exDevCnt]);
       
        /* Negate chip select */
        if ( TRUE == exDevCfgPtr->SpiEnableCs ) {
            /* Get negate level */
            if ( SPI_70_POLARITY_HIGH == exDevCfgPtr->SpiCsPolarity ) {
                level = STD_LOW;
            } else {
                level = STD_HIGH;
            }
           
            /* Get chip select config */
            for ( csCnt = 0U; csCnt < SPI_70_NUM_OF_CS_CONF; csCnt++ ) {
                if ( exDevCfgPtr->SpiCsIdentifier == s_CsConfPtr[csCnt].SpiCsIdentifier ) {
                    csCfgPtr = &(s_CsConfPtr[csCnt]);
                    break;
                }
            }
           
            /* Set chip select */
            spi_hwPutChipSelect( level, csCfgPtr->SpiCsPort, csCfgPtr->SpiCsBitPos );
        }
       
        /* clear data */
        s_ExDevInfo[exDevCnt].valPRS = 0U;
        s_ExDevInfo[exDevCnt].valSDR = 0U;
    }
   
    /* Clear configuration */
    s_HwUnitConfPtr = NULL_PTR;
    s_CsConfPtr     = NULL_PTR;    
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_hwPutChipSelect                                          */
/* Param       : (in) csValue : value of output level (0 or 1).               */
/*             : (in) csPort  : Port number for CS output                     */
/*             : (in) csBitPos: Bit position for CS output                    */
/* Return      : void                                                         */
/* Contents    : output HW dependent CS signal.                               */
/* Author      : k.sawada h.shishido s.nitao                                  */
/* Note        : NO check for SpiCsSelection, because RL78F2X is not supported*/
/******************************************************************************/
static void spi_hwPutChipSelect( bool_t csValue, uint8 csPort, uint8 csBitPos )
{
    Port_70_HW_SetPortBit( csPort, csBitPos, csValue );
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_RL78F2X_StartChannel                                  */
/* Param       : (in) hwUnit: The ID of the HW SPI Hardware                   */
/*                              microcontroller peripheral.                   */
/*             : (in) devId: The ID of external device.                       */
/*             : (in) dataWidth: width of Tx data unit.                       */
/*             : (in) transferStart: select LSB or MSB.                       */
/*             : (in) dataShiftEdge: The SPI data shift edge.                 */
/*             : (in) shiftClockIdleLevel: SPI shift clock idle level.        */
/* Return      : Std_ReturnType:                                              */
/*                     E_OK:     command has been accepted.                   */
/*                     E_NOT_OK: command has not been accepted.               */
/* Contents    : HW dependent set port serial clock / dout signal for input   */
/* Author      : k.sawada h.shishido s.nitao                                  */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Spi_70_RL78F2X_StartChannel( Spi_HWUnitType hwUnit,
                                            uint8 devId,
                                            uint8 dataWidth,
                                            Spi_70_TransferStartType transferStart,
                                            Spi_70_DataShiftEdgeType dataShiftEdge,
                                            uint8 shiftClockIdleLevel )
{
    Std_ReturnType retVal;
    uint16 val;
    uint16 tmp;
    uint8 unitRegShift;
    volatile Spi_70_RL78F2X_ChannelRegType* channelReg;
    volatile Spi_70_RL78F2X_SDRType* sdrReg;
    volatile Spi_70_RL78F2X_UnitRegType* unitReg;
    const Spi_70_RL78F2X_ExDevInfoType*  exDevInfoPtr;
    const Spi_70_RL78F2X_HwUnitConfType* hwUnitConfPtr = NULL_PTR;
    uint8_least hwUnitCnt;
   
    /* Interrupts are disabled during register acceses operations. */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
   
    /* Select SPI hardware unit */
    Spi_70_RL78F2X_SelectUnit( hwUnit );
   
    channelReg   = s_HwUnitRegInfo[hwUnit].ChannelReg;
    sdrReg       = s_HwUnitRegInfo[hwUnit].SDR;
    unitReg      = s_HwUnitRegInfo[hwUnit].UnitReg;
    unitRegShift = s_HwUnitRegInfo[hwUnit].UnitRegShift;
   
    val = unitReg->SE;
   
    /* For initial configuration before transmission, check if SE.SE bit is 0.  */
    if ( 0U == ( val & ( SPI_70_RL78F2X_SE_SE << unitRegShift ) ) ) {
        /* Get HW unit configuration */
        for ( hwUnitCnt = 0U ; hwUnitCnt < SPI_70_MAX_HW_UNIT_USING; hwUnitCnt++ ) {
            if ( s_HwUnitConfPtr[hwUnitCnt].SpiHwUnitCh == hwUnit ) {
                hwUnitConfPtr = &(s_HwUnitConfPtr[hwUnitCnt]);
                break;
            }
        }
       
        /* disable port for SFR setting */
        /* set port pin direction to input */
        Port_70_HW_SetPinDirection( hwUnitConfPtr->SpiPortClock, PORT_PIN_IN );
        Port_70_HW_SetPinDirection( hwUnitConfPtr->SpiPortOut, PORT_PIN_IN );
       
        exDevInfoPtr = &(s_ExDevInfo[devId]);
       
        /* set SPS register */
        tmp = unitReg->SPS;
        tmp |= ( ( exDevInfoPtr->valPRS & SPI_70_RL78F2X_SPS_PRS )
            << ( unitRegShift * SPI_70_RL78F2X_SPS_PRS_SIZE ) );
        unitReg->SPS = tmp;
       
        /* set SDR register */
        *sdrReg = exDevInfoPtr->valSDR;
       
        /* set SCR register */
        tmp = channelReg->SCR;
       
        /* set SCR.CKP bit */
        if ( SPI_70_IDLE_HIGH != shiftClockIdleLevel ) {
            /* shift clock idle level = LOW : CKPmn:1 */
            tmp |= ( SPI_70_RL78F2X_SCR_CKP );
        }
        /* set SCR.DAP bit */
        if ( SPI_70_EDGE_LEADING != dataShiftEdge ) {
            /* when data shift edge = TRAILING : DAPmn:1 */
            tmp |= ( SPI_70_RL78F2X_SCR_DAP );
        }
       
        /* set SCR.DIR bit */
        if ( SPI_70_START_LSB == transferStart ) {
            /* SCR.DIRmn:1:select start from LSB */
            tmp |= ( SPI_70_RL78F2X_SCR_DIR );
        } else {
            tmp &= ~( SPI_70_RL78F2X_SCR_DIR );
        }
       
        /* set SCR.DLS bit */
        tmp |= (uint16)( SPI_70_RL78F2X_SCR_DLS & ( dataWidth - 1U ) ); /* dls = bit width - 1 */
       
        channelReg->SCR = tmp;
       
        /* set SIR register */
        /* set SIR.OVCT bit */
        channelReg->SIR |= ( SPI_70_RL78F2X_SIR_OVCT );
       
        /* set SO register */
        if ( STD_LOW == shiftClockIdleLevel ) {
            /* Set CKO bit to 0 */
            unitReg->SO &= ( ~( SPI_70_RL78F2X_SO_CKO << unitRegShift ) );
        } else {
            /* Set CKO bit to 1 */
            unitReg->SO |= ( SPI_70_RL78F2X_SO_CKO << unitRegShift );
        }
       
        /* set SOE register */
        unitReg->SOE |= ( SPI_70_RL78F2X_SOE_SOE << unitRegShift );
       
        /* enable port after SFR setting */
        /* set port pin direction to output */
        Port_70_HW_SetPinDirection( hwUnitConfPtr->SpiPortClock, PORT_PIN_OUT );
        Port_70_HW_SetPinDirection( hwUnitConfPtr->SpiPortOut, PORT_PIN_OUT );
       
        /* set SS register */
        unitReg->SS |= ( SPI_70_RL78F2X_SS_SS << unitRegShift );
       
        retVal = E_OK;
    } else {
       
        /* If SE.SE bit is 1, set E_NOT_OK to retVal. */
        retVal = E_NOT_OK;
    }
   
    /* Enable interrupt. */
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
   
    return retVal;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_transmitChannel                                          */
/* Param       : (in) hwInfoPtr: pointer to HW information.                   */
/*             : (in) txData: transmit data.                                  */
/*             : (in) len: tx data length.                                    */
/* Return      : Std_ReturnType:                                              */
/*                     E_OK:     command has been accepted.                   */
/*                     E_NOT_OK: command has not been accepted.               */
/* Contents    : Transmit a channel                                           */
/* Author      : k.sawada h.shishido s.nitao                                  */
/* Note        : -                                                            */
/******************************************************************************/
Std_ReturnType Spi_70_RL78F2X_TransmitChannel( Spi_HWUnitType hwUnit,
                                               const uint8* txData,
                                               uint8 len )
{
    volatile Spi_70_RL78F2X_SDRType* sdrReg;
    uint16 ssrReg;
    uint16 tmpTxData;
   
    Std_ReturnType rtn = E_NOT_OK;
   
    /* Interrupts are disabled during register acceses operations. */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
   
    /* Select SPI hardware unit */
    Spi_70_RL78F2X_SelectUnit( hwUnit );
   
    /* Get register address */
    ssrReg = s_HwUnitRegInfo[hwUnit].ChannelReg->SSR;
    sdrReg = s_HwUnitRegInfo[hwUnit].SDR;
   
    /* Check SSR register */
    /* TSF bit, BFF bit and OVF bit is 0 */
    if ( 0U == ( ssrReg & ( SPI_70_RL78F2X_SSR_TSF |
                            SPI_70_RL78F2X_SSR_BFF |
                            SPI_70_RL78F2X_SSR_OVF ) ) ) {
        /* TX data 1Byte or 2Byte */
        if ( 1U >= len ) {
            tmpTxData = (uint16)txData[0];
        } else {
            /* RL78 is little endian */
            tmpTxData  = (uint16)txData[0];
            tmpTxData |= ( (uint16)txData[1] << 8U );
        }
       
        /* Set TX buffer */
        *sdrReg = tmpTxData;
       
        /* Enable interrupt. */
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
       
        /* Check that the TSF bit goes up */
        rtn = spi_checkTransmitStart( hwUnit );
    } else {
        /* Enable interrupt. */
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
    }
   
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   :                                                              */
/* Name        : Spi_70_RL78F2X_PutChipSelect                                 */
/* Param       : (in) csId: ID of CS                                          */
/*             : (in) flgAssert : TRUE:assert FALSE:negate                    */
/*             : (in) csPolarity: Active polarity of CS                       */
/*             : (in) calloutPtr: pointer to callout function                 */
/*             : (in) time      : callout function parameter                  */
/*             : (in) timing    : select Clk2Cs or Cs2Clk or Cs2Cs            */
/* Return      : void                                                         */
/* Contents    : Output chip select signal for job.                           */
/* Author      : k.sawada h.shishido s.nitao                                  */
/* Note        : no check for parameters.                                     */
/******************************************************************************/
void Spi_70_RL78F2X_PutChipSelect( uint8 csId, bool_t flgAssert, Spi_70_PolarityType csPolarity,
                                    void ( * const calloutPtr)( uint32 timeParam ),
                                    uint32 timeParam, uint8 timing )
{
    uint16_least csCnt;
    const Spi_70_HW_CsConfType* csCfgPtr = NULL_PTR;
    uint8   lvlValue;  /* output level */
   
    /* Get chip select config */
    for ( csCnt = 0U; csCnt < SPI_70_NUM_OF_CS_CONF; csCnt++ ) {
        if ( csId == s_CsConfPtr[csCnt].SpiCsIdentifier ) {
            csCfgPtr = &(s_CsConfPtr[csCnt]);
            break;
        }
    }
   
    if ( TRUE == flgAssert ) {
        if ( SPI_70_POLARITY_HIGH == csPolarity ) {
            lvlValue = TRUE;
        } else {
            lvlValue = FALSE;
        }
       
        spi_hwPutChipSelect( lvlValue, csCfgPtr->SpiCsPort, csCfgPtr->SpiCsBitPos );
       
        if ( ( SPI_70_CLK2CS == timing ) && ( NULL_PTR != calloutPtr ) ) {
            /* call callout function */
            calloutPtr( timeParam );
        }
    } else {
        if ( SPI_70_POLARITY_HIGH == csPolarity ) {
            lvlValue = FALSE;
        } else {
            lvlValue = TRUE;
        }
        if ( ( SPI_70_CS2CLK == timing ) && ( NULL_PTR != calloutPtr ) ) {
            /* call callout function */
            calloutPtr( timeParam );
        }
       
        spi_hwPutChipSelect( lvlValue, csCfgPtr->SpiCsPort, csCfgPtr->SpiCsBitPos );
       
        if ( ( SPI_70_CS2CS == timing ) && ( NULL_PTR != calloutPtr ) ) {
            /* call callout function */
            calloutPtr( timeParam );
        }
    }
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_RL78F2X_GetHWErrorStatus                              */
/* Param       : (in) hwUnit: The ID of the HW SPI Hardware                   */
/*                              microcontroller peripheral.                   */
/* Return      : bool_t:                                                      */
/*                  TRUE  : error happens in HW unit.                         */
/*                  FALSE : no error happens in HW unit.                      */
/* Contents    : Get specified Hardware error status.                         */
/* Author      : k.sawada h.shishido s.nitao                                  */
/* Note        : --                                                           */
/******************************************************************************/
bool_t Spi_70_RL78F2X_GetHWErrorStatus( Spi_HWUnitType hwUnit )
{
    bool_t rtn;
    uint16 val;
    volatile Spi_70_RL78F2X_ChannelRegType* channelReg;
 
    /* Interrupts are disabled during register acceses operations. */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
   
    /* Select SPI hardware unit */
    Spi_70_RL78F2X_SelectUnit( hwUnit );
   
    channelReg = s_HwUnitRegInfo[hwUnit].ChannelReg;
   
    val = channelReg->SSR;
   
    /* Clear error flag */
    channelReg->SIR |= ( SPI_70_RL78F2X_SIR_OVCT );
   
    /* Enable interrupt. */
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
   
    /* HW Error Checking */
    if( 0U != ( val & SPI_70_RL78F2X_SSR_OVF ) ) {
        /* HW error occurred */
        rtn = TRUE;
    } else {
        /* No HW error occurred */
        rtn = FALSE;
    }
   
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : -                                                            */
/* Name        : Spi_70_RL78F2X_ReceiveChannel                                */
/* Param       : (in) hwUnit: The ID of the HW SPI Hardware                   */
/*                              microcontroller peripheral.                   */
/*             : (in) rxData: Receive Data.                                   */
/*             : (in) len: RX data length.                                    */
/* Return      : void.                                                        */
/* Contents    : get receive data.                                            */
/* Author      : k.sawada h.shishido s.nitao                                  */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Spi_70_RL78F2X_ReceiveChannel( Spi_HWUnitType hwUnit, uint8* rxData, uint8* len )
{
    const volatile Spi_70_RL78F2X_SDRType* sdrReg;
    uint16 ssrReg;
    uint16 dlsBit;
    uint8 calculatedLen;
    Std_ReturnType rtn = E_NOT_OK;
   
    /* Interrupts are disabled during register acceses operations. */
    /* The ssrReg accessing needs exclusive processing */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
   
    /* Select SPI hardware unit */
    Spi_70_RL78F2X_SelectUnit( hwUnit );
   
    /* Get register address */
    ssrReg = s_HwUnitRegInfo[hwUnit].ChannelReg->SSR;
    sdrReg = s_HwUnitRegInfo[hwUnit].SDR;
   
    /* Enable interrupt. */
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
   
    /* Check OVF bit */
    /* OVF bit is 0  */
    if ( 0U == ( ssrReg & SPI_70_RL78F2X_SSR_OVF ) ) {
        /* RX data exists */
        /* TSF bit is 0 and BFF bit is 1 */
        if ( ( 0U == ( ssrReg & SPI_70_RL78F2X_SSR_TSF ) )
        && ( ( 0U != ( ssrReg & SPI_70_RL78F2X_SSR_BFF ) ) ) ) {
            /* Get DLS bit */
            dlsBit  = ( s_HwUnitRegInfo[hwUnit].ChannelReg->SCR );
            dlsBit &= SPI_70_RL78F2X_SCR_DLS;
           
            /* Calculate length from DLS bit */
            calculatedLen = (uint8)(( dlsBit / 8U ) + 1U);
           
            /* RX data 1Byte or 2Byte */
            /* The sdrReg accessing doesn't needs exclusive processing */
            if ( 1U >= calculatedLen ) {
                /* Get from RX buffer */
                rxData[0] = (uint8)*sdrReg;
            } else {
                /* Get from RX buffer */
                rxData[0] = (uint8)*sdrReg;
                rxData[1] = (uint8)( *sdrReg >> 8U );
            }
           
            /* Return RX data length */
            *len = calculatedLen;
            rtn = E_OK;
           
        /* HW unit is transmitting */
        /* TSF bit is 1            */
        } else if ( 0U != ( ssrReg & SPI_70_RL78F2X_SSR_TSF ) ) {
            *len = 0U; /* No data received */
            rtn = E_OK;
           
        } else {
            /* Do nothing      */
            /* return E_NOT_OK */
        }
    }
   
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_RL78F2X_StopChannel                                   */
/* Param       : (in) hwUnit: The ID of the HW SPI Hardware                   */
/*                              microcontroller peripheral.                   */
/*             : (in) shiftClockIdleLevel: SPI shift clock idle level.        */
/* Return      : void.                                                        */
/* Contents    : stop channel process.                                        */
/* Author      : k.sawada h.shishido s.nitao                                  */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_70_RL78F2X_StopChannel( Spi_HWUnitType hwUnit, uint8 shiftClockIdleLevel )
{
    volatile Spi_70_RL78F2X_UnitRegType* unitReg;
    uint8 unitRegShift;
   
    /* Interrupts are disabled during register acceses operations. */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
   
    /* Select SPI hardware unit */
    Spi_70_RL78F2X_SelectUnit( hwUnit );
   
    /* Get register address */
    unitReg      = s_HwUnitRegInfo[hwUnit].UnitReg;
    unitRegShift = s_HwUnitRegInfo[hwUnit].UnitRegShift;
   
    /* Stop HW unit */
    /* Set ST bit  to 1 */
    unitReg->ST  |= ( SPI_70_RL78F2X_ST_ST << unitRegShift );
    /* Set SOE bit to 0 */
    unitReg->SOE &= ~( SPI_70_RL78F2X_SOE_SOE << unitRegShift );
   
    /* Set serial output when idle (SO) */
    /* Set SO bit to 0 */
    unitReg->SO  &= ( ~( SPI_70_RL78F2X_SO_SO << unitRegShift ) );
   
    /* Set serial output when idle (SCK) */
    if ( STD_LOW == shiftClockIdleLevel ) {
        /* Set CKO bit to 0 */
        unitReg->SO &= ( ~( SPI_70_RL78F2X_SO_CKO << unitRegShift ) );
    } else {
        /* Set CKO bit to 1 */
        unitReg->SO |= ( SPI_70_RL78F2X_SO_CKO << unitRegShift );
    }
   
    /* Enable interrupt. */
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_RL78F2X_DisableInterrupts                             */
/* Param       : None                                                         */
/* Return      : void.                                                        */
/* Contents    : disable interrupt function                                   */
/* Author      : k.sawada h.shishido s.nitao                                  */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_70_RL78F2X_DisableInterrupts( void )
{
    const Spi_70_RL78F2X_HwUnitConfType* hwConfPtr;
    uint8_least hwUnitCnt;
    volatile Spi_70_RL78F2X_MKType* mkReg;
    uint8 mkShift;
   
    for ( hwUnitCnt = 0U ; hwUnitCnt < SPI_70_MAX_HW_UNIT_USING; hwUnitCnt++ ) {
        /* Get register information */
        hwConfPtr  = &(s_HwUnitConfPtr[hwUnitCnt]);
        mkReg      = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].MK;
        mkShift    = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].MKShift;
       
        /* Disable interrupt */
        *mkReg |= (uint8)( SPI_70_RL78F2X_MKx_CSIMKmn << mkShift );
    }
   
    return;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_RL78F2X_EnableInterrupts                              */
/* Param       : None                                                         */
/* Return      : void.                                                        */
/* Contents    : enable interrupt function                                    */
/* Author      : k.sawada h.shishido s.nitao                                  */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_70_RL78F2X_EnableInterrupts( void )
{
    const Spi_70_RL78F2X_HwUnitConfType* hwConfPtr;
    uint8_least hwUnitCnt;
    volatile Spi_70_RL78F2X_MKType* mkReg;
    uint8 mkShift;
   
    for ( hwUnitCnt = 0U ; hwUnitCnt < SPI_70_MAX_HW_UNIT_USING; hwUnitCnt++ ) {
        /* Get register information */
        hwConfPtr  = &(s_HwUnitConfPtr[hwUnitCnt]);
        mkReg      = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].MK;
        mkShift    = s_HwUnitRegInfo[hwConfPtr->SpiHwUnitCh].MKShift;
       
        /* Enable interrupt */
        *mkReg &= (uint8)(~( SPI_70_RL78F2X_MKx_CSIMKmn << mkShift ));
    }
   
    return;
}
 
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_RL78F2X_SelectUnit                                    */
/* Param       : (in) hwUnit: The ID of the HW SPI Hardware                   */
/*                              microcontroller peripheral.                   */
/* Return      : void.                                                        */
/* Contents    : select spi hardware unit.                                    */
/* Author      : h.tsunoda                                                    */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_70_RL78F2X_SelectUnit( Spi_HWUnitType hwUnit )
{
    volatile Spi_70_RL78F2X_UTSELType* utSel;
    uint8 utSelShift;
   
    /* Read Unit Select Register (UTSEL). */
    /* Get register address. */
    utSel      = s_HwUnitRegInfo[hwUnit].UTSEL;
    utSelShift = s_HwUnitRegInfo[hwUnit].UTSELShift;
   
    /* Change this register value with hwUnit. */
    if (( SPI_70_RL78F2X_CSIB0_0 == hwUnit ) ||
        ( SPI_70_RL78F2X_CSIB0_1 == hwUnit )) {
        *utSel &= ( uint8 )~(( uint8 )( SPI_70_RL78F2X_UTSEL_SAU1 << utSelShift ));
    } else if (( SPI_70_RL78F2X_CSIB1_0 == hwUnit ) ||
               ( SPI_70_RL78F2X_CSIB1_1 == hwUnit )) {
        *utSel |= ( uint8 )( SPI_70_RL78F2X_UTSEL_SAU1 << utSelShift );
    } else {
        /* Do nothing. */
    }
   
    return;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   :                                                              */
/* Name        : spi_checkTransmitStart                                       */
/* Param       :(in) hwUnit: The ID of the HW SPI Hardware                    */
/*                           microcontroller peripheral.                      */
/* Return      : Std_ReturnType:                                              */
/*                     E_OK:     Transmission start.                          */
/*                     E_NOT_OK: Transmission failure.                        */
/* Contents    : Check that the TSF bit goes up and transmission starts.      */
/* Author      : h.shishido                                                   */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType spi_checkTransmitStart( Spi_HWUnitType hwUnit )
{
    uint16 ssrReg;
    Std_ReturnType rtn = E_NOT_OK;
   
    /* Interrupts are disabled during register acceses operations. */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
   
    while ( TRUE ) {
        /* Get register value */
        ssrReg = s_HwUnitRegInfo[hwUnit].ChannelReg->SSR;
        /* Check transfer is processing */
        if ( 0U != ( ssrReg & SPI_70_RL78F2X_SSR_TSF ) ) {
            rtn = E_OK;
            break;
        }
        /* Check HW error happens  */
        if ( 0U != ( ssrReg & SPI_70_RL78F2X_SSR_OVF ) ) {
            rtn = E_NOT_OK;
            break;
        }
    }
   
    /* Enable interrupt. */
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
   
    return rtn;
}
 
#define SPI_STOP_SEC_CODE_LOCAL
#include "Spi_MemMap.h"
 
/**************** End Of File Spi_70_RL78F2X.c ********************************/