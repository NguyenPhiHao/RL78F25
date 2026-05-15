/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt_Irq.c                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : GPT Driver IRQ implementation                                */
/*               The GPT is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of GPT Driver                                                */
/* R22-11                                                                     */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Gpt.h"                /* [SWS_Gpt_00261] */
#include "Gpt_70_Irq.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_IRQ_C                      ( 70U )
#define GPT_70_MODULE_ID_IRQ_C                      ( 100U )
 
#define GPT_70_AR_RELEASE_MAJOR_VERSION_IRQ_C       ( 22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_IRQ_C       ( 11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_IRQ_C    ( 0U )
 
#define GPT_70_SW_MAJOR_VERSION_IRQ_C               ( 1U )
#define GPT_70_SW_MINOR_VERSION_IRQ_C               ( 0U )
#define GPT_70_SW_PATCH_VERSION_IRQ_C               ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Gpt.h version check start */
 
#if ( GPT_70_VENDOR_ID_IRQ_C != GPT_VENDOR_ID )
    #error "VENDOR ID for Gpt_Irq.c and Gpt.h are different"
#endif
 
#if ( GPT_70_MODULE_ID_IRQ_C != GPT_MODULE_ID )
    #error "MODULE ID for Gpt_Irq.c and Gpt.h are different"
#endif
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_IRQ_C    != GPT_AR_RELEASE_MAJOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_IRQ_C    != GPT_AR_RELEASE_MINOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_IRQ_C != GPT_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_Irq.c and Gpt.h are different"
#endif
 
#if ( ( GPT_70_SW_MAJOR_VERSION_IRQ_C != GPT_SW_MAJOR_VERSION ) || \
      ( GPT_70_SW_MINOR_VERSION_IRQ_C != GPT_SW_MINOR_VERSION ) || \
      ( GPT_70_SW_PATCH_VERSION_IRQ_C != GPT_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Gpt_Irq.c and Gpt.h are different"
#endif
 
/* Gpt.h version check end */
 
/* Gpt_70_Irq.h version check start */
 
#if ( GPT_70_VENDOR_ID_IRQ_C != GPT_70_VENDOR_ID_IRQ_H )
    #error "VENDOR ID for Gpt_Irq.c and Gpt_70_Irq.h are different"
#endif
 
#if ( GPT_70_MODULE_ID_IRQ_C != GPT_70_MODULE_ID_IRQ_H )
    #error "MODULE ID for Gpt_Irq.c and Gpt_70_Irq.h are different"
#endif
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_IRQ_C    != GPT_70_AR_RELEASE_MAJOR_VERSION_IRQ_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_IRQ_C    != GPT_70_AR_RELEASE_MINOR_VERSION_IRQ_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_IRQ_C != GPT_70_AR_RELEASE_REVISION_VERSION_IRQ_H ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_Irq.c and Gpt_70_Irq.h are different"
#endif
 
#if ( ( GPT_70_SW_MAJOR_VERSION_IRQ_C != GPT_70_SW_MAJOR_VERSION_IRQ_H ) || \
      ( GPT_70_SW_MINOR_VERSION_IRQ_C != GPT_70_SW_MINOR_VERSION_IRQ_H ) || \
      ( GPT_70_SW_PATCH_VERSION_IRQ_C != GPT_70_SW_PATCH_VERSION_IRQ_H ) \
    )
    #error "Software Version Numbers of Gpt_Irq.c and Gpt_70_Irq.h are different"
#endif
 
/* Gpt_70_Irq.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define GPT_START_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_0_CH0                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 0 Channel 0 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_0_CH0_USE != FALSE )
void Gpt_70_Isr_TAU_0_CH0( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_0_CH0 );
}
#endif /* #if ( GPT_70_TAU_0_CH0_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_0_CH1                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 0 Channel 1 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_0_CH1_USE != FALSE )
void Gpt_70_Isr_TAU_0_CH1( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_0_CH1 );
}
#endif /* #if ( GPT_70_TAU_0_CH1_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_0_CH2                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 0 Channel 2 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_0_CH2_USE != FALSE )
void Gpt_70_Isr_TAU_0_CH2( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_0_CH2 );
}
#endif /* #if ( GPT_70_TAU_0_CH2_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_0_CH3                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 0 Channel 3 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_0_CH3_USE != FALSE )
void Gpt_70_Isr_TAU_0_CH3( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_0_CH3 );
}
#endif /* #if ( GPT_70_TAU_0_CH3_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_0_CH4                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 0 Channel 4 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_0_CH4_USE != FALSE )
void Gpt_70_Isr_TAU_0_CH4( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_0_CH4 );
}
#endif /* #if ( GPT_70_TAU_0_CH4_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_0_CH5                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 0 Channel 5 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_0_CH5_USE != FALSE )
void Gpt_70_Isr_TAU_0_CH5( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_0_CH5 );
}
#endif /* #if ( GPT_70_TAU_0_CH5_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_0_CH6                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 0 Channel 6 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_0_CH6_USE != FALSE )
void Gpt_70_Isr_TAU_0_CH6( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_0_CH6 );
}
#endif /* #if ( GPT_70_TAU_0_CH6_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_0_CH7                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 0 Channel 7 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_0_CH7_USE != FALSE )
void Gpt_70_Isr_TAU_0_CH7( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_0_CH7 );
}
#endif /* #if ( GPT_70_TAU_0_CH7_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_1_CH0                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 1 Channel 0 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_1_CH0_USE != FALSE )
void Gpt_70_Isr_TAU_1_CH0( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_1_CH0 );
}
#endif /* #if ( GPT_70_TAU_1_CH0_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_1_CH1                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 1 Channel 1 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_1_CH1_USE != FALSE )
void Gpt_70_Isr_TAU_1_CH1( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_1_CH1 );
}
#endif /* #if ( GPT_70_TAU_1_CH1_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_1_CH2                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 1 Channel 2 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_1_CH2_USE != FALSE )
void Gpt_70_Isr_TAU_1_CH2( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_1_CH2 );
}
#endif /* #if ( GPT_70_TAU_1_CH2_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_1_CH3                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 1 Channel 3 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_1_CH3_USE != FALSE )
void Gpt_70_Isr_TAU_1_CH3( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_1_CH3 );
}
#endif /* #if ( GPT_70_TAU_1_CH3_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_1_CH4                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 1 Channel 4 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_1_CH4_USE != FALSE )
void Gpt_70_Isr_TAU_1_CH4( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_1_CH4 );
}
#endif /* #if ( GPT_70_TAU_1_CH4_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_1_CH5                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 1 Channel 5 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_1_CH5_USE != FALSE )
void Gpt_70_Isr_TAU_1_CH5( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_1_CH5 );
}
#endif /* #if ( GPT_70_TAU_1_CH5_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_1_CH6                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 1 Channel 6 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_1_CH6_USE != FALSE )
void Gpt_70_Isr_TAU_1_CH6( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_1_CH6 );
}
#endif /* #if ( GPT_70_TAU_1_CH6_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TAU_1_CH7                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TAU Unit 1 Channel 7 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TAU_1_CH7_USE != FALSE )
void Gpt_70_Isr_TAU_1_CH7( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TAU_1_CH7 );
}
#endif /* #if ( GPT_70_TAU_1_CH7_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TRJ_0_CH0                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TRJ Unit 0 Channel 0 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TRJ_0_CH0_USE != FALSE )
void Gpt_70_Isr_TRJ_0_CH0( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TRJ_0_CH0 );
}
#endif /* #if ( GPT_70_TRJ_0_CH0_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TRD_0_CH0                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TRD Unit 0 Channel 0 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TRD_0_CH0_USE != FALSE )
void Gpt_70_Isr_TRD_0_CH0( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TRD_0_CH0 );
}
#endif /* #if ( GPT_70_TRD_0_CH0_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_TRD_0_CH1                                         */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : TRD Unit 0 Channel 1 notification process                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_TRD_0_CH1_USE != FALSE )
void Gpt_70_Isr_TRD_0_CH1( void )
{
    Gpt_70_Isr_CHn( GPT_70_IDX_TRD_0_CH1 );
}
#endif /* #if ( GPT_70_TRD_0_CH1_USE != FALSE ) */
 
#define GPT_STOP_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"
 
/* EOF Gpt_Irq.c **************************************************************/