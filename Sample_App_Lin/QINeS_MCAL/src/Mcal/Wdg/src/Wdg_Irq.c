/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Wdg_Irq.c                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : Wdg Driver Layer IRQ implementation                          */
/*               The WDG is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of WDG Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Wdg.h"
#include "Wdg_Irq.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define WDG_70_VENDOR_ID_IRQ_C                  ( 70U )
#define WDG_70_MODULE_ID_IRQ_C                  (102U )

#define WDG_70_AR_RELEASE_MAJOR_VERSION_IRQ_C   ( 22U )
#define WDG_70_AR_RELEASE_MINOR_VERSION_IRQ_C   ( 11U )
#define WDG_70_AR_RELEASE_REVISION_VERSION_IRQ_C ( 00U )

#define WDG_70_SW_MAJOR_VERSION_IRQ_C           (  1U )
#define WDG_70_SW_MINOR_VERSION_IRQ_C           (  0U )
#define WDG_70_SW_PATCH_VERSION_IRQ_C           (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Wdg.h version check start */
#if ( WDG_70_VENDOR_ID_IRQ_C != WDG_VENDOR_ID )
  #error "VENDOR ID for Wdg_Irq.c and Wdg.h are different"
#endif

#if ( WDG_70_MODULE_ID_IRQ_C != WDG_MODULE_ID )
  #error "MODULE ID for Wdg_Irq.c and Wdg.h are different"
#endif

#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_IRQ_C != WDG_AR_RELEASE_MAJOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_IRQ_C != WDG_AR_RELEASE_MINOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_REVISION_VERSION_IRQ_C != WDG_AR_RELEASE_REVISION_VERSION ) )
  #error "AUTOSAR Version Numbers of Wdg_Irq.c and Wdg.h are different"
#endif

#if ( ( WDG_70_SW_MAJOR_VERSION_IRQ_C != WDG_SW_MAJOR_VERSION ) || \
      ( WDG_70_SW_MINOR_VERSION_IRQ_C != WDG_SW_MINOR_VERSION ) || \
      ( WDG_70_SW_PATCH_VERSION_IRQ_C != WDG_SW_PATCH_VERSION ) )
  #error "Software Version Numbers of Wdg_Irq.c and Wdg.h are different"
#endif

/* Wdg.h version check end */

/* Wdg_Irq.h version check start */
#if ( WDG_70_VENDOR_ID_IRQ_C != WDG_70_VENDOR_ID_IRQ_H )
  #error "VENDOR ID for Wdg_Irq.c and Wdg_Irq.h are different"
#endif

#if ( WDG_70_MODULE_ID_IRQ_C != WDG_70_MODULE_ID_IRQ_H )
  #error "MODULE ID for Wdg_Irq.c and Wdg_Irq.h are different"
#endif

#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_IRQ_C != WDG_70_AR_RELEASE_MAJOR_VERSION_IRQ_H ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_IRQ_C != WDG_70_AR_RELEASE_MINOR_VERSION_IRQ_H ) || \
      ( WDG_70_AR_RELEASE_REVISION_VERSION_IRQ_C != WDG_70_AR_RELEASE_REVISION_VERSION_IRQ_H ) )
  #error "AUTOSAR Version Numbers of Wdg_Irq.c and Wdg_Irq.h are different"
#endif

#if ( ( WDG_70_SW_MAJOR_VERSION_IRQ_C != WDG_70_SW_MAJOR_VERSION_IRQ_H ) || \
      ( WDG_70_SW_MINOR_VERSION_IRQ_C != WDG_70_SW_MINOR_VERSION_IRQ_H ) || \
      ( WDG_70_SW_PATCH_VERSION_IRQ_C != WDG_70_SW_PATCH_VERSION_IRQ_H ) )
  #error "Software Version Numbers of Wdg_Irq.c and Wdg_Irq.h are different"
#endif
/* Wdg_Irq.h version check end */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                         */
/*----------------------------------------------------------------------------*/
#define WDG_START_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"

/***************************************************************************/
/* ModuleID    : WDG_MODULE_ID (102)                                       */
/* ServiceID   : --                                                        */
/* Name        : Wdg_70_TimerIsr                                           */
/* Param       : void                                                      */
/* Return      : void                                                      */
/* Contents    : Watch dog hardware trigger timing by timer interrupt      */
/* Author      : --                                                           */
/* Note        : --                                                           */                                                        */
/***************************************************************************/
void Wdg_70_TimerIsr( void )
{
    Wdg_70_StatusValueType* lRefreshTimeValuePtr;
    /* Local variable to set/reset watchdog refresh signal */
    uint8 lSetRefreshSignal = ( uint8 )WDG_SET_REFRESH_NOT_OK;

    lRefreshTimeValuePtr = Wdg_70_GetRefreshTimeValue();
    if ( NULL_PTR == lRefreshTimeValuePtr ) {
        /* Do nothing */
    }
    else {
#if ( WDG_DISABLE_ALLOWED != FALSE )
        if ( WDGIF_OFF_MODE == lRefreshTimeValuePtr->WdgMode ) {
            /* Refresh internal wdg */
            lSetRefreshSignal = ( uint8 )WDG_SET_REFRESH_OK;
        }
        else
#endif /* #if ( WDG_DISABLE_ALLOWED != FALSE ) */
        {
            lRefreshTimeValuePtr->WdgTrigCycleCount++;
            if ( lRefreshTimeValuePtr->WdgTrigCycleCount >=
                 lRefreshTimeValuePtr->WdgRefreshCycle )
            {
                /* Check Trigger counter value */
                if ( lRefreshTimeValuePtr->WdgTrigCounter > 0U ) {
                    /* Refresh internal wdg */
                    lSetRefreshSignal = ( uint8 )WDG_SET_REFRESH_OK;
                }
                /* [SWS_Wdg_00135] Trigger counter is 0 and do nothing */
                lRefreshTimeValuePtr->WdgTrigCycleCount = 0U;
            }
            else {
                /* Refresh internal wdg */
                lSetRefreshSignal = ( uint8 )WDG_SET_REFRESH_OK;
            }

            /* Check Trigger counter value */
            if ( 1U < lRefreshTimeValuePtr->WdgTrigCounter ) {
                /* [SWS_Wdg_00134] Decrease trigger counter and trigger Hardware Wdg */
                lRefreshTimeValuePtr->WdgTrigCounter--;
            }
            else {
                lRefreshTimeValuePtr->WdgTrigCounter = 0U;
            }
        }
    }

    if ( ( uint8 )WDG_SET_REFRESH_OK == lSetRefreshSignal ) {
        ( void )Wdg_70_HW_Init();
    }
}

#define WDG_STOP_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"

/* EOF Wdg_Irq.c **************************************************************/