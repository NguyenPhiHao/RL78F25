/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt_70_Irq.h                                                 */
/* Version     : v1.00.00                                                     */
/* Contents    : GPT Driver IRQ header                                        */
/*               The GPT is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* Specification of GPT Driver  :                                             */
/* Release     : R22-11                                                       */
/*----------------------------------------------------------------------------*/

#ifndef GPT_70_IRQ_H_
#define GPT_70_IRQ_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_IRQ_H                 ( 70U )
#define GPT_70_MODULE_ID_IRQ_H                 ( 100U )

#define GPT_70_AR_RELEASE_MAJOR_VERSION_IRQ_H  ( 22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_IRQ_H  ( 11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_IRQ_H ( 0U )

#define GPT_70_SW_MAJOR_VERSION_IRQ_H          ( 1U )
#define GPT_70_SW_MINOR_VERSION_IRQ_H          ( 0U )
#define GPT_70_SW_PATCH_VERSION_IRQ_H          ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_0_CH0_USE != FALSE )
extern void Gpt_70_Isr_TAU_0_CH0( void );  /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_0_CH0_USE != FALSE ) */

#if ( GPT_70_TAU_0_CH1_USE != FALSE )
extern void Gpt_70_Isr_TAU_0_CH1( void );  /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_0_CH1_USE != FALSE ) */

#if ( GPT_70_TAU_0_CH2_USE != FALSE )
extern void Gpt_70_Isr_TAU_0_CH2(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_0_CH2_USE != FALSE ) */

#if ( GPT_70_TAU_0_CH3_USE != FALSE )
extern void Gpt_70_Isr_TAU_0_CH3(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_0_CH3_USE != FALSE ) */

#if ( GPT_70_TAU_0_CH4_USE != FALSE )
extern void Gpt_70_Isr_TAU_0_CH4(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_0_CH4_USE != FALSE ) */

#if ( GPT_70_TAU_0_CH5_USE != FALSE )
extern void Gpt_70_Isr_TAU_0_CH5(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_0_CH5_USE != FALSE ) */

#if ( GPT_70_TAU_0_CH6_USE != FALSE )
extern void Gpt_70_Isr_TAU_0_CH6(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_0_CH6_USE != FALSE ) */

#if ( GPT_70_TAU_0_CH7_USE != FALSE )
extern void Gpt_70_Isr_TAU_0_CH7(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_0_CH7_USE != FALSE ) */

/*----------------------------------------------------------------------------*/

/* TAU1 channel interrupts */

#if ( GPT_70_TAU_1_CH0_USE != FALSE )
extern void Gpt_70_Isr_TAU_1_CH0(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_1_CH0_USE != FALSE ) */

#if ( GPT_70_TAU_1_CH1_USE != FALSE )
extern void Gpt_70_Isr_TAU_1_CH1(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_1_CH1_USE != FALSE ) */

#if ( GPT_70_TAU_1_CH2_USE != FALSE )
extern void Gpt_70_Isr_TAU_1_CH2(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_1_CH2_USE != FALSE ) */

#if ( GPT_70_TAU_1_CH3_USE != FALSE )
extern void Gpt_70_Isr_TAU_1_CH3(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_1_CH3_USE != FALSE ) */

#if ( GPT_70_TAU_1_CH4_USE != FALSE )
extern void Gpt_70_Isr_TAU_1_CH4(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_1_CH4_USE != FALSE ) */

#if ( GPT_70_TAU_1_CH5_USE != FALSE )
extern void Gpt_70_Isr_TAU_1_CH5(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_1_CH5_USE != FALSE ) */

#if ( GPT_70_TAU_1_CH6_USE != FALSE )
extern void Gpt_70_Isr_TAU_1_CH6(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_1_CH6_USE != FALSE ) */

#if ( GPT_70_TAU_1_CH7_USE != FALSE )
extern void Gpt_70_Isr_TAU_1_CH7(void);   /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TAU_1_CH7_USE != FALSE ) */

#if ( GPT_70_TRJ_0_CH0_USE != FALSE )
extern void Gpt_70_Isr_TRJ_0_CH0(void);    /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TRJ_0_CH0_USE != FALSE ) */

#if ( GPT_70_TRD_0_CH0_USE != FALSE )
extern void Gpt_70_Isr_TRD_0_CH0(void);    /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TRD_0_CH0_USE != FALSE ) */

#if ( GPT_70_TRD_0_CH1_USE != FALSE )
extern void Gpt_70_Isr_TRD_0_CH1(void);    /* [SWS_Gpt_00206] */
#endif /* #if ( GPT_70_TRD_0_CH1_USE != FALSE ) */

#endif /* #ifndef GPT_70_IRQ_H_ */

/* EOF Gpt_70_Irq.h ************************************************************/
