/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt_PBcfg.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : Gpt post build time configuration                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of GPT Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Gpt_Cfg.h"
#include "Gpt.h"
#include "SampleGpt.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_PBCFG_C                      ( 70U )
#define GPT_70_MODULE_ID_PBCFG_C                      ( 100U )

#define GPT_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C       ( 22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_PBCFG_C       ( 11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_PBCFG_C    ( 0U )

#define GPT_70_SW_MAJOR_VERSION_PBCFG_C               ( 1U )
#define GPT_70_SW_MINOR_VERSION_PBCFG_C               ( 0U )
#define GPT_70_SW_PATCH_VERSION_PBCFG_C               ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Gpt_Cfg.h version check start */

#if ( GPT_70_VENDOR_ID_PBCFG_C != GPT_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Gpt_PBcfg.c and Gpt_Cfg.h are different"
#endif

#if ( GPT_70_MODULE_ID_PBCFG_C != GPT_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Gpt_PBcfg.c and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != GPT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_PBcfg.c and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_SW_MAJOR_VERSION_PBCFG_C != GPT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_MINOR_VERSION_PBCFG_C != GPT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_PATCH_VERSION_PBCFG_C != GPT_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Gpt_PBcfg.c and Gpt_Cfg.h are different"
#endif

/* Gpt_Cfg.h version check end */
 
/* Gpt.h version check start */

#if ( GPT_70_VENDOR_ID_PBCFG_C != GPT_VENDOR_ID )
    #error "VENDOR ID for Gpt_PBcfg.c and Gpt.h are different"
#endif

#if ( GPT_70_MODULE_ID_PBCFG_C != GPT_MODULE_ID )
    #error "MODULE ID for Gpt_PBcfg.c and Gpt.h are different"
#endif

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != GPT_AR_RELEASE_MAJOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != GPT_AR_RELEASE_MINOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != GPT_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_PBcfg.c and Gpt.h are different"
#endif

#if ( ( GPT_70_SW_MAJOR_VERSION_PBCFG_C != GPT_SW_MAJOR_VERSION ) || \
      ( GPT_70_SW_MINOR_VERSION_PBCFG_C != GPT_SW_MINOR_VERSION ) || \
      ( GPT_70_SW_PATCH_VERSION_PBCFG_C != GPT_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Gpt_PBcfg.c and Gpt.h are different"
#endif

/* Gpt.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* DATA                                                                       */
/*----------------------------------------------------------------------------*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
static const Gpt_WakeupConfigurationType GptWakeupConfigurationData[ GPT_70_NUM_OF_GPTWAKEUPCONF ] = {
    {
        ( void( * )( void ) )( TRJ0Notification ),  /* [ECUC_Gpt_00235] GptWakeupNotification        */
        0x00000020UL                /* [ECUC_Gpt_00313] GptWakeupSourceRef           */
    }
};
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */

/* Idx0 : GPT_70_CH_MAIN1MS_TIMER : TAU Unit1 CH4 */
static const Gpt_70_RL78F2X_TAU_SettingConfType GptTimerSettingConf0 = {
    GPT_70_RL78F2X_TIMERTYPE_TAU,       /* timerType */
    1U,                                 /* unitNo */
    4U,                                 /* chNo */
    ( Mcl_70_RL78F2X_TAU_ContRegType* )MCL_70_RL78F2X_TAU_TAU14_CONT_ADR,   /* contPtr */
    ( Mcl_70_RL78F2X_TAU_FixRegType* )MCL_70_RL78F2X_TAU_TAU1_FIX_ADR,      /* fixPtr */
    MCL_70_RL78F2X_TAU_TDR14_ADR,       /* tauTDrReg */
    MCL_70_RL78F2X_TAU_TMR_CK0|MCL_70_RL78F2X_TAU_TMR_CCS0      /* tauTmrData */
};

/* Idx1 : GPT_70_CH_WAKEUP : TRJ Unit0 CH0 */
static const Gpt_70_RL78F2X_TRJ_SettingConfType GptTimerSettingConf1 = {
    GPT_70_RL78F2X_TIMERTYPE_TRJ,       /* timerType */
    0U,                                 /* unitNo */
    0U,                                 /* chNo */
    ( Mcl_70_RL78F2X_TRJ_ContRegType* )MCL_70_RL78F2X_TRJ_TRJ00_CONT_ADR,   /*  contPtr */
    MCL_70_RL78F2X_TRJ_TRJ00_ADR,       /* trjPtr */
    MCL_70_RL78F2X_TRJ_TRJMR_TCK_FSL    /* trjTrjMrData */
};

/* Idx2 : GPT_70_CH_WDGDRV_TIMER : TAU Unit0 CH6 */
static const Gpt_70_RL78F2X_TAU_SettingConfType GptTimerSettingConf2 = {
    GPT_70_RL78F2X_TIMERTYPE_TAU,       /* timerType */
    0U,                                 /* unitNo */
    6U,                                 /* chNo */
    ( Mcl_70_RL78F2X_TAU_ContRegType* )MCL_70_RL78F2X_TAU_TAU06_CONT_ADR,   /* contPtr */
    ( Mcl_70_RL78F2X_TAU_FixRegType* )MCL_70_RL78F2X_TAU_TAU0_FIX_ADR,      /* fixPtr */
    MCL_70_RL78F2X_TAU_TDR06_ADR,       /* tauTDrReg */
    MCL_70_RL78F2X_TAU_TMR_CK2|MCL_70_RL78F2X_TAU_TMR_CCS0      /* tauTmrData */
};

/* Idx3 : GPT_70_CH_SAMPLE_TAU : TAU Unit0 CH1 */
static const Gpt_70_RL78F2X_TAU_SettingConfType GptTimerSettingConf3 = {
    GPT_70_RL78F2X_TIMERTYPE_TAU,       /* timerType */
    0U,                                 /* unitNo */
    1U,                                 /* chNo */
    ( Mcl_70_RL78F2X_TAU_ContRegType* )MCL_70_RL78F2X_TAU_TAU01_CONT_ADR,   /* contPtr */
    ( Mcl_70_RL78F2X_TAU_FixRegType* )MCL_70_RL78F2X_TAU_TAU0_FIX_ADR,      /* fixPtr */
    MCL_70_RL78F2X_TAU_TDR01_ADR,       /* tauTDrReg */
    MCL_70_RL78F2X_TAU_TMR_CK0|MCL_70_RL78F2X_TAU_TMR_CCS0          /* tauTmrData */
};

/* Idx4 : GPT_70_CH_SAMPLE_TRD : TRD Unit0 CH1 */
static const Gpt_70_RL78F2X_TRD_SettingConfType GptTimerSettingConf4 = {
    GPT_70_RL78F2X_TIMERTYPE_TRD,       /* timerType */
    0U,                                 /* unitNo */
    1U,                                 /* chNo */
    ( Mcl_70_RL78F2X_TRD_ContRegType* )MCL_70_RL78F2X_TRD_TRD01_CONT_ADR,   /* contPtr */
    ( Mcl_70_RL78F2X_TRD_FixRegType* )MCL_70_RL78F2X_TRD_TRD0_FIX_ADR,      /* fixPtr */
    MCL_70_RL78F2X_TRD_TRDCR_TCK_FTRD   /* trdTrdCrData */
};

#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )

#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
/* configuration for 1us predef timer */
#if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE )
/* GPT_70_CH_PREDEF_1US : TRD Unit0 CH0 */
static const Gpt_70_RL78F2X_TRD_SettingConfType GptTimerSettingConf1us = {
    GPT_70_RL78F2X_TIMERTYPE_TRD,       /* timerType */
    0U,                                 /* unitNo */
    0U,                                 /* chNo */
    ( Mcl_70_RL78F2X_TRD_ContRegType* )MCL_70_RL78F2X_TRD_TRD00_CONT_ADR,   /* contPtr */
    ( Mcl_70_RL78F2X_TRD_FixRegType* )MCL_70_RL78F2X_TRD_TRD0_FIX_ADR,      /* fixPtr */
    MCL_70_RL78F2X_TRD_TRDCR_TCK_FTRD   /* trdTrdCrData */
};
#endif /* #if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) */

/* GPT_70_CH_PREDEF_LOWER : TAU Unit0 CH0 */
static const Gpt_70_RL78F2X_TAU_SettingConfType GptTimerSettingConfLower = {
    GPT_70_RL78F2X_TIMERTYPE_TAU,       /* timerType */
    0U,                                 /* unitNo */
    0U,                                 /* chNo */
    ( Mcl_70_RL78F2X_TAU_ContRegType* )MCL_70_RL78F2X_TAU_TAU00_CONT_ADR,   /* contPtr */
    ( Mcl_70_RL78F2X_TAU_FixRegType* )MCL_70_RL78F2X_TAU_TAU0_FIX_ADR,      /* fixPtr */
    MCL_70_RL78F2X_TAU_TDR00_ADR,       /* tauTDrReg */
    MCL_70_RL78F2X_TAU_TMR_CK2|MCL_70_RL78F2X_TAU_TMR_CCS1      /* tauTmrData */
};
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */

#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */

static const Gpt_ChannelConfigurationType GptChannelConfigurationData[ GPT_70_NUM_OF_GPTCHANNELCONF ] = {  
    { /* Idx0 : GPT_70_CH_MAIN1MS_TIMER : TAU Unit1 CH4 */
        GPT_70_CH_MAIN1MS_TIMER,            /* GptChannelId                 */
        GPT_CH_MODE_CONTINUOUS,             /* GptChannelMode               */
        GPT_70_CHANNEL_TICK_VALUE_MAX,      /* GptChannelTickValueMax       */
        FALSE,                              /* GptEnableWakeup              */
        ( void( * )( void ) )( main1ms ),   /* GptNotification              */
#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
        NULL_PTR,                           /* GptWakeupConfiguration       */
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
                                            /* Gpt_70_TimerSettingConfPtr   */
        ( const Gpt_70_HW_Timer_SettingConfType* )&( GptTimerSettingConf0 )
    },
    { /* Idx1 : GPT_70_CH_WAKEUP : TRJ Unit0 CH0 */
        GPT_70_CH_WAKEUP,                   /* GptChannelId                 */
        GPT_CH_MODE_CONTINUOUS,             /* GptChannelMode               */
        GPT_70_CHANNEL_TICK_VALUE_MAX,      /* GptChannelTickValueMax       */
        TRUE,                               /* GptEnableWakeup              */
        NULL_PTR,                           /* GptNotification              */
#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
        &( GptWakeupConfigurationData[0] ), /* GptWakeupConfiguration       */
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
                                            /* Gpt_70_TimerSettingConfPtr   */
        ( const Gpt_70_HW_Timer_SettingConfType* )&( GptTimerSettingConf1 )
    },
    { /* Idx2 : GPT_70_CH_WDGDRV_TIMER : TAU Unit0 CH6 */
        GPT_70_CH_WDGDRV_TIMER,             /* GptChannelId                 */
        GPT_CH_MODE_CONTINUOUS,             /* GptChannelMode               */
        GPT_70_CHANNEL_TICK_VALUE_MAX,      /* GptChannelTickValueMax       */
        FALSE,                              /* GptEnableWakeup              */
        NULL_PTR,                           /* GptNotification              */
#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
        NULL_PTR,                           /* GptWakeupConfiguration       */
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
                                            /* Gpt_70_TimerSettingConfPtr   */
        ( const Gpt_70_HW_Timer_SettingConfType* )&( GptTimerSettingConf2 )
    },
    { /* Idx3 : GPT_70_CH_SAMPLE_TAU : TAU Unit0 CH1 */
        GPT_70_CH_SAMPLE_TAU,                 /* GptChannelId                 */
        GPT_CH_MODE_CONTINUOUS,             /* GptChannelMode               */
        GPT_70_CHANNEL_TICK_VALUE_MAX,      /* GptChannelTickValueMax       */
        FALSE,                              /* GptEnableWakeup              */
        ( void( * )( void ) )( TAU01Notification ), /* GptNotification      */
#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
        NULL_PTR,                           /* GptWakeupConfiguration       */
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
                                            /* Gpt_70_TimerSettingConfPtr   */
        ( const Gpt_70_HW_Timer_SettingConfType* )&( GptTimerSettingConf3 )
    },
    { /* Idx4 : GPT_70_CH_SAMPLE_TRD : TRD Unit0 CH1 */
        GPT_70_CH_SAMPLE_TRD,                 /* GptChannelId                 */
        GPT_CH_MODE_CONTINUOUS,             /* GptChannelMode               */
        GPT_70_CHANNEL_TICK_VALUE_MAX,      /* GptChannelTickValueMax       */
        FALSE,                              /* GptEnableWakeup              */
        ( void( * )( void ) )( TRD01Notification ), /* GptNotification      */
#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
        NULL_PTR,                           /* GptWakeupConfiguration       */
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
                                            /* Gpt_70_TimerSettingConfPtr   */
        ( const Gpt_70_HW_Timer_SettingConfType* )&( GptTimerSettingConf4 )
    }
};

#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
static const Gpt_70_RL78F2X_PredefTimerConfType GptPredefTimerConfigData = {
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
    /* configuration for 1us predef timer */
    /* for 1us 16/24/32bit predef timer */
#if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE )
                                                        /* channelConf1us */
    ( const Gpt_70_HW_RL78F2X_SettingConfType* )&( GptTimerSettingConf1us ),
    ( Gpt_ValueType )80U,                               /* timerValue1us */
    ( uint8 )MCL_70_RL78F2X_ELC_ELSELR_INTTRD0A,        /* elcElselrIdxLower */
    ( uint8 )MCL_70_RL78F2X_ELC_ELSELR_TAU00,           /* elcElselrValueLower */
#endif /* #if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) */
                                                        /* channelConfLower */
    ( const Gpt_70_HW_RL78F2X_SettingConfType* )&( GptTimerSettingConfLower ),
#if ( GPT_70_PREDEF_1US_USE_ELC != FALSE )
    GPT_70_RL78F2X_TAU00_ELC                            /* tis0Value */
#endif/* #if ( GPT_70_PREDEF_1US_USE_ELC != FALSE ) */
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED )
    /* no 1us 24/32bit predef timer */
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED ) */
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */
#if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE )
    /* 100us predef timer is not support. */
#endif /* #if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) */
};
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */

const Gpt_ConfigType Gpt_Config = {
    /* GptChannelConfigSet */
    {                              
        GPT_70_NUM_OF_GPTCHANNELCONF,
        &( GptChannelConfigurationData[0] )   /* [ECUC_Gpt_00269] */
    },
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
    /* GptDriverConfiguration */
    {
                                                        /* GptPredefTimerConfPtr   */
        ( const Gpt_70_HW_PredefTimerConfType* )&( GptPredefTimerConfigData )   /* [ECUC_Gpt_00183] */
    }
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
};

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/* EOF Gpt_PBcfg.c ***********************************************************/
