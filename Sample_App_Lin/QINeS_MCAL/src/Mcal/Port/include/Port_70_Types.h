/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Port_70_Types.h                                              */
/* Version     : v1.00.00                                                     */
/* Contents    : PORT Module type definition header                           */
/*               The PORT is a basic software module at the service layer of  */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of PORT Driver                                               */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef PORT_70_TYPES_H_
#define PORT_70_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"    /* [SWS_Port_00130] */
#include "Port_Cfg.h"     /* [SWS_Port_00130] */
#include "Port_70_HW_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PORT_INSTANCE_ID                              ( 0U )
#define PORT_70_VENDOR_ID_TYPES_H                     ( 70U )
#define PORT_70_MODULE_ID_TYPES_H                     ( 124U )

#define PORT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H      ( 22U )
#define PORT_70_AR_RELEASE_MINOR_VERSION_TYPES_H      ( 11U )
#define PORT_70_AR_RELEASE_REVISION_VERSION_TYPES_H   ( 0U )

#define PORT_70_SW_MAJOR_VERSION_TYPES_H              ( 1U )
#define PORT_70_SW_MINOR_VERSION_TYPES_H              ( 0U )
#define PORT_70_SW_PATCH_VERSION_TYPES_H              ( 0U )

/*----------------------------------------------------------------------------*/
/* version check                                                              */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */
 
#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Port_70_Types.h and Std_Types.h are different"
#endif

/* Std_Types.h version check end */

/* Port_Cfg.h version check start */

#if ( PORT_70_VENDOR_ID_TYPES_H != PORT_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Port_70_Types.h and Port_Cfg.h are different"
#endif

#if ( PORT_70_MODULE_ID_TYPES_H != PORT_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Port_70_Types.h and Port_Cfg.h are different"
#endif

#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != PORT_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != PORT_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( PORT_70_AR_RELEASE_REVISION_VERSION_TYPES_H != PORT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Port_70_Types.h and Port_Cfg.h are different"
#endif

#if ( ( PORT_70_SW_MAJOR_VERSION_TYPES_H != PORT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( PORT_70_SW_MINOR_VERSION_TYPES_H != PORT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( PORT_70_SW_PATCH_VERSION_TYPES_H != PORT_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Port_70_Types.h and Port_Cfg.h are different"
#endif

/* Port_Cfg.h version check end */


/* Port_70_HW_Types.h version check start */

#if ( PORT_70_VENDOR_ID_TYPES_H != PORT_70_VENDOR_ID_HW_TYPES_H )
    #error "VENDOR ID for Port_70_Types.h and Port_70_HW_Types.h are different"
#endif

#if ( PORT_70_MODULE_ID_TYPES_H != PORT_70_MODULE_ID_HW_TYPES_H )
    #error "MODULE ID for Port_70_Types.h and Port_70_HW_Types.h are different"
#endif

#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H \
      != PORT_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_TYPES_H \
        != PORT_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H ) || \
      ( PORT_70_AR_RELEASE_REVISION_VERSION_TYPES_H \
        != PORT_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Port_70_Types.h and Port_70_HW_Types.h are different"
#endif

#if ( ( PORT_70_SW_MAJOR_VERSION_TYPES_H != PORT_70_SW_MAJOR_VERSION_HW_TYPES_H ) || \
      ( PORT_70_SW_MINOR_VERSION_TYPES_H != PORT_70_SW_MINOR_VERSION_HW_TYPES_H ) || \
      ( PORT_70_SW_PATCH_VERSION_TYPES_H != PORT_70_SW_PATCH_VERSION_HW_TYPES_H ) \
    )
    #error "Software Version Numbers of Port_70_Types.h and Port_70_HW_Types.h are different"
#endif

/* Port_70_HW_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macro                                                                      */
/*----------------------------------------------------------------------------*/
/* Port name */
#define PORT_70_00 ( (uint8 )0U )
#define PORT_70_01 ( (uint8 )1U )
#define PORT_70_02 ( (uint8 )2U )
#define PORT_70_03 ( (uint8 )3U )
#define PORT_70_04 ( (uint8 )4U )
#define PORT_70_05 ( (uint8 )5U )
#define PORT_70_06 ( (uint8 )6U )
#define PORT_70_07 ( (uint8 )7U )
#define PORT_70_08 ( (uint8 )8U )
#define PORT_70_09 ( (uint8 )9U )
#define PORT_70_10 ( (uint8 )10U )
#define PORT_70_11 ( (uint8 )11U )
#define PORT_70_12 ( (uint8 )12U )
#define PORT_70_13 ( (uint8 )13U )
#define PORT_70_14 ( (uint8 )14U )
#define PORT_70_15 ( (uint8 )15U )

/* Port Pin container short name */
#define PORT_70_P00  ( (uint16 ) 0U )
#define PORT_70_P01  ( (uint16 ) 1U )
#define PORT_70_P02  ( (uint16 ) 2U )
#define PORT_70_P03  ( (uint16 ) 3U )
#define PORT_70_P04  ( (uint16 ) 4U )
#define PORT_70_P05  ( (uint16 ) 5U )
#define PORT_70_P06  ( (uint16 ) 6U )
#define PORT_70_P07  ( (uint16 ) 7U )
#define PORT_70_P10  ( (uint16 ) 8U )
#define PORT_70_P11  ( (uint16 ) 9U )
#define PORT_70_P12  ( (uint16 ) 10U )
#define PORT_70_P13  ( (uint16 ) 11U )
#define PORT_70_P14  ( (uint16 ) 12U )
#define PORT_70_P15  ( (uint16 ) 13U )
#define PORT_70_P16  ( (uint16 ) 14U )
#define PORT_70_P17  ( (uint16 ) 15U )
#define PORT_70_P20  ( (uint16 ) 16U )
#define PORT_70_P21  ( (uint16 ) 17U )
#define PORT_70_P22  ( (uint16 ) 18U )
#define PORT_70_P23  ( (uint16 ) 19U )
#define PORT_70_P24  ( (uint16 ) 20U )
#define PORT_70_P25  ( (uint16 ) 21U )
#define PORT_70_P26  ( (uint16 ) 22U )
#define PORT_70_P27  ( (uint16 ) 23U )
#define PORT_70_P30  ( (uint16 ) 24U )
#define PORT_70_P31  ( (uint16 ) 25U )
#define PORT_70_P32  ( (uint16 ) 26U )
#define PORT_70_P33  ( (uint16 ) 27U )
#define PORT_70_P34  ( (uint16 ) 28U )
#define PORT_70_P35  ( (uint16 ) 29U )
#define PORT_70_P36  ( (uint16 ) 30U )
#define PORT_70_P37  ( (uint16 ) 31U )
#define PORT_70_P40  ( (uint16 ) 32U )
#define PORT_70_P41  ( (uint16 ) 33U )
#define PORT_70_P42  ( (uint16 ) 34U )
#define PORT_70_P43  ( (uint16 ) 35U )
#define PORT_70_P44  ( (uint16 ) 36U )
#define PORT_70_P45  ( (uint16 ) 37U )
#define PORT_70_P46  ( (uint16 ) 38U )
#define PORT_70_P47  ( (uint16 ) 39U )
#define PORT_70_P50  ( (uint16 ) 40U )
#define PORT_70_P51  ( (uint16 ) 41U )
#define PORT_70_P52  ( (uint16 ) 42U )
#define PORT_70_P53  ( (uint16 ) 43U )
#define PORT_70_P54  ( (uint16 ) 44U )
#define PORT_70_P55  ( (uint16 ) 45U )
#define PORT_70_P56  ( (uint16 ) 46U )
#define PORT_70_P57  ( (uint16 ) 47U )
#define PORT_70_P60  ( (uint16 ) 48U )
#define PORT_70_P61  ( (uint16 ) 49U )
#define PORT_70_P62  ( (uint16 ) 50U )
#define PORT_70_P63  ( (uint16 ) 51U )
#define PORT_70_P64  ( (uint16 ) 52U )
#define PORT_70_P65  ( (uint16 ) 53U )
#define PORT_70_P66  ( (uint16 ) 54U )
#define PORT_70_P67  ( (uint16 ) 55U )
#define PORT_70_P70  ( (uint16 ) 56U )
#define PORT_70_P71  ( (uint16 ) 57U )
#define PORT_70_P72  ( (uint16 ) 58U )
#define PORT_70_P73  ( (uint16 ) 59U )
#define PORT_70_P74  ( (uint16 ) 60U )
#define PORT_70_P75  ( (uint16 ) 61U )
#define PORT_70_P76  ( (uint16 ) 62U )
#define PORT_70_P77  ( (uint16 ) 63U )
#define PORT_70_P80  ( (uint16 ) 64U )
#define PORT_70_P81  ( (uint16 ) 65U )
#define PORT_70_P82  ( (uint16 ) 66U )
#define PORT_70_P83  ( (uint16 ) 67U )
#define PORT_70_P84  ( (uint16 ) 68U )
#define PORT_70_P85  ( (uint16 ) 69U )
#define PORT_70_P86  ( (uint16 ) 70U )
#define PORT_70_P87  ( (uint16 ) 71U )
#define PORT_70_P90  ( (uint16 ) 72U )
#define PORT_70_P91  ( (uint16 ) 73U )
#define PORT_70_P92  ( (uint16 ) 74U )
#define PORT_70_P93  ( (uint16 ) 75U )
#define PORT_70_P94  ( (uint16 ) 76U )
#define PORT_70_P95  ( (uint16 ) 77U )
#define PORT_70_P96  ( (uint16 ) 78U )
#define PORT_70_P97  ( (uint16 ) 79U )
#define PORT_70_P100 ( (uint16 ) 80U )
#define PORT_70_P101 ( (uint16 ) 81U )
#define PORT_70_P102 ( (uint16 ) 82U )
#define PORT_70_P103 ( (uint16 ) 83U )
#define PORT_70_P104 ( (uint16 ) 84U )
#define PORT_70_P105 ( (uint16 ) 85U )
#define PORT_70_P106 ( (uint16 ) 86U )
#define PORT_70_P107 ( (uint16 ) 87U )
#define PORT_70_P110 ( (uint16 ) 88U )
#define PORT_70_P111 ( (uint16 ) 89U )
#define PORT_70_P112 ( (uint16 ) 90U )
#define PORT_70_P113 ( (uint16 ) 91U )
#define PORT_70_P114 ( (uint16 ) 92U )
#define PORT_70_P115 ( (uint16 ) 93U )
#define PORT_70_P116 ( (uint16 ) 94U )
#define PORT_70_P117 ( (uint16 ) 95U )
#define PORT_70_P120 ( (uint16 ) 96U )
#define PORT_70_P121 ( (uint16 ) 97U )
#define PORT_70_P122 ( (uint16 ) 98U )
#define PORT_70_P123 ( (uint16 ) 99U )
#define PORT_70_P124 ( (uint16 ) 100U )
#define PORT_70_P125 ( (uint16 ) 101U )
#define PORT_70_P126 ( (uint16 ) 102U )
#define PORT_70_P127 ( (uint16 ) 103U )
#define PORT_70_P130 ( (uint16 ) 104U )
#define PORT_70_P131 ( (uint16 ) 105U )
#define PORT_70_P132 ( (uint16 ) 106U )
#define PORT_70_P133 ( (uint16 ) 107U )
#define PORT_70_P134 ( (uint16 ) 108U )
#define PORT_70_P135 ( (uint16 ) 109U )
#define PORT_70_P136 ( (uint16 ) 110U )
#define PORT_70_P137 ( (uint16 ) 111U )
#define PORT_70_P140 ( (uint16 ) 112U )
#define PORT_70_P141 ( (uint16 ) 113U )
#define PORT_70_P142 ( (uint16 ) 114U )
#define PORT_70_P143 ( (uint16 ) 115U )
#define PORT_70_P144 ( (uint16 ) 116U )
#define PORT_70_P145 ( (uint16 ) 117U )
#define PORT_70_P146 ( (uint16 ) 118U )
#define PORT_70_P147 ( (uint16 ) 119U )
#define PORT_70_P150 ( (uint16 ) 120U )
#define PORT_70_P151 ( (uint16 ) 121U )
#define PORT_70_P152 ( (uint16 ) 122U )
#define PORT_70_P153 ( (uint16 ) 123U )
#define PORT_70_P154 ( (uint16 ) 124U )
#define PORT_70_P155 ( (uint16 ) 125U )
#define PORT_70_P156 ( (uint16 ) 126U )
#define PORT_70_P157 ( (uint16 ) 127U )

/* Port pin mode */
#define PORT_PIN_MODE_NONE       ( 0x0000U )  /* Port Pin non used           */
#define PORT_PIN_MODE_ADC        ( 0x0001U )  /* Port Pin used by ADC        */
#define PORT_PIN_MODE_CAN        ( 0x0002U )  /* Port Pin used by CAN        */
#define PORT_PIN_MODE_DIO        ( 0x0004U )  /* Port Pin configured for DIO.*/
                                              /* It shall be used under      */
                                              /* control of the DIO driver.  */
#define PORT_PIN_MODE_DIO_GPT    ( 0x0008U )  /* Port Pin configured for DIO.*/
                                              /* It shall be used under      */
                                              /* control of the general      */
                                              /* purpose timer driver.       */
#define PORT_PIN_MODE_DIO_WDG    ( 0x0010U )  /* Port Pin configured for DIO.*/
                                              /* It shall be used under      */
                                              /* control of the watchdog     */
                                              /* driver.                     */
#define PORT_PIN_MODE_FLEXRAY    ( 0x0020U )  /* Port Pin used for FlexRay   */
#define PORT_PIN_MODE_ICU        ( 0x0040U )  /* Port Pin used by ICU        */
#define PORT_PIN_MODE_LIN        ( 0x0080U )  /* Port Pin used for LIN       */
#define PORT_PIN_MODE_MEM        ( 0x0100U )  /* Port Pin used for external  */
                                              /* memory under control of a   */
                                              /* memory driver.              */
#define PORT_PIN_MODE_PWM        ( 0x0200U )  /* Port Pin used by PWM        */
#define PORT_PIN_MODE_SPI        ( 0x0400U )  /* Port Pin used by SPI        */
#define PORT_70_PIN_MODE_DAC     ( 0x0800U )  /* Port Pin used by DAC        */
#define PORT_70_PIN_MODE_CMP     ( 0x1000U )  /* Port Pin used by Comparator */
#define PORT_70_PIN_MODE_SNOOZE  ( 0x2000U )  /* Port Pin used by SNOOZE OUT */
#define PORT_70_PIN_MODE_INTP    ( 0x0004U )  /* Port Pin used by            */
                                              /* Interruption Input          */
#define PORT_70_PIN_MODE_DIO_SPI ( 0x0004U )  /* Port Pin configured for DIO.*/
                                              /* It shall be used under      */
                                              /* control of the SPI driver.  */

/*----------------------------------------------------------------------------*/
/* type definitions (non-AUTOSAR)                                             */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions (AUTOSAR)                                                 */
/*----------------------------------------------------------------------------*/
typedef uint16 Port_PinType; /* number of port pins ->PortNumberOfPortPins*/  /* [SWS_Port_00229] */
typedef uint16 Port_PinModeType;  /* [SWS_Port_00231] */

typedef enum
{
    PORT_PIN_OUT            = 0x00U,    /* Port Pin direction set as output */
    PORT_PIN_IN             = 0x01U     /* Port Pin direction set as input  */
} Port_PinDirectionType;     /* SWS_Port_00230 */


typedef enum
{
    PORT_PIN_LEVEL_LOW      = 0x00U,    /* Port Pin Level Low */
    PORT_PIN_LEVEL_HIGH     = 0x01U     /* Port Pin Level High */
} Port_PinLevelValueType;

/* [ECUC_Port_00118] */
typedef struct {
    Port_PinType                             PortPinId;
    Port_PinDirectionType                    PortPinDirection;
    bool_t                                   PortPinDirectionChangeable;
    Port_PinModeType                         PortPinInitialMode;
    Port_PinLevelValueType                   PortPinLevelValue;
    bool_t                                   PortPinModeChangeable;
    Port_PinModeType                         PortPinMode;
    const Port_70_HW_PortPinType*            PortHWPortPinType;

} Port_PortPinType;          /* SWS_Port_00229 */

typedef struct{
    uint16                     PortNumberOfPortPins;
    const                      Port_PortPinType* PortPin;
} Port_ContainerType;

typedef struct{
    uint16                     PortNumOfPortContainer;
    const Port_ContainerType*  PortContainer;

} Port_ConfigSetType;

typedef struct{
    const Port_ConfigSetType*  PortConfigSet;
} Port_ConfigType;           /* SWS_Port_00228 */

#endif /* #ifndef PORT_70_TYPES_H_ */

/* EOF Port_70_Types.h *******************************************************/
