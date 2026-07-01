/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Can_Irq_Dep.c                                                */
/* Version     : v1.00.00                                                     */
/* Contents    : This module provides services for initiating transmissions   */
/*               and calls the callback functions of the CanIf module for     */
/*               notifying events, independently from the hardware. Also it   */
/*               provides services to control the behavior and state of the   */
/*               CAN controllers that belong to the same CAN Hardware Unit.   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of CAN Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Can.h"
#include "Can_70_RL78F2X_HwReg.h"
#include "Can_Irq.h"
#include "CanIf_Cbk.h"
#include "SchM_Can.h"
#include "EcuM_Cbk.h"
#include "Det.h"
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define CAN_70_VENDOR_ID_IRQ_DEP_C                             ( 70U )
#define CAN_70_MODULE_ID_IRQ_DEP_C                             ( 80U )

#define CAN_70_AR_RELEASE_MAJOR_VERSION_IRQ_DEP_C              ( 22U )
#define CAN_70_AR_RELEASE_MINOR_VERSION_IRQ_DEP_C              ( 11U )
#define CAN_70_AR_RELEASE_REVISION_VERSION_IRQ_DEP_C           (  0U )

#define CAN_70_SW_MAJOR_VERSION_IRQ_DEP_C                      (  1U )
#define CAN_70_SW_MINOR_VERSION_IRQ_DEP_C                      (  0U )
#define CAN_70_SW_PATCH_VERSION_IRQ_DEP_C                      (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Can.h version check start */

/* Check if current file and Can.h header file are of the same Vendor ID */
#if (CAN_70_VENDOR_ID_IRQ_DEP_C    != CAN_VENDOR_ID)
    #error "VENDOR ID for Can_Irq_Dep.c and Can.h are different"
#endif      /* End of Vendor Id Version check */
#if (CAN_70_MODULE_ID_IRQ_DEP_C    != CAN_MODULE_ID)
    #error "MODULE ID for Can_Irq_Dep.c and Can.h are different"
#endif      /* End of Module Id Version check */

/* Check if current file and Can.h header file are of the same Software version */
#if ((CAN_70_SW_MAJOR_VERSION_IRQ_DEP_C    != CAN_SW_MAJOR_VERSION) ||\
     (CAN_70_SW_MINOR_VERSION_IRQ_DEP_C    != CAN_SW_MINOR_VERSION) ||\
     (CAN_70_SW_PATCH_VERSION_IRQ_DEP_C    != CAN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_Irq_Dep.c and Can.h are different"
#endif      /* End of S/W Version check */

/* Check if current file and Can.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_IRQ_DEP_C    != CAN_AR_RELEASE_MAJOR_VERSION)   ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_IRQ_DEP_C    != CAN_AR_RELEASE_MINOR_VERSION)   ||\
     (CAN_70_AR_RELEASE_REVISION_VERSION_IRQ_DEP_C != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Can_Irq_Dep.c and Can.h are different"
#endif      /* End of Autosar Version check */

/*---------------Can_70_RL78F2X_HwReg.h--------------------------------------------------*/

/* Check if current file and Can_70_RL78F2X_HwReg.h header file are of the same Vendor ID */
#if (CAN_70_VENDOR_ID_IRQ_DEP_C    != CAN_70_VENDOR_ID_RL78F2X_HWREG_H)
    #error "VENDOR ID for Can_Irq_Dep.c and Can_70_RL78F2X_HwReg.h are different"
#endif      /* End of Vendor Id Version check */
#if (CAN_70_MODULE_ID_IRQ_DEP_C    != CAN_70_MODULE_ID_RL78F2X_HWREG_H)
    #error "MODULE ID for Can_Irq_Dep.c and Can_70_RL78F2X_HwReg.h are different"
#endif      /* End of Module Id Version check */

/* Check if current file and Can_70_RL78F2X_HwReg.h header file are of the same Software version */
#if ((CAN_70_SW_MAJOR_VERSION_IRQ_DEP_C    != CAN_70_SW_MAJOR_VERSION_RL78F2X_HWREG_H) ||\
     (CAN_70_SW_MINOR_VERSION_IRQ_DEP_C    != CAN_70_SW_MINOR_VERSION_RL78F2X_HWREG_H) ||\
     (CAN_70_SW_PATCH_VERSION_IRQ_DEP_C    != CAN_70_SW_PATCH_VERSION_RL78F2X_HWREG_H))
    #error "Software Version Numbers of Can_Irq_Dep.c and Can_70_RL78F2X_HwReg.h are different"
#endif      /* End of S/W Version check */

/* Check if current file and Can_70_RL78F2X_HwReg.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_IRQ_DEP_C         != \
      CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_HWREG_H)  || \
     (CAN_70_AR_RELEASE_MINOR_VERSION_IRQ_DEP_C         != \
      CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_HWREG_H)  || \
     (CAN_70_AR_RELEASE_REVISION_VERSION_IRQ_DEP_C      != \
      CAN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_HWREG_H))
    #error "AUTOSAR Version Numbers of Can_Irq_Dep.c and Can_70_RL78F2X_HwReg.h are different"
#endif      /* End of Autosar Version check */

/*---------------------------Can_Irq.h--------------------------------------------------*/

/* Check if current file and Can_Irq.h header file are of the same Vendor ID */
#if (CAN_70_VENDOR_ID_IRQ_DEP_C    != CAN_70_VENDOR_ID_IRQ_H)
    #error "VENDOR ID for Can_Irq_Dep.c and Can_Irq.h are different"
#endif      /* End of Vendor Id Version check */
#if (CAN_70_MODULE_ID_IRQ_DEP_C    != CAN_70_MODULE_ID_IRQ_H)
    #error "MODULE ID for Can_Irq_Dep.c and Can_Irq.h are different"
#endif      /* End of Vendor Id Version check */

/* Check if current file and Can_Irq.h header file are of the same Software version */
#if ((CAN_70_SW_MAJOR_VERSION_IRQ_DEP_C    != CAN_70_SW_MAJOR_VERSION_IRQ_H) ||\
     (CAN_70_SW_MINOR_VERSION_IRQ_DEP_C    != CAN_70_SW_MINOR_VERSION_IRQ_H) ||\
     (CAN_70_SW_PATCH_VERSION_IRQ_DEP_C    != CAN_70_SW_PATCH_VERSION_IRQ_H))
    #error "Software Version Numbers of Can_Irq_Dep.c and Can_Irq.h are different"
#endif      /* End of S/W Version check */

/* Check if current file and Can_Irq.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_IRQ_DEP_C    != CAN_70_AR_RELEASE_MAJOR_VERSION_IRQ_H)   ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_IRQ_DEP_C    != CAN_70_AR_RELEASE_MINOR_VERSION_IRQ_H)   ||\
     (CAN_70_AR_RELEASE_REVISION_VERSION_IRQ_DEP_C != CAN_70_AR_RELEASE_REVISION_VERSION_IRQ_H))
    #error "AUTOSAR Version Numbers of Can_Irq_Dep.c and Can_Irq.h are different"
#endif      /* End of Autosar Version check */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/*---------------CanIf_Cbk.h--------------------------------------------------*/

/* Check if current file and CanIf_Cbk.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_IRQ_DEP_C    != CANIF_70_AR_RELEASE_MAJOR_VERSION_CBK_H)   ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_IRQ_DEP_C    != CANIF_70_AR_RELEASE_MINOR_VERSION_CBK_H))
    #error "AUTOSAR Version Numbers of Can.c and CanIf_Cbk.h are different"
#endif      /* End of Autosar Version check */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/*---------------EcuM_Cbk.h--------------------------------------------------*/

/* Check if current file and EcuM_Cbk.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_IRQ_DEP_C != ECUM_AR_RELEASE_MAJOR_VERSION_CBK_H)   ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_IRQ_DEP_C != ECUM_AR_RELEASE_MINOR_VERSION_CBK_H))
    #error "AUTOSAR Version Numbers of Can.c and EcuM_Cbk.h are different"
#endif      /* End of Autosar Version check */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/*---------------Det.h -------------------------------------------------------*/

/* Check if DET for CAN is enabled or not */
#if( CAN_DEV_ERROR_DETECT != FALSE )
/* Check if current file and Det.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_IRQ_DEP_C    != DET_AR_RELEASE_MAJOR_VERSION)   ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_IRQ_DEP_C    != DET_AR_RELEASE_MINOR_VERSION))
    #error "AUTOSAR Version Numbers of Can_Irq_Dep.c and Det.h are different"
#endif      /* End of Autosar Version check */
#endif      /* #if( CAN_DEV_ERROR_DETECT != FALSE ) */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/* Can_Irq.c version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                  Interrupt Service Routines                                */
/*----------------------------------------------------------------------------*/
#define CAN_START_SEC_CODE_LOCAL
#include "Can_MemMap.h"

#if( ( CAN_70_RX_INTERRUPT_PROCESSING == TRUE ) || ( CAN_70_RX_MIXED_PROCESSING == TRUE ) )
/******************************************************************************/
/* ModuleID    : CAN_MODULE_ID (080)                                          */
/* ServiceID   : --                                                           */
/* Name        : Can_70_Isr_Reception_CAN0                                    */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Refers to the CAN controller register and performs           */
/*               reception processing.                                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Can_70_Isr_Reception_CAN0( void )
{
    Can_70_Isr_Reception_CANX( CAN_70_CAN_CHANNEL_CAN0 );
}
#endif /* #if( ( CAN_70_RX_INTERRUPT_PROCESSING == TRUE ) || ( CAN_70_RX_MIXED_PROCESSING == TRUE ) ) */

#if( ( CAN_70_RX_INTERRUPT_PROCESSING == TRUE ) || ( CAN_70_RX_MIXED_PROCESSING == TRUE ) )
/******************************************************************************/
/* ModuleID    : CAN_MODULE_ID (080)                                          */
/* ServiceID   : --                                                           */
/* Name        : Can_70_Isr_Reception_CAN1                                    */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Refers to the CAN controller register and performs           */
/*               reception processing.                                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Can_70_Isr_Reception_CAN1( void )
{
    Can_70_Isr_Reception_CANX( CAN_70_CAN_CHANNEL_CAN1 );
}
#endif /* #if( ( CAN_70_RX_INTERRUPT_PROCESSING == TRUE ) || ( CAN_70_RX_MIXED_PROCESSING == TRUE ) ) */

/******************************************************************************/
/* ModuleID    : CAN_MODULE_ID (080)                                          */
/* ServiceID   : --                                                           */
/* Name        : Can_70_Isr_GlobalError_CAN0                                  */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Refers to the CAN controller register and notifies           */
/*               Det of the error.                                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Can_70_Isr_GlobalError_CAN0( void )
{
    Can_70_Isr_GlobalError_CANX( CAN_70_CAN_CHANNEL_CAN0 );
}

/******************************************************************************/
/* ModuleID    : CAN_MODULE_ID (080)                                          */
/* ServiceID   : --                                                           */
/* Name        : Can_70_Isr_GlobalError_CAN1                                  */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Refers to the CAN controller register and notifies           */
/*               Det of the error.                                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Can_70_Isr_GlobalError_CAN1( void )
{
    Can_70_Isr_GlobalError_CANX( CAN_70_CAN_CHANNEL_CAN1 );
}

#if( ( CAN_70_TX_INTERRUPT_PROCESSING == TRUE ) || ( CAN_70_TX_MIXED_PROCESSING == TRUE ) )
/******************************************************************************/
/* ModuleID    : CAN_MODULE_ID (080)                                          */
/* ServiceID   : --                                                           */
/* Name        : Can_70_Isr_Transmission_CAN0                                 */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Refers to the CAN controller register and performs           */
/*               transmission completion processing.                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Can_70_Isr_Transmission_CAN0( void )
{
    Can_70_Isr_Transmission_CANX( CAN_70_CAN_CHANNEL_CAN0 );
}
#endif /* #if( ( CAN_70_TX_INTERRUPT_PROCESSING == TRUE ) || ( CAN_70_TX_MIXED_PROCESSING == TRUE ) ) */

#if( ( CAN_70_TX_INTERRUPT_PROCESSING == TRUE ) || ( CAN_70_TX_MIXED_PROCESSING == TRUE ) )
/******************************************************************************/
/* ModuleID    : CAN_MODULE_ID (080)                                          */
/* ServiceID   : --                                                           */
/* Name        : Can_70_Isr_Transmission_CAN1                                 */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Refers to the CAN controller register and performs           */
/*               transmission completion processing.                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Can_70_Isr_Transmission_CAN1( void )
{
    Can_70_Isr_Transmission_CANX( CAN_70_CAN_CHANNEL_CAN1 );
}
#endif /* #if( ( CAN_70_TX_INTERRUPT_PROCESSING == TRUE ) || ( CAN_70_TX_MIXED_PROCESSING == TRUE ) ) */

/******************************************************************************/
/* ModuleID    : CAN_MODULE_ID (080)                                          */
/* ServiceID   : --                                                           */
/* Name        : Can_70_Isr_ChannelError_CAN0                                 */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Refers to the register of the CAN controller and notifies    */
/*               the upper layer of the error.                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Can_70_Isr_ChannelError_CAN0( void )
{
    Can_70_Isr_ChannelError_CANX( CAN_70_CAN_CHANNEL_CAN0 );
}

/******************************************************************************/
/* ModuleID    : CAN_MODULE_ID (080)                                          */
/* ServiceID   : --                                                           */
/* Name        : Can_70_Isr_ChannelError_CAN1                                 */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Refers to the register of the CAN controller and notifies    */
/*               the upper layer of the error.                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Can_70_Isr_ChannelError_CAN1( void )
{
    Can_70_Isr_ChannelError_CANX( CAN_70_CAN_CHANNEL_CAN1 );
}

#if ( ( CAN_70_WAKEUP_SUPPORT == TRUE ) && ( CAN_70_WAKEUP_INTERRUPT_PROCESSING == TRUE ) )
/******************************************************************************/
/* ModuleID    : CAN_MODULE_ID (080)                                          */
/* ServiceID   : --                                                           */
/* Name        : Can_70_Isr_Wakeup_CAN0                                       */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Refers to the register of the CAN controller and notifies    */
/*               the upper layer of the wakeup.                               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Can_70_Isr_Wakeup_CAN0( void )
{
    Can_70_Isr_Wakeup_CANX( CAN_70_CAN_CHANNEL_CAN0 );
}
#endif /* #if ( ( CAN_70_WAKEUP_SUPPORT == TRUE ) && ( CAN_70_WAKEUP_INTERRUPT_PROCESSING == TRUE ) ) */

#if ( ( CAN_70_WAKEUP_SUPPORT == TRUE ) && ( CAN_70_WAKEUP_INTERRUPT_PROCESSING == TRUE ) )
/******************************************************************************/
/* ModuleID    : CAN_MODULE_ID (080)                                          */
/* ServiceID   : --                                                           */
/* Name        : Can_70_Isr_Wakeup_CAN1                                       */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Refers to the register of the CAN controller and notifies    */
/*               the upper layer of the wakeup.                               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Can_70_Isr_Wakeup_CAN1( void )
{
    Can_70_Isr_Wakeup_CANX( CAN_70_CAN_CHANNEL_CAN1 );
}
#endif /* #if ( ( CAN_70_WAKEUP_SUPPORT == TRUE ) && ( CAN_70_WAKEUP_INTERRUPT_PROCESSING == TRUE ) ) */

#define CAN_STOP_SEC_CODE_LOCAL
#include "Can_MemMap.h"
/* EOF Can_Irq_Dep.c **********************************************************/