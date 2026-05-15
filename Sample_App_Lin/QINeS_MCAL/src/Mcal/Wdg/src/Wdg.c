/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Wdg.c                                                        */
/* Version     : v1.00.01                                                     */
/* Contents    : This specification specifies the functionality, API and      */
/*               configuration of the AUTOSAR Basic Software module WDG       */
/*               ( watchdog ) driver.                                         */
/*               The module provides service for initialization, changing the */
/*               operation mode and setting the trigger condition ( timeout ) */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of WDG Driver                                                */
/* R22-11                                                                     */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Wdg.h"
#if ( WDG_DEV_ERROR_DETECT != FALSE )
#include "Det.h"
#endif /* #if ( WDG_DEV_ERROR_DETECT != FALSE ) */
#include "SchM_Wdg.h"
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
#define WDG_70_VENDOR_ID_C                   ( 70U )
#define WDG_70_MODULE_ID_C                   ( 102U )
 
#define WDG_70_AR_RELEASE_MAJOR_VERSION_C    ( 22U )
#define WDG_70_AR_RELEASE_MINOR_VERSION_C    ( 11U )
#define WDG_70_AR_RELEASE_REVISION_VERSION_C ( 0U )
 
#define WDG_70_SW_MAJOR_VERSION_C            ( 1U )
#define WDG_70_SW_MINOR_VERSION_C            ( 0U )
#define WDG_70_SW_PATCH_VERSION_C            ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/* Wdg.h version check start */
 
#if ( WDG_70_VENDOR_ID_C != WDG_VENDOR_ID )
    #error "VENDOR ID for Wdg.c and Wdg.h are different"
#endif
 
#if ( WDG_70_MODULE_ID_C != WDG_MODULE_ID )
    #error "MODULE ID for Wdg.c and Wdg.h are different"
#endif
 
#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_C    != WDG_AR_RELEASE_MAJOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_C    != WDG_AR_RELEASE_MINOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_REVISION_VERSION_C != WDG_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Wdg.c and Wdg.h are different"
#endif
 
#if ( ( WDG_70_SW_MAJOR_VERSION_C != WDG_SW_MAJOR_VERSION ) || \
      ( WDG_70_SW_MINOR_VERSION_C != WDG_SW_MINOR_VERSION ) || \
      ( WDG_70_SW_PATCH_VERSION_C != WDG_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Wdg.c and Wdg.h are different"
#endif
 
/* Wdg.h version check end */
 
/* Det.h version check start */
#if ( WDG_DEV_ERROR_DETECT != FALSE )
#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Wdg.c and Det.h are different"
#endif
#endif  /* #if ( WDG_DEV_ERROR_DETECT != FALSE ) */
 
/* Det.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Wdg.h version check start */
 
#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_C != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_C != RTE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Wdg.c and SchM_Wdg.h are different"
#endif
 
/* SchM_Wdg.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/*----------------------------------------------------------------------------*/
/* Initial value of the variables                                             */
/*----------------------------------------------------------------------------*/
#define WDG_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Wdg_MemMap.h"
 
/* Memory area of wdg config data */
static const Wdg_SettingsConfigType *s_WdgConfigPtr = NULL_PTR;
 
/* Initialization set */
static Wdg_70_StatusValueType  s_Wdg_70_StatusValue = {
    0U,                             /* WdgTrgCycleCount Trigger refresh Count (Count) */
    WDG_70_DEFAULT_REFRESH_CYCLE,   /* Trigger refresh Cycle (Count) */
    0U,                             /* WdgTmrCounter Trigger Driver Timer Count (Count) */
    WDGIF_SLOW_MODE,                /* WdgMode WdgIf Mode */
    WDG_UNINIT                      /* WdgModState */
};
 
#define WDG_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Wdg_MemMap.h"
 
#define WDG_START_SEC_VAR_NO_INIT_LOCAL_32
#include "Wdg_MemMap.h"
 
static uint32 s_WdgCount; /* Variable to store Watchdog Internal counter */
 
#define WDG_STOP_SEC_VAR_NO_INIT_LOCAL_32
#include "Wdg_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
 
#define WDG_START_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
LOCAL_INLINE void wdg_modeSettings( const WdgIf_ModeType mode );
 
/******************************************************************************/
/* ModuleID    : WDG_MODULE_ID (102)                                          */
/* ServiceID   : WDG_INIT_ID (0x00)                                           */
/* Name        : Wdg_Init                                                     */
/* Param       : (in) ConfigPtr  Pointer to configuration set                 */
/* Return      : void                                                         */
/* Contents    : Initializes the module                                       */
/* Author      : --                                                           */
/* Note        : [SWS_Wdg_00106]                                              */
/*----------------------------------------------------------------------------*/
void Wdg_Init( const Wdg_ConfigType* ConfigPtr )
{
    /* Local lRetStat flag to check DET errors conditions */
    Std_ReturnType lRetStat = E_OK;
 
    /* Local lDemErrFlag flag to check DEM error conditions */
    Std_ReturnType lDemErrFlag = E_OK;
 
    WdgIf_ModeType lWdgMode; /* Local WdgIf Mode */
 
#if ( WDG_DEV_ERROR_DETECT != FALSE )
    Std_ReturnType lRetHwInit; /* Local lRetHwInit flag to check Hardware Initialization */
 
    /* Check If ConfigPtr is NULL or not */
    if ( NULL_PTR == ConfigPtr ) {
        /* [SWS_Wdg_00090] Report error code WDG_E_PARAM_CONFIG */
        ( void ) Det_ReportError( ( uint16 ) WDG_MODULE_ID, ( uint8 ) WDG_INSTANCE_ID,
                                  ( uint8 ) WDG_INIT_ID, ( uint8 ) WDG_E_PARAM_CONFIG );
        lRetStat = E_NOT_OK;
    } else
#endif  /* #if ( WDG_DEV_ERROR_DETECT != FALSE ) */
    /* If there is no DET error set wdgconfig pointer */
    {
        /* Keep a pointer to the config.  */
        s_WdgConfigPtr = &( ConfigPtr->WdgSettingsConfigSet[ WDG_70_INTERNAL_INDEX ] );
    }
 
    /* Check the return state value for E_OK */
    if ( E_OK == lRetStat ) {
        /* Get default Mode */
        lWdgMode = s_WdgConfigPtr->WdgDefaultMode;
 
        /* Set the wdg count with HW timer value */
        s_WdgCount = s_WdgConfigPtr->WdgIntCounter;
 
#if ( WDG_DISABLE_ALLOWED == FALSE )
        if ( WDGIF_OFF_MODE ==  lWdgMode ) {
#if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE )
            /* [SWS_Wdg_00179][SWS_Wdg_00025][SWS_Wdg_00182] */
            /* Report error code WDG_E_DISABLE_REJECTED */
            ( void ) Dem_SetEventStatus(
                                ( Dem_EventIdType ) WDG_E_DISABLE_REJECTED,
                                ( Dem_EventStatusType ) DEM_EVENT_STATUS_FAILED );
#endif /* #if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE ) */
            /* Set the flag as NOT OK if disabling of wdg is not allowed */
            lRetStat = E_NOT_OK;
        }
        else
#endif  /* #if ( WDG_DISABLE_ALLOWED == FALSE ) */
 
        /* If the WDG_DISABLE_ALLOWED is set as TRUE or there is no DEM error report */
        {
#if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE )
            ( void ) Dem_SetEventStatus(
                                ( Dem_EventIdType ) WDG_E_MODE_FAILED,
                                ( Dem_EventStatusType ) DEM_EVENT_STATUS_PASSED );
#endif /* #if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE ) */
            /* [SWS_Wdg_00001] Set default mode */
            if ( WDGIF_FAST_MODE == lWdgMode ) {
                /* [SWS_Wdg_00145] Set Timeout frame value for Fast mode */
                wdg_modeSettings( lWdgMode );
            } else if ( WDGIF_SLOW_MODE == lWdgMode ) {
                /* [SWS_Wdg_00145] Set Timeout frame value for slow mode */
                wdg_modeSettings( lWdgMode );
#if ( WDG_DISABLE_ALLOWED != FALSE )
            } else if ( WDGIF_OFF_MODE == lWdgMode ) {
                /* Trigger refresh Cycle count set 0 */
                s_Wdg_70_StatusValue.WdgRefreshCycle = 0U;
#endif /* if ( WDG_DISABLE_ALLOWED != FALSE ) */
            } else {
#if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE )
                /* [SWS_Wdg_00178][SWS_Wdg_00173][SWS_Wdg_00180] */
                /* Report Dem error for mode switching failed */
                ( void ) Dem_SetEventStatus(
                                ( Dem_EventIdType ) WDG_E_MODE_FAILED,
                                ( Dem_EventStatusType ) DEM_EVENT_STATUS_FAILED );
#endif /* #if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE ) */
                /* Set Dem error flag as NOT OK */
                lDemErrFlag = E_NOT_OK;
            }
        }
    }
 
    /* Check for the occurrence of DET and DEM errors */
    if ( ( E_OK == lRetStat ) && ( E_OK == lDemErrFlag ) ) {
#if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE )
        /* [SWS_Wdg_00178][SWS_Wdg_00181] */
        /* Report Dem error for mode switching not failed */
        ( void ) Dem_SetEventStatus(
                                ( Dem_EventIdType ) WDG_E_MODE_FAILED,
                                ( Dem_EventStatusType ) DEM_EVENT_STATUS_PASSED );
#endif /* #if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE ) */
 
        /* Trigger refresh Count */
        s_Wdg_70_StatusValue.WdgTrgCycleCount = 0U;
 
        /* Trigger Driver Timer Count (msec -> MicroSec) / Watchdog timer Internal counter */
        s_Wdg_70_StatusValue.WdgTmrCounter =
                           ( ( ( uint32 ) WDG_70_INITIAL_TIMEOUT * 1000U ) / s_WdgCount ) - WDG_ONE;
 
        /* Set Mode */
        s_Wdg_70_StatusValue.WdgMode = lWdgMode;
 
        /* [SWS_Wdg_00101] Initialize Watchdog Hardware */
#if ( WDG_DEV_ERROR_DETECT != FALSE )
        lRetHwInit = Wdg_70_HW_Init();
 
        /* Check Return Hardware Initialization */
        if ( E_NOT_OK == lRetHwInit ) {
            ( void ) Det_ReportError( ( uint16 ) WDG_MODULE_ID, ( uint8 ) WDG_INSTANCE_ID,
                                      ( uint8 ) WDG_INIT_ID, ( uint8 ) WDG_E_INIT_FAILED );
        }
#else
        ( void ) Wdg_70_HW_Init();
#endif /* #if ( WDG_DEV_ERROR_DETECT != FALSE ) */
 
        /* [SWS_Wdg_00019] Set Wdg module's state to WDG_IDLE */
        s_Wdg_70_StatusValue.WdgModState = WDG_IDLE;
    }
}
 
/******************************************************************************/
/* ModuleID    : WDG_MODULE_ID (102)                                          */
/* ServiceID   : WDG_SETMODE_ID (0x01)                                        */
/* Name        : Wdg_SetMode                                                  */
/* Param       : (in) Mode  One of the following statically configured modes: */
/*                          1. WDGIF_OFF_MODE                                 */
/*                          2. WDGIF_SLOW_MODE                                */
/*                          3. WDGIF_FAST_MODE                                */
/* Return      : E_OK:     The mode switch has been executed completely       */
/*               E_NOT_OK: Switching the Wdg module and the watchdog hardware */
/*                         into the requested mode is not possible            */
/* Contents    : Switches the watchdog into the mode "mode".                  */
/* Author      : --                                                           */
/* Note        : [SWS_Wdg_00107]                                              */
/*----------------------------------------------------------------------------*/
Std_ReturnType Wdg_SetMode( WdgIf_ModeType Mode )
{
    /* Local lRetStat flag to check DET and DEM errors conditions */
    Std_ReturnType lRetStat = E_OK;
 
    /* Check if the Wdg module state is IDLE or not */
    if ( WDG_IDLE != s_Wdg_70_StatusValue.WdgModState ) {
 
#if ( WDG_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Wdg_00017][SWS_Wdg_00035] If Wdg module is not in idle state */
        /* Report error code WDG_E_DRIVER_STATE */
        ( void ) Det_ReportError( ( uint16 ) WDG_MODULE_ID, ( uint8 ) WDG_INSTANCE_ID,
                                  ( uint8 ) WDG_SETMODE_ID, ( uint8 ) WDG_E_DRIVER_STATE );
#endif  /* #if ( WDG_DEV_ERROR_DETECT != FALSE ) */
 
        lRetStat = E_NOT_OK;
    } else if ( ( WDGIF_FAST_MODE != Mode ) &&
                ( WDGIF_SLOW_MODE != Mode ) && ( WDGIF_OFF_MODE != Mode ) ) {
 
#if ( WDG_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Wdg_00091] [SWS_Wdg_00092] If specified mode is not within the allowed boundaries */
        /* Report error code WDG_E_PARAM_MODE */
        ( void ) Det_ReportError( ( uint16 ) WDG_MODULE_ID, ( uint8 ) WDG_INSTANCE_ID,
                                  ( uint8 ) WDG_SETMODE_ID, ( uint8 ) WDG_E_PARAM_MODE );
#endif  /* #if ( WDG_DEV_ERROR_DETECT != FALSE ) */
 
        /* If switching of wdg module is not possible in the requested mode */
#if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE )
        /* Check for the DEM event id is configured */
        /* [SWS_Wdg_00178][SWS_Wdg_00016][SWS_Wdg_00180] Report error code WDG_E_MODE_FAILED */
        ( void ) Dem_SetEventStatus(
                                ( Dem_EventIdType ) WDG_E_MODE_FAILED,
                                ( Dem_EventStatusType ) DEM_EVENT_STATUS_FAILED );
#endif /* #if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE ) */
        lRetStat = E_NOT_OK;
    } else {
        /* If the mode passed is same as default  */
        if ( Mode == s_Wdg_70_StatusValue.WdgMode ) {
            /* [SWS_Wdg_00103] Wdg set mode is set successfully and return value should be E_OK */
            lRetStat = E_OK;
 
        /* If switching of wdg module is not possible in the requested mode */
#if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE )
            /* Check for the DEM event id is configured */
            /* [SWS_Wdg_00178][SWS_Wdg_00181] Setting watchdog mode not failed */
            ( void ) Dem_SetEventStatus(
                                ( Dem_EventIdType ) WDG_E_MODE_FAILED,
                                ( Dem_EventStatusType ) DEM_EVENT_STATUS_PASSED );
#endif /* #if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE ) */
        } else {
            /* [SWS_Wdg_00160] Wdg mode should be changed from the previous mode set */
            switch ( Mode ) {
            case WDGIF_FAST_MODE:
                /* [SWS_Wdg_00040] Disable all interrupt */
                SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_00();
                /* [SWS_Wdg_00018][SWS_Wdg_00052] Set Wdg module's state to WDG_BUSY */
                s_Wdg_70_StatusValue.WdgModState = WDG_BUSY;
                /* [SWS_Wdg_00145] Set Timeout frame value for Fast mode */
                wdg_modeSettings( Mode );
                /* [SWS_Wdg_00018][SWS_Wdg_00052] Set Wdg module's state to WDG_IDLE */
                s_Wdg_70_StatusValue.WdgModState = WDG_IDLE;
                /* [SWS_Wdg_00040] Enable all interrupt */
                SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00();
                break;
            case WDGIF_SLOW_MODE:
                /* [SWS_Wdg_00040] Disable all interrupt */
                SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_01();
                /* [SWS_Wdg_00018][SWS_Wdg_00052] Set Wdg module's state to WDG_BUSY */
                s_Wdg_70_StatusValue.WdgModState = WDG_BUSY;
                /* [SWS_Wdg_00145] Set Timeout frame value for Slow mode */
                wdg_modeSettings( Mode );
                /* [SWS_Wdg_00018][SWS_Wdg_00052] Set Wdg module's state to WDG_IDLE */
                s_Wdg_70_StatusValue.WdgModState = WDG_IDLE;
                /* [SWS_Wdg_00040] Enable all interrupt */
                SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_01();
                break;
            default:
                /* [SWS_Wdg_00031] To shutdown the Wdg, OFF mode should be used */
                /* The default case will be called for WDG OFF mode */
#if ( WDG_DISABLE_ALLOWED != FALSE )
                /* [SWS_Wdg_00040] Disable all interrupt */
                SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_02();
                /* [SWS_Wdg_00018][SWS_Wdg_00052] Set Wdg module's state to WDG_BUSY */
                s_Wdg_70_StatusValue.WdgModState = WDG_BUSY;
                /* [SWS_Wdg_00145] Set Timeout frame value for Off Mode */
                s_Wdg_70_StatusValue.WdgRefreshCycle = 0U;
                s_Wdg_70_StatusValue.WdgTrgCycleCount = 0U;
                /* [SWS_Wdg_00160] Wdg mode should be set to OFF mode */
                s_Wdg_70_StatusValue.WdgMode = Mode;
                /* [SWS_Wdg_00018][SWS_Wdg_00052] Set Wdg module's state to WDG_IDLE */
                s_Wdg_70_StatusValue.WdgModState = WDG_IDLE;
                /* [SWS_Wdg_00040] Enable all interrupt */
                SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_02();
#if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE )
                /* Check for the DEM event id is configured */
                /* [SWS_Wdg_00179][SWS_Wdg_00183] Disabling watchdog mode not failed */
                ( void ) Dem_SetEventStatus(
                  ( Dem_EventIdType ) WDG_E_MODE_FAILED,
                  ( Dem_EventStatusType ) DEM_EVENT_STATUS_PASSED );
#endif /* #if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE ) */
#else /* #if ( WDG_DISABLE_ALLOWED != FALSE ) */
                /* Disabling of the watchdog is not allowed */
#if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE )
                /* Check for the DEM event id is configured */
                /* [SWS_Wdg_00179][SWS_Wdg_00026][SWS_Wdg_00182] */
                /* Report error code WDG_E_DISABLE_REJECTED */
                ( void ) Dem_SetEventStatus(
                  ( Dem_EventIdType ) WDG_E_DISABLE_REJECTED,
                  ( Dem_EventStatusType ) DEM_EVENT_STATUS_FAILED );
#endif /* #if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE ) */
                /* Set the flag as NOT OK if disabling of wdg is not allowed */
                lRetStat = E_NOT_OK ;
#endif /* #if ( WDG_DISABLE_ALLOWED != FALSE ) */
                break;
            }
        }
    }
    return lRetStat;
}
 
/******************************************************************************/
/* ModuleID    : WDG_MODULE_ID (102)                                          */
/* ServiceID   : WDG_SETTRIGGERCONDITION_ID (0x03)                            */
/* Name        : Wdg_SetTriggerCondition                                      */
/* Param       : (in) timeout  Timeout value (milliseconds) for setting       */
/*                             the trigger counter.                           */
/* Return      : void                                                         */
/* Contents    : Sets the timeout value for the trigger counter.              */
/* Author      : --                                                           */
/* Note        : [SWS_Wdg_00155]                                              */
/*----------------------------------------------------------------------------*/
void Wdg_SetTriggerCondition( uint16 timeout )
{
#if ( WDG_DEV_ERROR_DETECT != FALSE )
    /* Check if the timeout parameter passed is in range */
    if ( WDG_70_MAX_TIMEOUT < timeout ) {
        /* [SWS_Wdg_00146] Report error code WDG_E_PARAM_TIMEOUT */
        ( void ) Det_ReportError ( ( uint16 ) WDG_MODULE_ID, ( uint8 ) WDG_INSTANCE_ID,
                              ( uint8 ) WDG_SETTRIGGERCONDITION_ID, ( uint8 ) WDG_E_PARAM_TIMEOUT );
    } else if ( WDG_IDLE != s_Wdg_70_StatusValue.WdgModState ) {
        /* Check if the Wdg module state is not idle */
        /* [SWS_Wdg_00035] Report error code WDG_E_DRIVER_STATE */
        ( void ) Det_ReportError( ( uint16 ) WDG_MODULE_ID, ( uint8 ) WDG_INSTANCE_ID,
                               ( uint8 ) WDG_SETTRIGGERCONDITION_ID, ( uint8 ) WDG_E_DRIVER_STATE );
    } else
#endif /* #if ( WDG_DEV_ERROR_DETECT != FALSE ) */
    /* Enter the condition if there is no DET */
    {
        /* [SWS_Wdg_00052] Set Wdg module's state to WDG_BUSY */
        s_Wdg_70_StatusValue.WdgModState = WDG_BUSY;
        /* Check if the timeout value passed is zero to shutdown the Wdg */
        if ( 0U == timeout ) {
            /* [SWS_Wdg_00140] Set Zero for immediate stop of watchdog triggering */
            s_Wdg_70_StatusValue.WdgTmrCounter = 0U;
        } else {
            /* [SWS_Wdg_00139][SWS_Wdg_00136][SWS_Wdg_00138] FAST/SLOW/OFF mode */
            s_Wdg_70_StatusValue.WdgTmrCounter =
                                         ( ( ( uint32 ) timeout  * 1000U ) / s_WdgCount ) - WDG_ONE;
        }
        /* [SWS_Wdg_00052] Set Wdg module's state to WDG_IDLE */
        s_Wdg_70_StatusValue.WdgModState = WDG_IDLE;
    }
}
 
/******************************************************************************/
/* ModuleID    : WDG_MODULE_ID (102)                                          */
/* ServiceID   : WDG_GETVERSIONINFO_ID (0x04)                                 */
/* Name        : Wdg_GetVersionInfo                                           */
/* Param       : (out) versioninfo  Pointer to where to store the version     */
/*                                  information of this module.               */
/* Return      : void                                                         */
/* Contents    : Returns the version information of this module.              */
/* Author      : --                                                           */
/* Note        : [SWS_Wdg_00109]                                              */
/*----------------------------------------------------------------------------*/
#if ( WDG_VERSION_INFO_API != FALSE )
void Wdg_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if ( WDG_DEV_ERROR_DETECT != FALSE )
    /* Check if the versioninfo pointer equals to NULL */
    if ( NULL_PTR == versioninfo ) {
        /* [SWS_Wdg_00174] Report error code Wdg_GetVersionInfo_ID */
        ( void ) Det_ReportError( ( uint16 ) WDG_MODULE_ID, ( uint8 ) WDG_INSTANCE_ID,
                                  ( uint8 ) WDG_GETVERSIONINFO_ID, ( uint8 ) WDG_E_PARAM_POINTER );
    }
    else
#endif /* #if ( WDG_DEV_ERROR_DETECT != FALSE ) */
    /* Enter the condition if there is no DET */
    {
        versioninfo->vendorID         = ( uint16 ) WDG_VENDOR_ID;       /* Vendor ID */
        versioninfo->moduleID         = ( uint16 ) WDG_MODULE_ID;       /* Module ID */
        versioninfo->sw_major_version = ( uint8 ) WDG_SW_MAJOR_VERSION; /* Software Major Version */
        versioninfo->sw_minor_version = ( uint8 ) WDG_SW_MINOR_VERSION; /* Software Minor Version */
        versioninfo->sw_patch_version = ( uint8 ) WDG_SW_PATCH_VERSION; /* Software Patch Version */
    }
}
#endif  /* #if ( WDG_VERSION_INFO_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : WDG_MODULE_ID (102)                                          */
/* ServiceID   : --                                                           */
/* Name        : Wdg_70_GetRefreshTimeValue                                   */
/* Param       : void                                                         */
/* Return      : Wdg_70_StatusValueType                                       */
/* Contents    : Get refresh Time value                                       */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Wdg_70_StatusValueType* Wdg_70_GetRefreshTimeValue( void )
{
    /* Return the current status value of Wdg driver */
    return &( s_Wdg_70_StatusValue );
}
 
/******************************************************************************/
/* ModuleID    : WDG_MODULE_ID (102)                                          */
/* ServiceID   : --                                                           */
/* Name        : wdg_modeSettings                                             */
/* Param       : (in) mode  One of the following statically configured modes: */
/*                          1. WDGIF_FAST_MODE                                */
/*                          2. WDGIF_SLOW_MODE                                */
/* Return      : void                                                         */
/* Contents    : Wdg fast and slow mode settings                              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
 
LOCAL_INLINE void wdg_modeSettings( const WdgIf_ModeType mode )
{
    uint32 lWdgTmval; /* Local variables to store Wdg timer value */
 
    s_Wdg_70_StatusValue.WdgTrgCycleCount = 0U;
 
    /* [SWS_Wdg_00160] Set mode as Passed in the function */
    s_Wdg_70_StatusValue.WdgMode = mode;
 
    /* Check for the mode passed to set the trigger RefreshCycle value */
    if ( WDGIF_FAST_MODE == mode ) {
        /* [SWS_Wdg_00145] Calculate refresh cycle count for Fast Mode settings */
        lWdgTmval = ( s_WdgConfigPtr->WdgSettingsFast )->WdgTimerValue;
 
    } else {
        /* [SWS_Wdg_00145] Calculate refresh cycle count for Slow Mode settings */
        lWdgTmval = ( s_WdgConfigPtr->WdgSettingsSlow )->WdgTimerValue;
    }
 
    /* Set refresh cycle count Value */
    s_Wdg_70_StatusValue.WdgRefreshCycle = ( lWdgTmval * 1000U ) / s_WdgCount;
}
 
#define WDG_STOP_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"
 
/* EOF Wdg.c ******************************************************************/