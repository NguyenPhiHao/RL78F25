/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Can_70_Types.h                                               */
/* Version     : v1.00.01                                                     */
/* Contents    : This module provides services for initiating transmissions   */
/*               and calls the callback functions of the CanIf module for     */
/*               notifying events, independently from the hardware. Also it   */
/*               provides services to control the behavior and state of the   */
/*               CAN controllers that belong to the same CAN Hardware Unit.   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of CAN Driver                                                */
/* R22-11                                                                     */

#ifndef CAN_70_TYPES_H
#define CAN_70_TYPES_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Can_70_HW_Types.h"
#include "EcuM.h"
#include "Mcu_70_Types.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define CAN_70_VENDOR_ID_TYPES_H             (70U)
#define CAN_70_MODULE_ID_TYPES_H             (80U)

#define CAN_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    (22U)
#define CAN_70_AR_RELEASE_MINOR_VERSION_TYPES_H    (11U)
#define CAN_70_AR_RELEASE_REVISION_VERSION_TYPES_H (0U)

#define CAN_70_SW_MAJOR_VERSION_TYPES_H       (1U)
#define CAN_70_SW_MINOR_VERSION_TYPES_H       (0U)
#define CAN_70_SW_PATCH_VERSION_TYPES_H       (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Check if current file and Can_70_HW_Types.h header file are of the same Vendor ID */
#if (CAN_70_VENDOR_ID_TYPES_H    != CAN_70_VENDOR_ID_HW_TYPES_H)
  #error "VENDOR ID for Can.c and Can_70_Types.h are different"
#endif    /* End of Vendor Id Version check */
#if (CAN_70_MODULE_ID_TYPES_H    != CAN_70_MODULE_ID_HW_TYPES_H)
  #error "MODULE ID for Can.c and Can_70_Types.h are different"
#endif    /* End of Vendor Id Version check */

/* Check if current file and Can_70_HW_Types.h header file are of the same Software version */
#if ((CAN_70_SW_MAJOR_VERSION_TYPES_H    != CAN_70_SW_MAJOR_VERSION_HW_TYPES_H) || \
     (CAN_70_SW_MINOR_VERSION_TYPES_H    != CAN_70_SW_MINOR_VERSION_HW_TYPES_H) || \
     (CAN_70_SW_PATCH_VERSION_TYPES_H    != CAN_70_SW_PATCH_VERSION_HW_TYPES_H))
  #error "Software Version Numbers of Can.c and Can_70_Types.h are different"
#endif    /* End of S/W Version check */

/* Check if current file and Can_70_HW_Types.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != CAN_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H) || \
     (CAN_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != CAN_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H) || \
     (CAN_70_AR_RELEASE_REVISION_VERSION_TYPES_H != CAN_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H))
  #error "AUTOSAR Version Numbers of Can.c and Can_70_Types.h are different"
#endif    /* End of Autosar Version check */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Check if current file and EcuM.h header file are of the same Autosar version */
  #if ((CAN_70_AR_RELEASE_MAJOR_VERSION_TYPES_H != ECU_AR_RELEASE_MAJOR_VERSION) || \
       (CAN_70_AR_RELEASE_MINOR_VERSION_TYPES_H != ECU_AR_RELEASE_MINOR_VERSION))
    #error "AUTOSAR Version Numbers of Can_70_Types.h and EcuM.h are different"
  #endif  /* End of Autosar Version check */
#endif  /* if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/*--------------Mcu_70_Types.h---------------------------------------------------*/
/* Check if current file and Mcu_70_Types.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_TYPES_H != MCU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H) || \
     (CAN_70_AR_RELEASE_MINOR_VERSION_TYPES_H != MCU_70_AR_RELEASE_MINOR_VERSION_TYPES_H))
  #error "AUTOSAR Version Numbers of Can_70_Types.h and Mcu_70_Types.h are different"
#endif  /* End of Autosar Version check */

/* macros                                                                     */
#define CAN_70_EXTENDED    (( Can_IdType )0x00U)
#define CAN_70_MIXED       (( Can_IdType )0x01U)
#define CAN_70_STANDARD    (( Can_IdType )0x02U)

/* type definitions */

/* Enumerations declaration */
/* [ECUC_Can_00495] */
typedef enum {
    CAN_OBJECT_PL_8,
    CAN_OBJECT_PL_12,   /* 1 */
    CAN_OBJECT_PL_16,   /* 2 */
    CAN_OBJECT_PL_20,   /* 3 */
    CAN_OBJECT_PL_24,   /* 4 */
    CAN_OBJECT_PL_32,   /* 5 */
    CAN_OBJECT_PL_48,   /* 6 */
    CAN_OBJECT_PL_64    /* 7 */
} Can_ObjectPIType;

/* [ECUC_Can_00323] */
typedef enum {
    CAN_70_BASIC,
    CAN_70_FULL
} Can_70_HandleType;

/* [ECUC_Can_00327] */
typedef enum {
    CAN_70_RECEIVE,
    CAN_70_TRANSMIT
} Can_70_ObjectType;

/* [SWS_Can_00103] */
typedef enum {
    CAN_UNINIT,
    CAN_READY
} Can_70_ModuleStatusType;

typedef enum {
    CAN_TO_NONE,
    CAN_TO_UNINIT,
    CAN_TO_STARTED,
    CAN_TO_STOPPED,
    CAN_TO_SLEEP,
    CAN_TO_BUSOFF,
    CAN_TO_WAKEUP
} Can_70_ControllerStatusActionType;

#if ( CAN_MULTIPLEXED_TRANSMISSION == TRUE )
typedef struct {
    bool_t           Enable;
    Can_HwHandleType Hth;
} Can_70_MultiTxHthInfoType;
#endif /* ( CAN_MULTIPLEXED_TRANSMISSION == TRUE ) */

typedef struct {
    bool_t           Enable;
    PduIdType        TxPduId;
    Can_HwHandleType Hth;
    uint16           TimeStamp;
} Can_70_EgressTimeStampType;

typedef struct {
    bool_t           Enable;
    Can_HwHandleType Hrh;
    uint16           TimeStamp;
} Can_70_IngressTimeStampType;

typedef struct {
    bool_t    Enable;
#if ( CAN_GLOBAL_TIME_SUPPORT == TRUE )
    bool_t    Timestamp;
#endif /* #if ( CAN_GLOBAL_TIME_SUPPORT == TRUE ) */
    PduIdType CanTxPduId;
} Can_70_TxRequestInfoType;

typedef struct {
    Can_HwHandleType Hth;
    uint8_least      IndexTxHwObj;
} Can_70_HthToHwObj;

/* [ECUC_Can_00473] */
typedef struct {
    uint32  CanControllerFdBaudRate;        /* [ECUC_Can_00481] */
    uint8   CanControllerPropSeg;           /* [ECUC_Can_00476] */
    uint8   CanControllerSeg1;              /* [ECUC_Can_00476] */
    uint8   CanControllerSeg2;              /* [ECUC_Can_00477] */
    uint8   CanControllerSspOffset;         /* [ECUC_Can_00494] */
    uint8   CanControllerSyncJumpWidth;     /* [ECUC_Can_00479] */
    bool_t  CanControllerTxBitRateSwitch;   /* [ECUC_Can_00475] */
} Can_ControllerFdBaudrateConfigType;

/* [ECUC_Can_00387] */
typedef struct
{
    uint32  CanControllerBaudRate;                    /* [ECUC_Can_00005] */
    uint16  CanControllerBaudRateConfigID;            /* [ECUC_Can_00471] */
    uint8   CanControllerPropSeg;                     /* [ECUC_Can_00073] */
    uint8   CanControllerSeg1;                        /* [ECUC_Can_00074] */
    uint8   CanControllerSeg2;                        /* [ECUC_Can_00075] */
    uint8   CanControllerSyncJumpWidth;               /* [ECUC_Can_00083] */
    const Can_ControllerFdBaudrateConfigType*  
            CanControllerFdBaudrateConfig;            /* [ECUC_Can_00473] */
} Can_ControllerBaudrateConfigType;

/* [ECUC_Can_00468] */
typedef struct
{
    uint32  CanHwFilterCode;                          /* [ECUC_Can_00469] */
    uint32  CanHwFilterMask;                          /* [ECUC_Can_00470] */
} CanHwFilterType;

/* [ECUC_Can_00354] */
typedef struct
{
    bool_t  CanControllerActivation;                  /* [ECUC_Can_00315] */
    uint32  CanControllerBaseAddress;                 /* [ECUC_Can_00382] */
    uint8   CanControllerId;                          /* [ECUC_Can_00316] */
    uint8   CanChannelId;                             /* [ECUC_Can_00316] */
    uint8   CanQClockSource;                          /* [ECUC_Can_00318] */
    uint8   CanTxProcessing;                          /* [ECUC_Can_00318] */
    uint8   CanRxProcessing;                          /* [ECUC_Can_00317] */
    uint8   CanBusoffProcessing;                      /* [ECUC_Can_00319] */
    bool_t  CanWakeupProcessing;                      /* [ECUC_Can_00319] */
    bool_t  CanWakeupSupport;                         /* [ECUC_Can_00319] */
    const Can_ControllerBaudrateConfigType*  
            CanControllerDefaultBaudrate;             /* [ECUC_Can_00435] */
    uint32  CanCpuClockRef;                           /* [ECUC_Can_00313] */
    EcuM_WakeupSourceType  
            CanWakeupSourceRef;                       /* [ECUC_Can_00359] */
    const Can_ControllerBaudrateConfigType*  
            CanControllerBaudRateConfig;              /* [ECUC_Can_00387] */
} Can_ControllerConfigType;

/* [ECUC_Can_00437] */
typedef struct
{
    uint16  CanMainFunctionPeriod;                    /* [ECUC_Can_00484] */
} Can_MainFunctionRWPeriodsType;

/* [ECUC_Can_00324] */
typedef struct
{
#if ( CAN_70_USE_CANFD == TRUE )
    uint8                              CanFdPaddingValue;           /* [ECUC_Can_00485] */
#endif /*#if ( CAN_70_USE_CANFD == TRUE ) */

    Can_70_HandleType                  CanHandleType;               /* [ECUC_Can_00323] */
    bool_t                             CanHardwareObjectUsesPolling;/* [ECUC_Can_00490] */
    uint16                             CanHwObjectCount;            /* [ECUC_Can_00467] */
    uint8                              CanIdType;                   /* [ECUC_Can_00065] */
    uint8                              CanObjectId;                 /* [ECUC_Can_00326] */
    Can_ObjectPlType                   CanObjectPayloadLength;      /* [ECUC_Can_00495] */
    Can_70_ObjectType                  CanObjectType;               /* [ECUC_Can_00327] */
    bool_t                             CanTriggerTransmitEnable;    /* [ECUC_Can_00486] */
    const Can_ControllerType*          CanControllerRef;            /* [ECUC_Can_00322] */
    const Can_MainFunctionRWPeriodsType* CanMainFunctionRWPeriodRef;/* [ECUC_Can_00438] */
    const Can_HwFilterType*            CanHwFilter;                 /* [ECUC_Can_00324] */
} Can_HardwareObjectType;

/* [ECUC_Can_00343] */
typedef struct
{
    const Can_ControllerType*          CanController;               /* [ECUC_Can_00354] */
    const Can_HardwareObjectType*      CanHardwareObject;           /* [ECUC_Can_00324] */
} Can_ConfigSetType;

/* [SWS_Can_00413],[ECUC_Can_00489] */
typedef struct
{
    const Can_ConfigSetType*           CanConfigSet;                /* [ECUC_Can_00343] */
} Can_ConfigType;

/* [SWS_Can_00443] */
typedef bool_t (*LPDU_CALLOUT_TYPE)(
    uint8               Hrh,
    Can_IdType          CanId,
    uint8               CanDataLength,
    const uint8*        CanSduPtr
);

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

#endif /* #ifndef CAN_70_TYPES_H */

/* EOF Can_70_Types.h */
