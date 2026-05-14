/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu_Irq.h                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : Icu Driver Layer IRQ Header                                  */
/*               The ICU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ICU Driver                                                */
/*----------------------------------------------------------------------------*/
/* R22-11                                                                     */
 
#ifndef ICU_IRQ_H_
#define ICU_IRQ_H_
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#define ICU_70_VENDOR_ID_IRQ_H                      (70U)
#define ICU_70_MODULE_ID_IRQ_H                      (122U)
 
#define ICU_70_AR_RELEASE_MAJOR_VERSION_IRQ_H       (22U)
#define ICU_70_AR_RELEASE_MINOR_VERSION_IRQ_H       (11U)
#define ICU_70_AR_RELEASE_REVISION_VERSION_IRQ_H    (0U)
 
#define ICU_70_SW_MAJOR_VERSION_IRQ_H               (1U)
#define ICU_70_SW_MINOR_VERSION_IRQ_H               (0U)
#define ICU_70_SW_PATCH_VERSION_IRQ_H               (0U)
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define ICU_70_EDGECOUNTER_MAXVALUE       ( uint16 )( 0xFFFFU )
#define ICU_70_TRDSR_PORT_A_OVERFLOW      ( 0x11U )
#define ICU_70_TRDSR_PORT_A               ( 0x01U )
#define ICU_70_TRDSR_PORT_B_OVERFLOW      ( 0x12U )
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#ifndef ICU_IRQ_C_
 
#if (ICU_70_ENABLE_TAU00  == TRUE )
extern void Icu_70_Isr_TAU00( void );
#endif      /* #if (ICU_70_ENABLE_TAU00  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU01  == TRUE )
extern void Icu_70_Isr_TAU01( void );
#endif      /* #if (ICU_70_ENABLE_TAU01  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU02  == TRUE )
extern void Icu_70_Isr_TAU02( void );
#endif      /* #if (ICU_70_ENABLE_TAU02  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU03  == TRUE )
extern void Icu_70_Isr_TAU03( void );
#endif      /* #if (ICU_70_ENABLE_TAU03  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU04  == TRUE )
extern void Icu_70_Isr_TAU04( void );
#endif      /* #if (ICU_70_ENABLE_TAU04  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU05  == TRUE )
extern void Icu_70_Isr_TAU05( void );
#endif      /* #if (ICU_70_ENABLE_TAU05  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU06  == TRUE )
extern void Icu_70_Isr_TAU06( void );
#endif      /* #if (ICU_70_ENABLE_TAU06  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU07  == TRUE )
extern void Icu_70_Isr_TAU07( void );
#endif      /* #if (ICU_70_ENABLE_TAU06  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU10  == TRUE )
extern void Icu_70_Isr_TAU10( void );
#endif      /* #if (ICU_70_ENABLE_TAU10  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU11  == TRUE )
extern void Icu_70_Isr_TAU11( void );
#endif      /* #if (ICU_70_ENABLE_TAU11  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU12  == TRUE )
extern void Icu_70_Isr_TAU12( void );
#endif      /* #if (ICU_70_ENABLE_TAU12  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU13  == TRUE )
extern void Icu_70_Isr_TAU13( void );
#endif      /* #if (ICU_70_ENABLE_TAU13  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU14  == TRUE )
extern void Icu_70_Isr_TAU14( void );
#endif      /* #if (ICU_70_ENABLE_TAU14  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU15  == TRUE )
extern void Icu_70_Isr_TAU15( void );
#endif      /* #if (ICU_70_ENABLE_TAU15  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU16  == TRUE )
extern void Icu_70_Isr_TAU16( void );
#endif      /* #if (ICU_70_ENABLE_TAU16  == TRUE ) */
 
#if (ICU_70_ENABLE_TAU17  == TRUE )
extern void Icu_70_Isr_TAU17( void );
#endif      /* #if (ICU_70_ENABLE_TAU17  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP0  == TRUE )
extern void Icu_70_Isr_INTP0( void );
#endif      /* #if (ICU_70_ENABLE_INTP0  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP1  == TRUE )
extern void Icu_70_Isr_INTP1( void );
#endif      /* #if (ICU_70_ENABLE_INTP1  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP2  == TRUE )
extern void Icu_70_Isr_INTP2( void );
#endif      /* #if (ICU_70_ENABLE_INTP2  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP3  == TRUE )
extern void Icu_70_Isr_INTP3( void );
#endif      /* #if (ICU_70_ENABLE_INTP3  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP4  == TRUE )
extern void Icu_70_Isr_INTP4( void );
#endif      /* #if (ICU_70_ENABLE_INTP4  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP5  == TRUE )
extern void Icu_70_Isr_INTP5( void );
#endif      /* #if (ICU_70_ENABLE_INTP5  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP6  == TRUE )
extern void Icu_70_Isr_INTP6( void );
#endif      /* #if (ICU_70_ENABLE_INTP6  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP7  == TRUE )
extern void Icu_70_Isr_INTP7( void );
#endif      /* #if (ICU_70_ENABLE_INTP7  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP8  == TRUE )
extern void Icu_70_Isr_INTP8( void );
#endif      /* #if (ICU_70_ENABLE_INTP8  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP9  == TRUE )
extern void Icu_70_Isr_INTP9( void );
#endif      /* #if (ICU_70_ENABLE_INTP9  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP10  == TRUE )
extern void Icu_70_Isr_INTP10( void );
#endif      /* #if (ICU_70_ENABLE_INTP10  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP11  == TRUE )
extern void Icu_70_Isr_INTP11( void );
#endif      /* #if (ICU_70_ENABLE_INTP11  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP12  == TRUE )
extern void Icu_70_Isr_INTP12( void );
#endif      /* #if (ICU_70_ENABLE_INTP12  == TRUE ) */
 
#if (ICU_70_ENABLE_INTP13  == TRUE )
extern void Icu_70_Isr_INTP13( void );
#endif      /* #if (ICU_70_ENABLE_INTP13  == TRUE ) */
 
#if (ICU_70_ENABLE_TRD0  == TRUE )
void Icu_70_Isr_TRD0( void );
#endif      /* #if (ICU_70_ENABLE_TRD0  == TRUE ) */
 
#if (ICU_70_ENABLE_TRD1  == TRUE )
void Icu_70_Isr_TRD1( void );
#endif      /* #if (ICU_70_ENABLE_TRD1  == TRUE ) */
 
#if ( ICU_70_ENABLE_TAU_ANY != FALSE )
static void icu_70_Irq_TAU( uint8 IcuCh );
static void icu_70_HW_Irq_TAU_Normal( Icu_70_ChannelInfoType* chInfoPtr );
#if ( ICU_TIMESTAMP_API != FALSE )
LOCAL_INLINE void icu_70_HW_Irq_TAU_TimeStamp( Icu_70_ChannelInfoType* chInfoPtr );
#endif /* #if ( ICU_TIMESTAMP_API != FALSE ) */
#if ( ICU_SIGNAL_MEASUREMENT_API != FALSE )
LOCAL_INLINE void icu_70_HW_Irq_TAU_HighLow( Icu_70_ChannelInfoType* chInfoPtr );
LOCAL_INLINE void icu_70_HW_Irq_TAU_Period( Icu_70_ChannelInfoType* chInfoPtr );
LOCAL_INLINE void icu_70_HW_Irq_TAU_DutyCycle( Icu_70_ChannelInfoType* chInfoPtr );
#endif /* #if ( ICU_SIGNAL_MEASUREMENT_API != FALSE ) */
#if ( ICU_70_TIMER_API_ENABLE != FALSE )
LOCAL_INLINE Icu_ValueType icu_70_RL78F2X_TAU_getTimerCount
                           ( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo );
#endif  /* #if ( ICU_70_TIMER_API_ENABLE != FALSE ) */
#endif      /* #if ( ICU_70_ENABLE_TAU_ANY != FALSE ) */
 
#if ( ICU_70_ENABLE_INTP_ANY != FALSE )
static void icu_70_Irq_INTP( uint8 IcuCh );
#endif      /* #if ( ICU_70_ENABLE_INTP_ANY != FALSE ) */
 
#if ( ICU_70_ENABLE_TRD_ANY != FALSE )
static void icu_70_Irq_TRD( uint8 IcuCh );
static void icu_70_HW_Irq_TRD_Normal( Icu_70_ChannelInfoType* chInfoPtr );
#if ( ICU_TIMESTAMP_API != FALSE )
LOCAL_INLINE void icu_70_HW_Irq_TRD_TimeStamp( Icu_70_ChannelInfoType* chInfoPtr );
#endif /* #if ( ICU_TIMESTAMP_API != FALSE ) */
#if ( ICU_SIGNAL_MEASUREMENT_API != FALSE )
LOCAL_INLINE void icu_70_HW_Irq_TRD_HighLow( Icu_70_ChannelInfoType* chInfoPtr );
LOCAL_INLINE void icu_70_HW_Irq_TRD_Period( Icu_70_ChannelInfoType* chInfoPtr );
LOCAL_INLINE void icu_70_HW_Irq_TRD_DutyCycle( Icu_70_ChannelInfoType* chInfoPtr );
#endif /* #if ( ICU_SIGNAL_MEASUREMENT_API != FALSE ) */
#if ( ICU_70_TIMER_API_ENABLE != FALSE )
LOCAL_INLINE Icu_ValueType icu_70_RL78F2X_TRD_getTimerCount
                           ( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo );
#endif  /* #if ( ICU_70_TIMER_API_ENABLE != FALSE ) */
#endif      /* #if ( ICU_70_ENABLE_TRD_ANY != FALSE ) */
 
#endif      /* #ifndef ICU_IRQ_C_ */
 
#endif      /* #ifndef ICU_IRQ_H_ */
 
/* EOF Icu_Irq.h **************************************************************/