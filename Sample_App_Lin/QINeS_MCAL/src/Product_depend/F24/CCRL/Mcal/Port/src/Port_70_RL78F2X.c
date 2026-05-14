/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Port_70_RL78F2X.c                                            */
/* Version     : v1.00.02                                                     */
/* Contents    : PORT Module HW dependent interface                           */
/*               The PORT is a basic software module at the service layer of  */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of PORT Driver                                               */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Port.h"
#include "SchM_Port.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PORT_70_VENDOR_ID_RL78F2X_C                     ( 70U )
#define PORT_70_MODULE_ID_RL78F2X_C                     ( 124U )

#define PORT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C      ( 22U )
#define PORT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C      ( 11U )
#define PORT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C   ( 0U )

#define PORT_70_SW_MAJOR_VERSION_RL78F2X_C              ( 1U )
#define PORT_70_SW_MINOR_VERSION_RL78F2X_C              ( 0U )
#define PORT_70_SW_PATCH_VERSION_RL78F2X_C              ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Port.h version check start */

#if ( PORT_70_VENDOR_ID_RL78F2X_C != PORT_VENDOR_ID )
    #error "VENDOR ID for Port_70_RL78F2X.c and Port.h are different"
#endif

#if ( PORT_70_MODULE_ID_RL78F2X_C != PORT_MODULE_ID )
    #error "MODULE ID for Port_70_RL78F2X.c and Port.h are different"
#endif

#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != PORT_AR_RELEASE_MAJOR_VERSION ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != PORT_AR_RELEASE_MINOR_VERSION ) || \
      ( PORT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != PORT_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Port_70_RL78F2X.c and Port.h are different"
#endif

#if ( ( PORT_70_SW_MAJOR_VERSION_RL78F2X_C != PORT_SW_MAJOR_VERSION ) || \
      ( PORT_70_SW_MINOR_VERSION_RL78F2X_C != PORT_SW_MINOR_VERSION ) || \
      ( PORT_70_SW_PATCH_VERSION_RL78F2X_C != PORT_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Port_70_RL78F2X.c and Port.h are different"
#endif

/* Port.h version check end */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Port.h version check start */
 
#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != RTE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Port_70_RL78F2X.c and SchM_Port.h are different"
#endif

/* SchM_Port.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* Calculate port ID */
#define PORT_70_PIN_TO_PORT( x )          ( ( x ) >> 3U )
/* Calculate port pin ID */
#define PORT_70_PIN_TO_BITPOS( x )        ( ( x ) & 0x07U )

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Initial value of the variables                                             */
/*----------------------------------------------------------------------------*/
#define PORT_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Port_MemMap.h"
static const Port_ConfigType*   s_port_ConfigPtr = NULL_PTR;
#define PORT_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Port_MemMap.h"

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define PORT_START_SEC_CONST_8
#include "Port_MemMap.h"

/* Pxx --------------------------------------------------------------- */
/* Port configration table for a 100-pin products.      */
/* Chapter 4-3. Table 4-25 of RL78F24 hardware manual   */
static const uint8             Port_70_SfrTbl[PORT_70_MAX_NUMBER] = {
/*  P0     P1     P2     P3     P4     P5     P6     P7     P8     P9     P10    P11    P12   */
    0x0FU, 0xFFU, 0x00U, 0x1FU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0x00U, 0xFFU, \
/*  P13    P14    P15   */
    0x81U, 0x01U, 0xFFU
};

#define PORT_STOP_SEC_CONST_8
#include "Port_MemMap.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define PORT_START_SEC_CODE_LOCAL
#include "Port_MemMap.h"

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_SetBit                                       */
/* Param       : address : uint16                                             */
/*             : xbit   : uint8                                               */
/*             : value  : uint8                                               */
/* Return      : none                                                         */
/* Contents    : Set the value in the port control register bit               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Port_70_RL78F2X_SetBit( uint16 address, uint8 xbit, uint8 value )
{
    const uint8 mask = xbit;
    /* Exclusive Control Start */
    /* [SWS_Port_00075] */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00();

    if( 0U == value ) {
        (*( volatile uint8 QL_70_NEAR * ) address ) &=
                                                        ( uint8 )(~( uint8 )( 1U << mask ));
    } else { /* ( 1U == value ) */
        (*( volatile uint8 QL_70_NEAR * ) address ) |= ( uint8 )( 1U << mask );
    }

    /* Exclusive Control End */
    /* [SWS_Port_00075] */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00();
}

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_SetReg                                       */
/* Param       : address : uint16                                             */
/*             : value  : uint8                                               */
/* Return      : none                                                         */
/* Contents    : Set the value in the port control register                   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Port_70_RL78F2X_SetReg( uint16 address, uint8 value )
{
    /* Exclusive Control Start */
    /* [SWS_Port_00075] */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();

    (*( volatile uint8 QL_70_NEAR * ) address) = value;

    /* Exclusive Control End */
    /* [SWS_Port_00075] */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
}

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_FlipBit                                      */
/* Param       : address : uint16                                             */
/*             : xbit  : uint8                                                */
/* Return      : none                                                         */
/* Contents    : Flip the value from the specified port register              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
uint8 Port_70_RL78F2X_FlipBit( uint16 address, uint8 xbit )
{
    uint8 level;
    const uint8 mask  = xbit;

    /* Exclusive Control Start */
    /* [SWS_Port_00075] */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02();

    /* flip the value from the specified port register (Bit change Type Function) */
    level = Port_70_RL78F2X_GetBit( address, xbit );
    level = level ^ 1U;

    if( 0U == level ) {
        (*( volatile uint8 QL_70_NEAR * ) address ) &=
                                                        ( uint8 )(~( uint8 )( 1U << mask ));
    } else { /* ( 1U == value ) */
        (*( volatile uint8 QL_70_NEAR * ) address ) |= ( uint8 )( 1U << mask );
    }

    /* Exclusive Control End */
    /* [SWS_Port_00075] */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02();

    return level;
}

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_GetBit                                       */
/* Param       : address : uint16                                             */
/*             : xbit   : uint8                                               */
/* Return      : Port control register bit                                    */
/* Contents    : Returns the value of the port control register bit           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
uint8 Port_70_RL78F2X_GetBit( uint16 address, uint8 xbit )
{
    const uint8 mask = xbit;
    uint8 value = *( volatile uint8 QL_70_NEAR * )address;

    value = ( value & ( uint8 )( 1U << mask ) ) >> mask;
    return value;
}

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_GetReg                                       */
/* Param       : address : uint16                                             */
/* Return      : Port control register                                        */
/* Contents    : Returns the value of the port control register               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
uint8 Port_70_RL78F2X_GetReg( uint16 address )
{
    const uint8 value = *( volatile uint8 QL_70_NEAR * )address;

    return value;
}

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_PreInit                                      */
/* Param       : --                                                           */
/* Return      : none                                                         */
/* Contents    : Port Driver Preinitialization processing                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Port_70_RL78F2X_CommonInit ( const Port_ConfigType* ConfigPtr )
{

    s_port_ConfigPtr = ConfigPtr;

    /* Write to registers that require initial setting */
    Port_70_RL78F2X_SetReg( PORT_70_RL78F2X_PMS_ADR, PORT_70_PMSVAL );
    Port_70_RL78F2X_SetReg( PORT_70_RL78F2X_PSRSEL_ADR, PORT_70_PSRSELVAL );
}

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_Init                                         */
/* Param       : configType : Port Config Type Table Pointer                  */
/* Return      : none                                                         */
/* Contents    : Port Driver initialization processing                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Port_70_RL78F2X_PortInit ( const Port_PortPinType* portPtr )
{
    Port_PinType                        lpin;        /* Pin  ID */
    uint8                               lport;       /* Port ID */
    uint8                               lbitpos;     /* PIN  BIT POSITION */
    uint16                              tPortAddr;   /* Port Register Address */
    uint16_least                        lcount;      /* Counter */
    /* Pointer to register set configuration */
    const Port_70_RL78F2X_PinSetConfType*     setConfPtr;
    /* Pointer to PIOR register configuration */
    const Port_70_RL78F2X_PinPiorSetType*     piorSetPtr;

    piorSetPtr  =
        ( const Port_70_RL78F2X_PinPiorSetType* )portPtr->PortHWPortPinType->Port_70_PinPiorSetPtr;
    setConfPtr  =
        ( const Port_70_RL78F2X_PinSetConfType* )portPtr->PortHWPortPinType->Port_70_PinSetConfPtr;
    /* Calculate port number and pin number */
    lpin        = portPtr->PortPinId;
    lport       = ( uint8 )PORT_70_PIN_TO_PORT( lpin );
    lbitpos     = ( uint8 )PORT_70_PIN_TO_BITPOS( lpin );

    /* Initialize Px and PMx register */
    Port_70_RL78F2X_SetBit( PORT_70_RL78F2X_Px( lport ), lbitpos,
                            ( uint8 )(portPtr->PortPinLevelValue) ); /* Px */
    Port_70_RL78F2X_SetBit( PORT_70_RL78F2X_PMx( lport ), lbitpos,
                            ( uint8 )(portPtr->PortPinDirection) ); /* PMx */

    /* If configured, initialize PIORx register */
    if( NULL_PTR != piorSetPtr ) {
        Port_70_RL78F2X_SetBit( piorSetPtr->PortPinPiorAddr, piorSetPtr->PortPinPiorBit,
                                ( uint8 )(piorSetPtr->PortPinPiorSetVal) );
    }
    /* If configured, initialize Port register */
    if( NULL_PTR != setConfPtr ) {
        /* Process for the number of configured registers */
        for( lcount = 0U; lcount < setConfPtr->PortRegNum; lcount++ ) {
            tPortAddr = ( setConfPtr->PortPinMode[lcount] )->PortRegAddr + ( uint16 )lport;
            Port_70_RL78F2X_SetBit( tPortAddr, lbitpos,
                                    ( uint8 )( setConfPtr->PortPinMode[lcount]->PortRegSetVal ) );
        }
    }
}

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_SetPinDirection                              */
/* Param       : Pin       : Port_PinType                                     */
/*             : Direction : Port_PinDirectionType                            */
/* Return      : none                                                         */
/* Contents    : Set the Port pin Direction Processing                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Port_70_RL78F2X_SetPinDirection( Port_PinType pin, Port_PinDirectionType direction )
{
    uint8               lport;      /* Port ID */
    uint8               lbitpos;    /* Port pin  bit position */

    /* Calculate port number and pin number */
    lport       = ( uint8 )PORT_70_PIN_TO_PORT( pin );
    lbitpos     = ( uint8 )PORT_70_PIN_TO_BITPOS( pin );

    /* Set the direction to the PMx register */
    Port_70_RL78F2X_SetBit( PORT_70_RL78F2X_PMx( lport ), lbitpos, ( uint8 )direction );
}

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_SetPinMode                                   */
/* Param       : Pin  : Port_PinType                                          */
/*             : Mode : Port_PinModeType                                      */
/* Return      : None                                                         */
/* Contents    : Shall set the port pin mode or the referenced pin            */
/*               during runtime.                                              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PORT_SET_PIN_MODE_API != FALSE )
void Port_70_RL78F2X_SetPinMode( Port_PinType pin, Port_PinModeType mode )
{
    uint8                               lport;          /* Port ID */
    uint8                               lbitpos;        /* Port pin  bit position */
    uint16_least                        lcount;         /* Counter */
    uint16_least                        lcount2;        /* Counter */
    uint16                              tPortAddr;      /* Port Register Address */
    /* Pointer to AUTOSAR configuration */
    const Port_PortPinType*                   portPtr;
    /* Pointer to change mode configuration */
    const Port_70_RL78F2X_PinChangeType*      changeModePtr;
    /* Pointer to register set configuration */
    const Port_70_RL78F2X_PinSetConfType*     setConfPtr;
     /* Pointer to PIORx register set configuration */
    const Port_70_RL78F2X_PinPiorSetType*     piorSetPtr;

    /* Get the configuration data */
    portPtr        = ( const Port_PortPinType* )&
                     ( ( s_port_ConfigPtr )->PortConfigSet->PortContainer->PortPin[pin] );
    changeModePtr  = ( const Port_70_RL78F2X_PinChangeType* )
                     portPtr->PortHWPortPinType->Port_70_PinChangePtr;
    /* Calculate port number and pin number */
    lport          = ( uint8 )PORT_70_PIN_TO_PORT( portPtr->PortPinId );
    lbitpos        = ( uint8 )PORT_70_PIN_TO_BITPOS( portPtr->PortPinId );

    /* Search modes that match the argument mode */
    for ( lcount = 0U; lcount < changeModePtr->PortChangeModeNum; lcount++ ) {
        if( mode == (changeModePtr->PortPinChange[lcount])->PortPinChangeMode ) {
            break;
        }
    }
    /* Get the register setting value of the matching mode from the configuration */
    piorSetPtr  = changeModePtr->PortPinChange[lcount]->Port_70_PinPiorSetPtr;
    setConfPtr  = changeModePtr->PortPinChange[lcount]->Port_70_PinSetConfPtr;

    /* If configured, set PIORx register */
    if( NULL_PTR != piorSetPtr ) {
        Port_70_RL78F2X_SetBit( piorSetPtr->PortPinPiorAddr, piorSetPtr->PortPinPiorBit,
                                ( uint8 )(piorSetPtr->PortPinPiorSetVal) );
    }
    /* If configured, set Port register */
    if( NULL_PTR != setConfPtr ) {
        for( lcount2 = 0U; lcount2 < setConfPtr->PortRegNum; lcount2++ ) {
            tPortAddr = ( setConfPtr->PortPinMode[lcount2] )->PortRegAddr + ( uint16 )lport;
            Port_70_RL78F2X_SetBit( tPortAddr, lbitpos,
                                    ( uint8 )( setConfPtr->PortPinMode[lcount2]->PortRegSetVal ) );
        }
    }
}
#endif /* #if ( PORT_SET_PIN_MODE_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_CheckPortSfr                                 */
/* Param       : portno  : uint8                                              */
/* Return      : retStat            statue                                    */
/* Contents    : Returns the value of the specified DIO channel.              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
uint8 Port_70_RL78F2X_CheckPortSfr( uint8 portno )
{
    uint8 retStat = E_NOT_OK;

    if ( ( PORT_70_MAX_NUMBER > portno ) && ( 0U != Port_70_SfrTbl[ portno ] ) ) {
        retStat = E_OK;
    }

    return retStat;
}

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_CheckPortSfrXbit                             */
/* Param       : portno  : uint8                                              */
/*             : xbit    : uint8                                              */
/* Return      : retStat                                                      */
/* Contents    : Returns the value of the specified DIO channel.              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
uint8 Port_70_RL78F2X_CheckPortSfrXbit( uint8 portno, uint8 xbit )
{
    uint8 retStat = E_NOT_OK;
    const uint8 mask    = xbit;


    if ( ( PORT_70_MAX_NUMBER > portno ) && ( 0U != ( Port_70_SfrTbl[portno] &
         ( uint8 )( 1U << mask ) ) ) ) {
        retStat = E_OK;
    }

    return retStat;
}

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : --                                                           */
/* Name        : Port_70_RL78F2X_CheckPortSfrMask                             */
/* Param       : portno  : uint8                                              */
/*             : mask    : uint8                                              */
/* Return      : retStat                                                      */
/* Contents    : Returns the value of the specified DIO channel.              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
uint8 Port_70_RL78F2X_CheckPortSfrMask( uint8 portno, uint8 mask )
{
    uint8   retStat = E_NOT_OK;

    if ( ( PORT_70_MAX_NUMBER > portno ) && ( mask == ( Port_70_SfrTbl[portno] & mask ) ) ) {
        retStat = E_OK;
    }

    return retStat;
}

#define PORT_STOP_SEC_CODE_LOCAL
#include "Port_MemMap.h"

/* EOF Port_70_RL78F2X.c *****************************************************/
