/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Port_70_RL78F2X_Types.h                                      */
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

#ifndef PORT_70_RL78F2X_TYPES_H_
#define PORT_70_RL78F2X_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Mcl_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PORT_70_VENDOR_ID_RL78F2X_TYPES_H                   ( 70U )
#define PORT_70_MODULE_ID_RL78F2X_TYPES_H                   ( 124U )

#define PORT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H    ( 22U )
#define PORT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H    ( 11U )
#define PORT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H ( 0U )

#define PORT_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H            ( 1U )
#define PORT_70_SW_MINOR_VERSION_RL78F2X_TYPES_H            ( 0U )
#define PORT_70_SW_PATCH_VERSION_RL78F2X_TYPES_H            ( 0U )

/*----------------------------------------------------------------------------*/
/* version check                                                              */
/*----------------------------------------------------------------------------*/
/* Mcl_70_RL78F2X.h version check start */

#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H \
        != MCL_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H \
        != MCL_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) \
    )
    #error "AUTOSAR Version Numbers of Port_70_RL78F2X_Types.h and Mcl_70_RL78F2X.h are different"
#endif

/* Mcl_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef enum
{
    PORT_PIN_DIGITAL        = 0x00U,    /* Port Pin direction set as input    */
    PORT_PIN_ANALOG         = 0x01U,    /* Port Pin direction set as output   */
    PORT_PIN_MODE_CTRL_NONE = 0x00U
} Port_70_PinModeControlType;

typedef enum
{
    PORT_PIN_DRIVEN_NOMAL     = 0U,
    PORT_PIN_DRIVEN_OPENDRAIN = 1U,
    PORT_PIN_DRIVEN_NONE      = 0U
} Port_70_PinDrivenModeType;

typedef enum
{
    PORT_PIN_PULLUP_OFF       = 0U,
    PORT_PIN_PULLUP_ON        = 1U,
    PORT_PIN_PULLUP_NONE      = 0U
} Port_70_PinPullUpType;

typedef enum
{
    PORT_PIN_INPUT_THRESHOLD_NORMAL = 0U,
    PORT_PIN_INPUT_THRESHOLD_05VDD  = 1U,
    PORT_PIN_INPUT_THRESHOLD_NONE   = 0U
} Port_70_PinInputThresholdType;

typedef enum
{
    PORT_PIN_INPUT_MODE_NORMAL      = 0U,
    PORT_PIN_INPUT_MODE_TTL         = 1U,
    PORT_PIN_INPUT_MODE_NONE        = 0U
} Port_70_PinInputModeType;

typedef enum
{
    PORT_PIN_INPUT_TYPE_SCHMITT1    = 0U,
    PORT_PIN_INPUT_TYPE_SCHMITT2    = 1U,
    PORT_PIN_INPUT_TYPE_TTL         = 2U,
    PORT_PIN_INPUT_TYPE_NONE        = 0U
} Port_70_PinInputType;

typedef enum
{
    PORT_PIN_SLEW_NOMAL             = 0U,
    PORT_PIN_SLEW_SLOW              = 1U,
    PORT_PIN_SLEW_NONE              = 0U
} Port_70_PinSlewRateType;

typedef enum {
    PORT_70_PIOR00_BIT = 0U,
    PORT_70_PIOR01_BIT = 1U,
    PORT_70_PIOR02_BIT = 2U,
    PORT_70_PIOR03_BIT = 3U,
    PORT_70_PIOR04_BIT = 4U,
    PORT_70_PIOR05_BIT = 5U,
    PORT_70_PIOR06_BIT = 6U,
    PORT_70_PIOR07_BIT = 7U,
    PORT_70_PIOR10_BIT = 8U,
    PORT_70_PIOR11_BIT = 9U,
    PORT_70_PIOR12_BIT = 10U,
    PORT_70_PIOR13_BIT = 11U,
    PORT_70_PIOR14_BIT = 12U,
    PORT_70_PIOR15_BIT = 13U,
    PORT_70_PIOR16_BIT = 14U,
    PORT_70_PIOR17_BIT = 15U,
    PORT_70_PIOR20_BIT = 16U,
    PORT_70_PIOR21_BIT = 17U,
    PORT_70_PIOR22_BIT = 18U,
    PORT_70_PIOR23_BIT = 19U,
    PORT_70_PIOR24_BIT = 20U,
    PORT_70_PIOR25_BIT = 21U,
    PORT_70_PIOR26_BIT = 22U,
    PORT_70_PIOR27_BIT = 23U,
    PORT_70_PIOR30_BIT = 24U,
    PORT_70_PIOR31_BIT = 25U,
    PORT_70_PIOR32_BIT = 26U,
    PORT_70_PIOR33_BIT = 27U,
    PORT_70_PIOR34_BIT = 28U,
    PORT_70_PIOR35_BIT = 29U,
    PORT_70_PIOR36_BIT = 30U,
    PORT_70_PIOR37_BIT = 31U,
    PORT_70_PIOR40_BIT = 32U,
    PORT_70_PIOR41_BIT = 33U,
    PORT_70_PIOR42_BIT = 34U,
    PORT_70_PIOR43_BIT = 35U,
    PORT_70_PIOR44_BIT = 36U,
    PORT_70_PIOR45_BIT = 37U,
    PORT_70_PIOR46_BIT = 38U,
    PORT_70_PIOR47_BIT = 39U,
    PORT_70_PIOR50_BIT = 40U,
    PORT_70_PIOR51_BIT = 41U,
    PORT_70_PIOR52_BIT = 42U,
    PORT_70_PIOR53_BIT = 43U,
    PORT_70_PIOR54_BIT = 44U,
    PORT_70_PIOR55_BIT = 45U,
    PORT_70_PIOR56_BIT = 46U,
    PORT_70_PIOR57_BIT = 47U,
    PORT_70_PIOR60_BIT = 48U,
    PORT_70_PIOR61_BIT = 49U,
    PORT_70_PIOR62_BIT = 50U,
    PORT_70_PIOR63_BIT = 51U,
    PORT_70_PIOR64_BIT = 52U,
    PORT_70_PIOR65_BIT = 53U,
    PORT_70_PIOR66_BIT = 54U,
    PORT_70_PIOR67_BIT = 55U,
    PORT_70_PIOR70_BIT = 56U,
    PORT_70_PIOR71_BIT = 57U,
    PORT_70_PIOR72_BIT = 58U,
    PORT_70_PIOR73_BIT = 59U,
    PORT_70_PIOR74_BIT = 60U,
    PORT_70_PIOR75_BIT = 61U,
    PORT_70_PIOR76_BIT = 62U,
    PORT_70_PIOR77_BIT = 63U,
    PORT_70_PIOR80_BIT = 64U,
    PORT_70_PIOR81_BIT = 65U,
    PORT_70_PIOR82_BIT = 66U,
    PORT_70_PIOR83_BIT = 67U,
    PORT_70_PIOR84_BIT = 68U,
    PORT_70_PIOR85_BIT = 69U,
    PORT_70_PIOR86_BIT = 70U,
    PORT_70_PIOR87_BIT = 71U,
    PORT_70_PIOR_BIT_NONE = 0xFFU
} Port_70_PinPiorBitType;

typedef enum
{
    PORT_SET_0 = 0U,
    PORT_SET_1 = 1U
} Port_70_PinRegSetType;

typedef enum
{
    PORT_70_STATE_UNINITIALIZED = 0U,
    PORT_70_STATE_INITIALIZED   = 1U
} Port_70_ModuleStateType;

typedef struct{
    uint16                PortRegAddr;                         /* Port register address */
    Port_70_PinRegSetType PortRegSetVal;                       /* Port register set value */
} Port_70_RL78F2X_PinModeType;

typedef struct{
    uint8 PortRegNum;                                          /* The number of register set */
    const Port_70_RL78F2X_PinModeType *QL_70_NEAR *PortPinMode;
} Port_70_RL78F2X_PinSetConfType;

typedef struct{
    uint16                PortPinPiorAddr;                     /* PIORx address */
    uint8                 PortPinPiorBit;                      /* Shift bit */
    Port_70_PinRegSetType PortPinPiorSetVal;                   /* PIORx set value */
} Port_70_RL78F2X_PinPiorSetType;

typedef struct{
    uint16                                PortPinChangeMode;   /* Port pin changeable mode */
    const Port_70_RL78F2X_PinSetConfType* Port_70_PinSetConfPtr;
    const Port_70_RL78F2X_PinPiorSetType* Port_70_PinPiorSetPtr;
} Port_70_RL78F2X_PinChangeModeType;

typedef struct{
    uint8   PortChangeModeNum;                                 /* The number of change mode */
    const   Port_70_RL78F2X_PinChangeModeType **PortPinChange;
} Port_70_RL78F2X_PinChangeType;



/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

#endif /* #ifndef PORT_70_RL78F2X_TYPES_H_ */
 
/* EOF Port_70_RL78F2X_TYpes.h *****************************************************/
