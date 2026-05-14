/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : SampleIcu.c                                                  */
/* Version     : v1.00.01                                                     */
/* Contents    : Icu sample application.                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Icu.h"
#include "Dio.h"
#include "Pwm.h"
#include "SampleIcu.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*  macros                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_ICU_ENABLE != FALSE )
bool_t SampleIcu_Wakeup;
#endif

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_ICU_ENABLE != FALSE )
Icu_EdgeNumberType SampleIcu_EdgeNum;
Icu_IndexType      SampleIcu_TimestampIndex;
Icu_ValueType      SampleIcu_Buffer[16];
Icu_ValueType      SampleIcu_ElapsedTime;
Icu_DutyCycleType  SampleIcu_Duty;
#endif

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_ICU_ENABLE != FALSE )
static void wait_sync( uint32 counter );
#endif

/*------------------------------------------------------------------------------*/
/* functions and function style macros                                          */
/*------------------------------------------------------------------------------*/
#if ( SAMPLE_ICU_ENABLE != FALSE )
void SampleIcu( void ) {
    uint8_least i;

    /*
     * Set operation mode and wakeup interrupt
     */
    Icu_Init( &Icu_Config );
    SampleIcu_Wakeup = FALSE;

    /* Enable wakeup function */
    Icu_EnableWakeup( ICU_CHANNEL_5 );

    /* Set the Icu module mode to SLEEP */
    Icu_SetMode( ICU_MODE_SLEEP );

    /* Enable signal detection */
    Icu_EnableEdgeDetection( ICU_CHANNEL_5 );

    /* Generate waveform and trigger rising edge once */
    for ( i = 0U; i < 2U; i++ ) {
        Dio_FlipChannel( DIO_70_CHANNEL_P02 );
        wait_sync( 50U );
    }

    /* Wakeup interrupt operation */
    /* Wait until EcuM_CheckWakeup is called */
    while ( FALSE == SampleIcu_Wakeup );

    /* Disable signal detection */
    Icu_DisableEdgeDetection( ICU_CHANNEL_5 );

    /* Disable wakeup */
    Icu_DisableWakeup( ICU_CHANNEL_5 );

    /* Set the Icu module mode to NORMAL */
    Icu_SetMode( ICU_MODE_NORMAL );

    Icu_DeInit();

    /*
     * Timestamp measurement
     */
    Icu_Init( &Icu_Config );

    /* Change the channel to falling edge detection */
    Icu_SetActivationCondition( ICU_CHANNEL_0, ICU_FALLING_EDGE );

    /* Enable interrupt notification */
    Icu_EnableNotification( ICU_CHANNEL_0 );
/* Start timestamp measurement */
Icu_StartTimestamp( ICU_CHANNEL_0, &SampleIcu_Buffer[0], 16U, 1U );

/* Generate waveform and trigger falling edge once */
for ( i = 0U; i < 10U; i++ ) {
    Dio_FlipChannel( DIO_70_CHANNEL_P03 );
    wait_sync( 50U );
}

/* Get timestamp index */
SampleIcu_TimestampIndex = Icu_GetTimestampIndex( ICU_CHANNEL_0 );

/* Stop timestamp measurement */
Icu_StopTimestamp( ICU_CHANNEL_0 );

/* Disable interrupt notification */
Icu_DisableNotification( ICU_CHANNEL_0 );

Icu_DeInit();

/*
 * Signal measurement
 */
Icu_Init( &Icu_Config );
Pwm_Init( &Pwm_Config );

wait_sync( 100000U );
/* Start signal measurement */
Icu_StartSignalMeasurement( ICU_CHANNEL_1 );
wait_sync( 100000U );
/* Generate waveform with duty ratio of 25% */
/* Flip port to capture Pwm output wave */
Dio_FlipChannel( DIO_70_CHANNEL_P67 );
wait_sync( 100000U );

/* Reset port output */
Dio_FlipChannel( DIO_70_CHANNEL_P67 );
wait_sync( 100000U );

/* Get elapsed time */
SampleIcu_ElapsedTime = Icu_GetTimeElapsed( ICU_CHANNEL_1 );

/* Stop signal measurement */
Icu_StopSignalMeasurement( ICU_CHANNEL_1 );

Pwm_DeInit();
Icu_DeInit();

/*
 * Edge count
 */
Icu_Init( &Icu_Config );

/* Change channel to rising edge detection */
Icu_SetActivationCondition( ICU_CHANNEL_4, ICU_RISING_EDGE );
/* Enable edge count */
Icu_EnableEdgeCount( ICU_CHANNEL_4 );

/* Generate waveform and trigger rising edge once */
for ( i = 0U; i < 4U; i++ ) {
    Dio_FlipChannel( DIO_70_CHANNEL_P01 );
    wait_sync( 50U );
}

/* Get edge count */
SampleIcu_EdgeNum = Icu_GetEdgeNumbers( ICU_CHANNEL_4 );

/* Reset edge count */
Icu_ResetEdgeCount( ICU_CHANNEL_4 );

/* Generate waveform and trigger rising edge once */
for ( i = 0U; i < 2U; i++ ) {
    Dio_FlipChannel( DIO_70_CHANNEL_P01 );
    wait_sync( 50U );
}

/* Get edge count */
SampleIcu_EdgeNum = Icu_GetEdgeNumbers( ICU_CHANNEL_4 );

/* Disable channel edge count */
Icu_DisableEdgeCount( ICU_CHANNEL_4 );

Icu_DeInit();

/*
 * Edge detection
 */
Icu_Init( &Icu_Config );

/* Change the channel to falling edge detection */
Icu_SetActivationCondition( ICU_CHANNEL_5, ICU_FALLING_EDGE );

/* Enable interrupt notification */
Icu_EnableNotification( ICU_CHANNEL_5 );

/* Enable edge detection */
Icu_EnableEdgeDetection( ICU_CHANNEL_5 );

/* Generate waveform and trigger rising edge once,
   and check that the notification function is called */
for ( i = 0U; i < 3U; i++ ) {
    Dio_FlipChannel( DIO_70_CHANNEL_P02 );
    wait_sync( 50U );
}

/* Check that the channel state is ICU_IDLE */
while ( ICU_IDLE == Icu_GetInputState( ICU_CHANNEL_5 ) );

/* Disable edge detection */
Icu_DisableEdgeDetection( ICU_CHANNEL_5 );

Icu_DeInit();

/* End of program */
while (TRUE) {
    FUNC_NO_OPERATION;
}
# endif

void Icu_SampleCallbackFunctionTAU( void ) {
}

void Icu_SampleCallbackFunctionINTP ( void ) {
}


#if (SAMPLE_ICU_ENABLE != FALSE)

static void wait_sync(uint32 counter) {
    volatile uint32_least i;

    for(i = 0U; i < counter; i++);
}
#endif


/* EOF SampleIcu.c ****************