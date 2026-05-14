/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt_Cfg.h                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : Gpt configuration header                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of GPT Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef GPT_CFG_H_
#define GPT_CFG_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_CFG_H                      ( 70U )
#define GPT_70_MODULE_ID_CFG_H                      ( 100U )

#define GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H       ( 22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H       ( 11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_CFG_H    ( 0U )

#define GPT_70_SW_MAJOR_VERSION_CFG_H               ( 1U )
#define GPT_70_SW_MINOR_VERSION_CFG_H               ( 0U )
#define GPT_70_SW_PATCH_VERSION_CFG_H               ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H    != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H    != STD_TYPES_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_70_Cfg.h and Std_Types.h are different"
#endif

/* Std_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/* --- Define what API functions to enable ---------------------------------- */
#define GPT_DEINIT_API                      ( TRUE )      /* [ECUC_Gpt_00314] */
#define GPT_ENABLE_DISABLE_NOTIFICATION_API ( TRUE )      /* [ECUC_Gpt_00315] */
#define GPT_TIME_ELAPSED_API                ( TRUE )      /* [ECUC_Gpt_00317] */
#define GPT_TIME_REMAINING_API              ( TRUE )      /* [ECUC_Gpt_00318] */
#define GPT_VERSION_INFO_API                ( TRUE )     /* [ECUC_Gpt_00319] */
#define GPT_WAKEUP_FUNCTIONALITY_API        ( TRUE )      /* [ECUC_Gpt_00320] */
#define GPT_DEV_ERROR_DETECT                ( TRUE )     /* [ECUC_Gpt_00321] */
#define GPT_REPORT_WAKEUP_SOURCE            ( TRUE )      /* [ECUC_Gpt_00322] */

#define GPT_70_NUM_OF_GPTWAKEUPCONF         ( 1U )
/* NOTE: not count on channels for preddef timer */
#define GPT_70_NUM_OF_GPTCHANNELCONF        ( 5U )

#define GPT_70_PREDEF_TIMER_ENABLE          ( TRUE )      /*   */

/* --- Define Container(Multiplicity 0..1) enable/disable ------------------- */

#define GPT_70_WAKEUP_CONFIGURATION_ENABLE  ( TRUE )      /* GPT_NOTIFICATION Container  */

#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
/* --- Define Predef Timer API functions to enable -------------------------- */
/* [ECUC_Gpt_00335] */
/* Enables/disables the GPT Predef Timer 100us32bit. */
#define GPT_PREDEF_TIMER_100US_32BIT_ENABLE ( FALSE )

/* [ECUC_Gpt_00334] */
/* Specifies the grade of enabling the GPT Predef Timers with 1us tick duration. */
#define GPT_PREDEF_TIMER_1US_16BIT_ENABLED          ( 0U )    /* 16bit timer enabled */
#define GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED       ( 1U )    /* 16 and 24bit timers enabled */
#define GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED    ( 2U )    /* 16, 24 and 32bit timers enabled */
#define GPT_PREDEF_TIMER_1US_DISABLED               ( 3U )    /* disabled */

#define GPT_PREDEF_TIMER_1US_ENABLING_GRADE    ( GPT_PREDEF_TIMER_1US_16BIT_ENABLED )

/* [QINeS_SWS_GPT_00006] */
/* Select a timer channel and ELC using for 1us cycle generate */
#define GPT_70_PREDEF_1US_ELC_ENABLE     ( TRUE )

#if ( ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) || \
      ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED ) || \
      ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED ) )
/* using ELC for 1us cycle generate or link lower/higher timer */
#define GPT_70_PREDEF_1US_USE_ELC        ( TRUE )
#else /* #if ( ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) || \
               ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED ) || \
               ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED ) ) */
/* no using ELC for 1us cycle generate or link lower/higher timer */
#define GPT_70_PREDEF_1US_USE_ELC        ( FALSE )
#endif /* #if ( ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) || \
                ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED ) || \
                ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED ) ) */

#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */

/* H/W dependent definition for RL78/F24,F25 */

/* --- Define Channel using/not using --------------------------------------- */
#define GPT_70_TAU_0_CH0_USE            ( TRUE )      /* TAU Unit0 CH0 : GPT_70_CH_PREDEF_LOWER */
#define GPT_70_TAU_0_CH1_USE            ( TRUE )      /* TAU Unit0 CH1 : GPT_70_CH_SAMPLE_TAU */
#define GPT_70_TAU_0_CH2_USE            ( FALSE )     /* TAU Unit0 CH2 */
#define GPT_70_TAU_0_CH3_USE            ( FALSE )     /* TAU Unit0 CH3 */
#define GPT_70_TAU_0_CH4_USE            ( FALSE )     /* TAU Unit0 CH4 */
#define GPT_70_TAU_0_CH5_USE            ( FALSE )     /* TAU Unit0 CH5 */
#define GPT_70_TAU_0_CH6_USE            ( TRUE )      /* TAU Unit0 CH6 : GPT_70_CH_WDGDRV_TIMER */
#define GPT_70_TAU_0_CH7_USE            ( FALSE )     /* TAU Unit0 CH7 */
#define GPT_70_TAU_1_CH0_USE            ( FALSE )     /* TAU Unit1 CH0 */
#define GPT_70_TAU_1_CH1_USE            ( FALSE )     /* TAU Unit1 CH1 */
#define GPT_70_TAU_1_CH2_USE            ( FALSE )     /* TAU Unit1 CH2 */
#define GPT_70_TAU_1_CH3_USE            ( FALSE )     /* TAU Unit1 CH3 */
#define GPT_70_TAU_1_CH4_USE            ( TRUE )      /* TAU Unit1 CH4 : GPT_70_CH_MAIN1MS_TIMER */
#define GPT_70_TAU_1_CH5_USE            ( FALSE )     /* TAU Unit1 CH5 */
#define GPT_70_TAU_1_CH6_USE            ( FALSE )     /* TAU Unit1 CH6 */
#define GPT_70_TAU_1_CH7_USE            ( FALSE )     /* TAU Unit1 CH7 */
#define GPT_70_TRJ_0_CH0_USE            ( TRUE )      /* TRJ Unit0 CH0 : GPT_70_CH_WAKEUP */
#define GPT_70_TRD_0_CH0_USE            ( TRUE )      /* TRD Unit0 CH0 : GPT_70_CH_PREDEF_1US */
#define GPT_70_TRD_0_CH1_USE            ( TRUE )      /* TRD Unit0 CH1 : GPT_70_CH_SAMPLE_TRD */

#if ( ( GPT_70_TAU_0_CH0_USE != FALSE ) \
   || ( GPT_70_TAU_0_CH1_USE != FALSE ) \
   || ( GPT_70_TAU_0_CH2_USE != FALSE ) \
   || ( GPT_70_TAU_0_CH3_USE != FALSE ) \
   || ( GPT_70_TAU_0_CH4_USE != FALSE ) \
   || ( GPT_70_TAU_0_CH5_USE != FALSE ) \
   || ( GPT_70_TAU_0_CH6_USE != FALSE ) \
   || ( GPT_70_TAU_0_CH7_USE != FALSE ) \
   || ( GPT_70_TAU_1_CH0_USE != FALSE ) \
   || ( GPT_70_TAU_1_CH1_USE != FALSE ) \
   || ( GPT_70_TAU_1_CH2_USE != FALSE ) \
   || ( GPT_70_TAU_1_CH3_USE != FALSE ) \
   || ( GPT_70_TAU_1_CH4_USE != FALSE ) \
   || ( GPT_70_TAU_1_CH5_USE != FALSE ) \
   || ( GPT_70_TAU_1_CH6_USE != FALSE ) \
   || ( GPT_70_TAU_1_CH7_USE != FALSE ) \
   || ( GPT_70_TRJ_0_CH0_USE != FALSE ) \
   || ( GPT_70_TRD_0_CH0_USE != FALSE ) \
   || ( GPT_70_TRD_0_CH1_USE != FALSE ) )
#define GPT_70_IRQ_USE                  ( TRUE )
#else /* #if ( ( GPT_70_TAU_0_CH0_USE != FALSE ) || ... || ( GPT_70_TRD_0_CH1_USE != FALSE ) ) */
#define GPT_70_IRQ_USE                  ( FALSE )
#endif /* #if ( ( GPT_70_TAU_0_CH0_USE != FALSE ) || ... || ( GPT_70_TRD_0_CH1_USE != FALSE ) ) */

/* --- Define Channel Index -------------------------------------------------- */
#define GPT_70_CH_MAIN1MS_TIMER         ( 0U )        /* TAU Unit1 CH4 */
#define GPT_70_CH_WAKEUP                ( 1U )        /* TRJ Unit0 CH0 */
#define GPT_70_CH_WDGDRV_TIMER          ( 2U )        /* TAU Unit0 CH6 */
#define GPT_70_CH_SAMPLE_TAU            ( 3U )        /* TAU Unit0 CH1 */
#define GPT_70_CH_SAMPLE_TRD            ( 4U )        /* TRD Unit0 CH1 */
#define GPT_70_CH_PREDEF_1US            ( 5U )        /* TRD Unit0 CH0 */
#define GPT_70_CH_PREDEF_LOWER          ( 6U )        /* TAU Unit0 CH0 */

#define GPT_70_CH_UNINITIALIZED         ( 0xFFU )     /* wrong index */

/* --- Define Channel Index for ISR ------------------------------------------ */
#if ( GPT_70_TAU_0_CH0_USE != FALSE )
#define GPT_70_IDX_TAU_0_CH0            ( GPT_70_CH_PREDEF_LOWER )
#endif /* #if ( GPT_70_TAU_0_CH0_USE != FALSE ) */

#if ( GPT_70_TAU_0_CH1_USE != FALSE )
#define GPT_70_IDX_TAU_0_CH1            ( GPT_70_CH_SAMPLE_TAU )
#endif /* #if ( GPT_70_TAU_0_CH1_USE != FALSE ) */

#if ( GPT_70_TAU_0_CH6_USE != FALSE )
#define GPT_70_IDX_TAU_0_CH6            ( GPT_70_CH_WDGDRV_TIMER )
#endif /* #if ( GPT_70_TAU_0_CH6_USE != FALSE ) */

#if ( GPT_70_TAU_1_CH4_USE != FALSE )
#define GPT_70_IDX_TAU_1_CH4            ( GPT_70_CH_MAIN1MS_TIMER )
#endif /* #if ( GPT_70_TAU_1_CH4_USE != FALSE ) */

#if ( GPT_70_TRJ_0_CH0_USE != FALSE )
#define GPT_70_IDX_TRJ_0_CH0            ( GPT_70_CH_WAKEUP )
#endif /* #if ( GPT_70_TRJ_0_CH0_USE != FALSE ) */

#if ( GPT_70_TRD_0_CH0_USE != FALSE )
#define GPT_70_IDX_TRD_0_CH0            ( GPT_70_CH_PREDEF_1US )
#endif /* #if ( GPT_70_TRD_0_CH0_USE != FALSE ) */

#if ( GPT_70_TRD_0_CH1_USE != FALSE )
#define GPT_70_IDX_TRD_0_CH1            ( GPT_70_CH_SAMPLE_TRD )
#endif /* #if ( GPT_70_TRD_0_CH1_USE != FALSE ) */

#endif      /* #ifndef GPT_CFG_H_ */

/* EOF Gpt_Cfg.h **************************************************************/