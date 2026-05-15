/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_70_Types.h                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : ADC Module type definition header                            */
/*               The ADC is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
#ifndef ADC_70_TYPES_H_
#define ADC_70_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc_Cfg.h"
#include "Adc_70_HW_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_TYPES_H                      (70U)
#define ADC_70_MODULE_ID_TYPES_H                      (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_TYPES_H       (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_TYPES_H       (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_TYPES_H    (0U)

#define ADC_70_SW_MAJOR_VERSION_TYPES_H               (1U)
#define ADC_70_SW_MINOR_VERSION_TYPES_H               (0U)
#define ADC_70_SW_PATCH_VERSION_TYPES_H               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Adc_Cfg.h version check start */
#if ( ADC_70_VENDOR_ID_TYPES_H != ADC_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Adc_70_Types.h and Adc_Cfg.h are different"
#endif

#if ( ADC_70_MODULE_ID_TYPES_H != ADC_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Adc_70_Types.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != ADC_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != ADC_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_TYPES_H != ADC_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Adc_70_Types.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_TYPES_H != ADC_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( ADC_70_SW_MINOR_VERSION_TYPES_H != ADC_70_SW_MINOR_VERSION_CFG_H ) || \
      ( ADC_70_SW_PATCH_VERSION_TYPES_H != ADC_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Adc_70_Types.h and Adc_Cfg.h are different"
#endif
/* Adc_Cfg.h version check end */

/* Adc_70_HW_Types.h version check start */
#if ( ADC_70_VENDOR_ID_TYPES_H != ADC_70_VENDOR_ID_HW_TYPES_H )
    #error "VENDOR ID for Adc_70_Types.h and Adc_70_HW_Types.h are different"
#endif

#if ( ADC_70_MODULE_ID_TYPES_H != ADC_70_MODULE_ID_HW_TYPES_H )
    #error "MODULE ID for Adc_70_Types.h and Adc_70_HW_Types.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_TYPES_H \
        != ADC_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H ) \
    || ( ADC_70_AR_RELEASE_MINOR_VERSION_TYPES_H \
        != ADC_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H ) \
    || ( ADC_70_AR_RELEASE_REVISION_VERSION_TYPES_H \
        != ADC_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H ) )
    #error "AUTOSAR Version Numbers of Adc_70_Types.h and Adc_70_HW_Types.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_TYPES_H != ADC_70_SW_MAJOR_VERSION_HW_TYPES_H ) || \
      ( ADC_70_SW_MINOR_VERSION_TYPES_H != ADC_70_SW_MINOR_VERSION_HW_TYPES_H ) || \
      ( ADC_70_SW_PATCH_VERSION_TYPES_H != ADC_70_SW_PATCH_VERSION_HW_TYPES_H ) \
    )
    #error "Software Version Numbers of Adc_70_Types.h and Adc_70_HW_Types.h are different"
#endif
/* Adc_70_HW_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* number of ADC HW unit. */
#define ADC_70_NUM_OF_HWUNIT            (ADC_70_HW_NUM_OF_HWUNIT)
/* no HW unit */
#define ADC_70_HWUNIT_NONE              (255U)

/*----------------------------------------------------------------------------*/
/* type definitions (AUTOSAR)                                                 */
/*----------------------------------------------------------------------------*/
/* 8.2.2 Adc_ChannelType : Numeric ID of an ADC channel. */
typedef uint16 Adc_ChannelType;

/* 8.2.3 Adc_GroupType : Numeric ID of an ADC channel group.*/
typedef uint16 Adc_GroupType;

/* 8.2.4 Adc_ValueGroupType : Type for reading the converted values of a channel group */
typedef uint16  Adc_ValueGroupType;

/* 8.2.5 Adc_PrescaleType : Type of clock prescaler factor. */
typedef Adc_70_HW_PrescaleType Adc_PrescaleType;

/* 8.2.9 Adc_StatusType : Current status of the conversion of the requested ADC Channel group. */
typedef enum {
    ADC_IDLE                            = (0U),
    ADC_BUSY                            = (1U),
    ADC_COMPLETED                       = (2U),
    ADC_STREAM_COMPLETED                = (3U)
} Adc_StatusType;

/* 8.2.10 Adc_TriggerSourceType : Type for configuring the trigger source for an ADC Channel group. */
typedef Adc_70_HW_TriggerSourceType Adc_TriggerSourceType;

/* 8.2.11 Adc_GroupConvModeType : Type for configuring the conversion mode of an ADC Channel group. */
typedef enum {
    ADC_CONV_MODE_ONESHOT               = (0U), /* [SWS_Adc_00380] */
    ADC_CONV_MODE_CONTINUOUS            = (1U)  /* [SWS_Adc_00381] */
} Adc_GroupConvModeType;

/* 8.2.14 Adc_StreamNumSampleType : */
/*  Type for configuring the number of group conversions in streaming access mode */
typedef uint8 Adc_StreamNumSampleType;

/* 8.2.15 Adc_StreamBufferModeType : Type for configuring the streaming access mode buffer type. */
typedef enum {
    ADC_70_STREAM_BUFFER_NONE           = (0U),
    ADC_STREAM_BUFFER_LINEAR            = (1U),
    ADC_STREAM_BUFFER_CIRCULAR          = (2U)
} Adc_StreamBufferModeType;

/* 8.2.16 Adc_GroupAccessModeType : Type for configuring the access mode to group conversion results. */
typedef enum {
    ADC_ACCESS_MODE_SINGLE              = (0U),
    ADC_ACCESS_MODE_STREAMING           = (1U)
} Adc_GroupAccessModeType;

typedef uint8 Adc_70_HwUnitIdType;

typedef uint8 Adc_70_IntGrpIdType;

/* [ECUC_Adc_00268] 10.2.5 AdcChannel{AdcChannelConfiguration} */
typedef struct {
    Adc_ChannelType                 AdcChannelId;               /* [ECUC_Adc_00392] ID of channel. */
} Adc_ChannelConfigurationType;

/* [ECUC_Adc_00028] 10.2.6 AdcGroup{AdcGroupConfiguration} */
typedef struct {
    Adc_GroupType                       AdcGroupId;                 /* [ECUC_Adc_00398] ID of group */
    Adc_TriggerSourceType               AdcGroupTriggSrc;           /* [ECUC_Adc_00399] Trigger Type  */
    Adc_GroupAccessModeType             AdcGroupAccessMode;         /* [ECUC_Adc_00317] SINGLE or STREAMING */
    Adc_GroupConvModeType               AdcGroupConversionMode;     /* [ECUC_Adc_00397] ONESHOT or CONTINUOUS */
    void(*AdcNotification)(void);                                   /* [ECUC_Adc_00402] Notification function */
    Adc_StreamBufferModeType            AdcStreamingBufferMode;     /* [ECUC_Adc_00316] LINER, CIRCULAR or NONE */
    Adc_StreamNumSampleType             AdcStreamingNumSamples;     /* [ECUC_Adc_00292] Samples number of stream */
    uint16                              AdcNumOfGroupDefinition;    /* Number of AdcGroupDefinition */
    const Adc_ChannelConfigurationType* const *             AdcGroupDefinition;         /* [ECUC_Adc_00014] Channels list of group */
    const Adc_70_HW_GroupConfigType*    Adc_70_GroupConfig;         /* Hardware Specific Group config Data */
    bool_t                              Adc_70_implicitlyStop;      /* [QINeS_SWS_ADC_00010] can be implicitly stopped */
} Adc_GroupConfigurationType;

/* [ECUC_Adc_00242] 10.2.7 AdcHwUnit */
typedef struct {
    Adc_70_HwUnitIdType                 AdcHwUnitId;            /* [ECUC_Adc_00389] ID of HW */
    Adc_PrescaleType                    AdcPrescale;            /* [ECUC_Adc_00088] Prescale parameter of clock */
    uint16                              AdcNumOfAdcChannel;     /* Number of AdcChannel */
    const Adc_ChannelConfigurationType* AdcChannel;             /* Channels definition list */
    uint16                              AdcNumOfAdcGroup;       /* Number of AdcGroup */
    const Adc_GroupConfigurationType*   AdcGroup;               /* Groups definition list */
} Adc_HwUnitType;

/* [ECUC_Adc_00390] 10.2.3 AdcConfigSet */
typedef struct {
    uint8                           AdcNumOfHwAdcUnit;      /* number of AdcHwUnit */
    const Adc_HwUnitType*           AdcHwUnit;              /* HW unit configuration list */
} Adc_ConfigSetType;

/* 8.2.1 Adc_ConfigType */
typedef struct {
    const Adc_ConfigSetType         AdcConfigSet;
} Adc_ConfigType;

/*----------------------------------------------------------------------------*/
/* type definitions (NON-AUTOSAR)                                             */
/*----------------------------------------------------------------------------*/

/* workarea for group. */
typedef struct {
    Adc_70_HwUnitIdType                 hwunitId;           /* hardware unit id */
    const Adc_GroupConfigurationType*   groupDef;           /* group definition */
#if ( ADC_GRP_NOTIF_CAPABILITY != FALSE)
    bool_t                              notificationEnable; /* flag of notification  enable*/
#endif /* #if ( ADC_GRP_NOTIF_CAPABILITY != FALSE) */
    Adc_StreamNumSampleType             validSamples;       /* complete samples in group    */
    Adc_StreamNumSampleType             curSample;          /* index for cur sample         */
    Adc_StatusType                      status;             /* group status                 */
    Adc_ValueGroupType*                 resultBuffer;       /* result buffer                */
    Adc_ValueGroupType*                 lastPtr;            /* last pointer of group buffer */
} Adc_70_GroupInfoType;

/* workarea for HW unit. */
typedef struct {
    const Adc_HwUnitType*           hwUnitDef;              /* HW unit definition */
    Adc_70_GroupInfoType*           execGroup;              /* current conversion group information */
} Adc_70_HwInfoType;

/* workarea for HW trigger source */
typedef enum {
    ADC_HW_TRIG_SRC_INTTM01         = (1U),
    ADC_HW_TRIG_SRC_INTRTC          = (2U),
    ADC_HW_TRIG_SRC_INTTRJ0         = (3U),
    ADC_HW_TRIG_SRC_INTTRD0_IFA     = (4U),
    ADC_HW_TRIG_SRC_INTTRD0_IFB     = (5U),
    ADC_HW_TRIG_SRC_INTTRD1_IFA     = (6U),
    ADC_HW_TRIG_SRC_INTTRD1_IFB     = (7U),
    ADC_HW_TRIG_SRC_INTTRD1_UDF     = (8U),
    ADC_HW_TRIG_SRC_INTTRD_ADTRG    = (11U),
    ADC_HW_TRIG_SRC_ELCTRG0         = (48U)
} Adc_HwTrigSrcType;

typedef struct {
    const Adc_HwTrigSrcType hwtrigsrc;
    bool_t                  istriggered;
} Adc_HwTrigSrcMngType;

/*----------------------------------------------------------------------------*/
/* External Variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototypes                                                        */
/*----------------------------------------------------------------------------*/

#endif /* #define ADC_70_TYPES_H_ */

/* EOF Adc_70_Types.h *********************************************************/
