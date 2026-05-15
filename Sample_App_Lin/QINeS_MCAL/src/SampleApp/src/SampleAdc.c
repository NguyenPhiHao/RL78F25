/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                              */
/* File Name   : SampleAdc.c
/* Version     : v1.00.02
/* Contents    : Adc sample application.
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "SampleAdc.h"
#include "Adc.h"
#include "Gpt.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*  macros                                                                    */
/*----------------------------------------------------------------------------*/
#define SAMPLE_ADC_3_2_3_1   (3231U)
#define SAMPLE_ADC_3_2_3_2   (3232U)
#define SAMPLE_ADC_3_2_3_3   (3233U)
#define SAMPLE_ADC_3_2_3_4   (3234U)

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
* function definitions
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_ADC_ENABLE != FALSE )
    uint16 SampleAdc_Case = 0U;
    Adc_ValueGroupType SampleAdc_Group0_Buf[ADC_70_GRP_CH_NUM_0*ADC_70_STREAMING_SAMPLE_NUM_GRP_0];
    Adc_ValueGroupType SampleAdc_Group5_Buf[ADC_70_GRP_CH_NUM_5*ADC_70_STREAMING_SAMPLE_NUM_GRP_5];
    Adc_ValueGroupType SampleAdc_Group6_Buf[ADC_70_GRP_CH_NUM_6*ADC_70_STREAMING_SAMPLE_NUM_GRP_6];
    Adc_ValueGroupType SampleAdc_Group7_Buf[ADC_70_GRP_CH_NUM_7*ADC_70_STREAMING_SAMPLE_NUM_GRP_7];
    Adc_ValueGroupType SampleAdc_Group0_Result[ADC_70_GRP_CH_NUM_0];
    Adc_ValueGroupType SampleAdc_Group5_Result[ADC_70_GRP_CH_NUM_5];
    Adc_ValueGroupType SampleAdc_Group6_Result[ADC_70_GRP_CH_NUM_6];
    Adc_ValueGroupType SampleAdc_Group7_Result[ADC_70_GRP_CH_NUM_7];
    volatile uint8 SampleAdc_NtfCallCnt1 = 0U;
    volatile uint8 SampleAdc_NtfCallCnt2 = 0U;
    Std_ReturnType SampleAdc_Ret;
#endif

/*------------------------------------------------------------------------------*/
/* functions and function style macros                                          */
/*------------------------------------------------------------------------------*/

#if ( SAMPLE_ADC_ENABLE != FALSE )
void SampleAdc( void ) {
    uint16 cnt;

    /* Start conversion with INTTRJ0 */
    ELSELRn(13) = 0x0001U;
    Gpt_Init( &Gpt_Config );
    Gpt_StartTimer( GPT_70_CH_WAKEUP, 1000U );

    /* Reset buffer */
    for ( cnt = 0; cnt < (ADC_70_GRP_CH_NUM_0*ADC_70_STREAMING_SAMPLE_NUM_GRP_0); cnt++ ) {
        SampleAdc_Group0_Buf[cnt] = 0x0000U;
    }

    for ( cnt = 0; cnt < (ADC_70_GRP_CH_NUM_5*ADC_70_STREAMING_SAMPLE_NUM_GRP_5); cnt++ ) {
        SampleAdc_Group5_Buf[cnt] = 0x0000U;
    }

    for ( cnt = 0; cnt < (ADC_70_GRP_CH_NUM_6*ADC_70_STREAMING_SAMPLE_NUM_GRP_6); cnt++ ) {
        SampleAdc_Group6_Buf[cnt] = 0x0000U;
    }

    for ( cnt = 0; cnt < (ADC_70_GRP_CH_NUM_7*ADC_70_STREAMING_SAMPLE_NUM_GRP_7); cnt++ ) {
        SampleAdc_Group7_Buf[cnt] = 0x0000U;
    }

    /*
     * Hardware triggered One-Shot conversion with notification
     */
    SampleAdc_Case = SAMPLE_ADC_3_2_3_1;
    Adc_Init( &Adc_Config );

/* Reset buffer */
/* Enabling notifications and HW triggers */
Adc_EnableGroupNotification( AdcConf_AdcGroup_AdcGroup5 );
SampleAdc_Ret = Adc_SetupResultBuffer( AdcConf_AdcGroup_AdcGroup5, &SampleAdc_Group5_Buf[0] );
Adc_EnableHardwareTrigger( AdcConf_AdcGroup_AdcGroup5 );

/* Wait until notified */
while ( 1U > SampleAdc_NtfCallCnt1 );
SampleAdc_NtfCallCnt1 = 0;

/* Disabling notifications and HW triggers */
Adc_DisableGroupNotification( AdcConf_AdcGroup_AdcGroup5 );
Adc_DisableHardwareTrigger( AdcConf_AdcGroup_AdcGroup5 );
Adc_DeInit();

/*
 * Sw trigger, CONTINUOUS, single, notification enabled
 */
SampleAdc_Case = SAMPLE_ADC_3_2_3_2;
Adc_Init( &Adc_Config );

/* Start conversion of channel group */
SampleAdc_Ret = Adc_SetupResultBuffer( AdcConf_AdcGroup_AdcGroup7, &SampleAdc_Group7_Buf[0] );
Adc_EnableGroupNotification( AdcConf_AdcGroup_AdcGroup7 );
Adc_StartGroupConversion( AdcConf_AdcGroup_AdcGroup7 );

/* Wait until notified */
while ( 1U > SampleAdc_NtfCallCnt1 );
SampleAdc_NtfCallCnt1 = 0;

/* Disabling notification and stop conversion of channel group */
Adc_DisableGroupNotification( AdcConf_AdcGroup_AdcGroup7 );
Adc_StopGroupConversion( AdcConf_AdcGroup_AdcGroup7 );
Adc_DeInit();

/*
 * Sw trigger, CONTINUOUS, LINEAR streaming, notification enabled
 */
/* Reset buffer */
SampleAdc_Case = SAMPLE_ADC_3_2_3_3;
Adc_Init( &Adc_Config );

/* Start conversion of channel group */
Adc_EnableGroupNotification( AdcConf_AdcGroup_AdcGroup0 );
SampleAdc_Ret = Adc_SetupResultBuffer( AdcConf_AdcGroup_AdcGroup0, &SampleAdc_Group0_Buf[0] );
Adc_StartGroupConversion( AdcConf_AdcGroup_AdcGroup0 );

/* Wait until the streaming buffer is filled with results. */
while ( 3U > SampleAdc_NtfCallCnt1 );
SampleAdc_NtfCallCnt1 = 0U;

/* Disabling notification and stop conversion of channel group */
Adc_DisableGroupNotification( AdcConf_AdcGroup_AdcGroup0 );
Adc_StopGroupConversion    ( AdcConf_AdcGroup_AdcGroup0 );
Adc_DeInit();

/*
 * Sw trigger, CONTINUOUS, CIRCULAR streaming, notification enabled
 */
/* Reset buffer */
SampleAdc_Case = SAMPLE_ADC_3_2_3_4;
Adc_Init( &Adc_Config );

/* Start conversion of channel group */
SampleAdc_Ret = Adc_SetupResultBuffer( AdcConf_AdcGroup_AdcGroup6, &SampleAdc_Group6_Buf[0] );
Adc_EnableGroupNotification( AdcConf_AdcGroup_AdcGroup6 );
Adc_StartGroupConversion    ( AdcConf_AdcGroup_AdcGroup6 );

/* Convert 2 round before stop */
while ( 6 > SampleAdc_NtfCallCnt2 );
SampleAdc_NtfCallCnt2 = 0;

/* Disabling notifications and stop conversion of channel group */
Adc_DisableGroupNotification( AdcConf_AdcGroup_AdcGroup6 );
Adc_StopGroupConversion    ( AdcConf_AdcGroup_AdcGroup6 );
Adc_DeInit();

/* End of program */
while ( TRUE ) {
    FUNC_NO_OPERATION;
}
}
#endif  /* SAMPLE_ADC_ENABLE != FALSE */

void SampleAdc_GroupNotification_1( void ) {
#if ( SAMPLE_ADC_ENABLE != FALSE )
    SampleAdc_NtfCallCnt1++;

    switch( SampleAdc_Case ) {
    case SAMPLE_ADC_3_2_3_1:
        /* Get result */
        SampleAdc_Ret = Adc_ReadGroup( AdcConf_AdcGroup_AdcGroup5, &SampleAdc_Group5_Result[0] );
        break;
    case SAMPLE_ADC_3_2_3_2:
        /* Get result */
        SampleAdc_Ret = Adc_ReadGroup( AdcConf_AdcGroup_AdcGroup7, &SampleAdc_Group7_Result[0] );
        break;
    case SAMPLE_ADC_3_2_3_3:
        /* Get result */
        SampleAdc_Ret = Adc_ReadGroup( AdcConf_AdcGroup_AdcGroup0, &SampleAdc_Group0_Result[0] );
        break;
    default:
        break;
    }
#endif
}

void SampleAdc_GroupNotification_2( void ) {
#if ( SAMPLE_ADC_ENABLE != FALSE )
    SampleAdc_NtfCallCnt2++;

    switch( SampleAdc_Case ) {
    case SAMPLE_ADC_3_2_3_4:
        if ( 3U == SampleAdc_NtfCallCnt2 ) {
            /* Get result */
            SampleAdc_Ret = Adc_ReadGroup( AdcConf_AdcGroup_AdcGroup6, &SampleAdc_Group6_Result[0] );
        }
        break;
    default:
        break;
    }
#endif
}

/* EOF SampleAdc.c ************************************************************/