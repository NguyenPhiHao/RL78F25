/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_70_RL78F2X.c                                             */
/* Version     : v1.00.03                                                     */
/* Contents    : ADC Module HW dependent interface                            */
/*               The ADC is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc_70_RL78F2X.h"
#include "Mcl_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_RL78F2X_C                      (70U)
#define ADC_70_MODULE_ID_RL78F2X_C                      (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C       (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C       (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C    (0U)

#define ADC_70_SW_MAJOR_VERSION_RL78F2X_C               (1U)
#define ADC_70_SW_MINOR_VERSION_RL78F2X_C               (0U)
#define ADC_70_SW_PATCH_VERSION_RL78F2X_C               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Adc_70_RL78F2X.h version check start */
#if ( ADC_70_VENDOR_ID_RL78F2X_C != ADC_70_VENDOR_ID_RL78F2X_H )
    #error "VENDOR ID for Adc_70_RL78F2X.c and Adc_70_RL78F2X.h are different"
#endif

#if ( ADC_70_MODULE_ID_RL78F2X_C != ADC_70_MODULE_ID_RL78F2X_H )
    #error "MODULE ID for Adc_70_RL78F2X.c and Adc_70_RL78F2X.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C \
        != ADC_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) \
    || ( ADC_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C \
        != ADC_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) \
    || ( ADC_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C \
    != ADC_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) )
    #error "AUTOSAR Version Numbers of Adc_70_RL78F2X.c and Adc_70_RL78F2X.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_RL78F2X_C != ADC_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( ADC_70_SW_MINOR_VERSION_RL78F2X_C != ADC_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( ADC_70_SW_PATCH_VERSION_RL78F2X_C != ADC_70_SW_PATCH_VERSION_RL78F2X_H ) \
    )
    #error "Software Version Numbers of Adc_70_RL78F2X.c and Adc_70_RL78F2X.h are different"
#endif
/* Adc_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
LOCAL_INLINE void adc_70_RL78F2X_ADIFClear( void );

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define ADC_START_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : adc_70_RL78F2X_ADIFClear                                     */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Assembre Clr1 ADIF.                                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
LOCAL_INLINE void adc_70_RL78F2X_ADIFClear( void )
{
    /* [SWS_Adc_00078] Reset the interrupt flag. */
    __clr1( ( uint8 QL_70_NEAR * )ADC_70_RL78F2X_IF1H_ADR, 0U );    /* bit0: ADIF */
    __clr1( ( uint8 QL_70_NEAR * )ADC_70_RL78F2X_IF2H_ADR, 2U );    /* bit0: ADIFGB */
}

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : Adc_70_RL78F2X_Init                                          */
/* Param       : (in) hwDefPtr: pointer to HW unit configuration              */
/* Return      : None                                                         */
/* Contents    : initialize for ADC hw1.                                      */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00365][SWS_Adc_00054]SWS_Adc_00056][SWS_Adc_00247]  */
/*               [SWS_Adc_00248][SWS_Adc_00249][SWS_Adc_00250]                */
/******************************************************************************/
void Adc_70_RL78F2X_Init( const Adc_HwUnitType* hwDefPtr )
{
    volatile uint16_least i;    /* loop counter for wait time.  */

    /* [SWS_Adc_00246] Initialize only the register having only the ADC function. */
    /* stop convert and disable ADC before setting */
    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_0;
    /* Stops A/D conversion process and Disable INTAD and INTADGB interrupt generation  */
    /* ADCSR.ADST=0 and ADCSR.ADIE=0 and ADCSR.GBADIE=0                                 */
    ADC_70_RL78F2X_REG_ADCSR  &= ADC_70_RL78F2X_ADCSR_DISABLE_CONVERT_AND_INTERRUPT;

    /* --- Set Prescale value ---------------------------------------- */
    /* Since there is only one hardware unit, */
    /* it will be configured macro-definition to reduce memory resources in the future. */
    ADC_70_RL78F2X_REG_ADCKS = ( uint8 ) ( hwDefPtr->AdcPrescale );

    /* A/D High-/Low-potential Reference Voltage Control Register */
    /* Transition analog block to operation mode. */
    ADC_70_RL78F2X_REG_ADHVREFCNT = ADC_70_RL78F2X_ADHVREFCNT_ADSLP_NORMAL;

    /* wait time for after ADSLP changed 1 to 0. */
    for ( i = 0U; i < ADC_70_WAIT_10US; i++ ) {
        /* According to the hardware specifications, when setting the   */
        /* "Selects A/D analog block standby state[ADHVREFCNT.ADSLP]"   */
        /* to normal mode, a wait of at least 1us is required.          */
        /* However, considering compiler differences and other factors, */
        /* it will be set to approximately 10us.                        */
    }

    /* In the future, the following processes will be local functions */
    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_0;
    /* A/D Channel Select Register A */
    ADC_70_RL78F2X_REG_ADANSA0 = ADC_70_RL78F2X_ADANSA0_INIT;
    ADC_70_RL78F2X_REG_ADANSA1 = ADC_70_RL78F2X_ADANSA1_INIT;
    /* A/D Control Extended Register */
    ADC_70_RL78F2X_REG_ADCER   = ADC_70_RL78F2X_ADCER_INIT;

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_1;
    /* A/D Conversion Start Trigger Select Register */
    ADC_70_RL78F2X_REG_ADSTRGR = ADC_70_RL78F2X_ADSTRGR_INIT;
    /* A/D Conversion Extended Input Control Registe */
    ADC_70_RL78F2X_REG_ADEXICR = ADC_70_RL78F2X_ADEXICR_INIT;
    /* A/D Channel Select Register B */
    ADC_70_RL78F2X_REG_ADANSB0 = ADC_70_RL78F2X_ADANSB0_INIT;
    ADC_70_RL78F2X_REG_ADANSB1 = ADC_70_RL78F2X_ADANSB1_INIT;

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_6;
    /* A/D Sample-and-Hold Circuit Control Register */
    ADC_70_RL78F2X_REG_ADSHCR  = ADC_70_RL78F2X_ADSHCR_INIT;

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_8;
    /* A/D Group Scan Priority Control Register */
    ADC_70_RL78F2X_REG_ADGSPCR = ADC_70_RL78F2X_ADGSPCR_INIT;
    /* A/D High-/Low-potential Reference Voltage Control Register */
    ADC_70_RL78F2X_REG_ADHVREFCNT = ADC_70_RL78F2X_ADHVREFCNT_FIXD_VALUE;

    /* Set A/D Sampling State Register */
    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_D;
    ADC_70_RL78F2X_REG_ADSSTRL = ADC_70_RL78F2X_ADSSTRL_CFG;
    ADC_70_RL78F2X_REG_ADSSTRO = ADC_70_RL78F2X_ADSSTRO_CFG;

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_E;
    ADC_70_RL78F2X_REG_ADSSTR0 = ADC_70_RL78F2X_ADSSTR0_CFG;
    ADC_70_RL78F2X_REG_ADSSTR1 = ADC_70_RL78F2X_ADSSTR1_CFG;
    ADC_70_RL78F2X_REG_ADSSTR2 = ADC_70_RL78F2X_ADSSTR2_CFG;
    ADC_70_RL78F2X_REG_ADSSTR3 = ADC_70_RL78F2X_ADSSTR3_CFG;
    ADC_70_RL78F2X_REG_ADSSTR4 = ADC_70_RL78F2X_ADSSTR4_CFG;
    ADC_70_RL78F2X_REG_ADSSTR5 = ADC_70_RL78F2X_ADSSTR5_CFG;
    ADC_70_RL78F2X_REG_ADSSTR6 = ADC_70_RL78F2X_ADSSTR6_CFG;
    ADC_70_RL78F2X_REG_ADSSTR7 = ADC_70_RL78F2X_ADSSTR7_CFG;
    ADC_70_RL78F2X_REG_ADSSTR8 = ADC_70_RL78F2X_ADSSTR8_CFG;
    ADC_70_RL78F2X_REG_ADSSTR9 = ADC_70_RL78F2X_ADSSTR9_CFG;
    ADC_70_RL78F2X_REG_ADSSTR10 = ADC_70_RL78F2X_ADSSTR10_CFG;
    ADC_70_RL78F2X_REG_ADSSTR11 = ADC_70_RL78F2X_ADSSTR11_CFG;
    ADC_70_RL78F2X_REG_ADSSTR12 = ADC_70_RL78F2X_ADSSTR12_CFG;
    ADC_70_RL78F2X_REG_ADSSTR13 = ADC_70_RL78F2X_ADSSTR13_CFG;
    ADC_70_RL78F2X_REG_ADSSTR14 = ADC_70_RL78F2X_ADSSTR14_CFG;
    ADC_70_RL78F2X_REG_ADSSTR15 = ADC_70_RL78F2X_ADSSTR15_CFG;
}


/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : Adc_70_RL78F2X_DeInit                                        */
/* Param       : (in) hwDefPtr: pointer to HW unit configuration              */
/* Return      : None                                                         */
/* Contents    : deinitialize for ADC hw1.                                    */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00366]                                              */
/******************************************************************************/
/* [SWS_Adc_00228] The function Adc_DeInit shall be pre compile time configurable On/Off by */
/*          the configuration parameter: AdcDeInitApi. */
#if ( ADC_DEINIT_API != FALSE )
void Adc_70_RL78F2X_DeInit( const Adc_HwUnitType* hwDefPtr )
{
    volatile uint16_least i;    /* loop counter for wait time.  */

    /* [SWS_Adc_00110] Reset the ADC driver to the same state as the reset state. */

    /* stop convert and disable ADC before setting */
    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_0;
    /* Stops A/D conversion process and Disable INTAD and INTADGB interrupt generation  */
    /* ADCSR.ADST=0 and ADCSR.ADIE=0 and ADCSR.GBADIE=0                                 */
    ADC_70_RL78F2X_REG_ADCSR  &= ADC_70_RL78F2X_ADCSR_DISABLE_CONVERT_AND_INTERRUPT;

    /* In the future, the following processes will be local functions */
    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_0;
    /* A/D Channel Select Register A */
    ADC_70_RL78F2X_REG_ADANSA0 = ADC_70_RL78F2X_ADANSA0_INIT;
    ADC_70_RL78F2X_REG_ADANSA1 = ADC_70_RL78F2X_ADANSA1_INIT;
    /* A/D Control Extended Register */
    ADC_70_RL78F2X_REG_ADCER   = ADC_70_RL78F2X_ADCER_INIT;

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_1;
    /* A/D Conversion Start Trigger Select Register */
    ADC_70_RL78F2X_REG_ADSTRGR = ADC_70_RL78F2X_ADSTRGR_INIT;
    /* A/D Conversion Extended Input Control Registe */
    ADC_70_RL78F2X_REG_ADEXICR = ADC_70_RL78F2X_ADEXICR_INIT;
    /* A/D Channel Select Register B */
    ADC_70_RL78F2X_REG_ADANSB0 = ADC_70_RL78F2X_ADANSB0_INIT;
    ADC_70_RL78F2X_REG_ADANSB1 = ADC_70_RL78F2X_ADANSB1_INIT;

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_6;
    /* A/D Sample-and-Hold Circuit Control Register */
    ADC_70_RL78F2X_REG_ADSHCR  = ADC_70_RL78F2X_ADSHCR_INIT;

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_8;
    /* A/D Group Scan Priority Control Register */
    ADC_70_RL78F2X_REG_ADGSPCR = ADC_70_RL78F2X_ADGSPCR_INIT;
    /* A/D High-/Low-potential Reference Voltage Control Register */
    ADC_70_RL78F2X_REG_ADHVREFCNT = ADC_70_RL78F2X_ADHVREFCNT_INIT;

    /* A/D Conversion Clock Control Register */
    ADC_70_RL78F2X_REG_ADCKS = ADC_70_RL78F2X_ADCKS_INIT;

    /* wait time for after ADSLP changed 0 to 1. */
    for ( i = 0U; i < ADC_70_WAIT_10US; i++ ) {
        /* According to the hardware specifications, when setting the   */
        /* "Selects A/D analog block standby state[ADHVREFCNT.ADSLP]"   */
        /* to standby mode (initial value), a gap of at least 5us is    */
        /* required before the next normal mode setting.                */
        /* However, considering compiler differences and other factors, */
        /* it will be set to 10us.                                      */
    }
}
#endif /* #if ( ADC_DEINIT_API != FALSE ) */


/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : Adc_70_RL78F2X_StartConvert                                  */
/* Param       : (in) gpPtr: pointer to group information table element       */
/*               (in) gpDefPtr: pointer to group definition table element     */
/*               (in) chDefptr: pointer to channel definition table element   */
/* Return      : None                                                         */
/* Contents    : start ADC conversion of hw1.                                 */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00367]                                              */
/******************************************************************************/
void Adc_70_RL78F2X_StartConvert( const Adc_70_GroupInfoType* gpPtr,
    const Adc_GroupConfigurationType* gpDefPtr )
{
    const Adc_70_RL78F2X_GroupConfigType* gpConfig;

    /* get HW dependent sconfiguration */
    gpConfig = gpDefPtr->Adc_70_GroupConfig;
    /* stop convert and disable ADC before setting */
    ADC_70_RL78F2X_REG_ADWINR = ADC_70_RL78F2X_ADWINR_0;
    /* Stops A/D conversion process and Disable INTAD and INTADGB interrupt generation  */
    /* ADCSR.ADST=0 and ADCSR.ADIE=0 and ADCSR.GBADIE=0                                 */
    ADC_70_RL78F2X_REG_ADCSR  &= ADC_70_RL78F2X_ADCSR_DISABLE_CONVERT_AND_INTERRUPT;
    /* ADIF clear */
    adc_70_RL78F2X_ADIFClear();

    /* Set A/D conversion channel select */
    ADC_70_RL78F2X_REG_ADANSA0 = ( gpConfig->regAdansa0 );
    ADC_70_RL78F2X_REG_ADANSA1 = ( gpConfig->regAdansa1 );

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_1;
    /* Set Internal reference voltage (VBGR) conversion select */
    ADC_70_RL78F2X_REG_ADEXICR = ( gpConfig->regAdExicr );
    /* Set A/D Conversion Start Trigger Select Register */
    ADC_70_RL78F2X_REG_ADSTRGR = ( gpConfig->regAdstrgr );

    /* Set A/D Channel Select Register B */
    ADC_70_RL78F2X_REG_ADANSB0 = ( gpConfig->regAdansb0 );
    ADC_70_RL78F2X_REG_ADANSB1 = ( gpConfig->regAdansb1 );

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_8;
    /* Set A/D Group Scan Priority Control Register */
    ADC_70_RL78F2X_REG_ADGSPCR = ( gpConfig->regAdgspcr );

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_0;
    /* Set A/D control expansion register */
    ADC_70_RL78F2X_REG_ADCER   = ( gpConfig->regAdcer );

    /* Enable/Disables A/D conversion to be started by trigger. */
    /* [SWS_Adc_00144] A group with trigger source hardware, whose trigger was enabled */
    /*                 with Adc_EnableHardwareTrigger, shall execute the group channel conversions,  */
    /*                 whenever a trigger event occurs. */
    if ( TRUE == gpConfig->regAdcsrTrge ) {
        ADC_70_RL78F2X_REG_ADCSR   |=  ADC_70_RL78F2X_ADCSR_TRGE_BIT;              /* ADCSR.TRGE=1 */
    } else {
        ADC_70_RL78F2X_REG_ADCSR   &=  ( uint16 ) ~ADC_70_RL78F2X_ADCSR_TRGE_BIT;     /* ADCSR.TRGE=0 */
    }
    /* Clean Scan mode selection */
    ADC_70_RL78F2X_REG_ADCSR   &= ( uint16 ) ~(ADC_70_RL78F2X_ADCSR_ADCS_MSK);
    /* Set Scan mode selection */
    ADC_70_RL78F2X_REG_ADCSR   |=  ( uint16 ) ( ( uint16 ) ( ( uint16 ) ( gpConfig->regAdcsrAdcs )\
                                                << 13U ) & ADC_70_RL78F2X_ADCSR_ADCS_MSK );     /* ADCSR.ADCS[1:0] */

    /* Enables INTAD interrupt generation upon scan completion. */
    if ( TRUE == gpConfig->regAdcsrAdie ) {
        ADC_70_RL78F2X_REG_ADCSR   |=  ADC_70_RL78F2X_ADCSR_ADIE_BIT;              /* ADCSR.ADIE=1 */
    } else {
        ADC_70_RL78F2X_REG_ADCSR   &=  ( uint16 ) ~ADC_70_RL78F2X_ADCSR_ADIE_BIT;     /* ADCSR.ADIE=0 */
    }

    /* Enable/Disables INTADGB interrupt generation upon group B scan completion. */
    if ( TRUE == gpConfig->regAdcsrGbade ) {
        ADC_70_RL78F2X_REG_ADCSR   |=  ADC_70_RL78F2X_ADCSR_GBADIE_BIT;            /* ADCSR.GBADIE=1 */
    } else {
        ADC_70_RL78F2X_REG_ADCSR   &=  ( uint16 ) ~ADC_70_RL78F2X_ADCSR_GBADIE_BIT;   /* ADCSR.GBADIE=0 */
    }

    /* [SWS_Adc_00061][SWS_Adc_00114] start ADC conversion */
    if ( TRUE != gpConfig->regAdcsrTrge ) {
        ADC_70_RL78F2X_REG_ADCSR   |=  ADC_70_RL78F2X_ADCSR_ADST_BIT;     /* ADCSR.ADST=1 */
    }
}

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : Adc_70_RL78F2X_StopConvert                                   */
/* Param       : (in) gpPtr: pointer to group information table element       */
/*               (in) gpDefPtr: pointer to group definition table element     */
/* Return      : None                                                         */
/* Contents    : stop ADC conversion of hw1.                                  */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00368]                                              */
/******************************************************************************/
void Adc_70_RL78F2X_StopConvert( const Adc_70_GroupInfoType* gpPtr,
    const Adc_GroupConfigurationType* gpDefPtr )
{
    /* [SWS_Adc_00385] Stop group conversion during conversion              */
    /*          that is set in ONESHOT conversion mode and SW trigger mode. */
    /* [SWS_Adc_00386] Stop group conversion during conversion              */
    /*          set for CONTINUOUS conversion mode and SW trigger mode.     */
    ADC_70_RL78F2X_REG_ADWINR  =   ADC_70_RL78F2X_ADWINR_0;
    /* Stops A/D conversion process and Disable INTAD and INTADGB interrupt generation  */
    /* ADCSR.ADST=0 and ADCSR.ADIE=0 and ADCSR.GBADIE=0                                 */
    ADC_70_RL78F2X_REG_ADCSR  &= ADC_70_RL78F2X_ADCSR_DISABLE_CONVERT_AND_INTERRUPT;
   
    adc_70_RL78F2X_ADIFClear(); /*  ADIF clear */
}

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : Adc_70_RL78F2X_HwStopConvert                                 */
/* Param       : (in) gpPtr: pointer to group information table element       */
/*               (in) gpDefPtr: pointer to group definition table element     */
/* Return      : None                                                         */
/* Contents    : stop ADC Hw trigger conversion of hw1.                       */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Adc_70_RL78F2X_HwStopConvert( const Adc_70_GroupInfoType* gpPtr,
    const Adc_GroupConfigurationType* gpDefPtr )
{
    volatile uint8  lADCSbits;              /* ADCSR.ADCS */
    uint8_least     lcounti;
    volatile uint8  lELSELR;

    /* [SWS_Adc_00116] The function Adc_DisableHardwareTrigger shall disable */
    /*                  the hardware trigger for the requested ADC Channel group. */
    /* 12.7.2 Procedure for Stopping A/D Conversion */

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_8;
    /* Clear group priority setting */
    ADC_70_RL78F2X_REG_ADGSPCR &= ( uint16 ) ~ADC_70_RL78F2X_ADGSPCR_PGS_BIT;

    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_0;
    lADCSbits = ( uint8 )  ( ( ADC_70_RL78F2X_REG_ADCSR & 0x6000U ) >> 13U);
    ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_1;
    if ( 0x01U == lADCSbits ) { /* group scan mode */
        ADC_70_RL78F2X_REG_ADSTRGR  = 0x3F3FU;  /* set the TRSA[5:0] and TRSB[5:0] bits to 3FH and 3FH */
        ADC_70_RL78F2X_REG_ADWINR   = ADC_70_RL78F2X_ADWINR_0;
        ADC_70_RL78F2X_REG_ADCSR    &= ( uint16 ) ~( ADC_70_RL78F2X_ADCSR_ADIE_BIT |\
                                                    ADC_70_RL78F2X_ADCSR_GBADIE_BIT );
    } else {
        ADC_70_RL78F2X_REG_ADSTRGR  |= ( uint16 )( ( uint16 ) ( 0x3FU ) << 8U ); /* To disable trigger inputs for Group A */
        ADC_70_RL78F2X_REG_ADWINR   = ADC_70_RL78F2X_ADWINR_0;
        ADC_70_RL78F2X_REG_ADCSR    &= ( uint16 ) ~( ADC_70_RL78F2X_ADCSR_ADIE_BIT );
    }
    for (lcounti = 0U; lcounti < 26U; lcounti++) {
        lELSELR = ELSELRn( lcounti ) & 0xFU ;
        if ( 0x01U == lELSELR ) {
            ELSELRn( lcounti ) = 0x00U;  /* event link disabled */
        }
    }
    /* Stops A/D conversion process */
    /* ADCSR.ADST=0                             */
    ADC_70_RL78F2X_REG_ADCSR  &= ( uint16 ) ~( ADC_70_RL78F2X_ADCSR_ADST_BIT );

    adc_70_RL78F2X_ADIFClear(); /*  ADIF clear */
}

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : Adc_70_RL78F2X_GetAdcValue                                   */
/* Param       : (in) hwChannelId: channel id                                 */
/* Return      : None                                                         */
/* Contents    : get A/D conveted value of channel                            */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00140][SWS_Adc_00446]                               */
/******************************************************************************/
Adc_ValueGroupType Adc_70_RL78F2X_GetAdcValue( Adc_ChannelType hwChannelId )
{
    Adc_ValueGroupType value;   /* no initial value for MISRA2012 Rule-2.2 */

    /* Not supported [SWS_Adc_00122] no mask lower bits when left alignment. */
    if ( ADC_70_RL78F2X_CH_ID_VBGR != hwChannelId ) {
        ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_ADDRy( hwChannelId );
        value = *ADC_70_RL78F2X_ADDRy( hwChannelId );
    } else {
        ADC_70_RL78F2X_REG_ADWINR  = ADC_70_RL78F2X_ADWINR_1;
        value = ADC_70_RL78F2X_REG_ADOCDR;
    }
    return value;
}

#define ADC_START_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

/* EOF Adc_70_RL78F2X.c *******************************************************/

