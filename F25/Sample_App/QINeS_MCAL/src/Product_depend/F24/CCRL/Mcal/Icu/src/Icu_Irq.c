/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu_Irq.c                                                    */
/* Version     : v1.00.01                                                     */
/* Contents    : ICU Driver Layer IRQ implementation                          */
/*               The ICU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ICU Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Icu.h"
#include "Icu_Irq.h"
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ICU_70_VENDOR_ID_IRQ_C                      (70U)
#define ICU_70_MODULE_ID_IRQ_C                      (122U)

#define ICU_70_AR_RELEASE_MAJOR_VERSION_IRQ_C       (22U)
#define ICU_70_AR_RELEASE_MINOR_VERSION_IRQ_C       (11U)
#define ICU_70_AR_RELEASE_REVISION_VERSION_IRQ_C    (0U)

#define ICU_70_SW_MAJOR_VERSION_IRQ_C               (1U)
#define ICU_70_SW_MINOR_VERSION_IRQ_C               (0U)
#define ICU_70_SW_PATCH_VERSION_IRQ_C               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Icu.h version check start */

#if ( ICU_70_VENDOR_ID_IRQ_C != ICU_VENDOR_ID )
    #error "VENDOR ID for Icu_Irq.c and Icu.h are different"
#endif

#if ( ICU_70_MODULE_ID_IRQ_C != ICU_MODULE_ID )
    #error "MODULE ID for Icu_Irq.c and Icu.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_IRQ_C    != ICU_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_IRQ_C    != ICU_AR_RELEASE_MINOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_IRQ_C != ICU_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Icu_Irq.c and Icu.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_IRQ_C != ICU_SW_MAJOR_VERSION ) || \
      ( ICU_70_SW_MINOR_VERSION_IRQ_C != ICU_SW_MINOR_VERSION ) || \
      ( ICU_70_SW_PATCH_VERSION_IRQ_C != ICU_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Icu_Irq.c and Icu.h are different"
#endif

/* Icu.h version check end */

/* Icu_Cfg.h version check start */

#if ( ICU_70_VENDOR_ID_IRQ_C != ICU_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Icu_Irq.c and Icu_Cfg.h are different"
#endif

#if ( ICU_70_MODULE_ID_IRQ_C != ICU_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Icu_Irq.c and Icu_Cfg.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_IRQ_C    != ICU_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_IRQ_C    != ICU_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_IRQ_C != ICU_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_Irq.c and Icu_Cfg.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_IRQ_C != ICU_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( ICU_70_SW_MINOR_VERSION_IRQ_C != ICU_70_SW_MINOR_VERSION_CFG_H ) || \
      ( ICU_70_SW_PATCH_VERSION_IRQ_C != ICU_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Icu_Irq.c and Icu_Cfg.h are different"
#endif

/* Icu_Cfg.h version check end */
/* Icu_Irq.h version check start */

#if ( ICU_70_VENDOR_ID_IRQ_C != ICU_70_VENDOR_ID_IRQ_H )
    #error "VENDOR ID for Icu_Irq.c and Icu_Irq.h are different"
#endif

#if ( ICU_70_MODULE_ID_IRQ_C != ICU_70_MODULE_ID_IRQ_H )
    #error "MODULE ID for Icu_Irq.c and Icu_Irq.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_IRQ_C    != ICU_70_AR_RELEASE_MAJOR_VERSION_IRQ_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_IRQ_C    != ICU_70_AR_RELEASE_MINOR_VERSION_IRQ_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_IRQ_C != ICU_70_AR_RELEASE_REVISION_VERSION_IRQ_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_Irq.c and Icu_Irq.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_IRQ_C != ICU_70_SW_MAJOR_VERSION_IRQ_H ) || \
      ( ICU_70_SW_MINOR_VERSION_IRQ_C != ICU_70_SW_MINOR_VERSION_IRQ_H ) || \
      ( ICU_70_SW_PATCH_VERSION_IRQ_C != ICU_70_SW_PATCH_VERSION_IRQ_H ) \
    )
    #error "Software Version Numbers of Icu_Irq.c and Icu_Irq.h are different"
#endif

/* Icu_Irq.h version check end */
/* Icu_70_HW.h version check start */

#if ( ICU_70_VENDOR_ID_IRQ_C != ICU_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Icu_Irq.c and Icu_70_HW.h are different"
#endif

#if ( ICU_70_MODULE_ID_IRQ_C != ICU_70_MODULE_ID_HW_H )
    #error "MODULE ID for Icu_Irq.c and Icu_70_HW.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_IRQ_C    != ICU_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_IRQ_C    != ICU_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_IRQ_C != ICU_70_AR_RELEASE_REVISION_VERSION_HW_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_Irq.c and Icu_70_HW.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_IRQ_C != ICU_70_SW_MAJOR_VERSION_HW_H ) || \
      ( ICU_70_SW_MINOR_VERSION_IRQ_C != ICU_70_SW_MINOR_VERSION_HW_H ) || \
      ( ICU_70_SW_PATCH_VERSION_IRQ_C != ICU_70_SW_PATCH_VERSION_HW_H ) \
    )
    #error "Software Version Numbers of Icu_Irq.c and Icu_70_HW.h are different"
#endif

/* Icu_70_HW.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef void ( *Icu_70_HW_TAU_FuncType )( Icu_70_ChannelInfoType* chInfoPtr );
typedef void ( *Icu_70_HW_TRD_FuncType )( Icu_70_ChannelInfoType* chInfoPtr );

/*----------------------------------------------------------------------------*/
/* extern variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#if ( ( ICU_70_TIMER_API_ENABLE != FALSE ) && ( ICU_70_ENABLE_TRD_ANY != FALSE ) )
#define ICU_START_SEC_VAR_NO_INIT_LOCAL_8
#include "Icu_MemMap.h"
static uint8 s_regTrdSr;
#define ICU_STOP_SEC_VAR_NO_INIT_LOCAL_8
#include "Icu_MemMap.h"
#endif /* #if ( ( ICU_70_TIMER_API_ENABLE != FALSE ) && ( ICU_70_ENABLE_TRD_ANY != FALSE ) ) */
/*----------------------------------------------------------------------------*/
/* const                                                                      */
/*----------------------------------------------------------------------------*/
#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

#if ( ICU_SIGNAL_MEASUREMENT_API != FALSE )
#if ( ICU_70_ENABLE_TAU_ANY == TRUE )
/* function table for input type */
static const Icu_70_HW_TAU_FuncType s_IcuHwTAUFuncTbl[ICU_70_SIGNALMEASUREMENT_NUM] = {
    icu_70_HW_Irq_TAU_HighLow,
    icu_70_HW_Irq_TAU_HighLow,
    icu_70_HW_Irq_TAU_Period,
    icu_70_HW_Irq_TAU_DutyCycle
};
#endif/* ( ICU_70_ENABLE_TAU_ANY == TRUE ) */
#if ( ICU_70_ENABLE_TRD_ANY == TRUE )
/* function table for input type */
static const Icu_70_HW_TRD_FuncType s_IcuHwTRDFuncTbl[ICU_70_SIGNALMEASUREMENT_NUM] = {
    icu_70_HW_Irq_TRD_HighLow,
    icu_70_HW_Irq_TRD_HighLow,
    icu_70_HW_Irq_TRD_Period,
    icu_70_HW_Irq_TRD_DutyCycle
};
#endif/* ( ICU_70_ENABLE_TRD_ANY == TRUE ) */
#endif /* #if ( ICU_SIGNAL_MEASUREMENT_API != FALSE ) */

#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define ICU_START_SEC_CODE_LOCAL
#include "Icu_MemMap.h"

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU00                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU00                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU00  != FALSE )
void Icu_70_Isr_TAU00( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU0_CH0 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU00  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU01                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU01                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU01  != FALSE )
void Icu_70_Isr_TAU01( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU0_CH1 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU01  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU02                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU02                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU02  != FALSE )
void Icu_70_Isr_TAU02( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU0_CH2 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU02  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU03                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU03                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU03  != FALSE )
void Icu_70_Isr_TAU03( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU0_CH3 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU03  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU04                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU04                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU04  != FALSE )
void Icu_70_Isr_TAU04( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU0_CH4 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU04  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU05                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU05                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU05  != FALSE )
void Icu_70_Isr_TAU05( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU0_CH5 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU05  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU06                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU06                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU06  != FALSE )
void Icu_70_Isr_TAU06( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU0_CH6 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU06  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU07                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU07                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU07  != FALSE )
void Icu_70_Isr_TAU07( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU0_CH7 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU06  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU10                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU10                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU10  != FALSE )
void Icu_70_Isr_TAU10( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU1_CH0 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU10  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU11                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU11                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU11  != FALSE )
void Icu_70_Isr_TAU11( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU1_CH1 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU11  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU12                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU12                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU12  != FALSE )
void Icu_70_Isr_TAU12( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU1_CH2 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU12  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU13                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU13                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU13  != FALSE )
void Icu_70_Isr_TAU13( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU1_CH3 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU13  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU14                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU14                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU14  != FALSE )
void Icu_70_Isr_TAU14( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU1_CH4 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU14  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU15                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU15                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU15  != FALSE )
void Icu_70_Isr_TAU15( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU1_CH5 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU15  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU16                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU16                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU16  != FALSE )
void Icu_70_Isr_TAU16( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU1_CH6 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU16  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TAU17                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TAU17                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TAU17  != FALSE )
void Icu_70_Isr_TAU17( void )
{
    icu_70_Irq_TAU( ICU_70_IDX_TAU1_CH7 );
}
#endif      /* #if ( ICU_70_ENABLE_TAU17  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP0                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP0                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP0  != FALSE )
void Icu_70_Isr_INTP0( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP0 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP0  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP1                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP1                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP1  != FALSE )
void Icu_70_Isr_INTP1( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP1 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP1  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP2                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP2                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP2  != FALSE )
void Icu_70_Isr_INTP2( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP2 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP2  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP3                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP3                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP3  != FALSE )
void Icu_70_Isr_INTP3( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP3 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP3  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP4                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP4                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP4  != FALSE )
void Icu_70_Isr_INTP4( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP4 );

#endif      /* #if ( ICU_70_ENABLE_INTP4  != FALSE ) */



/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP5                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP5                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP5  != FALSE )
void Icu_70_Isr_INTP5( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP5 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP5  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP6                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP6                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP6  != FALSE )
void Icu_70_Isr_INTP6( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP6 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP6  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP7                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP7                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP7  != FALSE )
void Icu_70_Isr_INTP7( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP7 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP7  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP8                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP8                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP8  != FALSE )
void Icu_70_Isr_INTP8( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP8 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP8  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP9                                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP9                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP9  != FALSE )
void Icu_70_Isr_INTP9( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP9 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP9  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP10                                            */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP10                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP10  != FALSE )
void Icu_70_Isr_INTP10( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP10 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP10  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP11                                            */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP11                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP11  != FALSE )
void Icu_70_Isr_INTP11( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP11 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP11  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP12                                            */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP12                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP12  != FALSE )
void Icu_70_Isr_INTP12( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP12 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP12  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_INTP13                                            */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by INTP13                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_INTP13  != FALSE )
void Icu_70_Isr_INTP13( void )
{
    icu_70_Irq_INTP( ICU_70_IDX_INTP13 );
}
#endif      /* #if ( ICU_70_ENABLE_INTP13  != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TRD0                                              */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TRD0                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TRD0 != FALSE )
void Icu_70_Isr_TRD0( void )
{
    icu_70_Irq_TRD( ICU_70_IDX_TRD0 );
}
#endif      /* #if ( ICU_70_ENABLE_TRD0 != FALSE ) */

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_Isr_TRD1                                              */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Interrupt Service Routine by TRD1                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_70_ENABLE_TRD1 != FALSE )
void Icu_70_Isr_TRD1( void )
{
    icu_70_Irq_TRD( ICU_70_IDX_TRD1 );
}
#endif      /* #if ( ICU_70_ENABLE_TRD1 != FALSE  ) */

#if ( ICU_70_ENABLE_TAU_ANY != FALSE )
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_Irq_TAU                                               */
/* Param       : (in) IcuCh: TAU channel ID                                   */
/* Return      : void                                                         */
/* Contents    : measure the data that corresponds to the timer interrupt     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void icu_70_Irq_TAU( uint8 IcuCh )
{
    Icu_ModeType                mode;                   /* Icu Mode               */
    Icu_70_ChannelInfoType*     chInfoPtr = NULL_PTR;

    Icu_70_getChInfo( IcuCh, &chInfoPtr, &mode );

    /* Processing in normal mode. */
    if ( ICU_MODE_NORMAL == mode ) {
        icu_70_HW_Irq_TAU_Normal( chInfoPtr );
        if ( ( TRUE == chInfoPtr->notifSw ) && ( NULL_PTR != chInfoPtr->cbEdge ) ) {
            /* Calling configured notification function */
            /* [SWS_Icu_00011][SWS_Icu_00259][SWS_Icu_00119] */
            chInfoPtr->cbEdge();
        }
    /* Processing in sleep mode */
    /* [SWS_Icu_00260] */
    } else {
        /* Sleep mode when not in normal mode. */
        /* Check wakeup is enable and srcRef is valid */
        /* [SWS_Icu_00012][SWS_Icu_00261] */
        if ( ( TRUE == chInfoPtr->wuCap ) && ( TRUE == chInfoPtr->wuEbl ) ) {
#if ( ICU_REPORT_WAKEUP_SOURCE != FALSE )
            /* Calling EcuM_CheckWakeup. */
            /* [SWS_Icu_00244][SWS_Icu_00055][SWS_Icu_00056][SWS_Icu_00057][SWS_Icu_00228] */
            EcuM_CheckWakeup( chInfoPtr->wuSrc );          /* call EcuM_CheckWakeup function */
#endif      /* #if ( ICU_REPORT_WAKEUP_SOURCE != FALSE ) */
            if ( ( TRUE == chInfoPtr->notifSw ) && ( NULL_PTR != chInfoPtr->cbEdge ) ) {
                /* Calling configured notification function */
                /* [SWS_Icu_00119] */
                chInfoPtr->cbEdge();
            }
        }
    }
}
#endif  /* #if ( ICU_70_ENABLE_TAU_ANY != FALSE ) */

#if ( ICU_70_ENABLE_INTP_ANY != FALSE )
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_Irq_INTP                                              */
/* Param       : (in) IcuCh: INTP channel ID                                  */
/* Return      : void                                                         */
/* Contents    : measure the data that corresponds to the input edge          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void icu_70_Irq_INTP( uint8 IcuCh )
{
    Icu_ModeType            mode;                   /* Icu Mode               */
    Icu_70_ChannelInfoType* chInfoPtr = NULL_PTR;

    Icu_70_getChInfo( IcuCh, &chInfoPtr, &mode );

    /* Processing in normal mode. */
    if ( ICU_MODE_NORMAL == mode ) {
        /* Cannot use SignalMeasuremt and TimeStamp measurements using INTP. */
        if ( ICU_MODE_SIGNAL_EDGE_DETECT == chInfoPtr->msrMode ) {
            chInfoPtr->state = ICU_ACTIVE;      /* [SWS_Icu_00031] */
        } else {
            /* When using INTP, msrMode is Edge_Count if msrMode is not Edge_Detect. */
            /* [QINeS_SWS_ICU_00015] */
            if ( ICU_70_EDGECOUNTER_MAXVALUE > chInfoPtr->edgeCount ) {
                chInfoPtr->edgeCount++;
            }
        }
        if ( ( TRUE == chInfoPtr->notifSw ) && ( NULL_PTR != chInfoPtr->cbEdge ) ) {
            /* Calling configured notification function */
            /* [SWS_Icu_00011][SWS_Icu_00259][SWS_Icu_00119] */
            chInfoPtr->cbEdge();
        }
    /* Processing in sleep mode */
    /* [SWS_Icu_00260] */
    } else {
        /* Sleep mode when not in normal mode. */
        /* Check wakeup is enable and srcRef is valid */
        /* [SWS_Icu_00012][SWS_Icu_00261] */
        if ( ( TRUE == chInfoPtr->wuCap ) && ( TRUE == chInfoPtr->wuEbl ) ) {
#if ( ICU_REPORT_WAKEUP_SOURCE != FALSE )
            /* Calling EcuM_CheckWakeup. */
            /* [SWS_Icu_00244][SWS_Icu_00055][SWS_Icu_00056][SWS_Icu_00057][SWS_Icu_00228] */
            EcuM_CheckWakeup( chInfoPtr->wuSrc );             /* call EcuM_CheckWakeup function */
#endif      /* #if ( ICU_REPORT_WAKEUP_SOURCE != FALSE ) */
            if ( ( TRUE == chInfoPtr->notifSw ) && ( NULL_PTR != chInfoPtr->cbEdge ) ) {
                /* Calling configured notification function */
                /* [SWS_Icu_00119] */
                chInfoPtr->cbEdge();
            }
        }
    }
}
#endif  /* #if ( ICU_70_ENABLE_INTP_ANY != FALSE ) */

#if ( ICU_70_ENABLE_TAU_ANY != FALSE )
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_HW_Irq_TAU_Normal                                     */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : Icu module Normal processing.                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void icu_70_HW_Irq_TAU_Normal( Icu_70_ChannelInfoType* chInfoPtr )
{
    Icu_MeasurementModeType measurementMode;

    measurementMode = chInfoPtr->msrMode;

    switch ( measurementMode ) {
#if ( ICU_EDGE_DETECT_API != FALSE )
    case    ICU_MODE_SIGNAL_EDGE_DETECT:
        chInfoPtr->state = ICU_ACTIVE;    /* [SWS_Icu_00031]*/
        break;
#endif /* #if ( ICU_EDGE_DETECT_API != FALSE ) */
#if ( ICU_SIGNAL_MEASUREMENT_API != FALSE )
    case    ICU_MODE_SIGNAL_MEASUREMENT:
        /* call function for timer type */
        ( s_IcuHwTAUFuncTbl[ chInfoPtr->msrProp ] )( chInfoPtr );
        break;
#endif /*#if ( ICU_SIGNAL_MEASUREMENT_API != FALSE )*/
#if ( ICU_TIMESTAMP_API != FALSE )
    case    ICU_MODE_TIMESTAMP:
        icu_70_HW_Irq_TAU_TimeStamp( chInfoPtr );
        break;
#endif /* #if ( ICU_TIMESTAMP_API != FALSE ) */
#if ( ICU_EDGE_COUNT_API != FALSE )
    case    ICU_MODE_EDGE_COUNTER:
        /* [QINeS_SWS_ICU_00015] */
        if ( ICU_70_EDGECOUNTER_MAXVALUE > chInfoPtr->edgeCount ) {
            chInfoPtr->edgeCount++;
        }
        break;
#endif /* #if ( ICU_EDGE_COUNT_API != FALSE ) */
    default:
        /* DO NOTHING */
        break;
    }
}

#if ( ICU_TIMESTAMP_API != FALSE )
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_HW_Irq_TAU_TimeStamp                                  */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : The measurement of the timestamp                             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
LOCAL_INLINE void icu_70_HW_Irq_TAU_TimeStamp( Icu_70_ChannelInfoType* chInfoPtr )
{
    const Icu_70_RL78F2X_TAU_SettingConfType*    chInfo;
    Icu_ValueType cnt;

    chInfo = ( ( const Icu_70_RL78F2X_TAU_SettingConfType* )chInfoPtr->conf_chInfo->IcuSetConfPtr );

    /* Get Timer value adding with previous captured time */
    cnt = ( ( Icu_ValueType )chInfo->tdrPtr->regTdr + 1U + chInfoPtr->elapsedTime );
    /* If timestamp exceeds the timer maximum count, get the value counted from 0 */
    if ( ICU_70_RL78F2X_COUNTER_OVER_DATA <= cnt ) {
        cnt = cnt - ICU_70_RL78F2X_COUNTER_OVER_DATA;
    }

    chInfoPtr->buff[chInfoPtr->bufIdx] = cnt;
    chInfoPtr->elapsedTime = cnt;                                       /* elapsed time update    */
    chInfoPtr->bufIdx++;                                                /* Increment buff index   */
    /* buffer overflow check        */
    if ( chInfoPtr->bufSize <= chInfoPtr->bufIdx ) {
        /* Overflow ICU_LINEAR_BUFFER   */
        if ( ICU_LINEAR_BUFFER == chInfoPtr->bufType ) {
            /* [SWS_Icu_00065] */
            Icu_70_HW_StopTimer( chInfoPtr->conf_chInfo->IcuSetConfPtr );
            /* Channel stop */
            chInfoPtr->chRunning = FALSE;
        } else {                                                  /* Overflow ICU_CIRCULAR_BUFFER */
            /* [SWS_Icu_00064] */
            chInfoPtr->bufIdx = 0U;                               /* reset buff index             */
        }
    }

    /* [SWS_Icu_00319] */
    /* NotifyInterval zero check */
    if ( 0U != chInfoPtr->notifIntv ) {
        chInfoPtr->notifCnt++;                           /* Increment Notification interval Count */
        /* [SWS_Icu_00320] */
        if ( chInfoPtr->notifIntv <= chInfoPtr->notifCnt ) {    /* [SWS_Icu_00320] */
            /* [SWS_Icu_00318] */
            if ( ( TRUE == chInfoPtr->notifSw ) && ( NULL_PTR != chInfoPtr->cbTS ) ) {
                chInfoPtr->cbTS();                              /* [SWS_Icu_00134][SWS_Icu_00119] */
            }
            chInfoPtr->notifCnt = 0U;
        }
    }
}
#endif /* #if ( ICU_TIMESTAMP_API != FALSE ) */

#if ( ICU_SIGNAL_MEASUREMENT_API != FALSE )
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_HW_Irq_TAU_HighLow                                    */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : The measurement of the high time/low time                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
LOCAL_INLINE void icu_70_HW_Irq_TAU_HighLow( Icu_70_ChannelInfoType* chInfoPtr )
{
    const Icu_70_RL78F2X_TAU_SettingConfType*    chInfo;
    uint16 temp = 0;

    chInfo = ( const Icu_70_RL78F2X_TAU_SettingConfType* )chInfoPtr->conf_chInfo->IcuSetConfPtr;

    if ( ICU_70_MEAS_ACTIVE == chInfoPtr->irqState ) {
        /* [SWS_Icu_00081][SWS_Icu_00082] */
        /* Set Active Time  */
        chInfoPtr->elapsedTime = icu_70_RL78F2X_TAU_getTimerCount( chInfo );
        /* [SWS_Icu_00314] */
        /* Since it is now possible to provide useful information, */
        /* set the channel status to ACTIVE */
        chInfoPtr->state = ICU_ACTIVE;
        /* change irq state from MEASURE ACTIVE TIME to MEASURE PERIOD TIME */
        chInfoPtr->irqState    = ICU_70_MEAS_PERIOD;
    } else if ( ICU_70_MEAS_PERIOD == chInfoPtr->irqState ) {
        /* change irq state from MEASURE PERIOD TIME to MEASURE ACTIVE TIME */
        chInfoPtr->irqState = ICU_70_MEAS_ACTIVE;
    } else {
        temp = chInfo->contPtr->regTmr;
        /* Clear CIS */
        temp &= ICU_70_TMR_CIS_CLEAR;
        /* Set CIS = 2. Activation Edge is Both Edge */
        temp |= ICU_70_TMR_CIS2;
        chInfo->contPtr->regTmr = temp;
        /* change irq state from MEASURE NONE to MEASURE ACTIVE TIME */
        chInfoPtr->irqState = ICU_70_MEAS_ACTIVE;
    }
}

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_HW_Irq_TAU_Period                                     */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : The measurement of the period                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
LOCAL_INLINE void icu_70_HW_Irq_TAU_Period( Icu_70_ChannelInfoType* chInfoPtr )
{
    const Icu_70_RL78F2X_TAU_SettingConfType*    chInfo;
 
    chInfo = ( const Icu_70_RL78F2X_TAU_SettingConfType* )chInfoPtr->conf_chInfo->IcuSetConfPtr;
 
    if ( ICU_70_MEAS_PERIOD == chInfoPtr->irqState ) {
        /* [SWS_Icu_00083] */
        chInfoPtr->elapsedTime = icu_70_RL78F2X_TAU_getTimerCount( chInfo );
        /* [SWS_Icu_00314] */
        /* Since it is now possible to provide useful information, */
        /* set the channel status to ACTIVE. */
        chInfoPtr->state = ICU_ACTIVE;
    } else {
        /* change irq state from MEASURE NONE to MEASURE PERIOD TIME */
        chInfoPtr->irqState = ICU_70_MEAS_PERIOD;
    }
}

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_HW_Irq_TAU_DutyCycle                                  */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : The measurement of the duty cycle                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
LOCAL_INLINE void icu_70_HW_Irq_TAU_DutyCycle( Icu_70_ChannelInfoType* chInfoPtr )
{
    Icu_ValueType           cnt;
    const Icu_70_RL78F2X_TAU_SettingConfType*    chInfo;

    chInfo = ( const Icu_70_RL78F2X_TAU_SettingConfType* )chInfoPtr->conf_chInfo->IcuSetConfPtr;

    cnt = icu_70_RL78F2X_TAU_getTimerCount( chInfo );

    if ( ICU_70_MEAS_ACTIVE == chInfoPtr->irqState ) {
        /* [SWS_Icu_00084] */
        /* Set Active Time */
        chInfoPtr->duty.ActiveTime = cnt;
        /* change irq state from MEASURE ACTIVE TIME to MEASURE PERIOD TIME */
        chInfoPtr->irqState    = ICU_70_MEAS_PERIOD;
    } else if ( ICU_70_MEAS_PERIOD == chInfoPtr->irqState ) {
        /* [SWS_Icu_00084] */
        /* Set Period Time */
        chInfoPtr->duty.PeriodTime = chInfoPtr->duty.ActiveTime + cnt;
        /* change irq state from MEASURE PERIOD TIME to MEASURE ACTIVE TIME */
        chInfoPtr->irqState = ICU_70_MEAS_ACTIVE;
        /* [SWS_Icu_00314] */
        /* Since it is now possible to provide useful information, */
        /* set the channel status to ACTIVE. */
        chInfoPtr->state = ICU_ACTIVE;
    } else {
        /* Clear CIS */
        chInfo->contPtr->regTmr &= ICU_70_TMR_CIS_CLEAR;
        /* Set CIS = 2. Activation Edge is Both Edge */
        chInfo->contPtr->regTmr |= ICU_70_TMR_CIS2;
        /* change irq state from MEASURE NONE to MEASURE ACTIVE TIME */
        chInfoPtr->irqState = ICU_70_MEAS_ACTIVE;
    }
}
#endif /* #if ( ICU_SIGNAL_MEASUREMENT_API != FALSE ) */

#if ( ICU_70_TIMER_API_ENABLE != FALSE )
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_RL78F2X_TAU_getTimerCount                             */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : Get the value captured data register                         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
LOCAL_INLINE Icu_ValueType icu_70_RL78F2X_TAU_getTimerCount
                           ( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo )
{
    Icu_ValueType cnt;

    /* [SWS_Icu_00081][SWS_Icu_00082][SWS_Icu_00083][SWS_Icu_00084] */
    if ( 0U < ( chInfo->contPtr->regTsr ) ) {
        /* Get adding overflow Timer Value */
        cnt = ( Icu_ValueType )chInfo->tdrPtr->regTdr + 1U + ICU_70_RL78F2X_COUNTER_OVER_DATA;
    } else {
        /* Get Timer Value */
        cnt = ( Icu_ValueType )chInfo->tdrPtr->regTdr + 1U;
    }

    return cnt;
}
#endif  /* #if ( ICU_70_TIMER_API_ENABLE != FALSE ) */
#endif  /* #if ( ICU_70_ENABLE_TAU_ANY != FALSE ) */

#if ( ICU_70_ENABLE_TRD_ANY != FALSE )
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_Irq_TRD                                               */
/* Param       : (in) IcuCh: TRD channel ID                                   */
/* Return      : void                                                         */
/* Contents    : measure the data that corresponds to the timer interrupt     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void icu_70_Irq_TRD( uint8 IcuCh )
{
    Icu_ModeType                        mode;                   /* Icu Mode */
    Icu_70_ChannelInfoType*             chInfoPtr = NULL_PTR;
    const Icu_70_RL78F2X_TRD_SettingConfType* chConfPtr;

    Icu_70_getChInfo( IcuCh, &chInfoPtr, &mode );

    chConfPtr = ( const Icu_70_RL78F2X_TRD_SettingConfType* )chInfoPtr->conf_chInfo->IcuSetConfPtr;
#if ( ICU_70_TIMER_API_ENABLE != FALSE )
    /* save TRDSR register */
    s_regTrdSr = chConfPtr->contPtr->regTrdSr;
#endif  /* #if ( ICU_70_TIMER_API_ENABLE != FALSE ) */
    /* [SWS_Icu_00229] */
    /* clear  TRDSR register */
    Icu_70_HW_ClrInt( chConfPtr );             /* Clear TRDSRi register */


    /* Processing in normal mode. */
    if ( ICU_MODE_NORMAL == mode ) {
        icu_70_HW_Irq_TRD_Normal( chInfoPtr );
        if ( ( TRUE == chInfoPtr->notifSw ) && ( NULL_PTR != chInfoPtr->cbEdge ) ) {
            /* Calling configured notification function */
            /* [SWS_Icu_00011][SWS_Icu_00259][SWS_Icu_00119] */
            chInfoPtr->cbEdge();
        }
    /* Processing in sleep mode */
    /* [SWS_Icu_00260] */
    } else {
        /* Sleep mode when not in normal mode. */
        /* Check wakeup is enable and srcRef is valid */
        /* [SWS_Icu_00012][SWS_Icu_00261] */
        if ( ( TRUE == chInfoPtr->wuCap ) && ( TRUE == chInfoPtr->wuEbl ) ) {
#if ( ICU_REPORT_WAKEUP_SOURCE != FALSE )
            /* Calling EcuM_CheckWakeup. */
            /* [SWS_Icu_00244][SWS_Icu_00055][SWS_Icu_00056][SWS_Icu_00057][SWS_Icu_00228] */
            EcuM_CheckWakeup( chInfoPtr->wuSrc );               /* call EcuM_CheckWakeup function */
#endif      /* #if ( ICU_REPORT_WAKEUP_SOURCE != FALSE ) */
            if ( ( TRUE == chInfoPtr->notifSw ) && ( NULL_PTR != chInfoPtr->cbEdge ) ) {
                /* Calling configured notification function */
                /* [SWS_Icu_00119] */
                chInfoPtr->cbEdge();
            }
        }
    }
}

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_HW_Irq_TRD_Normal                                     */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : Icu module Normal processing.                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void icu_70_HW_Irq_TRD_Normal( Icu_70_ChannelInfoType* chInfoPtr )
{
    Icu_MeasurementModeType measurementMode;

    measurementMode = chInfoPtr->msrMode;

    switch ( measurementMode ) {
#if ( ICU_EDGE_DETECT_API != FALSE )
    case    ICU_MODE_SIGNAL_EDGE_DETECT:
        chInfoPtr->state = ICU_ACTIVE;    /* [SWS_Icu_00031]*/
        break;
#endif /* #if ( ICU_EDGE_DETECT_API != FALSE ) */

#if ( ICU_SIGNAL_MEASUREMENT_API != FALSE )
    case    ICU_MODE_SIGNAL_MEASUREMENT:
        /* call function for timer type */
        ( s_IcuHwTRDFuncTbl[ chInfoPtr->msrProp ] )( chInfoPtr );
        break;
#endif /* #if ( ICU_SIGNAL_MEASUREMENT_API != FALSE ) */

#if ( ICU_TIMESTAMP_API != FALSE )
    case    ICU_MODE_TIMESTAMP:
        icu_70_HW_Irq_TRD_TimeStamp( chInfoPtr );
        break;
#endif /* #if ( ICU_TIMESTAMP_API != FALSE ) */

#if ( ICU_EDGE_COUNT_API != FALSE )
    case    ICU_MODE_EDGE_COUNTER:
        /* [QINeS_SWS_ICU_00015] */
        if ( ICU_70_EDGECOUNTER_MAXVALUE > chInfoPtr->edgeCount ) {
            chInfoPtr->edgeCount++;
        }
        break;
#endif /* #if ( ICU_EDGE_COUNT_API != FALSE ) */
    default:
        /* DO NOTHING */
        break;
    }
}

#if ( ICU_TIMESTAMP_API != FALSE )
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_HW_Irq_TRD_TimeStamp                                  */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : The measurement of the timestamp                             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
LOCAL_INLINE void icu_70_HW_Irq_TRD_TimeStamp( Icu_70_ChannelInfoType* chInfoPtr )
{
    const Icu_70_RL78F2X_TRD_SettingConfType*    chInfo;
    Icu_ValueType cnt;
    uint8 trdSrBitCheck;

    chInfo = ( ( const Icu_70_RL78F2X_TRD_SettingConfType* )chInfoPtr->conf_chInfo->IcuSetConfPtr );

    /* Get the input port of TRD unit to check in TRDSR register */
    trdSrBitCheck =  ( chInfo->inputPort + ICU_70_SET_U1BIT ) & s_regTrdSr;

    if ( ICU_70_TRDSR_PORT_A == trdSrBitCheck ) {
        /* Get Timer Value TRDGRA adding with previous captured time */
        cnt = ( Icu_ValueType )chInfo->contPtr->regTrdGra + chInfoPtr->elapsedTime;
    } else {
        /* Get Timer Value TRDGRB adding with previous captured time */
        cnt = ( Icu_ValueType )chInfo->contPtr->regTrdGrb + chInfoPtr->elapsedTime;
    }

    /* If timestamp exceeds the timer maximum count, get the value counted from 0 */
    if ( ICU_70_RL78F2X_COUNTER_OVER_DATA <= cnt ) {
        cnt = cnt - ICU_70_RL78F2X_COUNTER_OVER_DATA;
    }

    chInfoPtr->buff[chInfoPtr->bufIdx] = cnt;
    chInfoPtr->elapsedTime = cnt;                                 /* elapsed time update    */
    chInfoPtr->bufIdx++;                                          /* Increment buff index   */
    /* buffer overflow check        */
    if ( chInfoPtr->bufSize <= chInfoPtr->bufIdx ) {
        /* Overflow ICU_LINEAR_BUFFER   */
        if ( ICU_LINEAR_BUFFER == chInfoPtr->bufType ) {
            /* [SWS_Icu_00065] */
            /* stop timestamp */
            Icu_70_HW_StopTimer( chInfoPtr->conf_chInfo->IcuSetConfPtr );
            /* Channel stop */
            chInfoPtr->chRunning = FALSE;
        } else {                                                  /* Overflow ICU_CIRCULAR_BUFFER */
            /* [SWS_Icu_00064] */
            chInfoPtr->bufIdx = 0U;                               /* reset buff index             */
        }
    }

    /* NotifyInterval zero check */ /* [SWS_Icu_00319] */
    if ( 0U != chInfoPtr->notifIntv ) {
        chInfoPtr->notifCnt++;                          /* Increment Notification interval Count  */
        /* [SWS_Icu_00320] */
        if ( chInfoPtr->notifIntv <= chInfoPtr->notifCnt ) {                   /* [SWS_Icu_00320] */
            /* [SWS_Icu_00318] */
            if ( ( TRUE == chInfoPtr->notifSw ) && ( NULL_PTR != chInfoPtr->cbTS ) ) {
                chInfoPtr->cbTS();                              /* [SWS_Icu_00134][SWS_Icu_00119] */
            }
            chInfoPtr->notifCnt = 0U;
        }
    }
}
#endif /* #if ( ICU_TIMESTAMP_API != FALSE ) */

#if ( ICU_SIGNAL_MEASUREMENT_API != FALSE )
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_HW_Irq_TRD_HighLow                                    */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : The measurement of the high time/low time                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
LOCAL_INLINE void icu_70_HW_Irq_TRD_HighLow( Icu_70_ChannelInfoType* chInfoPtr )
{
    const Icu_70_RL78F2X_TRD_SettingConfType*    chInfo;

    chInfo = ( const Icu_70_RL78F2X_TRD_SettingConfType* )chInfoPtr->conf_chInfo->IcuSetConfPtr;

    if ( ICU_70_MEAS_ACTIVE == chInfoPtr->irqState ) {
        /* [SWS_Icu_00081][SWS_Icu_00082] */
        chInfoPtr->elapsedTime = icu_70_RL78F2X_TRD_getTimerCount( chInfo );
        /* [SWS_Icu_00314] */
        /* Since it is now possible to provide useful information, */
        /* set the channel status to ACTIVE. */
        chInfoPtr->state = ICU_ACTIVE;
        /* change irq state from MEASURE ACTIVE TIME to MEASURE PERIOD TIME */
        chInfoPtr->irqState    = ICU_70_MEAS_PERIOD;
    } else if ( ICU_70_MEAS_PERIOD == chInfoPtr->irqState ) {
        /* change irq state from MEASURE PERIOD TIME to MEASURE ACTIVE TIME */
        chInfoPtr->irqState = ICU_70_MEAS_ACTIVE;
    } else {
        /* Clear edge */
        chInfo->contPtr->regTrdIora &= ( uint8 )( ~( uint8 )( ICU_70_TRD_TRDIORA_IO
                                    << ( uint8 )( chInfo->inputPort << ICU_70_TRDIOR_SHIFT ) ) );
        /* Set Both Edge */
        chInfo->contPtr->regTrdIora |= ( uint8 )( ICU_70_TRDIORA_BOTH_EDGE
                                    << ( uint8 )( chInfo->inputPort << ICU_70_TRDIOR_SHIFT ) );
        /* change irq state from MEASURE NONE to MEASURE ACTIVE TIME */
        chInfoPtr->irqState = ICU_70_MEAS_ACTIVE;
    }
}

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_HW_Irq_TRD_Period                                     */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : The measurement of the period                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
LOCAL_INLINE void icu_70_HW_Irq_TRD_Period( Icu_70_ChannelInfoType* chInfoPtr )
{
    const Icu_70_RL78F2X_TRD_SettingConfType*    chInfo;

    chInfo = ( const Icu_70_RL78F2X_TRD_SettingConfType* )chInfoPtr->conf_chInfo->IcuSetConfPtr;

    if ( ICU_70_MEAS_PERIOD == chInfoPtr->irqState ) {
        /* [SWS_Icu_00083] */
        chInfoPtr->elapsedTime = icu_70_RL78F2X_TRD_getTimerCount( chInfo );
        /* [SWS_Icu_00314] */
        /* Since it is now possible to provide useful information, */
        /* set the channel status to ACTIVE. */
        chInfoPtr->state = ICU_ACTIVE;
    } else {
        /* change irq state from MEASURE NONE to MEASURE PERIOD TIME */
        chInfoPtr->irqState = ICU_70_MEAS_PERIOD;
    }
}

/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_HW_Irq_TRD_DutyCycle                                  */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : The measurement of the duty cycle                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
LOCAL_INLINE void icu_70_HW_Irq_TRD_DutyCycle( Icu_70_ChannelInfoType* chInfoPtr )
{
    Icu_ValueType           cnt;
    const Icu_70_RL78F2X_TRD_SettingConfType*    chInfo;

    chInfo = ( const Icu_70_RL78F2X_TRD_SettingConfType* )chInfoPtr->conf_chInfo->IcuSetConfPtr;

    cnt = icu_70_RL78F2X_TRD_getTimerCount( chInfo );

    if ( ICU_70_MEAS_ACTIVE == chInfoPtr->irqState ) {
        /* [SWS_Icu_00084] */
        /* Set Active Time */
        chInfoPtr->duty.ActiveTime = cnt;
        /* change irq state from MEASURE ACTIVE TIME to MEASURE PERIOD TIME */
        chInfoPtr->irqState    = ICU_70_MEAS_PERIOD;
    } else if ( ICU_70_MEAS_PERIOD == chInfoPtr->irqState ) {
        /* [SWS_Icu_00084] */
        /* Set Period Time */
        chInfoPtr->duty.PeriodTime = chInfoPtr->duty.ActiveTime + cnt;
        /* change irq state from MEASURE PERIOD TIME to MEASURE ACTIVE TIME */
        chInfoPtr->irqState = ICU_70_MEAS_ACTIVE;
        /* [SWS_Icu_00314] */
        /* Since it is now possible to provide useful information, */
        /* set the channel status to ACTIVE. */
        chInfoPtr->state = ICU_ACTIVE;
    } else {
        /* Clear edge */
        chInfo->contPtr->regTrdIora &= ( uint8 )( ~( uint8 )( ICU_70_TRD_TRDIORA_IO
                                    << ( uint8 )( chInfo->inputPort << ICU_70_TRDIOR_SHIFT ) ) );
        /* Set Both Edge */
        chInfo->contPtr->regTrdIora |= ( uint8 )( ICU_70_TRDIORA_BOTH_EDGE
                                    << ( uint8 )( chInfo->inputPort << ICU_70_TRDIOR_SHIFT ) );
        /* change irq state from MEASURE NONE to MEASURE ACTIVE TIME */
        chInfoPtr->irqState = ICU_70_MEAS_ACTIVE;
    }
}
#endif /* #if ( ICU_SIGNAL_MEASUREMENT_API != FALSE ) */

#if ( ICU_70_TIMER_API_ENABLE != FALSE )
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_RL78F2X_TRD_getTimerCount                             */
/* Param       : (in) chInfoPtr  pointer to channel info table                */
/* Return      : void                                                         */
/* Contents    : measure the data that corresponds to the input edge          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
LOCAL_INLINE Icu_ValueType icu_70_RL78F2X_TRD_getTimerCount
                            ( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo )
{
    Icu_ValueType cnt;
    uint8 trdSrBitCheck;

    /* Get the input port of TRD unit to check in TRDSR register */
    trdSrBitCheck = ( ICU_70_TRDSR_OVF_BIT | ( chInfo->inputPort + ICU_70_SET_U1BIT ) )
                  & s_regTrdSr;

    /* [SWS_Icu_00081][SWS_Icu_00082][SWS_Icu_00083][SWS_Icu_00084] */
    if ( ICU_70_TRDSR_PORT_A_OVERFLOW == trdSrBitCheck ) {
        /* Get adding overflow Timer Value */
        cnt = ICU_70_RL78F2X_COUNTER_OVER_DATA + chInfo->contPtr->regTrdGra;
    } else if ( ICU_70_TRDSR_PORT_A == trdSrBitCheck ) {
        /* Get Timer Value */
        cnt = chInfo->contPtr->regTrdGra;
    } else if ( ICU_70_TRDSR_PORT_B_OVERFLOW == trdSrBitCheck ) {
        /* Get adding overflow Timer Value */
        cnt = ICU_70_RL78F2X_COUNTER_OVER_DATA + chInfo->contPtr->regTrdGrb;
    } else {
        /* Get Timer Value */
        cnt = ( Icu_ValueType )chInfo->contPtr->regTrdGrb;
    }
    return cnt;
}
#endif  /* #if ( ICU_70_TIMER_API_ENABLE != FALSE ) */
#endif  /* #if ( ICU_70_ENABLE_TRD_ANY != FALSE ) */

#define ICU_STOP_SEC_CODE_LOCAL
#include "Icu_MemMap.h"

/* EOF Icu_Irq.c **************************************************************/