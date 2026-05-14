/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : SampleGpt.c                                                  */
/* Version     : v1.00.02                                                     */
/* Contents    : Gpt sample application.                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "SampleGpt.h"
#include "Gpt.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*  macros                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_GPT_ENABLE != FALSE )
bool_t           SampleGpt_Notification = FALSE;
bool_t           SampleGpt_Wakeup       = FALSE;
Gpt_ValueType    SampleGpt_Value        = 0U;
Std_ReturnType   SampleGpt_Ret;
#endif

/*----------------------------------------------------------------------------*/
* functions and function style macros
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_GPT_ENABLE != FALSE )
void SampleGpt( void ) {
    uint32 PredefTimerBuff = 0x00000000;

    /*
     * 3.2.3.1 Sample program for Timer processing
     */

    /* Initialize the Gpt module */
    Gpt_Init( &Gpt_Config );

    /* Start the timer */
    Gpt_StartTimer( GPT_70_CH_SAMPLE_TAU, 1000U );

    /* Get elapsed time */
    SampleGpt_Value = Gpt_GetTimeElapsed( GPT_70_CH_SAMPLE_TAU );

    /* Get remaining time */
    SampleGpt_Value = Gpt_GetTimeRemaining( GPT_70_CH_SAMPLE_TAU );

    /* Get predef timer value */
    SampleGpt_Ret = Gpt_GetPredefTimerValue( GPT_PREDEF_TIMER_1US_16BIT, &PredefTimerBuff );

    /* Stop the timer */
    Gpt_StopTimer( GPT_70_CH_SAMPLE_TAU );

    /* De-initialize the Gpt module */
    Gpt_DeInit();

    /*
     * 3.2.3.2 Sample program for Wakeup interrupt processing
     */

    /* Initialize the Gpt module */
    Gpt_Init( &Gpt_Config );

    /* Enable wakeup interrupt */
    Gpt_EnableWakeup( GPT_70_CH_WAKEUP );

    /* Start the timer */
    Gpt_StartTimer( GPT_70_CH_WAKEUP, 1000U );

    /* Set the mode to GPT_MODE_SLEEP */
    Gpt_SetMode( GPT_MODE_SLEEP );

    /* Wakeup interrupt processing */
    /* Gpt_CheckWakeup will be called */
    while ( FALSE == SampleGpt_Wakeup ) {
        FUNC_NO_OPERATION;
    }
    SampleGpt_Wakeup = FALSE;

    /* Disable wakeup interrupt and verify that the wakeup interrupt is not performed */
    Gpt_DisableWakeup( GPT_70_CH_WAKEUP );
    /* Stop the timer */
    Gpt_StopTimer( GPT_70_CH_SAMPLE_TAU );

    /* Set the mode to GPT_MODE_NORMAL */
    Gpt_SetMode( GPT_MODE_NORMAL );

    /*
     * 3.2.3.3 Sample program for Timer interrupt notification processing
     */

    /* Initialize the Gpt module */
    Gpt_Init( &Gpt_Config );

    /* Enable timer interrupt notification */
    Gpt_EnableNotification( GPT_70_CH_SAMPLE_TAU );

    /* Start the timer */
    Gpt_StartTimer( GPT_70_CH_SAMPLE_TAU, 1000U );

    /* Wait until notified */
    while ( FALSE == SampleGpt_Notification ) {
        FUNC_NO_OPERATION;
    }

    /* Disable timer interrupt notification */
    Gpt_DisableNotification( GPT_70_CH_SAMPLE_TAU );

    /* Start the timer, and verify that interrupt is not notified */
    Gpt_StartTimer( GPT_70_CH_SAMPLE_TAU, 1000U );
    SampleGpt_Notification = FALSE;

    /* End of program */
    while ( FALSE == SampleGpt_Notification ) {
        /* Make sure notifications are not called */
        /* Correct End */
        FUNC_NO_OPERATION;
    }
    SampleGpt_Notification = FALSE;

    /* Error End of program */
    while ( TRUE ) {
        FUNC_NO_OPERATION;
    }
}
#endif  /* SAMPLE_GPT_ENABLE != FALSE */

void TAU01Notification( void ) {
#if ( SAMPLE_GPT_ENABLE != FALSE )
    /* Timer interrupt is notified */
    SampleGpt_Notification = TRUE;
#endif
}

void TRJ0Notification( void ) {
}

void TRD01Notification( void ) {
}

void main1s( void ) {
}
