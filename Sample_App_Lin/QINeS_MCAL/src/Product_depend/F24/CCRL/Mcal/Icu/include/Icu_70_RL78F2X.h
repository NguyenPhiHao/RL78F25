/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu_70_RL78F2X.h                                             */
/* Version     : v1.00.01                                                     */
/* Contents    : ICU Module HW dependent header                               */
/*               The ICU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ICU Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef ICU_70_RL78F2X_H_
#define ICU_70_RL78F2X_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Icu_70_Types.h"
#include "Icu_70_RL78F2X_types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ICU_70_VENDOR_ID_RL78F2X_H                      (70U)
#define ICU_70_MODULE_ID_RL78F2X_H                      (122U)

#define ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H       (22U)
#define ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H       (11U)
#define ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H    (0U)

#define ICU_70_SW_MAJOR_VERSION_RL78F2X_H               (1U)
#define ICU_70_SW_MINOR_VERSION_RL78F2X_H               (0U)
#define ICU_70_SW_PATCH_VERSION_RL78F2X_H               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != STD_TYPES_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_RL78F2X.h and Std_Types.h are different"
#endif

/* Std_Types.h version check end */

/* Icu_70_Types.h version check start */

#if ( ICU_70_VENDOR_ID_RL78F2X_H != ICU_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Icu_70_RL78F2X.h and Icu_70_Types.h are different"
#endif

#if ( ICU_70_MODULE_ID_RL78F2X_H != ICU_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Icu_70_RL78F2X.h and Icu_70_Types.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    != ICU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    != ICU_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != ICU_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_RL78F2X.h and Icu_70_Types.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_RL78F2X_H != ICU_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( ICU_70_SW_MINOR_VERSION_RL78F2X_H != ICU_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( ICU_70_SW_PATCH_VERSION_RL78F2X_H != ICU_70_SW_PATCH_VERSION_TYPES_H ) \
    )
    #error "Software Version Numbers of Icu_70_RL78F2X.h and Icu_70_Types.h are different"
#endif

/* Icu_70_Types.h version check end */

/* Icu_70_RL78F2X_types.h version check start */

#if ( ICU_70_VENDOR_ID_RL78F2X_H != ICU_70_VENDOR_ID_RL78F2X_TYPES_H )
    #error "VENDOR ID for Icu_70_RL78F2X.h and Icu_70_RL78F2X_types.h are different"
#endif

#if ( ICU_70_MODULE_ID_RL78F2X_H != ICU_70_MODULE_ID_RL78F2X_TYPES_H )
    #error "MODULE ID for Icu_70_RL78F2X.h and Icu_70_RL78F2X_types.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    != ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    != ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_RL78F2X.h and Icu_70_RL78F2X_types.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_RL78F2X_H != ICU_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( ICU_70_SW_MINOR_VERSION_RL78F2X_H != ICU_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( ICU_70_SW_PATCH_VERSION_RL78F2X_H != ICU_70_SW_PATCH_VERSION_RL78F2X_TYPES_H ) \
    )
    #error "Software Version Numbers of Icu_70_RL78F2X.h and Icu_70_RL78F2X_types.h are different"
#endif

/* Icu_70_RL78F2X_types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/


#define ICU_70_RL78F2X_ACT_RISING                   ( 0x01U )
#define ICU_70_RL78F2X_ACT_FALLING                  ( 0x02U )

#define ICU_70_RL78F2X_COUNTER_OVER_DATA            ( 0x00010000UL )
/* For Work */
#define ICU_70_TRDIORC                    ( uint8 )( 0x0CU ) /* Use TRDGRC,D as Buffer of TRDGRA,B */
#define ICU_70_TRDSR_OVF_BIT              ( uint8 )( 0x10U ) /* OVF bit position in TRDSR */
#define ICU_70_TRDCR_CCLR_MASK            ( uint8 )( 0x20U ) /* Select Counter clear */
#define ICU_70_TRDCR_TCK_FTRD_MASK        ( uint8 )( 0x00U ) /* TRDCR select fTRD    */
#define ICU_70_TRDCR_TCK_FTRD2_MASK       ( uint8 )( 0x01U ) /* TRDCR select fTRD/2  */
#define ICU_70_TRDCR_TCK_FTRD4_MASK       ( uint8 )( 0x02U ) /* TRDCR select fTRD/4  */
#define ICU_70_TRDCR_TCK_FTRD8_MASK       ( uint8 )( 0x03U ) /* TRDCR select fTRD/8  */
#define ICU_70_TRDCR_TCK_FTRD32_MASK      ( uint8 )( 0x04U ) /* TRDCR select fTRD/32 */
#define ICU_70_TRDCR_TCK_TRDCLK_MASK      ( uint8 )( 0x05U ) /* TRDCR select TRDCLK  */
#define ICU_70_TRDIER_IMIE                ( uint8 )( 0x01U ) /* For TRDIER set */
#define ICU_70_TRDMR_TRDBF                ( uint8 )( 0x10U ) /* For TRDMR set  */
#define ICU_70_TRD_TRDGRX_INIT            ( uint16 )( 0xFFFFU ) /* For init TRDGRmn register */
#define ICU_70_TRDSTR_CSEL_MASK           ( MCL_70_RL78F2X_TRD_TRDSTR_CSEL_MASK )    /* Select count operation */
#define ICU_70_TRDMR_TRDSYNC_MASK         ( uint8 )( ~MCL_70_RL78F2X_TRD_TRDMR_TRDSYNC_MASK ) /* Not SYNC  */
#define ICU_70_TRD_START                  ( MCL_70_RL78F2X_TRD_TRDSTR_TSTART_MASK )
#define ICU_70_TRD_TRD_INIT               ( uint16 )( 0x0000U )
#define ICU_70_TRDIOR_SHIFT               ( uint8 )( 2U )
#define ICU_70_TRDMR_SHIFT                ( uint8 )( 1U )
#define ICU_70_TRDSR_INIT                 ( uint8 )( 0x01U )
#define ICU_70_RL78F2X_INT_INTMSK_ADR     ( *( MCL_70_RL78F2X_INT_INTMSK_ADR ) )
#define ICU_70_SET_U1BIT                  ( uint8 )( 0x01U )
#define ICU_70_SET_U2BIT                  ( uint16 )(0x0001U )
#define ICU_70_RL78F2X_INTMSK_INIT        ( uint8 )( 0xffU )
#define ICU_70_TMR_CIS_SHIFT              ( uint8 )( 6U )
#define ICU_70_TRDIORA_INIT               ( uint8 )( 0x03U )
#define ICU_70_TMR_CCS0_STS1_MD4          ( uint16 )( MCL_70_RL78F2X_TAU_TMR_CCS0    /* count clock is operation clock  */ \
                                                  | MCL_70_RL78F2X_TAU_TMR_STS1      /* Valid edge is used as both the start and capture trigger. */ \
                                                  | MCL_70_RL78F2X_TAU_TMR_MD1_3_1 ) /* Capture mode */
#define ICU_70_TRDDF_DFCK3                ( uint8 )( 0xC0U )  /* Clock for digital filter function is count source */
#define ICU_70_MEAS_NONE                  ( uint8 )( 0U )
#define ICU_70_MEAS_ACTIVE                ( uint8 )( 1U )
#define ICU_70_MEAS_PERIOD                ( uint8 )( 2U )

#define ICU_70_RL78F2X_MK0H_ADR           ( IO8( 0xFFE5U ) )
#define ICU_70_RL78F2X_MK1L_ADR           ( IO8( 0xFFE6U ) )
#define ICU_70_RL78F2X_MK1H_ADR           ( IO8( 0xFFE7U ) )
#define ICU_70_RL78F2X_MK2L_ADR           ( IO8( 0xFFD4U ) )
#define ICU_70_RL78F2X_MK2H_ADR           ( IO8( 0xFFD5U ) )
#define ICU_70_RL78F2X_MK3L_ADR           ( IO8( 0xFFD6U ) )

/* Set Compile switch for using timer function */
#if ( ( ICU_TIMESTAMP_API == TRUE ) || ( ICU_SIGNAL_MEASUREMENT_API == TRUE ) )
#define ICU_70_TIMER_API_ENABLE        ( TRUE )
#else
#define ICU_70_TIMER_API_ENABLE        ( FALSE )
#endif

/* Set Compile switch for using Edge detect function */
#if ( ( ICU_EDGE_COUNT_API == TRUE ) || ( ICU_EDGE_DETECT_API == TRUE ) )
#define ICU_70_EDGE_API_ENABLE         ( TRUE )
#else
#define ICU_70_EDGE_API_ENABLE         ( FALSE )
#endif

/* Set Compile switch for using timer and Edge detect function ( for TAU ) */
#if ( ( ICU_70_EDGE_API_ENABLE == TRUE ) || ( ICU_70_TIMER_API_ENABLE == TRUE ) )
#define ICU_70_USING_TAU_API_ENABLE      ( TRUE )
#else
#define ICU_70_USING_TAU_API_ENABLE      ( FALSE )
#endif


/*----------------------------------------------------------------------------*/
/*  Type definitions                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#if ( ICU_70_ENABLE_TAU_ANY != FALSE )
extern void Icu_70_RL78F2X_TAU_Init( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo,
                                     uint8 actEdge );

#if ( ICU_DE_INIT_API  == TRUE )
extern void Icu_70_RL78F2X_TAU_DeInit( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo );
#endif    /* #if ( ICU_DE_INIT_API  == TRUE ) */

#if ( ICU_70_USING_TAU_API_ENABLE != FALSE )
extern void Icu_70_RL78F2X_TAU_StartTimer( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo,
                                           uint8 actEdge );
extern void Icu_70_RL78F2X_TAU_StopTimer( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo );
#endif    /* #if ( ICU_70_USING_TAU_API_ENABLE != FALSE ) */

extern void Icu_70_RL78F2X_TAU_SetActivationCondition
                                ( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo, uint8 actEdge );

#if ( ICU_SET_MODE_API != FALSE )
extern void Icu_70_RL78F2X_TAU_EnableInt( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo,
                                          uint8 actEdge );
extern void Icu_70_RL78F2X_TAU_DisableInt( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo );
#endif    /* #if ( ICU_SET_MODE_API != FALSE ) */
#endif    /* #if ( ICU_70_ENABLE_TAU_ANY != FALSE ) */

#if ( ICU_70_ENABLE_TRD_ANY != FALSE )
extern void Icu_70_RL78F2X_TRD_Init( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo,
                                     uint8 actEdge );
#if ( ICU_DE_INIT_API  == TRUE )
extern void Icu_70_RL78F2X_TRD_DeInit( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo );
#endif

#if ( ICU_70_TIMER_API_ENABLE != FALSE )
extern void Icu_70_RL78F2X_TRD_StartTimer( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo,
                                           uint8 actEdge );
extern void Icu_70_RL78F2X_TRD_StopTimer( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo );
#endif    /* #if ( ICU_70_TIMER_API_ENABLE != FALSE ) */

extern void Icu_70_RL78F2X_TRD_ClrInt( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo );

#if ( ICU_70_EDGE_API_ENABLE != FALSE )
extern void Icu_70_RL78F2X_TRD_EnableEdge( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo,
                                           uint8 actEdge );
extern void Icu_70_RL78F2X_TRD_DisableEdge( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo );
#endif    /* #if ( ICU_70_EDGE_API_ENABLE != FALSE ) */

extern void Icu_70_RL78F2X_TRD_SetActivationCondition
                                ( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo, uint8 actEdge );

#if ( ICU_SET_MODE_API != FALSE )
extern void Icu_70_RL78F2X_TRD_EnableInt( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo,
                                          uint8 actEdge );
extern void Icu_70_RL78F2X_TRD_DisableInt( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo );
#endif    /* #if ( ICU_SET_MODE_API != FALSE ) */
#endif    /* #if ( ICU_70_ENABLE_TRD_ANY != FALSE ) */

#if ( ICU_70_ENABLE_INTP_ANY != FALSE )
extern void Icu_70_RL78F2X_INTP_Init( const Icu_70_RL78F2X_INTP_SettingConfType* chInfo,
                                      uint8 actEdge );
#if ( ICU_DE_INIT_API == TRUE )
extern void Icu_70_RL78F2X_INTP_DeInit( const Icu_70_RL78F2X_INTP_SettingConfType* chInfo );
#endif    /* #if ( ICU_DE_INIT_API == TRUE ) */

#if ( ICU_70_EDGE_API_ENABLE != FALSE )
extern void Icu_70_RL78F2X_INTP_EnableEdge( const Icu_70_RL78F2X_INTP_SettingConfType* chInfo,
                                            uint8 actEdge );
extern void Icu_70_RL78F2X_INTP_DisableEdge( const Icu_70_RL78F2X_INTP_SettingConfType* chInfo );
#endif    /* #if ( ICU_70_EDGE_API_ENABLE != FALSE ) */

#endif    /* #if ( ICU_70_ENABLE_INTP_ANY != FALSE ) */

#endif        /* #ifndef ICU_70_RL78F2X_H_ */

/* EOF Icu_70_RL78F2X.h *******************************************************/