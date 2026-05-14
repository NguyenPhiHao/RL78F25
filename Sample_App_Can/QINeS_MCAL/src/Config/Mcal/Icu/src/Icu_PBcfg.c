/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu_PBcfg.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : Icu post build time configuration                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ICU Driver                                                */
/* R22-11                                                                     */


/*----------------------------------------------------------------------------*/
/* include header                                                             */
/*----------------------------------------------------------------------------*/
#include "Icu_Cfg.h"
#include "Icu.h"

extern void Icu_SampleCallbackFunctionTAU( void );
extern void Icu_SampleCallbackFunctionINTP( void );

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ICU_70_VENDOR_ID_PBCFG_C                      (70U)
#define ICU_70_MODULE_ID_PBCFG_C                      (122U)

#define ICU_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (22U)
#define ICU_70_AR_RELEASE_MINOR_VERSION_PBCFG_C       (11U)
#define ICU_70_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0U)

#define ICU_70_SW_MAJOR_VERSION_PBCFG_C               (1U)
#define ICU_70_SW_MINOR_VERSION_PBCFG_C               (0U)
#define ICU_70_SW_PATCH_VERSION_PBCFG_C               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Icu_Cfg.h version check start */

#if ( ICU_70_VENDOR_ID_PBCFG_C != ICU_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Icu_PBcfg.c and Icu_Cfg.h are different"
#endif

#if ( ICU_70_MODULE_ID_PBCFG_C != ICU_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Icu_PBcfg.c and Icu_Cfg.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != ICU_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != ICU_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != ICU_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_PBcfg.c and Icu_Cfg.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_PBCFG_C != ICU_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( ICU_70_SW_MINOR_VERSION_PBCFG_C != ICU_70_SW_MINOR_VERSION_CFG_H ) || \
      ( ICU_70_SW_PATCH_VERSION_PBCFG_C != ICU_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Icu_PBcfg.c and Icu_Cfg.h are different"

#endif

/* Icu_Cfg.h version check end */

/* Icu.h version check start */

#if ( ICU_70_VENDOR_ID_PBCFG_C != ICU_VENDOR_ID )
    #error "VENDOR ID for Icu_PBcfg.c and Icu.h are different"
#endif

#if ( ICU_70_MODULE_ID_PBCFG_C != ICU_MODULE_ID )
    #error "MODULE ID for Icu_PBcfg.c and Icu.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != ICU_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != ICU_AR_RELEASE_MINOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != ICU_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Icu_PBcfg.c and Icu.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_PBCFG_C != ICU_SW_MAJOR_VERSION ) || \
      ( ICU_70_SW_MINOR_VERSION_PBCFG_C != ICU_SW_MINOR_VERSION ) || \
      ( ICU_70_SW_PATCH_VERSION_PBCFG_C != ICU_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Icu_PBcfg.c and Icu.h are different"
#endif

/* Icu.h version check end */

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
/* IcuSignalEdgeDetection  */ /* [ECUC_Icu_00021] */
static const Icu_SignalEdgeDetectionType IcuSignalEdgeDetectionConf [ICU_MAX_CHANNEL] = {
    {
        NULL_PTR
    },
    {
        NULL_PTR
    },
    {
        NULL_PTR
    },
    {
        NULL_PTR
    },
    {
        NULL_PTR
    },
    {
        Icu_SampleCallbackFunctionINTP
    }
};

/* IcuTimestampMeasurement */ /* [ECUC_Icu_00228] */
static const Icu_TimestampMeasurementType IcuTimestampMeasurementConf [ICU_MAX_CHANNEL] = {
    {
        ICU_LINEAR_BUFFER,              /* IcuTimestampMeasurementProperty */
        Icu_SampleCallbackFunctionTAU   /* IcuTimestampNotification        */
    },
    {
        ICU_LINEAR_BUFFER,              /* IcuTimestampMeasurementProperty */
        NULL_PTR                        /* IcuTimestampNotification        */
    },
    {
        ICU_LINEAR_BUFFER,              /* IcuTimestampMeasurementProperty */
        NULL_PTR                        /* IcuTimestampNotification        */
    },
    {
        ICU_LINEAR_BUFFER,              /* IcuTimestampMeasurementProperty */
        NULL_PTR                        /* IcuTimestampNotification        */
    },
    {
        ICU_LINEAR_BUFFER,              /* IcuTimestampMeasurementProperty */
        NULL_PTR                        /* IcuTimestampNotification        */
    },
    {
        ICU_LINEAR_BUFFER,              /* IcuTimestampMeasurementProperty */
        NULL_PTR                        /* IcuTimestampNotification        */
    }
};
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

#define ICU_START_SEC_CONFIG_DATA_8
#include "Icu_MemMap.h"
/* IcuSignalMeasurement    */ /* [ECUC_Icu_00226] */
static const Icu_SignalMeasurementType IcuSignalMeasurementConf [ICU_MAX_CHANNEL] = {
    {
        ICU_HIGH_TIME
    },
    {
        ICU_LOW_TIME
    },
    {
        ICU_PERIOD_TIME
    },
    {
        ICU_DUTY_CYCLE
    },
    {
        ICU_HIGH_TIME
    },
    {
        ICU_HIGH_TIME
    }
};
#define ICU_STOP_SEC_CONFIG_DATA_8
#include "Icu_MemMap.h"

#define ICU_START_SEC_CONFIG_DATA_32
#include "Icu_MemMap.h"
/* IcuWakeup               */ /* [ECUC_Icu_00126] */
static const  Icu_WakeupType  IcuWakeupConf [ICU_MAX_CHANNEL] = {
    {
        0x00000011UL /* IcuChannelWakeupInfo            */
    },
    {
        0x00000012UL  /* IcuChannelWakeupInfo            */
    },
    {
        0x00000013UL  /* IcuChannelWakeupInfo            */
    },
    {
        0x00000000UL /* IcuChannelWakeupInfo            */
    },
    {
        0x00000000UL /* IcuChannelWakeupInfo            */
    },
    {
        0x00000016UL /* IcuChannelWakeupInfo            */
    }
};
#define ICU_STOP_SEC_CONFIG_DATA_32
#include "Icu_MemMap.h"

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
static const Icu_70_RL78F2X_TAU_SettingConfType IcuSettingConf0 = {
    ICU_70_INPUT_TAU,                   /* timerType */
    7U,                                 /* chNo */
    (Mcl_70_RL78F2X_TAU_ContRegType*)MCL_70_RL78F2X_TAU_TAU07_CONT_ADR,   /* contPtr */
    (Mcl_70_RL78F2X_TAU_FixRegType*)MCL_70_RL78F2X_TAU_TAU0_FIX_ADR,      /* fixPtr */
    (Icu_70_RL78F2X_TAU_NfenRegType*)MCL_70_RL78F2X_TAU_NFEN1_ADR,        /* tauNfenReg */
    (Icu_70_RL78F2X_TAU_TdrRegType*)MCL_70_RL78F2X_TAU_TDR07_ADR,         /* tauTDrReg  */
    MCL_70_RL78F2X_TAU_TMR_CK1,         /* set operation clock        */
#if ( ICU_SET_MODE_API != FALSE)
    ICU_70_RL78F2X_MK2L_ADR,     /* Generate address of MKxL or MKxH where TAU interrupt source located */
    0x04U,                        /* Generate the bit location of TAU interrupt source */
#endif
    ICU_70_TIMER_TAU0              /* tauUnit */

};
static const Icu_70_RL78F2X_TAU_SettingConfType IcuSettingConf1 = {
    ICU_70_INPUT_TAU,                   /* timerType */
    7U,                                 /* chNo */
    (Mcl_70_RL78F2X_TAU_ContRegType*)MCL_70_RL78F2X_TAU_TAU17_CONT_ADR,   /* contPtr */
    (Mcl_70_RL78F2X_TAU_FixRegType*)MCL_70_RL78F2X_TAU_TAU1_FIX_ADR,      /* fixPtr */
    (Icu_70_RL78F2X_TAU_NfenRegType*)NULL_PTR,              /* tauNfenReg */
    (Icu_70_RL78F2X_TAU_TdrRegType*)MCL_70_RL78F2X_TAU_TDR17_ADR,         /* tauTDrReg  */
    MCL_70_RL78F2X_TAU_TMR_CK1,         /* set operation clock        */
#if ( ICU_SET_MODE_API != FALSE)
    ICU_70_RL78F2X_MK3H_ADR,      /* Generate address of MKxL or MKxH where TAU interrupt source located */
    0x08U,                        /* Generate the bit location of TAU interrupt source */
#endif
    ICU_70_TIMER_TAU1              /* tauUnit */
};
static const Icu_70_RL78F2X_TRD_SettingConfType IcuSettingConf2 = {
    ICU_70_INPUT_TRD,                    /* timerType  */
    ICU_70_TIMER_TRD_CH0,                /* chNo       */
    (Mcl_70_RL78F2X_TRD_ContRegType*)MCL_70_RL78F2X_TRD_TRD00_CONT_ADR,   /* contPtr */
    (Mcl_70_RL78F2X_TRD_FixRegType*)MCL_70_RL78F2X_TRD_TRD0_FIX_ADR,      /* fixPtr */
    ICU_70_TRDIOB,                       /* Input Port */
    ICU_70_TRDCR_TCK_FTRD8_MASK,         /* trdTrdCrData */
    (Icu_70_RL78F2X_TRD_TrddfRegType*)MCL_70_RL78F2X_TRD_TRDDF0_ADR,      /* TRD filter OFF */
#if ( ICU_SET_MODE_API != FALSE)
    ICU_70_RL78F2X_MK0H_ADR,      /* Generate address of MKxL or MKxH where TRD0 interrupt source located */
    0x08U                         /* Generate the bit location of TRD0 interrupt source */
#endif
};
static const Icu_70_RL78F2X_TRD_SettingConfType IcuSettingConf3 = {
    ICU_70_INPUT_TRD,                    /* timerType  */
    ICU_70_TIMER_TRD_CH1,                /* chNo       */
    (Mcl_70_RL78F2X_TRD_ContRegType*)MCL_70_RL78F2X_TRD_TRD01_CONT_ADR,   /* contPtr */
    (Mcl_70_RL78F2X_TRD_FixRegType*)MCL_70_RL78F2X_TRD_TRD0_FIX_ADR,      /* fixPtr */
    ICU_70_TRDIOA,                       /* Input Port */
    ICU_70_TRDCR_TCK_FTRD8_MASK,         /* trdTrdCrData */
    (Icu_70_RL78F2X_TRD_TrddfRegType*)NULL_PTR,               /* TRD filter OFF */
#if ( ICU_SET_MODE_API != FALSE)
    ICU_70_RL78F2X_MK0H_ADR,      /* Generate address of MKxL or MKxH where TRD0 interrupt source located */
    0x10U                         /* Generate the bit location of TRD0 interrupt source */
#endif
};
static const Icu_70_RL78F2X_INTP_SettingConfType IcuSettingConf4 = {  
    /*  RL78F2X HW specific information */
    ICU_70_INPUT_INTP,
    ICU_70_INTP4,                        /* intp channel */
    /* channel No is bigger than 7, set EGP1 addr */
    (Icu_70_RL78F2X_INTP_EgpRegType*)MCL_70_RL78F2X_INT_EGP0_ADR,
    /* channel No is bigger than 7, set EGN1 addr */
    (Icu_70_RL78F2X_INTP_EgnRegType*)MCL_70_RL78F2X_INT_EGN0_ADR
};
static const Icu_70_RL78F2X_INTP_SettingConfType IcuSettingConf5 = {  
    /*  RL78F2X HW specific information */
    ICU_70_INPUT_INTP,
    ICU_70_INTP13,                        /* intp channel */
    /* channel No is bigger than 7, set EGP1 addr */
    (Icu_70_RL78F2X_INTP_EgpRegType*)MCL_70_RL78F2X_INT_EGP1_ADR,
    /* channel No is bigger than 7, set EGN1 addr */
    (Icu_70_RL78F2X_INTP_EgnRegType*)MCL_70_RL78F2X_INT_EGN1_ADR
};


static const Icu_IcuChannelType  IcuChannelData [ICU_MAX_CHANNEL] = {
    {    /* IcuChannelData[0] */
        ICU_CHANNEL_0,                            /* IcuChannel                      */
        ICU_RISING_EDGE,                          /* IcuDefaultStartEdge             */
        ICU_MODE_TIMESTAMP,                       /* IcuMeasurementMode              */
        TRUE,                                     /* IcuWakeupCapability             */
        /* IcuSignalEdgeDetection */
        (const Icu_SignalEdgeDetectionType *)&(IcuSignalEdgeDetectionConf[0U]),
        /* IcuSignalMeasurement */
        (const Icu_SignalMeasurementType *)&(IcuSignalMeasurementConf[0U]),
        /* IcuTimestampMeasurement */
        (const Icu_TimestampMeasurementType *)&(IcuTimestampMeasurementConf[0U]),
        /* IcuWakeup               */
        (const Icu_WakeupType *)&(IcuWakeupConf[0U]),
        /* IcuSettingConfig */
        (const Icu_70_HW_SetConfType*)&(IcuSettingConf0)  /*  RL78F2X HW specific information */
    },
    {    /* IcuChannelData[1] */
        ICU_CHANNEL_1,                            /* IcuChannel                      */
        ICU_BOTH_EDGES,                           /* IcuDefaultStartEdge             */
        ICU_MODE_SIGNAL_MEASUREMENT,              /* IcuMeasurementMode              */
        TRUE,                                     /* IcuWakeupCapability             */
        /* IcuSignalEdgeDetection */
        (const Icu_SignalEdgeDetectionType *)&(IcuSignalEdgeDetectionConf[1U]),
        /* IcuSignalMeasurement */
        (const Icu_SignalMeasurementType *)&(IcuSignalMeasurementConf[1U]),
        /* IcuTimestampMeasurement */
        (const Icu_TimestampMeasurementType *)&(IcuTimestampMeasurementConf[1U]),
        /* IcuWakeup               */
        (const Icu_WakeupType *)&(IcuWakeupConf[1U]),
        /* IcuSettingConfig */
        (const Icu_70_HW_SetConfType*)&(IcuSettingConf1)  /*  RL78F2X HW specific information */
    },
    {    /* IcuChannelData[2] */
        ICU_CHANNEL_2,                            /* IcuChannel                      */
        ICU_BOTH_EDGES,                           /* IcuDefaultStartEdge             */
        ICU_MODE_SIGNAL_MEASUREMENT,              /* IcuMeasurementMode              */
        TRUE,                                     /* IcuWakeupCapability             */
        /* IcuSignalEdgeDetection */
        (const Icu_SignalEdgeDetectionType *)&(IcuSignalEdgeDetectionConf[2U]),
        /* IcuSignalMeasurement */
        (const Icu_SignalMeasurementType *)&(IcuSignalMeasurementConf[2U]),
        /* IcuTimestampMeasurement */
        (const Icu_TimestampMeasurementType *)&(IcuTimestampMeasurementConf[2U]),
        /* IcuWakeup               */
        (const Icu_WakeupType *)&(IcuWakeupConf[2U]),
        /* IcuSettingConfig */
        (const Icu_70_HW_SetConfType*)&(IcuSettingConf2)  /*  RL78F2X HW specific information */
    },
    {    /* IcuChannelData[3] */
        ICU_CHANNEL_3,                            /* IcuChannel                      */
        ICU_RISING_EDGE,                          /* IcuDefaultStartEdge             */
        ICU_MODE_SIGNAL_MEASUREMENT,              /* IcuMeasurementMode              */
        FALSE,                                    /* IcuWakeupCapability             */
        /* IcuSignalEdgeDetection */
        (const Icu_SignalEdgeDetectionType *)&(IcuSignalEdgeDetectionConf[3U]),
        /* IcuSignalMeasurement */
        (const Icu_SignalMeasurementType *)&(IcuSignalMeasurementConf[3U]),
        /* IcuTimestampMeasurement */
        (const Icu_TimestampMeasurementType *)&(IcuTimestampMeasurementConf[3U]),
        /* IcuWakeup               */
        (const Icu_WakeupType *)&(IcuWakeupConf[3U]),
        /* IcuSettingConfig */
        (const Icu_70_HW_SetConfType*)&(IcuSettingConf3)  /*  RL78F2X HW specific information */
    },
    {    /* IcuChannelData[4] */
        ICU_CHANNEL_4,                            /* IcuChannel                      */
        ICU_BOTH_EDGES,                           /* IcuDefaultStartEdge             */
        ICU_MODE_EDGE_COUNTER,                    /* IcuMeasurementMode              */
        FALSE,                                    /* IcuWakeupCapability             */
        /* IcuSignalEdgeDetection */
        (const Icu_SignalEdgeDetectionType *)&(IcuSignalEdgeDetectionConf[4U]),
        /* IcuSignalMeasurement */
        (const Icu_SignalMeasurementType *)&(IcuSignalMeasurementConf[4U]),
        /* IcuTimestampMeasurement */
        (const Icu_TimestampMeasurementType *)&(IcuTimestampMeasurementConf[4U]),
        /* IcuWakeup               */
        (const Icu_WakeupType *)&(IcuWakeupConf[4U]),
        /* IcuSettingConfig */
        (const Icu_70_HW_SetConfType*)&(IcuSettingConf4)  /*  RL78F2X HW specific information */
    },
    {    /* IcuChannelData[5] */
        ICU_CHANNEL_5,                            /* IcuChannel                      */
        ICU_FALLING_EDGE,                         /* IcuDefaultStartEdge             */
        ICU_MODE_SIGNAL_EDGE_DETECT,              /* IcuMeasurementMode              */
        TRUE,                                     /* IcuWakeupCapability             */
        /* IcuSignalEdgeDetection */
        (const Icu_SignalEdgeDetectionType *)&(IcuSignalEdgeDetectionConf[5U]),
        /* IcuSignalMeasurement */
        (const Icu_SignalMeasurementType *)&(IcuSignalMeasurementConf[5U]),
        /* IcuTimestampMeasurement */
        (const Icu_TimestampMeasurementType *)&(IcuTimestampMeasurementConf[5U]),
        /* IcuWakeup               */
        (const Icu_WakeupType *)&(IcuWakeupConf[5U]),
        /* IcuSettingConfig */
        (const Icu_70_HW_SetConfType*)&(IcuSettingConf5)  /*  RL78F2X HW specific information */
    }
};

const Icu_ConfigType  Icu_Config = {
    {
        ICU_MAX_CHANNEL,
        &(IcuChannelData[0U])
    }
};

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"


/* EOF Icu_PBcfg.c *******************************************************/
