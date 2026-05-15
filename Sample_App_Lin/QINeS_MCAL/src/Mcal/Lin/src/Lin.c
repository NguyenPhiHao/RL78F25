/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Lin.h                                                        */
/* Version     : v1.00.02                                                     */
/* Contents    : LIN  Module API Header                                       */
/*               The file contains extern decelerations of AUTOSAR APIs and   */
/*               Macros used for configurations as per AUTOSAR.               */
/*               The LIN is a basic software module at the service layer      */
/*               of the standardized basic software architecture of AUTOSAR.  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Lin.h"
#if ( LIN_70_DEM_REPORT_ERROR_STATUS != FALSE )
#include "Dem.h"
#endif
#if ( LIN_DEV_ERROR_DETECT != FALSE )
#include "Det.h"
#endif /* LIN_DEV_ERROR_DETECT != FALSE */
#include "SchM_Lin.h"
#include "LinIf.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_70_VENDOR_ID_C                   ( 70U )
#define LIN_70_MODULE_ID_C                   ( 82U )
 
#define LIN_70_AR_RELEASE_MAJOR_VERSION_C    ( 22U )
#define LIN_70_AR_RELEASE_MINOR_VERSION_C    ( 11U )
#define LIN_70_AR_RELEASE_REVISION_VERSION_C ( 0U )
 
#define LIN_70_SW_MAJOR_VERSION_C            ( 1U )
#define LIN_70_SW_MINOR_VERSION_C            ( 0U )
#define LIN_70_SW_PATCH_VERSION_C            ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/*---------------Lin.h -------------------------------------------------------*/
/* Check if current file and Lin.h header file are of the same Vendor ID */
#if (LIN_70_VENDOR_ID_C    != LIN_VENDOR_ID)
    #error "Vendor ID of Lin.c and Lin.h are different"
#endif
 
#if (LIN_70_MODULE_ID_C    != LIN_MODULE_ID)
    #error "Module ID of Lin.c and Lin.h are different"
#endif
 
/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_70_SW_MAJOR_VERSION_C    != LIN_SW_MAJOR_VERSION) ||\
     (LIN_70_SW_MINOR_VERSION_C    != LIN_SW_MINOR_VERSION) ||\
     (LIN_70_SW_PATCH_VERSION_C    != LIN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lin.c and Lin.h are different"
#endif
 
/* Check if current file and Lin.h header file are of the same Autosar version */
#if ((LIN_70_AR_RELEASE_MAJOR_VERSION_C    != LIN_AR_RELEASE_MAJOR_VERSION)   ||\
     (LIN_70_AR_RELEASE_MINOR_VERSION_C    != LIN_AR_RELEASE_MINOR_VERSION)   ||\
     (LIN_70_AR_RELEASE_REVISION_VERSION_C != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lin.c and Lin.h are different"
#endif
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/*---------------EcuM_Cbk.h --------------------------------------------------*/
/* Check if current file and Lin_70_HW.h header file are of the same Autosar version */
#if ((LIN_70_AR_RELEASE_MAJOR_VERSION_C    != ECUM_AR_RELEASE_MAJOR_VERSION_CBK_H)   ||\
     (LIN_70_AR_RELEASE_MINOR_VERSION_C    != ECUM_AR_RELEASE_MINOR_VERSION_CBK_H))
    #error "AutoSar Version Numbers of Lin.c and Dem.h are different"
#endif
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/*---------------Det.h -------------------------------------------------------*/
#if ( LIN_DEV_ERROR_DETECT != FALSE )
/* Check if current file and Lin_70_HW.h header file are of the same Autosar version */
#if ((LIN_70_AR_RELEASE_MAJOR_VERSION_C    != DET_AR_RELEASE_MAJOR_VERSION)   ||\
     (LIN_70_AR_RELEASE_MINOR_VERSION_C    != DET_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lin.c and Det.h are different"
#endif
#endif
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
#if ( LIN_70_DEM_REPORT_ERROR_STATUS != FALSE )
/*---------------Dem.h -------------------------------------------------------*/
/* Check if current file and Lin_70_HW.h header file are of the same Autosar version */
#if ( (LIN_70_AR_RELEASE_MAJOR_VERSION_C    != DEM_AR_RELEASE_MAJOR_VERSION)   ||\
      (LIN_70_AR_RELEASE_MINOR_VERSION_C    != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lin.c and Dem.h are different"
#endif
#endif
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/*---------------SchM_Lin.h -------------------------------------------------------*/
/* Check if current file and SchM_Lin.h are of the same Software version */
#if ( (LIN_70_AR_RELEASE_MAJOR_VERSION_C    != RTE_AR_RELEASE_MAJOR_VERSION) ||\
      (LIN_70_AR_RELEASE_MINOR_VERSION_C    != RTE_AR_RELEASE_MINOR_VERSION))
    #error "Software Version Numbers of Lin.c and SchM_Lin.h are different"
#endif
#endif /* ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define LIN_START_SEC_CODE_LOCAL
#include "Lin_MemMap.h"
 
/* Function to stop the ongoing/pending frames */
static void lin_stopFrame( void );
 
#define LIN_STOP_SEC_CODE_LOCAL
#include "Lin_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/*** LCUCn ***/
/* To cancel Lin reset mode OM0(0) */
#define LIN_70_CANCEL_RESET_MODE         (  0x01U )
/* To set Lin Operation mode bit OM1(1) */
#define LIN_70_SET_OPERATIONAL_MODE      (  0x02U )
 
/* Bit settings for configuring the LIN Data Field Configuration Register */
/* RFT(4) */
#define LIN_70_SET_TRANSMISSION_MODE     ( 0x10U )
/* CSM(5) */
#define LIN_70_SET_ENHANCED_CSM          ( 0x20U )
/* FSM(6) */
#define LIN_70_SET_SEPARATE_MODE         ( 0x40U )
/* To set the LIN Operational mode bit and LIN Cancel Reset mode bit */
#define LIN_70_OPERATIONAL_MODE          ( 0x03U )
#define LIN_70_WAKEUP_MODE               ( LIN_70_CANCEL_RESET_MODE )
 
#define LIN_70_FRAME_BUFF_LENGTH         ( 8U )
 
/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
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
#define LIN_START_SEC_VAR_NO_INIT_GLOBAL_UNSPECIFIED
#include "Lin_MemMap.h"
 
Lin_70_ChannelStatusType  s_Lin_Status[LIN_70_NUM_OF_CHANNEL];
 
#define LIN_STOP_SEC_VAR_NO_INIT_GLOBAL_UNSPECIFIED
#include "Lin_MemMap.h"
 
#define LIN_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Lin_MemMap.h"
 
static Lin_70_DriverStatusType  s_Lin_DriverStatus = LIN_UNINIT;
static uint8                    s_LinFrameReceiveBuffer[LIN_70_FRAME_BUFF_LENGTH] = { 0U };
const Lin_ConfigType*           s_Lin_Config = NULL_PTR;
 
#define LIN_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Lin_MemMap.h"
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define LIN_START_SEC_CODE_LOCAL
#include "Lin_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : lin_stopFrame                                                */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Stop LIN frame transmit.                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void lin_stopFrame( void )
{
    Std_ReturnType result;
    uint8 mode;
 
    mode = Lin_70_HW_ReadModeStatusReg();
 
    /* Set the Lin operational bit and reset the Lin reset mode bit */
    mode &= (uint8)LIN_70_SET_OPERATIONAL_MODE;
 
    /* Call function to change the channel mode */
    result = lin_chModeChange( mode );
 
    /* Set the Lin reset mode bit for transition to operational mode */
    if ( E_OK == result ) {
        mode |= (uint8)LIN_70_CANCEL_RESET_MODE;
 
        /* Call function to change the channel mode */
        (void)lin_chModeChange( mode);
    }
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : lin_chModeChange                                             */
/* Param       : mode: Requested Mode (LCUC register vaule)                   */
/* Return      : Std_ReturnType     E_OK: mode transition success             */
/*                                  E_NOT_OK: mode transition failure         */
/* Contents    : change Lin channel mode                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType lin_chModeChange( uint8 mode )
{
    Std_ReturnType  result;
 
    /* Call the Hw function to enable the changes to take place */
    result = Lin_70_HW_ModeChange( mode, LIN_TIMEOUT_DURATION );
 
#if ( LIN_70_DEM_REPORT_ERROR_STATUS != FALSE )
    /* [SWS_Lin_00234] Check for hardware error detection (LIN_E_TIMEOUT) */
    /*    and DEM event id configured or not                              */
    if ( E_OK != result ) {
        /* [SWS_Lin_00058] Report error code LIN_E_TIMEOUT */
        ( void )Dem_SetEventStatus(( Dem_EventIdType )Lin_DemEventParameterRefs.LinEventId[0].id,
                              ( Dem_EventStatusType )Lin_DemEventParameterRefs.LinEventId[0].state);
    }
#endif /* #if ( LIN_70_DEM_REPORT_ERROR_STATUS != FALSE ) */
 
    return result;
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_INIT_ID (0x00)                                           */
/* Name        : Lin_Init                                                     */
/* Param       : (in) Config     Pointer to LIN driver configuration set.     */
/* Return      : void                                                         */
/* Contents    : Initializes the LIN module.                                  */
/* Author      : --                                                           */
/* Note        : [SWS_Lin_00006]                                              */
/*----------------------------------------------------------------------------*/
void Lin_Init( const Lin_ConfigType* Config )
{
    /* [SWS_Lin_00084] */
    /* Initialize static variables, flags, Lin Hw unit settings */
    uint8           chIndex;
    uint8           initStat = (uint8)TRUE;
    Std_ReturnType  result;
 
#if ( LIN_DEV_ERROR_DETECT != FALSE )
    if ( (const Lin_ConfigType*)NULL_PTR == Config ) {
        /* [SWS_Lin_00099] */
        /* Config has an invalid value report error code LIN_E_INVALID_POINTER */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX, ( uint8 )  LIN_INIT_ID,   ( uint8 ) LIN_E_INVALID_POINTER );
        initStat = (uint8)FALSE;
    } else if ( LIN_UNINIT != s_Lin_DriverStatus ) {
        /* [SWS_Lin_00105] */
        /* Lin Driver is not in Uninit state report error code LIN_E_STATE_TRANSITION */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX, ( uint8 ) LIN_INIT_ID,    ( uint8 ) LIN_E_STATE_TRANSITION );
        initStat = (uint8)FALSE;
    } else {
        for( chIndex = (uint8)0; chIndex< (uint8)LIN_70_NUM_OF_CHANNEL; chIndex++ ) {
            /* checking config prameter */
            if ( Config->Lin_GlobalConfig->LinChannel[chIndex].LinNodeType == LIN_70_MASTER )  {/* Master node */
                /* baud rate is 0 */
                if (  Config->Lin_GlobalConfig->LinChannel[chIndex].LinChannelBaudRate == 0U ) {
                    ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX, ( uint8 ) LIN_INIT_ID,    ( uint8 ) LIN_70_E_INIT_FAILED );
                    initStat = (uint8)FALSE;
                    break;
                }
            }
        }
    }
 
#endif /* #if ( LIN_DEV_ERROR_DETECT != FALSE ) */
    if ( TRUE == initStat ) {
        /* save config pointer */
        Lin_70_HW_SetConfigPtr( Config );
 
        for ( chIndex = 0x0U; chIndex < (uint8)LIN_70_NUM_OF_CHANNEL; chIndex++ ) {
            /* Change channel. */
            Lin_70_HW_ChangeChannel( (uint8)Config->Lin_GlobalConfig->LinChannel[chIndex].LinChannelId );
 
            /* [SWS_Lin_00084] [SWS_Lin_00008] [SWS_Lin_00190] */
            /* Initialize lin hardware registers */
            Lin_70_HW_Init( chIndex );
 
            /* Call function to change the channel mode */
            result = lin_chModeChange( (uint8)LIN_70_OPERATIONAL_MODE );
 
            /* Check if mode transition result was ok */
            if ( E_OK == result ) {
                /* Set to Lin parameters */
                Lin_70_HW_InitParameter( chIndex );
            } else {
                initStat = (uint8)FALSE;
                break;
            }
        }
    }
    /* if Init is TRUE, Lin driver mode is LIN_INIT. */
    if ( (uint8)TRUE == initStat ) {
        s_Lin_DriverStatus = LIN_INIT;
    }
}
 
#if ( LIN_CHANNEL_WAKE_UP_SUPPORT != FALSE )
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_CHECKWAKEUP_ID (0x0A)                                    */
/* Name        : Lin_CheckWakeup                                              */
/* Param       : (in) Channel       LIN channel to be addressed.              */
/* Return      : Std_ReturnType     E_OK: No error has occurred during        */
/*                                  execution of the API                      */
/*                                  E_NOT_OK: An error has occurred during    */
/*                                  execution of the API                      */
/* Contents    : This function checks if a wakeup has occurred on the         */
/*               addressed LIN channel.                                       */
/* Author      : --                                                           */
/* Note        : [SWS_Lin_00160]                                              */
/*----------------------------------------------------------------------------*/
Std_ReturnType Lin_CheckWakeup( uint8 Channel )
{
    Std_ReturnType          result;
    const Lin_ChannelType*  ptrLinChannel;
    uint8                   chIndex = (uint8)LIN_70_NUM_OF_CHANNEL;
 
    result = Lin_searchChIndex( Channel, &chIndex );
 
#if ( LIN_DEV_ERROR_DETECT != FALSE )
    if ( result != E_OK) {
        /* [SWS_Lin_00251] Channel has an invalid value report error code LIN_E_INVALID_CHANNEL */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_CHECKWAKEUP_ID, ( uint8 ) LIN_E_INVALID_CHANNEL );
        return result;
    }
#endif /* #if ( LIN_DEV_ERROR_DETECT != FALSE ) */
 
    ptrLinChannel = &s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex];
 
#if ( LIN_DEV_ERROR_DETECT != FALSE )
    if ( LIN_INIT != s_Lin_DriverStatus ) {
        /* [SWS_Lin_00107] Lin Driver is not initialized report error code LIN_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_CHECKWAKEUP_ID, ( uint8 ) LIN_E_UNINIT );
    } else if ( LIN_CH_SLEEP != s_Lin_Status[chIndex].ChannelStatus ) { /* Lin Channel is in Sleep state */
            ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                      ( uint8 ) LIN_CHECKWAKEUP_ID, ( uint8 ) LIN_E_STATE_TRANSITION );
    } else
#endif /* #if ( LIN_DEV_ERROR_DETECT != FALSE ) */
    {
 
        /* [SWS_Lin_00098] If wakeup is detected, notify wakeup event to EcuM */
        EcuM_SetWakeupEvent( ptrLinChannel->LinChannelEcuMWakeupSource );
       
        /* [SWS_Lin_00234] after the successful wakeup detection */
        LinIf_WakeupConfirmation( ptrLinChannel->LinChannelEcuMWakeupSource );
 
        if ( ptrLinChannel->LinNodeType ==  LIN_70_MASTER )  { /* Master node */
            if ( FALSE != s_Lin_Status[chIndex].WakeupStatus ) {
                s_Lin_Status[chIndex].ChannelStatus = LIN_CH_OPERATIONAL;
                s_Lin_Status[chIndex].WakeupStatus  = (uint8)FALSE;
            }
        } else
        { /* Slave node */
            if ( FALSE != s_Lin_Status[chIndex].WakeupStatus ) {
                s_Lin_Status[chIndex].ChannelStatus = LIN_CH_OPERATIONAL;
                s_Lin_Status[chIndex].WakeupStatus = (uint8)FALSE;
            }
        }
 
        result = E_OK;
    }
    return result;
}
#endif /* #if ( LIN_CHANNEL_WAKE_UP_SUPPORT != FALSE ) */
 
#if ( LIN_VERSION_INFO_API != FALSE )
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_GETVERSIONINFO_ID (0x01)                                 */
/* Name        : Lin_GetVersionInfo                                           */
/* Param       : (out) versioninfo  Pointer to where to store the version     */
/*                                  information of this module.               */
/* Return      : void                                                         */
/* Contents    : Returns the version information of this module.              */
/* Author      : --                                                           */
/* Note        : [SWS_Lin_00160]                                              */
/*----------------------------------------------------------------------------*/
void Lin_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if ( LIN_DEV_ERROR_DETECT != FALSE )
    /* check if the versioninfo pointer equals to NULL */
    if ( NULL_PTR == versioninfo ) {
        /* Report error code Lin_GetVersionInfo_ID [SWS_Lin_00248] */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_GETVERSIONINFO_ID, ( uint8 ) LIN_E_PARAM_POINTER );
    }
    else
#endif /* #if ( LIN_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Lin version information is defined by macro in the header file */
        versioninfo->vendorID         = ( uint16 )LIN_VENDOR_ID;       /* Vendor ID */
        versioninfo->moduleID         = ( uint16 )LIN_MODULE_ID;       /* Module ID */
        versioninfo->sw_major_version = ( uint8 )LIN_SW_MAJOR_VERSION; /* Software Major Version */
        versioninfo->sw_minor_version = ( uint8 )LIN_SW_MINOR_VERSION; /* Software Minor Version */
        versioninfo->sw_patch_version = ( uint8 )LIN_SW_PATCH_VERSION; /* Software Patch Version */
    }
}
#endif /* #if ( LIN_VERSION_INFO_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_SENDFRAME_ID (0x04)                                      */
/* Name        : Lin_SendFrame                                                */
/* Param       : (in) Channel       LIN channel to be addressed               */
/*                    PduInfoPtr    Pointer to PDU containing the PID,        */
/*                                  checksum model, response type, Dl and SDU */
/*                                  data pointer                              */
/* Return      : Std_ReturnType     E_OK: Send command has been accepted.     */
/*                                  E_NOT_OK: Send command has not been       */
/*                                  accepted, development or production error */
/*                                  occurred.                                 */
/* Contents    : Sends a LIN header and a LIN response, if necessary. The     */
/*               direction of the frame response (master response, slave      */
/*               response, slave-to-slave communication) is provided by the   */
/*               PduInfoPtr.                                                  */
/* Author      : --                                                           */
/* Note        : [SWS_Lin_00191]                                              */
/*               Interrupt enable should be configured according to chapter   */
/*               17.4.1(F24) and chapter 18.4.1(F25) of the hardware manual.  */
/*----------------------------------------------------------------------------*/
Std_ReturnType Lin_SendFrame( uint8 Channel, Lin_PduType* PduInfoPtr )
{
    Std_ReturnType result;
    Lin_FrameDlType frameType;
    uint8                   chIndex = (uint8)LIN_70_NUM_OF_CHANNEL;
    const Lin_ChannelType*  ptrLinChannel;
   
    result = Lin_searchChIndex( Channel, &chIndex );
   
    ptrLinChannel = &s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex];
 
#if ( LIN_DEV_ERROR_DETECT != FALSE )
    if ( result != E_OK ) {
        /* [SWS_Lin_00251] Channel has an invalid value report error code LIN_E_INVALID_CHANNEL */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX, ( uint8 ) LIN_SENDFRAME_ID, ( uint8 ) LIN_E_INVALID_CHANNEL );
        return result;
    }
 
 
    if ( LIN_INIT != s_Lin_DriverStatus ) {
        /* [SWS_Lin_00195] Lin Driver is not already initialized report error code LIN_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX, ( uint8 ) LIN_SENDFRAME_ID, ( uint8 ) LIN_E_UNINIT );
    } else if ( NULL_PTR == PduInfoPtr ) {
        /* [SWS_Lin_00198] PduInfoPtr has an invalid value report error code LIN_E_PARAM_POINTER */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX, ( uint8 ) LIN_SENDFRAME_ID, ( uint8 ) LIN_E_PARAM_POINTER );
    } else if (( LIN_CH_SLEEP == s_Lin_Status[chIndex].ChannelStatus ) ||( LIN_CH_SLEEP_PENDING == s_Lin_Status[chIndex].ChannelStatus )  ) {
        /* [SWS_Lin_00199] Lin Channel is in sleep state report error code LIN_E_STATE_TRANSITION */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX, ( uint8 ) LIN_SENDFRAME_ID, ( uint8 ) LIN_E_STATE_TRANSITION );
    } else
#endif /* #if ( LIN_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Change channel. */
        Lin_70_HW_ChangeChannel( (uint8)ptrLinChannel->LinChannelId );
       
        Lin_70_HW_DisableInterrupts( (uint8)ptrLinChannel->LinChannelId );
 
        /* Abort the current frame transmission if ongoing transmission */
        if (( LIN_TX_BUSY == s_Lin_Status[chIndex].ChannelSubStatus ) ||
            ( LIN_RX_BUSY == s_Lin_Status[chIndex].ChannelSubStatus )) {
            lin_stopFrame( );
        }
 
        /* Frame information configure */
        frameType = (Lin_FrameDlType)PduInfoPtr->Dl;
 
        /* [SWS_Lin_00025] Setup frame identifier and data buffer to be transmitted */
        Lin_70_HW_SetFrameId( PduInfoPtr );
 
        if ( (uint8)LIN_FRAMERESPONSE_TX == (uint8)PduInfoPtr->Drc ) {   /* Master responce */
            /* Set Lin Channel sub status to transmit busy */
            s_Lin_Status[chIndex].ChannelSubStatus = LIN_TX_BUSY;
            /* Frame Transmission and separate mode is set */
            frameType |= (Lin_FrameDlType)(LIN_70_SET_TRANSMISSION_MODE | LIN_70_SET_SEPARATE_MODE);
        } else {                                                        /* Slave responce */
            /* Set Lin Channel sub status to receive busy */
            s_Lin_Status[chIndex].ChannelSubStatus = LIN_RX_BUSY;
        }
 
        /* [SWS_Lin_00014] check for Checksum is "Classic" or "Enhanced" */
        if ( PduInfoPtr->Cs == LIN_ENHANCED_CS ) {
            /* Set the Checksum bit as "Enhanced" */
            frameType |= (Lin_FrameDlType)LIN_70_SET_ENHANCED_CSM;
        }
 
        /* [SWS_Lin_00019] Set Checksum in data field register */
        Lin_70_HW_SetFrameType( (uint8)frameType );
 
        /* [SWS_Lin_00018] [SWS_Lin_00017] change the Lin_FrameStatus to send header first */
        s_Lin_Status[chIndex].FrameStatus = LIN_SEND_HEADER;
 
        /* start frame transmission */
        Lin_70_HW_StartCommunication();
 
        Lin_70_HW_ClearInterrupts( (uint8)ptrLinChannel->LinChannelId );
        Lin_70_HW_EnableInterrupts( (uint8)ptrLinChannel->LinChannelId );
 
        result = E_OK;
    }
    return result;
}
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_GOTOSLEEP_ID (0x06)                                      */
/* Name        : Lin_GoToSleep                                                */
/* Param       : (in) Channel       LIN channel to be addressed               */
/* Return      : Std_ReturnType     E_OK: Sleep command has been accepted     */
/*                                  E_NOT_OK: Sleep command has not been      */
/*                                  accepted, development or production error */
/*                                  occurred                                  */
/* Contents    : The service instructs the driver to transmit a               */
/*               go-to-sleep-command on the addressed LIN channel.            */
/* Author      : --                                                           */
/* Note        : [SWS_Lin_00166]                                              */
/*               Interrupt enable should be configured according to chapter   */
/*               17.4.1(F24) and chapter 18.4.1(F25) of the hardware manual.  */
/*----------------------------------------------------------------------------*/
Std_ReturnType Lin_GoToSleep( uint8 Channel )
{
    Std_ReturnType result;
    uint8                   chIndex = (uint8)LIN_70_NUM_OF_CHANNEL;
    const Lin_ChannelType*  ptrLinChannel;
   
    result = Lin_searchChIndex( Channel, &chIndex );
   
    ptrLinChannel = &s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex];
   
#if ( LIN_DEV_ERROR_DETECT != FALSE )
    if ( result != E_OK ) {
        /* [SWS_Lin_00251] Channel has an invalid value report error code LIN_E_INVALID_CHANNEL */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_GOTOSLEEP_ID, ( uint8 ) LIN_E_INVALID_CHANNEL );
        return result;
    }
 
    if ( LIN_INIT != s_Lin_DriverStatus ) {
        /* [SWS_Lin_00129] Lin Driver is not already initialized report error code LIN_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_GOTOSLEEP_ID, ( uint8 ) LIN_E_UNINIT );
    } else if (( LIN_CH_SLEEP == s_Lin_Status[chIndex].ChannelStatus ) ||
               ( LIN_CH_SLEEP_PENDING == s_Lin_Status[chIndex].ChannelStatus )) {
        /*  Lin Channel status is already Sleep report error code LIN_E_STATE_TRANSITION */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_GOTOSLEEP_ID, ( uint8 ) LIN_E_STATE_TRANSITION );
    } else
#endif /* #if ( LIN_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Change channel. */
        Lin_70_HW_ChangeChannel( (uint8)ptrLinChannel->LinChannelId );
 
        Lin_70_HW_DisableInterrupts( (uint8)ptrLinChannel->LinChannelId );
        /* [SWS_Lin_00074] Abort the current frame transmission if ongoing transmission */
        if (( LIN_TX_BUSY == s_Lin_Status[chIndex].ChannelSubStatus ) ||
            ( LIN_RX_BUSY == s_Lin_Status[chIndex].ChannelSubStatus )) {
            lin_stopFrame( );
        }
 
        /* Set Lin Channel sub status to transmit busy */
        s_Lin_Status[chIndex].ChannelSubStatus = LIN_TX_BUSY;
 
        /* [SWS_Lin_00089] Set data for sleep command in data buffer register */
        Lin_70_HW_GoToSleep();
 
        /* change the Lin_FrameStatus to send header first */
        s_Lin_Status[chIndex].FrameStatus = LIN_SEND_HEADER;
        /*  change the Lin_ChannelOrderedStatus to sleep */
        s_Lin_Status[chIndex].ChannelOrderedStatus = LIN_ORDER_SLEEP;
 
        /* SWS_Lin_00263 */
        s_Lin_Status[chIndex].ChannelStatus = LIN_CH_SLEEP_PENDING;
 
        /* start frame transmission */
        Lin_70_HW_StartCommunication();
 
        Lin_70_HW_ClearInterrupts( (uint8)ptrLinChannel->LinChannelId );
        Lin_70_HW_EnableInterrupts( (uint8)ptrLinChannel->LinChannelId );
 
        result = E_OK;
    }
    return result;
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_GOTOSLEEPINTERNAL_ID (0x09)                              */
/* Name        : Lin_GoToSleepInternal                                        */
/* Param       : (in) Channel       LIN channel to be addressed               */
/* Return      : Std_ReturnType     E_OK: Command has been accepted           */
/*                                  E_NOT_OK: Command has not been accepted,  */
/*                                  development or production error occurred  */
/* Contents    : Sets the channel state to LIN_CH_SLEEP, enables the wake-up  */
/*               detection and optionally sets the LIN hardware unit.         */
/* Author      : --                                                           */
/* Note        : [SWS_Lin_00167]                                              */
/*----------------------------------------------------------------------------*/
Std_ReturnType Lin_GoToSleepInternal( uint8 Channel )
{
    Std_ReturnType result;
    uint8                   chIndex = (uint8)LIN_70_NUM_OF_CHANNEL;
    const Lin_ChannelType*  ptrLinChannel;
 
    result = Lin_searchChIndex( Channel, &chIndex );
   
    ptrLinChannel = &s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex];
   
#if ( LIN_DEV_ERROR_DETECT != FALSE )
    if ( result != E_OK ) {
        /* [SWS_Lin_00251] Channel has an invalid value report error code LIN_E_INVALID_CHANNEL */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_GOTOSLEEPINTERNAL_ID, ( uint8 ) LIN_E_INVALID_CHANNEL );
        return result;
    }
 
    if ( LIN_INIT != s_Lin_DriverStatus ) {
        /* [SWS_Lin_00133]  Lin Driver is not already initialized report error code LIN_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_GOTOSLEEPINTERNAL_ID, ( uint8 ) LIN_E_UNINIT );
    } else if (( LIN_CH_SLEEP == s_Lin_Status[chIndex].ChannelStatus ) ||
                   ( LIN_CH_SLEEP_PENDING == s_Lin_Status[chIndex].ChannelStatus )) {
                /* Channel is in sleep state. Report error code LIN_E_STATE_TRANSITION */
                ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                           ( uint8 ) LIN_GOTOSLEEPINTERNAL_ID, ( uint8 ) LIN_E_STATE_TRANSITION );
    } else
#endif /* #if ( LIN_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Change channel. */
        Lin_70_HW_ChangeChannel( (uint8)ptrLinChannel->LinChannelId  );
 
        Lin_70_HW_DisableInterrupts( (uint8)ptrLinChannel->LinChannelId  );
 
        /* Call function to change the channel mode */
        result = lin_chModeChange( (uint8)LIN_70_WAKEUP_MODE );
        if ( E_OK == result ) {
            /* [SWS_Lin_00095] */
            /* set the channel state to LIN_CH_SLEEP */
            if ( ptrLinChannel->LinNodeType ==  LIN_70_MASTER )  { /* Master node */
                s_Lin_Status[chIndex].ChannelStatus    = LIN_CH_SLEEP;
                s_Lin_Status[chIndex].ChannelSubStatus = LIN_CH_SLEEP;
            } else
            { /* Slave node */
                s_Lin_Status[chIndex].WakeupStatus  = TRUE;
                s_Lin_Status[chIndex].ChannelStatus = LIN_CH_SLEEP;
            }
 
            Lin_70_HW_EnableInterrupts( (uint8)ptrLinChannel->LinChannelId );
        }
    }
    return result;
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_WAKEUP_ID (0x07)                                         */
/* Name        : Lin_Wakeup                                                   */
/* Param       : (in) Channel       LIN channel to be addressed               */
/* Return      : Std_ReturnType     E_OK: Wake-up request has been accepted   */
/*                                  E_NOT_OK: Wake-up request has not been    */
/*                                  accepted, development or production error */
/*                                  occurred                                  */
/* Contents    : Generates a wake up pulse.                                   */
/* Author      : --                                                           */
/* Note        : [SWS_Lin_00169]                                              */
/*               Interrupt enable should be configured according to chapter   */
/*               17.4.1(F24) and chapter 18.4.1(F25) of the hardware manual.  */
/*----------------------------------------------------------------------------*/
Std_ReturnType Lin_Wakeup( uint8 Channel )
{
    Std_ReturnType result;
    uint8                   chIndex = (uint8)LIN_70_NUM_OF_CHANNEL;
    const Lin_ChannelType*  ptrLinChannel;
   
    result = Lin_searchChIndex( Channel, &chIndex );
   
    ptrLinChannel = &s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex];
   
#if ( LIN_DEV_ERROR_DETECT != FALSE )
    if (  result != E_OK) {
        /* [SWS_Lin_00251] Channel has an invalid value report error code LIN_E_INVALID_CHANNEL */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_WAKEUP_ID, ( uint8 ) LIN_E_INVALID_CHANNEL );
        return result;
    }
   
    if ( LIN_INIT != s_Lin_DriverStatus ) {
        /* SWS_Lin_00137  Lin Driver is not already initialized report error code LIN_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                         ( uint8 ) LIN_WAKEUP_ID,  ( uint8 ) LIN_E_UNINIT );
    } else if ( LIN_CH_SLEEP != s_Lin_Status[chIndex].ChannelStatus ) {
        if ( ptrLinChannel->LinNodeType ==  LIN_70_MASTER )  { /* Master node */
            /* [SWS_Lin_00140]  Lin Channel is in sleep state report error code LIN_E_UNINIT */
             ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                       ( uint8 ) LIN_WAKEUP_ID,  ( uint8 ) LIN_E_STATE_TRANSITION );
        }
    } else
#endif /* #if ( LIN_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Change channel. */
        Lin_70_HW_ChangeChannel( (uint8)ptrLinChannel->LinChannelId );
 
        Lin_70_HW_DisableInterrupts( (uint8)ptrLinChannel->LinChannelId );
 
        /* disable wakeup receive */
        lin_stopFrame( );
 
        if ( ptrLinChannel->LinNodeType ==  LIN_70_MASTER )  { /* Master node */
            /* Set Lin Channel sub status to transmit busy */
            s_Lin_Status[chIndex].ChannelSubStatus = LIN_TX_BUSY;
        }
 
        /* [SWS_Lin_00174] Setting operational mode*/
        if ( ptrLinChannel->LinNodeType ==  LIN_70_MASTER )  { /* Master node */
            s_Lin_Status[chIndex].FrameStatus          = LIN_SEND_WAKEUP;
            s_Lin_Status[chIndex].ChannelOrderedStatus = LIN_ORDER_OPERATIONAL;
        } else
        { /* Slave node */
            s_Lin_Status[chIndex].WakeupStatus  = TRUE;
            s_Lin_Status[chIndex].ChannelStatus = LIN_CH_OPERATIONAL;
        }
 
        /* [SWS_Lin_00209] Set Wake-up transmission */
        Lin_70_HW_SetWakeupTransMode();
 
        /* start Wake-up transmission */
        Lin_70_HW_StartCommunication();
 
        Lin_70_HW_ClearInterrupts( (uint8)ptrLinChannel->LinChannelId );
        Lin_70_HW_EnableInterrupts( (uint8)ptrLinChannel->LinChannelId );
 
        result = E_OK;
    }
    return result;
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_WAKEUPINTERNAL_ID (0x0B)                                 */
/* Name        : Lin_WakeupInternal                                           */
/* Param       : (in) Channel       LIN channel to be addressed               */
/* Return      : Std_ReturnType     E_OK: Wake-up request has been accepted   */
/*                                  E_NOT_OK: Wake-up request has not been    */
/*                                  accepted, development or production error */
/*                                  occurred                                  */
/* Contents    : Generates a wake up pulse.                                   */
/* Author      : --                                                           */
/* Note        : [SWS_Lin_00256]                                              */
/*               Interrupt enable should be configured according to chapter   */
/*               17.4.1(F24) and chapter 18.4.1(F25) of the hardware manual.  */
/*----------------------------------------------------------------------------*/
Std_ReturnType Lin_WakeupInternal( uint8 Channel )
{
    Std_ReturnType result;
    uint8                   chIndex = (uint8)LIN_70_NUM_OF_CHANNEL;
    const Lin_ChannelType*  ptrLinChannel;
   
    result = Lin_searchChIndex( Channel, &chIndex );
   
    ptrLinChannel = &s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex];
   
#if ( LIN_DEV_ERROR_DETECT != FALSE )
    if ( result != E_OK ) {
        /* [SWS_Lin_00251] Channel has an invalid value report error code LIN_E_INVALID_CHANNEL */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_WAKEUPINTERNAL_ID, ( uint8 ) LIN_E_INVALID_CHANNEL );
        return result;
    }
 
   
 
    if ( LIN_INIT != s_Lin_DriverStatus ) {
        /* SWS_Lin_00137  Lin Driver is not already initialized report error code LIN_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                         ( uint8 ) LIN_WAKEUPINTERNAL_ID,  ( uint8 ) LIN_E_UNINIT );
    } else if ( LIN_CH_SLEEP != s_Lin_Status[chIndex].ChannelStatus ) {
        if ( ptrLinChannel->LinNodeType ==  LIN_70_MASTER )  { /* Master node */
            /* [SWS_Lin_00260]  Lin Channel is in sleep state report error code LIN_E_UNINIT */
            ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                     ( uint8 ) LIN_WAKEUPINTERNAL_ID,  ( uint8 ) LIN_E_STATE_TRANSITION );
        }
    } else
#endif /* #if ( LIN_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Change channel. */
        Lin_70_HW_ChangeChannel( (uint8)ptrLinChannel->LinChannelId );
 
        Lin_70_HW_DisableInterrupts( (uint8)ptrLinChannel->LinChannelId );
 
        /* disable wakeup receive */
        lin_stopFrame( );
 
        /* [SWS_Lin_00174] Setting operational mode*/
        if ( ptrLinChannel->LinNodeType ==  LIN_70_MASTER )  { /* Master node */
            s_Lin_Status[chIndex].ChannelStatus        = LIN_CH_OPERATIONAL;
            s_Lin_Status[chIndex].ChannelSubStatus     = LIN_CH_OPERATIONAL;
            s_Lin_Status[chIndex].ChannelOrderedStatus = LIN_ORDER_NON;
            s_Lin_Status[chIndex].WakeupStatus         = FALSE;
 
            /* Preparation for sending frame is done with Lin_SendFrame in the master node */
            /* Lin_70_HW_StartCommunication(); */
        } else
        { /* Slave node */
            s_Lin_Status[chIndex].ChannelStatus = LIN_CH_OPERATIONAL;
            s_Lin_Status[chIndex].WakeupStatus  = FALSE;
        }
 
        /* Preparation for frame transmission and wake-up send/receivein the Lin_WakeupInternal function of the slave node */
        Lin_70_HW_StartCommunication();
 
        Lin_70_HW_ClearInterrupts( (uint8)ptrLinChannel->LinChannelId );
        Lin_70_HW_EnableInterrupts( (uint8)ptrLinChannel->LinChannelId );
 
        result = E_OK;
    }
    return result;
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_GETSTATUS_ID (0x08)                                      */
/* Name        : Lin_GetStatus                                                */
/* Param       : (in) Channel       LIN channel to be addressed               */
/*               (out) Lin_SduPtr   Pointer to pointer to a shadow buffer or  */
/*                                  memory mapped LIN Hardware receive buffer */
/*                                  where the current SDU is stored.          */
/* Return      : Lin_StatusType     LIN_NOT_OK: Development or production     */
/*                                  error occurred                            */
/*                                  LIN_TX_OK: Successful transmission        */
/*                                  LIN_TX_BUSY: Ongoing transmission (Header */
/*                                  or Response)                              */
/*                                  LIN_TX_HEADER_ERROR: Erroneous header     */
/*                                  transmission such as: - Mismatch between  */
/*                                  sent and read back data - Identifier      */
/*                                  parity error or Physical bus error        */
/*                                  LIN_TX_ERROR: Erroneous response          */
/*                                  transmission such as: - Mismatch between  */
/*                                  sent and read back data - Physical bus    */
/*                                  error                                     */
/*                                  LIN_RX_OK: Reception of correct response  */
/*                                  LIN_RX_BUSY: Ongoing reception: at least  */
/*                                  one response byte has been received, but  */
/*                                  the checksum byte has not been received   */
/*                                  LIN_RX_ERROR: Erroneous response reception*/
/*                                  such as: - Framing error - Overrun error  */
/*                                  - Checksum error or Short response        */
/*                                  LIN_RX_NO_RESPONSE: No response byte has  */
/*                                  been received so far                      */
/*                                  LIN_OPERATIONAL: Normal operation; the    */
/*                                  related LIN channel is woken up from the  */
/*                                  LIN_CH_SLEEP and no data has been sent.   */
/*                                  LIN_CH_SLEEP: Sleep state operation; in   */
/*                                  this state wake-up detection from slave   */
/*                                  nodes is enabled.                         */
/*                                  LIN_CH_SLEEP_PENDING: This mode cannot be */
/*                                  detected by the aforementioned function   */
/*                                  because it transitions to LIN_CH_SLEEP    */
/*                                  when the Lin_GetStatus function is called.*/
/* Contents    : Gets the status of the LIN driver.                           */
/* Author      : --                                                           */
/* Note        : [SWS_Lin_00168]                                              */
/*----------------------------------------------------------------------------*/
Lin_StatusType Lin_GetStatus( uint8 Channel, uint8** Lin_SduPtr )
{
    Lin_StatusType result = LIN_NOT_OK;
    Std_ReturnType stdResult;
    uint8                   chIndex = (uint8)LIN_70_NUM_OF_CHANNEL;
    const Lin_ChannelType*  ptrLinChannel;
   
    stdResult = Lin_searchChIndex( Channel, &chIndex );
   
    ptrLinChannel = &s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex];
 
#if ( LIN_DEV_ERROR_DETECT != FALSE )
 
    if ( stdResult != E_OK ) {
        /* [SWS_Lin_00251] Channel has an invalid value report error code LIN_E_INVALID_CHANNEL */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_GETSTATUS_ID, ( uint8 ) LIN_E_INVALID_CHANNEL );
        return result;
    }
 
    if ( LIN_INIT != s_Lin_DriverStatus ) {
        /* [SWS_Lin_00141] Lin Driver is not already initialized report error code LIN_E_UNINIT */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_GETSTATUS_ID, ( uint8 ) LIN_E_UNINIT );
    } else if ( NULL_PTR == Lin_SduPtr ) {
        /* [SWS_Lin_00144] Lin_SduPtr has an invalid value report error code LIN_E_PARAM_POINTER */
        ( void ) Det_ReportError( ( uint16 ) LIN_MODULE_ID, ( uint8 ) LIN_INDEX,
                                  ( uint8 ) LIN_GETSTATUS_ID, ( uint8 ) LIN_E_PARAM_POINTER );
    } else
#endif /* #if ( LIN_DEV_ERROR_DETECT != FALSE ) */
    {
        Lin_70_HW_ChangeChannel( (uint8)ptrLinChannel->LinChannelId );
 
        /* [SWS_Lin_00211]] Get current Lin Channel status */
        result = s_Lin_Status[chIndex].ChannelSubStatus;
        if ( result == LIN_CH_OPERATIONAL ) {
            result = LIN_OPERATIONAL;
        }
 
        /* [SWS_Lin_00092] Store the SDU in a shadow buffer */
        if (( LIN_RX_OK == s_Lin_Status[chIndex].ChannelSubStatus ) ||
            ( LIN_RX_ERROR == s_Lin_Status[chIndex].ChannelSubStatus )) {
                *Lin_SduPtr = (uint8*)s_LinFrameReceiveBuffer;
        }
       
        /* SWS_Lin_00264 */
        if ( LIN_CH_SLEEP_PENDING  == s_Lin_Status[chIndex].ChannelStatus ) {
            s_Lin_Status[chIndex].ChannelStatus = LIN_CH_SLEEP;
        }
 
    }
    /* [SWS_Lin_00091] function returns status of the LIN driver */
    return result;
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_70_Isr_Tx                                                */
/* Param       : channelId                                                    */
/* Return      : void                                                         */
/* Contents    : Transmit interrupt process.                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Lin_70_Isr_Tx( uint8 channelId )
{
    uint8 errorCheck;
    uint8 transCheck;
    uint8 frameType;
    uint8 chIndex = (uint8)LIN_70_NUM_OF_CHANNEL;
    Std_ReturnType stdResult;
 
    stdResult = Lin_searchChIndex( channelId, &chIndex );
   
    if ( stdResult == E_OK ) {
        /* change channel */
        Lin_70_HW_ChangeChannel( channelId );
 
        errorCheck = Lin_70_HW_ClrInt_ChkErr( ( uint8 ) LIN_70_SET_TRANSMISSION);
 
        if ( 0x00U != errorCheck ) { /* LST ERR bit : 0x00:no error 0x08: errorr */
            /* do nothing */
        } else {                    /* What to do if an error occurs */
            switch ( s_Lin_Status[chIndex].FrameStatus ) {
            case LIN_SEND_HEADER:
                /* check if transmit bit is set */
                transCheck = Lin_70_HW_CheckTransFlags();
                if ( 0x00U != transCheck ) { /* RFT bit : 0x10:Tx  0x00:Rx */
                    s_Lin_Status[chIndex].FrameStatus = LIN_SEND_RESPONSE;
 
                    Lin_70_HW_StartResponse();
                }
                break;
            case LIN_SEND_RESPONSE:
                if ( LIN_ORDER_SLEEP == s_Lin_Status[chIndex].ChannelOrderedStatus ) {
 
                    /* Call function to change the channel mode */
                    ( void )lin_chModeChange( LIN_70_WAKEUP_MODE );
 
                    s_Lin_Status[chIndex].ChannelStatus = LIN_CH_SLEEP;
                    s_Lin_Status[chIndex].ChannelSubStatus = LIN_CH_SLEEP;
                    s_Lin_Status[chIndex].ChannelOrderedStatus = LIN_ORDER_NON;
 
                    frameType = 0U;
                    Lin_70_HW_SetFrameType( frameType );
 
                    Lin_70_HW_StartCommunication();
 
                } else {
                    s_Lin_Status[chIndex].ChannelSubStatus = LIN_TX_OK;
                    Lin_70_HW_DisableInterrupts( chIndex );
                }
                break;
            case LIN_SEND_WAKEUP:
                /* Call function to change the channel mode */
                ( void )lin_chModeChange( LIN_70_OPERATIONAL_MODE );
                /* [SWS_Lin_00174] */
                s_Lin_Status[chIndex].ChannelStatus        = LIN_CH_OPERATIONAL;
                s_Lin_Status[chIndex].ChannelSubStatus     = LIN_CH_OPERATIONAL;
                s_Lin_Status[chIndex].ChannelOrderedStatus = LIN_ORDER_NON;
                Lin_70_HW_DisableInterrupts( chIndex );
                break;
            default:
                /* do nothing */
                break;
            }
        }
    }
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_70_Isr_Rx                                                */
/* Param       : channelId                                                    */
/* Return      : void                                                         */
/* Contents    : Reception interrupt process.                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Lin_70_Isr_Rx( uint8 channelId )
{
    uint8 errorCheck;
    uint8 chIndex = (uint8)LIN_70_NUM_OF_CHANNEL;
    Std_ReturnType stdResult;
 
    stdResult = Lin_searchChIndex( channelId, &chIndex );
   
    if ( stdResult == E_OK ) {
        /* change channel */
        Lin_70_HW_ChangeChannel( channelId );
 
        errorCheck = Lin_70_HW_ClrInt_ChkErr( ( uint8 ) LIN_70_SET_RECEPTION );
 
        if ( 0x00U != errorCheck ) { /* LST ERR bit : 0x00:no error 0x08: errorr */
            /* do nothing */
        } else {                  /* What to do if an error occurs */
            switch ( ( uint16 ) s_Lin_Status[chIndex].ChannelStatus ) {
            case ( uint16 ) LIN_CH_OPERATIONAL:
                if ( LIN_RX_BUSY == s_Lin_Status[chIndex].ChannelSubStatus ) {
 
                    Lin_70_HW_ReadReceivedData( &s_LinFrameReceiveBuffer[0] );
 
                    s_Lin_Status[chIndex].ChannelSubStatus = LIN_RX_OK;
                }
                break;
            case ( uint16 ) LIN_CH_SLEEP:
                s_Lin_Status[chIndex].WakeupStatus = TRUE;
                /* Notification wakeup event to EcuM */
                EcuM_CheckWakeup( s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinChannelEcuMWakeupSource );
 
                /* Transition operational mode */
                /* Call function to change the channel mode */
                ( void )lin_chModeChange( LIN_70_OPERATIONAL_MODE );
                break;
            default:
                /* do nothing */
                break;
            }
        }
    }
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_70_Isr_Err                                               */
/* Param       : channelId                                                    */
/* Return      : void                                                         */
/* Contents    : Error interrupt process.                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Lin_70_Isr_Err( uint8 channelId )
{
    uint8 timeoutErrCheck;
    uint8 chIndex = (uint8)LIN_70_NUM_OF_CHANNEL;
    Std_ReturnType stdResult;
 
    stdResult = Lin_searchChIndex( channelId, &chIndex );
   
    if ( stdResult == E_OK ) {
        /* change channel */
        Lin_70_HW_ChangeChannel( channelId );
 
        /* In this function, handling only no response error */
        if ( LIN_TX_BUSY == s_Lin_Status[chIndex].ChannelSubStatus ) {
            if ( LIN_SEND_HEADER == s_Lin_Status[chIndex].FrameStatus ) {
                /* If error occur, frame processing stop */
                lin_stopFrame( );
                s_Lin_Status[chIndex].ChannelSubStatus = LIN_TX_HEADER_ERROR;
            } else {
                s_Lin_Status[chIndex].ChannelSubStatus = LIN_TX_ERROR;
            }
        } else if ( LIN_RX_BUSY == s_Lin_Status[chIndex].ChannelSubStatus ) {
            Lin_70_HW_ReadReceivedData( &s_LinFrameReceiveBuffer[0] );
 
            timeoutErrCheck = Lin_70_HW_TimeoutErrCheck();
 
            if ( 0x00U == timeoutErrCheck ) {
                s_Lin_Status[chIndex].ChannelSubStatus = LIN_RX_ERROR;
            } else {
                s_Lin_Status[chIndex].ChannelSubStatus = LIN_RX_NO_RESPONSE;
            }
        } else {
            /* do nothing */
        }
 
        (void) Lin_70_HW_ClrInt_ChkErr( ( uint8 ) LIN_70_SET_ERRSTATUS );
    }
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : Lin_searchChIndex                                            */
/* Param       : (in) channelId     LIN channel id                            */
/*               (out) chIndex      Index to Lin_ChannelType container        */
/* Return      : Std_ReturnType     E_OK : Index is set successfully          */
/*                                  E_NOT_OK : Index error                    */
/* Contents    : Search LIN ch index from config parameter.                   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Lin_searchChIndex( const uint8 channelId, uint8* const chIndex )
{
    Std_ReturnType  result = E_NOT_OK;
    uint8           ChannelTypeIndex;
   
    for ( ChannelTypeIndex = 0x0U; ChannelTypeIndex < (uint8)LIN_70_NUM_OF_CHANNEL; ChannelTypeIndex++ ) {
        if ( (uint8)s_Lin_Config->Lin_GlobalConfig->LinChannel[ChannelTypeIndex].LinChannelId == channelId ) {
            result = E_OK;
            *chIndex = ChannelTypeIndex;
            break;
        }
    }
    return result;
}
 
#define LIN_STOP_SEC_CODE_LOCAL
#include "Lin_MemMap.h"

/* EOF Lin.c ******************************************************************/