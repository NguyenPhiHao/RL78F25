/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Lin_Irq.c                                                    */
/* Version     : v1.00.02                                                     */
/* Contents    : This file is LIN Driver Interrupt Source                     */
/*               Lin Driver State IRQ implementation                          */
/*               The LIN is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Lin_Irq.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_70_VENDOR_ID_IRQ_C                      ( 70U )
#define LIN_70_MODULE_ID_IRQ_C                      ( 82U )

#define LIN_70_AR_RELEASE_MAJOR_VERSION_IRQ_C       ( 22U )
#define LIN_70_AR_RELEASE_MINOR_VERSION_IRQ_C       ( 11U )
#define LIN_70_AR_RELEASE_REVISION_VERSION_IRQ_C    ( 0U )

#define LIN_70_SW_MAJOR_VERSION_IRQ_C               ( 1U )
#define LIN_70_SW_MINOR_VERSION_IRQ_C               ( 0U )
#define LIN_70_SW_PATCH_VERSION_IRQ_C               ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*------------------- Lin_Irq.h --------------------------------------------- */
#if ( LIN_70_VENDOR_ID_IRQ_H != LIN_70_VENDOR_ID_IRQ_C )
    #error "VENDOR ID for Lin_Irq.h and Lin_Irq.c are different"
#endif

#if ( LIN_70_MODULE_ID_IRQ_H != LIN_70_MODULE_ID_IRQ_C )
    #error "MODULE ID for Lin_Irq.h and Lin_Irq.c are different"
#endif

#if ( ( LIN_70_AR_RELEASE_MAJOR_VERSION_IRQ_H    != LIN_70_AR_RELEASE_MAJOR_VERSION_IRQ_C ) || \
      ( LIN_70_AR_RELEASE_MINOR_VERSION_IRQ_H    != LIN_70_AR_RELEASE_MINOR_VERSION_IRQ_C ) || \
      ( LIN_70_AR_RELEASE_REVISION_VERSION_IRQ_H != LIN_70_AR_RELEASE_REVISION_VERSION_IRQ_C ) \
    )
    #error "AUTOSAR Version Numbers of Lin_Irq.h and Lin_Irq.c are different"
#endif

#if ( ( LIN_70_SW_MAJOR_VERSION_IRQ_H != LIN_70_SW_MAJOR_VERSION_IRQ_C ) || \
      ( LIN_70_SW_MINOR_VERSION_IRQ_H != LIN_70_SW_MINOR_VERSION_IRQ_C ) || \
      ( LIN_70_SW_PATCH_VERSION_IRQ_H != LIN_70_SW_PATCH_VERSION_IRQ_C ) \
    )
    #error "Software Version Numbers of Lin_Irq.h and Lin_Irq.c are different"
#endif

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

#define LIN_START_SEC_CODE_LOCAL
#include "Lin_MemMap.h"

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_70_IsrTx                                                 */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : t.oota Wrapper Transmit interrupt process.                   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Lin_70_Isr_TxCh0(void)
{
    uint8 chIndex;
    Std_ReturnType stdResult = E_NOT_OK;

    stdResult = Lin_searchChIndex( LIN_70_CH0, &chIndex );
    if ( stdResult == E_OK ) {
        /* Call transmit interrupt handler if transmission interrupt occurs at interrupt vector */
        if ( s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinNodeType == LIN_70_MASTER ) /* Master node */ {
            Lin_70_Isr_Tx( LIN_70_CH0 );
        } else
        { /* Slave node */
            Lin_70_RL78F2X_SlaveIsrTx( LIN_70_CH0 );
        }
    }
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_70_IsrRx                                                 */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Wrapper Reception interrupt process.                         */
/* Author      : --                                                           */
/* Note        : Change Interrupt OS Call                                     */
/******************************************************************************/
void Lin_70_Isr_RxCh0(void)
{
    uint8 chIndex;
    Std_ReturnType stdResult = E_NOT_OK;

    stdResult = Lin_searchChIndex( LIN_70_CH0, &chIndex );
    if ( stdResult == E_OK ) {
        /* Call reception interrupt handler if receive interrupt occurs at interrupt vector */
        if ( s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinNodeType == LIN_70_MASTER ) /* Master node */ {
            Lin_70_Isr_Rx( LIN_70_CH0 );
        } else
        { /* Slave node */
            Lin_70_RL78F2X_SlaveIsrRx( LIN_70_CH0 );
        }
    }
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_70_IsrError                                              */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Wrapper Error interrupt process.                             */
/* Author      : --                                                           */
/* Note        : Change Interrupt OS Call                                     */
/******************************************************************************/
void Lin_70_Isr_ErrCh0(void)
{
    uint8 chIndex;
    Std_ReturnType stdResult = E_NOT_OK;

    stdResult = Lin_searchChIndex( LIN_70_CH0, &chIndex );
    if ( stdResult == E_OK ) {
        /* Enable all error detections to get the Call of error interrupt handler if there is any error
           occurs while transmitting or receiving data or header */
        if ( s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinNodeType == LIN_70_MASTER ) /* Master node */ {
            Lin_70_Isr_Err( LIN_70_CH0 );
        } else
        { /* Slave node */
            Lin_70_RL78F2X_SlaveIsrError( LIN_70_CH0 );
        }
    }
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_70_Isr_WakeupCh0                                         */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Wrapper Wakeup interrupt process.                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Lin_70_Isr_WakeupCh0(void)
{
    /* Call wakeup interrupt handler if wakeup interrupt occurs at interrupt vector */
    ( void )Lin_CheckWakeup( LIN_70_CH0 );
}


/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_70_IsrTx                                                 */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Wrapper Transmit interrupt process.                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Lin_70_Isr_TxCh1(void)
{
    uint8 chIndex;
    Std_ReturnType stdResult = E_NOT_OK;

    stdResult = Lin_searchChIndex( LIN_70_CH1, &chIndex );
    if ( stdResult == E_OK ) {
        /* Call transmit interrupt handler if transmission interrupt occurs at interrupt vector */
        if ( s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinNodeType == LIN_70_MASTER ) /* Master node */ {
            Lin_70_Isr_Tx( LIN_70_CH1 );
        } else
        { /* Slave node */
            Lin_70_RL78F2X_SlaveIsrTx( LIN_70_CH1 );
        }
    }
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_70_IsrRx                                                 */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Wrapper Reception interrupt process.                         */
/* Author      : --                                                           */
/* Note        : Change Interrupt OS Call                                     */
/******************************************************************************/
void Lin_70_Isr_RxCh1(void)
{
    uint8 chIndex;
    Std_ReturnType stdResult = E_NOT_OK;

    stdResult = Lin_searchChIndex( LIN_70_CH1, &chIndex );
    if ( stdResult == E_OK ) {
        /* Call reception interrupt handler if receive interrupt occurs at interrupt vector */
        if ( s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinNodeType == LIN_70_MASTER ) /* Master node */ {
            Lin_70_Isr_Rx( LIN_70_CH1 );
        } else
        { /* Slave node */
            Lin_70_RL78F2X_SlaveIsrRx( LIN_70_CH1 );
        }
    }
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_70_Isr_ErrCh1                                            */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Wrapper Error interrupt process.                             */
/* Author      : --                                                           */
/* Note        : Change Interrupt OS Call                                     */
/******************************************************************************/
void Lin_70_Isr_ErrCh1(void)
{
    uint8 chIndex;
    Std_ReturnType stdResult = E_NOT_OK;

    stdResult = Lin_searchChIndex( LIN_70_CH1, &chIndex );
    if ( stdResult == E_OK ) {
        /* Enable all error detections to get the Call of error interrupt handler if there is any error
           occurs while transmitting or receiving data or header */
        if ( s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinNodeType == LIN_70_MASTER ) /* Master node */ {
            Lin_70_Isr_Err( LIN_70_CH1 );
        } else
        { /* Slave node */
            Lin_70_RL78F2X_SlaveIsrError( LIN_70_CH1 );
        }
    }
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_70_Isr_WakeupCh1                                         */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Wrapper Wakeup interrupt process.                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Lin_70_Isr_WakeupCh1(void)
{
    /* Call wakeup interrupt handler if wakeup interrupt occurs at interrupt vector */
    ( void )Lin_CheckWakeup( LIN_70_CH1 );
}

#define LIN_STOP_SEC_CODE_LOCAL
#include "Lin_MemMap.h"


/* EOF Lin_Irq.c ****************************************************/
