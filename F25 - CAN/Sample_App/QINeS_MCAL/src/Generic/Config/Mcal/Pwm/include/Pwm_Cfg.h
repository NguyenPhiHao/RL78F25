/*----------------------------------------------------------------------------*/
/* Copyright    : 2023 SCSK Corporation                                       */
/* System Name   : QINeS-Lite MCAL                                            */
/* File Name     : Pwm_Cfg.h                                                  */
/* Version       : v1.00.00                                                   */
/* Contents      : Pwm configuration header                                   */
/* Author        : h.tomita f.sawano                                          */
/* Note          : --                                                         */
/* History       : --                                                         */
/*----------------------------------------------------------------------------*/
/* Specification of PWM Driver                                                */
/*            R22-11                                                          */
/*----------------------------------------------------------------------------*/
#ifndef PWM_CFG_H
#define PWM_CFG_H

/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define PWM_70_VENDOR_ID_CFG_H                     (70U)
#define PWM_70_MODULE_ID_CFG_H                     (121U)

#define PWM_70_AR_RELEASE_MAJOR_VERSION_CFG_H      (22U)
#define PWM_70_AR_RELEASE_MINOR_VERSION_CFG_H      (11U)
#define PWM_70_AR_RELEASE_REVISION_VERSION_CFG_H   (0U)

#define PWM_70_SW_MAJOR_VERSION_CFG_H              (1U)
#define PWM_70_SW_MINOR_VERSION_CFG_H              (0U)
#define PWM_70_SW_PATCH_VERSION_CFG_H              (0U)

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* [ECUC_PWM_00131] Switch for enabling the development error detection */
#define PWM_DEV_ERROR_DETECT               (TRUE)

/* [ECUC_PWM_00133] Switch to indicate that the notifications are supported */
#define PWM_NOTIFICATION_SUPPORTED         (TRUE)

/* [ECUC_PWM_00132] Switch for enabling the update of the duty cycle parameter at the end of the current period */
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD    (FALSE)

/* [ECUC_PWM_00134] Switch for enabling the update of the period parameter at the end of the current period */
#define PWM_DUTY_PERIOD_UPDATED_ENDPERIOD  (FALSE)

/* [ECUC_PWM_00126] */
/* Define what API functions to enable */
/* PwmConfigurationOfPoptApiServices */
/* [ECUC_PWM_00127] Switch of function Pwm_GetOutputState */
#define PWM_GET_OUTPUT_STATE_API           (FALSE)

/* [ECUC_PWM_00130] Switch of function Pwm_SetPeriodAndDuty */
#define PWM_SET_PERIOD_AND_DUTY_API        (TRUE)

/* [ECUC_PWM_00141] Switch of function Pwm_DeInit */
#define PWM_DE_INIT_API                    (TRUE)

/* [ECUC_PWM_00128] Switch of function Pwm_SetDutyCycle */
#define PWM_SET_DUTY_CYCLE_API             (TRUE)

/* [ECUC_PWM_00129] Switch of function Pwm_SetOutputToIdle */
#define PWM_SET_OUTPUT_TO_IDLE_API         (TRUE)

/* [ECUC_PWM_00135] Switch of function Pwm_GetVersionInfo */
#define PWM_VERSION_INFO_API               (TRUE)

/* PWM CHANNEL USE/NO USE DEFINE */
#define PWM_70_CHANNEL_A0_USE              (TRUE)  /* PWM CHANNEL A0 (TAU0-01) */
#define PWM_70_CHANNEL_A1_USE              (FALSE) /* PWM CHANNEL A1 (TAU0-03) */
#define PWM_70_CHANNEL_A2_USE              (FALSE) /* PWM CHANNEL A2 (TAU0-05) */
#define PWM_70_CHANNEL_A3_USE              (FALSE) /* PWM CHANNEL A3 (TAU0-07) */
#define PWM_70_CHANNEL_B0_USE              (TRUE)  /* PWM CHANNEL B0 (TAU10-11) */
#define PWM_70_CHANNEL_B1_USE              (FALSE) /* PWM CHANNEL B1 (TAU12-13) */
#define PWM_70_CHANNEL_B2_USE              (FALSE) /* PWM CHANNEL B2 (TAU14-15) */
#define PWM_70_CHANNEL_B3_USE              (FALSE) /* PWM CHANNEL B3 (TAU16-17) */
#define PWM_70_CHANNEL_TRD00_USE           (TRUE)  /* PWM CHANNEL TRD00 */
#define PWM_70_CHANNEL_TRD01_USE           (FALSE) /* PWM CHANNEL TRD01 */

/* The number of registered PWM channel configuration */
#define PWM_70_NUM_OF_PWMCHANNEL           (3U)

/* [ECUC_PWM_00139] Module instance ID */
/* As a concept there is a definition in AUTOSAR, */
/* but because the name is not specified, we followed the QINeS naming convention */
#define PWM_70_INSTANCE_ID                 (0U)

/* --- Define Channel Index --- */
#define PWM_70_CH_A0                       (0U)
#define PWM_70_CH_B0                       (1U)
#define PWM_70_CH_TRD00                    (2U)

/* --- Define Channel Index for ISR --- */
#if ( PWM_70_CHANNEL_A0_USE != FALSE )
#define PWM_70_IDX_TAU_A0              ( PWM_70_CH_A0 )
#endif /* #if ( PWM_70_CHANNEL_A0_USE != FALSE ) */

#if ( PWM_70_CHANNEL_A1_USE != FALSE )
#define PWM_70_IDX_TAU_A1              ( PWM_70_CH_A1 )
#endif /* #if ( PWM_70_CHANNEL_A1_USE != FALSE ) */

#if ( PWM_70_CHANNEL_A2_USE != FALSE )
#define PWM_70_IDX_TAU_A2              ( PWM_70_CH_A2 )
#endif /* #if ( PWM_70_CHANNEL_A2_USE != FALSE ) */

#if ( PWM_70_CHANNEL_A3_USE != FALSE )
#define PWM_70_IDX_TAU_A3              ( PWM_70_CH_A3 )
#endif /* #if ( PWM_70_CHANNEL_A3_USE != FALSE ) */

#if ( PWM_70_CHANNEL_B0_USE != FALSE )
#define PWM_70_IDX_TAU_B0              ( PWM_70_CH_B0 )
#endif /* #if ( PWM_70_CHANNEL_B0_USE != FALSE ) */

#if ( PWM_70_CHANNEL_B1_USE != FALSE )
#define PWM_70_IDX_TAU_B1              ( PWM_70_CH_B1 )
#endif /* #if ( PWM_70_CHANNEL_B1_USE != FALSE ) */

#if ( PWM_70_CHANNEL_B2_USE != FALSE )
#define PWM_70_IDX_TAU_B2              ( PWM_70_CH_B2 )
#endif /* #if ( PWM_70_CHANNEL_B2_USE != FALSE ) */

#if ( PWM_70_CHANNEL_B3_USE != FALSE )
#define PWM_70_IDX_TAU_B3              ( PWM_70_CH_B3 )
#endif /* #if ( PWM_70_CHANNEL_B3_USE != FALSE ) */

#if ( PWM_70_CHANNEL_TRD00_USE != FALSE )
#define PWM_70_IDX_TRD_00              ( PWM_70_CH_TRD00 )
#endif /* #if ( PWM_70_CHANNEL_TRD00_USE != FALSE ) */

#if ( PWM_70_CHANNEL_TRD01_USE != FALSE )
#define PWM_70_IDX_TRD_01              ( PWM_70_CH_TRD01 )
#endif /* #if ( PWM_70_CHANNEL_TRD01_USE != FALSE ) */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
extern void SamplePwm_Notification_TAU_A0( void );
extern void SamplePwm_Notification_TRD_00( void );

#endif /* PWM_CFG_H */

/* EOF Pwm_Cfg.h **********************************************************/
