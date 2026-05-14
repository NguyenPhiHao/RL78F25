/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc.c                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    : This program file is for AUTOSAR Basic Software module       */
/*               "ADC Driver"                                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc.h"
#include "SchM_Adc.h"
#include "Det.h"
#include "Adc_70_HW.h"
#include "Adc_70_Group.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_C                   (70U)
#define ADC_70_MODULE_ID_C                   (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_C    (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_C    (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_C (0U)

#define ADC_70_SW_MAJOR_VERSION_C            (1U)
#define ADC_70_SW_MINOR_VERSION_C            (0U)
#define ADC_70_SW_PATCH_VERSION_C            (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Adc.h version check start */
#if ( ADC_70_VENDOR_ID_C != ADC_VENDOR_ID )
    #error "VENDOR ID for Adc.c and Adc.h are different"
#endif

#if ( ADC_70_MODULE_ID_C != ADC_MODULE_ID )
    #error "MODULE ID for Adc.c and Adc.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_C    != ADC_AR_RELEASE_MAJOR_VERSION ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_C    != ADC_AR_RELEASE_MINOR_VERSION ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_C != ADC_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Adc.c and Adc.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_C != ADC_SW_MAJOR_VERSION ) || \
      ( ADC_70_SW_MINOR_VERSION_C != ADC_SW_MINOR_VERSION ) || \
      ( ADC_70_SW_PATCH_VERSION_C != ADC_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Adc.c and Adc.h are different"
#endif
/* Adc.h version check end */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Adc.h version check start */
#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_C != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_C != RTE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Adc.c and SchM_Adc.h are different"
#endif
/* SchM_Adc.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Det.h version check start */
#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Adc.c and Det.h are different"
#endif
/* Det.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/* Adc_70_HW.h version check start */
#if ( ADC_70_VENDOR_ID_C != ADC_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Adc.c and Adc_70_HW.h are different"
#endif

#if ( ADC_70_MODULE_ID_C != ADC_70_MODULE_ID_HW_H )
    #error "MODULE ID for Adc.c and Adc_70_HW.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_C    != ADC_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_C    != ADC_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_C != ADC_70_AR_RELEASE_REVISION_VERSION_HW_H ) \
    )
    #error "AUTOSAR Version Numbers of Adc.c and Adc_70_HW.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_C != ADC_70_SW_MAJOR_VERSION_HW_H ) || \
      ( ADC_70_SW_MINOR_VERSION_C != ADC_70_SW_MINOR_VERSION_HW_H ) || \
      ( ADC_70_SW_PATCH_VERSION_C != ADC_70_SW_PATCH_VERSION_HW_H ) \
    )
    #error "Software Version Numbers of Adc.c and Adc_70_HW.h are different"
#endif
/* Adc_70_HW.h version check end */

/* Adc_70_Group.h version check start */
#if ( ADC_70_VENDOR_ID_C != ADC_70_VENDOR_ID_GROUP_H )
    #error "VENDOR ID for Adc.c and Adc_70_Group.h are different"
#endif

#if ( ADC_70_MODULE_ID_C != ADC_70_MODULE_ID_GROUP_H )
    #error "MODULE ID for Adc.c and Adc_70_Group.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_C    != ADC_70_AR_RELEASE_MAJOR_VERSION_GROUP_H ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_C    != ADC_70_AR_RELEASE_MINOR_VERSION_GROUP_H ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_C != ADC_70_AR_RELEASE_REVISION_VERSION_GROUP_H ) \
    )
    #error "AUTOSAR Version Numbers of Adc.c and Adc_70_Group.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_C != ADC_70_SW_MAJOR_VERSION_GROUP_H ) || \
      ( ADC_70_SW_MINOR_VERSION_C != ADC_70_SW_MINOR_VERSION_GROUP_H ) || \
      ( ADC_70_SW_PATCH_VERSION_C != ADC_70_SW_PATCH_VERSION_GROUP_H ) \
    )
    #error "Software Version Numbers of Adc.c and Adc_70_Group.h are different"
#endif
/* Adc_70_Group.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*  const data declarations                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#if ( ADC_READ_GROUP_API != FALSE )
LOCAL_INLINE Std_ReturnType adc_70_CheckReadGroup( const Adc_70_GroupInfoType* gpPtr,
    const Adc_GroupConfigurationType* gpDefPtr, bool_t* restartFlag, Adc_StatusType* newStatus );
#endif /* #if ( ADC_READ_GROUP_API != FALSE ) */
LOCAL_INLINE Std_ReturnType adc_70_CheckGetStreamLastPointer( const Adc_70_GroupInfoType* gpPtr,
    const Adc_GroupConfigurationType* gpDefPtr, bool_t* restartFlag, Adc_StatusType* newStatus );
LOCAL_INLINE bool_t adc_70_StartConversion( Adc_70_HwInfoType* hwInfoPtr,
    Adc_70_GroupInfoType* gpPtr, Adc_StatusType status );
LOCAL_INLINE void adc_70_StopConversion( Adc_70_HwInfoType* hwInfoPtr,
    Adc_70_GroupInfoType* gpPtr, Adc_StatusType status );
#if ( ADC_HW_TRIGGER_API != FALSE )
LOCAL_INLINE bool_t adc_70_CheckHwTrigSrc( const Adc_70_HW_GroupConfigType* groupConfig );
LOCAL_INLINE void adc_70_SetHwTrigSrc( const Adc_70_HW_GroupConfigType* groupConfig,
                                    bool_t triggerflag );
#endif /* ( ADC_HW_TRIGGER_API != FALSE ) */
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#define ADC_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Adc_MemMap.h"

/* workarea for HW unit. */
static Adc_70_HwInfoType        s_Adc_70_HwInfo[ADC_70_NUM_OF_HWUNIT] = { 0U };
/* workarea for group. */
static Adc_70_GroupInfoType     s_Adc_70_GroupInfo[ADC_70_MAX_NUM_OF_GROUP] = { 0U };
/* pointer to config data */
static const Adc_ConfigType*    s_Adc_70_ConfigPtr = NULL_PTR;
/* workarea for HW trigger source management */
#if ( ADC_HW_TRIGGER_API != FALSE )
static Adc_HwTrigSrcMngType     s_Adc_70_HwTrigSrcMng[ADC_70_RL78F2X_NUM_OF_HWTRIGSRC] = {
    {ADC_HW_TRIG_SRC_INTTM01        , FALSE},
    {ADC_HW_TRIG_SRC_INTRTC         , FALSE},
    {ADC_HW_TRIG_SRC_INTTRJ0        , FALSE},
    {ADC_HW_TRIG_SRC_INTTRD0_IFA    , FALSE},
    {ADC_HW_TRIG_SRC_INTTRD0_IFB    , FALSE},
    {ADC_HW_TRIG_SRC_INTTRD1_IFA    , FALSE},
    {ADC_HW_TRIG_SRC_INTTRD1_IFB    , FALSE},
    {ADC_HW_TRIG_SRC_INTTRD1_UDF    , FALSE},
    {ADC_HW_TRIG_SRC_INTTRD_ADTRG   , FALSE},
    {ADC_HW_TRIG_SRC_ELCTRG0        , FALSE}
};
static uint8 s_Adc_NumOfCurHwTrig = 0U;
#endif /* #if ( ADC_HW_TRIGGER_API != FALSE ) */
#define ADC_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Adc_MemMap.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define ADC_START_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_INIT_ID (0x00)                                        */
/* Name        : Adc_Init                                                     */
/* Param       : (in) ConfigPtr  Pointer to configuration set                 */
/* Return      : None                                                         */
/* Contents    : Initializes the ADC hardware units and driver.               */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00365][SWS_Adc_00056][QINeS_SWS_ADC_00008]          */
/******************************************************************************/
void Adc_Init( const Adc_ConfigType* ConfigPtr )
{
    /* HW unit configuration pointer */
    const Adc_HwUnitType*   hwDefPtr;   /* no initial value for MISRA2012 Rule-2.2 */
    /* pointer to group information table */
    Adc_70_GroupInfoType*   gpPtr;      /* no initial value for MISRA2012 Rule-2.2 */
    /* pointer to H/W information */
    Adc_70_HwInfoType*      hwInfoPtr;  /* no initial value for MISRA2012 Rule-2.2 */
    /* loop index */
    uint16_least            lcounti;
    /* loop index */
    uint8_least             lcountj;
    /* group id work */
    Adc_GroupType           groupid;

#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    /* [QINeS_SWS_ADC_00005] support PostBuild only. */
    if ( NULL_PTR == ConfigPtr ) {
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_INIT_ID, ( uint8 ) ADC_E_PARAM_POINTER );
    } else if ( NULL_PTR != s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00107] If development error detection for the ADC module is enabled: */
        /*                 if called when the ADC driver and hardware are already initialized, */
        /*                 the function Adc_Init shall raise development error ADC_E_ALREADY_INITIALIZED */
        /*                 and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_INIT_ID, ( uint8 ) ADC_E_ALREADY_INITIALIZED );
    } else
#endif /* ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /* clean group work table. */
        for ( lcounti = 0U; lcounti < ADC_70_HW1_NUM_OF_GROUP; lcounti++ ) {
            /* get pointer of group work table */
            gpPtr                       = &( s_Adc_70_GroupInfo[lcounti] ) ;
            gpPtr->hwunitId             = ADC_70_HWUNIT_NONE;   /* clear hardware id */
            gpPtr->groupDef             = NULL_PTR;             /* clear pointer to group def */
#if ( ADC_GRP_NOTIF_CAPABILITY != FALSE )
            gpPtr->notificationEnable   = FALSE;                /* [SWS_Adc_00077] disable notification */
#endif /* #if ( ADC_GRP_NOTIF_CAPABILITY != FALSE ) */
            gpPtr->validSamples         = 0U;                   /* clear validSamples of result */
            gpPtr->curSample            = 0U;                   /* index for current samples */
            gpPtr->status               = ADC_IDLE;             /* [SWS_Adc_00307] set group to ADC_IDLE state */
            gpPtr->resultBuffer         = NULL_PTR;             /* channel id in conversion */
            gpPtr->lastPtr              = NULL_PTR;             /* clear last pointer of group */
        }
        /* [SWS_Adc_00054] Initialize the driver according to the configuration. */
        /* initialize HW work table */
        for ( lcounti = 0U; lcounti < ADC_70_NUM_OF_HWUNIT; lcounti++ ) {
            /* get configuration of HW unit */
            hwDefPtr   = &( ConfigPtr->AdcConfigSet.AdcHwUnit[lcounti] ) ;
            /* initialize group work table of HW unit */
            for ( lcountj = 0U; lcountj < hwDefPtr->AdcNumOfAdcGroup; lcountj++ ) {
                groupid                 = hwDefPtr->AdcGroup[lcountj].AdcGroupId;
                gpPtr                   = &( s_Adc_70_GroupInfo[groupid] );
                gpPtr->groupDef         = &( hwDefPtr->AdcGroup[lcountj] );
                gpPtr->hwunitId         = ( Adc_70_HwUnitIdType ) lcounti;
            }
            hwInfoPtr   = &( s_Adc_70_HwInfo[lcounti] );    /* pointer to H/W information */
            hwInfoPtr->hwUnitDef        = hwDefPtr;     /* group-id of HW1 in conversion   */
            hwInfoPtr->execGroup        = NULL_PTR;     /* current conversion group information */
            Adc_70_HW_Init( hwDefPtr ) ;
        }
        s_Adc_70_ConfigPtr = ConfigPtr;           /* save the config data pointer. */
    }
}

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_SETUP_RESULT_BUFFER_ID (0x0C)                         */
/* Name        : Adc_SetupResultBuffer                                        */
/* Param       : (in) Group Numeric ID of requested ADC channel group         */
/*               (in) DataBufferPtr pointer to result data buffer             */
/* Return      : E_OK     : result buffer pointer initialized                 */
/*               E_NOT_OK : operation failed or development error occured     */
/* Contents    : Initializes ADC driver with the group specific result buffer */
/*               start address where the conversion results will be stored.   */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00413][SWS_Adc_00415][SWS_Adc_91000]                */
/******************************************************************************/
Std_ReturnType Adc_SetupResultBuffer( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr )
{
    Std_ReturnType          retStat = E_NOT_OK;     /* return status */

#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00434] If development error detection for the ADC module is enabled: */
        /*          when called prior to initializing the driver, the function Adc_SetupResultBuffer */
        /*          shall raise development error ADC_E_UNINIT. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_SETUP_RESULT_BUFFER_ID, ( uint8 ) ADC_E_UNINIT );
    } else if ( ( Adc_GroupType ) ADC_70_MAX_NUM_OF_GROUP <= Group ) {
        /* [SWS_Adc_00423] If development error detection for the ADC module is enabled: */
        /*          if the channel group ID is non-existing, the function Adc_SetupResultBuffer */
        /*          shall raise development error ADC_E_PARAM_GROUP and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_SETUP_RESULT_BUFFER_ID,
                               ( uint8 ) ADC_E_PARAM_GROUP );
    } else if ( NULL_PTR == DataBufferPtr ) {
        /* [SWS_Adc_00457] If development error detection for the ADC module is enabled: */
        /*          when called with a NULL_PTR as DataBufferPtr, the function Adc_SetupResultBuffer */
        /*          shall raise development error ADC_E_PARAM_POINTER. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_SETUP_RESULT_BUFFER_ID,
                               ( uint8 ) ADC_E_PARAM_POINTER );
    } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        if ( ADC_IDLE != s_Adc_70_GroupInfo[Group].status ) {
            /* [SWS_Adc_00433] If called while group is not in state ADC_IDLE, function Adc_SetupResultBuffer */
            /*          shall report a runtime error ADC_E_BUSY. */
            ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_SETUP_RESULT_BUFFER_ID, ( uint8 ) ADC_E_BUSY );
        } else {
            /* [SWS_Adc_00420] The function Adc_SetupResultBuffer shall initialize the result buffer pointer */
            /*          of the selected group with the address value passed as parameter. */
            s_Adc_70_GroupInfo[Group].resultBuffer = DataBufferPtr;
            retStat = E_OK;
        }
    }
    return retStat;
}

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_DEINIT_ID (0x01)                                      */
/* Name        : Adc_DeInit                                                   */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Returns all ADC HW Units to                                  */
/*               a state comparable to their power on reset state.            */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00366]                                              */
/******************************************************************************/
/* [SWS_Adc_00228] The function Adc_DeInit shall be pre compile time configurable On/Off by */
/*          the configuration parameter: AdcDeInitApi. */
#if ( ADC_DEINIT_API != FALSE )
void Adc_DeInit( void )
{
    /* pointer to group information table element */
    Adc_70_GroupInfoType*   gpPtr;      /* no initial value for MISRA2012 Rule-2.2 */
    /* pointer to H/W information */
    Adc_70_HwInfoType*      hwInfoPtr;  /* no initial value for MISRA2012 Rule-2.2 */
    /* HW unit configuration pointer */
    const Adc_HwUnitType*   hwDefPtr;   /* no initial value for MISRA2012 Rule-2.2 */
    /* loop index */
    uint16_least            lcounti;
    bool_t                  allGroupIsIdle  = TRUE;     /* the status is idle of all group */

#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00154] If development error detection for the ADC module is enabled: if called before */
        /*          the module has been initialized, the function Adc_DeInit shall raise */
        /*          development error ADC_E_UNINIT and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_DEINIT_ID, ( uint8 ) ADC_E_UNINIT );
    } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Adc_00112] if called while not all groups are either in state ADC_IDLE or */
        /*          state ADC_STREAM_COMPLETED, while no conversion is ongoing */
        /*          (ADC groups which are implicitly stopped), the function Adc_DeInit */
        /*          shall report a runtime error. */
        for ( lcounti = 0U; lcounti < ADC_70_MAX_NUM_OF_GROUP; lcounti++ ) {
            gpPtr = &( s_Adc_70_GroupInfo[lcounti] );
            if ( ( ADC_IDLE             != gpPtr->status )
              && ( ADC_STREAM_COMPLETED != gpPtr->status ) ) {
                allGroupIsIdle = FALSE;
                break;
            }
        }
        if ( FALSE == allGroupIsIdle ) {
            ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_DEINIT_ID, ( uint8 ) ADC_E_BUSY );
        } else {
            /* deinitialize ADC hardware and information of ADC hardware HW */
            for ( lcounti = 0U; lcounti < ADC_70_NUM_OF_HWUNIT; lcounti++ ) {
                /* get configuration of HW unit */
                hwDefPtr   = &( s_Adc_70_ConfigPtr->AdcConfigSet.AdcHwUnit[lcounti] ) ;
                Adc_70_HW_DeInit( hwDefPtr );
                /* get pointer to H/W information */
                hwInfoPtr = &( s_Adc_70_HwInfo[ lcounti ] ) ;
                hwInfoPtr->hwUnitDef = NULL_PTR;                    /* group-id of HW1 in conversion   */
                hwInfoPtr->execGroup = NULL_PTR;                    /* current conversion group information */
            }
            /* deinitialize all group information */
            for ( lcounti = 0U; lcounti < ADC_70_MAX_NUM_OF_GROUP; lcounti++ ) {
                gpPtr = &( s_Adc_70_GroupInfo[ lcounti ] ) ;
                gpPtr->hwunitId             = ADC_70_HWUNIT_NONE;   /* clear hardware id */
                gpPtr->groupDef             = NULL_PTR;             /* clear pointer to group def */
#if ( ADC_GRP_NOTIF_CAPABILITY != FALSE )
                gpPtr->notificationEnable   = FALSE;                /* [SWS_Adc_00111] disable notification */
#endif /* #if ( ADC_GRP_NOTIF_CAPABILITY != FALSE ) */
                gpPtr->validSamples         = 0U;                   /* clear validSamples of result */
                gpPtr->curSample            = 0U;                   /* clear current index for sample */
                gpPtr->status               = ADC_IDLE;             /* clear group state */
                gpPtr->resultBuffer         = NULL_PTR;             /* channel id in conversion */
                gpPtr->lastPtr              = NULL_PTR;             /* clear last pointer of group */
            }
            /* Deinitialize HW Trigger Source Management */
#if ( ADC_HW_TRIGGER_API != FALSE )
            for ( lcounti = 0U; lcounti < ADC_70_RL78F2X_NUM_OF_HWTRIGSRC; lcounti++ ) {
                s_Adc_70_HwTrigSrcMng[lcounti].istriggered  = FALSE;
            }
            s_Adc_NumOfCurHwTrig = 0U;
#endif /* #if ( ADC_HW_TRIGGER_API != FALSE ) */
            s_Adc_70_ConfigPtr = NULL_PTR;                          /* save the config data pointer */
        }
    }
}
#endif /* #if ( ADC_DEINIT_API != FALSE ) */


/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_START_GROUP_CONVERSION_ID (0x02)                      */
/* Name        : Adc_StartGroupConversion                                     */
/* Param       : (in) Group    Numeric ID of requested ADC channel group.     */
/* Return      : None                                                         */
/* Contents    : Starts the conversion of all channels of the requested       */
/*               ADC Channel group.                                           */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00413][SWS_Adc_00415]                               */
/*               [SWS_Adc_00367][SWS_Adc_00156]                               */
/******************************************************************************/
/* [SWS_Adc_00259] The function Adc_StartGroupConversion shall be pre-compile time configurable */
/*          On/Off by the configuration parameter AdcEnableStartStopGroupApi. */
#if ( ADC_ENABLE_START_STOP_GROUP_API != FALSE )
void Adc_StartGroupConversion( Adc_GroupType Group )
{
    /* pointer to group information */
    Adc_70_GroupInfoType*             gpPtr;        /* no initial value for MISRA2012 Rule-2.2 */
    /* pointer to group definition */
    const Adc_GroupConfigurationType* gpDefPtr;     /* no initial value for MISRA2012 Rule-2.2 */
    /* pointer to H/W infomation */
    Adc_70_HwInfoType*                hwInfoPtr;    /* no initial value for MISRA2012 Rule-2.2 */

#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00294] If development error detection for the ADC module is enabled: */
        /*          when called prior to initializing the driver, the function Adc_StartGroupConversion */
        /*          shall raise development error ADC_E_UNINIT. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_START_GROUP_CONVERSION_ID, ( uint8 ) ADC_E_UNINIT );
    } else if ( ( Adc_GroupType ) ADC_70_MAX_NUM_OF_GROUP <= Group ) {
        /* [SWS_Adc_00125] If development error detection for the ADC module is enabled: */
        /*          when called with a non-existing channel group ID, function Adc_StartGroupConversion */
        /*          shall raise development error ADC_E_PARAM_GROUP and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_START_GROUP_CONVERSION_ID,
                               ( uint8 )  ADC_E_PARAM_GROUP );
    } else
#endif      /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /* get pointer of group work table and group def table. */
        gpPtr     = &( s_Adc_70_GroupInfo[Group] );
        gpDefPtr  = gpPtr->groupDef;
        hwInfoPtr = &( s_Adc_70_HwInfo[gpPtr->hwunitId] );
#if ( ADC_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
        if ( ADC_TRIGG_SRC_SW != gpDefPtr->AdcGroupTriggSrc ) {
            /* [SWS_Adc_00133] The ADC module's environment shall only call Adc_StartGroupConversion */
            /*          for groups configured with software trigger source. */
            ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_START_GROUP_CONVERSION_ID,
                                   ( uint8 ) ADC_E_WRONG_TRIGG_SRC );
        } else if ( NULL_PTR == gpPtr->resultBuffer ) {
            /* [SWS_Adc_00424] If development error detection for the ADC module is enabled: */
            /*          when called prior to initializing the result buffer pointer */
            /*          with function Adc_SetupResultBuffer, the function Adc_StartGroupConversion */
            /*          shall raise development error ADC_E_BUFFER_UNINIT. */
            ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_START_GROUP_CONVERSION_ID,
                                   ( uint8 ) ADC_E_BUFFER_UNINIT );
        } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
        if ( ( FALSE    == gpDefPtr->Adc_70_implicitlyStop )
                 && ( ADC_IDLE != gpPtr->status ) ) {
            /* [SWS_Adc_00346] If the priority mechanism is disabled and the queuing is disabled : */
            /*          when called while any of the groups, which can not be implicitly stopped, */
            /*          is not in state ADC_IDLE , the function Adc_StartGroupConversion shall */
            /*          report a runtime error ADC_E_BUSY. */
            ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                          ( uint8 ) ADC_70_START_GROUP_CONVERSION_ID,
                                          ( uint8 ) ADC_E_BUSY );
        } else if ( ( FALSE                != gpDefPtr->Adc_70_implicitlyStop )
                 && ( ADC_IDLE             != gpPtr->status )
                 && ( ADC_STREAM_COMPLETED != gpPtr->status ) ) {
            /* [SWS_Adc_00426] If the priority mechanism is disabled and the queuing is disabled: */
            /*          when called while any of the groups, which can be implicitly stopped, */
            /*          is not in state ADC_IDLE and not in state ADC_STREAM_COMPLETED, */
            /*          the function Adc_StartGroupConversion shall report a runtime error ADC_E_BUSY. */
            ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                          ( uint8 ) ADC_70_START_GROUP_CONVERSION_ID,
                                          ( uint8 ) ADC_E_BUSY );
        } else if ( ( NULL_PTR != hwInfoPtr->execGroup )
                 && ( gpPtr != hwInfoPtr->execGroup ) ) {
            /* [SWS_Adc_00346][SWS_Adc_00426] Make it busy if any group has been converted by HW unit. */
            ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                          ( uint8 ) ADC_70_START_GROUP_CONVERSION_ID,
                                          ( uint8 ) ADC_E_BUSY );
        } else {
            /* [SWS_Adc_00380] Accept groups configured in ONESHOT conversion mode. */
            /* [SWS_Adc_00381] Accept groups configured in CONTINUOUS conversion mode. */
            /* [SWS_Adc_00061] start ADC conversion */
            ( void )adc_70_StartConversion( hwInfoPtr, gpPtr, ADC_BUSY );
        }
    }
}
#endif /* #if ( ADC_ENABLE_START_STOP_GROUP_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_STOP_GROUP_CONVERSION_ID (0x03)                       */
/* Name        : Adc_StopGroupConversion                                      */
/* Param       : (in) Group         Numeric ID of requested ADC channel group.*/
/* Return      : None                                                         */
/* Contents    : STOP the conversion of all channels of the requested         */
/*               ADC Channel group.                                           */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00413][SWS_Adc_00415][SWS_Adc_00368]                */
/******************************************************************************/
/* [SWS_Adc_00260] The function Adc_StopGroupConversion shall be pre compile time configurable */
/*          On/Off by the configuration parameter AdcEnableStartStopGroupApi. */
#if ( ADC_ENABLE_START_STOP_GROUP_API != FALSE )
void Adc_StopGroupConversion( Adc_GroupType Group )
{
    /* pointer to group information table element */
    Adc_70_GroupInfoType*   gpPtr;              /* no initial value for MISRA2012 Rule-2.2 */
    /* pointer to group definition table element */
    const Adc_GroupConfigurationType* gpDefPtr; /* no initial value for MISRA2012 Rule-2.2 */

#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00295] If development error detection for the ADC module is enabled: */
        /*          if called prior to initializing the module, function Adc_StopGroupConversion */
        /*          shall raise development error ADC_E_UNINIT and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_STOP_GROUP_CONVERSION_ID, ( uint8 ) ADC_E_UNINIT );
    } else if ( ( Adc_GroupType ) ADC_70_MAX_NUM_OF_GROUP <= Group ) {
        /* [SWS_Adc_00126] If development error detection for the ADC module is enabled: */
        /*          if the group ID is non-existing, the function Adc_StopGroupConversion */
        /*          shall raise development error ADC_E_PARAM_GROUP and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_STOP_GROUP_CONVERSION_ID,
                               ( uint8 ) ADC_E_PARAM_GROUP );
    } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /* get pointer of group work table and group def table. */
        gpPtr    = &( s_Adc_70_GroupInfo[Group] );
        gpDefPtr = gpPtr->groupDef;
#if ( ADC_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
        if ( ADC_TRIGG_SRC_SW != gpDefPtr->AdcGroupTriggSrc ) {
            /* [SWS_Adc_00164] If development error detection for the ADC module is enabled: */
            /*          if the group has a trigger source configured as hardware, function */
            /*          Adc_StopGroupConversion shall raise development error ADC_E_WRONG_TRIGG_SRC */
            /*          and return without any action. */
            ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_STOP_GROUP_CONVERSION_ID,
                                   ( uint8 ) ADC_E_WRONG_TRIGG_SRC );
        } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
        {
            if ( ADC_IDLE == gpPtr->status ) {
                /* [SWS_Adc_00241] when called while the group is in state ADC_IDLE, the function */
                /*          Adc_StopGroupConversion shall report a runtime error ADC_E_IDLE. */
                ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                              ( uint8 ) ADC_70_STOP_GROUP_CONVERSION_ID,
                                              ( uint8 ) ADC_E_IDLE );
            } else {
                /* [SWS_Adc_00385] Stop group conversion during conversion                     */
                /*          that is set in ONESHOT conversion mode and SW trigger mode. */
                /* [SWS_Adc_00386] Stop group conversion during conversion                     */
                /*          set for CONTINUOUS conversion mode and SW trigger mode.     */
                /* [SWS_Adc_00360] set the group status to state ADC_IDLE. */
                adc_70_StopConversion( &s_Adc_70_HwInfo[gpPtr->hwunitId], gpPtr, ADC_IDLE );
                /* [SWS_Adc_00155] disable group notification for the requested group */
#if ( ADC_GRP_NOTIF_CAPABILITY != FALSE )
                gpPtr->notificationEnable = FALSE;
#endif /* #if ( ADC_GRP_NOTIF_CAPABILITY != FALSE ) */
            }
        }
    }
}
#endif /* #if ( ADC_ENABLE_START_STOP_GROUP_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_READ_GROUP_ID (0x04)                                  */
/* Name        : Adc_ReadGroup                                                */
/* Param       : (in)  Group        Numeric ID of requested ADC channel group.*/
/*               (out) DataBufferPtr ADC results of all channels of the       */
/*                                   selected group are stored                */
/*                                   in the data buffer addressed with the    */
/*                                   pointer.                                 */
/* Return      : E_OK     : results are available and written                 */
/*                          to the data buffer                                */
/*               E_NOT_OK : no results are available or                       */
/*                          development error occured                         */
/* Contents    : Reads the group conversion result of the last completed      */
/*               conversion round of the requested group and stores           */
/*               the channel values starting at the DataBufferPtr address.    */
/*               The group channel values are stored in ascending channel     */
/*               number order ( in contrast to the storage layout of the      */
/*               result buffer if streaming access is configured).            */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00413][SWS_Adc_00415][SWS_Adc_00369]                */
/******************************************************************************/
/* [SWS_Adc_00359] The function Adc_ReadGroup shall be pre-compile configurable On/Off */
/*          by the configuration parameter AdcReadGroupApi. */
#if ( ADC_READ_GROUP_API != FALSE )
Std_ReturnType Adc_ReadGroup( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr )
{
    /* pointer to group infomation table element */
    Adc_70_GroupInfoType*   gpPtr;              /* no initial value for MISRA2012 Rule-2.2 */
    /* pointer to group definition table element */
    const Adc_GroupConfigurationType* gpDefPtr; /* no initial value for MISRA2012 Rule-2.2 */
    /* return status */
    Std_ReturnType          retStat = E_NOT_OK;
    /* sampled data number work */
    uint8                   sampleNum;
    /* sampled data number work */
    uint8                   sampleNumFast;
    /* loop counter */
    uint8_least             lcounti;
    /* array position cal */
    uint16                  lArrayCal;
    /* restart flag : TRUE restart after read */
    bool_t                  restartFlag = FALSE;
    /* new status */
    Adc_StatusType          newStatus;          /* no initial value for MISRA2012 Rule-2.2 */

#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00296] If development error detection for the ADC module is enabled: */
        /*          when called prior to initializing the driver, the function Adc_ReadGroup */
        /*          shall raise development error ADC_E_UNINIT and return E_NOT_OK. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_READ_GROUP_ID, ( uint8 ) ADC_E_UNINIT );
    } else if ( ( Adc_GroupType ) ADC_70_MAX_NUM_OF_GROUP <= Group ) {
        /* [SWS_Adc_00152] If development error detection for the ADC module is enabled: */
        /*          if the group ID is non-existing, the function Adc_ReadGroup shall raise */
        /*          development errorADC_E_PARAM_GROUP and return E_NOT_OK. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_READ_GROUP_ID, ( uint8 ) ADC_E_PARAM_GROUP );
    } else if ( NULL_PTR == DataBufferPtr ) {
        /* [QINeS_SWS_ADC_00011] check Data Buffer Pointer is not NULL */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_READ_GROUP_ID, ( uint8 ) ADC_E_PARAM_POINTER );
    } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /*get pointer of group work table and group def table */
        gpPtr    = &( s_Adc_70_GroupInfo[Group] );
        gpDefPtr = gpPtr->groupDef;
        /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
        if ( ( ADC_IDLE == gpPtr->status )
          && ( 0U == gpPtr->validSamples ) ) {
            /* [SWS_Adc_00388] When called while the group status is ADC_IDLE and the group conversion */
            /*          was not started (no results are available from previous conversions), */
            /*          the function Adc_ReadGroup shall report a runtime error ADC_E_IDLE. */
            ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                          ( uint8 ) ADC_70_READ_GROUP_ID, ( uint8 ) ADC_E_IDLE );
        } else {
            /* [SWS_Adc_00503] Simple read calls, as implemented in Adc_ReadGroup and */
            /*                  Adc_GetGroupStatus,shall always be reentrant even if  */
            /*                  the functions are called for same channel groups. It  */
            /*                  is up to the implementation to use adequate protection*/
            /*                  mechanisms (e.g. disabling/enabling interrupts. */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03();             /* Disable Interrupt */
            newStatus = gpPtr->status;
            /* check status to transition */
            /* SW-Trigger */
            /* [SWS_Adc_00329] If conversion of all samples is completed               */
            /*          and it is a group in the STREAM_COMPLETED state                */
            /*          that does not implicitly stop,                                 */
            /*          the state transitions to the BUSY state.                       */
            /* [SWS_Adc_00330] If conversion of all samples is complete                */
            /*          and it is a group of STREAM_COMPLETED states                   */
            /*          that implicitly stop, the state transitions to the IDLE state. */
            /* [SWS_Adc_00331] If conversion of all samples is not completed           */
            /*          and the group is in the COMPLETED state,                       */
            /*          the state transitions to the BUSY state.                       */
            /* [SWS_Adc_00140] When the conversion result is not overwritten,          */
            /*          the consistency of the conversion result is guaranteed.        */
            retStat = adc_70_CheckReadGroup( gpPtr, gpDefPtr, &restartFlag, &newStatus );
            if ( E_OK == retStat ) {
                /* copy the result to application buffer. */
                /* [SWS_Adc_00113][SWS_Adc_00122]                           */
                /*      Considering only the alignment that has been set,   */
                /*      return the conversion result without scaling.       */
                /* [SWS_Adc_00075] read newest data from buffer             */
                if ( 0U == gpPtr->curSample ) {
                    sampleNum = gpDefPtr->AdcStreamingNumSamples - 1U;
                } else {
                    sampleNum = gpPtr->curSample - 1U;
                }
                sampleNumFast = gpDefPtr->AdcStreamingNumSamples; /* Get the sample number of converted group */
                for ( lcounti = 0U; lcounti < gpDefPtr->AdcNumOfGroupDefinition; lcounti++ ) {
                    lArrayCal = ( lcounti * sampleNumFast ) + sampleNum;
                    DataBufferPtr[lcounti] = gpPtr->resultBuffer[lArrayCal];
                }
                gpPtr->status = newStatus;  /* update status */
                gpPtr->validSamples = 0U;   /* clear the number of valid samples */
                if ( FALSE != restartFlag ) {
                    ( void )adc_70_StartConversion( &s_Adc_70_HwInfo[gpPtr->hwunitId],
                                                    gpPtr, ADC_BUSY );
                }
            }
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03();              /* Enable interrupt  */
        }
    }
    return retStat;
}
#endif /* #if ( ADC_READ_GROUP_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_ENABLE_HARDWARE_TRIGGER_ID (0x05)                     */
/* Name        : Adc_EnableHardwareTrigger                                    */
/* Param       : (in) Group         Numeric ID of requested ADC channel group.*/
/* Return      : None                                                         */
/* Contents    : Enables the hardware trigger for the requested               */
/*               ADC Channel group.                                           */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00413][SWS_Adc_00415][SWS_Adc_91001]                */
/******************************************************************************/
/* [SWS_Adc_00265] The function Adc_EnableHardwareTrigger shall be pre-compile time configurable */
/*                 On/Off by the configuration parameter AdcHwTriggerApi */
#if ( ADC_HW_TRIGGER_API != FALSE )
void Adc_EnableHardwareTrigger( Adc_GroupType Group )
{
    /* pointer to group information */
    Adc_70_GroupInfoType*             gpPtr;        /* no initial value for MISRA2012 Rule-2.2 */
    /* pointer to group definition */
    const Adc_GroupConfigurationType* gpDefPtr;     /* no initial value for MISRA2012 Rule-2.2 */
    /* pointer to H/W infomation */
    Adc_70_HwInfoType*                hwInfoPtr;    /* no initial value for MISRA2012 Rule-2.2 */
    /* loop index */
    uint16_least            lcounti;
    /* the status is idle of all group */
    bool_t                  allSWGroupIsIdle  = TRUE;

#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00297] If development error detection for the ADC module is enabled: */
        /*          when called prior to initializing the driver, the function Adc_EnableHardwareTrigger */
        /*          shall raise development error ADC_E_UNINIT and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_ENABLE_HARDWARE_TRIGGER_ID, ( uint8 ) ADC_E_UNINIT );

    } else if ( ( Adc_GroupType ) ADC_70_MAX_NUM_OF_GROUP <= Group ) {
        /* [SWS_Adc_00128] If development error detection for the ADC module is enabled: */
        /*          when called with a non-existing channel group ID, function Adc_EnableHardwareTrigger */
        /*          shall raise development error ADC_E_PARAM_GROUP and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_ENABLE_HARDWARE_TRIGGER_ID,
                               ( uint8 )  ADC_E_PARAM_GROUP );

    } else
#endif      /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /* get pointer of group work table and group def table. */
        gpPtr     = &( s_Adc_70_GroupInfo[Group] );
        gpDefPtr  = gpPtr->groupDef;
        hwInfoPtr = &( s_Adc_70_HwInfo[gpPtr->hwunitId] );

#if ( ADC_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
        if ( ADC_TRIGG_SRC_HW != gpDefPtr->AdcGroupTriggSrc ) {
            /* [SWS_Adc_00136] If development error detection for the ADC module is enabled: */
            /*          If the group is configured for software API trigger mode, the function */
            /*          Adc_EnableHardwareTrigger shall raise development error ADC_E_WRONG_TRIGG_SRC */
            /*          and return without any action */
            ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_ENABLE_HARDWARE_TRIGGER_ID,
                                   ( uint8 ) ADC_E_WRONG_TRIGG_SRC );

        } else if ( NULL_PTR == gpPtr->resultBuffer ) {
            /* [SWS_Adc_00425] If development error detection for the ADC module is enabled: */
            /*          when called prior to initializing the result buffer pointer */
            /*          with function Adc_SetupResultBuffer, the function Adc_EnableHardwareTrigger */
            /*          shall raise development error ADC_E_BUFFER_UNINIT. */
            ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_ENABLE_HARDWARE_TRIGGER_ID,
                                   ( uint8 ) ADC_E_BUFFER_UNINIT );

        } else if ( ADC_CONV_MODE_CONTINUOUS == gpDefPtr->AdcGroupConversionMode ) {
            /* [SWS_Adc_00281]  If development error detection for the ADC module is enabled: */
            /*                  if a HW group is erroneously configured for continuous conversion mode, */
            /*                  the function Adc_EnableHardwareTrigger shall raise development error */
            /*                  ADC_E_WRONG_CONV_MODE and return without any action. */
            ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_ENABLE_HARDWARE_TRIGGER_ID,
                                   ( uint8 ) ADC_E_WRONG_CONV_MODE );

        } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
        {
            for ( lcounti = 0U; lcounti < ADC_70_MAX_NUM_OF_GROUP; lcounti++ ) {
                gpPtr = &( s_Adc_70_GroupInfo[lcounti] );
                if ( ( ADC_IDLE != gpPtr->status )
                    && ( ADC_TRIGG_SRC_SW == gpPtr->groupDef->AdcGroupTriggSrc ) ) {
                    allSWGroupIsIdle = FALSE;
                    break;
                }
            }

            gpPtr = &( s_Adc_70_GroupInfo[Group] );

            if ( FALSE == allSWGroupIsIdle ) {
                /* [SWS_Adc_00321] If the priority mechanism is disabled and queuing disabled: */
                /*                 when called while any group with trigger source SW is not in state ADC_IDLE, */
                /*                 the function Adc_EnableHardwareTrigger shall report a runtime error ADC_E_BUSY.*/
                ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                              ( uint8 ) ADC_70_ENABLE_HARDWARE_TRIGGER_ID,
                                              ( uint8 ) ADC_E_BUSY );

            } else if ( ADC_70_RL78F2X_HWTRIGSRC_MAX <= s_Adc_NumOfCurHwTrig ) {
                /* [SWS_Adc_00353]  If the maximum number of available hardware triggers is already enabled */
                /*                  (device and implementation specific), the function Adc_EnableHardwareTrigger */
                /*                  shall report a runtime error ADC_E_BUSY. */
                ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                              ( uint8 ) ADC_70_ENABLE_HARDWARE_TRIGGER_ID,
                                              ( uint8 ) ADC_E_BUSY );

            } else if ( TRUE != adc_70_CheckHwTrigSrc( gpPtr->groupDef->Adc_70_GroupConfig ) ) {
                /* [SWS_Adc_00349]  If the HW trigger for the group is already enabled, the function */
                /*                  Adc_EnableHardwareTrigger shall report a runtime error ADC_E_BUSY. */
                ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                              ( uint8 ) ADC_70_ENABLE_HARDWARE_TRIGGER_ID,
                                              ( uint8 ) ADC_E_BUSY );

            } else {
                /* start HW trigger conversion */
                ( void )adc_70_StartConversion( hwInfoPtr, gpPtr, ADC_BUSY );
                /* update HW trigger source management */
                adc_70_SetHwTrigSrc( gpPtr->groupDef->Adc_70_GroupConfig, TRUE );
                s_Adc_NumOfCurHwTrig++;
            }
        }
    }
}
#endif /* #if ( ADC_HW_TRIGGER_API != FALSE ) */


/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_DISABLE_HARDWARE_TRIGGER_ID (0x06)                    */
/* Name        : Adc_DisableHardwareTrigger                                   */
/* Param       : (in) Group     Numeric ID of requested ADC Channel group.    */
/* Return      : None                                                         */
/* Contents    : Disables the hardware trigger for the requested              */
/*               ADC Channel group.                                           */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00413][SWS_Adc_00415][SWS_Adc_91002]                */
/******************************************************************************/
/* [SWS_Adc_00266] The function Adc_DisableHardwareTrigger shall be pre-compile time configurable */
/*                 On/Off by the configuration parameter AdcHwTriggerApi. */
#if ( ADC_HW_TRIGGER_API != FALSE )
void Adc_DisableHardwareTrigger( Adc_GroupType Group )
{
    /* pointer to group infomation table element */
    Adc_70_GroupInfoType*             gpPtr;        /* no initial value for MISRA2012 Rule-2.2 */
#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* pointer to group definition table element */
    const Adc_GroupConfigurationType* gpDefPtr;     /* no initial value for MISRA2012 Rule-2.2 */
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */

#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00298] If development error detection for the ADC module is enabled: */
        /*          if called prior to initializing the ADC module, Adc_DisableHardwareTrigger shall */
        /*          raise development error ADC_E_UNINIT and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_DISABLE_HARDWARE_TRIGGER_ID,
                               ( uint8 ) ADC_E_UNINIT );

    } else if ( ( Adc_GroupType ) ADC_70_MAX_NUM_OF_GROUP <= Group ) {
        /* [SWS_Adc_00129] If development error detection for the ADC module is enabled: */
        /*          if the channel group ID is non-existing, the function Adc_DisableHardwareTrigger */
        /*          shall raise development error ADC_E_PARAM_GROUP and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_DISABLE_HARDWARE_TRIGGER_ID,
                               ( uint8 ) ADC_E_PARAM_GROUP );

    } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /* get pointer of group work table and group def table */
        gpPtr = &( s_Adc_70_GroupInfo[Group] );
#if ( ADC_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
        gpDefPtr = gpPtr->groupDef;

        if ( ADC_TRIGG_SRC_HW != gpDefPtr->AdcGroupTriggSrc ) {
            /* [SWS_Adc_00137] If development error detection for the ADC module is enabled: */
            /*          If the group is configured for software API trigger mode, the function */
            /*          Adc_DisableHardwareTrigger shall raise development error ADC_E_WRONG_TRIGG_SRC */
            /*          and return without any action */
            ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_DISABLE_HARDWARE_TRIGGER_ID,
                                   ( uint8 ) ADC_E_WRONG_TRIGG_SRC );

        } else if ( ADC_CONV_MODE_CONTINUOUS == gpDefPtr->AdcGroupConversionMode ) {
            /* [SWS_Adc_00281]  If development error detection for the ADC module is enabled: */
            /*                  if a HW group is erroneously configured for continuous conversion mode, */
            /*                  the function Adc_DisableHardwareTrigger shall raise development error */
            /*                  ADC_E_WRONG_CONV_MODE and return without any action. */
            ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_DISABLE_HARDWARE_TRIGGER_ID,
                                   ( uint8 ) ADC_E_WRONG_CONV_MODE );

        } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
        {
            if ( ADC_IDLE == gpPtr->status ) {
                /* [SWS_Adc_00304] If the group is not enabled (with a previous call of Adc_EnableHardwareTrigger), */
                /*                 the function Adc_DisableHardwareTrigger shall report a runtime error ADC_E_IDLE.*/
                ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                              ( uint8 ) ADC_70_DISABLE_HARDWARE_TRIGGER_ID,
                                              ( uint8 ) ADC_E_IDLE );

            } else {
                /* [SWS_Adc_00116] The function Adc_DisableHardwareTrigger shall disable */
                /*                 the hardware trigger for the requested ADC Channel group. */
                /* [SWS_Adc_00361] set the group status to state ADC_IDLE. */
                adc_70_StopConversion( &s_Adc_70_HwInfo[gpPtr->hwunitId], gpPtr, ADC_IDLE );

                /* update HW trigger source management */
                adc_70_SetHwTrigSrc( gpPtr->groupDef->Adc_70_GroupConfig, FALSE );

                s_Adc_NumOfCurHwTrig--;

                /* [SWS_Adc_00157] disable group notification for the requested group */
#if ( ADC_GRP_NOTIF_CAPABILITY != FALSE )
                gpPtr->notificationEnable = FALSE;
#endif /* #if ( ADC_GRP_NOTIF_CAPABILITY != FALSE ) */
            }
        }
    }
}
#endif /* #if ( ADC_HW_TRIGGER_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_ENABLE_GROUP_NOTIFICATION_ID (0x07)                   */
/* Name        : Adc_EnableGroupNotification                                  */
/* Param       : (in) Group     Numeric ID of requested ADC Channel group.    */
/* Return      : None                                                         */
/* Contents    : Enables the notification mechanism                           */
/*               for the requested ADC Channel group.                         */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00413][SWS_Adc_00415][SWS_Adc_91003]                */
/******************************************************************************/
/* [SWS_Adc_00100] The function Adc_EnableGroupNotification shall be pre-compile time configurable */
/*          On/Off by the configuration parameter AdcGrpNotifCapability. */
#if ( ADC_GRP_NOTIF_CAPABILITY != FALSE )
void Adc_EnableGroupNotification( Adc_GroupType Group )
{
    /* pointer to group infomation table element */
    Adc_70_GroupInfoType*             gpPtr;        /* no initial value for MISRA2012 Rule-2.2 */
#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* pointer to group definition table element */
    const Adc_GroupConfigurationType* gpDefPtr;     /* no initial value for MISRA2012 Rule-2.2 */
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */

#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00299] If development error detection for the ADC module is enabled: */
        /*          if called prior to initializing the ADC module, Adc_EnableGroupNotification shall */
        /*          raise development error ADC_E_UNINIT and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_ENABLE_GROUP_NOTIFICATION_ID,
                               ( uint8 ) ADC_E_UNINIT );
    } else if ( ( Adc_GroupType ) ADC_70_MAX_NUM_OF_GROUP <= Group ) {
        /* [SWS_Adc_00130] If development error detection for the ADC module is enabled: */
        /*          if the channel group ID is non-existing, the function Adc_EnableGroupNotification */
        /*          shall raise development error ADC_E_PARAM_GROUP and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_ENABLE_GROUP_NOTIFICATION_ID,
                               ( uint8 ) ADC_E_PARAM_GROUP );
    } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /* get pointer of group work table and group def table */
        gpPtr    = &( s_Adc_70_GroupInfo[Group] );
#if ( ADC_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
        gpDefPtr = gpPtr->groupDef;
        if ( NULL_PTR == gpDefPtr->AdcNotification ) {
            /* [SWS_Adc_00165] If development error detection for the ADC module is enabled: */
            /*          if the group notification function pointer is NULL, the function */
            /*          Adc_EnableGroupNotification shall raise development error */
            /*          ADC_E_NOTIF_CAPABILITY and return without any action. */
            ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_ENABLE_GROUP_NOTIFICATION_ID,
                                   ( uint8 ) ADC_E_NOTIF_CAPABILITY );
        } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
        {
            /* [SWS_Adc_00057] The function Adc_EnableGroupNotification shall enable the notification */
            /*          mechanism for the requested ADC Channel group. */
            /* [SWS_Adc_00080] Execute only when Callback function pointer is not NULL. */
            gpPtr->notificationEnable = TRUE;
        }
    }
}
#endif /* #if ( ADC_GRP_NOTIF_CAPABILITY != FALSE ) */


/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_DISABLE_GROUP_NOTIFICATION_ID (0x08)                  */
/* Name        : Adc_DisableGroupNotification                                 */
/* Param       : (in) Group     Numeric ID of requested ADC Channel group.    */
/* Return      : None                                                         */
/* Contents    : Disable the notification mechanism                           */
/*               for the requested ADC Channel group.                         */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00413][SWS_Adc_00415][SWS_Adc_91004]                */
/******************************************************************************/
#if ( ADC_GRP_NOTIF_CAPABILITY != FALSE )
/* [SWS_Adc_00101] The function Adc_DisableGroupNotification shall be pre-compile time configurable */
/*          On/Off by the configuration parameter AdcGrpNotifCapability */
void Adc_DisableGroupNotification( Adc_GroupType Group )
{
    /* pointer to group infomation table element */
    Adc_70_GroupInfoType*             gpPtr;    /* no initial value for MISRA2012 Rule-2.2 */
#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* pointer to group definition table element */
    const Adc_GroupConfigurationType* gpDefPtr; /* no initial value for MISRA2012 Rule-2.2 */
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */

#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00300] If development error detection for the ADC module is enabled: */
        /*          if called prior to initializing the ADC module, Adc_DisableGroupNotification */
        /*          shall raise development error ADC_E_UNINIT and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_DISABLE_GROUP_NOTIFICATION_ID,
                               ( uint8 ) ADC_E_UNINIT );
    } else if ( ( Adc_GroupType ) ADC_70_MAX_NUM_OF_GROUP <= Group ) {
        /* [SWS_Adc_00131] If development error detection for the ADC module is enabled: */
        /*          if the channel group ID is non-existing, the function Adc_DisableGroupNotification */
        /*          shall raise development error ADC_E_PARAM_GROUP and return without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_DISABLE_GROUP_NOTIFICATION_ID,
                               ( uint8 ) ADC_E_PARAM_GROUP );
    } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /* get pointer of group work table and group def table. */
        gpPtr    = &( s_Adc_70_GroupInfo[Group] );
#if ( ADC_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
        gpDefPtr = gpPtr->groupDef;
        if ( NULL_PTR == gpDefPtr->AdcNotification ) {
            /* [SWS_Adc_00166] If development error detection for the ADC module is enabled: */
            /*          if the group notification function pointer is NULL, the function */
            /*          Adc_DisableGroupNotification shall raise development error */
            /*          ADC_E_NOTIF_CAPABILITY and return without any action. */
            ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                   ( uint8 ) ADC_70_DISABLE_GROUP_NOTIFICATION_ID,
                                   ( uint8 ) ADC_E_NOTIF_CAPABILITY );
        } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
        {
            /* [SWS_Adc_00058] The function Adc_DisableGroupNotification shall disable the notification */
            /*          mechanism for the requested ADC Channel group. */
            gpPtr->notificationEnable = FALSE;
        }
    }
}
#endif /* #if ( ADC_GRP_NOTIF_CAPABILITY != FALSE ) */

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_GET_GROUP_STATUS_ID (0x09)                            */
/* Name        : Adc_GetGroupStatus                                           */
/* Param       : (in) Group         Numeric ID of requested ADC channel group.*/
/* Return      : Conversion status for the requested group.                   */
/* Contents    : Returns the conversion status                                */
/*               of the requested ADC Channel group.                          */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00413][SWS_Adc_00415][SWS_Adc_00374]                */
/*               [SWS_Adc_00221][SWS_Adc_00222][SWS_Adc_00224]                */
/*               [SWS_Adc_00225][SWS_Adc_00226]                               */
/******************************************************************************/
Adc_StatusType Adc_GetGroupStatus( Adc_GroupType Group )
{
    Adc_StatusType groupStatus = ADC_IDLE;

#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00301] If development error detection for the ADC module is enabled: */
        /*          if called prior to initializing the ADC module, Adc_GetGroupStatus shall */
        /*          raise development error ADC_E_UNINIT and return ADC_IDLE without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_GET_GROUP_STATUS_ID, ( uint8 ) ADC_E_UNINIT );
    } else if ( ( Adc_GroupType ) ADC_70_MAX_NUM_OF_GROUP <= Group ) {
        /* [SWS_Adc_00225] If development error detection for the ADC module is enabled: */
        /*          if the channel group ID is non-existing, the function Adc_GetGroupStatus */
        /*          shall raise development error ADC_E_PARAM_GROUP and return ADC_IDLE */
        /*          without any action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_GET_GROUP_STATUS_ID, ( uint8 ) ADC_E_PARAM_GROUP );
    } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Adc_00220] Returns the conversion status of the requested ADC channel group. */
        /* [SWS_Adc_00503] Simple read calls, as implemented in Adc_ReadGroup and */
        /*                  Adc_GetGroupStatus,shall always be reentrant even if  */
        /*                  the functions are called for same channel groups. It  */
        /*                  is up to the implementation to use adequate protection*/
        /*                  mechanisms (e.g. disabling/enabling interrupts. */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00();
        groupStatus = s_Adc_70_GroupInfo[Group].status;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00();
    }
    return groupStatus;
}

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_GET_STREAM_LAST_POINTER_ID (0x0b)                     */
/* Name        : Adc_GetStreamLastPointer                                     */
/* Param       : (in) Group         Numeric ID of requested ADC channel group.*/
/* Param       : (out) PtrToSamplePtr        Pointer to result buffer pointer.*/
/* Return      : Adc_StreamNumSampleType  Number of valid samples per channel.*/
/* Contents    : Returns the number of valid samples per channel,             */
/*               stored in the result buffer. Reads a pointer, pointing to    */
/*               a position in the group result buffer.With the pointer       */
/*               position,the results of all group channels of                */
/*               the last completed conversion round can be accessed.         */
/*               With the pointer and the return value,all valid group        */
/*               conversion results can be accessed (the user has to take     */
/*               the layout of the result buffer into account).               */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00413][SWS_Adc_00415][SWS_Adc_00375]                */
/******************************************************************************/
Adc_StreamNumSampleType Adc_GetStreamLastPointer( Adc_GroupType Group,
    Adc_ValueGroupType** PtrToSamplePtr )
{
    /* pointer to group infomation table element */
    Adc_70_GroupInfoType*    gpPtr;             /* no initial value for MISRA2012 Rule-2.2 */
    /* pointer to group definition table element */
    const Adc_GroupConfigurationType* gpDefPtr; /* no initial value for MISRA2012 Rule-2.2 */
    /* number of valid sample */
    Adc_StreamNumSampleType sampleNum = 0U;
    /* status for judge */
    Std_ReturnType          retStat;            /* no initial value for MISRA2012 Rule-2.2 */
    /* Restart Flag */
    bool_t                  restartFlag = FALSE;
    /* new status */
    Adc_StatusType          newStatus;          /* no initial value for MISRA2012 Rule-2.2 */

    /* [SWS_Adc_00215][SWS_Adc_00216][SWS_Adc_00218][SWS_Adc_00302]   */
    /* Set null to the argument pointer                               */
    /* for processing that does not return a valid conversion result. */
    if ( NULL_PTR != PtrToSamplePtr ) {
        *PtrToSamplePtr = NULL_PTR;
    }
#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == s_Adc_70_ConfigPtr ) {
        /* [SWS_Adc_00302] If development error detection for the ADC module is enabled: */
        /*          if called prior to initializing the driver, the function */
        /*          Adc_GetStreamLastPointer shall raise development error ADC_E_UNINIT, */
        /*          set the pointer, passed as parameter (PtrToSamplePtr), to NULL and */
        /*          return 0 without any further action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_GET_STREAM_LAST_POINTER_ID,
                               ( uint8 ) ADC_E_UNINIT );
    } else if ( ( Adc_GroupType ) ADC_70_MAX_NUM_OF_GROUP <= Group ) {
        /* [SWS_Adc_00218] If development error detection for the ADC module is enabled: */
        /*          if the group ID is non-existent, the function Adc_GetStreamLastPointer */
        /*          shall raise development error ADC_E_PARAM_GROUP, set the pointer, passed as */
        /*          parameter (PtrToSamplePtr), to NULL and return 0 without any further action. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_GET_STREAM_LAST_POINTER_ID,
                               ( uint8 ) ADC_E_PARAM_GROUP );
    } else if ( NULL_PTR == PtrToSamplePtr ) {
        /* [QINeS_SWS_ADC_00011] check Data Buffer Pointer is not NULL */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ADC_70_GET_STREAM_LAST_POINTER_ID,
                               ( uint8 ) ADC_E_PARAM_POINTER );
    } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /* --- Get pointer of group work table and group def table ----- */
        gpPtr    = &( s_Adc_70_GroupInfo[Group] );
        gpDefPtr = gpPtr->groupDef;
        if ( ADC_BUSY == gpPtr->status  ) {/*  BUSY Check  [SWS_Adc_00216]  */
            /* [SWS_Adc_00216] When called while the group status is ADC_BUSY (a conversion of the group */
            /*          is in progress), the function Adc_GetStreamLastPointer shall set the pointer, */
            /*          passed as parameter (PtrToSamplePtr), to NULL and return 0.*/
        } else if ( ( ADC_IDLE == gpPtr->status )
          && ( 0U == gpPtr->validSamples ) ) {
            /* [SWS_Adc_00215] when called while the group status is ADC_IDLE and the group conversion */
            /*          was not started (no results are available from previous conversions) , */
            /*          the function Adc_GetStreamLastPointer shall report a runtime error ADC_E_IDLE */
            ( void )Det_ReportRuntimeError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                                          ( uint8 ) ADC_70_GET_STREAM_LAST_POINTER_ID,
                                          ( uint8 ) ADC_E_IDLE );
        } else {
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09();     /* Disable Interrupt */
            newStatus = gpPtr->status;
            /* check status to transition */
            /* SW-Trigger  */
            /* [SWS_Adc_00326] If conversion of all samples is completed               */
            /*          and it is a group in the STREAM_COMPLETED state                */
            /*          that does not implicitly stop,                                 */
            /*          the state transitions to the BUSY state.                       */
            /* [SWS_Adc_00327] If conversion of all samples is complete                */
            /*          and it is a group of STREAM_COMPLETED states                   */
            /*          that implicitly stop, the state transitions to the IDLE state. */
            /* [SWS_Adc_00328] If conversion of all samples is not completed           */
            /*          and the group is in the COMPLETED state,                       */
            /*          the state transitions to the BUSY state.                       */
            /* [SWS_Adc_00140] When the conversion result is not overwritten,          */
            /*          the consistency of the conversion result is guaranteed.        */
            retStat = adc_70_CheckGetStreamLastPointer( gpPtr, gpDefPtr, &restartFlag, &newStatus );
            if ( E_OK == retStat ) {
                /* [SWS_Adc_00214] Set a pointer indicating the latest conversion result. */
                /* [SWS_Adc_00418] Considering only the alignment that has been set,   */
                /*          return the conversion result without scaling.       */
                *PtrToSamplePtr = gpPtr->lastPtr;
                /* [SWS_Adc_00387] Returns the number of valid samples. */
                sampleNum = ( gpPtr->validSamples );
                gpPtr->status = newStatus;  /* update status */
                gpPtr->validSamples = 0U;   /* clear the number of valid samples */
                if ( FALSE != restartFlag ) {
                    ( void )adc_70_StartConversion( &s_Adc_70_HwInfo[gpPtr->hwunitId],
                                                  gpPtr, ADC_BUSY );
                }
            }
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();      /* Enable interrupt  */
        }
    }
    return sampleNum;
}


/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : ADC_70_GET_VERSION_INFO_ID (0x0a)                            */
/* Name        : Adc_GetVersionInfo                                           */
/* Param       : (out) VersionInfo  Pointer to where to store the version     */
/*                                  information of this module.               */
/* Return      : None                                                         */
/* Contents    : Returns the version information of this module.              */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00376]                                              */
/******************************************************************************/
#if ( ADC_VERSION_INFO_API != FALSE )
void Adc_GetVersionInfo( Std_VersionInfoType* VersionInfo )
{
#if ( ADC_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Adc_91005][SWS_Adc_91006] Use error codes defined by AUTOSAR. */
    if ( NULL_PTR == VersionInfo ) {
        /* [SWS_Adc_00458] If development error detection for the ADC module is enabled: */
        /*          The function Adc_GetVersionInfo shall check the parameter versioninfo */
        /*          for not being NULL and shall raise the development error ADC_E_PARAM_POINTER */
        /*          if the check fails. */
        ( void )Det_ReportError( ( uint16 ) ADC_MODULE_ID, ( uint8 ) ADC_70_INSTANCE_ID,
                               ( uint8 ) ( ADC_70_GET_VERSION_INFO_ID ),
                               ( uint8 ) ( ADC_E_PARAM_POINTER ) );
    } else
#endif /* #if ( ADC_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Adc_00236] Read out module ID, vendor ID and version number */
        VersionInfo->vendorID         = ( uint16 ) ADC_VENDOR_ID;           /* Vendor ID */
        VersionInfo->moduleID         = ( uint16 ) ADC_MODULE_ID;           /* Module ID */
        VersionInfo->sw_major_version = ( uint8 ) ADC_SW_MAJOR_VERSION;     /* Software Major Version */
        VersionInfo->sw_minor_version = ( uint8 ) ADC_SW_MINOR_VERSION;     /* Software Minor Version */
        VersionInfo->sw_patch_version = ( uint8 ) ADC_SW_PATCH_VERSION;     /* Software Patch Version */
    }
}
#endif /* #if ( ADC_VERSION_INFO_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : adc_70_CheckReadGroup                                        */
/* Param       :(in)  gpPtr: pointer to group information table element       */
/*             :(in)  gpDefPtr: pointer to group definition table element     */
/*             :(out) restartFlg: TRUE restart after read                     */
/*             :(out) newStatus: update status after read                     */
/* Return      : E_OK     : be able to status transition                      */
/*               E_NOT_OK : be not able to status transition                  */
/* Contents    : check status for Adc_ReadGroup                               */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00369]                                              */
/******************************************************************************/
/* [SWS_Adc_00359] The function Adc_ReadGroup shall be pre-compile configurable On/Off */
/*          by the configuration parameter AdcReadGroupApi. */
#if ( ADC_READ_GROUP_API != FALSE )
LOCAL_INLINE Std_ReturnType adc_70_CheckReadGroup( const Adc_70_GroupInfoType* gpPtr,
    const Adc_GroupConfigurationType* gpDefPtr, bool_t* restartFlag, Adc_StatusType* newStatus )
{
    Std_ReturnType retStat = E_NOT_OK;     /* status for judge */
    Adc_StatusType grpStatus;

    grpStatus = gpPtr->status;
    switch ( grpStatus ) {
    case ADC_STREAM_COMPLETED:
        if ( FALSE == gpDefPtr->Adc_70_implicitlyStop ) {
            /* [SWS_Adc_00329] If conversion of all samples is completed       */
            /*          and it is a group in the STREAM_COMPLETED state */
            /*          that does not implicitly stop,                  */
            /*          the state transitions to the BUSY state.        */
            *newStatus   = ADC_BUSY;
            if ( ADC_TRIGG_SRC_SW == gpDefPtr->AdcGroupTriggSrc ) {
                *restartFlag = TRUE;
            }
        } else {
            /* [SWS_Adc_00330] If conversion of all samples is complete                       */
            /*          and it is a group of STREAM_COMPLETED states                   */
            /*          that implicitly stop, the state transitions to the IDLE state. */
            *newStatus   = ADC_IDLE;
        }
        retStat = E_OK;
        break ;
    case ADC_COMPLETED:
        /* [SWS_Adc_00331] If conversion of all samples is not completed */
        /*          and the group is in the COMPLETED state,      */
        /*          the state transitions to the BUSY state.      */
        *newStatus = ADC_BUSY;
        if ( ADC_TRIGG_SRC_SW == gpDefPtr->AdcGroupTriggSrc ) {
            *restartFlag = TRUE;
        }
        retStat    = E_OK;
        break;
    case ADC_IDLE:
        /* [SWS_Adc_00388] If there is a valid conversion result even in the idle state, */
        /*          accept the request.                                           */
        if ( 0U != gpPtr->validSamples ) {
            *newStatus = ADC_IDLE;
            retStat = E_OK;
        }
        break;
    default:
        /* The busy state has no valid conversion result, so it does not accept the request. */
        break;
    }

    return retStat;
}
#endif /* #if ( ADC_READ_GROUP_API != FALSE )*/

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : adc_70_CheckGetStreamLastPointer                             */
/* Param       :(in)  gpPtr: pointer to group information table element       */
/*             :(in)  gpDefPtr: pointer to group definition table element     */
/*             :(out) restartFlg: TRUE restart after read                     */
/*             :(out) newStatus: update status after read                     */
/* Return      : E_OK     : be able to status transition                      */
/*               E_NOT_OK : be not able to status transition                  */
/* Contents    : check status for Adc_GetStreamLastPointer                    */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00375]                                              */
/******************************************************************************/
LOCAL_INLINE Std_ReturnType adc_70_CheckGetStreamLastPointer( const Adc_70_GroupInfoType* gpPtr,
    const Adc_GroupConfigurationType* gpDefPtr, bool_t* restartFlag, Adc_StatusType* newStatus )
{
    Std_ReturnType retStat = E_NOT_OK;     /* status for judge */
    Adc_StatusType grpStatus;

    grpStatus = gpPtr->status;
    switch ( grpStatus ) {
    case ADC_STREAM_COMPLETED:
        if ( FALSE == gpDefPtr->Adc_70_implicitlyStop ) {
            /* [SWS_Adc_00326] If conversion of all samples is completed*/
            /*          and it is a group in the STREAM_COMPLETED state */
            /*          that does not implicitly stop,                  */
            /*          the state transitions to the BUSY state.        */
            *newStatus   = ADC_BUSY;
            if ( ADC_TRIGG_SRC_SW == gpDefPtr->AdcGroupTriggSrc ) {
                *restartFlag = TRUE;
            }
        } else {
            /* [SWS_Adc_00327] If conversion of all samples is complete                */
            /*          and it is a group of STREAM_COMPLETED states                   */
            /*          that implicitly stop, the state transitions to the IDLE state. */
            *newStatus   = ADC_IDLE;
        }
        retStat = E_OK;
        break ;
    case ADC_COMPLETED:
        /* [SWS_Adc_00328] If conversion of all samples is not completed */
        /*          and the group is in the COMPLETED state,             */
        /*          the state transitions to the BUSY state.             */
        *newStatus = ADC_BUSY;
        if ( ADC_TRIGG_SRC_SW == gpDefPtr->AdcGroupTriggSrc ) {
            *restartFlag = TRUE;
        }
        retStat    = E_OK;
        break;
    case ADC_IDLE:
        /* [SWS_Adc_00215] If there is a valid conversion result even in the idle state, */
        /*          accept the request.                                                  */
        if ( 0U != gpPtr->validSamples ) {
            *newStatus = ADC_IDLE;
            retStat = E_OK;
        }
        break;
    default:
        /* The busy state has no valid conversion result, so it does not accept the request. */
        break;
    }

    return retStat;
}


/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : adc_70_StartConversion                                       */
/* Param       : (in) hwInfoPtr: pointer to HW unit information               */
/*             : (in) gpPtr: pointer to group information                     */
/*             : (in) Status: status for setting to group                     */
/* Return      : TRUE: group has started or enqueued.                         */
/*             : FALSE: group has notstarted or enqueued.                     */
/* Contents    : ADC interrupt handler common function.                       */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00367]                                              */
/******************************************************************************/
LOCAL_INLINE bool_t adc_70_StartConversion( Adc_70_HwInfoType* hwInfoPtr,
    Adc_70_GroupInfoType* gpPtr, Adc_StatusType status )
{
    /* pointer to group ongoing */
    const Adc_70_GroupInfoType* gpRunPtr; /* no initial value for MISRA2012 Rule-2.2 */
    bool_t retFlg = TRUE;

    gpRunPtr = s_Adc_70_HwInfo[gpPtr->hwunitId].execGroup;
    /* gpPtr is able to start, check other group is running */
    if ( ( NULL_PTR != gpRunPtr ) && ( gpPtr != gpRunPtr ) ) {
        /* when other group is ongoing */
        /* cannot start this group, because other group is running */
        retFlg = FALSE;
    } else {
        /* [SWS_Adc_00061][SWS_Adc_00114] start ADC conversion */
        Adc_70_Group_StartConversion( hwInfoPtr, gpPtr, status );
    }
    return retFlg;
}

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : adc_70_StopConversion                                        */
/* Param       : (in) hwInfoPtr: pointer to HW unit information               */
/*             : (in) gpPtr: pointer to group information                     */
/*             : (in) Status: status for setting to group                     */
/* Return      : None                                                         */
/* Contents    : stop ADC conversion.                                         */
/* Author      : --                                                           */
/* Note        : [SWS_Adc_00368]                                              */
/******************************************************************************/
LOCAL_INLINE void adc_70_StopConversion( Adc_70_HwInfoType* hwInfoPtr,
    Adc_70_GroupInfoType* gpPtr, Adc_StatusType status )
{
    Adc_70_Group_StopConversion( hwInfoPtr, gpPtr, status );
}

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : adc_70_CheckHwTrigSrc                                        */
/* Param       : (in) groupConfig: pointer to HW Group config                 */
/* Return      : bool_t                                                       */
/* Contents    : Check HW trigger source.                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ADC_HW_TRIGGER_API != FALSE )
LOCAL_INLINE bool_t adc_70_CheckHwTrigSrc( const Adc_70_HW_GroupConfigType* groupConfig )
{
    bool_t ret = TRUE;
    uint16  lhwtrigsrcA;
    uint16  lhwtrigsrcB;
    uint8_least lcounti;

    if ( FALSE == groupConfig->regAdcsrTrge) {
        ret = FALSE;

    } else {
        lhwtrigsrcA = ( ( groupConfig->regAdstrgr ) & 0x3F00U ) >> 8U;
        lhwtrigsrcB = ( ( groupConfig->regAdstrgr ) & 0x3FU );
 
        if ( lhwtrigsrcA == lhwtrigsrcB ) {
            /* Should not use the same HW trigger source for Group A and Group B */
            ret = FALSE;

        } else {
            /* check if HW trigger source is already enabled by another group */
            for ( lcounti = 0U; lcounti < ( ADC_70_RL78F2X_NUM_OF_HWTRIGSRC - 1U ); lcounti++ ) {
                /* exclude ELC, user have to take care it */
                if ( ( ( ( uint16 )s_Adc_70_HwTrigSrcMng[lcounti].hwtrigsrc == lhwtrigsrcA )
                    || ( ( uint16 )s_Adc_70_HwTrigSrcMng[lcounti].hwtrigsrc == lhwtrigsrcB ) )
                    && ( s_Adc_70_HwTrigSrcMng[lcounti].istriggered == TRUE ) ) {
                    ret = FALSE;
                    break;
                }
            }
        }
    }
    return ret;
}
#endif /* ( ADC_HW_TRIGGER_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : adc_70_SetHwTrigSrc                                          */
/* Param       : (in) groupConfig: pointer to HW Group config                 */
/* Param       : (in) triggerflag: value to update to                         */
/*                s_Adc_70_HwTrigSrcMng[lcounti].istriggered                  */
/* Return      : None                                                         */
/* Contents    : Set HW trigger source state.                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ADC_HW_TRIGGER_API != FALSE )
LOCAL_INLINE void adc_70_SetHwTrigSrc( const Adc_70_HW_GroupConfigType* groupConfig,
                                       bool_t triggerflag )
{
    uint16 lhwtrigsrcA;
    uint16 lhwtrigsrcB;
    uint8_least lcounti;
 
    lhwtrigsrcA = ( ( groupConfig->regAdstrgr ) & 0x3F00U ) >> 8U;
    lhwtrigsrcB = ( ( groupConfig->regAdstrgr ) & 0x3FU );
    for ( lcounti = 0U; lcounti < ( ADC_70_RL78F2X_NUM_OF_HWTRIGSRC - 1U ); lcounti++ ) {
        /* exclude ELC, user have to take care it */
        if ( ( ( uint16 )s_Adc_70_HwTrigSrcMng[lcounti].hwtrigsrc == lhwtrigsrcA )
            || ( ( uint16 )s_Adc_70_HwTrigSrcMng[lcounti].hwtrigsrc == lhwtrigsrcB ) ) {
            s_Adc_70_HwTrigSrcMng[lcounti].istriggered = triggerflag;
        }
    }
}
#endif /* ( ADC_HW_TRIGGER_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : ADC_MODULE_ID(123)                                           */
/* ServiceID   : --                                                           */
/* Name        : Adc_70_Isr_Common                                            */
/* Param       : (in) hwUnitId: HW unit ID.                                   */
/*               (in) intGrpId: Interrupt Group ID                            */
/* Return      : None                                                         */
/* Contents    : ADC interrupt handler common function.                       */
/* Author      : --                                                           */
/* Note        : The fact that an interrupt occurred means                    */
/*               that the conversion result within                            */
/*               the limit check range could be acquired.                     */
/*               [SWS_Adc_00083][SWS_Adc_00416][SWS_Adc_00446]                */
/******************************************************************************/
void Adc_70_Isr_Common( Adc_70_HwUnitIdType hwUnitId, Adc_70_IntGrpIdType intGrpId )
{
    Adc_70_HwInfoType*      hwInfoPtr;              /* pointer to H/W infomation */
    Adc_70_GroupInfoType*   gpPtr;                  /* group infomation table pointer */
    const Adc_GroupConfigurationType* gpDefPtr;     /* group definition table pointer */
    const Adc_ChannelConfigurationType* channelCfgPtr;  /* channel configuration pointer */
    Adc_ValueGroupType*     resultBuf;              /* result buffer pointer */
    Adc_StreamNumSampleType sampleNum;              /* sampling number on streaming mode */
    uint16_least            channel_cnt;
    hwInfoPtr   = &( s_Adc_70_HwInfo[ hwUnitId ] ); /* get H/W infomation pointer*/
    /* get the converted group information table pointer. */
gpPtr       = hwInfoPtr->execGroup;
gpDefPtr    = gpPtr->groupDef;                  /* get the converted group def table pointer. */
sampleNum   = gpDefPtr->AdcStreamingNumSamples; /* get the sample number of converted group. */
resultBuf   = gpPtr->resultBuffer;              /* get the result buffer pointer of converted group. */

/* get channel definition */
channelCfgPtr = gpDefPtr->AdcGroupDefinition[0];
for ( channel_cnt = 0U; channel_cnt<gpDefPtr->AdcNumOfGroupDefinition; channel_cnt++ ) {
/* get value from ADC */
resultBuf[ ( sampleNum * channel_cnt ) + gpPtr->curSample ] = \
Adc_70_HW_GetAdcValue( channelCfgPtr->AdcChannelId );
channelCfgPtr = &( channelCfgPtr[1U] );
}

/* finished conversion of the current group channel -> COMPLETED or STREAM_COMPLETED */
/* save current data pointer for Adc_GetStreamLastPointer() */
gpPtr->lastPtr = &( resultBuf[ gpPtr->curSample ] );
gpPtr->curSample++;                             /* increment index for current sample. */
if ( sampleNum > gpPtr->curSample )   {         /* buffer is full or not? */
/* not Buffer full -> COMPLETED */
if ( sampleNum > gpPtr->validSamples ) {    /* buffer is full or not? */
gpPtr->validSamples++;                 /* increment sample number. */
}
/* [SWS_Adc_00447] Trigger to update group status. */
/* [SWS_Adc_00078] Reset the interrupt flag. */
/* [SWS_Adc_00140] Continue conversion even                               */
/*          if implicitly stopped group goes into STREAM_COMPLETED state. */
/* start 1st channel of next cycle */
if ( ADC_TRIGG_SRC_SW == gpDefPtr->AdcGroupTriggSrc ) {
if ( ADC_STREAM_COMPLETED == gpPtr->status ) {
( void )adc_70_StartConversion( hwInfoPtr, gpPtr, ADC_STREAM_COMPLETED );
} else {
( void )adc_70_StartConversion( hwInfoPtr, gpPtr, ADC_COMPLETED );
}
}
else {
if ( ADC_STREAM_COMPLETED == gpPtr->status ) {
gpPtr->status = ADC_STREAM_COMPLETED;
} else {
gpPtr->status = ADC_COMPLETED;
}

if ( ( Adc_70_IntGrpIdType ) ADC_70_RL78F2X_INTAD == intGrpId ) {
#if ( COMPILER == COMPILER_CC )
/* [SWS_Adc_00078] Reset the interrupt flag. */
__clr1( ( uint8 QL_70_NEAR * )ADC_70_RL78F2X_IF1H_ADR, 0U );    /* bit0: ADIF */
#elif ( COMPILER == COMPILER_IAR )
#endif
} else {
#if ( COMPILER == COMPILER_CC )
/* [SWS_Adc_00078] Reset the interrupt flag. */
__clr1( ( uint8 QL_70_NEAR * )ADC_70_RL78F2X_IF3H_ADR, 2U );    /* bit0: ADGBIF */
#elif ( COMPILER == COMPILER_IAR )
#endif
}
}

/* notification when ADC_COMPLETED */
#if ( ADC_GRP_NOTIF_CAPABILITY != FALSE )
/* [SWS_Adc_00060][SWS_Adc_00104]                                       */
/* Call the notification function                                       */
/* every time all the channel conversion within the group is completed. */
if ( FALSE != gpPtr->notificationEnable ) {
gpDefPtr->AdcNotification();
}
#endif /* #if ( ADC_GRP_NOTIF_CAPABILITY != FALSE ) */
} else {
/* buffer full -> STREAM_COMPLETED */
gpPtr->validSamples = sampleNum;            /* increment sample number. */
gpPtr->curSample = 0U;                      /* clear index for current sample. */
/* no need to stop request when not implicitly stop group has ADC_STREAM_COMPLETED */
/* [QINeS_SWS_ADC_00010][QINeS_SWS_ADC_00013] Determines whether to stop implicitly. */
/* [SWS_Adc_00447] Trigger to update group status. */
/* [SWS_Adc_00078] Reset the interrupt flag. */
if ( FALSE != gpDefPtr->Adc_70_implicitlyStop ) {
/* stop conversion */
adc_70_StopConversion( hwInfoPtr, gpPtr, ADC_STREAM_COMPLETED );
#if ( ADC_HW_TRIGGER_API != FALSE )
if ( ADC_TRIGG_SRC_HW == gpDefPtr->AdcGroupTriggSrc ) {
/* update HW trigger source management */
adc_70_SetHwTrigSrc( gpDefPtr->Adc_70_GroupConfig, FALSE );
s_Adc_NumOfCurHwTrig--;
}
#endif /* #if ( ADC_HW_TRIGGER_API != FALSE ) */
} else {
if ( ADC_TRIGG_SRC_SW == gpDefPtr->AdcGroupTriggSrc ) {
/* start 1st channel of next cycle */
( void )adc_70_StartConversion( hwInfoPtr, gpPtr, ADC_STREAM_COMPLETED );
} else {
gpPtr->status = ADC_STREAM_COMPLETED;
if ( ( Adc_70_IntGrpIdType ) ADC_70_RL78F2X_INTAD == intGrpId ) {
#if ( COMPILER == COMPILER_CC )
__clr1( ( uint8 QL_70_NEAR * )ADC_70_RL78F2X_IF1H_ADR, 0U );    /* bit0: ADIF */
#elif ( COMPILER == COMPILER_IAR )
#endif
} else {
#if ( COMPILER == COMPILER_CC )
__clr1( ( uint8 QL_70_NEAR * )ADC_70_RL78F2X_IF3H_ADR, 2U );    /* bit0: ADIFGB */
#elif ( COMPILER == COMPILER_IAR )
#endif
}
}

}
/* notification when ADC_COMPLETED */
#if ( ADC_GRP_NOTIF_CAPABILITY != FALSE )
/* [SWS_Adc_00060][SWS_Adc_00104]                                       */
/* Call the notification function                                       */
/* every time all the channel conversion within the group is completed. */
if ( FALSE != gpPtr->notificationEnable ) {
gpDefPtr->AdcNotification();
}
#endif /* #if ( ADC_GRP_NOTIF_CAPABILITY != FALSE ) */
}
}

#define ADC_STOP_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

/* EOF Adc.c ******************************************************************/
