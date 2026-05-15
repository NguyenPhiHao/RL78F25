/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcu.c                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    : This specification describes the functionality and API for a */
/*               MCU [Microcontroller Unit] driver.                           */
/*               The MCU driver provides services for basic microcontroller   */
/*               initialization, power down functionality, reset and          */
/*               microcontroller specific functions required by other         */
/*               MCAL software modules.                                       */
/*               The initialization services allow a flexible and application */
/*               related MCU initialization in addition to the start-up code. */
/* Author      : --                                                           */
/* Note        : -                                                            */
/******************************************************************************/
/* Specification of MCU Driver                                                */
/* R22-11                                                                     */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Mcu.h"
 
#if ( MCU_DEV_ERROR_DETECT != FALSE )
#include "Det.h"
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define MCU_70_VENDOR_ID_C                      (70U)
 
#define MCU_70_MODULE_ID_C                      (101U)
 
#define MCU_70_AR_RELEASE_MAJOR_VERSION_C       (22U)
#define MCU_70_AR_RELEASE_MINOR_VERSION_C       (11U)
#define MCU_70_AR_RELEASE_REVISION_VERSION_C    (0U)
 
#define MCU_70_SW_MAJOR_VERSION_C               (1U)
#define MCU_70_SW_MINOR_VERSION_C               (0U)
#define MCU_70_SW_PATCH_VERSION_C               (0U)
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Mcu.h version check start */
#if ( MCU_70_VENDOR_ID_C != MCU_VENDOR_ID )
    #error "Mcu.c and Mcu.h have different vendor ids"
#endif
 
#if ( MCU_70_MODULE_ID_C != MCU_MODULE_ID )
    #error "Mcu.c and Mcu.h have different module ids"
#endif
 
#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION ) || \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION ) || \
      ( MCU_70_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Mcu.c and Mcu.h are different"
#endif
 
#if ( ( MCU_70_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION ) || \
      ( MCU_70_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION ) || \
      ( MCU_70_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION ) )
    #error "Software Version Numbers of Mcu.c and Mcu.h are different"
#endif
/* Mcu.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
#if ( MCU_DEV_ERROR_DETECT != FALSE )
/* Check if header file and DET header file are of the same Software version */
#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION ) || \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION ) )
    #error "AUTOSAR Version Numbers of Mcu.c and Det.h are different"
#endif
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* extern variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_VAR_INIT_LOCAL_8
#include "Mcu_MemMap.h"
 
#if ( MCU_DEV_ERROR_DETECT != FALSE )
static Mcu_70_ModuleStateType s_McuInitState = MCU_70_STATE_UNINITIALIZED;
#endif
 
#define MCU_STOP_SEC_VAR_INIT_LOCAL_8
#include "Mcu_MemMap.h"
 
#if ( MCU_INIT_CLOCK != FALSE )
 
#define MCU_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Mcu_MemMap.h"
 
static const Mcu_ClockSettingConfigType* s_ClockSetCfgPtr = NULL_PTR;  /* clock setting pointer */
 
#define MCU_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Mcu_MemMap.h"
#endif /* #if ( MCU_INIT_CLOCK != FALSE ) */
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Mcu_MemMap.h"
 
static const Mcu_ConfigType* s_Mcu_ConfigPtr = NULL_PTR;
 
#define MCU_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Mcu_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : MCU_INIT_ID ( 0x00 )                                         */
/* Name        : Mcu_Init                                                     */
/* Param       : (in) ConfigPtr     Pointer to the configuration set in       */
/*                                  VARIANT-POST-BUILD.                       */
/* Return      : None                                                         */
/* Contents    : Initializes or reinitializes this module.                    */
/* Author      : --                                                           */
/* Note        : [SWS_Mcu_00153]                                              */
/******************************************************************************/
void Mcu_Init( const Mcu_ConfigType* ConfigPtr )
{
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    Std_ReturnType rtn;
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    if ( NULL_PTR == ConfigPtr ) {    /* Mcu config is equal to NULL */
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_INIT_ID, ( uint8 )MCU_E_PARAM_CONFIG );    /* error report */
        return;
    }
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    rtn = Mcu_70_HW_Init( ConfigPtr );    /* H/W dependent function */
 
    if ( E_NOT_OK == rtn ) {    /* Mcu initialization failed, error report. */
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                                 ( uint8 )MCU_INIT_ID, ( uint8 )MCU_E_INIT_FAILED );
        return;
    }
#else
    ( void )Mcu_70_HW_Init( ConfigPtr );    /* H/W dependent function */
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
#if ( MCU_INIT_CLOCK != FALSE )
    /* clear clock setting pointer */
    s_ClockSetCfgPtr = NULL_PTR;
#endif /* #if ( MCU_INIT_CLOCK != FALSE ) */
 
    s_Mcu_ConfigPtr = ConfigPtr;      /* save MCU configuration data */
 
    /* MCU module initialization state to initialized */
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    s_McuInitState = MCU_70_STATE_INITIALIZED;
#endif
}
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : MCU_INITRAMSECTION_ID ( 0x01 )                               */
/* Name        : Mcu_InitRamSection                                           */
/* Param       : (in) RamSection  initialization RAM section No.              */
/* Return      : E_OK      successful initialization RAM section.             */
/*               E_NOT_OK  RAM section initialization failed.                 */
/* Contents    : MCU Init Ram Section processing                              */
/* Author      : --                                                           */
/* Note        : [SWS_Mcu_00154]                                              */
/******************************************************************************/
Std_ReturnType Mcu_InitRamSection( Mcu_RamSectionType RamSection )
{
    Std_ReturnType rtn = E_OK;                   /* return value       */
    uint8* ptronebyte;                           /* initial start address */
    uint16* ptrtwobyte;                          /* initial start address */
    uint8 defaultValonebyte;                     /* initial value      */
    uint16 defaultValtwobyte;                    /* initial value      */
    uint32 sectSize;                             /* initial area size  */
    uint8 sectWriteSize;                         /* initial write size  */
    uint8 noofbytewritten;                       /* the size in bytes of data which can be written into RAM at once. */
    const Mcu_RamSectorSettingConfType* confPtr; /* Ram section setting configuration pointer. */
 
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Mcu_00136] */
    if ( MCU_70_STATE_INITIALIZED != s_McuInitState ) {    /* MCU initialization status */
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_INITRAMSECTION_ID, ( uint8 )MCU_E_UNINIT );    /* error report */
        rtn = E_NOT_OK;
        return ( rtn );
    }
    /* [SWS_Mcu_00021] */
    if ( s_Mcu_ConfigPtr->McuModuleConfiguration.McuRamSectors <= RamSection ) {    /* MCU initialization status */
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_INITRAMSECTION_ID, ( uint8 )MCU_E_PARAM_RAMSECTION );    /* error report */
        rtn = E_NOT_OK;
        return ( rtn );
    }
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
    /* [SWS_Mcu_00011] */
    confPtr = &( s_Mcu_ConfigPtr->McuModuleConfiguration.McuRamSectorSettingConfPtr[RamSection] );
    sectWriteSize = ( uint8 )( confPtr->McuRamSectionWriteSize );  /* Get Ram Section Write Size. */
    sectSize = confPtr->McuRamSectionSize;           /* Get Ram Section Size. */
 
    switch ( sectWriteSize ) {
    case MCU_8BIT_SIZE:
        ptronebyte = confPtr->McuRamSectionBaseAddress;        /* Get Ram Section Base Address.  */
        defaultValonebyte = confPtr->McuRamDefaultValue;       /* Get Ram Section Set Default Value. */
        noofbytewritten = 1U;
 
        if ( 1UL > sectSize ) {
            rtn = E_NOT_OK;
        }
        break;
    case MCU_16BIT_SIZE:
        /* Cast for CC-RL warning */
        ptrtwobyte = ( uint16* )( ( void* ) ( confPtr->McuRamSectionBaseAddress ) );   /* Get Ram Section Base Address.  */
        /* Get Ram Section Set Default Value. */
        defaultValtwobyte = ( ( uint16 )( confPtr->McuRamDefaultValue ) << 8U ) |
                                                        confPtr->McuRamDefaultValue;
        noofbytewritten = 2U;
 
        if ( ( 2UL > sectSize ) || ( 0UL != ( sectSize % noofbytewritten ) ) ) {
            rtn = E_NOT_OK;
        }
        break;
    default:
        rtn = E_NOT_OK;
        break;
    }
 
    if ( E_OK == rtn ) {
        while ( 0UL != sectSize ) {
            switch ( sectWriteSize ) {
            case MCU_8BIT_SIZE:
                /* Initialize RAM area with the value */
                if ( NULL_PTR != ptronebyte ) {
                    *ptronebyte = defaultValonebyte;
                    ptronebyte = &( ptronebyte[1U] );
                }
                break;
            case MCU_16BIT_SIZE:
                /* Initialize RAM area with the value */
                if ( NULL_PTR != ptrtwobyte ) {
                    *ptrtwobyte = defaultValtwobyte;
                    ptrtwobyte = &( ptrtwobyte[1U] );
                }
                break;
            default:
                /* DO NOTHING */
                break;
            }
 
            /* Decrement the size */
            sectSize = sectSize - ( uint32 )( noofbytewritten );
        }
    }
 
    return ( rtn );
}
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : MCU_INITCLOCK_ID ( 0x02 )                                    */
/* Name        : Mcu_InitClock                                                */
/* Param       : (in) ClockSetting  clock setting type.                       */
/* Return      : E_OK      successful initialization clock.                   */
/*               E_NOT_OK  clock initialization failed.                       */
/* Contents    : Initializes the PLL and other MCU specific clock options     */
/* Author      : --                                                           */
/* Note        : [SWS_Mcu_00155]                                              */
/******************************************************************************/
#if ( MCU_INIT_CLOCK != FALSE )
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting )
{
    Std_ReturnType rtn = E_NOT_OK;
 
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Mcu_00139] */
    if ( MCU_70_STATE_INITIALIZED != s_McuInitState ) {    /* MCU initialization status */
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_INITCLOCK_ID, ( uint8 )MCU_E_UNINIT );    /* error report */
        return ( rtn );
    }
 
    /* [SWS_Mcu_00019] */
    /* Check configuration clock ID */
    if ( MCU_70_CLOCK_TYPE_NUM <= ClockSetting ) {
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_INITCLOCK_ID, ( uint8 )MCU_E_PARAM_CLOCK );    /* error report */
        return ( rtn );
    }
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
    /* [SWS_Mcu_00248] */
    /* [SWS_Mcu_00165] */
    /* [SWS_Mcu_00137] */
    /* [ECUC_Mcu_00124] */
    /* select specified clock setting data */
    s_ClockSetCfgPtr = &( s_Mcu_ConfigPtr->McuModuleConfiguration.McuClockSettingConfigPtr[ClockSetting] );
 
    /* clock initialize */
    rtn = Mcu_70_HW_InitClock( s_ClockSetCfgPtr );
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    if ( E_NOT_OK == rtn ) {
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_INITCLOCK_ID, ( uint8 )MCU_E_70_PLL_FAIL );    /* error report */
    }
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
    return ( rtn );
}
#endif /* #if ( MCU_INIT_CLOCK != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : MCU_DISTRIBUTEPLLCLOCK_ID(0x03)                              */
/* Name        : Mcu_DistributePllClock                                       */
/* Param       : None                                                         */
/* Return      : E_OK       successful distribution PLL clock.                */
/*               E_NOT_OK   PLL clock distribution failed.                    */
/* Contents    : Activates the PLL clock to the MCU clock distribution        */
/* Author      : --                                                           */
/* Note        : [SWS_Mcu_00156]                                              */
/******************************************************************************/
#if ( MCU_NO_PLL == FALSE )
Std_ReturnType Mcu_DistributePllClock( void )
{
    Std_ReturnType       rtn;       /* no initial value for MISRA2012 Rule-2.2 */
    /* for check PLL is lock or not */
    Mcu_PllStatusType    pllSts;    /* no initial value for MISRA2012 Rule-2.2 */
 
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    if ( MCU_70_STATE_INITIALIZED != s_McuInitState ) {    /* MCU initialization status */
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_DISTRIBUTEPLLCLOCK_ID, ( uint8 )MCU_E_UNINIT );    /* error report */
        rtn = E_NOT_OK;
        return ( rtn );
    }
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
    /* Do not check the lock of the PLL with the following SWS. */
    /* [SWS_Mcu_00141] */
    /* The function Mcu_DistributePllClock shall remove the
     * current clock source (for example internal oscillator clock) from MCU
     * clock distribution.
     * The MCU module's environment shall only call the function
     * Mcu_DistributePllClock after the status of the PLL has been detected as
     * locked by the function Mcu_GetPllStatus.
     */
 
    pllSts = Mcu_70_HW_GetPllStatus();
    if ( MCU_PLL_LOCKED != pllSts ) {    /* check PLL status */
#if ( MCU_DEV_ERROR_DETECT != FALSE )
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_DISTRIBUTEPLLCLOCK_ID, ( uint8 )MCU_E_PLL_NOT_LOCKED );    /* error report */
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE )  */
        rtn = E_NOT_OK;
        return ( rtn );
    }
 
    /* distribute pll clock*/
    rtn = Mcu_70_HW_DistributePllClock();
    /* PLL not lock Dem Event report MCU_E_CLOCK_FAILURE  */
#if ( MCU_70_DEM_SET_EVENT_STATUS != FALSE )
        if ( E_NOT_OK == rtn ) {
            ( void )Dem_SetEventStatus( MCU_E_CLOCK_FAILURE,
                                ( Dem_EventStatusType )DEM_EVENT_STATUS_FAILED );
        } else {
            ( void )Dem_SetEventStatus( MCU_E_CLOCK_FAILURE,
                                ( Dem_EventStatusType )DEM_EVENT_STATUS_PASSED );
        }
#endif /* #if ( MCU_70_DEM_SET_EVENT_STATUS != FALSE ) */
    return ( rtn );
}
#endif /* #if ( MCU_NO_PLL == FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : MCU_GETPLLSTATUS_ID(0x04)                                    */
/* Name        : Mcu_GetPllStatus                                             */
/* Param       : None                                                         */
/* Return      : MCU_PLL_LOCKED             PLL is locked                     */
/*               MCU_PLL_UNLOCKED           PLL is unlocked                   */
/*               MCU_PLL_STATUS_UNDEFINED   PLL Status is unknown             */
/* Contents    : Provide the lock status of the PLL                           */
/* Author      : --                                                           */
/* Note        : [SWS_Mcu_00157]                                              */
/******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus( void )
{
    Mcu_PllStatusType    pllStatus = MCU_PLL_STATUS_UNDEFINED;
 
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    if ( MCU_70_STATE_INITIALIZED != s_McuInitState ) {    /* MCU initialization status */
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_GETPLLSTATUS_ID, ( uint8 )MCU_E_UNINIT );    /* error report */
        return ( pllStatus );
    }
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
#if ( MCU_NO_PLL == FALSE )
    /* Get Pll status */
    pllStatus = Mcu_70_HW_GetPllStatus();
#endif /* #if ( MCU_NO_PLL == FALSE ) */
 
    return ( pllStatus );
}
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : MCU_GETRESETREASON_ID(0x05)                                  */
/* Name        : Mcu_GetResetReason                                           */
/* Param       : None                                                         */
/* Return      : MCU_POWER_ON_RESET    Power On Reset                         */
/*               MCU_WATCHDOG_RESET    Watchdog Timer underflows              */
/*               MCU_SW_RESET          Software Reset                         */
/*               MCU_RESET_UNDEFINED   Reset is undefined                     */
/* Contents    : Read the reset type from the hardware                        */
/* Author      : --                                                           */
/* Note        : [SWS_Mcu_00158]                                              */
/******************************************************************************/
Mcu_ResetType Mcu_GetResetReason( void )
{
    Mcu_ResetType resetType;    /* no initial value for MISRA2012 Rule-2.2 */
 
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    if ( MCU_70_STATE_INITIALIZED != s_McuInitState ) {    /* MCU initialization status */
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_GETRESETREASON_ID, ( uint8 )MCU_E_UNINIT );    /* error report */
        resetType = MCU_RESET_UNDEFINED;    /* reset undefined [SWS_Mcu_00133] */
        return ( resetType );
    }
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
    resetType = Mcu_70_HW_GetResetReason();
 
    return ( resetType );
}
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID ( 101 )                                        */
/* ServiceID   : MCU_GETRESETRAWVALUE_ID( 0x06 )                              */
/* Name        : Mcu_GetResetRawValue                                         */
/* Param       : None                                                         */
/* Return      : MCU_70_HW_RAW_RESET_UNDEFINED   no reset value.              */
/*               Other                           Reset value.                 */
/* Contents    : Read the reset type from the hardware register               */
/* Author      : --                                                           */
/* Note        : [SWS_Mcu_00159]                                              */
/******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue( void )
{
    /* [SWS_Mcu_00006] */
    Mcu_RawResetType rawReset;  /* no initial value for MISRA2012 Rule-2.2 */
 
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    if ( MCU_70_STATE_INITIALIZED != s_McuInitState ) { /* MCU initialization status */
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_GETRESETRAWVALUE_ID, ( uint8 )MCU_E_UNINIT );    /* error report */
        /* [SWS_Mcu_00135] */
        rawReset = MCU_70_HW_RAW_RESET_UNDEFINED;    /* no reset status register or uninitialized */
        return ( rawReset );
    }
 
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
    rawReset = Mcu_70_HW_GetResetRawValue();
 
    return ( rawReset );
}
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : MCU_PERFORM_RESET_ID(0x07)                                   */
/* Name        : Mcu_PerformReset                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Perform a micro controller reset.                            */
/* Author      : --                                                           */
/* Note        : [SWS_Mcu_00160]                                              */
/******************************************************************************/
#if ( MCU_PERFORM_RESET_API != FALSE )
void Mcu_PerformReset( void )
{
 
}
#endif /* #if ( MCU_PERFORM_RESET_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : MCU_SETMODE_ID(0x08)                                         */
/* Name        : Mcu_SetMode                                                  */
/* Param       : (in) McuMode     select CPU set mode.                        */
/* Return      : None                                                         */
/* Contents    : Activate the MCU power modes                                 */
/* Author      : --                                                           */
/* Note        : [SWS_Mcu_00161]                                              */
/******************************************************************************/
void Mcu_SetMode( Mcu_ModeType McuMode )
{
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Mcu_00148] */
    if ( MCU_70_STATE_INITIALIZED != s_McuInitState ) {    /* MCU initialization status */
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_SETMODE_ID, ( uint8 )MCU_E_UNINIT );    /* error report */
        return;
    }
    /* [SWS_Mcu_00020] */
    if ( s_Mcu_ConfigPtr->McuModuleConfiguration.McuNumberOfMcuModes <= McuMode ) {
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_SETMODE_ID, ( uint8 )MCU_E_PARAM_MODE );    /* error report */
        return;
    }
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE )*/
 
    /* [SWS_Mcu_00147] */
    /* [SRS_Mcu_12421] */
    /* [SWS_Mcu_00164] */
    /* Note:  *1 No need susupend/resume interrupt, because disable interrupt by EcuM before call Mcu_SetMode() */
    Mcu_70_HW_SetMode( McuMode );
}
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : MCU_GETVERSIONINFO_ID(0x09)                                  */
/* Name        : Mcu_GetVersionInfo                                           */
/* Param       : (out) versioninfo   set version info pointer.                */
/* Return      : None                                                         */
/* Contents    : Return the version information of this module                */
/* Author      : --                                                           */
/* Note        : [SWS_Mcu_00162]                                              */
/******************************************************************************/
#if ( MCU_VERSION_INFO_API != FALSE )
void Mcu_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    if ( NULL_PTR == versioninfo ) {
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_GETVERSIONINFO_ID, ( uint8 )MCU_E_PARAM_POINTER );    /* error report */
        return;
    }
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
    /* get the version information */
    versioninfo->vendorID         = MCU_VENDOR_ID;
    versioninfo->moduleID         = MCU_MODULE_ID;
    versioninfo->sw_major_version = MCU_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = MCU_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = MCU_SW_PATCH_VERSION;
}
#endif /* #if ( MCU_VERSION_INFO_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : MCU_GETRAMSTATE_ID(0x0a)                                     */
/* Name        : Mcu_GetRamState                                              */
/* Param       : None                                                         */
/* Return      : MCU_RAMSTATE_VALID    RAM state valid.                       */
/*               MCU_RAMSTATE_INVALID  RAM state invalid.                     */
/* Contents    : Provide the actual status of the microcontroller RAM         */
/* Author      : --                                                           */
/* Note        : [SWS_Mcu_00207]                                              */
/******************************************************************************/
#if ( MCU_GET_RAM_STATE_API !=  FALSE )
Mcu_RamStateType Mcu_GetRamState( void )
{
    /* when does not support the RAM state register */
    Mcu_RamStateType ramState = MCU_RAMSTATE_INVALID;
    Std_ReturnType   ret;   /* no initial value for MISRA2012 Rule-2.2 */
 
#if ( MCU_DEV_ERROR_DETECT != FALSE )
    if ( MCU_70_STATE_INITIALIZED != s_McuInitState ) {    /* MCU initialization status */
        ( void )Det_ReportError( ( uint16 )MCU_MODULE_ID, ( uint8 )MCU_70_INSTANCE_ID,
                    ( uint8 )MCU_GETRAMSTATE_ID, ( uint8 )MCU_E_UNINIT );    /* error report */
        ramState = MCU_RAMSTATE_INVALID;    /* setting the return value is equal to MCU_RAMSTATE_INVALID */
        return ( ramState );
    }
#endif /* #if ( MCU_DEV_ERROR_DETECT != FALSE ) */
 
    ret = Mcu_70_HW_GetRamState();
    if ( E_OK == ret ){
        ramState = MCU_RAMSTATE_VALID;
    }
    return ( ramState );
}
#endif /* #if ( MCU_GET_RAM_STATE_API != FALSE ) */
 
#define MCU_STOP_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"
 
/* EOF Mcu.c ******************************************************************/