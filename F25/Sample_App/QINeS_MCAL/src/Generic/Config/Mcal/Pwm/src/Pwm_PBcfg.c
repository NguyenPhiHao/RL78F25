/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Pwm_PBcfg.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : Pwm post build time configuration                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of PWM Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include header                                                             */
/*----------------------------------------------------------------------------*/
#include "Pwm.h"

/*----------------------------------------------------------------------------*/
/* Source File Version Infromation                                            */
/*----------------------------------------------------------------------------*/
#define PWM_70_VENDOR_ID_PBCFG_C                      (70U)
#define PWM_70_MODULE_ID_PBCFG_C                      (121U)

#define PWM_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (22U)
#define PWM_70_AR_RELEASE_MINOR_VERSION_PBCFG_C       (11U)
#define PWM_70_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0U)

#define PWM_70_SW_MAJOR_VERSION_PBCFG_C               (1U)
#define PWM_70_SW_MINOR_VERSION_PBCFG_C               (0U)
#define PWM_70_SW_PATCH_VERSION_PBCFG_C               (0U)

/*----------------------------------------------------------------------------*/
/* File version check                                                         */
/*----------------------------------------------------------------------------*/
/* Pwm.h version check start */
#if ( PWM_70_VENDOR_ID_PBCFG_C != PWM_VENDOR_ID )
    #error "VENDOR ID for Pwm_PBcfg.c and Pwm.h is different"
#endif

#if ( PWM_70_MODULE_ID_PBCFG_C != PWM_MODULE_ID )
    #error "MODULE ID for Pwm_PBcfg.c and Pwm.h is different"
#endif

#if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != PWM_AR_RELEASE_MAJOR_VERSION )  || \
      ( PWM_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != PWM_AR_RELEASE_MINOR_VERSION )  || \
      ( PWM_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != PWM_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Pwm_PBcfg.c and Pwm.h are different"
#endif

#if ( ( PWM_70_SW_MAJOR_VERSION_PBCFG_C != PWM_SW_MAJOR_VERSION ) || \
      ( PWM_70_SW_MINOR_VERSION_PBCFG_C != PWM_SW_MINOR_VERSION ) || \
      ( PWM_70_SW_PATCH_VERSION_PBCFG_C != PWM_SW_PATCH_VERSION ) )
    #error "Software Version Numbers of Pwm_PBcfg.c and Pwm.h are different"
#endif
/* Pwm.h version check end */

/*----------------------------------------------------------------------------*/
/*  const data declarations                                                   */
/*----------------------------------------------------------------------------*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/* Channel configuration for TAU and TRD */
/* TAU Unit0 */
static const Pwm_70_RL78F2X_TAU_RegInfoType Pwm_70_RL78F2X_TAU00_RegInfo =
{   /* PWM_CHANNEL_A0 master channel */
    ( Mcl_70_RL78F2X_TAU_ContRegType* ) MCL_70_RL78F2X_TAU_TAU00_CONT_ADR,
    ( Mcl_70_RL78F2X_TAU_FixRegType* ) MCL_70_RL78F2X_TAU_TAU0_FIX_ADR,
    MCL_70_RL78F2X_TAU_TDR00_ADR            /* address of TDR register */
};

static const Pwm_70_RL78F2X_TAU_RegInfoType Pwm_70_RL78F2X_TAU01_RegInfo =
{   /* PWM_CHANNEL_A0 slave channel */
    ( Mcl_70_RL78F2X_TAU_ContRegType* ) MCL_70_RL78F2X_TAU_TAU01_CONT_ADR,
    ( Mcl_70_RL78F2X_TAU_FixRegType* ) MCL_70_RL78F2X_TAU_TAU0_FIX_ADR,
    MCL_70_RL78F2X_TAU_TDR01_ADR            /* address of TDR register */
};

/* TAU Unit1 */
static const Pwm_70_RL78F2X_TAU_RegInfoType Pwm_70_RL78F2X_TAU10_RegInfo =
{   /* PWM_CHANNEL_B0 master channel */
    ( Mcl_70_RL78F2X_TAU_ContRegType* ) MCL_70_RL78F2X_TAU_TAU10_CONT_ADR,
    ( Mcl_70_RL78F2X_TAU_FixRegType* ) MCL_70_RL78F2X_TAU_TAU1_FIX_ADR,
    MCL_70_RL78F2X_TAU_TDR10_ADR            /* address of TDR register */
};

static const Pwm_70_RL78F2X_TAU_RegInfoType Pwm_70_RL78F2X_TAU11_RegInfo =
{   /* PWM_CHANNEL_B0 slave channel */
    ( Mcl_70_RL78F2X_TAU_ContRegType* ) MCL_70_RL78F2X_TAU_TAU11_CONT_ADR,
    ( Mcl_70_RL78F2X_TAU_FixRegType* ) MCL_70_RL78F2X_TAU_TAU1_FIX_ADR,
    MCL_70_RL78F2X_TAU_TDR11_ADR            /* address of TDR register */
};

/* TRDe */
static const Pwm_70_RL78F2X_TRD_RegInfoType Pwm_70_RL78F2X_TRD0_RegInfo =
{   /* PWM_CHANNEL_TRD0 channel */
    ( Mcl_70_RL78F2X_TRD_ContRegType* ) MCL_70_RL78F2X_TRD_TRD00_CONT_ADR,
    ( Mcl_70_RL78F2X_TRD_FixRegType* ) MCL_70_RL78F2X_TRD_TRD0_FIX_ADR,
     NULL_PTR
};

/* TAU0 ch0-1 */
static const Pwm_70_RL78F2X_TAU_ConfType Pwm_70_RL78F2X_TAU_SettingConf_A0 =
{
    0U,                                 /* CKS Selector                              */
    PWM_70_RL78F2X_TIMERTYPE_TAU,       /* timerType                                 */
    PWM_70_RL78F2X_TAU_UNIT_0,          /* unitId                                    */
    PWM_70_RL78F2X_TAU_PHCH_ID_0,       /* masterChId                                */
    &( Pwm_70_RL78F2X_TAU00_RegInfo ),
    &( Pwm_70_RL78F2X_TAU01_RegInfo )
};

/* TAU1 ch0-1 */
static const Pwm_70_RL78F2X_TAU_ConfType Pwm_70_RL78F2X_TAU_SettingConf_B0 =
{
    0U,                                 /* CKS Selector                              */
    PWM_70_RL78F2X_TIMERTYPE_TAU,       /* timerType                                 */
    PWM_70_RL78F2X_TAU_UNIT_1,          /* unitId                                    */
    PWM_70_RL78F2X_TAU_PHCH_ID_0,       /* masterChId                                */
    &( Pwm_70_RL78F2X_TAU10_RegInfo ),
    &( Pwm_70_RL78F2X_TAU11_RegInfo )
};

/* TRD0 ch0 */
static const Pwm_70_RL78F2X_TRD_ConfType Pwm_70_RL78F2X_TRD_SettingConf_TRD0 =
{
    0U,                                 /* Not use in TRD. Please set it to 0 in TRD */
    PWM_70_RL78F2X_TIMERTYPE_TRD,       /* timerType                                 */
    PWM_70_RL78F2X_TRD_UNIT_0,          /* unitId                                    */
    PWM_70_RL78F2X_TRD_PHCH_ID_0,       /* masterChId                                */
    &( Pwm_70_RL78F2X_TRD0_RegInfo ),
    &( Pwm_70_RL78F2X_TRD0_RegInfo )
};

static const Pwm_ChannelConfigType PwmChannels[PWM_70_NUM_OF_PWMCHANNEL] = {
    {
        PWM_VARIABLE_PERIOD,                       /* PwmChannelClass           */
        ( Pwm_ChannelType )PWM_70_CH_A0,           /* PwmChannelId              */
        0x2000U,                                   /* PwmDutycycleDefault       */
        PWM_LOW,                                   /* PwmIdleState              */
        SamplePwm_Notification_TAU_A0,             /* PwmNotification function  */
        0x04E2U,                                   /* PwmPeriodDefault          */
        PWM_HIGH,                                  /* PwmPolarity               */
        NULL_PTR,                                  /* PwmMcuClockReferencePoint */
        ( const Pwm_70_HW_ConfigType* )&( Pwm_70_RL78F2X_TAU_SettingConf_A0 ),
    },
    {
        PWM_VARIABLE_PERIOD,                       /* PwmChannelClass           */
        ( Pwm_ChannelType )PWM_70_CH_B0,           /* PwmChannelId              */
        0x6000U,                                   /* PwmDutycycleDefault       */
        PWM_LOW,                                   /* PwmIdleState              */
        NULL_PTR,                                  /* PwmNotification function  */
        0x9C40U,                                   /* PwmPeriodDefault          */
        PWM_HIGH,                                  /* PwmPolarity               */
        NULL_PTR,                                  /* PwmMcuClockReferencePoint */
        ( const Pwm_70_HW_ConfigType* )&( Pwm_70_RL78F2X_TAU_SettingConf_B0 ),
    },
    {
        PWM_VARIABLE_PERIOD,                       /* PwmChannelClass           */
        ( Pwm_ChannelType )PWM_70_CH_TRD00,        /* PwmChannelId              */
        0x2000U,                                   /* PwmDutycycleDefault       */
        PWM_LOW,                                   /* PwmIdleState              */
        SamplePwm_Notification_TRD_00,             /* PwmNotification function  */
        0x9C40U,                                   /* PwmPeriodDefault          */
        PWM_HIGH,                                  /* PwmPolarity               */
        NULL_PTR,                                  /* PwmMcuClockReferencePoint */
        ( const Pwm_70_HW_ConfigType* )&( Pwm_70_RL78F2X_TRD_SettingConf_TRD0 ),
    },
};

static const Pwm_ChannelConfigSetType PwmChannelConfigSet = {
    &(PwmChannels[0])
};

const Pwm_ConfigType Pwm_Config = {
    &PwmChannelConfigSet
};

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/* EOF Pwm_PBcfg.c ************************************************************/
