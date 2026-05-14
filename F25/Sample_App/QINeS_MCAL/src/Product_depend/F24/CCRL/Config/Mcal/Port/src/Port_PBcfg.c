/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Port_PBcfg.c                                                 */
/* Version     : v1.00.00                                                     */
/* Contents    : Port post build time configuration                           */
/* Author      : --                                                           */
/* Note        : (Index:0)                                                    */
/******************************************************************************/
/* Specification of PORT Driver                                               */
/* R22-11                                                                     */


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Port.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PORT_70_VENDOR_ID_PBCFG_C                      ( 70U )
#define PORT_70_MODULE_ID_PBCFG_C                      ( 124U )

#define PORT_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C       ( 22U )
#define PORT_70_AR_RELEASE_MINOR_VERSION_PBCFG_C       ( 11U )
#define PORT_70_AR_RELEASE_REVISION_VERSION_PBCFG_C    ( 0U )

#define PORT_70_SW_MAJOR_VERSION_PBCFG_C               ( 1U )
#define PORT_70_SW_MINOR_VERSION_PBCFG_C               ( 0U )
#define PORT_70_SW_PATCH_VERSION_PBCFG_C               ( 0U )

/*----------------------------------------------------------------------------*/
/* version check                                                              */
/*----------------------------------------------------------------------------*/
/* Port.h version check start */
#if ( PORT_70_VENDOR_ID_PBCFG_C != PORT_VENDOR_ID )
    #error "VENDOR ID for Port_PBcfg.c and Port.h is different"
#endif

#if ( PORT_70_MODULE_ID_PBCFG_C != PORT_MODULE_ID )
    #error "M
#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MAJOR_VERSION )  || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MINOR_VERSION )  || \
      ( PORT_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != PORT_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Port_PBcfg.c and Port.h are different"
#endif

#if ( ( PORT_70_SW_MAJOR_VERSION_PBCFG_C != PORT_SW_MAJOR_VERSION ) || \
      ( PORT_70_SW_MINOR_VERSION_PBCFG_C != PORT_SW_MINOR_VERSION ) || \
      ( PORT_70_SW_PATCH_VERSION_PBCFG_C != PORT_SW_PATCH_VERSION ) )
    #error "Software Version Numbers of Port_PBcfg.c and Port.h are different"
#endif
/* Port.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

static const Port_70_RL78F2X_PinModeType Port_70_PinRegSet[PORT_70_NUM_OF_REG_SET] = {
    /* Px register addresss */
    { PORT_70_RL78F2X_P_ADR, PORT_SET_0 },      /* index0  : Set Px register to 0 */
    { PORT_70_RL78F2X_P_ADR, PORT_SET_1 },      /* index1  : Set Px register to 1 */
    /* PITHLx register addresss */
    { PORT_70_RL78F2X_PITHL_ADR, PORT_SET_0 },  /* index2  : Set PITHLx register to 0 */
    { PORT_70_RL78F2X_PITHL_ADR, PORT_SET_1 },  /* index3  : Set PITHLx register to 1 */
    /* PUx register addresss */
    { PORT_70_RL78F2X_PU_ADR, PORT_SET_0 },     /* index4  : Set PUx register to 0 */
    { PORT_70_RL78F2X_PU_ADR, PORT_SET_1 },     /* index5  : Set PUx register to 1 */
    /* PIMx register addresss */
    { PORT_70_RL78F2X_PIM_ADR, PORT_SET_0 },    /* index6  : Set PIMx register to 0 */
    { PORT_70_RL78F2X_PIM_ADR, PORT_SET_1 },    /* index7  : Set PIMx register to 1 */
    /* POMx register addresss */
    { PORT_70_RL78F2X_POM_ADR, PORT_SET_0 },    /* index8 : Set POMx register to 0 */
    { PORT_70_RL78F2X_POM_ADR, PORT_SET_1 },    /* index9 : Set POMx register to 1 */
    /* PMCx register addresss */
    { PORT_70_RL78F2X_PMC_ADR, PORT_SET_0 },    /* index10 : Set PMCx register to 0 */
    { PORT_70_RL78F2X_PMC_ADR, PORT_SET_1 },    /* index11 : Set PMCx register to 1 */
    /* PMx register addresss */
    { PORT_70_RL78F2X_PM_ADR, PORT_SET_0 },     /* index12 : Set PMx register to 0 */
    { PORT_70_RL78F2X_PM_ADR, PORT_SET_1 }      /* index13 : Set PMx register to 1 */
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_VAR_INIT_GLOBAL_UNSPECIFIED
#include "Port_MemMap.h"

/* Set PMC register */
static const Port_70_RL78F2X_PinModeType *Port_70_RL78F2X_PinMode0[1U] = {
    &Port_70_PinRegSet[10]
};

/* Set PMC register */
static const Port_70_RL78F2X_PinModeType *Port_70_RL78F2X_PinMode1[1U] = {
    &Port_70_PinRegSet[11]
};

/* Set PMC register */
static const Port_70_RL78F2X_PinModeType *Port_70_RL78F2X_PinMode2[1U] = {
    &Port_70_PinRegSet[5]
};

#define PORT_STOP_SEC_VAR_INIT_GLOBAL_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

static const Port_70_RL78F2X_PinSetConfType Port_70_RL78F2X_PinModeConf[PORT_70_NUM_OF_CONFMODE] = {
    { /* Port_70_RL78F2X_PinModeConf[0] */
        1U,                         /* PortRegNum */
        Port_70_RL78F2X_PinMode0   /* PortPinMode */
    },
    { /* Port_70_RL78F2X_PinModeConf[1] */
        1U,                         /* PortRegNum */
        Port_70_RL78F2X_PinMode1   /* PortPinMode */
    },
    { /* Port_70_RL78F2X_PinModeConf[2] */
        1U,                         /* PortRegNum */
        Port_70_RL78F2X_PinMode2   /* PortPinMode */
    }
};

static const Port_70_HW_PinPiorSetType Port_70_RL78F2X_PinPiorSetConf[PORT_70_NUM_OF_PIOR_SET] = {
    { /* Port_70_RL78F2X_PinPiorSetConf[0] */
        PORT_70_RL78F2X_PIOR04_ADR,  /* PortPinPiorAddr   */
        2U,                          /* PortPinPiorBit    */
        PORT_SET_1                  /* PortPinPiorSetVal */
    },
    { /* Port_70_RL78F2X_PinPiorSetConf[1] */
        PORT_70_RL78F2X_PIOR04_ADR,  /* PortPinPiorAddr   */
        4U,                          /* PortPinPiorBit    */
        PORT_SET_0                  /* PortPinPiorSetVal */
    },
    { /* Port_70_RL78F2X_PinPiorSetConf[2] */
        PORT_70_RL78F2X_PIOR04_ADR,  /* PortPinPiorAddr   */
        6U,                          /* PortPinPiorBit    */
        PORT_SET_0                  /* PortPinPiorSetVal */
    },
    { /* Port_70_RL78F2X_PinPiorSetConf[3] */
        PORT_70_RL78F2X_PIOR02_ADR,  /* PortPinPiorAddr   */
        7U,                          /* PortPinPiorBit    */
        PORT_SET_1                  /* PortPinPiorSetVal */
    },
    { /* Port_70_RL78F2X_PinPiorSetConf[4] */
        PORT_70_RL78F2X_PIOR01_ADR,  /* PortPinPiorAddr   */
        1U,                          /* PortPinPiorBit    */
        PORT_SET_1                   /* PortPinPiorSetVal */
    },
    { /* Port_70_RL78F2X_PinPiorSetConf[5] */
        PORT_70_RL78F2X_PIOR00_ADR, /* PortPinPiorAddr      */
        7U,                         /* PortPinPiorBit       */
        PORT_SET_1                  /* PortPinPiorSetVal    */
    },
    { /* Port_70_RL78F2X_PinPiorSetConf[6] */
        PORT_70_RL78F2X_PIOR04_ADR, /* PortPinPiorAddr      */
        5U,                         /* PortPinPiorBit       */
        PORT_SET_1                  /* PortPinPiorSetVal    */
    },
    { /* Port_70_RL78F2X_PinPiorSetConf[7] */
        PORT_70_RL78F2X_PIOR09_ADR, /* PortPinPiorAddr      */
        4U,                         /* PortPinPiorBit       */
        PORT_SET_1                  /* PortPinPiorSetVal    */
    }
};

static const Port_70_HW_PortPinType HW_PortPinData[13] = {
    { /* HW_PortPinData[0] */
        NULL_PTR,        /* Port_70_PinSetConfPtr */
        NULL_PTR,        /* Port_70_PinPiorSetPtr */
        NULL_PTR        /* Port_70_PinChangePtr  */
    },
    { /* HW_PortPinData[1] */
        &Port_70_RL78F2X_PinModeConf[0],        /* Port_70_PinSetConfPtr */
         NULL_PTR,        /* Port_70_PinPiorSetPtr */
         NULL_PTR        /* Port_70_PinChangePtr  */
    },
    { /* HW_PortPinData[2] */
        &Port_70_RL78F2X_PinModeConf[1],        /* Port_70_PinSetConfPtr */
         NULL_PTR,        /* Port_70_PinPiorSetPtr */
         NULL_PTR        /* Port_70_PinChangePtr  */
    },
    { /* HW_PortPinData[3] */
        NULL_PTR,        /* Port_70_PinSetConfPtr */
        &Port_70_RL78F2X_PinPiorSetConf[0],        /* Port_70_PinPiorSetPtr */
        NULL_PTR        /* Port_70_PinChangePtr  */
    },
    { /* HW_PortPinData[4] */
        NULL_PTR,        /* Port_70_PinSetConfPtr */
        &Port_70_RL78F2X_PinPiorSetConf[1],        /* Port_70_PinPiorSetPtr */
        NULL_PTR        /* Port_70_PinChangePtr  */
    },
    { /* HW_PortPinData[5] */
        NULL_PTR,        /* Port_70_PinSetConfPtr */
        &Port_70_RL78F2X_PinPiorSetConf[2],        /* Port_70_PinPiorSetPtr */
        NULL_PTR        /* Port_70_PinChangePtr  */
    },
    { /* HW_PortPinData[6] */
        &Port_70_RL78F2X_PinModeConf[0],        /* Port_70_PinSetConfPtr */
        &Port_70_RL78F2X_PinPiorSetConf[0],        /* Port_70_PinPiorSetPtr */
        NULL_PTR        /* Port_70_PinChangePtr  */
    },
    { /* HW_PortPinData[7] */
        &Port_70_RL78F2X_PinModeConf[2],        /* Port_70_PinSetConfPtr */
        &Port_70_RL78F2X_PinPiorSetConf[1],        /* Port_70_PinPiorSetPtr */
        NULL_PTR        /* Port_70_PinChangePtr  */
    },
    { /* HW_PortPinData[8] */
        NULL_PTR,        /* Port_70_PinSetConfPtr */
        &Port_70_RL78F2X_PinPiorSetConf[4],        /* Port_70_PinPiorSetPtr */
        NULL_PTR         /* Port_70_PinChangePtr  */
    },
    { /* HW_PortPinData[9] */
        NULL_PTR,       /* Port_70_PinSetConfPtr */
        &Port_70_RL78F2X_PinPiorSetConf[3],         /* Port_70_PinPiorSetPtr */
        NULL_PTR        /* Port_70_PinChangePtr */
    },
    { /* HW_PortPinData[10]*/
        NULL_PTR,       /* Port_70_PinSetConfPtr */
        &Port_70_RL78F2X_PinPiorSetConf[5],         /* Port_70_PinPiorSetPtr */
        NULL_PTR        /* Port_70_PinChangePtr */
    },
    { /* HW_PortPinData[11]*/
        NULL_PTR,        /* Port_70_PinSetConfPtr */
        &Port_70_RL78F2X_PinPiorSetConf[6],        /* Port_70_PinPiorSetPtr */
        NULL_PTR        /* Port_70_PinChangePtr  */
    },
    { /* HW_PortPinData[12]*/
        &Port_70_RL78F2X_PinModeConf[0],           /* Port_70_PinSetConfPtr */
        &Port_70_RL78F2X_PinPiorSetConf[7],        /* Port_70_PinPiorSetPtr */
        NULL_PTR        /* Port_70_PinChangePtr  */
    }
};

static const Port_PortPinType PortPinData[PORT_70_NUM_OF_PORT_PIN] = {
    /* [PORT  0] */
    {
        PORT_70_P00,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        TRUE,                                /* PortPinDirectionChangeable */
        PORT_70_PIN_MODE_INTP,               /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        TRUE,                                /* PortPinModeChangeable      */
        (PORT_70_PIN_MODE_INTP | PORT_PIN_MODE_DIO_GPT),/* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P01  PortPinData[1] */
        PORT_70_P01,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P02  PortPinData[2] */
        PORT_70_P02,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P03  PortPinData[3] */
        PORT_70_P03,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P04  PortPinData[4] */
        PORT_70_P04,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P05  PortPinData[5] */
        PORT_70_P05,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P06  PortPinData[6] */
        PORT_70_P06,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P07  PortPinData[7] */
        PORT_70_P07,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  1] */
    {
        /* Port P10  PortPinData[8] */
        PORT_70_P10,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_CAN,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_CAN,                   /* PortPinMode                */
        &HW_PortPinData[5]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P11  PortPinData[9] */
        PORT_70_P11,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_CAN,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_CAN,                   /* PortPinMode                */
        &HW_PortPinData[5]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P12  PortPinData[10] */
        PORT_70_P12,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_PWM,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_PWM|PORT_PIN_MODE_DIO, /* PortPinMode                */
        &HW_PortPinData[5]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P13  PortPinData[11] */
        PORT_70_P13,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_LIN,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */   /* refer to Lin Document(DetailDesign) */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_LIN,                   /* PortPinMode                */
        &HW_PortPinData[4]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P14  PortPinData[12] */
        PORT_70_P14,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_LIN,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_LIN,                   /* PortPinMode                */
        &HW_PortPinData[7]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */ /* refer to Lin Document(DetailDesign) */
    },
    {
        /* Port P15  PortPinData[13] */
        PORT_70_P15,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_PWM,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_PWM|PORT_PIN_MODE_DIO, /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P16  PortPinData[14] */
        PORT_70_P16,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        TRUE,                                /* PortPinDirectionChangeable */
        PORT_PIN_MODE_ICU,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_ICU,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P17  PortPinData[15] */
        PORT_70_P17,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_ICU,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_ICU,                   /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  2] */
    {
        /* Port P20  PortPinData[16] */
        PORT_70_P20,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P21  PortPinData[17] */
        PORT_70_P21,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P22  PortPinData[18] */
        PORT_70_P22,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P23  PortPinData[19] */
        PORT_70_P23,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P24  PortPinData[20] */
        PORT_70_P24,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P25  PortPinData[21] */
        PORT_70_P25,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P26  PortPinData[22] */
        PORT_70_P26,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P27  PortPinData[23] */
        PORT_70_P27,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  3] */

    {
        /* Port P30  PortPinData[24] */
        PORT_70_P30,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P31  PortPinData[25] */
        PORT_70_P31,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P32  PortPinData[26] */
        PORT_70_P32,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P33  PortPinData[27] */
        PORT_70_P33,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P34  PortPinData[28] */
        PORT_70_P34,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P35  PortPinData[29] */
        PORT_70_P35,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P36  PortPinData[30] */
        PORT_70_P36,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P37  PortPinData[31] */
        PORT_70_P37,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  4] */
    {
        /* Port P40  PortPinData[32] */
        PORT_70_P40,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P41  PortPinData[33] */
        PORT_70_P41,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P42  PortPinData[34] */
        PORT_70_P42,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P43  PortPinData[35] */
        PORT_70_P43,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P44  PortPinData[36] */
        PORT_70_P44,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_ICU,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_ICU,                  /* PortPinMode                */
        &HW_PortPinData[10]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P45  PortPinData[37] */
        PORT_70_P45,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
 
        /* Port P46  PortPinData[38] */
        PORT_70_P46,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P47  PortPinData[39] */
        PORT_70_P47,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_ICU,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_ICU,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  5] */
    {
        /* Port P50  PortPinData[40] */
        PORT_70_P50,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P51  PortPinData[41] */
        PORT_70_P51,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P52  PortPinData[42] */
        PORT_70_P52,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */   /* refer to Lin Document(DetailDesign) */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                  /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P53  PortPinData[43] */
        PORT_70_P53,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */   /* refer to Lin Document(DetailDesign) */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P54  PortPinData[44] */
        PORT_70_P54,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P55  PortPinData[45] */
        PORT_70_P55,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P56  PortPinData[46] */
        PORT_70_P56,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P57  PortPinData[47] */
        PORT_70_P57,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_ICU,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_ICU,                   /* PortPinMode                */
        &HW_PortPinData[9]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  6] */
    {
        /* Port P60  PortPinData[48] */
        PORT_70_P60,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_CAN,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_CAN,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P61  PortPinData[49] */
        PORT_70_P61,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_CAN,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_CAN,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P62  PortPinData[50] */
        PORT_70_P62,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P63  PortPinData[51] */
        PORT_70_P63,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P64  PortPinData[52] */
        PORT_70_P64,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P65  PortPinData[53] */
        PORT_70_P65,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P66  PortPinData[54] */
        PORT_70_P66,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P67  PortPinData[55] */
        PORT_70_P67,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  7] */
    {
        /* Port P70  PortPinData[56] */
        PORT_70_P70,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_LIN,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */   /* refer to Lin Document(DetailDesign) */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_LIN,                   /* PortPinMode                */
        &HW_PortPinData[12]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P71  PortPinData[57] */
        PORT_70_P71,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_LIN,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_LIN,                   /* PortPinMode                */
        &HW_PortPinData[12]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P72  PortPinData[58] */
        PORT_70_P72,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P73  PortPinData[59] */
        PORT_70_P73,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P74  PortPinData[60] */
        PORT_70_P74,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_SPI,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_SPI,                   /* PortPinMode                */
        &HW_PortPinData[6]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P75  PortPinData[61] */
        PORT_70_P75,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_SPI,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_SPI,                   /* PortPinMode                */
        &HW_PortPinData[3]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P76  PortPinData[62] */
        PORT_70_P76,                         /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_SPI,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_SPI,                   /* PortPinMode                */
        &HW_PortPinData[3]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P77  PortPinData[63] */
        PORT_70_P77,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  8] */

    {
        /* Port P80  PortPinData[64] */
        PORT_70_P80,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P81  PortPinData[65] */
        PORT_70_P81,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_ADC,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_ADC,                   /* PortPinMode                */
        &HW_PortPinData[2]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P82  PortPinData[66] */
        PORT_70_P82,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P83  PortPinData[67] */
        PORT_70_P83,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_ADC,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_ADC,                   /* PortPinMode                */
        &HW_PortPinData[2]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P84  PortPinData[68] */
        PORT_70_P84,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_ADC,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_ADC,                   /* PortPinMode                */
        &HW_PortPinData[2]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P85  PortPinData[69] */
        PORT_70_P85,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P86  PortPinData[70] */
        PORT_70_P86,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P87  PortPinData[71] */
        PORT_70_P87,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  9] */
    {
        /* Port P90  PortPinData[72] */
        PORT_70_P90,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P91  PortPinData[73] */
        PORT_70_P91,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P92  PortPinData[74] */
        PORT_70_P92,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P93  PortPinData[75] */
        PORT_70_P93,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P94  PortPinData[76] */
        PORT_70_P94,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P95  PortPinData[77] */
        PORT_70_P95,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P96  PortPinData[78] */
        PORT_70_P96,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P97  PortPinData[79] */
        PORT_70_P97,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  10] */
    {
        /* Port P100  PortPinData[80] */
        PORT_70_P100,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P101  PortPinData[81] */
        PORT_70_P101,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P102  PortPinData[82] */
        PORT_70_P102,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P103  PortPinData[83] */
        PORT_70_P103,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P104  PortPinData[84] */
        PORT_70_P104,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P105  PortPinData[85] */
        PORT_70_P105,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P106  PortPinData[86] */
        PORT_70_P106,                        /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_LIN,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */   /* refer to Lin Document(DetailDesign) */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_LIN,                   /* PortPinMode                */
        &HW_PortPinData[11]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P107  PortPinData[87] */
        PORT_70_P107,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_LIN,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_LIN,                   /* PortPinMode                */
        &HW_PortPinData[7]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  11] */
    {
        /* Port P110  PortPinData[88] */
        PORT_70_P110,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P111  PortPinData[89] */
        PORT_70_P111,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P112  PortPinData[90] */
        PORT_70_P112,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P113  PortPinData[91] */
        PORT_70_P113,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P114  PortPinData[92] */
        PORT_70_P114,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P115  PortPinData[93] */
        PORT_70_P115,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P116  PortPinData[94] */
        PORT_70_P116,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P117  PortPinData[95] */
        PORT_70_P117,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  12] */

    {
        /* Port P120  PortPinData[96] */
        PORT_70_P120,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_ICU,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_ICU,                   /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P121  PortPinData[97] */
        PORT_70_P121,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P122  PortPinData[98] */
        PORT_70_P122,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P123  PortPinData[99] */
        PORT_70_P123,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P124  PortPinData[100] */
        PORT_70_P124,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P125  PortPinData[101] */
        PORT_70_P125,                        /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_PWM,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_PWM,                   /* PortPinMode                */
        &HW_PortPinData[1]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P126  PortPinData[102] */
        PORT_70_P126,                        /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO|PORT_PIN_MODE_PWM, /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO|PORT_PIN_MODE_PWM, /* PortPinMode                */
        &HW_PortPinData[8]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P127  PortPinData[103] */
        PORT_70_P127,                        /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  13] */
    {
        /* Port P130  PortPinData[104] */
        PORT_70_P130,                        /* PortPinId                  */
        PORT_PIN_OUT,                        /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P131  PortPinData[105] */
        PORT_70_P131,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P132  PortPinData[106] */
        PORT_70_P132,                         /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P133  PortPinData[107] */
        PORT_70_P133,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P134  PortPinData[108] */
        PORT_70_P134,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P135  PortPinData[109] */
        PORT_70_P135,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P136  PortPinData[110] */
        PORT_70_P136,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P137  PortPinData[111] */
        PORT_70_P137,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_DIO,                   /* PortPinInitialMode         */
        PORT_PIN_LEVEL_HIGH,                 /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_DIO,                   /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  14] */
    {
        /* Port P140  PortPinData[112] */
        PORT_70_P140,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P141  PortPinData[113] */
        PORT_70_P141,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P142  PortPinData[114] */
        PORT_70_P142,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P143  PortPinData[115] */
        PORT_70_P143,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P144  PortPinData[116] */
        PORT_70_P144,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P145  PortPinData[117] */
        PORT_70_P145,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P146  PortPinData[118] */
        PORT_70_P146,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P147  PortPinData[119] */
        PORT_70_P147,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    /* [PORT  15] */
    {
        /* Port P150  PortPinData[120] */
        PORT_70_P150,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P151  PortPinData[121] */
        PORT_70_P151,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P152  PortPinData[122] */
        PORT_70_P152,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P153  PortPinData[123] */
        PORT_70_P153,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P154  PortPinData[124] */
        PORT_70_P154,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P155  PortPinData[125] */
        PORT_70_P155,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P156  PortPinData[126] */
        PORT_70_P156,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    },
    {
        /* Port P157  PortPinData[127] */
        PORT_70_P157,                        /* PortPinId                  */
        PORT_PIN_IN,                         /* PortPinDirection           */
        FALSE,                               /* PortPinDirectionChangeable */
        PORT_PIN_MODE_NONE,                  /* PortPinInitialMode         */
        PORT_PIN_LEVEL_LOW,                  /* PortPinLevelValue          */
        FALSE,                               /* PortPinModeChangeable      */
        PORT_PIN_MODE_NONE,                  /* PortPinMode                */
        &HW_PortPinData[0]                   /* PortHWPortPinType          */   /* Option ParameterPtr dependent on RL78F2X [SWS_Port_00081] */
    }
};

static const Port_ContainerType PortContainerData[PORT_70_NUM_OF_PORT_CONTAINER] = {
    {
        PORT_70_NUM_OF_PORT_PIN,    /* PortNumberOfPortPins */
        &( PortPinData[0U] )
    }
};

static const Port_ConfigSetType PortConfigSetData = {
    PORT_70_NUM_OF_PORT_CONTAINER,
    &( PortContainerData[0U] )
};

const Port_ConfigType Port_Config = {
    &( PortConfigSetData )
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/* EOF Port_PBcfg.c ***********************************************************/

 