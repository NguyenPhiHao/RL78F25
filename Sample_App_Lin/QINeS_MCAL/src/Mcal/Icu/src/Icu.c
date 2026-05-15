/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu.c                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    : This specification specifies the functionality, API and      */
/*               configuration of the AUTOSAR Basic Software module ICU       */
/*               driver.                                                      */
/*               The ICU driver is a module using the input capture unit(ICU) */
/*               for demodulation of a PWM signal, counting pulses, measuring */
/*               of frequency and duty cycle, generating simple interrupts    */
/*               and also wakeup interrupts.                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ICU Driver                                                */
/* R22-11                                                                     */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Icu.h"
#include "SchM_Icu.h"
#include "Det.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ICU_70_VENDOR_ID_C                      (70U)
#define ICU_70_MODULE_ID_C                      (122U)
 
#define ICU_70_AR_RELEASE_MAJOR_VERSION_C       (22U)
#define ICU_70_AR_RELEASE_MINOR_VERSION_C       (11U)
#define ICU_70_AR_RELEASE_REVISION_VERSION_C    (0U)
 
#define ICU_70_SW_MAJOR_VERSION_C               (1U)
#define ICU_70_SW_MINOR_VERSION_C               (0U)
#define ICU_70_SW_PATCH_VERSION_C               (0U)
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Icu.h version check start */
 
#if ( ICU_70_VENDOR_ID_C != ICU_VENDOR_ID )
    #error "VENDOR ID for Icu.c and Icu.h are different"
#endif
 
#if ( ICU_70_MODULE_ID_C != ICU_MODULE_ID )
    #error "MODULE ID for Icu.c and Icu.h are different"
#endif
 
#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_C    != ICU_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_C    != ICU_AR_RELEASE_MINOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Icu.c and Icu.h are different"
#endif
 
#if ( ( ICU_70_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION ) || \
      ( ICU_70_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION ) || \
      ( ICU_70_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Icu.c and Icu.h are different"
#endif
 
/* Icu.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Icu.h version check start */
 
#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_C != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_C != RTE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Icu.c and SchM_Icu.h are different"
#endif
 
/* SchM_Icu.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Det.h version check start */
#if ( ICU_DEV_ERROR_DETECT != FALSE )
#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Icu.c and Det.h are different"
#endif
#endif
 
/* Det.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#define ICU_START_SEC_VAR_INIT_LOCAL_8
#include "Icu_MemMap.h"
 
#if ( ICU_DEV_ERROR_DETECT != FALSE )
static Icu_70_ModuleStateType      s_Icu_ModuleState   = ICU_STATE_UNINITIALIZED;
#endif  /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
 
static Icu_ModeType             s_Icu_Mode          = ICU_MODE_NORMAL;
 
#define ICU_STOP_SEC_VAR_INIT_LOCAL_8
#include "Icu_MemMap.h"
 
#define ICU_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Icu_MemMap.h"
 
static const Icu_ConfigType*    s_Icu_ConfigPtr     = NULL_PTR;
static Icu_70_ChannelInfoType   s_ChInfo[ICU_MAX_CHANNEL] = { 0 };
 
#define ICU_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Icu_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
static void icu_70_preInit( const Icu_IcuChannelType* chPtr );
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define ICU_START_SEC_CODE_LOCAL
#include "Icu_MemMap.h"
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : icu_70_preInit                                               */
/* Param       : (in) chInfo Pointer to channel info table                    */
/* Return      : void                                                         */
/* Contents    : referece pointer to icu channel infomation table             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void icu_70_preInit( const Icu_IcuChannelType* chPtr )
{
    Icu_70_ChannelInfoType*     chInfoPtr;
 
    chInfoPtr                   = &( s_ChInfo[ chPtr->IcuChannelId ] );
 
    chInfoPtr->icuCh            = chPtr->IcuChannelId;
    /* input state of an ICU channel */
    chInfoPtr->state            = ICU_IDLE;                        /* [SWS_Icu_00040] */
    /* configuration pointer of channel */
    chInfoPtr->conf_chInfo      = chPtr;
    /* Activation Type */
    chInfoPtr->actType          = chPtr->IcuDefaultStartEdge;      /* [SWS_Icu_00011] */
    /* Measurement mode */
    chInfoPtr->msrMode          = chPtr->IcuMeasurementMode;
    /* Measurement Property */
    chInfoPtr->msrProp          = chPtr->IcuSignalMeasurement->IcuSignalMeasurementProperty;
    /* Notification Switch */
    chInfoPtr->notifSw          = FALSE;
    /* Notification Interval for Timestamp */
    chInfoPtr->notifIntv        = 0U;
    /* Notification Count for Timestamp */
    chInfoPtr->notifCnt         = 0U;
    /* captured buffer index */
    chInfoPtr->bufIdx           = 0U;
    /* captured buffer size */
    chInfoPtr->bufSize          = 0U;
    /* captured buffer type */
    chInfoPtr->bufType          = chPtr->IcuTimestampMeasurement->IcuTimestampMeasurementProperty;
    /* Time Stamp captured buffer */
    chInfoPtr->buff             = NULL_PTR;
    /* Edge Count */
    chInfoPtr->edgeCount        = 0U;
    /* duty cycle data */
    chInfoPtr->duty.ActiveTime  = 0U;
    /* duty cycle data                        */
    chInfoPtr->duty.PeriodTime  = 0U;
    /* elapsed time */
    chInfoPtr->elapsedTime      = 0U;
    /* Wakeup source */
    chInfoPtr->wuSrc            = chPtr->IcuWakeup->IcuChannelWakeupInfo;
    /* Wakeup Capability */
    chInfoPtr->wuCap            = chPtr->IcuWakeupCapability;       /* [SWS_Icu_00012][SWS_Icu_00261] */
    /* Wakeup Enable/Disable */
    chInfoPtr->wuEbl            = FALSE;
    /* Callback for TS notification   */
    chInfoPtr->cbTS             = chPtr->IcuTimestampMeasurement->IcuTimestampNotification;
    /* Callback for Edge notification */
    chInfoPtr->cbEdge           = chPtr->IcuSignalEdgeDetection->IcuSignalNotification;
    /* Reset irqState                 */
    chInfoPtr->irqState         = ICU_70_MEAS_NONE;
    /* Running check of Channel       */
    chInfoPtr->chRunning        = FALSE;
}
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x00                                                         */
/* Name        : Icu_Init                                                     */
/* Param       : (in) ConfigPtr Pointer to a selected configuration structure */
/* Return      : void                                                         */
/* Contents    : This function initializes.                                   */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00191                                                */
/*----------------------------------------------------------------------------*/
void Icu_Init( const Icu_ConfigType* ConfigPtr )
{
    const Icu_ConfigSetType*          cfgPtr;
    uint16_least                      lcount;
    const Icu_IcuChannelType*         chPtr;
 
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00220][SWS_Icu_00054][SWS_Icu_00382] */
    if ( ICU_STATE_INITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_INIT_ID, ( uint8 )ICU_E_ALREADY_INITIALIZED );
    /* [SWS_Icu_00382] */
    } else if ( NULL_PTR == ConfigPtr ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_INIT_ID, ( uint8 )ICU_E_INIT_FAILED );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Icu_00298] *//* Initialize Icu Driver */
        /* State variable initialization */
        s_Icu_ConfigPtr = ConfigPtr;
        /* Set configuration pointer */
        cfgPtr = &( ConfigPtr->IcuConfigSet );
        /* Set the configuration data to the Icu channel information table */
        for ( lcount=0U; lcount<s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel; lcount++ ) {
            chPtr = ( const Icu_IcuChannelType* ) & ( cfgPtr->IcuChannel[ lcount ] );
            /* [SWS_Icu_00061][SWS_Icu_00121][SWS_Icu_00040][SWS_Icu_00054] */
            icu_70_preInit( chPtr );
            /* [SWS_Icu_00006][SWS_Icu_00051][SWS_Icu_00054] *//* Setup timer   */
            Icu_70_HW_Init( chPtr->IcuSetConfPtr, s_ChInfo[ chPtr->IcuChannelId ].actType );
        }
        s_Icu_Mode          = ICU_MODE_NORMAL;                  /* Icu work mode *//* [SWS_Icu_00060] */
#if ( ICU_DEV_ERROR_DETECT != FALSE )
        s_Icu_ModuleState = ICU_STATE_INITIALIZED;
#endif  /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    }
}
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x01                                                         */
/* Name        : Icu_DeInit                                                   */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : This function de-initializes the ICU module.                 */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00193                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_DE_INIT_API  != FALSE )    /* [SWS_Icu_00301] */
void Icu_DeInit( void )
{
    uint16_least                lcount;
    Icu_70_ChannelInfoType*     chInfoPtr;
 
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00385] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_DEINIT_ID, ( uint8 )ICU_E_UNINIT );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Icu_00036][SWS_Icu_00037] */
        /* Initialize the Icu channel infomation table */
        for ( lcount=0U; lcount<s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel; lcount++ ) {
            chInfoPtr                   = &( s_ChInfo[ lcount ] );
            Icu_70_HW_DeInit( chInfoPtr->conf_chInfo->IcuSetConfPtr );    /* Specified timer reset macro         */
            chInfoPtr->state            = ICU_IDLE;                       /* input state of an ICU channel       */
            chInfoPtr->actType          = ICU_70_NO_EDGE;                 /* Notification Switch                 */
            chInfoPtr->msrMode          = ICU_MODE_SIGNAL_EDGE_DETECT;    /* Measurement mode                    */
            chInfoPtr->msrProp          = ICU_LOW_TIME;                   /* Measurement Property                */
            chInfoPtr->notifSw          = FALSE;                          /* Notification Switch                 */
            chInfoPtr->notifIntv        = 0U;                             /* Notification Interval for Timestamp */
            chInfoPtr->notifCnt         = 0U;                             /* Notification Count for Timestamp    */
            chInfoPtr->bufType          = ICU_LINEAR_BUFFER;              /* captured buffer type                */
            chInfoPtr->bufIdx           = 0U;                             /* captured buffer index               */
            chInfoPtr->bufSize          = 0U;                             /* captured buffer size                */
            chInfoPtr->buff             = NULL_PTR;                       /* Time Stamp captured buffer          */
            chInfoPtr->edgeCount        = 0U;                             /* Edge Count                          */
            chInfoPtr->duty.ActiveTime  = 0U;                             /* duty cycle data                     */
            chInfoPtr->duty.PeriodTime  = 0U;                             /* duty cycle data                     */
            chInfoPtr->elapsedTime      = 0U;                             /* elapsed time                        */
            chInfoPtr->wuSrc            = 0x00000000UL;                   /* Wakeup source                       */
            chInfoPtr->wuCap            = FALSE;                          /* Wakeup Capability                   */
            chInfoPtr->wuEbl            = FALSE;                          /* Wakeup Enable/Disable               */
            chInfoPtr->cbTS             = NULL_PTR;                       /* Callback for TS notification        */
            chInfoPtr->cbEdge           = NULL_PTR;                       /* Callback for Edge notification      */
            chInfoPtr->irqState         = ICU_70_MEAS_NONE;               /* Reset irqState                      */
        }
        s_Icu_Mode                      = ICU_MODE_NORMAL;              /* Icu mode                             */
        s_Icu_ConfigPtr                 = NULL_PTR;                     /* clear pointer to configure data      */
#if ( ICU_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Icu_00221] */
        s_Icu_ModuleState               = ICU_STATE_UNINITIALIZED;      /* Set uninitialized status to IcuState */
#endif  /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    }
}
#endif      /* #if ( ICU_DE_INIT_API  != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x02                                                         */
/* Name        : Icu_SetMode                                                  */
/* Param       : (in) Mode operation mode of Icu                              */
/* Return      : void                                                         */
/* Contents    : This function sets the ICU mode.                             */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00194                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_SET_MODE_API != FALSE ) /* [SWS_Icu_00303] */
void Icu_SetMode( Icu_ModeType Mode )
{
    Icu_70_ChannelInfoType*     chInfoPtr;
    uint16_least    lcount;
 
    /* [SWS_Icu_00095] */
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    bool_t          runChkErr = FALSE;
    /* [SWS_Icu_00382][SWS_Icu_00386] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_SETMODE_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00125][SWS_Icu_00382] */
    } else if ( ( ICU_MODE_SLEEP != Mode ) && ( ICU_MODE_NORMAL != Mode ) ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_SETMODE_ID, ( uint8 )ICU_E_PARAM_MODE );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        for ( lcount=0U; lcount<s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel; lcount++ ) {
            chInfoPtr = &s_ChInfo[ lcount ];
            /* When channel wakeup is not enabled  */
            if ( FALSE == chInfoPtr->wuEbl ) {
                /* [SWS_Icu_00012][SWS_Icu_00260][SWS_Icu_00261] */
                /* When go to SLEEP mode, disable interrupt and stop all channel that is not enabled for wakeup */
                if ( ICU_MODE_SLEEP == Mode ) {
                    Icu_70_HW_DisableNonWakeupChannel( chInfoPtr->conf_chInfo->IcuSetConfPtr );
                    chInfoPtr->chRunning = FALSE;
                }
                else { /* Set mode to NORMAL */
                    /*  [SWS_Icu_00011][SWS_Icu_00259] */
                    Icu_70_HW_EnableNonWakeupChannel( chInfoPtr->conf_chInfo->IcuSetConfPtr,
                                                      chInfoPtr->actType );
                }
            }
        }
#if ( ICU_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Icu_00382] */
        /* Running check  */
        for ( lcount=0U; lcount<s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel; lcount++ ) {
            /* All non wakeup channel is stopped, report error if there is any wakeup channel running  */
            if ( FALSE != s_ChInfo[ lcount ].chRunning ) {
                ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                         ( uint8 )ICU_70_SETMODE_ID,
                                         ( uint8 )ICU_E_BUSY_OPERATION );
                runChkErr = TRUE;
                break;
            }
        }
        /* When all channels are not running */
        if ( FALSE == runChkErr )
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
        {
            s_Icu_Mode = Mode;       /* [SWS_Icu_00008] */
        }
    }
}
#endif      /* #if ( ICU_SET_MODE_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x03                                                         */
/* Name        : Icu_DisableWakeup                                            */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : This function disables the wakeup capability of a single     */
/*               ICU channel.                                                 */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00195                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_DISABLE_WAKEUP_API != FALSE )    /* [SWS_Icu_00306] */
void Icu_DisableWakeup( Icu_ChannelType Channel )
{
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00387] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_DISABLEWAKEUP_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00024][SWS_Icu_00059][SWS_Icu_00305] */
    } else if ( ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel )
             || ( TRUE != s_ChInfo[ Channel ].wuCap ) ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_DISABLEWAKEUP_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        s_ChInfo[ Channel ].wuEbl = FALSE;    /* [SWS_Icu_00013] */
    }
}
#endif      /* #if ( ICU_DISABLE_WAKEUP_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x04                                                         */
/* Name        : Icu_EnableWakeup                                             */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : This function (re-)enables the wakeup capability of the      */
/*               given ICU channel.                                           */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00196                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_ENABLE_WAKEUP_API != FALSE )    /* [SWS_Icu_00308] */
void Icu_EnableWakeup( Icu_ChannelType Channel )
{
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00388] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_ENABLEWAKEUP_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00155][SWS_Icu_00156] */
    } else if ( ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) ||
                ( TRUE != s_ChInfo[ Channel ].wuCap ) ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_ENABLEWAKEUP_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        s_ChInfo[ Channel ].wuEbl = TRUE;    /* [SWS_Icu_00014][SWS_Icu_00012][SWS_Icu_00261] */
    }
}
#endif      /* #if ( ICU_ENABLE_WAKEUP_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x15                                                         */
/* Name        : Icu_CheckWakeup                                              */
/* Param       : (in) WakeupSource Information on wakeup source to be checked */
/* Return      : void                                                         */
/* Contents    : Checks if a wakeup capable ICU channel is the source for a   */
/*               wakeup event and calls the ECU state manager service         */
/*               EcnM_SetWakeupEvent in case of a valid ICU channel           */
/*               wakeup event.                                                */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00358                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_WAKEUP_FUNCTIONALITY_API != FALSE )    /* [SWS_Icu_00362] */
void Icu_CheckWakeup( EcuM_WakeupSourceType WakeupSource )
{
    uint16_least    lcount;
 
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00363][SWS_Icu_00382] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_CHECKWAKEUP_ID, ( uint8 )ICU_E_UNINIT );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        for ( lcount=0U; lcount<s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel; lcount++ ) {
            /* [SWS_Icu_00360] */
            if ( ( TRUE == s_ChInfo[ lcount ].wuEbl )
              && ( s_ChInfo[ lcount ].wuSrc == WakeupSource ) ) {
                /* [SWS_Icu_00359] */
                EcuM_SetWakeupEvent( WakeupSource );
                break;
            }
        }
    }
}
#endif      /* #if ( ICU_WAKEUP_FUNCTIONALITY_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x05                                                         */
/* Name        : Icu_SetActivationCondition                                   */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/*               (in) Activation Type of activation                           */
/* Return      : void                                                         */
/* Contents    :                                                              */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00197                                                */
/*----------------------------------------------------------------------------*/
void Icu_SetActivationCondition( Icu_ChannelType Channel, Icu_ActivationType Activation )
{
    Icu_70_ChannelInfoType* chInfoPtr;
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    Icu_MeasurementModeType measurementMode;    /* Measurement Mode */
    measurementMode = s_ChInfo[ Channel ].msrMode;
 
    /* [SWS_Icu_00382] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_SETACTIVATIONCONDITION_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00159] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_SETACTIVATIONCONDITION_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    } else if ( ( ICU_MODE_SIGNAL_EDGE_DETECT != measurementMode )
             && ( ICU_MODE_TIMESTAMP          != measurementMode )
             && ( ICU_MODE_EDGE_COUNTER       != measurementMode ) ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_SETACTIVATIONCONDITION_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    } else {
        /* [SWS_Icu_00043][SWS_Icu_00090][SWS_Icu_00382] */
        if ( ( ICU_RISING_EDGE > Activation )
          || ( ICU_BOTH_EDGES  < Activation ) ) {
            ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                     ( uint8 )ICU_70_SETACTIVATIONCONDITION_ID,
                                     ( uint8 )ICU_E_PARAM_ACTIVATION );
        } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
        {
            chInfoPtr = &( s_ChInfo[ Channel ] );
            /* [SWS_Icu_00090][SWS_Icu_00011] */
            if ( FALSE != chInfoPtr->chRunning ) {
                /* Call HW function when channel is running */
                Icu_70_HW_SetActivationCondition( chInfoPtr->conf_chInfo->IcuSetConfPtr,
                                                  Activation );
            }
            /* Set Activation to work area. */
            chInfoPtr->actType = Activation;
            chInfoPtr->state   = ICU_IDLE;    /* [SWS_Icu_00139] */
        }
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    }
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
}
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x06                                                         */
/* Name        : Icu_DisableNotification                                      */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : This function disables the notification of a channel.        */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00198                                                */
/*----------------------------------------------------------------------------*/
void Icu_DisableNotification( Icu_ChannelType Channel )
{
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00389] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_DISABLENOTIFICATION_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00160] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_DISABLENOTIFICATION_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        s_ChInfo[ Channel ].notifSw = FALSE;    /* [SWS_Icu_00009][SWS_Icu_00259] */
    }
}
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x07                                                         */
/* Name        : Icu_EnableNotification                                       */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : This function enables the notification on the given channel. */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00199                                                */
/*----------------------------------------------------------------------------*/
void Icu_EnableNotification( Icu_ChannelType Channel )
{
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00390] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_ENABLENOTIFICATION_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00161] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_ENABLENOTIFICATION_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        s_ChInfo[ Channel ].notifSw = TRUE;    /* [SWS_Icu_00010][SWS_Icu_00259] */
    }
}
 
 
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x08                                                         */
/* Name        : Icu_GetInputState                                            */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : Icu_InputStateType                                           */
/* Contents    : This function returns the status of the ICU input.           */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00200                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_GET_INPUT_STATE_API != FALSE )    /* [SWS_Icu_00315] */
Icu_InputStateType Icu_GetInputState( Icu_ChannelType Channel )
{
    Icu_InputStateType          inputState = ICU_IDLE;    /* [SWS_Icu_00049] */
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    Icu_MeasurementModeType     measurementMode;             /* Measurement Mode */
 
    /* [SWS_Icu_00162][SWS_Icu_00391] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETINPUTSTATE_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00382] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETINPUTSTATE_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    } else {
        measurementMode = s_ChInfo[ Channel ].msrMode;
        /* [SWS_Icu_00030] */
        if ( ( ICU_MODE_SIGNAL_EDGE_DETECT != measurementMode )
          && ( ICU_MODE_SIGNAL_MEASUREMENT != measurementMode ) ) {
            ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                     ( uint8 )ICU_70_GETINPUTSTATE_ID,
                                     ( uint8 )ICU_E_PARAM_CHANNEL );
        } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
        {
            /* [SWS_Icu_00313][SWS_Icu_00031] */
            inputState                   = s_ChInfo[ Channel ].state;
            /* [SWS_Icu_00032] */
            s_ChInfo[ Channel ].state = ICU_IDLE;
        }
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    }
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    return inputState;
}
#endif      /* #if ( ICU_GET_INPUT_STATE_API != FALSE) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x09                                                         */
/* Name        : Icu_StartTimestamp                                           */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/*             : (out) BufferPtr : pointer for output buffer                  */
/*             : (in) Buffersize : Size of the external buffer                */
/*             : (in) NotifyInterval : Notification interval                  */
/*             :                       (number of events).                    */
/* Return      : void                                                         */
/* Contents    : This function starts the measurement of signals.             */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00201                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_TIMESTAMP_API != FALSE )    /* [SWS_Icu_00321] */
void Icu_StartTimestamp( Icu_ChannelType Channel, Icu_ValueType* BufferPtr,
                         uint16 BufferSize,  uint16 NotifyInterval )
{
    Icu_70_ChannelInfoType*     chInfoPtr;
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00392] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STARTTIMESTAMP_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00163] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STARTTIMESTAMP_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    /* [SWS_Icu_00066] */
    } else if ( ICU_MODE_TIMESTAMP != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STARTTIMESTAMP_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    /* [SWS_Icu_00108][SWS_Icu_00382] */
    } else if ( 0U == BufferSize ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STARTTIMESTAMP_ID,
                                 ( uint8 )ICU_E_PARAM_BUFFER_SIZE );
    /* [SWS_Icu_00382] */
    } else if ( NULL_PTR == BufferPtr ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STARTTIMESTAMP_ID, ( uint8 )ICU_E_PARAM_POINTER );
    /* [SWS_Icu_00354][SWS_Icu_00382] */
    } else if (( NULL_PTR != s_ChInfo[ Channel ].cbTS ) && ( 1U >  NotifyInterval )) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STARTTIMESTAMP_ID,
                                 ( uint8 )ICU_E_PARAM_NOTIFY_INTERVAL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        chInfoPtr = &( s_ChInfo[ Channel ] );
        chInfoPtr->notifIntv   = NotifyInterval;        /* Notification Interval for Timestamp */
        chInfoPtr->notifCnt    = 0U;                    /* Notification Count for Timestamp    */
        chInfoPtr->bufIdx      = 0U;                    /* Set buffer index 0                  */
        chInfoPtr->bufSize     = BufferSize;            /* Set buffer size    [SWS_Icu_00108]  */
        chInfoPtr->buff        = BufferPtr;             /* Set buffer pointer                  */
        chInfoPtr->elapsedTime = 0U;                    /* Set elapesedTime 0 */
        /* [SWS_Icu_00317][SWS_Icu_00063] */
        Icu_70_HW_StartTimestamp( chInfoPtr->conf_chInfo->IcuSetConfPtr,
                                  s_ChInfo[ Channel ].actType );
        /* Manage the state of the channel with bits */
        chInfoPtr->chRunning   = TRUE;
    }
}
#endif      /* #if ( ICU_TIMESTAMP_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x0a                                                         */
/* Name        : Icu_StopTimestamp                                            */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : This function starts the measurement of signals.             */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00202                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_TIMESTAMP_API != FALSE )    /* [SWS_Icu_00323] */
void Icu_StopTimestamp( Icu_ChannelType Channel )
{
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00393] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STOPTIMESTAMP_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00164] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STOPTIMESTAMP_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    /* [SWS_Icu_00165] */
    } else if ( ICU_MODE_TIMESTAMP != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STOPTIMESTAMP_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Icu_00166][SWS_Icu_91004] */
        if ( TRUE != s_ChInfo[ Channel ].chRunning ) {
            ( void )Det_ReportRuntimeError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                            ( uint8 )ICU_70_STOPTIMESTAMP_ID,
                                            ( uint8 )ICU_E_NOT_STARTED );
        }
        else {
            /* [SWS_Icu_00067] */
            Icu_70_HW_StopTimestamp( s_ChInfo[ Channel ].conf_chInfo->IcuSetConfPtr );
            /* Manage the state of the channel with bits */
            s_ChInfo[ Channel ].chRunning = FALSE;
        }
    }
}
#endif      /* #if ( ICU_TIMESTAMP_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x0b                                                         */
/* Name        : Icu_GetTimestampIndex                                        */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : Icu_IndexType next index of time stamp buffer                */
/* Contents    : Reads the timestamp index of the given channel.              */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00203                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_TIMESTAMP_API != FALSE )    /* [SWS_Icu_00325] */
Icu_IndexType Icu_GetTimestampIndex( Icu_ChannelType Channel )
{
    Icu_IndexType idx = 0U;                 /* [SWS_Icu_00107] */
 
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00394] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETTIMESTAMPINDEX_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00169] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETTIMESTAMPINDEX_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    /* [SWS_Icu_00170] */
    } else if ( ICU_MODE_TIMESTAMP != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETTIMESTAMPINDEX_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        /* get current index of capture buffer */
        idx = s_ChInfo[ Channel ].bufIdx;    /* [SWS_Icu_00071] */
    }
    return idx;
}
#endif      /*  #if ( ICU_TIMESTAMP_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x0c                                                         */
/* Name        : Icu_ResetEdgeCount                                           */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : Resets the value of the counted edges to zero.               */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00204                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_EDGE_COUNT_API != FALSE )    /* [SWS_Icu_00327] */
void Icu_ResetEdgeCount( Icu_ChannelType Channel )
{
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00395] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_RESETEDGECOUNT_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00171] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_RESETEDGECOUNT_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    /* [SWS_Icu_00171] */
    } else if ( ICU_MODE_EDGE_COUNTER != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_RESETEDGECOUNT_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        /* clear edge count of specified channel */
        s_ChInfo[ Channel ].edgeCount = 0U;   /* [SWS_Icu_00072] */
    }
}
#endif      /* #if ( ICU_EDGE_COUNT_API != FALSE )   */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x0d                                                         */
/* Name        : Icu_EnableEdgeCount                                          */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : Enables the counting of edges of the given channel           */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00205                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_EDGE_COUNT_API != FALSE )    /* [SWS_Icu_00329] */
void Icu_EnableEdgeCount( Icu_ChannelType Channel )
{
    Icu_70_ChannelInfoType*     chInfoPtr;
 
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00396] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_ENABLEEDGECOUNT_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00172] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_ENABLEEDGECOUNT_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    /* [SWS_Icu_00074] */
    } else if ( ICU_MODE_EDGE_COUNTER != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_ENABLEEDGECOUNT_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        chInfoPtr              = &( s_ChInfo[ Channel ] );
        /* [SWS_Icu_00078] */
        Icu_70_HW_EnableEdgeCount( chInfoPtr->conf_chInfo->IcuSetConfPtr, chInfoPtr->actType );
        /* [SWS_Icu_00073] Manage the state of the channel with bits */
        chInfoPtr->chRunning   = TRUE;
    }
}
#endif      /* #if ( ICU_EDGE_COUNT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x16                                                         */
/* Name        : Icu_EnableEdgeDetection                                      */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : Enables/Reenables the detection of edges of the given channel*/
/* Author      : --                                                           */
/* Note        : SWS_Icu_00364                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_EDGE_DETECT_API != FALSE )    /* [SWS_Icu_00370] */
void Icu_EnableEdgeDetection( Icu_ChannelType Channel )
{
    Icu_70_ChannelInfoType*  chInfoPtr;
 
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00397] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_ENABLEEDGEDETECTION_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00371] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_ENABLEEDGEDETECTION_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    /* [SWS_Icu_00367] */
    } else if ( ICU_MODE_SIGNAL_EDGE_DETECT != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_ENABLEEDGEDETECTION_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        chInfoPtr = &( s_ChInfo[ Channel ] );
        /* [SWS_Icu_00365][SWS_Icu_00366] */
        Icu_70_HW_EnableEdgeDetection( chInfoPtr->conf_chInfo->IcuSetConfPtr, chInfoPtr->actType );
 
        chInfoPtr->chRunning = TRUE;
    }
}
#endif /* #if ( ICU_EDGE_DETECT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x17                                                         */
/* Name        : Icu_DisableEdgeDetection                                     */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : Disables the detection of edges of the given channel.        */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00377                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_EDGE_DETECT_API != FALSE )    /* [SWS_Icu_00375] */
void Icu_DisableEdgeDetection( Icu_ChannelType Channel )
{
    Icu_70_ChannelInfoType*  chInfoPtr;
 
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00398] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_DISABLEEDGEDETECTION_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00376] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_DISABLEEDGEDETECTION_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    /* [SWS_Icu_00376] */
    } else if ( ICU_MODE_SIGNAL_EDGE_DETECT != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_DISABLEEDGEDETECTION_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        chInfoPtr = &( s_ChInfo[ Channel ] );
        /* [SWS_Icu_00372] */
        Icu_70_HW_DisableEdgeDetection( chInfoPtr->conf_chInfo->IcuSetConfPtr );
 
        chInfoPtr->chRunning = FALSE;
    }
}
#endif /* #if ( ICU_EDGE_DETECT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x0e                                                         */
/* Name        : Icu_DisableEdgeCount                                         */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : Disables the counting of edges of the given channel.         */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00206                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_EDGE_COUNT_API != FALSE )    /* [SWS_Icu_00331] */
void Icu_DisableEdgeCount( Icu_ChannelType Channel )
{
    Icu_70_ChannelInfoType*  chInfoPtr;
 
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00399] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_DISABLEEDGECOUNT_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00173] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_DISABLEEDGECOUNT_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    /* [SWS_Icu_00173] */
    } else if ( ICU_MODE_EDGE_COUNTER != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_DISABLEEDGECOUNT_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        chInfoPtr = &( s_ChInfo[ Channel ] );
        /* [SWS_Icu_00079] */
        Icu_70_HW_DisableEdgeCount( chInfoPtr->conf_chInfo->IcuSetConfPtr );
        /* Manage the state of the channel with bits. */
        chInfoPtr->chRunning = FALSE;
    }
}
#endif /* #if ( ICU_EDGE_COUNT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x0f                                                         */
/* Name        : Icu_GetEdgeNumbers                                           */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : Icu_EdgeNumberType captured edge number                      */
/* Contents    : Reads the number of counted edges.                           */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00207                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_EDGE_COUNT_API != FALSE )    /* [SWS_Icu_00333] */
Icu_EdgeNumberType Icu_GetEdgeNumbers( Icu_ChannelType Channel )
{
    uint16      edgeCnt = 0U;               /* [SWS_Icu_00175] */
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00400] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETEDGENUMBERS_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00174] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETEDGENUMBERS_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    } else if ( ICU_MODE_EDGE_COUNTER != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETEDGENUMBERS_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        edgeCnt = s_ChInfo[ Channel ].edgeCount;  /* [SWS_Icu_00080] */
    }
    return edgeCnt;
}
#endif      /* #if ( ICU_EDGE_COUNT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x13                                                         */
/* Name        : Icu_StartSignalMeasurement                                   */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : This function starts the measurement of signals.             */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00208                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_SIGNAL_MEASUREMENT_API != FALSE )         /* [SWS_Icu_00335] */
void Icu_StartSignalMeasurement( Icu_ChannelType Channel )
{
    Icu_70_ChannelInfoType*     chInfoPtr;
 
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00401] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STARTSIGNALMEASUREMENT_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00176] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STARTSIGNALMEASUREMENT_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    /* [SWS_Icu_00141] */
    } else if ( ICU_MODE_SIGNAL_MEASUREMENT != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STARTSIGNALMEASUREMENT_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        chInfoPtr                  = &( s_ChInfo[ Channel ] );
        chInfoPtr->duty.ActiveTime = 0U;                           /* duty cycle active time */
        chInfoPtr->duty.PeriodTime = 0U;                           /* duty cycle period time */
        chInfoPtr->elapsedTime     = 0U;                           /* elapsed time           */
        chInfoPtr->irqState        = ICU_70_MEAS_NONE;             /* Reset irqState         */
        /* [SWS_Icu_00140] */
        /* Start Timer */
        Icu_70_HW_StartSignalMeasurement( chInfoPtr->conf_chInfo->IcuSetConfPtr,
                                          chInfoPtr->actType );
        chInfoPtr->state = ICU_IDLE;                              /* [SWS_Icu_00146] */
        /* Manage the state of the channel with bits. */
        chInfoPtr->chRunning = TRUE;
    }
}
#endif    /* #if ( ICU_SIGNAL_MEASUREMENT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x14                                                         */
/* Name        : Icu_StopSignalMeasurement                                    */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : This function stops the measurement of signals of            */
/*               the given channel.                                           */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00209                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_SIGNAL_MEASUREMENT_API != FALSE )    /* [SWS_Icu_00337] */
void Icu_StopSignalMeasurement( Icu_ChannelType Channel )
{
    Icu_70_ChannelInfoType*     chInfoPtr;
 
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00402] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STOPSIGNALMEASUREMENT_ID,
                                 ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00177] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STOPSIGNALMEASUREMENT_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    /* [SWS_Icu_00144][SWS_Icu_00177] */
    } else if ( ICU_MODE_SIGNAL_MEASUREMENT != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_STOPSIGNALMEASUREMENT_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        chInfoPtr = &( s_ChInfo[ Channel ] );                                 /* Set Channel info */
        chInfoPtr->irqState = ICU_70_MEAS_NONE;                               /* Reset irqState   */
        /* Stop Timer *//* [SWS_Icu_00143] */
        Icu_70_HW_StopSignalMeasurement( chInfoPtr->conf_chInfo->IcuSetConfPtr );
        /* Manage the state of the channel with bits. */
        chInfoPtr->chRunning = FALSE;
    }
}
#endif      /* #if ( ICU_SIGNAL_MEASUREMENT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x10                                                         */
/* Name        : Icu_GetTimeElapsed                                           */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : Icu_ValueType                                                */
/* Contents    : This function reads the elapsed Signal Low Time for the      */
/*               given channel.                                               */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00210                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_GET_TIME_ELAPSED_API != FALSE ) /* [SWS_Icu_00341] */
Icu_ValueType Icu_GetTimeElapsed( Icu_ChannelType Channel )
{
    Icu_ValueType rtnTimeElapsed = 0U;   /* [SWS_Icu_00179] */
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Icu_00382][SWS_Icu_00403] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETTIMEELAPSED_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00178] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETTIMEELAPSED_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    } else if ( ICU_MODE_SIGNAL_MEASUREMENT != s_ChInfo[ Channel ].msrMode ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETTIMEELAPSED_ID, ( uint8 )ICU_E_PARAM_CHANNEL );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Icu_00081][SWS_Icu_00082][SWS_Icu_00083][SWS_Icu_00136] */
        rtnTimeElapsed                  = s_ChInfo[ Channel ].elapsedTime;
        s_ChInfo[ Channel ].elapsedTime = 0U;    /* [SWS_Icu_00340] */
    }
    return  rtnTimeElapsed;
}
#endif      /* #if ( ICU_GET_TIME_ELAPSED_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x11                                                         */
/* Name        : Icu_GetDutyCycleValues                                       */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/*               (out) DutyCycleValues Pointer to a buffer where the results  */
/*                     (high time and period time) shall be placed.           */
/* Return      : void                                                         */
/* Contents    : This function reads the coherent active time and period time */
/*               for the given ICU channel.                                   */
/* Author      : --                                                           */
/* Note        : SWS_Icu_00211                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_GET_DUTY_CYCLE_VALUES_API != FALSE )    /* [SWS_Icu_00345] */
void Icu_GetDutyCycleValues( Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues )
{
    Icu_DutyCycleType* dutyValue;
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    const Icu_70_ChannelInfoType*     chInfo;        /* Measurement Mode */
 
    /* [SWS_Icu_00382][SWS_Icu_00404] */
    if ( ICU_STATE_UNINITIALIZED == s_Icu_ModuleState ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETDUTYCYCLEVALUES_ID, ( uint8 )ICU_E_UNINIT );
    /* [SWS_Icu_00180] */
    } else if ( s_Icu_ConfigPtr->IcuConfigSet.IcuMaxChannel <= Channel ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETDUTYCYCLEVALUES_ID,
                                 ( uint8 )ICU_E_PARAM_CHANNEL );
    } else {
        chInfo = &( s_ChInfo[ Channel ] );
        if ( ( ICU_MODE_SIGNAL_MEASUREMENT != chInfo->msrMode )
          || ( ICU_DUTY_CYCLE != chInfo->msrProp ) ) {
            ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                     ( uint8 )ICU_70_GETDUTYCYCLEVALUES_ID,
                                     ( uint8 )ICU_E_PARAM_CHANNEL );
        /* [SWS_Icu_00181][SWS_Icu_00382] */
        } else if ( NULL_PTR == DutyCycleValues ) {
            ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                     ( uint8 )ICU_70_GETDUTYCYCLEVALUES_ID,
                                     ( uint8 )ICU_E_PARAM_POINTER );
        } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
        {
            dutyValue = &( s_ChInfo[ Channel ].duty );
            /* [SWS_Icu_00084][SWS_Icu_00137][SWS_Icu_00343] */
            DutyCycleValues->ActiveTime        = dutyValue->ActiveTime; /* Set Active time */
            DutyCycleValues->PeriodTime        = dutyValue->PeriodTime; /* Set Period Time */
            /* [SWS_Icu_00344] */
            dutyValue->ActiveTime   = 0U;       /* return value at once, set 0 */
            dutyValue->PeriodTime   = 0U;       /* return value at once, set 0 */
        }
#if ( ICU_DEV_ERROR_DETECT != FALSE )
    }
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
}
#endif      /* #if ( ICU_GET_DUTY_CYCLE_VALUES_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x12                                                         */
/* Name        : Icu_GetVersionInfo                                           */
/* Param       : (out) versioninfo Pointer to where to store                  */
/*                     the version information of this module                 */
/* Return      : void                                                         */
/* Contents    : This function returns the version information of this module.*/
/* Author      : --                                                           */
/* Note        : SWS_Icu_00212                                                */
/*----------------------------------------------------------------------------*/
#if ( ICU_GET_VERSION_INFO_API == (TRUE) )
void Icu_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if ( ICU_DEV_ERROR_DETECT != FALSE )
 
    /* [SWS_Icu_00356][SWS_Icu_00382] */
    if ( NULL_PTR == versioninfo ) {
        ( void )Det_ReportError( ( uint16 )ICU_MODULE_ID, ( uint8 )ICU_INSTANCE_ID,
                                 ( uint8 )ICU_70_GETVERSIONINFO_ID, ( uint8 )ICU_E_PARAM_VINFO );
    } else
#endif      /* #if ( ICU_DEV_ERROR_DETECT != FALSE ) */
    {
        versioninfo->vendorID         = ( uint16 )ICU_VENDOR_ID;           /* Vendor ID                      */
        versioninfo->moduleID         = ( uint16 )ICU_MODULE_ID;           /* Module ID                      */
        versioninfo->sw_major_version = ( uint8 )ICU_SW_MAJOR_VERSION;     /* Software Major Version         */
        versioninfo->sw_minor_version = ( uint8 )ICU_SW_MINOR_VERSION;     /* Software Minor Version         */
        versioninfo->sw_patch_version = ( uint8 )ICU_SW_PATCH_VERSION;     /* Software Patch Version         */
    }
}
#endif /* #if ( ICU_GET_VERSION_INFO_API == (TRUE) ) */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x18                                                         */
/* Name        : Icu_DisableNotificationAsync                                 */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : This function disables the notification of a channel         */
/*               asyncronously                                                */
/* Author      : --                                                           */
/* Note        : SWS_Icu_91002                                                */
/*----------------------------------------------------------------------------*/
#ifdef ICU_DISABLE_NOTIFICATION_ASYNC_API
void Icu_DisableNotificationAsync( Icu_ChannelType Channel )
{
 
}
#endif /* #ifdef ICU_DISABLE_NOTIFICATION_ASYNC_API */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : 0x19                                                         */
/* Name        : Icu_EnableNotificationAsync                                  */
/* Param       : (in) Channel Numeric identifier of the ICU channel           */
/* Return      : void                                                         */
/* Contents    : This function enables the notification of a channel          */
/*               asyncronously                                                */
/* Author      : --                                                           */
/* Note        : SWS_Icu_91003                                                */
/*----------------------------------------------------------------------------*/
#ifdef ICU_ENABLE_NOTIFICATION_ASYNC_API
void Icu_EnableNotificationAsync( Icu_ChannelType Channel )
{
 
}
#endif /* #ifdef ICU_ENABLE_NOTIFICATION_ASYNC_API */
 
/******************************************************************************/
/* ModuleID    : ICU_MODULE_ID (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_getChInfo                                             */
/* Param       : (in)  ch      Channel ID                                     */
/* Param       : (in)  chInfo  Pointer to channel info table                  */
/*             : (out) mode    Operating mode of Icu module                   */
/* Return      : void                                                         */
/* Contents    : referece pointer to icu channel infomation table             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_getChInfo( uint8 ch, Icu_70_ChannelInfoType** chInfo, Icu_ModeType* mode )
{
    /* Set Icu module state */
    *mode = s_Icu_Mode;
    /* Set Icu Channel Info */
    *chInfo = &( s_ChInfo[ch] );
}
 
#define ICU_STOP_SEC_CODE_LOCAL
#include "Icu_MemMap.h"
 
/* EOF Icu.c ******************************************************************/