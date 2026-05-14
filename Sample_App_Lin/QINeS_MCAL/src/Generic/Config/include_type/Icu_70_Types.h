/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu_70_Types.h                                               */
/* Version     : v1.00.01                                                     */
/* Contents    : Icu Module type definition header                            */
/*               The ICU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of ICU Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef ICU_70_TYPES_H_
#define ICU_70_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Icu_Cfg.h"
#include "Icu_70_HW_Types.h"

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define ICU_70_VENDOR_ID_TYPES_H                      (70U)
#define ICU_70_MODULE_ID_TYPES_H                      (122U)

#define ICU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H       (22U)
#define ICU_70_AR_RELEASE_MINOR_VERSION_TYPES_H       (11U)
#define ICU_70_AR_RELEASE_REVISION_VERSION_TYPES_H    (0U)

#define ICU_70_SW_MAJOR_VERSION_TYPES_H               (1U)
#define ICU_70_SW_MINOR_VERSION_TYPES_H               (0U)
#define ICU_70_SW_PATCH_VERSION_TYPES_H               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_Types.h and Std_Types.h are different"
#endif

/* Std_Types.h version check end */

/* Icu_Cfg.h version check start */

#if ( ICU_70_VENDOR_ID_TYPES_H != ICU_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Icu_70_Types.h and Icu_Cfg.h are different"
#endif

#if ( ICU_70_MODULE_ID_TYPES_H != ICU_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Icu_70_Types.h and Icu_Cfg.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != ICU_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != ICU_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_TYPES_H != ICU_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_Types.h and Icu_Cfg.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_TYPES_H != ICU_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( ICU_70_SW_MINOR_VERSION_TYPES_H != ICU_70_SW_MINOR_VERSION_CFG_H ) || \
      ( ICU_70_SW_PATCH_VERSION_TYPES_H != ICU_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Icu_70_Types.h and Icu_Cfg.h are different"
#endif

/* Icu_Cfg.h version check end */

/* Icu_70_HW_Types.h version check start */

#if ( ICU_70_VENDOR_ID_TYPES_H != ICU_70_VENDOR_ID_HW_TYPES_H )
    #error "VENDOR ID for Icu_70_Types.h and Icu_70_HW_Types.h are different"
#endif

#if ( ICU_70_MODULE_ID_TYPES_H != ICU_70_MODULE_ID_HW_TYPES_H )
    #error "MODULE ID for Icu_70_Types.h and Icu_70_HW_Types.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != ICU_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != ICU_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_TYPES_H != ICU_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_Types.h and Icu_70_HW_Types.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_TYPES_H != ICU_70_SW_MAJOR_VERSION_HW_TYPES_H ) || \
      ( ICU_70_SW_MINOR_VERSION_TYPES_H != ICU_70_SW_MINOR_VERSION_HW_TYPES_H ) || \
      ( ICU_70_SW_PATCH_VERSION_TYPES_H != ICU_70_SW_PATCH_VERSION_HW_TYPES_H ) \
    )
    #error "Software Version Numbers of Icu_70_Types.h and Icu_70_HW_Types.h are different"
#endif

/* Icu_70_HW_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* [SWS_Icu_00277] */
typedef enum {
    ICU_MODE_NORMAL              = ( uint8 )( 0x00U ),
    ICU_MODE_SLEEP               = ( uint8 )( 0x01U )
} Icu_ModeType;

/* [SWS_Icu_00279] */
typedef enum {
    ICU_IDLE                     = ( uint8 )( 0x00U ),
    ICU_ACTIVE                   = ( uint8 )( 0x01U )
} Icu_InputStateType;

/* [SWS_Icu_00290] */
typedef uint32 Icu_ValueType;

/* [SWS_Icu_00296] */
typedef enum {
    ICU_LINEAR_BUFFER            = ( uint8 )( 0x00U ),
    ICU_CIRCULAR_BUFFER          = ( uint8 )( 0x01U )
} Icu_TimestampBufferType;

/* [SWS_Icu_00295] */
typedef enum {
    ICU_LOW_TIME                 = ( 0x00U ),
    ICU_HIGH_TIME                = ( 0x01U ),
    ICU_PERIOD_TIME              = ( 0x02U ),
    ICU_DUTY_CYCLE               = ( 0x03U )
} Icu_SignalMeasurementPropertyType;

/* [SWS_Icu_00294] */
typedef enum {
    ICU_MODE_SIGNAL_EDGE_DETECT  = ( uint8 )( 0x00U ),
    ICU_MODE_SIGNAL_MEASUREMENT  = ( uint8 )( 0x01U ),
    ICU_MODE_TIMESTAMP           = ( uint8 )( 0x02U ),
    ICU_MODE_EDGE_COUNTER        = ( uint8 )( 0x03U )
} Icu_MeasurementModeType;

/* [SWS_Icu_00289] */
typedef enum {
    ICU_70_NO_EDGE               = ( uint8 )( 0x00U ),
    ICU_RISING_EDGE              = ( uint8 )( 0x01U ),
    ICU_FALLING_EDGE             = ( uint8 )( 0x02U ),
    ICU_BOTH_EDGES               = ( uint8 )( 0x03U )
} Icu_ActivationType;

#if ( ICU_DEV_ERROR_DETECT != FALSE )
/* Indicates that the initialization status. */
typedef enum {
    ICU_STATE_UNINITIALIZED      = ( 0U ),
    ICU_STATE_INITIALIZED        = ( 1U )
} Icu_70_ModuleStateType;
#endif
typedef uint16 Icu_ChannelType;                                     /* [SWS_Icu_00278]    */
#if ( ICU_TIMESTAMP_API != FALSE )    /* [SWS_Icu_00325] */
typedef uint32 Icu_IndexType;                                       /* [SWS_Icu_00292]    */
#endif
#if ( ICU_EDGE_COUNT_API != FALSE )    /* [SWS_Icu_00333] */
typedef uint32 Icu_EdgeNumberType;                                  /* [SWS_Icu_00293]    */
#endif
/* [SWS_Icu_00291] */
typedef struct {
    Icu_ValueType           ActiveTime;
    Icu_ValueType           PeriodTime;
} Icu_DutyCycleType;

/* [SWS_Icu_00126] */
typedef struct {
    EcuM_WakeupSourceType                IcuChannelWakeupInfo;      /* Icu Channel Wakeup Info */ /* [SWS_Icu_00231] */
} Icu_WakeupType;

/* [SWS_Icu_00228] */
typedef struct {
    Icu_TimestampBufferType              IcuTimestampMeasurementProperty; /* Icu Timestamp Measurement Property */ /* [SWS_Icu_00229] */
    void ( *IcuTimestampNotification )( void );                           /* Icu Timestamp Notification         */ /* [SWS_Icu_00230] */
} Icu_TimestampMeasurementType;

/* [SWS_Icu_00226] */
typedef struct {
    Icu_SignalMeasurementPropertyType    IcuSignalMeasurementProperty;  /* Icu Signal Measurement Property */ /* [SWS_Icu_00227] */
} Icu_SignalMeasurementType;

/* [SWS_Icu_00021] */
typedef struct {
    void ( *IcuSignalNotification )( void );                            /* Icu Signal Notification   */ /* [SWS_Icu_00225] */
} Icu_SignalEdgeDetectionType;

/* [SWS_Icu_00027] */
typedef struct {
    Icu_ChannelType                     IcuChannelId;               /* Icu Channel               */ /* [SWS_Icu_00278]  */
    Icu_ActivationType                  IcuDefaultStartEdge;        /* Icu Default Start Edge    */ /* [SWS_Icu_00222] */
    Icu_MeasurementModeType             IcuMeasurementMode;         /* Icu Measurement Mode      */ /* [SWS_Icu_00223] */
    bool_t                              IcuWakeupCapability;        /* Icu Wakeup Capability     */ /* [SWS_Icu_00224] */
    const Icu_SignalEdgeDetectionType*  IcuSignalEdgeDetection;     /* Icu Signal Edge Detection */ /* [SWS_Icu_00021] */
    const Icu_SignalMeasurementType*    IcuSignalMeasurement;       /* Icu Signal Measurement    */ /* [SWS_Icu_00226] */
    const Icu_TimestampMeasurementType* IcuTimestampMeasurement;    /* Icu Timestamp Measurement */ /* [SWS_Icu_00228] */
    const Icu_WakeupType*               IcuWakeup;                  /* Icu Wakeup                */ /* [SWS_Icu_00126] */
    const Icu_70_HW_SetConfType*        IcuSetConfPtr;              /* Icu_70_RL78F2X_SettingConfigType */
} Icu_IcuChannelType;

/* [ECUC_Icu_00219] */
typedef struct {
    Icu_ChannelType                     IcuMaxChannel;              /* [SWS_Icu_00220][ECUC_Icu_00220] */
    const Icu_IcuChannelType*           IcuChannel;                 /* [SWS_Icu_00027] */
} Icu_ConfigSetType;

/* [SWS_Icu_00280] */
typedef struct {
    const Icu_ConfigSetType             IcuConfigSet;
} Icu_ConfigType;

/* Work information for a channel. */
typedef struct {
    Icu_ChannelType                     icuCh;                      /*  icu channel id                     */
    Icu_InputStateType                  state;                      /*  input state of an ICU channel      */
    const Icu_IcuChannelType*           conf_chInfo;                /*  configuration channel information  */
    Icu_ActivationType                  actType;                    /*  Activation Type                    */
    bool_t                              notifSw;                    /*  Notification Switch                */
    EcuM_WakeupSourceType               wuSrc;                      /*  Icu Channel Wakeup Info            */
    bool_t                              wuCap;                      /*  Wakeup Capability                  */
    bool_t                              wuEbl;                      /*  Wakeup Enable/Disable              */
    uint8                               irqState;                   /*  first flag                         */
    bool_t                              chRunning;                  /*  TRUE:Channel is Running, FALSE :Channel is Stopped */
    void                                (*cbEdge)( void );          /*  Callback for Edge notification     */
    Icu_ValueType                       elapsedTime;                /*  elapsed time                       */
    Icu_MeasurementModeType             msrMode;                    /*  Measurement Mode                   */
    Icu_SignalMeasurementPropertyType   msrProp;                    /*  Measurement Property               */
    Icu_DutyCycleType                   duty;                       /*  duty cycle data                    */
    uint16                              notifIntv;                  /*  Notification Interval for time stamp */
    uint16                              notifCnt;                   /*  Notification Count for time stamp  */
    Icu_TimestampBufferType             bufType;                    /*  captured buff type                 */
    uint16                              bufIdx;                     /*  captured buff index                */
    uint16                              bufSize;                    /*  captured buff size                 */
    Icu_ValueType*                      buff;                       /*  Time stamp captured buffer         */
    void                                ( *cbTS )( void );          /*  Callback for TS notification       */
    uint16                              edgeCount;                  /*  edge count                         */
} Icu_70_ChannelInfoType;
/*----------------------------------------------------------------------------*/
/* External Variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototypes                                                        */
/*----------------------------------------------------------------------------*/

#endif /* #ifndef ICU_70_TYPES_H_ */

/* EOF Icu_70_Types.h *********************************************************/
