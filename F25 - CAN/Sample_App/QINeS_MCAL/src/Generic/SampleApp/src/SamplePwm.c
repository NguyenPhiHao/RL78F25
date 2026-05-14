/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : SamplePwm.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : Pwm sample application.                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Pwm.h"
#include "Pwm_70_RL78F2X.h"
#include "Dio.h"
#include "SamplePwm.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define Sample_Pwm_Init                   (0U)
#define Sample_Pwm_SetDutyCycle           (1U)
#define Sample_Pwm_SetPeriodAndDuty       (2U)
#define Sample_Pwm_SetOutPutToIdle        (3U)
#define Sample_Pwm_CobinationProcess_TAU  (4U)
#define Sample_Pwm_CobinationProcess_TRD  (5U)

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_PWM_ENABLE != FALSE )
uint16  Pwm_SampleCaseNumber       = 6U;
bool_t  Pwm_InterruptDetect_TAU_A0 = FALSE;
bool_t  Pwm_InterruptDetect_TRD_00 = FALSE;
#endif

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_PWM_ENABLE != FALSE )
void wait_sync( uint32 counter )
{
    volatile uint32 i;
    for( i=0; i<counter; i++ ) {
    }
}
#endif /* #if ( SAMPLE_PWM_ENABLE != FALSE ) */

#if ( SAMPLE_PWM_ENABLE != FALSE )
#if ( PWM_DE_INIT_API != FALSE )
#if ( PWM_SET_DUTY_CYCLE_API != FALSE )
#if ( PWM_SET_PERIOD_AND_DUTY_API != FALSE )
#if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE )
#if ( PWM_NOTIFICATION_SUPPORTED != FALSE )
void SamplePwm( void ) {

    uint16 Pwm_SampleCounter;

    for ( Pwm_SampleCounter=0; Pwm_SampleCounter < Pwm_SampleCaseNumber; Pwm_SampleCounter++ ){
        switch ( Pwm_SampleCounter ) {
        case Sample_Pwm_Init:
            /* Pwm Initialization */
            Pwm_Init( &Pwm_Config );

            /* Flip port to capture Pwm output wave */
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* reset port output */
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );
           
            /* Pwm de-Initialization */
            Pwm_DeInit();
            break;
         
         case Sample_Pwm_SetDutyCycle:
            /* Pwm Initialization */
            Pwm_Init( &Pwm_Config );
            wait_sync( (uint32)1000000U );

            /* Change dutycycle ( TAU Unit0 Ch0,1 TAU Unit1 Ch0,1 TRDe Unit0 Ch0 ) */
            /* TAU Unit0 Ch0,1 dutycycle change 25% */
            Pwm_SetDutyCycle( PWM_70_IDX_TAU_A0, 0x2000U );
            /* TAU Unit0 Ch0,1 dutycycle change 75% */
            Pwm_SetDutyCycle( PWM_70_IDX_TAU_A0, 0x6000U );
            /* TAU Unit1 Ch0,1 dutycycle change 25% */
            Pwm_SetDutyCycle( PWM_70_IDX_TAU_B0, 0x2000U );
            /* TRDe Unit0 Ch0 dutycycle change 75% */
            Pwm_SetDutyCycle( PWM_70_IDX_TRD_00, 0x6000U );

            /* Flip port to capture Pwm output wave */
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* reset port output */
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );
           
            /* Pwm de-Initialization */
            Pwm_DeInit();
            break;

         case Sample_Pwm_SetPeriodAndDuty:
            /* Pwm Initialization */
            Pwm_Init( &Pwm_Config );
            wait_sync( (uint32)1000000U );

            /* Change period and dutycycle ( TAU Unit0 Ch0,1 TAU Unit1 Ch0,1 TRDe Unit0 Ch0 ) */
            /* TAU Unit0 Ch0,1 period changes 1.5ms, dutycycle changes 75% */
            Pwm_SetPeriodAndDuty( PWM_70_IDX_TAU_A0, 0x0753U, 0x6000U );
            /* TAU Unit1 Ch0,1 period changes 1.5ms, dutycycle change 25% */
            Pwm_SetPeriodAndDuty( PWM_70_IDX_TAU_B0, 0xEA60U, 0x2000U );
            /* TRDe Unit0 Ch0 period changes 0.5ms, dutycycle change 75% */
            Pwm_SetPeriodAndDuty( PWM_70_IDX_TRD_00, 0x4E20U, 0x6000U );

            /* Flip port to capture Pwm output wave */
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* reset port output */
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* Pwm de-Initialization */
            Pwm_DeInit();
            break;

         case Sample_Pwm_SetOutPutToIdle:
            /* Pwm Initialization */
            Pwm_Init( &Pwm_Config );
            wait_sync( (uint32)1000000U );

            /* Set IDLE output ( TAU Unit0 Ch0,1 TAU Unit1 Ch0,1 TRDe Unit0 Ch0 ) */
            /* Set PWM_LOW */
            Pwm_SetOutputToIdle( PWM_70_IDX_TAU_A0 );
            Pwm_SetOutputToIdle( PWM_70_IDX_TAU_B0 );
            Pwm_SetOutputToIdle( PWM_70_IDX_TRD_00 );

            /* Flip port to capture Pwm output wave */
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* reset port output */
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );
           
            /* Pwm de-Initialization */
            Pwm_DeInit();
            break;

        case Sample_Pwm_CobinationProcess_TAU:
            /* Pwm Initialization */
            Pwm_Init( &Pwm_Config );
            wait_sync( (uint32)1000000U );

            /* Set IDLE output and disable interrupts */
            Pwm_DisableNotification( PWM_70_IDX_TAU_A0 );
            Pwm_SetOutputToIdle( PWM_70_IDX_TAU_A0 );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );

            /* reset port output */
            wait_sync( (uint32)1000000U );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* Change dutycycle and enable interrupts */
            Pwm_SetDutyCycle( PWM_70_IDX_TAU_A0, 0x6000U );
            Pwm_EnableNotification( PWM_70_IDX_TAU_A0, PWM_RISING_EDGE );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            while( 1 ) {
                if( Pwm_InterruptDetect_TAU_A0 == TRUE ) {
                    break;
                }
            }

            /* reset port output */
            wait_sync( (uint32)1000000U );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* Set IDLE output and disable interrupts */
            Pwm_DisableNotification( PWM_70_IDX_TAU_A0 );
            Pwm_SetOutputToIdle( PWM_70_IDX_TAU_A0 );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            Pwm_InterruptDetect_TAU_A0 = FALSE;
    
            /* reset port output */
            wait_sync( (uint32)1000000U );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* Change period and dutycycle, and enable interrupts */
            Pwm_SetPeriodAndDuty( PWM_70_IDX_TAU_A0, 0x0271U, 0x2000U);
            Pwm_EnableNotification( PWM_70_IDX_TAU_A0, PWM_RISING_EDGE );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            while( 1 ) {
                if( Pwm_InterruptDetect_TAU_A0 == TRUE ) {
                    break;
                }
            }

            /* reset port output */
            wait_sync( (uint32)1000000U );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* Set IDLE output and disable interrupts */
            Pwm_DisableNotification( PWM_70_IDX_TAU_A0 );
            Pwm_SetOutputToIdle( PWM_70_IDX_TAU_A0 );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            Pwm_InterruptDetect_TAU_A0 = FALSE;

            /* reset port output */
            wait_sync( (uint32)1000000U );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* Pwm de-Initialization */
            Pwm_DeInit();
            break;

        case Sample_Pwm_CobinationProcess_TRD:
            /* Pwm Initialization */
            Pwm_Init( &Pwm_Config );
            wait_sync( (uint32)1000000U );

            /* Set IDLE output and disable interrupts */
            Pwm_DisableNotification( PWM_70_IDX_TRD_00 );
            Pwm_SetOutputToIdle( PWM_70_IDX_TRD_00 );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );

            /* reset port output */
            wait_sync( (uint32)1000000U );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* Change dutycycle and enable interrupts */
            Pwm_SetDutyCycle( PWM_70_IDX_TRD_00, 0x6000U );
            Pwm_EnableNotification( PWM_70_IDX_TRD_00, PWM_RISING_EDGE );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            while( 1 ) {
                if( Pwm_InterruptDetect_TRD_00 == TRUE ) {
                    break;
                }
            }

            /* reset port output */
            wait_sync( (uint32)1000000U );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* Set IDLE output and disable interrupts */
            Pwm_DisableNotification( PWM_70_IDX_TRD_00 );
            Pwm_SetOutputToIdle( PWM_70_IDX_TRD_00 );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            Pwm_InterruptDetect_TRD_00 = FALSE;

            /* reset port output */
            wait_sync( (uint32)1000000U );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* Change period and dutycycle, and enable interrupts */
            Pwm_SetPeriodAndDuty( PWM_70_IDX_TRD_00, 0x4E20U, 0x2000U);
            Pwm_EnableNotification( PWM_70_IDX_TRD_00, PWM_FALLING_EDGE );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            while( 1 ) {
                if( Pwm_InterruptDetect_TRD_00 == TRUE ) {
                    break;
                }
            }

            /* reset port output */
            wait_sync( (uint32)1000000U );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)999900U );

            /* Set IDLE output and disable interrupts */
            Pwm_DisableNotification( PWM_70_IDX_TRD_00 );
            Pwm_SetOutputToIdle( PWM_70_IDX_TRD_00 );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            Pwm_InterruptDetect_TRD_00 = FALSE;

            /* reset port output */
            wait_sync( (uint32)1000000U );
            Dio_FlipChannel( DIO_70_CHANNEL_P67 );
            wait_sync( (uint32)1000000U );

            /* Pwm de-Initialization */
            Pwm_DeInit();
            break;

         default:
             break;
        }
    }
}
#endif /* #if ( SAMPLE_PWM_ENABLE != FALSE ) */
#endif /* #if ( PWM_DE_INIT_API != FALSE ) */
#endif /* #if ( PWM_SET_DUTY_CYCLE_API != FALSE ) */
#endif /* #if ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) */
#endif /* #if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) */
#endif /* #if ( PWM_NOTIFICATION_SUPPORTED != FALSE ) */

void SamplePwm_Notification_TAU_A0( void )
{
#if ( SAMPLE_PWM_ENABLE != FALSE )
    Dio_FlipChannel( DIO_70_CHANNEL_P66 );
    wait_sync( (uint32)200U );
    Dio_FlipChannel( DIO_70_CHANNEL_P66 );
    Pwm_InterruptDetect_TAU_A0 = TRUE;
#endif /* #if ( SAMPLE_PWM_ENABLE != FALSE ) */
}

void SamplePwm_Notification_TRD_00( void )
{
#if ( SAMPLE_PWM_ENABLE != FALSE )
    Dio_FlipChannel( DIO_70_CHANNEL_P66 );
    wait_sync( (uint32)50U );
    Dio_FlipChannel( DIO_70_CHANNEL_P66 );
    Pwm_InterruptDetect_TRD_00 = TRUE;
#endif /* #if ( SAMPLE_PWM_ENABLE != FALSE ) */
}

/* EOF SamplePwm.c ************************************************************/
