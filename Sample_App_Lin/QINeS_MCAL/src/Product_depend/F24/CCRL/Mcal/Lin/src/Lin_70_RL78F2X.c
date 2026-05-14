/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Lin_70_RL78F2X.c                                             */
/* Version     : v1.00.01                                                     */
/* Contents    : LIN Module HW dependent interface                            */
/*               This file covers Hw dependent functionality for LIN module   */
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
#include "LinIf.h"
#include "Lin_70_RL78F2X.h"
#include "Lin_70_HW.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_70_VENDOR_ID_RL78F2X_C                   ( 70U )
#define LIN_70_MODULE_ID_RL78F2X_C                   ( 82U )

#define LIN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    ( 22U )
#define LIN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    ( 11U )
#define LIN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C ( 0U )

#define LIN_70_SW_MAJOR_VERSION_RL78F2X_C            ( 1U )
#define LIN_70_SW_MINOR_VERSION_RL78F2X_C            ( 0U )
#define LIN_70_SW_PATCH_VERSION_RL78F2X_C            ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/*---------------Lin.h -------------------------------------------------------*/
/* Check if current file and Lin.h header file are of the same Vendor ID */
#if (LIN_70_VENDOR_ID_RL78F2X_C    != LIN_VENDOR_ID)
    #error "Vendor ID of Lin.c and Lin.h are different"
#endif

#if (LIN_70_MODULE_ID_RL78F2X_C    != LIN_MODULE_ID)
    #error "Module ID of Lin.c and Lin.h are different"
#endif

/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_70_SW_MAJOR_VERSION_RL78F2X_C    != LIN_SW_MAJOR_VERSION) ||\
     (LIN_70_SW_MINOR_VERSION_RL78F2X_C    != LIN_SW_MINOR_VERSION) ||\
     (LIN_70_SW_PATCH_VERSION_RL78F2X_C    != LIN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lin.c and Lin.h are different"
#endif

/* Check if current file and Lin.h header file are of the same Autosar version */
#if ((LIN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != LIN_AR_RELEASE_MAJOR_VERSION)   ||\
     (LIN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != LIN_AR_RELEASE_MINOR_VERSION)   ||\
     (LIN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lin.c and Lin.h are different"
#endif

/*---------------Lin_70_RL78F2X.h --------------------------------------------*/
/* Check if current source file and Lin_70_RL78F2X.h header file are of the same Vendor ID */
#if (LIN_70_VENDOR_ID_RL78F2X_C != LIN_70_VENDOR_ID_RL78F2X_H)
    #error "Vendor ID of Lin_70_RL78F2X.c and Lin_70_RL78F2X.h are different"
#endif

/* Check if current source file and Lin_70_RL78F2X.h header file are of the same Module ID */
#if (LIN_70_MODULE_ID_RL78F2X_C != LIN_70_MODULE_ID_RL78F2X_H)
    #error "Module of Lin_70_RL78F2X.c and Lin_70_RL78F2X.h are different"
#endif

/* Check if current source file and Lin_70_RL78F2X header file are of the same Autosar version */
#if ( ( LIN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != \
        LIN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C )  || \
      ( LIN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != \
        LIN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H )  || \
      ( LIN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != \
        LIN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) )
    #error "AUTOSAR Version Numbers of Lin_70_RL78F2X.c and Lin_70_RL78F2X.h are different"
#endif

/* Check if current file and Lin_70_RL78F2X.h header file are of the same Software version */
#if ((LIN_70_SW_MAJOR_VERSION_RL78F2X_C != LIN_70_SW_MAJOR_VERSION_RL78F2X_H) ||\
     (LIN_70_SW_MINOR_VERSION_RL78F2X_C != LIN_70_SW_MINOR_VERSION_RL78F2X_H) ||\
     (LIN_70_SW_PATCH_VERSION_RL78F2X_C != LIN_70_SW_PATCH_VERSION_RL78F2X_H))
    #error "Software Version Numbers of Lin_70_RL78F2X.c and Ic.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
static void lin_setBaudRate( const uint16 baudRatePrescalar );

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#define LIN_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Lin_MemMap.h"
volatile LIN_70_RL78Type* s_lin_reg = LIN_70_RL78F2X_REG_ADDR;
#define LIN_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Lin_MemMap.h"

#define LIN_70_LWBR_MAX_VALUE   ( 255U )
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define LIN_START_SEC_CODE_LOCAL
#include "Lin_MemMap.h"

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : lin_setBaudRate                                              */
/* Param       : baudRatePrescalar : baud rate prescalar value                */
/* Return      : -                                                            */
/* Contents    : This function will calculate baudrate prescalar value.       */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
static void lin_setBaudRate( const uint16 baudRatePrescalar )
{
    uint8  lwbr_val = 0U;
    uint16 brp;

    brp = baudRatePrescalar;
    /* Keep dividing baudRatePrescalar by 2 until it is greater than the max value */
    while ( brp >= (uint16)LIN_70_MAX_VALUE_PRESCALAR )
    {
        /* Divide the baudRatePrescalar by 2 */
        brp = brp >> 1U;
        /* Increment the value for LWBR register */
        if ( LIN_70_LWBR_MAX_VALUE >= lwbr_val ) {
            lwbr_val++;
        }
    }

    /* setting bit/sampling number selection bit  */
    s_lin_reg->LWBR_REG  = (uint8)LIN_70_LWBR_VALUE;
    /* setting Prescaler clock selection bit */
    s_lin_reg->LWBR_REG |= (uint8)( lwbr_val << 1U );
    /* Lin 2.x */
    s_lin_reg->LWBR_REG |= LIN_70_LWBR_LWBR0;
    /* setting the prescaler clock */
    s_lin_reg->LBRP0_REG = (uint8)( brp - 1U );
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : lin_setMKxx                                                  */
/* Param       : (in) chIndex channel index                                   */
/* Return      : void                                                         */
/* Contents    : This function will set MK1L,MK0H,MK2L,MK3L registers to      */
/*               enable interrupts of lin.                                    */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void lin_setMKxx( const uint8 chIndex )
{    /* Interrupt masking */
    if ( chIndex == LIN_70_CH0 ) {                /* Channel 0 */
        LIN_70_RL78F2X_MK2L &= (uint8)~( LIN_70_LIN0TRMMK | LIN_70_LIN0RVCMK | LIN_70_LIN0MK );
        LIN_70_RL78F2X_MK2L |= (uint8)LIN_70_LIN0WUPMK;
    } else if ( chIndex == LIN_70_CH1 ) {         /* Channel 1 */
        LIN_70_RL78F2X_MK2L &= ( uint8 )~( LIN_70_LIN1TRMMK | LIN_70_LIN1RVCMK | LIN_70_LIN1MK );
        LIN_70_RL78F2X_MK3L |= ( uint8 )LIN_70_LIN1WUPMK ;
    } else if ( chIndex == LIN_70_CH2 ) {         /* Channel 2 */
        LIN_70_RL78F2X_MK1L &= ( uint8 )~( LIN_70_LIN2MK | LIN_70_LIN2RVCMK | LIN_70_LIN2TRMMK );
        LIN_70_RL78F2X_MK1H |= ( uint8 )LIN_70_LIN2WUPMK;
    } else {
        /* Channel index invalid */
    }
}



/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_MstInit                                       */
/* Param       : (in) chIndex channel index                                   */
/*             : (in) baudRatePrescaler configure baud rate prescaler         */
/* Return      : -                                                            */
/* Contents    : function initializes hw reg required for lin initialization  */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_MstInit ( const uint8 chIndex, const uint16 baudRatePrescaler )
{  
    /* Sets the baud rate for the Lin communication */
    lin_setBaudRate( baudRatePrescaler );

    /* LIN mode register configuration */
    s_lin_reg->LMD_REG = (uint8)LIN_70_LMD_VALUE;

    /* Interrupt Configure */
    /* Configuration of Interrupt Enable register  */
    s_lin_reg->LIE_REG = (uint8)LIN_70_LIE_VALUE;

    /* Interrupt masking */
    lin_setMKxx( chIndex );

    /* Configuration of Error Detection Enable register  */
    s_lin_reg->LEDE_REG = (uint8)LIN_70_LEDE_VALUE;

    /* setting break field in transmission frame header */
    s_lin_reg->LBFC_REG = (uint8)( LIN_70_BREAKFIELD_LENGTH | LIN_70_BREAKFIELD_DELIMITER );

    /* setting Inter byte space of transmission frame header */
    s_lin_reg->LSC_REG = (uint8)( LIN_70_INTERBYTE_SPACE_HEADER | LIN_70_INTERBYTE_SPACE );

    /* set the low width of the wake-up signal transmission */
    s_lin_reg->LWUP_REG = LIN_70_WAKEUP_WIDTH;

    LIN_70_RL78F2X_ISC = (uint8)( LIN_70_RL78F2X_ISC_ISC4 | LIN_70_RL78F2X_ISC_ISC3 | LIN_70_RL78F2X_ISC_ISC2 | LIN_70_RL78F2X_ISC_ISC0 );
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_ReadModeStatusReg                             */
/* Param       : void                                                         */
/* Return      : RESET STATUS   [0:0] 0:Reset mode  1:Not reset mode          */
/*             : LIN MODE STATUS[1:1] 0:Wakup mode  1:Lin mode                */
/*             : OPERATIONAL MODE == Not reset mode | Lin mode                */
/* Contents    : Provide the mode status                                      */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
uint8 Lin_70_RL78F2X_ReadModeStatusReg( void )
{
    uint8 mode;
    /* Reading LIN mode status register */
    mode = (s_lin_reg->LMST_REG);

    return( mode );
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_SetFrameId                                    */
/* Param       : (in) PduInfoPtr pointert of LIN frame data                   */
/* Return      : void                                                         */
/* Contents    : Set Frame Id and copy data to reg                            */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_SetFrameId ( const Lin_PduType* PduInfoPtr )
{
    uint8 dataIndex;
    /* Set identifier ID to be transmitted */
    s_lin_reg->LIDB_REG = (uint8)PduInfoPtr->Pid;
    /* check if it is the master response */
    if ( (uint8)LIN_FRAMERESPONSE_TX == (uint8)PduInfoPtr->Drc ) {
        /* Copy the data from upper layer buffer */
        for ( dataIndex = (uint8)0; dataIndex < (uint8)PduInfoPtr->Dl; dataIndex++ ) {
            s_lin_reg->LDB_REG[dataIndex] = PduInfoPtr->SduPtr[dataIndex];
        }
    }
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_SetFrameType                                  */
/* Param       : (in) frameType                                               */
/* Return      : void                                                         */
/* Contents    : This function configure the Frame to be transmitted          */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_SetFrameType ( const uint8 frameType )
{
    s_lin_reg->LDFC_REG = frameType;
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_GoToSleep                                     */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : Sets the Lin channel to sleep mode                           */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_GoToSleep( void )
{
    uint8 dataIndex = 0U;

    /* Set sleep ID identifier */
    s_lin_reg->LIDB_REG = LIN_70_GO_TO_SLEEP_ID;

    /* Copy the GoToSleep command to data buffer register */
    s_lin_reg->LDB_REG[dataIndex] = (uint8)LIN_SLEEP_COMMAND_0U;

    for ( dataIndex = 1U; dataIndex < LIN_70_GO_TO_SLEEP_LENGTH; dataIndex++ ) {
        s_lin_reg->LDB_REG[dataIndex] = (uint8)LIN_SLEEP_COMMAND_255U;
    }
    /* setting the data field reg with length and mode */
    s_lin_reg->LDFC_REG = (uint8)(LIN_70_GO_TO_SLEEP_LENGTH | LIN_70_LDFC_RFT | LIN_70_LDFC_FSM);
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_SetWakeupTranMode                             */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : This function provides wake-up transmission                  */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_SetWakeupTranMode( void )
{
    /* Frame information configure */
    /* set transmission mode */
    s_lin_reg->LDFC_REG = LIN_70_LDFC_RFT;
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_ClrInt_ChkErr                                 */
/* Param       : modee LIN_70_SET_TRANSMISSION                                */
/*             :       LIN_70_SET_RECEPTION                                   */
/*             :       LIN_70_SET_ERRSTATUS                                   */
/* Return      : errorCheck                                                   */
/* Contents    : function will clear pending tasks and check for error flag   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
uint8 Lin_70_RL78F2X_ClrInt_ChkErr( const uint8 mode )
{
    uint8 errVal;

    if ( ( uint8 ) LIN_70_SET_TRANSMISSION == mode ) {
        /* clearing frame and header transmission bits */
        s_lin_reg->LST_REG &= ( uint8 )~(LIN_70_LST_FTC | LIN_70_LST_HTRC);

    } else if ( ( uint8 ) LIN_70_SET_RECEPTION == mode ) {
        /* clearing frame and data reception bits */
        s_lin_reg->LST_REG &= ( uint8 )~(LIN_70_LST_FRC | LIN_70_LST_D1RC);

    } else {
        /* clearing error status register */
        s_lin_reg->LEST_REG = 0U;
    }

    errVal = (s_lin_reg->LST_REG & LIN_70_LST_ERR);

    return( errVal );
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_CheckTransFlags                               */
/* Param       : void                                                         */
/* Return      : transCheck                                                   */
/* Contents    : This function will check if the transmit bit is set or not   */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
uint8 Lin_70_RL78F2X_CheckTransFlags( void )
{
    uint8 transCheck;

    transCheck = (s_lin_reg->LDFC_REG & LIN_70_LDFC_RFT);

    return( transCheck );
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_TimeoutErrCheck                               */
/* Param       : void                                                         */
/* Return      : timeoutErrCheck                                              */
/* Contents    : This function will check if timeout error has occurred       */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
uint8 Lin_70_RL78F2X_TimeoutErrCheck( void )
{
    uint8 timeoutErrCheck;
    /* checking for Frame/response timeout error */
    timeoutErrCheck = (s_lin_reg->LEST_REG & LIN_70_LEST_FTER);

    return( timeoutErrCheck );
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_ReadReceivedData                              */
/* Param       : void                                                         */
/* Return      : responseLength                                               */
/* Contents    : This function will read and store the data received          */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_ReadReceivedData( uint8* LinFrameBufPtr )
{
    uint8 responseLength;
    uint8 dataIndex;

    /* Store receive data in buffer */
    responseLength = ( uint8 )( s_lin_reg->LDFC_REG & LIN_70_MASK_LENGTH );

    for ( dataIndex = 0U; dataIndex < responseLength; dataIndex++ ) {
        LinFrameBufPtr[dataIndex] = s_lin_reg->LDB_REG[dataIndex];
    }
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_ModeChange                                    */
/* Param       : (in) modeChange, timeout Request mode change in a given time */
/* Return      : Std_ReturnType     E_OK: Mode change success                 */
/*                                  E_NOT_OK: Mode change failure             */
/* Contents    : Change hardware LIN operation mode.                          */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
Std_ReturnType Lin_70_RL78F2X_ModeChange( const uint8 modeChange, const uint16 timeout )
{
    Std_ReturnType result = E_NOT_OK;
    uint16 waitTime;

    /* setting LIN control register will cause mode change */
    s_lin_reg->LCUC_REG = modeChange;

    for ( waitTime = 0U; waitTime < timeout; waitTime++ ) {
        /* checking mode status reg for mode change */
        if ( s_lin_reg->LMST_REG == modeChange ) {
            /* Success */
            result = E_OK;
            break;
        }
    }
    return result;
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_StartCommunication                            */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : This function will set frame or wake-up trans/receive        */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_StartCommunication( void )
{
    /* start Header reception/wake-up transmission/reception start  */
    s_lin_reg->LTRC_REG = LIN_70_LTRC_FTS;
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_StartResponse                                 */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : This function will set response trans/receive                */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_StartResponse ( void )
{
    /* start response transmission/reception in frame separate mode */
    s_lin_reg->LTRC_REG = LIN_70_LTRC_RTS;
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_DisableInterrupts                             */
/* Param       : Channel    channel id                                        */
/* Return      : void                                                         */
/* Contents    : This function will disable interrupt services                */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_DisableInterrupts ( const uint8 Channel )
{
    if ( Channel == LIN_70_CH0) {   /* Channel 0 */
        /* Disable Lin receive, transmit and error interrupts */
        LIN_70_RL78F2X_MK2L |= (uint8)( LIN_70_LIN0WUPMK | LIN_70_LIN0TRMMK | LIN_70_LIN0RVCMK | LIN_70_LIN0MK);
    } else if ( Channel == LIN_70_CH1 )  {    /* Channel 1 */
        LIN_70_RL78F2X_MK2L |= (uint8)( LIN_70_LIN1TRMMK | LIN_70_LIN1RVCMK | LIN_70_LIN1MK);
        LIN_70_RL78F2X_MK3L |= (uint8)LIN_70_LIN1WUPMK;
    } else if ( Channel == LIN_70_CH2 )  {    /* Channel 2 */
        LIN_70_RL78F2X_MK1L |= (uint8)( LIN_70_LIN2MK | LIN_70_LIN2RVCMK | LIN_70_LIN2TRMMK );
        LIN_70_RL78F2X_MK1H |= (uint8)LIN_70_LIN2WUPMK;
    } else {
        /* Channel index invalid */
    }
   
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_EnableInterrupts                              */
/* Param       : Channel Chaneel index                                        */
/* Return      : void                                                         */
/* Contents    : This function will enable interrupt services                 */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_EnableInterrupts ( const uint8 Channel )
{
    if ( Channel == LIN_70_CH0 ) {   /* Channel 0 */
        /* Disable Lin receive, transmit and error interrupts */
        LIN_70_RL78F2X_MK2L &= ( uint8 )~( ( LIN_70_LIN0WUPMK | LIN_70_LIN0TRMMK | LIN_70_LIN0RVCMK | LIN_70_LIN0MK ) );
    } else if ( Channel == LIN_70_CH1 )  {    /* Channel 1 */
        LIN_70_RL78F2X_MK2L &= ( uint8 )~( ( LIN_70_LIN1TRMMK | LIN_70_LIN1RVCMK | LIN_70_LIN1MK ) );
        LIN_70_RL78F2X_MK3L &= ( uint8 )~LIN_70_LIN1WUPMK;
    } else if ( Channel == LIN_70_CH2 )  {    /* Channel 2 */
        LIN_70_RL78F2X_MK1L &= ( uint8 )~( ( LIN_70_LIN2MK | LIN_70_LIN2RVCMK | LIN_70_LIN2TRMMK ) );
        LIN_70_RL78F2X_MK1H &= ( uint8 )~LIN_70_LIN2WUPMK;
    } else {
        /* Channel index invalid */
    }
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_ClearInterrupts                               */
/* Param       : Channel Chaneel index                                        */
/* Return      : void                                                         */
/* Contents    : This function will clear flags for interrupt requests        */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_ClearInterrupts ( const uint8 Channel )
{
    if ( Channel == LIN_70_CH0 ) {   /* Channel 0 */
        /* Disable Lin receive, transmit and error interrupts */
        LIN_70_RL78F2X_IF2L |= (uint8)( LIN_70_LIN0WUPMK | LIN_70_LIN0TRMMK | LIN_70_LIN0RVCMK | LIN_70_LIN0MK);
    } else if ( Channel == LIN_70_CH1 )  {    /* Channel 1 */
        LIN_70_RL78F2X_IF2L |= (uint8)( LIN_70_LIN1TRMMK | LIN_70_LIN1RVCMK | LIN_70_LIN1MK);
        LIN_70_RL78F2X_IF3L |= (uint8)LIN_70_LIN1WUPMK;
    } else if ( Channel == LIN_70_CH2 )  {    /* Channel 2 */
        LIN_70_RL78F2X_IF1L &= (uint8)~( LIN_70_LIN2MK | LIN_70_LIN2RVCMK | LIN_70_LIN2TRMMK );
        LIN_70_RL78F2X_IF1H &= (uint8)~LIN_70_LIN2WUPMK;
    } else {
        /* Channel index invalid */
    }
}

/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_RL78F2X_ChangeChannel                                 */
/* Param       : Channel Chaneel index                                        */
/* Return      : void                                                         */
/* Contents    : This function shall change channel2.                         */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_ChangeChannel( const uint8 chIndex )
{
    LIN_70_RL78F2X_LCHSEL = chIndex;
}

#define LIN_STOP_SEC_CODE_LOCAL
#include "Lin_MemMap.h"
/* EOF Lin_70_RL78F2X.c *******************************************************/