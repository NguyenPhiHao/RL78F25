/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_Cfg.h                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : Adc configuration header                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef ADC_CFG_H__
#define ADC_CFG_H__

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_CFG_H                      (70U)
#define ADC_70_MODULE_ID_CFG_H                      (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_CFG_H       (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_CFG_H       (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_CFG_H    (0U)

#define ADC_70_SW_MAJOR_VERSION_CFG_H               (1U)
#define ADC_70_SW_MINOR_VERSION_CFG_H               (0U)
#define ADC_70_SW_PATCH_VERSION_CFG_H               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_CFG_H    != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_CFG_H    != STD_TYPES_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Adc_Cfg.h and Std_Types.h are different"
#endif

/* Std_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/* non AUITOSAR compile switch */

#define ADC_DEV_ERROR_DETECT            (TRUE)          /* [ECUC_Adc_00405] */
#define ADC_DEINIT_API                  (TRUE)          /* [ECUC_Adc_00404] */
#define ADC_ENABLE_START_STOP_GROUP_API (TRUE)          /* [ECUC_Adc_00406] */
#define ADC_READ_GROUP_API              (TRUE)          /* [ECUC_Adc_00394] */
#define ADC_VERSION_INFO_API            (TRUE)          /* [ECUC_Adc_00409] */
#define ADC_GRP_NOTIF_CAPABILITY        (TRUE)          /* [ECUC_Adc_00105] */
#define ADC_HW_TRIGGER_API              (TRUE)          /* [ECUC_Adc_00408] */

#define ADC_70_HWUNIT_INTERNAL          (0U)            /* internal ADC HW unit 1 */

                                                        /* for internal ADC HW unit 1 */
#define ADC_70_HW1_NUM_OF_CHANNEL       (8U)            /* number of channel definitions. */
#define ADC_70_HW1_NUM_OF_GROUP         (10U)            /* number of group definitions. */

#define ADC_70_MAX_NUM_OF_GROUP         (ADC_70_HW1_NUM_OF_GROUP)  /* maximum number of group definitions. */

/* --- define group index ---------------------------------------------------- */
#define AdcConf_AdcGroup_AdcGroup_0     ( (Adc_GroupType)0x00U )
#define AdcConf_AdcGroup_AdcGroup_1     ( (Adc_GroupType)0x01U )
#define AdcConf_AdcGroup_AdcGroup_2     ( (Adc_GroupType)0x02U )
#define AdcConf_AdcGroup_AdcGroup_3     ( (Adc_GroupType)0x03U )
#define AdcConf_AdcGroup_AdcGroup_4     ( (Adc_GroupType)0x04U )
#define AdcConf_AdcGroup_AdcGroup_5     ( (Adc_GroupType)0x05U )
#define AdcConf_AdcGroup_AdcGroup_6     ( (Adc_GroupType)0x06U )
#define AdcConf_AdcGroup_AdcGroup_7     ( (Adc_GroupType)0x07U )
#define AdcConf_AdcGroup_AdcGroup_8     ( (Adc_GroupType)0x08U )
#define AdcConf_AdcGroup_AdcGroup_9     ( (Adc_GroupType)0x09U )

/* --- define channel number on the group ------------------------------------ */
#define ADC_70_GRP_CH_NUM_0         ( 3U )
#define ADC_70_GRP_CH_NUM_1         ( 1U )
#define ADC_70_GRP_CH_NUM_2         ( 1U )
#define ADC_70_GRP_CH_NUM_3         ( 3U )
#define ADC_70_GRP_CH_NUM_4         ( 3U )
#define ADC_70_GRP_CH_NUM_5         ( 3U )
#define ADC_70_GRP_CH_NUM_6         ( 1U )
#define ADC_70_GRP_CH_NUM_7         ( 3U )
#define ADC_70_GRP_CH_NUM_8         ( 3U )
#define ADC_70_GRP_CH_NUM_9         ( 1U )

/* --- define sampling number on the group ----------------------------------- */
#define ADC_70_STREAMING_SAMPLE_NUM_GRP_0   ( 3U )
#define ADC_70_STREAMING_SAMPLE_NUM_GRP_1   ( 1U )
#define ADC_70_STREAMING_SAMPLE_NUM_GRP_2   ( 1U )
#define ADC_70_STREAMING_SAMPLE_NUM_GRP_3   ( 1U )
#define ADC_70_STREAMING_SAMPLE_NUM_GRP_4   ( 1U )
#define ADC_70_STREAMING_SAMPLE_NUM_GRP_5   ( 3U )
#define ADC_70_STREAMING_SAMPLE_NUM_GRP_6   ( 3U )
#define ADC_70_STREAMING_SAMPLE_NUM_GRP_7   ( 1U )
#define ADC_70_STREAMING_SAMPLE_NUM_GRP_8   ( 3U )
#define ADC_70_STREAMING_SAMPLE_NUM_GRP_9   ( 3U )

/* --- define register setting ----------------------------------------------- */
/* A/D High-/Low-potential Reference Voltage Control Register */
/* configuration tool will calcurate register setting value from AdcChannelRefVoltsrcHigh and AdcChannelRefVoltsrcLow? */
#define ADC_70_RL78F2X_ADHVREFCNT_CFG   ( ( uint8 ) ADC_70_RL78F2X_VOLT_HIGH_REFP |( uint8 ) ADC_70_RL78F2X_VOLT_LOW_REFM )

/* A/D Sampling State Register */
/* configuration tool will calcurate sampling state register setting value from AdcChannelSampTime */
#define ADC_70_RL78F2X_ADSSTRL_CFG      ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTRO_CFG      ( ( uint8 ) 0xFFU )
#define ADC_70_RL78F2X_ADSSTR0_CFG      ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR1_CFG      ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR2_CFG      ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR3_CFG      ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR4_CFG      ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR5_CFG      ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR6_CFG      ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR7_CFG      ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR8_CFG      ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR9_CFG      ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR10_CFG     ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR11_CFG     ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR12_CFG     ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR13_CFG     ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR14_CFG     ( ( uint8 ) 0x06U )
#define ADC_70_RL78F2X_ADSSTR15_CFG     ( ( uint8 ) 0x06U )

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

#endif      /* #ifndef ADC_CFG_H__ */

/* EOF Adc_Cfg.h **************************************************************/
