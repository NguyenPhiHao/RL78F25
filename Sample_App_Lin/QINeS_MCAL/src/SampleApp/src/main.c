/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : main.c                                                       */
/* Version     : v1.00.01                                                     */
/* Contents    : Main processing of samples.                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Adc.h"
#include "Spi.h"
#include "Gpt.h"
#include "Wdg.h"
#include "Can.h"
#include "Pwm.h"
#include "Icu.h"
#include "Lin.h"
#include "Fls.h"
#include "SampleMcu.h"
#include "SamplePort.h"
#include "SampleDio.h"
#include "SampleAdc.h"
#include "SampleCrypto.h"
#include "SampleSpi.h"
#include "SampleGpt.h"
#include "SampleWdg.h"
#include "SampleCan.h"
#include "SamplePwm.h"
#include "SampleIcu.h"
#include "SampleFls.h"
#include "SampleLin.h"
#if ( COMPILER == COMPILER_IAR )
#include "intrinsics.h"
#endif
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define MK0L    ( *(volatile unsigned char QL_70_NEAR *)0xFFE4U )
#define MK0H    ( *(volatile unsigned char QL_70_NEAR *)0xFFE5U )
#define MK1L    ( *(volatile unsigned char QL_70_NEAR *)0xFFE6U )
#define MK1H    ( *(volatile unsigned char QL_70_NEAR *)0xFFE7U )
#define MK2L    ( *(volatile unsigned char QL_70_NEAR *)0xFFD4U )
#define MK2H    ( *(volatile unsigned char QL_70_NEAR *)0xFFD5U )
#define MK3L    ( *(volatile unsigned char QL_70_NEAR *)0xFFD6U )
#define MK3H    ( *(volatile unsigned char QL_70_NEAR *)0xFFD7U )

#define MK0L_SETMASK   ( 0xFFU & MK0L_ICU_MASK & MK0L_WDG_MASK )
#define MK0H_SETMASK   ( 0xFFU & MK0H_PWM_MASK & MK0H_ICU_MASK & MK0H_ADC_MASK & MK0H_GPT_MASK )
#define MK1L_SETMASK   ( 0xFFU & MK1L_PWM_MASK & MK1L_ICU_MASK & MK1L_GPT_MASK )
#define MK1H_SETMASK   ( 0xFFU & MK1H_PWM_MASK & MK1H_ICU_MASK & MK1H_ADC_MASK )
#define MK2L_SETMASK   ( 0xFFU & MK2L_PWM_MASK & MK2L_ICU_MASK & MK2L_GPT_MASK )
#define MK2H_SETMASK   ( 0xFFU & MK2H_PWM_MASK & MK2H_ICU_MASK & MK2H_ADC_MASK )
#define MK3L_SETMASK   ( 0xFFU & MK3L_PWM_MASK & MK3L_ICU_MASK )
#define MK3H_SETMASK   ( 0xFFU & MK3H_ADC_MASK & MK3H_ICU_MASK & MK3H_GPT_MASK )

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#if ( COMPILER == COMPILER_CC )
    /* In the CC-RL compiler, Option Bytes are defined in optionbyte.asm file. */
#elif ( COMPILER == COMPILER_IAR )
#if ( SAMPLE_WDG_ENABLE == TRUE )
__root __far const unsigned char option_bytes[4] @ 0x00C0 = {
    0xB7, /* Option Byte 0 for Wdg SampleApp */
    0xF3, /* Option Byte 1 */
    0xF8, /* Option Byte 2 */
    0x87  /* Option Byte 3 */
#else
__root __far const unsigned char option_bytes[4] @ 0x00C0 = {
    0x6E, /* Option Byte 0 */
    0xF3, /* Option Byte 1 */
    0xF8, /* Option Byte 2 */
    0x87  /* Option Byte 3 */
#endif /* SAMPLE_WDG_ENABLE == TRUE */
};
#endif

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
void main( void ) {

#if ( SAMPLE_MCU_ENABLE != FALSE )
    SampleMcu();
#endif /* #if ( SAMPLE_MCU_ENABLE != FALSE ) */
    Mcu_PllStatusType   pllSts;

    /* Initialization of clock and cpu mode for RL78/F24 100pin sample board */
    Mcu_Init( &Mcu_Config );
    Mcu_InitClock( McuConf_McuClockSettingConfig_0 );
    do {
        /* check PLL is loked before call Mcu_DistibutePllClock() */
        pllSts = Mcu_GetPllStatus();
    } while( MCU_PLL_UNLOCKED == pllSts );
    Mcu_DistributePllClock();    /* activate the PLL clock */

    Mcu_SetMode( MCU_70_MODE_NORMAL );

#if ( SAMPLE_PORT_ENABLE != FALSE )
    SamplePort();
#endif /* #if ( SAMPLE_PORT_ENABLE != FALSE ) */

    Port_Init( &Port_Config );

    /* Interrupt mask clear */
    MK0L = MK0L & MK0L_SETMASK;
    MK0H = MK0H & MK0H_SETMASK;
    MK1L = MK1L & MK1L_SETMASK;
    MK1H = MK1H & MK1H_SETMASK;
    MK2L = MK2L & MK2L_SETMASK;
    MK2H = MK2H & MK2H_SETMASK;
    MK3L = MK3L & MK3L_SETMASK;
    MK3H = MK3H & MK3H_SETMASK;

    FUNC_ENABLE_INTERRUPT;

#if ( SAMPLE_DIO_ENABLE != FALSE )
    SampleDio();
#endif /* #if ( SAMPLE_DIO_ENABLE != FALSE ) */

#if ( SAMPLE_GPT_ENABLE != FALSE )
    SampleGpt();
#endif /* #if ( SAMPLE_GPT_ENABLE != FALSE ) */

#if ( SAMPLE_WDG_ENABLE != FALSE )
    SampleWdg();
#endif /* #if ( SAMPLE_WDG_ENABLE != FALSE ) */

#if ( SAMPLE_ADC_ENABLE != FALSE )
    SampleAdc();
#endif /* #if ( SAMPLE_ADC_ENABLE != FALSE ) */

#if ( SAMPLE_CAN_ENABLE != FALSE )
    SampleCan();
#endif /* #if ( SAMPLE_CAN_ENABLE != FALSE ) */

#if ( SAMPLE_CRYPTO_ENABLE != FALSE )
    SampleCrypto();
#endif /* #if ( SAMPLE_CRYPTO_ENABLE != FALSE ) */

#if ( SAMPLE_SPI_ENABLE != FALSE )
    SampleSpi_Init();
    SampleSpi();
#endif /* #if ( SAMPLE_SPI_ENABLE != FALSE ) */

#if ( SAMPLE_LIN_ENABLE != FALSE )
    SampleLin_Init();
    SampleLin();
#endif /* #if ( SAMPLE_LIN_ENABLE != FALSE ) */

#if ( SAMPLE_PWM_ENABLE != FALSE )
    SamplePwm();
#endif /* #if ( SAMPLE_PWM_ENABLE != FALSE ) */

#if ( SAMPLE_ICU_ENABLE != FALSE )
    SampleIcu();
#endif /* #if ( SAMPLE_ICU_ENABLE != FALSE ) */

#if ( SAMPLE_FLS_ENABLE != FALSE )
    SampleFls();
#endif /* #if ( SAMPLE_FLS_ENABLE != FALSE ) */

    /* End of program */
    while ( TRUE ) {
        FUNC_NO_OPERATION;
    }
}

/* EOF main.c *****************************************************************/