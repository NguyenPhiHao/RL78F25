/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_70_RL78F2X_Types.h                                       */
/* Version     : v1.00.02                                                     */
/* Contents    : ADC Module type definition header                            */
/*               The ADC is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of ADC                                                       */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef ADC_70_RL78F2X_TYPES_H_
#define ADC_70_RL78F2X_TYPES_H_

/* include headers */
#include "Adc_Cfg.h"
#include "QINeS_Lite.h"

/* file version information */
#define ADC_70_VENDOR_ID_RL78F2X_TYPES_H            ( 70U )
#define ADC_70_MODULE_ID_RL78F2X_TYPES_H            (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H   (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H   (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H ( 0U)

#define ADC_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H            ( 1U )
#define ADC_70_SW_MINOR_VERSION_RL78F2X_TYPES_H            ( 0U )
#define ADC_70_SW_PATCH_VERSION_RL78F2X_TYPES_H            ( 0U )

/* Adc_Cfg.h version check start */
#if ( ADC_70_VENDOR_ID_RL78F2X_TYPES_H != ADC_70_VENDOR_ID_CFG_H )
  #error "VENDOR ID for Adc_70_RL78F2X_Types.h and Adc_Cfg.h are different"
#endif

#if ( ADC_70_MODULE_ID_RL78F2X_TYPES_H != ADC_70_MODULE_ID_CFG_H )
  #error "MODULE ID for Adc_70_RL78F2X_Types.h and Adc_Cfg.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H != ADC_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H != ADC_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H != ADC_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
  #error "AUTOSAR Version Numbers of Adc_70_RL78F2X_Types.h and Adc_Cfg.h are different"
#endif
/* Adc_Cfg.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                     */
/*----------------------------------------------------------------------------*/
/* number of ADC HW unit.                                     */
#define ADC_70_RL78F2X_NUM_OF_HWUNIT       ( 1U )
#define ADC_70_RL78F2X_NUM_OF_HWTRIGSRC    (10U )
#define ADC_70_RL78F2X_NUM_OF_ELC          (26U )
/* Can config 10 HW trigger source (ADC_70_RL78F2X_NUM_OF_HWTRIGSRC) */
/* include ELC */
/* there are 26 ELC can be config to trigger ADC */
/* in 26 ELC, INTT11 and INTTM01 are conflict with HW trigger source in ADSTGR */
#define ADC_70_RL78F2X_HWTRIGSRC_MAX   ( ADC_70_RL78F2X_NUM_OF_HWTRIGSRC + \
                                         ADC_70_RL78F2X_NUM_OF_ELC - 4U )
#define ADC_70_RL78F2X_INTAD           ( 0U )
#define ADC_70_RL78F2X_INTADGB         ( 1U )

#define ELSELRn(n)  (*((volatile uint8 QL_70_NEAR *)(0x0780U + (n))) )

/* Register related */
#define ADC_70_RL78F2X_REG_ADCSR        (*(volatile uint16 QL_70_NEAR *)0x6B00U)
#define ADC_70_RL78F2X_REG_ADGSPCR      (*(volatile uint16 QL_70_NEAR *)0x6B02U)
#define ADC_70_RL78F2X_REG_ADSTRGR      (*(volatile uint16 QL_70_NEAR *)0x6B04U)
#define ADC_70_RL78F2X_REG_ADSSTR0      (*(volatile uint8  QL_70_NEAR *)0x6B06U)
#define ADC_70_RL78F2X_REG_ADSSTR1      (*(volatile uint8  QL_70_NEAR *)0x6B07U)
#define ADC_70_RL78F2X_REG_ADEXICR      (*(volatile uint16 QL_70_NEAR *)0x6B08U)
#define ADC_70_RL78F2X_REG_ADSSTR2      (*(volatile uint8  QL_70_NEAR *)0x6B09U)
#define ADC_70_RL78F2X_REG_ADANSB0      (*(volatile uint16 QL_70_NEAR *)0x6B0AU)
#define ADC_70_RL78F2X_REG_ADANSB1      (*(volatile uint16 QL_70_NEAR *)0x6B0CU)
#define ADC_70_RL78F2X_REG_ADSHCR       (*(volatile uint8  QL_70_NEAR *)0x6B0EU)
#define ADC_70_RL78F2X_REG_ADSCR        (*(volatile uint8  QL_70_NEAR *)0x6B0FU)
#define ADC_70_RL78F2X_REG_ADSTR4       (*(volatile uint8  QL_70_NEAR *)0x6B14U)
#define ADC_70_RL78F2X_REG_ADSTR5       (*(volatile uint8  QL_70_NEAR *)0x6B15U)
#define ADC_70_RL78F2X_REG_ADSTR6       (*(volatile uint8  QL_70_NEAR *)0x6B16U)
#define ADC_70_RL78F2X_REG_ADSTR7       (*(volatile uint8  QL_70_NEAR *)0x6B17U)
#define ADC_70_RL78F2X_REG_ADHVREFCNT   (*(volatile uint8  QL_70_NEAR *)0x6B1AU)
#define ADC_70_RL78F2X_REG_ADSTSTR11    (*(volatile uint8  QL_70_NEAR *)0x6B1BU)
#define ADC_70_RL78F2X_REG_ADCODCR      (*(volatile uint16 QL_70_NEAR *)0x6B1CU)
#define ADC_70_RL78F2X_REG_ADSTSTR12    (*(volatile uint8  QL_70_NEAR *)0x6B1DU)
#define ADC_70_RL78F2X_REG_ADSTSTR13    (*(volatile uint8  QL_70_NEAR *)0x6B1EU)
#define ADC_70_RL78F2X_REG_ADSTR14      (*(volatile uint8  QL_70_NEAR *)0x6B1FU)
#define ADC_70_RL78F2X_REG_ADSTSTR15    (*(volatile uint8  QL_70_NEAR *)0x6B20U)
#define ADC_70_RL78F2X_REG_ADWINR       (*(volatile uint8  QL_70_NEAR *)0xFF30U)

/* A/D Conversion Clock Control Register */
#define ADC_70_RL78F2X_REG_ADCKS        (*(volatile uint8  QL_70_NEAR *)0x2C7U)

#define ADC_70_RL78F2X_IF1H_ADR         ((volatile uint8 *)0xFFE3U)
#define ADC_70_RL78F2X_IF2H_ADR         ((volatile uint8 *)0xFFD1U)

#define ADC_70_RL78F2X_ADDR_ADR         (0x06B0U)
#define ADC_70_RL78F2X_ADWINR_ADDRy_BASE (2U)
#define ADC_70_RL78F2X_ADWINR_ADDRy(i)  \
    ((uint8)(ADC_70_RL78F2X_ADWINR_ADDRy_BASE + ((i) >> 3U)))

#define ADC_70_RL78F2X_ADDRy(i)        \
    (*(volatile uint16 QL_70_NEAR *)   \
      (ADC_70_RL78F2X_ADDR_ADR +       \
       (0x02U * ((i) % 8U))))

/* A/D conversion clock select ADCKS.ADCK[1:0] */
#define ADC_70_RL78F2X_ADCKS_NON_DIV    ((uint8)0x00U) /* 00b: fCLK   */
#define ADC_70_RL78F2X_ADCKS_DIV2       ((uint8)0x01U) /* 01b: fCLK/2 */
#define ADC_70_RL78F2X_ADCKS_DIV4       ((uint8)0x02U) /* 10b: fCLK/4 */
#define ADC_70_RL78F2X_ADCKS_DIV8       ((uint8)0x03U) /* 11b: fCLK/8 */

/* A/D High-/Low-potential Reference Voltage Control Register */
/* Selects A/D analog block standby state ADHVREFCNT.ADSLP */
/* ADSLP is the MSB of the AAA register. 0-bit is the initial value. */
#define ADC_70_RL78F2X_ADHVREFCNT_ADSLP_NORMAL  ((uint8)0x11U)

/* Selects low-potential reference voltage ADHVREFCNT.LVSEL */
#define ADC_70_RL78F2X_ADHVREFCNT_LVSEL_AV_REFM   ((uint8)0x10U)  /* select AVrefm */

/* Selects high-potential reference voltage ADHVREFCNT.HVSEL */
#define ADC_70_RL78F2X_ADHVREFCNT_HVSEL_AV_REFP   ((uint8)0x01U)  /* select AVrefp */

#define ADC_70_RL78F2X_ADHVREFCNT_FIXD_VALUE  \
    ( (uint8)( ADC_70_RL78F2X_ADHVREFCNT_LVSEL_AV_REFM | \
               ADC_70_RL78F2X_ADHVREFCNT_HVSEL_AV_REFP ) )

/* A/D converter access window select bit ADWINR.ADPAGE[3:0] */
#define ADC_70_RL78F2X_ADWINR_0   ((uint8)0x00U)
#define ADC_70_RL78F2X_ADWINR_1   ((uint8)0x01U)
#define ADC_70_RL78F2X_ADWINR_6   ((uint8)0x06U)
#define ADC_70_RL78F2X_ADWINR_8   ((uint8)0x08U)
#define ADC_70_RL78F2X_ADWINR_D   ((uint8)0x0DU)
#define ADC_70_RL78F2X_ADWINR_E   ((uint8)0x0EU)

/* Register initial value */
#define ADC_70_RL78F2X_ADCKS_INIT      ((uint8 )0x00U)
#define ADC_70_RL78F2X_ADANSA0_INIT    ((uint16)0x0000U)
#define ADC_70_RL78F2X_ADANSA1_INIT    ((uint16)0x0000U)
#define ADC_70_RL78F2X_ADCR_INIT       ((uint16)0x0000U)
#define ADC_70_RL78F2X_ADSTRGR_INIT    ((uint16)0x0000U)
#define ADC_70_RL78F2X_ADEXICR_INIT    ((uint16)0x0000U)
#define ADC_70_RL78F2X_ADANSB0_INIT    ((uint16)0x0000U)
#define ADC_70_RL78F2X_ADANSB1_INIT    ((uint16)0x0000U)
#define ADC_70_RL78F2X_ADSHCR_INIT     ((uint8 )0x00U)
#define ADC_70_RL78F2X_ADGSPCR_INIT    ((uint16)0x0000U)
#define ADC_70_RL78F2X_ADHVREFCNT_INIT ((uint8 )0x91U)

#define ADC_70_RL78F2X_ADCSR_ADST_BIT   ((uint16)0x8000U) /* ADCSR.ADST : Control of A/D conversion start */
#define ADC_70_RL78F2X_ADCSR_ADCS_MSK   ((uint16)0x6000U) /* ADCSR.ADCS : Scan mode selection */
#define ADC_70_RL78F2X_ADCSR_ADIE_BIT   ((uint16)0x1000U) /* ADCSR.ADIE : Scan end interrupt enable */
#define ADC_70_RL78F2X_ADCSR_ADHSC_BIT  ((uint16)0x2000U) /* ADCSR.ADHSC : Low-current conversion mode */
#define ADC_70_RL78F2X_ADCSR_TRGE_BIT   ((uint16)0x0200U) /* ADCSR.TRGE : Trigger start enable */
#define ADC_70_RL78F2X_ADCSR_GBADIE_BIT ((uint16)0x0040U) /* ADCSR.GBADIE: Group B scan end interrupt enable */

#define ADC_70_RL78F2X_ADCSR_DISABLE_CONVERT_AND_INTERRUPT \
    ((uint16)( ADC_70_RL78F2X_ADCSR_ADST_BIT | \
               ADC_70_RL78F2X_ADCSR_ADCS_MSK | \
               ADC_70_RL78F2X_ADCSR_ADIE_BIT | \
               ADC_70_RL78F2X_ADCSR_ADHSC_BIT | \
               ADC_70_RL78F2X_ADCSR_TRGE_BIT | \
               ADC_70_RL78F2X_ADCSR_GBADIE_BIT )) /* ADST=0 & ADCS=0 & ADIE=0 & ADHSC=0 & TRGE=0 & GBADIE=0 */

#define ADC_70_RL78F2X_ADGSPCR_PGS_BIT  ((uint16)0x0001U) /* ADGSPCR.PGS : Group priority operation */
/*----------------------------------------------------------------------------*/
/* type definitions                                           */
/*----------------------------------------------------------------------------*/
/* 8.2.2 Adc_ChannelType : Numeric ID of an ADC channel.      */
/* RL78F2X dependent */
typedef enum {
    ADC_70_RL78F2X_CH_ID_A0   =  0U,  /* ANI00 */
    ADC_70_RL78F2X_CH_ID_A1   =  1U,  /* ANI01 */
    ADC_70_RL78F2X_CH_ID_A2   =  2U,  /* ANI02 */
    ADC_70_RL78F2X_CH_ID_A3   =  3U,  /* ANI03 */
    ADC_70_RL78F2X_CH_ID_A4   =  4U,  /* ANI04 */
    ADC_70_RL78F2X_CH_ID_A5   =  5U,  /* ANI05 */
    ADC_70_RL78F2X_CH_ID_A6   =  6U,  /* ANI06 */
    ADC_70_RL78F2X_CH_ID_A7   =  7U,  /* ANI07 */
    ADC_70_RL78F2X_CH_ID_A8   =  8U,  /* ANI08 */
    ADC_70_RL78F2X_CH_ID_A9   =  9U,  /* ANI09 */
    ADC_70_RL78F2X_CH_ID_A10  = 10U,  /* ANI10 */
    ADC_70_RL78F2X_CH_ID_A11  = 11U,  /* ANI11 */
    ADC_70_RL78F2X_CH_ID_A12  = 12U,  /* ANI12 */
    ADC_70_RL78F2X_CH_ID_A13  = 13U,  /* ANI13 */
    ADC_70_RL78F2X_CH_ID_A14  = 14U,  /* ANI14 */
    ADC_70_RL78F2X_CH_ID_A15  = 15U,  /* ANI15 */
    ADC_70_RL78F2X_CH_ID_A16  = 16U,  /* ANI16 */
    ADC_70_RL78F2X_CH_ID_A17  = 17U,  /* ANI17 */
    ADC_70_RL78F2X_CH_ID_A18  = 18U,  /* ANI18 */
    ADC_70_RL78F2X_CH_ID_A19  = 19U,  /* ANI19 */
    ADC_70_RL78F2X_CH_ID_A20  = 20U,  /* ANI20 */
    ADC_70_RL78F2X_CH_ID_A21  = 21U,  /* ANI21 */
    ADC_70_RL78F2X_CH_ID_A22  = 22U,  /* ANI22 */
    ADC_70_RL78F2X_CH_ID_A23  = 23U,  /* ANI23 */
    ADC_70_RL78F2X_CH_ID_A24  = 24U,  /* ANI24 */
    ADC_70_RL78F2X_CH_ID_A25  = 25U,  /* ANI25 */
    ADC_70_RL78F2X_CH_ID_A26  = 26U,  /* ANI26 */
    ADC_70_RL78F2X_CH_ID_A27  = 27U,  /* ANI27 */
    ADC_70_RL78F2X_CH_ID_A28  = 28U,  /* ANI28 */
    ADC_70_RL78F2X_CH_ID_VBGR = 31U,  /* V_BGR */
} Adc_70_RL78F2X_ChannelType;

/* 8.2.5 Adc_PrescaleType : Type of clock prescaler factor. */
typedef enum {
    ADC_70_RL78F2X_CLOCK_NON_DIVIDE = ( ADC_70_RL78F2X_ADCKS_NON_DIV ),
    ADC_70_RL78F2X_CLOCK_DIVIDE_2   = ( ADC_70_RL78F2X_ADCKS_DIV2    ),
    ADC_70_RL78F2X_CLOCK_DIVIDE_4   = ( ADC_70_RL78F2X_ADCKS_DIV4    ),
    ADC_70_RL78F2X_CLOCK_DIVIDE_8   = ( ADC_70_RL78F2X_ADCKS_DIV8    )
} Adc_70_RL78F2X_PrescaleType;

/* 8.2.10 Adc_TriggerSourceType : Type for configuring the trigger source for an ADC Channel group. */
typedef enum {
    ADC_TRIGG_SRC_SW = ( 0U ),  /* RL78 Software Trigger Mode */
    ADC_TRIGG_SRC_HW = ( 1U )   /* RL78 Hardware Trigger Mode */
} Adc_70_RL78F2X_TriggerSourceType;

/* [ECUC_Adc_00089] Upper reference voltage source for each channel. */
typedef enum {
    ADC_70_RL78F2X_VOLT_HIGH_REFP = (ADC_70_RL78F2X_ADHVREFCNT_HVSEL_AV_REFP)  /* select AVrefp */
} Adc_70_RL78F2X_RefVoltSrcHighType;

/* [ECUC_Adc_00023] Lower reference voltage source for each channel. */
typedef enum {
    ADC_70_RL78F2X_VOLT_LOW_REFM  = (ADC_70_RL78F2X_ADHVREFCNT_LVSEL_AV_REFM)  /* select AVrefm */
} Adc_70_RL78F2X_RefVoltSrcLowType;

/* Adc_70_RL78F2X_GroupConfigType */
/* H/W dependent group configuration data */
typedef struct {
    uint8   regAdcsrAdcs;    /* ADCSR.ADCS[1:0]    : Scan mode selection                 */
    bool_t  regAdcsrAdie;    /* ADCSR.ADIE         : Control of scan end interrupt enable */
    bool_t  regAdcsrTrge;    /* ADCSR.TRGE         : Control of trigger start enable      */
    bool_t  regAdcsrGbadie;  /* ADCSR.GBADIE       : Control of group B scan end interrupt enable */
    uint16  regAdansa0;      /* ADANSA0            : A/D channel select register A0       */
    uint16  regAdansa1;      /* ADANSA1            : A/D channel select register A1       */
    uint16  regAdads0;       /* ADADS0             : Addition/average function channel select register 0  (future use) */
    uint16  regAdads1;       /* ADADS1             : Addition/average function channel select register 1  (future use) */
    uint16  regAdadc;        /* ADADC              : Addition/average function counter select register        */
    uint16  regAdcer;        /* ADCER              : A/D control expansion register                       */
    uint16  regAdstrgr;      /* ADSTRGR            : A/D start trigger select register                    */
    uint16  regAdexicr;      /* ADEXICR            : A/D expansion input control register                 */
    uint16  regAdansb0;      /* ADANSB0            : A/D channel select register B0                       */
    uint16  regAdansb1;      /* ADANSB1            : A/D channel select register B1                       */
    uint8   regAdshcr;       /* ADSHCR             : A/D sample & hold control register                   */
    uint8   regAddiscr;      /* ADDISCR            : A/D disconnection detection control register        */
    uint16  regAdgspcr;      /* ADGSPCR            : A/D Group Scan Priority Control Register            */
} Adc_70_RL78F2X_GroupConfigType;

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                             */
/*----------------------------------------------------------------------------*/

#endif /* #ifndef ADC_70_RL78F2X_TYPES_H_ */

/* EOF Adc_70_RL78F2X_Types.h ************************************/```
