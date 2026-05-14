/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : EcuM.h                                                       */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef ECUM_H
#define ECUM_H

#define ECUM_Q_CONST const
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "EcuM_Types.h"
#include "EcuM_Cbk.h"
#include "Os.h"
#include "Mcu.h"

#if ( ECUM_Q_FLEX == FALSE )
#if ( ECUM_Q_MOD_NVM_ENABLED != FALSE )
#include "NvM.h"
#endif /* ECUM_Q_MOD_NVM_ENABLED */
#endif /* ECUM_Q_FLEX */
#if ( ECUM_Q_MOD_BSWM_ENABLED != FALSE )
#include "BswM.h"
#endif /* ECUM_Q_MOD_BSWM_ENABLED */
#if ( ECUM_Q_MOD_COMM_ENABLED != FALSE )
#include "ComM_Types.h"
#endif /* ECUM_Q_MOD_COMM_ENABLED */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
#define ECUM_Q_CONST const

/* [ECUC_EcuM_00116] */
typedef struct {
bool_t                                      EcuMDevErrorDetect;              /* [ECUC_EcuM_00108] */
bool_t                                      EcuMIncludeDet;                  /* [ECUC_EcuM_00118] */
uint32                                      EcuMMainFunctionPeriod;          /* [ECUC_EcuM_00121] */
bool_t                                      EcuMVersionInfoApi;              /* [ECUC_EcuM_00149] */
} EcuM_GeneralType;

#if ( ECUM_Q_FLEX == FALSE )
/* [ECUC_EcuM_00166] */
typedef struct {
bool_t                                      EcuMIncludeComM;                 /* [ECUC_EcuM_00189] */
bool_t                                      EcuMTTIIEnabled;                 /* [ECUC_EcuM_00144] */
EcuM_WakeupSourceType                       EcuMTTIIWakeupSourceRef;         /* [ECUC_EcuM_00145] */
} EcuM_FixedGeneralType;
#endif /* ECUM_Q_FLEX */

/* [ECUC_EcuM_00150] */
typedef struct {
    uint16                                  EcuMCheckWakeupTimeout;           /* [ECUC_EcuM_00208] */
#if ( ECUM_Q_FLEX == FALSE )
    uint32                                  EcuMValidationTimeout;            /* [ECUC_EcuM_00148] */
#else
    EcuM_TimeType                           EcuMValidationTimeout;            /* [ECUC_EcuM_00148] */
#endif /* ECUM_Q_FLEX == FALSE */
    uint8                                   EcuMWakeupSourceId;               /* [ECUC_EcuM_00151] */
    bool_t                                  EcuMWakeupSourcePolling;          /* [ECUC_EcuM_00153] */
    uint8                                   EcuMComMChannelRef;               /* [ECUC_EcuM_00101] */
    uint8                                   EcuMResetReasonRef;               /* [ECUC_EcuM_00128] */
} EcuM_WakeupSourceTypeType;

/* [ECUC_EcuM_00131] */
typedef struct {
    uint8                                   EcuMSleepModeId;                  /* [ECUC_EcuM_00132] */
    bool_t                                  EcuMSleepModeSuspend;             /* [ECUC_EcuM_00136] */
    Mcu_ModeType                            EcuMSleepModeMcuModeRef;          /* [ECUC_EcuM_00133] */
    uint8                                   EcuMNumOfWakeupSourceMask;
    ECUM_Q_CONST uint8*                     EcuMWakeupSourceMask;             /* [ECUC_EcuM_00152] */
    uint32                                  EcuMWakeupSourceBitMask;
} EcuM_SleepModeType;

/* [ECUC_EcuM_00105] */
typedef struct {
    EcuM_StateType                          EcuMDefaultState;                 /* [ECUC_EcuM_00107] */
#if ( ECUM_Q_FLEX != FALSE )
    uint8                                   EcuMDefaultResetModeRef;          /* [ECUC_EcuM_00205] */
#endif /* ECUM_Q_FLEX */
    uint8                                   EcuMDefaultSleepModeRef;          /* [ECUC_EcuM_00106] */
} EcuM_DefaultShutdownTargetType;

#if ( ECUM_Q_FLEX == FALSE )
/* [ECUC_EcuM_00219] */
typedef struct {
    void*                                   EcuMFixedModuleConfigurationRef;  /* [ECUC_EcuM_00122] */
} EcuM_FixedModuleConfigurationType;
#endif /* ECUM_Q_FLEX */

/* [ECUC_EcuM_00181] */
typedef struct {
    uint32                                  EcuMConfigConsistencyHash;        /* [ECUC_EcuM_00102] */
    ECUM_Q_CONST AppModeType*               EcuMDefaultAppMode;               /* [ECUC_EcuM_00104] */
    ECUM_Q_CONST uint8*                     EcuMOSResource;                   /* [ECUC_EcuM_00183] */
    EcuM_DefaultShutdownTargetType          EcuMDefaultShutdownTarget;        /* [ECUC_EcuM_00105] */
    uint16                                  EcuMNumOfEcuMSleepMode;
    ECUM_Q_CONST EcuM_SleepModeType*        EcuMSleepMode;                    /* [ECUC_EcuM_00131] */
    uint8                                   EcuMNumOfEcuMWakeupSource;
    ECUM_Q_CONST EcuM_WakeupSourceTypeType* EcuMWakeupSource;                 /* [ECUC_EcuM_00150] */
} EcuM_CommonConfigurationType;

#if ( ECUM_Q_FLEX == FALSE )

/* [ECUC_EcuM_00147] */
typedef struct {
    uint8                                   EcuMFixedUser;                    /* [ECUC_EcuM_00202] */
} EcuM_FixedUserConfigType;

/* [ECUC_EcuM_00143] */
typedef struct {
    uint32                                  EcuMDivisor;                      /* [ECUC_EcuM_00109] */
    uint8                                   EcuMSleepModeRef;                 /* [ECUC_EcuM_00135] */
    uint8                                   EcuMSuccessorRef;                 /* [ECUC_EcuM_00141] */
} EcuM_TTIIType;

/* [ECUC_EcuM_00165] */
typedef struct {
    uint32                                  EcuMNvramReadallTimeout;          /* [ECUC_EcuM_00126] */
    uint32                                  EcuMNvramWriteallTimeout;         /* [ECUC_EcuM_00127] */
    uint32                                  EcuMRunMinimumDuration;           /* [ECUC_EcuM_00129] */
    uint16                                  EcuMNumOfEcuMComMCommunicationAllowedList;
    ECUM_Q_CONST uint8*                     EcuMComMCommunicationAllowedList; /* [ECUC_EcuM_00191] */
    Mcu_ModeType                            EcuMNormalMcuModeRef;             /* [ECUC_EcuM_00125] */
    uint16                                  EcuMNumOfEcuMFixedUserConfig;
    ECUM_Q_CONST EcuM_FixedUserConfigType*  EcuMFixedUserConfig;              /* [ECUC_EcuM_00147] */
    uint8                                   EcuMNumOfEcuMTTII;
    ECUM_Q_CONST EcuM_TTIIType*             EcuMTTII;                         /* [ECUC_EcuM_00143] */
} EcuM_FixedConfigurationType;

#else /* ( ECUM_Q_FLEX != FALSE ) */

typedef struct {
    bool_t                                  AlarmClockSet;
    EcuM_TimeType                           AlarmClock;
} EcuM_Q_AlarmClockType;

/* [ECUC_EcuM_00184] */
typedef struct {
    uint8                                   EcuMAlarmClockId;                       /* [ECUC_EcuM_00186] */
    EcuM_TimeType                           EcuMAlarmClockTimeOut;                  /* [ECUC_EcuM_00188] */
    EcuM_FlexUserType                       EcuMAlarmClockUser;                     /* [ECUC_EcuM_00195] */
} EcuM_AlarmClockType;

/* [ECUC_EcuM_00201] */
typedef struct {
    EcuM_FlexUserType                       EcuMFlexUser;                           /* [ECUC_EcuM_00146] */
    Ecuc_PartitionType*                     EcuMFlexEcucPartitionRef;               /* [ECUC_EcuM_00203] */
} EcuM_FlexUserConfigType;

/* [ECUC_EcuM_00206] */
typedef struct {
    uint16                                  EcuMNumOfEcuMGoDownAllowedUserRef;
    ECUM_Q_CONST EcuM_FlexUserType*         EcuMGoDownAllowedUserRef;               /* [ECUC_EcuM_00207] */
} EcuM_GoDownAllowedUsersType;

/* [ECUC_EcuM_00197] */
typedef struct {
    uint16                                  EcuMNumOfEcuMSetClockAllowedUserRef;
    ECUM_Q_CONST EcuM_FlexUserType*         EcuMSetClockAllowedUserRef;             /* [ECUC_EcuM_00198] */
} EcuM_SetClockAllowedUsersType;

/* [ECUC_EcuM_00172] */
typedef struct {
    uint8                                   EcuMResetModeId;                        /* [ECUC_EcuM_00173] */
} EcuM_ResetModeType;

/* [ECUC_EcuM_00175] */
typedef struct {
    EcuM_ShutdownCauseType                  EcuMShutdownCauseId;                    /* [ECUC_EcuM_00176] */
} EcuM_ShutdownCauseTypeType;

/* [ECUC_EcuM_00167] */
typedef struct {
    Mcu_ModeType                            EcuMNormalMcuModeRef;                   /* [ECUC_EcuM_00204] */
    uint16                                  EcuMNumOfEcuMPartitionRef;
    Ecuc_PartitionType*                     EcuMPartitionRef;                       /* [ECUC_EcuM_00217] */
    uint16                                  EcuMNumOfEcuMAlarmClock;
    ECUM_Q_CONST EcuM_AlarmClockType*       EcuMAlarmClock;                         /* [ECUC_EcuM_00184] */
    uint16                                  EcuMNumOfEcuMFlexUserConfig;
    ECUM_Q_CONST EcuM_FlexUserConfigType*   EcuMFlexUserConfig;                     /* [ECUC_EcuM_00201] */
#if ( ECUM_Q_ECUM_GO_DOWN_ALLOWED_USERS_ENABLED != FALSE )
    EcuM_GoDownAllowedUsersType             EcuMGoDownAllowedUsers;                 /* [ECUC_EcuM_00206] */
#endif /* ECUM_Q_ECUM_GO_DOWN_ALLOWED_USERS_ENABLED */
    uint16                                  EcuMNumOfEcuMResetMode;
    ECUM_Q_CONST EcuM_ResetModeType*        EcuMResetMode;                          /* [ECUC_EcuM_00172] */
#if ( ECUM_Q_ECUM_SET_CLOCK_ALLOWED_USERS_ENABLED != FALSE )
    EcuM_SetClockAllowedUsersType           EcuMSetClockAllowedUsers;               /* [ECUC_EcuM_00197] */
#endif /* ECUM_Q_ECUM_SET_CLOCK_ALLOWED_USERS_ENABLED */
    uint16                                  EcuMNumOfEcuMShutdownCause;
    ECUM_Q_CONST EcuM_ShutdownCauseTypeType*    EcuMShutdownCause;                  /* [ECUC_EcuM_00175] */
} EcuM_FlexConfigurationType;
#endif /* ECUM_Q_FLEX */

#if ( ECUM_Q_MULTI_CORE != FALSE )
typedef struct {
    CoreIdType                              EcuMQCoreId;
    TaskType                                EcuMQEventTaskId;
    EventMaskType                           EcuMQEventMask;
    OsIocIdType                             EcuMQIocId;
} EcuM_QEventInfoType;

typedef struct {
    uint8                                   EcuMNumOfEcuMQEventInfo;
    ECUM_Q_CONST EcuM_QEventInfoType*       EcuMQEventInfo;
} EcuM_QINeSConfigurationType;
#endif /* ECUM_Q_MULTI_CORE */

/* [ECUC_EcuM_00219] */
typedef struct {
    EcuM_CommonConfigurationType            EcuMCommonConfiguration;          /* [ECUC_EcuM_00181] */
#if ( ECUM_Q_FLEX == FALSE )
    EcuM_FixedConfigurationType             EcuMFixedConfiguration;           /* [ECUC_EcuM_00165] */
#else /* ( ECUM_Q_FLEX != FALSE ) */
    EcuM_FlexConfigurationType              EcuMFlexConfiguration;            /* [ECUC_EcuM_00167] */
#endif /* ECUM_Q_FLEX */
#if ( ECUM_Q_MULTI_CORE != FALSE )
    EcuM_QINeSConfigurationType             EcuMQINeSConfiguration;
#endif /* ECUM_Q_MULTI_CORE */
} EcuM_ConfigurationType;

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* DET Error CODE */
#define ECUM_E_UNINIT                           ( uint8 )( 0x10U )
#define ECUM_E_SERVICE_DISABLED                 ( uint8 )( 0x11U )
#define ECUM_E_PARAM_POINTER                    ( uint8 )( 0x12U ) /* EcuM_Flex */
#define ECUM_E_NULL_POINTER                     ( uint8 )( 0x12U ) /* EcuM_Fixed */
#define ECUM_E_INVALID_PAR                      ( uint8 )( 0x13U )
#define ECUM_E_MULTIPLE_RUN_REQUESTS            ( uint8 )( 0x14U )
#define ECUM_E_MISMATCHED_RUN_RELEASE           ( uint8 )( 0x15U )
#define ECUM_E_STATE_PAR_OUT_OF_RANGE           ( uint8 )( 0x16U )
#define ECUM_E_UNKNOWN_WAKEUP_SOURCE            ( uint8 )( 0x17U )
#define ECUM_E_INIT_FAILED                      ( uint8 )( 0x18U )

/* ModuleID */
#define ECUM_MODULE_ID                          ( uint16 )( MODULE_ID_ECUM )
/* Instance ID */
#define ECUM_INSTANCE_ID                        ( uint8 )( 0x00U )

#define ECUM_SW_MAJOR_VERSION                   ( uint8 )( 0x02U )
#define ECUM_SW_MINOR_VERSION                   ( uint8 )( 0x00U )
#define ECUM_SW_PATCH_VERSION                   ( uint8 )( 0x00U )

/* ServiceID */
/* General */
#define ECUM_GETVERSIONINFO_ID                  ( uint8 )( 0x00U )
/* Run Request */
#define ECUM_SETRUNREQUESTED_ID                 ( uint8 )( 0xDCU )
#define ECUM_CLEARRUNREQUESTED_ID               ( uint8 )( 0xDDU )
#define ECUM_ISRUNREQUESTED_ID                  ( uint8 )( 0xDEU )
#define ECUM_SETPOSTRUNREQUESTED_ID             ( uint8 )( 0xDFU )
#define ECUM_CLEARPOSTRUNREQUESTED_ID           ( uint8 )( 0xE0U )
#define ECUM_ISPOSTRUNREQUESTED_ID              ( uint8 )( 0xE1U )
/* Initialization and Shutdown */
#if ( ECUM_Q_FLEX != FALSE )
#define ECUM_GODOWN_ID                          ( uint8 )( 0x1FU )
#define ECUM_GOHALT_ID                          ( uint8 )( 0x20U )
#define ECUM_GOPOLL_ID                          ( uint8 )( 0x21U )
#endif /* ECUM_Q_FLEX */
#define ECUM_INIT_ID                            ( uint8 )( 0x01U )
#define ECUM_STARTUPTWO_ID                      ( uint8 )( 0x1AU )
#define ECUM_SHUTDOWN_ID                        ( uint8 )( 0x02U )
/* State Management */
#if (( ECUM_Q_FLEX == FALSE ) || (( ECUM_Q_FLEX != FALSE ) && ( ECUM_MODE_HANDLING != FALSE )))
#define ECUM_REQUESTRUN_ID                      ( uint8 )( 0x03U )
#define ECUM_RELEASERUN_ID                      ( uint8 )( 0x04U )
#define ECUM_REQUESTPOST_RUN_ID                 ( uint8 )( 0x0aU )
#define ECUM_RELEASEPOST_RUN_ID                 ( uint8 )( 0x0bU )
#endif /* ( ECUM_Q_FLEX != FALSE ) && ( ECUM_MODE_HANDLING != FALSE ) */
#if (( ECUM_Q_FLEX == FALSE ) || \
     (( ECUM_Q_FLEX != FALSE ) && ( ECUM_MODE_HANDLING != FALSE )) || \
     ( ECUM_Q_MOD_BSWM_ENABLED != FALSE ))
#define ECUM_RUNSTATUS_UNKNOWN                  ( uint8 )( 0x00U )
#define ECUM_RUNSTATUS_REQUESTED                ( uint8 )( 0x01U )
#define ECUM_RUNSTATUS_RELEASED                 ( uint8 )( 0x02U )
#define ECUM_SETSTATE_ID                        ( uint8 )( 0x03U )
#endif /* (( ECUM_Q_FLEX != FALSE ) && ( ECUM_MODE_HANDLING != FALSE )) || ( ECUM_Q_MOD_BSWM_ENABLED != FALSE )*/

#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_KILLALLRUNREQUESTS_ID              ( uint8 )( 0x05U )
#define ECUM_KILLALLPOSTRUNREQUESTS_ID          ( uint8 )( 0x2aU )
#endif /* ECUM_Q_FLEX */
#define ECUM_SELECTSHUTDOWNTARGET_ID            ( uint8 )( 0x06U )
#define ECUM_GETSHUTDOWNTARGET_ID               ( uint8 )( 0x09U )
#define ECUM_GETLASTSHUTDOWNTARGET_ID           ( uint8 )( 0x08U )
#if ( ECUM_Q_FLEX != FALSE )
#define ECUM_SELECTSHUTDOWNCAUSE_ID             ( uint8 )( 0x1BU )
#define ECUM_GETSHUTDOWNCAUSE_ID                ( uint8 )( 0x1CU )
#define ECUM_SETRELWAKEUPALARM_ID               ( uint8 )( 0x22U )
#define ECUM_SETABSWAKEUPALARM_ID               ( uint8 )( 0x23U )
#define ECUM_ABORTWAKEUPALARM_ID                ( uint8 )( 0x24U )
#define ECUM_GETCURRENTTIME_ID                  ( uint8 )( 0x25U )
#define ECUM_GETWAKEUPTIME_ID                   ( uint8 )( 0x26U )
#define ECUM_SETCLOCK                           ( uint8 )( 0x27U )
#endif /* ECUM_Q_FLEX */
#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_GETSTATE_ID                        ( uint8 )( 0x07U )
#endif /* ECUM_Q_FLEX */
/* Wake up Handling */
#define ECUM_GETPENDINGWAKEUPEVENTS_ID          ( uint8 )( 0x0DU )
#define ECUM_CLEARWAKEUPEVENT_ID                ( uint8 )( 0x16U )
#define ECUM_GETVALIDATEDWAKEUPEVENTS_ID        ( uint8 )( 0x15U )
#define ECUM_GETEXPIREDWAKEUPEVENTS_ID          ( uint8 )( 0x19U )
#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_GETSTATUSOFWAKEUPSOURCE_ID         ( uint8 )( 0x17U )
#endif /* ECUM_Q_FLEX */
#define ECUM_STARTCHECKWAKEUP_ID                ( uint8 )( 0x28U )
#define ECUM_ENDCHECKWAKEUP_ID                  ( uint8 )( 0x29U )
/* Miscellaneous */
#define ECUM_SELECTBOOTTARGET_ID                ( uint8 )( 0x12U )
#define ECUM_GETBOOTTARGET_ID                   ( uint8 )( 0x13U )
/* Scheduled Functions */
#define ECUM_MAINFUNCTION_ID                    ( uint8 )( 0x18U )
/* Add QINeS API */
#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_Q_SWITCHSTATE_STARTUPONE_ID        ( uint8 )( 0x9AU )
#define ECUM_Q_SWITCHSTATE_STARTUPTWO_ID        ( uint8 )( 0x9BU )
#define ECUM_Q_SWITCHSTATE_APPRUN_ID            ( uint8 )( 0x9CU )
#define ECUM_Q_SWITCHSTATE_APPPOSTRUN_ID        ( uint8 )( 0x9DU )
#define ECUM_Q_SWITCHSTATE_PREPSHUTDOWN_ID      ( uint8 )( 0x9EU )
#define ECUM_Q_SWITCHSTATE_WAKEUPONE_ID         ( uint8 )( 0x9FU )
#define ECUM_Q_SWITCHSTATE_WAKEUPVALIDATION_ID  ( uint8 )( 0xA0U )
#define ECUM_Q_SWITCHSTATE_WAKEUPREACTION_ID    ( uint8 )( 0xA1U )
#define ECUM_Q_SWITCHSTATE_WAKEUPTWO_ID         ( uint8 )( 0xA2U )
#define ECUM_Q_SWITCHSTATE_WAKEUPWAKESLEEP_ID   ( uint8 )( 0xA3U )
#define ECUM_Q_SWITCHSTATE_WAKEUPTTII_ID        ( uint8 )( 0xA4U )
#define ECUM_Q_SWITCHSTATE_GOSLEEP_ID           ( uint8 )( 0xA5U )
#define ECUM_Q_SWITCHSTATE_SLEEP_ID             ( uint8 )( 0xA6U )
#define ECUM_Q_SWITCHSTATE_GOOFFONE_ID          ( uint8 )( 0xA7U )
#define ECUM_Q_SWITCHSTATE_GOOFFTWO_ID          ( uint8 )( 0xA8U )
#endif /* ECUM_Q_FLEX */

#define ECUM_Q_STARTTIMER_ID                    ( uint8 )( 0xAAU )
#define ECUM_Q_CHECKTIMER_ID                    ( uint8 )( 0xABU )
#define ECUM_Q_STOPTIMER_ID                     ( uint8 )( 0xACU )
#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_Q_SETRUNMINDURATION_ID             ( uint8 )( 0xADU )
#define ECUM_Q_CHECKRUNMINDURATION_ID           ( uint8 )( 0xAEU )
#define ECUM_Q_SETNVMTIMEOUT_ID                 ( uint8 )( 0xAFU )
#define ECUM_Q_CHECKNVMTIMEOUT_ID               ( uint8 )( 0xB0U )

#define ECUM_Q_GETPREVSTATE_ID                  ( uint8 )( 0xB1U )
#endif /* ECUM_Q_FLEX */

#define ECUM_Q_CLEARPENDINGWAKEUPEVENTS_ID      ( uint8 )( 0xB2U )
#define ECUM_Q_SETPENDINGWAKEUPEVENTS_ID        ( uint8 )( 0xB3U )
#define ECUM_Q_CLEARVALIDATEDWAKEUPEVENTS_ID    ( uint8 )( 0xB4U )
#define ECUM_Q_SETVALIDATEDWAKEUPEVENTS_ID      ( uint8 )( 0xB5U )
#define ECUM_Q_CLEAREXPIREDWAKEUPEVENTS_ID      ( uint8 )( 0xB6U )
#define ECUM_Q_SETEXPIREDWAKEUPEVENTS_ID        ( uint8 )( 0xB7U )

#if ( ECUM_Q_FLEX == FALSE )
#define EcuM_Q_INITIALIZED_ID                   ( uint8 )( 0xB8U )
#define ECUM_Q_ISINITIALIZED_ID                 ( uint8 )( 0xB9U )

#define ECUM_Q_KILLALLRUNREQUESTED_ID           ( uint8 )( 0xBAU )
#define ECUM_Q_ENDKILLALLRUNREQUEST_ID          ( uint8 )( 0xBBU )
#define ECUM_Q_ISKILLALLRUNREQUESTED_ID         ( uint8 )( 0xBCU )

#define ECUM_Q_KILLALLPOSTRUNREQUESTED_ID       ( uint8 )( 0xD5U )
#define ECUM_Q_ENDKILLALLPOSTRUNREQUEST_ID      ( uint8 )( 0xD4U )
#define ECUM_Q_ISKILLALLPOSTRUNREQUESTED_ID     ( uint8 )( 0xD3U )

#define ECUM_Q_CHECKRUNREQUESTED_ID             ( uint8 )( 0xBEU )
#define ECUM_Q_CHECKPOSTRUNREQUESTED_ID         ( uint8 )( 0xBFU )
#define ECUM_Q_CHECKCOMMREQUESTED_ID            ( uint8 )( 0xC0U )

#define ECUM_Q_CLEARNVMJOBEND_ID                ( uint8 )( 0xC1U )
#define ECUM_Q_SETNVMJOBEND_ID                  ( uint8 )( 0xC2U )
#define ECUM_Q_ISNVMJOBEND_ID                   ( uint8 )( 0xC3U )
#endif /* ECUM_Q_FLEX */

#define ECUM_Q_SETLASTSHUTDOWNTARGET_ID         ( uint8 )( 0xC4U )

#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_Q_ALLCLEARRUNREQUESTED_ID          ( uint8 )( 0xC5U )
#define ECUM_Q_ALLCLEARPOSTRUNREQUESTED_ID      ( uint8 )( 0xC6U )
#endif /* ECUM_Q_FLEX */

#define ECUM_Q_GETSLEEPMODEREF_ID               ( uint8 )( 0xE2U )
#if ( ECUM_Q_FLEX != FALSE )
#define ECUM_Q_SETNVRAMBLOCK_ID                 ( uint8 )( 0xC7U )
#define ECUM_Q_INITALARMCLOCK_ID                ( uint8 )( 0xEBU )
#define ECUM_Q_GETNEXTPHASE_ID                  ( uint8 )( 0xEDU )
#endif /* ECUM_Q_FLEX */

/* Callout Definitions */
/* Generic Callouts */
#define ECUM_ERRORHOOK_ID                       ( uint8 )( 0x80U )
/* Callouts from STARTUP */
#if ( ECUM_Q_FLEX != FALSE )
#define ECUM_AL_SETPROGRAMMABLEINTERRUPTS_ID    ( uint8 )( 0xE8U )
#endif /* ECUM_Q_FLEX */
#define ECUM_AL_DRIVERINITZERO_ID               ( uint8 )( 0x81U )
#define ECUM_DETERMINEPBCONFIGURATION_ID        ( uint8 )( 0x82U )
#define ECUM_AL_DRIVERINITONE_ID                ( uint8 )( 0x83U )
#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_AL_DRIVERINITTWO_ID                ( uint8 )( 0x84U )
#define ECUM_AL_DRIVERINITTHREE_ID              ( uint8 )( 0x85U )
#define ECUM_ONRTESTARTUP_ID                    ( uint8 )( 0x86U )
/* Callouts from RUN State */
#define ECUM_ONENTERRUN_ID                      ( uint8 )( 0x87U )
#define ECUM_ONEXITRUN_ID                       ( uint8 )( 0x88U )
#define ECUM_ONEXITPOSTRUN_ID                   ( uint8 )( 0x89U )
/* Callouts from SHUTDOWN */
#define ECUM_ONPREPSHUTDOWN_ID                  ( uint8)(0x8AU)
#define ECUM_ONGOSLEEP_ID                       ( uint8)(0x8BU)
#endif /* ECUM_Q_FLEX */
#define ECUM_ONGOOFFONE_ID                      ( uint8)(0x8CU)
#define ECUM_ONGOOFFTWO_ID                      ( uint8)(0x8DU)
#define ECUM_ENABLEWAKEUPSOURCES_ID             ( uint8)(0x8EU)
#define ECUM_GENERATERAMHASH_ID                 ( uint8)(0x8FU)
#define ECUM_AL_SWITCHOFF_ID                    ( uint8)(0x90U)
#if ( ECUM_Q_FLEX != FALSE )
#define ECUM_AL_RESET_ID                        ( uint8)(0xE9U)
#endif /* ECUM_Q_FLEX */

/* Callouts from WAKEUP */
#define ECUM_CHECKRAMHASH_ID                    ( uint8 )( 0x91U )
#define ECUM_DISABLEWAKEUPSOURCES_ID            ( uint8 )( 0x92U )
#define ECUM_AL_DRIVERRESTART_ID                ( uint8 )( 0x93U )
#define ECUM_STARTWAKEUPSOURCES_ID              ( uint8 )( 0x94U )
#define ECUM_CHECKVALIDATION_ID                 ( uint8 )( 0x95U )
#define ECUM_STOPWAKEUPSOURCES_ID               ( uint8 )( 0x96U )
#define ECUM_ONWAKEUPREACTION_ID                ( uint8 )( 0x97U )
/* Callouts from SLEEP State */
#define ECUM_SLEEPACTIVITY_ID                   ( uint8 )( 0x98U )

#if (( ECUM_Q_FLEX == FALSE ) || (( ECUM_Q_FLEX != FALSE ) && ( ECUM_MODE_HANDLING != FALSE )))
#define STARTUP                        ( EcuM_StateType )( 0x00U )
#define RUN                            ( EcuM_StateType )( 0x01U )
#define POST_RUN                       ( EcuM_StateType )( 0x02U )
#define SLEEP                          ( EcuM_StateType )( 0x03U )
#if ( ECUM_Q_FLEX == FALSE )
#define WAKE_SLEEP                     ( EcuM_StateType )( 0x04U )
#endif /* ECUM_Q_FLEX == FALSE */
#define SHUTDOWN                       ( EcuM_StateType )( 0x05U )
#endif /* ( ECUM_Q_FLEX == FALSE ) || (( ECUM_Q_FLEX != FALSE ) && ( ECUM_MODE_HANDLING != FALSE )) */

#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_STATE_GoSleep                  ( EcuM_ModeType )( 0x49U )
#define ECUM_STATE_SleepWaitForNvMWriteAll  ( EcuM_ModeType )( 0x51U )
#define ECUM_STATE_GoOff1                   ( EcuM_ModeType )( 0x4EU )
#define ECUM_STATE_GoOff2                   ( EcuM_ModeType )( 0x4DU )
#endif /* ECUM_Q_FLEX */

/* SWS_EcuMf_047 EcuM_StateType(uint8)  EcuM_QINeS.currentStatus */
#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_Q_STATE_MASK               ( EcuM_StateType )( 0xF0U )
#endif /* ECUM_Q_FLEX == FALSE */
#define ECUM_SUBSTATE_MASK              ( EcuM_StateType )( 0x0FU )
#define ECUM_STATE_STARTUP              ( EcuM_StateType )( 0x10U )
#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_STATE_STARTUP_ONE          ( EcuM_StateType )( 0x11U )
#define ECUM_STATE_STARTUP_TWO          ( EcuM_StateType )( 0x12U )
#define ECUM_STATE_WAKEUP               ( EcuM_StateType )( 0x20U )
#define ECUM_STATE_WAKEUP_ONE           ( EcuM_StateType )( 0x21U )
#define ECUM_STATE_WAKEUP_VALIDATION    ( EcuM_StateType )( 0x22U )
#define ECUM_STATE_WAKEUP_REACTION      ( EcuM_StateType )( 0x23U )
#define ECUM_STATE_WAKEUP_TWO           ( EcuM_StateType )( 0x24U )
#define ECUM_STATE_WAKEUP_WAKESLEEP     ( EcuM_StateType )( 0x25U )
#define ECUM_STATE_WAKEUP_TTII          ( EcuM_StateType )( 0x26U )
#endif /* ECUM_Q_FLEX == FALSE */
#define ECUM_STATE_RUN                  ( EcuM_StateType )( 0x30U )
#define ECUM_STATE_APP_RUN              ( EcuM_StateType )( 0x32U )
#define ECUM_STATE_APP_POST_RUN         ( EcuM_StateType )( 0x33U )
#define ECUM_STATE_SHUTDOWN             ( EcuM_StateType )( 0x40U )
#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_STATE_PREP_SHUTDOWN        ( EcuM_StateType )( 0x44U )
#define ECUM_STATE_GO_SLEEP             ( EcuM_StateType )( 0x49U )
#define ECUM_STATE_GO_OFF_ONE           ( EcuM_StateType )( 0x4DU )
#define ECUM_STATE_GO_OFF_TWO           ( EcuM_StateType )( 0x4EU )
#endif /* ECUM_Q_FLEX == FALSE */
/* SWS_EcuMf_047 EcuM_StateType(uint8)  EcuM_QINeS.shutdownTarget */
#define ECUM_STATE_SLEEP                ( EcuM_StateType )( 0x50U )
#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_STATE_OFF                  ( EcuM_StateType )( 0x80U )
#define ECUM_STATE_RESET                ( EcuM_StateType )( 0x90U )
#else /* ECUM_Q_FLEX != FALSE */
#define ECUM_SHUTDOWN_TARGET_SLEEP      ( EcuM_ShutdownTargetType )( 0x00U )
#define ECUM_SHUTDOWN_TARGET_RESET      ( EcuM_ShutdownTargetType )( 0x01U )
#define ECUM_SHUTDOWN_TARGET_OFF        ( EcuM_ShutdownTargetType )( 0x02U )
#endif /* ECUM_Q_FLEX */


/* EcuM_WakeupSourceType SWS_EcuMf_049 */
#define ECUM_WKSOURCE_POWER             ( EcuM_WakeupSourceType )( 0x00000001UL )
#define ECUM_WKSOURCE_RESET             ( EcuM_WakeupSourceType )( 0x00000002UL )
#define ECUM_WKSOURCE_INTERNAL_RESET    ( EcuM_WakeupSourceType )( 0x00000004UL )
#define ECUM_WKSOURCE_INTERNAL_WDG      ( EcuM_WakeupSourceType )( 0x00000008UL )
#define ECUM_WKSOURCE_EXTERNAL_WDG      ( EcuM_WakeupSourceType )( 0x00000010UL )
#define ECUM_Q_WKSOURCE_NONE            ( EcuM_WakeupSourceType )( 0x00000000UL )
#define ECUM_Q_WKSOURCE_ALL_SOURCES     ( EcuM_WakeupSourceType )( 0xFFFFFFFFUL )

/* EcuM_WakeupStatusType SWS_EcuMf_050 EcuM4041 */
#define ECUM_WKSTATUS_NONE              ( EcuM_WakeupStatusType )( 0x00U )
#define ECUM_WKSTATUS_PENDING           ( EcuM_WakeupStatusType )( 0x01U )
#define ECUM_WKSTATUS_VALIDATED         ( EcuM_WakeupStatusType )( 0x02U )
#define ECUM_WKSTATUS_EXPIRED           ( EcuM_WakeupStatusType )( 0x03U )
#define ECUM_WKSTATUS_ENABLED           ( EcuM_WakeupStatusType )( 0x06U )

/* EcuM_WakeupReactionType SWS_EcuMf_051 */
#define ECUM_WKACT_RUN                  ( EcuM_WakeupReactionType )( 0x00U )
#define ECUM_WKACT_TTII                 ( EcuM_WakeupReactionType )( 0x02U )
#define ECUM_WKACT_SHUTDOWN             ( EcuM_WakeupReactionType )( 0x03U )

/* EcuM_BootTargetType SWS_EcuMf_00036 */
#define ECUM_BOOT_TARGET_APP            ( EcuM_BootTargetType )( 0x00U )
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER ( EcuM_BootTargetType )( 0x01U )
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER ( EcuM_BootTargetType )( 0x02U )

/* EcuM_ResetType EcuM4044 */
#define ECUM_RESET_MCU                  ( EcuM_ResetType )( 0x00U )
#define ECUM_RESET_WDG                  ( EcuM_ResetType )( 0x01U )
#define ECUM_RESET_IO                   ( EcuM_ResetType )( 0x02U )

/* EcuM_ShutdownCauseType EcuM4045 */
#define ECUM_CAUSE_UNKNOWN              ( EcuM_ShutdownCauseType )( 0x00U )
#define ECUM_CAUSE_ECU_STATE            ( EcuM_ShutdownCauseType )( 0x01U )
#define ECUM_CAUSE_WDGM                 ( EcuM_ShutdownCauseType )( 0x02U )
#define ECUM_CAUSE_DCM                  ( EcuM_ShutdownCauseType )( 0x03U )

#define ECUM_Q_GORUN                    ( EcuM_Q_NextPhaseType )( 0x00U )
#define ECUM_Q_GODOWN                   ( EcuM_Q_NextPhaseType )( 0x01U )
#define ECUM_Q_GOHALT                   ( EcuM_Q_NextPhaseType )( 0x02U )
#define ECUM_Q_GOPOLL                   ( EcuM_Q_NextPhaseType )( 0x03U )

/* length of RunRequested */
#define ECUM_Q_LENOF_RUNREQUESTED       ( 32U )

/* OsResource */
#define RES_AUTOSAR_ECUM                ( RES_SCHEDULER )

/* NvM Read/Write area */
#if ( ECUM_Q_FLEX != FALSE )
#define ECUM_Q_NVRAMSIZE ( 3 )
#else /* ECUM_Q_FLEX == FALSE */
#define ECUM_Q_NVRAMSIZE ( 2 )
#endif /* ECUM_Q_FLEX */

/* Dem Error */
/* It is described in Dem_Types */
#if ( ECUM_Q_FLEX == FALSE )
#define ECUM_E_RAM_CHECK_FAILED                  DemConf_DemEventParameter_ECUM_E_RAM_CHECK_FAILED
#define ECUM_E_CONFIGURATION_DATA_INCONSISTENT   DemConf_DemEventParameter_ECUM_E_CONFIGURATION_DATA_INCONSISTENT
#define ECUM_E_ALL_RUN_REQUESTS_KILLED           DemConf_DemEventParameter_ECUM_E_ALL_RUN_REQUESTS_KILLED
#endif /* ECUM_Q_FLEX */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
/* General */
#if ( ECUM_VERSION_INFO_API != FALSE )
void EcuM_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif
/* Initialization and Shutdown */
void EcuM_Init( void );
void EcuM_StartupTwo( void );
void EcuM_Shutdown( void );
#if ( ECUM_Q_FLEX != FALSE )
Std_ReturnType EcuM_GoDown( uint16 caller );
Std_ReturnType EcuM_GoHalt( void );
Std_ReturnType EcuM_GoPoll( void );
#endif /* ECUM_Q_FLEX */
#if ( ECUM_Q_FLEX == FALSE )
void EcuM_Q_Initialized( void );
bool_t EcuM_Q_IsInitialized( void );
#endif /* FIXED */

/* RUN Request */
#if ((ECUM_Q_FLEX == FALSE ) || (ECUM_Q_FLEX != FALSE ) && ( ECUM_MODE_HANDLING != FALSE ))
void EcuM_Q_AllClearRunRequested( void );
void EcuM_Q_AllClearPostRunRequested( void );
Std_ReturnType EcuM_RequestRUN( EcuM_UserType user );
Std_ReturnType EcuM_ReleaseRUN( EcuM_UserType user );
Std_ReturnType EcuM_RequestPOST_RUN( EcuM_UserType user );
Std_ReturnType EcuM_ReleasePOST_RUN( EcuM_UserType user );
bool_t EcuM_Q_CheckRunRequested( void );
bool_t EcuM_Q_CheckPostRunRequested( void );
#endif /* (ECUM_Q_FLEX == FALSE ) || (ECUM_Q_FLEX != FALSE ) && ( ECUM_MODE_HANDLING != FALSE ) */

#if ((ECUM_Q_FLEX != FALSE ) && ( ECUM_MODE_HANDLING != FALSE ))
bool_t EcuM_Q_GetAcceptRunRequestFlg( void );
void EcuM_SetState( EcuM_StateType state );
#endif /* (ECUM_Q_FLEX != FALSE ) && ( ECUM_MODE_HANDLING != FALSE ) */

#if ( ECUM_Q_FLEX == FALSE )
void EcuM_KillAllRUNRequests( void );
void EcuM_KillAllPostRUNRequests( void );
void EcuM_Q_KillAllRUNRequested( void );
void EcuM_Q_KillAllPostRUNRequested( void );
void EcuM_Q_EndKillAllRUNRequest( void );
void EcuM_Q_EndKillAllPostRUNRequest( void );
bool_t EcuM_Q_IsKillAllRUNRequested( void );
bool_t EcuM_Q_IsKillAllPostRUNRequested( void );
#if ( ECUM_Q_MOD_COMM_ENABLED != FALSE )
bool_t EcuM_Q_CheckComMRequested( void );
#endif /* ECUM_Q_MOD_COMM_ENABLED */
#endif /* FIXED */

/* Shutdown Target */
Std_ReturnType EcuM_Q_GetSleepModeRef( uint8 sleepModeId , ECUM_Q_CONST EcuM_SleepModeType** sleepModeRef );
#if ( ECUM_Q_FLEX == FALSE )
Std_ReturnType EcuM_SelectShutdownTarget( EcuM_StateType target, uint8 mode );
Std_ReturnType EcuM_GetShutdownTarget( EcuM_StateType* shutdownTarget, uint8* sleepMode );
Std_ReturnType EcuM_GetLastShutdownTarget( EcuM_StateType* shutdownTarget, uint8* sleepMode );
void EcuM_Q_SetLastShutdownTarget( void );
#else /* FIXED */
Std_ReturnType EcuM_SelectShutdownTarget(
    EcuM_ShutdownTargetType shutdownTarget, EcuM_ShutdownModeType shutdownMode );
Std_ReturnType EcuM_GetShutdownTarget(
    EcuM_ShutdownTargetType* shutdownTarget, EcuM_ShutdownModeType* shutdownMode );
Std_ReturnType EcuM_GetLastShutdownTarget(
    EcuM_ShutdownTargetType* shutdownTarget, EcuM_ShutdownModeType* shutdownMode );
Std_ReturnType EcuM_SelectShutdownCause( EcuM_ShutdownCauseType shutdownCause );
Std_ReturnType EcuM_GetShutdownCause( EcuM_ShutdownCauseType* shutdownCause );
#endif /* ECUM_Q_FLEX */

/* Wakeup Alarm */
#if ( ECUM_Q_FLEX != FALSE )
Std_ReturnType EcuM_SetRelWakeupAlarm( EcuM_UserType user, EcuM_TimeType time );
Std_ReturnType EcuM_SetAbsWakeupAlarm( EcuM_UserType user, EcuM_TimeType time );
Std_ReturnType EcuM_AbortWakeupAlarm( EcuM_UserType user );
Std_ReturnType EcuM_GetCurrentTime( EcuM_TimeType* time );
Std_ReturnType EcuM_GetWakeupTime( EcuM_TimeType* time );
Std_ReturnType EcuM_SetClock( EcuM_UserType user, EcuM_TimeType time );
#endif /* ECUM_Q_FLEX */

/* Timer */
#if ( ECUM_Q_FLEX != FALSE )
void EcuM_Q_StartTimer( EcuM_TimeType timeoutTime );
#else /* ECUM_Q_FLEX != FALSE */
void EcuM_Q_StartTimer( uint32 timeoutTime );
#endif /* ECUM_Q_FLEX == FALSE */
#if ( ECUM_Q_FLEX != FALSE )
void EcuM_Q_InitAlarmClock( void );
#endif /* ECUM_Q_FLEX */
bool_t EcuM_Q_CheckTimer( void );
void EcuM_Q_StopTimer( void );
#if ( ECUM_Q_FLEX == FALSE )
void EcuM_Q_SetRunMinDuration( void );
bool_t EcuM_Q_CheckRunMinDuration( void );
void EcuM_Q_SetNvMTimeout( EcuM_Q_NvMType type );
bool_t EcuM_Q_CheckNvMTimeout( void );
#endif /* FIXED */

#if ( ECUM_Q_FLEX == FALSE )
Std_ReturnType EcuM_GetState( EcuM_StateType* state );
#endif /* ECUM_Q_FLEX */

/* Wake up Handling */
EcuM_WakeupSourceType EcuM_GetPendingWakeupEvents( void );
void EcuM_ClearWakeupEvent( EcuM_WakeupSourceType sources );
EcuM_WakeupSourceType EcuM_GetValidatedWakeupEvents( void );
EcuM_WakeupSourceType EcuM_GetExpiredWakeupEvents( void );
void EcuM_Q_ClearPendingWakeupEvents( EcuM_WakeupSourceType sources );
void EcuM_Q_SetPendingWakeupEvents( EcuM_WakeupSourceType sources );
void EcuM_Q_ClearValidatedWakeupEvents( EcuM_WakeupSourceType sources );
void EcuM_Q_SetValidatedWakeupEvents( EcuM_WakeupSourceType sources );
void EcuM_Q_ClearExpiredWakeupEvents( EcuM_WakeupSourceType sources );
void EcuM_Q_SetExpiredWakeupEvents( EcuM_WakeupSourceType sources );
#if ( ECUM_Q_FLEX == FALSE )
EcuM_WakeupStatusType EcuM_GetStatusOfWakeupSource(
    EcuM_WakeupSourceType sources );
void EcuM_StartCheckWakeup( EcuM_WakeupSourceType WakeupSource );
void EcuM_EndCheckWakeup( EcuM_WakeupSourceType WakeupSource );
#endif /* FIXED */

/* BootTarget */
Std_ReturnType EcuM_SelectBootTarget( EcuM_BootTargetType target );
Std_ReturnType EcuM_GetBootTarget( EcuM_BootTargetType * target );

/* Scheduled Functions */
void EcuM_MainFunction( void );

/* State Processing */
#if ( ECUM_Q_FLEX == FALSE )
void EcuM_Q_SwitchState_StartupOne( void );
void EcuM_Q_SwitchState_StartupTwo( void );
void EcuM_Q_SwitchState_AppRun( void );
void EcuM_Q_SwitchState_AppPostRun( void );
void EcuM_Q_SwitchState_PrepShutdown( void );
void EcuM_Q_SwitchState_WakeupOne( void );
void EcuM_Q_SwitchState_WakeupValidation( void );
void EcuM_Q_SwitchState_WakeupReaction( void );
void EcuM_Q_SwitchState_WakeupTwo( void );
void EcuM_Q_SwitchState_WakeupTTII( void );
void EcuM_Q_SwitchState_GoSleep( void );
void EcuM_Q_SwitchState_Sleep( void );
void EcuM_Q_SwitchState_GoOffOne( void );
void EcuM_Q_SwitchState_GoOffTwo( void );

Std_ReturnType EcuM_Q_GetPrevState( EcuM_StateType* state );
#endif /* ECUM_Q_FLEX */

/* NvM Job Processing */
#if ( ECUM_Q_FLEX == FALSE )
void EcuM_Q_ClearNvMJobEnd( void );
void EcuM_Q_SetNvMJobEnd( void );
bool_t EcuM_Q_IsNvMJobEnd( void );
#endif /* FIXED */
#if ( ECUM_Q_FLEX != FALSE )
void EcuM_Q_SetNvramBlock( void );
EcuM_Q_NextPhaseType EcuM_Q_GetNextPhase( void );
#endif /* ECUM_Q_FLEX */

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

#endif /* ECUM_H */

/* EOF EcuM.h *****************************************************************/
