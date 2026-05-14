/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Port.c                                                       */
/* Version     : v1.00.01                                                     */
/* Contents    : This module shall provide the service for initializing the   */
/*               whole PORT structure of the microcontroller. Many ports and  */
/*               port pins can be assigned to various functionalities,        */
/*               e.g.                                                         */
/*                  General purpose I/O                                       */
/*                  ADC                                                       */
/*                  SPI                                                       */
/*                  SCI                                                       */
/*                  PWM                                                       */
/*                  CAN                                                       */
/*                  LIN                                                       */
/*                  etc                                                       */
/*               For this reason, there shall be an overall configuration and */
/*               initialization of this port structure. The configuration and */
/*               mode of these port pins is microcontroller and ECU dependent.*/
/*               Port initialisation data shall be written to each port as    */
/*               efficiently as possible.                                     */
/*               This PORT driver module shall complete the overall           */
/*               configuration and initialisation of the port structure which */
/*               is used in the DIO driver module. Therefore, the DIO driver  */
/*               works on pins and ports which are configured by the PORT     */
/*               driver.                                                      */
/*               The PORT driver shall be initialised prior to use of the DIO */
/*               functions. Otherwise DIO functions will exhibit undefined    */
/*               behaviour.                                                   */
/*               The diagram below identifies the PORT driver functions, and  */
/*               the structure of the PORT driver and DIO driver within the   */
/*               MCAL software layer.                                         */
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
#if ( PORT_DEV_ERROR_DETECT != FALSE )
#include "Det.h"
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PORT_70_VENDOR_ID_C                     ( 70U )
#define PORT_70_MODULE_ID_C                     ( 124U )

#define PORT_70_AR_RELEASE_MAJOR_VERSION_C      ( 22U )
#define PORT_70_AR_RELEASE_MINOR_VERSION_C      ( 11U )
#define PORT_70_AR_RELEASE_REVISION_VERSION_C   ( 0U )

#define PORT_70_SW_MAJOR_VERSION_C              ( 1U )
#define PORT_70_SW_MINOR_VERSION_C              ( 0U )
#define PORT_70_SW_PATCH_VERSION_C              ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Port.h version check start */

#if ( PORT_70_VENDOR_ID_C != PORT_VENDOR_ID )
    #error "VENDOR ID for Port.c and Port.h are different"
#endif

#if ( PORT_70_MODULE_ID_C != PORT_MODULE_ID )
    #error "MODULE ID for Port.c and Port.h are different"
#endif

#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_C    != PORT_AR_RELEASE_MAJOR_VERSION ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_C    != PORT_AR_RELEASE_MINOR_VERSION ) || \
      ( PORT_70_AR_RELEASE_REVISION_VERSION_C != PORT_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Port.c and Port.h are different"
#endif

#if ( ( PORT_70_SW_MAJOR_VERSION_C != PORT_SW_MAJOR_VERSION ) || \
      ( PORT_70_SW_MINOR_VERSION_C != PORT_SW_MINOR_VERSION ) || \
      ( PORT_70_SW_PATCH_VERSION_C != PORT_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Port.c and Port.h are different"
#endif

/* Port.h version check end */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Port.h version check start */
#if ( PORT_DEV_ERROR_DETECT != FALSE )
#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_C != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_C != RTE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "Software Version Numbers of Port.c and SchM_Port.h are different"
#endif
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */
/* SchM_Port.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Det.h version check start */
#if ( PORT_DEV_ERROR_DETECT != FALSE )
#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "Software Version Numbers of Port.c and Det.h are different"
#endif
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */
/* Det.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Initial value of the variables                                             */
/*----------------------------------------------------------------------------*/
#define PORT_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Port_MemMap.h"

#if ( ( PORT_SET_PIN_DIRECTION_API != FALSE ) || ( PORT_REFRESH_PORT_DIRECTION_API != FALSE )\
                                              || ( PORT_SET_PIN_MODE_API != FALSE ) )
#if ( PORT_DEV_ERROR_DETECT != FALSE )
static Port_70_ModuleStateType  s_portStateData = PORT_70_STATE_UNINITIALIZED;
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */
static const Port_ConfigType*   s_portConfigPtr = NULL_PTR;
#endif

#define PORT_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_CODE_LOCAL
#include "Port_MemMap.h"
/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : PORT_INIT_ID (0x00)                                          */
/* Name        : Port_Init                                                    */
/* Param       : configType : Port Config Type Table Pointer                  */
/* Return      : none                                                         */
/* Contents    : Initializes the Port Driver module.                          */
/* Author      : --                                                           */
/* Note        : [SWS_Port_00140]                                             */
/******************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr )
{
    uint16                              portNumber;  /* The number of Port pins */
    uint16_least                        lcount;      /* Counter */
    const Port_PortPinType*             portPtr;     /* Pointer to AUTOSAR configuration */

#if ( PORT_DEV_ERROR_DETECT != FALSE )
    if ( NULL_PTR == ConfigPtr ) { /* [SWS_Port_00051][SWS_Port_00087] */
        ( void )Det_ReportError( ( uint16 )PORT_MODULE_ID, ( uint8 )PORT_INSTANCE_ID,
                                 ( uint8 )PORT_INIT_ID, ( uint8 )PORT_E_INIT_FAILED );
    } else
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */
    {
        Port_70_HW_CommonInit( ConfigPtr );
        portNumber = ( ConfigPtr )->PortConfigSet->PortContainer->PortNumberOfPortPins;

        for ( lcount = 0U; lcount < portNumber; lcount++ ) {
            /* Get the configuration data */
            portPtr     = ( const Port_PortPinType* )&
                          ( ( ConfigPtr )->PortConfigSet->PortContainer->PortPin[lcount] );
            /* Call H/W dependent initialize */
            Port_70_HW_PortInit( portPtr );
        }
#if ( ( PORT_SET_PIN_DIRECTION_API != FALSE ) || ( PORT_REFRESH_PORT_DIRECTION_API != FALSE )\
                                              || ( PORT_SET_PIN_MODE_API != FALSE ) )
        /* Initialization completed */
        s_portConfigPtr = ConfigPtr;
#if ( PORT_DEV_ERROR_DETECT != FALSE )
        s_portStateData = PORT_70_STATE_INITIALIZED;
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */
#endif
    }
}

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : PORT_SET_PIN_DIRECTION_ID (0x01)                             */
/* Name        : Port_SetPinDirection                                         */
/* Param       : Pin       : Port_PinType                                     */
/*             : Direction : Port_PinDirectionType                            */
/* Return      : none                                                         */
/* Contents    : Set the Port pin Direction Processing                        */
/* Author      : --                                                           */
/* Note        : [SWS_Port_00141]                                             */
/******************************************************************************/
#if ( PORT_SET_PIN_DIRECTION_API != FALSE )
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
    const Port_PortPinType*     portPtr;

#if ( PORT_DEV_ERROR_DETECT != FALSE )
    uint16                      portNumber;
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */

#if ( PORT_DEV_ERROR_DETECT != FALSE )
    if ( PORT_70_STATE_INITIALIZED != s_portStateData ) { /* [SWS_Port_00051][SWS_Port_00087] */
        ( void )Det_ReportError( ( uint16 )PORT_MODULE_ID, ( uint8 )PORT_INSTANCE_ID,
                                 ( uint8 )PORT_SET_PIN_DIRECTION_ID, ( uint8 )PORT_E_UNINIT );
    } else
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */
    {
        portPtr = &( s_portConfigPtr->PortConfigSet->PortContainer->PortPin[Pin] );

#if ( PORT_DEV_ERROR_DETECT != FALSE ) /* [SWS_Port_00077] */
        portNumber = s_portConfigPtr->PortConfigSet->PortContainer->PortNumberOfPortPins;

        if ( Pin >= portNumber ) { /* [SWS_Port_00051][SWS_Port_00087] */
            ( void )Det_ReportError( ( uint16 )PORT_MODULE_ID, ( uint8 )PORT_INSTANCE_ID,
                                     ( uint8 )PORT_SET_PIN_DIRECTION_ID,
                                     ( uint8 )PORT_E_PARAM_PIN );
        } else if ( TRUE != portPtr->PortPinDirectionChangeable ) {
        /* [SWS_Port_00051][SWS_Port_00087] */
            ( void )Det_ReportError( ( uint16 )PORT_MODULE_ID, ( uint8 )PORT_INSTANCE_ID,
                                     ( uint8 )PORT_SET_PIN_DIRECTION_ID,
                                     ( uint8 )PORT_E_DIRECTION_UNCHANGEABLE );
        } else
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */
        {
            /* Set port pin direction */
            Port_70_HW_SetPinDirection( portPtr->PortPinId, Direction );
        }
    }
}
#endif /* #if ( PORT_SET_PIN_DIRECTION_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : PORT_REFRESH_PORT_DIRECTION_ID (0x02)                        */
/* Name        : Port_RefreshPortDirection                                    */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Shall Refresh the Direction id all configured port to        */
/*               the configured direction processing                          */
/* Author      : --                                                           */
/* Note        : [SWS_Port_00142]                                             */
/******************************************************************************/
#if ( PORT_REFRESH_PORT_DIRECTION_API != FALSE )
void Port_RefreshPortDirection( void )
{
    const Port_PortPinType*   portPtr;
    uint16_least              lcount;
    uint16                    portNumber;

#if ( PORT_DEV_ERROR_DETECT != FALSE )
    if ( PORT_70_STATE_INITIALIZED != s_portStateData ) { /* [SWS_Port_00051][SWS_Port_00087] */
        ( void )Det_ReportError( ( uint16 )PORT_MODULE_ID, ( uint8 )PORT_INSTANCE_ID,
                                 ( uint8 )PORT_REFRESH_PORT_DIRECTION_ID, ( uint8 )PORT_E_UNINIT );
    } else
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */
    {
        portNumber = s_portConfigPtr->PortConfigSet->PortContainer->PortNumberOfPortPins;

        /* Process for the number of configured pins */
        for ( lcount = 0U; lcount < portNumber; lcount++ ) {
            portPtr = &( s_portConfigPtr->PortConfigSet->PortContainer->PortPin[lcount] );
            if ( ( PORT_PIN_MODE_NONE != portPtr->PortPinMode ) &&
                 ( TRUE != portPtr->PortPinDirectionChangeable ) ) { /* [SWS_Port_00061] */
                /* Set port pin drection */
                Port_70_HW_RefreshPortDirection( portPtr->PortPinId, portPtr->PortPinDirection );
            }
        }
    }
}
#endif /* #if ( PORT_REFRESH_PORT_DIRECTION_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : PORT_GET_VERSION_INFO_ID (0x03)                              */
/* Name        : Port_GetVersionInfo                                          */
/* Param       : versionInfo : Std Version Info Type                          */
/* Return      : None                                                         */
/* Contents    : Return the version information of this module                */
/* Author      : --                                                           */
/* Note        : [SWS_Port_00143]                                             */
/******************************************************************************/
#if ( PORT_VERSION_INFO_API != FALSE )
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if ( PORT_DEV_ERROR_DETECT != FALSE )
    if ( versioninfo == NULL_PTR ) { /* [SWS_Port_00225][SWS_Port_00051][SWS_Port_00087] */
        ( void )Det_ReportError( ( uint16 )PORT_MODULE_ID, ( uint8 )PORT_INSTANCE_ID,
                                 ( uint8 )PORT_GET_VERSION_INFO_ID,
                                 ( uint8 )PORT_E_PARAM_POINTER );
    } else
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */
    {
        versioninfo->vendorID         = ( uint16 )PORT_VENDOR_ID;       /* Vendor ID */
        versioninfo->moduleID         = ( uint16 )PORT_MODULE_ID;       /* Module ID */
        versioninfo->sw_major_version = ( uint8 )PORT_SW_MAJOR_VERSION; /* Software Major Version */
        versioninfo->sw_minor_version = ( uint8 )PORT_SW_MINOR_VERSION; /* Software Minor Version */
        versioninfo->sw_patch_version = ( uint8 )PORT_SW_PATCH_VERSION; /* Software Patch Version */
    }
}
#endif /* #if ( PORT_VERSION_INFO_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : PORT_MODULE_ID (124)                                         */
/* ServiceID   : PORT_SET_PIN_MODE_ID (0x04)                                  */
/* Name        : Port_SetPinMode                                              */
/* Param       : Pin  : Port_PinType                                          */
/*             : Mode : Port_PinModeType                                      */
/* Return      : None                                                         */
/* Contents    : Shall set the port pin mode or the referenced pin            */
/*               during runtime.                                              */
/* Author      : --                                                           */
/* Note        : [SWS_Port_00145]                                             */
/******************************************************************************/
#if ( PORT_SET_PIN_MODE_API != FALSE )
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{

#if ( PORT_DEV_ERROR_DETECT != FALSE ) /* [SWS_Port_00077] */
    const Port_PortPinType*   portPtr;
    uint16                    portNumber;
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */

#if ( PORT_DEV_ERROR_DETECT != FALSE ) /* [SWS_Port_00077] */
    if ( PORT_70_STATE_INITIALIZED != s_portStateData ) { /* [SWS_Port_00051][SWS_Port_00087] */
        ( void )Det_ReportError( ( uint16 )PORT_MODULE_ID, ( uint8 )PORT_INSTANCE_ID,
                                 ( uint8 )PORT_SET_PIN_MODE_ID, ( uint8 )PORT_E_UNINIT );
    } else
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */
    {
        /* check that the specified pin is within the range */
#if ( PORT_DEV_ERROR_DETECT != FALSE ) /* [SWS_Port_00077] */
        portPtr = &( s_portConfigPtr->PortConfigSet->PortContainer->PortPin[Pin] );
        portNumber = s_portConfigPtr->PortConfigSet->PortContainer->PortNumberOfPortPins;

        if ( Pin >= portNumber ) { /* [SWS_Port_00051][SWS_Port_00087] */
            ( void )Det_ReportError( ( uint16 )PORT_MODULE_ID, ( uint8 )PORT_INSTANCE_ID,
                                     ( uint8 )PORT_SET_PIN_MODE_ID, ( uint8 )PORT_E_PARAM_PIN );
        /* check that the specified pin can be changed */
        } else if ( TRUE != portPtr->PortPinModeChangeable ) {
        /* [SWS_Port_00223][SWS_Port_00051][SWS_Port_00087] */
            ( void )Det_ReportError( ( uint16 )PORT_MODULE_ID, ( uint8 )PORT_INSTANCE_ID,
                                     ( uint8 )PORT_SET_PIN_MODE_ID,
                                     ( uint8 )PORT_E_MODE_UNCHANGEABLE );
        /* Check that the specified mode is one of the mode can be changed */
        } else if ( 0U == ( portPtr->PortPinMode & Mode ) ) { /* [SWS_Port_00051][SWS_Port_00087] */
            ( void )Det_ReportError( ( uint16 )PORT_MODULE_ID, ( uint8 )PORT_INSTANCE_ID,
                                     ( uint8 )PORT_SET_PIN_MODE_ID,
                                     ( uint8 )PORT_E_PARAM_INVALID_MODE );
        } else
#endif /* #if ( PORT_DEV_ERROR_DETECT != FALSE ) */
        {
            /* Set mode to port pin */
            Port_70_HW_SetPinMode( Pin, Mode );

        }
    }
}

#endif /* #if ( PORT_SET_PIN_MODE_API != FALSE ) */

#define PORT_STOP_SEC_CODE_LOCAL
#include "Port_MemMap.h"

/* EOF Port.c ****************************************************************/