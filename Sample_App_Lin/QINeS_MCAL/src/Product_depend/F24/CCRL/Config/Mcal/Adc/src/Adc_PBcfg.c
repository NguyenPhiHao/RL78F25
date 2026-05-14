/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_PBcfg.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : Adc post build time configuration                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC                                                       */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_PBCFG_C                      (70U)
#define ADC_70_MODULE_ID_PBCFG_C                      (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_PBCFG_C       (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0U)

#define ADC_70_SW_MAJOR_VERSION_PBCFG_C               (1U)
#define ADC_70_SW_MINOR_VERSION_PBCFG_C               (0U)
#define ADC_70_SW_PATCH_VERSION_PBCFG_C               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Adc.h version check start */
#if ( ADC_70_VENDOR_ID_PBCFG_C != ADC_VENDOR_ID )
    #error "VENDOR ID for Adc_PBcfg.c and Adc.h are different"
#endif

#if ( ADC_70_MODULE_ID_PBCFG_C != ADC_MODULE_ID )
    #error "MODULE ID for Adc_PBcfg.c and Adc.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != ADC_AR_RELEASE_MAJOR_VERSION ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != ADC_AR_RELEASE_MINOR_VERSION ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != ADC_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Adc_PBcfg.c and Adc.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_PBCFG_C != ADC_SW_MAJOR_VERSION ) || \
      ( ADC_70_SW_MINOR_VERSION_PBCFG_C != ADC_SW_MINOR_VERSION ) || \
      ( ADC_70_SW_PATCH_VERSION_PBCFG_C != ADC_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Adc_PBcfg.c and Adc.h are different"
#endif
/* Adc.h version check end */

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external definition                                                        */
/*----------------------------------------------------------------------------*/
extern void SampleAdc_GroupNotification_1( void );
extern void SampleAdc_GroupNotification_2( void );

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

static const Adc_ChannelConfigurationType Adc_70_Hw1Channel[ADC_70_HW1_NUM_OF_CHANNEL] = {
    {   /* Idx=00 */
        (Adc_ChannelType)ADC_70_RL78F2X_CH_ID_A1   /* AdcChannelId */
    },
    {   /* Idx=01 */
        (Adc_ChannelType)ADC_70_RL78F2X_CH_ID_A3   /* AdcChannelId */
    },
    {   /* Idx=02 */
        (Adc_ChannelType)ADC_70_RL78F2X_CH_ID_A4   /* AdcChannelId */
    },
    {   /* Idx=03 */
        (Adc_ChannelType)ADC_70_RL78F2X_CH_ID_VBGR /* AdcChannelId */
    },
    {   /* Idx=04 */
        (Adc_ChannelType)ADC_70_RL78F2X_CH_ID_A5   /* AdcChannelId */
    },
    {   /* Idx=05 */
        (Adc_ChannelType)ADC_70_RL78F2X_CH_ID_A8   /* AdcChannelId */
    },
    {   /* Idx=06 */
        (Adc_ChannelType)ADC_70_RL78F2X_CH_ID_A15  /* AdcChannelId */
    },
    {   /* Idx=07 */
        (Adc_ChannelType)ADC_70_RL78F2X_CH_ID_A28  /* AdcChannelId */
    }
};

#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONST_8
#include "Adc_MemMap.h"

/* Channel Id's of groups */
static const Adc_ChannelConfigurationType* const Adc_70_GroupChannelList_0[ADC_70_GRP_CH_NUM_0] = {
    &Adc_70_Hw1Channel[0],
    &Adc_70_Hw1Channel[1],
    &Adc_70_Hw1Channel[2]
};

static const Adc_ChannelConfigurationType* const Adc_70_GroupChannelList_1[ADC_70_GRP_CH_NUM_1] = {
    &Adc_70_Hw1Channel[0]
};

static const Adc_ChannelConfigurationType* const Adc_70_GroupChannelList_2[ADC_70_GRP_CH_NUM_2] = {
    &Adc_70_Hw1Channel[3]
};

static const Adc_ChannelConfigurationType* const Adc_70_GroupChannelList_3[ADC_70_GRP_CH_NUM_3] = {
    &Adc_70_Hw1Channel[0],
    &Adc_70_Hw1Channel[1],
    &Adc_70_Hw1Channel[2]
};

static const Adc_ChannelConfigurationType* const Adc_70_GroupChannelList_4[ADC_70_GRP_CH_NUM_4] = {
    &Adc_70_Hw1Channel[0],
    &Adc_70_Hw1Channel[1],
    &Adc_70_Hw1Channel[2]
};

static const Adc_ChannelConfigurationType* const Adc_70_GroupChannelList_5[ADC_70_GRP_CH_NUM_5] = {
    &Adc_70_Hw1Channel[0],
    &Adc_70_Hw1Channel[1],
    &Adc_70_Hw1Channel[2]
};

static const Adc_ChannelConfigurationType* const Adc_70_GroupChannelList_6[ADC_70_GRP_CH_NUM_6] = {
    &Adc_70_Hw1Channel[0]
};

static const Adc_ChannelConfigurationType* const Adc_70_GroupChannelList_7[ADC_70_GRP_CH_NUM_7] = {
    &Adc_70_Hw1Channel[0],
    &Adc_70_Hw1Channel[1],
    &Adc_70_Hw1Channel[2]
};

static const Adc_ChannelConfigurationType* const Adc_70_GroupChannelList_8[ADC_70_GRP_CH_NUM_8] = {
    &Adc_70_Hw1Channel[1],
    &Adc_70_Hw1Channel[6],
    &Adc_70_Hw1Channel[7]
};

static const Adc_ChannelConfigurationType* const Adc_70_GroupChannelList_9[ADC_70_GRP_CH_NUM_9] = {
    &Adc_70_Hw1Channel[0]
};

#define ADC_STOP_SEC_CONST_8
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

static const Adc_70_RL78F2X_GroupConfigType Adc_70_GroupConfigData[ ADC_70_MAX_NUM_OF_GROUP ] =
{
    /* Donot support assign channels in one group to HW group A and groupB */
    {   /* Adc_70_GroupConfigData[0] ANI1,3,4 single scan mode */
        0x02U,     /* regAdcsrAdcs   ADCSR.ADCS[1:0] : Scan mode selection                          */
        TRUE,      /* regAdcsrAdie   ADCSR.ADIE      : Control of scan end interrupt enable         */
        FALSE,     /* regAdcsrTrge   ADCSR.TRGE      : Control of trigger start enable              */
        FALSE,     /* regAdcsrGbade  ADCSR.GBADIE    : Control of group B scan end interrupt enable */
        /* ADC_70_RL78F2X_CH_ID_A1|ADC_70_RL78F2X_CH_ID_A3|ADC_70_RL78F2X_CH_ID_A4 */
        0x001AU,   /* regAdansa0     ADANSA0 : A/D channel select register A0                       */
        0x0000U,   /* regAdansa1     ADANSA1 : A/D channel select register A1                       */
        0x0000U,   /* regAdads0      ADADS0  : Addition/average function channel select register 0  */   /* future use */
        0x0000U,   /* regAdads1      ADADS1  : Addition/average function channel select register 1  */   /* future use */
        0x00U,     /* regAdadc       ADADC   : Addition/average counter select register             */   /* future use */
        0x0000U,   /* regAdcer       ADCER   : A/D control expansion register                       */
        0x0000U,   /* regAdstrgr     ADSTRGR : A/D start trigger select register                    */   /* future use */
        0x0000U,   /* regAdExicr     ADEXICR : A/D expansion input control register                 */   /* future use */
        0x0000U,   /* regAdansb0     ADANSB0 : A/D channel select register B0                       */   /* future use */
        0x0000U,   /* regAdansb1     ADADSB1 : A/D channel select register B1                       */   /* future use */
        0x0000U,   /* regAdshcr      ADSHCR  : A/D sample & hold control register                   */   /* future use */
        0x0000U,   /* regAddiscr     ADDISCR : A/D disconnection detection control register         */   /* future use */
        0x0000U    /* regAdgspcr     ADGSPCR : A/D Group Scan Priority Control Register             */
    },
    {   /* Adc_70_GroupConfigData[1] ANI1 single scan mode with sample & hold */
        0x02U,     /* regAdcsrAdcs   ADCSR.ADCS[1:0] : Scan mode selection                          */
        TRUE,      /* regAdcsrAdie   ADCSR.ADIE      : Control of scan end interrupt enable         */
        FALSE,     /* regAdcsrTrge   ADCSR.TRGE      : Control of trigger start enable              */
        FALSE,     /* regAdcsrGbade  ADCSR.GBADIE    : Control of group B scan end interrupt enable */
        /* ADC_70_RL78F2X_CH_ID_A1 */
        0x0002U,   /* regAdansa0     ADANSA0 : A/D channel select register A0                       */
        0x0000U,   /* regAdansa1     ADANSA1 : A/D channel select register A1                       */
        0x0000U,   /* regAdads0      ADADS0  : Addition/average function channel select register 0  */   /* future use */
        0x0000U,   /* regAdads1      ADADS1  : Addition/average function channel select register 1  */   /* future use */
        0x00U,     /* regAdadc       ADADC   : Addition/average counter select register             */   /* future use */
        0x0000U,   /* regAdcer       ADCER   : A/D control expansion register                       */
        0x0000U,   /* regAdstrgr     ADSTRGR : A/D start trigger select register                    */   /* future use */
        0x0000U,   /* regAdExicr     ADEXICR : A/D expansion input control register                 */
        0x0000U,   /* regAdansb0     ADANSB0 : A/D channel select register B0                       */
        0x0000U,   /* regAdansb1     ADADSB1 : A/D channel select register B1                       */
        0x0000U,   /* regAdshcr      ADSHCR  : A/D sample & hold control register                   */
        0x0000U,   /* regAddiscr     ADDISCR : A/D disconnection detection control register         */
        0x0000U    /* regAdgspcr     ADGSPCR : A/D Group Scan Priority Control Register             */
    },
    {   /* Adc_70_GroupConfigData[2] V_BGR single scan mode */
        0x00U,     /* regAdcsrAdcs   ADCSR.ADCS[1:0] : Scan mode selection                          */
        TRUE,      /* regAdcsrAdie   ADCSR.ADIE      : Control of scan end interrupt enable         */
        FALSE,     /* regAdcsrTrge   ADCSR.TRGE      : Control of trigger start enable              */
        FALSE,     /* regAdcsrGbade  ADCSR.GBADIE    : Control of group B scan end interrupt enable */
        0x0000U,   /* regAdansa0     ADANSA0 : A/D channel select register A0                       */
        0x0000U,   /* regAdansa1     ADANSA1 : A/D channel select register A1                       */
        0x0000U,   /* regAdads0      ADADS0  : Addition/average function channel select register 0  */   /* future use */
        0x0000U,   /* regAdads1      ADADS1  : Addition/average function channel select register 1  */   /* future use */
        0x00U,     /* regAdadc       ADADC   : Addition/average counter select register             */   /* future use */
        0x0000U,   /* regAdcer       ADCER   : A/D control expansion register                       */
        0x0000U,   /* regAdstrgr     ADSTRGR : A/D start trigger select register                    */   /* future use */
        0x0200U,   /* regAdExicr     ADEXICR : A/D expansion input control register                 */
        0x0000U,   /* regAdansb0     ADANSB0 : A/D channel select register B0                       */
        0x0000U,   /* regAdansb1     ADADSB1 : A/D channel select register B1                       */
        0x0000U,   /* regAdshcr      ADSHCR  : A/D sample & hold control register                   */
        0x0000U,   /* regAddiscr     ADDISCR : A/D disconnection detection control register         */
        0x0000U    /* regAdgspcr     ADGSPCR : A/D Group Scan Priority Control Register             */
    },
    {   /* Adc_70_GroupConfigData[3] ANI1,3,4 single scan mode : HW trigger tau01 */
        0x00U,     /* regAdcsrAdcs   ADCSR.ADCS[1:0] : Scan mode selection                          */
        TRUE,      /* regAdcsrAdie   ADCSR.ADIE      : Control of scan end interrupt enable         */
        TRUE,      /* regAdcsrTrge   ADCSR.TRGE      : Control of trigger start enable              */
        FALSE,     /* regAdcsrGbade  ADCSR.GBADIE    : Control of group B scan end interrupt enable */
        /* ADC_70_RL78F2X_CH_ID_A1|ADC_70_RL78F2X_CH_ID_A3|ADC_70_RL78F2X_CH_ID_A4 */
        0x001AU,   /* regAdansa0     ADANSA0 : A/D channel select register A0                       */
        0x0000U,   /* regAdansa1     ADANSA1 : A/D channel select register A1                       */
        0x0000U,   /* regAdads0      ADADS0  : Addition/average function channel select register 0  */   /* future use */
        0x0000U,   /* regAdads1      ADADS1  : Addition/average function channel select register 1  */   /* future use */
        0x00U,     /* regAdadc       ADADC   : Addition/average counter select register             */   /* future use */
        0x0000U,   /* regAdcer       ADCER   : A/D control expansion register                       */
        0x0100U,   /* regAdstrgr     ADSTRGR : A/D start trigger select register                    */   /* future use */
        0x0000U,   /* regAdExicr     ADEXICR : A/D expansion input control register                 */
        0x0000U,   /* regAdansb0     ADANSB0 : A/D channel select register B0                       */
        0x0000U,   /* regAdansb1     ADADSB1 : A/D channel select register B1                       */
        0x0000U,   /* regAdshcr      ADSHCR  : A/D sample & hold control register                   */
        0x0000U,   /* regAddiscr     ADDISCR : A/D disconnection detection control register         */
        0x0000U    /* regAdgspcr     ADGSPCR : A/D Group Scan Priority Control Register             */
    },
    {   /* Adc_70_GroupConfigData[4] ANI1,3,4 Continuous scan mode : HW trigger tau01 */
        0x00U,     /* regAdcsrAdcs   ADCSR.ADCS[1:0] : Scan mode selection                          */
        TRUE,      /* regAdcsrAdie   ADCSR.ADIE      : Control of scan end interrupt enable         */
        TRUE,      /* regAdcsrTrge   ADCSR.TRGE      : Control of trigger start enable              */
        FALSE,     /* regAdcsrGbade  ADCSR.GBADIE    : Control of group B scan end interrupt enable */
        /* ADC_70_RL78F2X_CH_ID_A1|ADC_70_RL78F2X_CH_ID_A3|ADC_70_RL78F2X_CH_ID_A4 */
        0x001AU,   /* regAdansa0     ADANSA0 : A/D channel select register A0                       */
        0x0000U,   /* regAdansa1     ADANSA1 : A/D channel select register A1                       */
        0x0000U,   /* regAdads0      ADADS0  : Addition/average function channel select register 0  */   /* future use */
        0x0000U,   /* regAdads1      ADADS1  : Addition/average function channel select register 1  */   /* future use */
        0x00U,     /* regAdadc       ADADC   : Addition/average counter select register             */   /* future use */
        0x0000U,   /* regAdcer       ADCER   : A/D control expansion register                       */
        0x0300U,   /* regAdstrgr     ADSTRGR : A/D start trigger select register                    */   /* future use */
        0x0000U,   /* regAdExicr     ADEXICR : A/D expansion input control register                 */
        0x0000U,   /* regAdansb0     ADANSB0 : A/D channel select register B0                       */
        0x0000U,   /* regAdansb1     ADADSB1 : A/D channel select register B1                       */
        0x0000U,   /* regAdshcr      ADSHCR  : A/D sample & hold control register                   */
        0x0000U,   /* regAddiscr     ADDISCR : A/D disconnection detection control register         */
        0x0000U    /* regAdgspcr     ADGSPCR : A/D Group Scan Priority Control Register             */
    },
    {   /* Adc_70_GroupConfigData[5] ANI1,3 ANI4 Group scan mode */
        0x00U,     /* regAdcsrAdcs   ADCSR.ADCS[1:0] : Scan mode selection                          */
        TRUE,      /* regAdcsrAdie   ADCSR.ADIE      : Control of scan end interrupt enable         */
        TRUE,      /* regAdcsrTrge   ADCSR.TRGE      : Control of trigger start enable              */
        FALSE,     /* regAdcsrGbade  ADCSR.GBADIE    : Control of group B scan end interrupt enable */
        /* ADC_70_RL78F2X_CH_ID_A1|ADC_70_RL78F2X_CH_ID_A3|ADC_70_RL78F2X_CH_ID_A4 */
        0x001AU,   /* regAdansa0     ADANSA0 : A/D channel select register A0                       */
        0x0000U,   /* regAdansa1     ADANSA1 : A/D channel select register A1                       */
        0x0000U,   /* regAdads0      ADADS0  : Addition/average function channel select register 0  */   /* future use */
        0x0000U,   /* regAdads1      ADADS1  : Addition/average function channel select register 1  */   /* future use */
        0x00U,     /* regAdadc       ADADC   : Addition/average counter select register             */   /* future use */
        0x0000U,   /* regAdcer       ADCER   : A/D control expansion register                       */
        0x3000U,   /* regAdstrgr     ADSTRGR : A/D start trigger select register                    */   /* future use */
        0x0000U,   /* regAdExicr     ADEXICR : A/D expansion input control register                 */
        0x0000U,   /* regAdansb0     ADANSB0 : A/D channel select register B0                       */
        0x0000U,   /* regAdansb1     ADADSB1 : A/D channel select register B1                       */
        0x0000U,   /* regAdshcr      ADSHCR  : A/D sample & hold control register                   */
        0x0000U,   /* regAddiscr     ADDISCR : A/D disconnection detection control register         */
        0x0000U    /* regAdgspcr     ADGSPCR : A/D Group Scan Priority Control Register             */
    },
    {   /* Adc_70_GroupConfigData[6] ANI1 continuous scan mode */
        0x02U,     /* regAdcsrAdcs   ADCSR.ADCS[1:0] : Scan mode selection                          */
        TRUE,      /* regAdcsrAdie   ADCSR.ADIE      : Control of scan end interrupt enable         */
        FALSE,     /* regAdcsrTrge   ADCSR.TRGE      : Control of trigger start enable              */
        FALSE,     /* regAdcsrGbade  ADCSR.GBADIE    : Control of group B scan end interrupt enable */
        /* ADC_70_RL78F2X_CH_ID_A1 */
        0x0002U,   /* regAdansa0     ADANSA0 : A/D channel select register A0                       */
        0x0000U,   /* regAdansa1     ADANSA1 : A/D channel select register A1                       */
        0x0000U,   /* regAdads0      ADADS0  : Addition/average function channel select register 0  */   /* future use */
        0x0000U,   /* regAdads1      ADADS1  : Addition/average function channel select register 1  */   /* future use */
        0x00U,     /* regAdadc       ADADC   : Addition/average counter select register             */   /* future use */
        0x0000U,   /* regAdcer       ADCER   : A/D control expansion register                       */
        0x0000U,   /* regAdstrgr     ADSTRGR : A/D start trigger select register                    */   /* future use */
        0x0000U,   /* regAdExicr     ADEXICR : A/D expansion input control register                 */
        0x0000U,   /* regAdansb0     ADANSB0 : A/D channel select register B0                       */
        0x0000U,   /* regAdansb1     ADADSB1 : A/D channel select register B1                       */
        0x0000U,   /* regAdshcr      ADSHCR  : A/D sample & hold control register                   */
        0x0000U,   /* regAddiscr     ADDISCR : A/D disconnection detection control register         */
        0x0000U    /* regAdgspcr     ADGSPCR : A/D Group Scan Priority Control Register             */
    },
    {   /* Adc_70_GroupConfigData[7] ANI4,5,6 single scan mode : SW trigger */
        0x02U,     /* regAdcsrAdcs   ADCSR.ADCS[1:0] : Scan mode selection                          */
        TRUE,      /* regAdcsrAdie   ADCSR.ADIE      : Control of scan end interrupt enable         */
        FALSE,     /* regAdcsrTrge   ADCSR.TRGE      : Control of trigger start enable              */
        FALSE,     /* regAdcsrGbade  ADCSR.GBADIE    : Control of group B scan end interrupt enable */
        /* ADC_70_RL78F2X_CH_ID_A1|ADC_70_RL78F2X_CH_ID_A3|ADC_70_RL78F2X_CH_ID_A4 */
        0x001AU,   /* regAdansa0     ADANSA0 : A/D channel select register A0                       */
        0x0000U,   /* regAdansa1     ADANSA1 : A/D channel select register A1                       */
        0x0000U,   /* regAdads0      ADADS0  : Addition/average function channel select register 0  */   /* future use */
        0x0000U,   /* regAdads1      ADADS1  : Addition/average function channel select register 1  */   /* future use */
        0x00U,     /* regAdadc       ADADC   : Addition/average counter select register             */   /* future use */
        0x0000U,   /* regAdcer       ADCER   : A/D control expansion register                       */
        0x0000U,   /* regAdstrgr     ADSTRGR : A/D start trigger select register                    */   /* future use */
        0x0000U,   /* regAdExicr     ADEXICR : A/D expansion input control register                 */
        0x0000U,   /* regAdansb0     ADANSB0 : A/D channel select register B0                       */
        0x0000U,   /* regAdansb1     ADADSB1 : A/D channel select register B1                       */
        0x0000U,   /* regAdshcr      ADSHCR  : A/D sample & hold control register                   */
        0x0000U,   /* regAddiscr     ADDISCR : A/D disconnection detection control register         */
        0x0000U    /* regAdgspcr     ADGSPCR : A/D Group Scan Priority Control Register             */
    },
    {   /* Adc_70_GroupConfigData[8] ANI3 ANI15 ANI28 Group scan mode */
        0x01U,     /* regAdcsrAdcs   ADCSR.ADCS[1:0] : Scan mode selection                          */
        FALSE,     /* regAdcsrAdie   ADCSR.ADIE      : Control of scan end interrupt enable         */
        TRUE,      /* regAdcsrTrge   ADCSR.TRGE      : Control of trigger start enable              */
        TRUE,      /* regAdcsrGbade  ADCSR.GBADIE    : Control of group B scan end interrupt enable */
        /* ADC_70_RL78F2X_CH_ID_A15|ADC_70_RL78F2X_CH_ID_A28 */
        0x0000U,   /* regAdansa0     ADANSA0 : A/D channel select register A0                       */
        0x0000U,   /* regAdansa1     ADANSA1 : A/D channel select register A1                       */
        0x0000U,   /* regAdads0      ADADS0  : Addition/average function channel select register 0  */   /* future use */
        0x0000U,   /* regAdads1      ADADS1  : Addition/average function channel select register 1  */   /* future use */
        0x00U,     /* regAdadc       ADADC   : Addition/average counter select register             */   /* future use */
        0x0000U,   /* regAdcer       ADCER   : A/D control expansion register                       */
        0x0003U,   /* regAdstrgr     ADSTRGR : A/D start trigger select register                    */   /* future use */
        0x0000U,   /* regAdExicr     ADEXICR : A/D expansion input control register                 */
        0x8008U,   /* regAdansb0     ADANSB0 : A/D channel select register B0                       */
        0x1000U,   /* regAdansb1     ADANSB1 : A/D channel select register B1                       */
        0x0000U,   /* regAdshcr      ADSHCR  : A/D sample & hold control register                   */
        0x0000U,   /* regAddiscr     ADDISCR : A/D disconnection detection control register         */
        0x8001U    /* regAdgspcr     ADGSPCR : A/D Group Scan Priority Control Register             */
    },
    {   /* Adc_70_GroupConfigData[9] ANI1 continuous scan mode */
        0x02U,     /* regAdcsrAdcs   ADCSR.ADCS[1:0] : Scan mode selection                          */
        TRUE,      /* regAdcsrAdie   ADCSR.ADIE      : Control of scan end interrupt enable         */
        FALSE,     /* regAdcsrTrge   ADCSR.TRGE      : Control of trigger start enable              */
        FALSE,     /* regAdcsrGbade  ADCSR.GBADIE    : Control of group B scan end interrupt enable */
        /* ADC_70_RL78F2X_CH_ID_A1 */
        0x0002U,   /* regAdansa0     ADANSA0 : A/D channel select register A0                       */
        0x0000U,   /* regAdansa1     ADANSA1 : A/D channel select register A1                       */
        0x0000U,   /* regAdads0      ADADS0  : Addition/average function channel select register 0  */   /* future use */
        0x0000U,   /* regAdads1      ADADS1  : Addition/average function channel select register 1  */   /* future use */
        0x00U,     /* regAdadc       ADADC   : Addition/average counter select register             */   /* future use */
        0x0000U,   /* regAdcer       ADCER   : A/D control expansion register                       */
        0x0000U,   /* regAdstrgr     ADSTRGR : A/D start trigger select register                    */   /* future use */
        0x0000U,   /* regAdExicr     ADEXICR : A/D expansion input control register                 */
        0x0000U,   /* regAdansb0     ADANSB0 : A/D channel select register B0                       */
        0x0000U,   /* regAdansb1     ADADSB1 : A/D channel select register B1                       */
        0x0000U,   /* regAdshcr      ADSHCR  : A/D sample & hold control register                   */
        0x0000U,   /* regAddiscr     ADDISCR : A/D disconnection detection control register         */
        0x0000U    /* regAdgspcr     ADGSPCR : A/D Group Scan Priority Control Register             */
    }
};

static const Adc_GroupConfigurationType Adc_70_Hw1Grp[ADC_70_HW1_NUM_OF_GROUP] = {
    {   /* Idx=00 */
        AdcConf_AdcGroup_AdcGroup_0,                /* AdcGroupId */
        ADC_TRIGG_SRC_SW,                           /* AdcGroupTriggSrc */
        ADC_ACCESS_MODE_STREAMING,                  /* AdcGroupAccessMode */
        ADC_CONV_MODE_CONTINUOUS,                   /* AdcGroupConversionMode */
        SampleAdc_GroupNotification_1,              /* AdcNotification */
        ADC_STREAM_BUFFER_LINEAR,                   /* AdcStreamingBufferMode */
        ADC_70_STREAMING_SAMPLE_NUM_GRP_0,          /* AdcStreamingNumSamples */
        ADC_70_GRP_CH_NUM_0,                        /* AdcNumOfGroupDefinition */
        &(Adc_70_GroupChannelList_0[0]),            /* AdcGroupDefinition */
        &(Adc_70_GroupConfigData[0U]),              /* Adc_70_GroupConfig : Hardware Specific config Data */
        TRUE                                        /* Adc_70_implicitlyStop */
    },
    {   /* Idx=01 */
        AdcConf_AdcGroup_AdcGroup_1,                /* AdcGroupId */
        ADC_TRIGG_SRC_SW,                           /* AdcGroupTriggSrc */
        ADC_ACCESS_MODE_SINGLE,                     /* AdcGroupAccessMode */
        ADC_CONV_MODE_CONTINUOUS,                   /* AdcGroupConversionMode */
        NULL_PTR,                                   /* AdcNotification */
        ADC_70_STREAM_BUFFER_NONE,                  /* AdcStreamingBufferMode */
        ADC_70_STREAMING_SAMPLE_NUM_GRP_1,          /* AdcStreamingNumSamples */
        ADC_70_GRP_CH_NUM_1,                        /* AdcNumOfGroupDefinition */
        &(Adc_70_GroupChannelList_1[0]),            /* AdcGroupDefinition */
        &(Adc_70_GroupConfigData[1U]),              /* Adc_70_GroupConfig : Hardware Specific config Data */
        FALSE                                       /* Adc_70_implicitlyStop */
    },
    {   /* Idx=02 */
        AdcConf_AdcGroup_AdcGroup_2,                /* AdcGroupId */
        ADC_TRIGG_SRC_SW,                           /* AdcGroupTriggSrc */
        ADC_ACCESS_MODE_SINGLE,                     /* AdcGroupAccessMode */
        ADC_CONV_MODE_ONESHOT,                      /* AdcGroupConversionMode */
        NULL_PTR,                                   /* AdcNotification */
        ADC_70_STREAM_BUFFER_NONE,                  /* AdcStreamingBufferMode */
        ADC_70_STREAMING_SAMPLE_NUM_GRP_2,          /* AdcStreamingNumSamples */
        ADC_70_GRP_CH_NUM_2,                        /* AdcNumOfGroupDefinition */
        &(Adc_70_GroupChannelList_2[0]),            /* AdcGroupDefinition */
        &(Adc_70_GroupConfigData[2U]),              /* Adc_70_GroupConfig : Hardware Specific config Data */
        TRUE                                        /* Adc_70_implicitlyStop */
    },
    {   /* Idx=03 */
        AdcConf_AdcGroup_AdcGroup_3,                /* AdcGroupId */
        ADC_TRIGG_SRC_HW,                           /* AdcGroupTriggSrc */
        ADC_ACCESS_MODE_SINGLE,                     /* AdcGroupAccessMode */
        ADC_CONV_MODE_CONTINUOUS,                   /* AdcGroupConversionMode */
        NULL_PTR,                                   /* AdcNotification */
        ADC_70_STREAM_BUFFER_NONE,                  /* AdcStreamingBufferMode */
        ADC_70_STREAMING_SAMPLE_NUM_GRP_3,          /* AdcStreamingNumSamples */
        ADC_70_GRP_CH_NUM_3,                        /* AdcNumOfGroupDefinition */
        &(Adc_70_GroupChannelList_3[0]),            /* AdcGroupDefinition */
        &(Adc_70_GroupConfigData[3U]),              /* Adc_70_GroupConfig : Hardware Specific config Data */
        FALSE                                       /* Adc_70_implicitlyStop */
    },
    {   /* Idx=04 */
        AdcConf_AdcGroup_AdcGroup_4,                /* AdcGroupId */
        ADC_TRIGG_SRC_HW,                           /* AdcGroupTriggSrc */
        ADC_ACCESS_MODE_SINGLE,                     /* AdcGroupAccessMode */
        ADC_CONV_MODE_ONESHOT,                      /* AdcGroupConversionMode */
        NULL_PTR,                                   /* AdcNotification */
        ADC_70_STREAM_BUFFER_NONE,                  /* AdcStreamingBufferMode */
        ADC_70_STREAMING_SAMPLE_NUM_GRP_4,          /* AdcStreamingNumSamples */
        ADC_70_GRP_CH_NUM_4,                        /* AdcNumOfGroupDefinition */
        &(Adc_70_GroupChannelList_4[0]),            /* AdcGroupDefinition */
        &(Adc_70_GroupConfigData[4U]),              /* Adc_70_GroupConfig : Hardware Specific config Data */
        FALSE                                       /* Adc_70_implicitlyStop */
    },
    {   /* Idx=05 */
        AdcConf_AdcGroup_AdcGroup_5,                /* AdcGroupId */
        ADC_TRIGG_SRC_HW,                           /* AdcGroupTriggSrc */
        ADC_ACCESS_MODE_STREAMING,                  /* AdcGroupAccessMode */
        ADC_CONV_MODE_ONESHOT,                      /* AdcGroupConversionMode */
        SampleAdc_GroupNotification_1,              /* AdcNotification */
        ADC_STREAM_BUFFER_LINEAR,                   /* AdcStreamingBufferMode */
        ADC_70_STREAMING_SAMPLE_NUM_GRP_5,          /* AdcStreamingNumSamples */
        ADC_70_GRP_CH_NUM_5,                        /* AdcNumOfGroupDefinition */
        &(Adc_70_GroupChannelList_5[0]),            /* AdcGroupDefinition */
        &(Adc_70_GroupConfigData[5U]),              /* Adc_70_GroupConfig : Hardware Specific config Data */
        TRUE                                        /* Adc_70_implicitlyStop */
    },
    {   /* Idx=06 */
        AdcConf_AdcGroup_AdcGroup_6,                /* AdcGroupId */
        ADC_TRIGG_SRC_SW,                           /* AdcGroupTriggSrc */
        ADC_ACCESS_MODE_STREAMING,                  /* AdcGroupAccessMode */
        ADC_CONV_MODE_CONTINUOUS,                   /* AdcGroupConversionMode */
        SampleAdc_GroupNotification_2,              /* AdcNotification */
        ADC_STREAM_BUFFER_CIRCULAR,                 /* AdcStreamingBufferMode */
        ADC_70_STREAMING_SAMPLE_NUM_GRP_6,          /* AdcStreamingNumSamples */
        ADC_70_GRP_CH_NUM_6,                        /* AdcNumOfGroupDefinition */
        &(Adc_70_GroupChannelList_6[0]),            /* AdcGroupDefinition */
        &(Adc_70_GroupConfigData[6U]),              /* Adc_70_GroupConfig : Hardware Specific config Data */
        FALSE                                       /* Adc_70_implicitlyStop */
    },
    {   /* Idx=07 */
        AdcConf_AdcGroup_AdcGroup_7,                /* AdcGroupId */
        ADC_TRIGG_SRC_SW,                           /* AdcGroupTriggSrc */
        ADC_ACCESS_MODE_SINGLE,                     /* AdcGroupAccessMode */
        ADC_CONV_MODE_CONTINUOUS,                   /* AdcGroupConversionMode */
        SampleAdc_GroupNotification_1,              /* AdcNotification */
        ADC_70_STREAM_BUFFER_NONE,                  /* AdcStreamingBufferMode */
        ADC_70_STREAMING_SAMPLE_NUM_GRP_7,          /* AdcStreamingNumSamples */
        ADC_70_GRP_CH_NUM_7,                        /* AdcNumOfGroupDefinition */
        &(Adc_70_GroupChannelList_7[0]),            /* AdcGroupDefinition */
        &(Adc_70_GroupConfigData[7U]),              /* Adc_70_GroupConfig : Hardware Specific config Data */
        FALSE                                       /* Adc_70_implicitlyStop */
    },
    {   /* Idx=08 */
        AdcConf_AdcGroup_AdcGroup_8,                /* AdcGroupId */
        ADC_TRIGG_SRC_HW,                           /* AdcGroupTriggSrc */
        ADC_ACCESS_MODE_STREAMING,                  /* AdcGroupAccessMode */
        ADC_CONV_MODE_ONESHOT,                      /* AdcGroupConversionMode */
        SampleAdc_GroupNotification_2,              /* AdcNotification */
        ADC_STREAM_BUFFER_CIRCULAR,                 /* AdcStreamingBufferMode */
        ADC_70_STREAMING_SAMPLE_NUM_GRP_8,          /* AdcStreamingNumSamples */
        ADC_70_GRP_CH_NUM_8,                        /* AdcNumOfGroupDefinition */
        &(Adc_70_GroupChannelList_8[0]),            /* AdcGroupDefinition */
        &(Adc_70_GroupConfigData[8U]),              /* Adc_70_GroupConfig : Hardware Specific config Data */
        FALSE                                       /* Adc_70_implicitlyStop */
    },
    {   /* Idx=09 */
        AdcConf_AdcGroup_AdcGroup_9,                /* AdcGroupId */
        ADC_TRIGG_SRC_SW,                           /* AdcGroupTriggSrc */
        ADC_ACCESS_MODE_STREAMING,                  /* AdcGroupAccessMode */
        ADC_CONV_MODE_CONTINUOUS,                   /* AdcGroupConversionMode */
        SampleAdc_GroupNotification_2,              /* AdcNotification */
        ADC_STREAM_BUFFER_LINEAR,                   /* AdcStreamingBufferMode */
        ADC_70_STREAMING_SAMPLE_NUM_GRP_9,          /* AdcStreamingNumSamples */
        ADC_70_GRP_CH_NUM_9,                        /* AdcNumOfGroupDefinition */
        &(Adc_70_GroupChannelList_9[0]),            /* AdcGroupDefinition */
        &(Adc_70_GroupConfigData[9U]),              /* Adc_70_GroupConfig : Hardware Specific config Data */
        TRUE                                        /* Adc_70_implicitlyStop */
    }
};

static const Adc_HwUnitType AdcHwUnitList[ ADC_70_NUM_OF_HWUNIT ] = {
    {   /* Idx = 00 */
        ADC_70_HWUNIT_INTERNAL,                     /* AdcHwUnitId */
        ADC_70_RL78F2X_CLOCK_DIVIDE_8,              /* AdcPrescale */
        ADC_70_HW1_NUM_OF_CHANNEL,                  /* AdcNumOfAdcChannel */
        &(Adc_70_Hw1Channel[0U]),                   /* AdcChannel */
        ADC_70_HW1_NUM_OF_GROUP,                    /* AdcNumOfAdcGroup */
        &(Adc_70_Hw1Grp[0U])                        /* AdcGroup */
    }
};

const Adc_ConfigType Adc_Config = {
    {                                               /* Adc_70_ConfigSetType */
        ADC_70_NUM_OF_HWUNIT,                       /* AdcNumOfHwAdcUnit */
        &( AdcHwUnitList[ 0U ] )                        /* AdcHwUnit */
    }
};

#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

/* EOF Adc_PBcfg.c ************************************************************/