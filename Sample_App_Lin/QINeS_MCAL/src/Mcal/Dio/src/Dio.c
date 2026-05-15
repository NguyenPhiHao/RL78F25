/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Dio.c                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    :                                                              */
/*               This specification is applicable to drivers only for on chip */
/*               DIO pins and ports.                                          */
/*               The DIO Driver provides services for reading and writing     */
/*               to/from                                                      */
/*                 DIO Channels (Pins)                                        */
/*                 DIO Ports                                                  */
/*                 DIO Channel Groups                                         */
/*               The behaviour of those services is synchronous.              */
/*               This module works on pins and ports which are configured by  */
/*               the PORT driver for this purpose. For this reason, there is  */
/*               no configuration and initialization of this port structure   */
/*               in the DIO Driver.                                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of DIO Driver                                                */
/* R22-11                                                                     */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Dio.h"
#include "Dio_70_HW.h"
 
#include "SchM_Dio.h"
#if ( DIO_DEV_ERROR_DETECT != FALSE )
#include "Det.h"
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
 
/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define DIO_70_VENDOR_ID_C                   ( 70U )
#define DIO_70_MODULE_ID_C                   ( 120U )
 
#define DIO_70_AR_RELEASE_MAJOR_VERSION_C    ( 22U )
#define DIO_70_AR_RELEASE_MINOR_VERSION_C    ( 11U )
#define DIO_70_AR_RELEASE_REVISION_VERSION_C ( 0U )
 
#define DIO_70_SW_MAJOR_VERSION_C            ( 1U )
#define DIO_70_SW_MINOR_VERSION_C            ( 0U )
#define DIO_70_SW_PATCH_VERSION_C            ( 0U )
 
/*----------------------------------------------------------------------------*/
/* FILE VERSION CHECKS                                                        */
/*----------------------------------------------------------------------------*/
 
/* Dio.h version check start */
 
#if ( DIO_70_VENDOR_ID_C != DIO_VENDOR_ID )
    #error "VENDOR ID for Dio.c and Dio.h are different"
#endif
 
#if ( DIO_70_MODULE_ID_C != DIO_MODULE_ID )
    #error "MODULE ID for Dio.c and Dio.h are different"
#endif
 
#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_C    != DIO_AR_RELEASE_MAJOR_VERSION ) || \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_C    != DIO_AR_RELEASE_MINOR_VERSION ) || \
      ( DIO_70_AR_RELEASE_REVISION_VERSION_C != DIO_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Dio.c and Dio.h are different"
#endif
 
#if ( ( DIO_70_SW_MAJOR_VERSION_C != DIO_SW_MAJOR_VERSION ) || \
      ( DIO_70_SW_MINOR_VERSION_C != DIO_SW_MINOR_VERSION ) || \
      ( DIO_70_SW_PATCH_VERSION_C != DIO_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Dio.c and Dio.h are different"
#endif
 
/* Dio.h version check end */
 
/* Dio_70_HW.h version check start */
 
#if ( DIO_70_VENDOR_ID_C != DIO_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Dio.c and Dio_70_HW.h are different"
#endif
 
#if ( DIO_70_MODULE_ID_C != DIO_70_MODULE_ID_HW_H )
    #error "MODULE ID for Dio.c and Dio_70_HW.h are different"
#endif
 
#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_C    != DIO_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_C    != DIO_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( DIO_70_AR_RELEASE_REVISION_VERSION_C != DIO_70_AR_RELEASE_REVISION_VERSION_HW_H ) \
    )
    #error "AUTOSAR Version Numbers of Dio.c and Dio_70_HW.h are different"
#endif
 
#if ( ( DIO_70_SW_MAJOR_VERSION_C != DIO_70_SW_MAJOR_VERSION_HW_H ) || \
      ( DIO_70_SW_MINOR_VERSION_C != DIO_70_SW_MINOR_VERSION_HW_H ) || \
      ( DIO_70_SW_PATCH_VERSION_C != DIO_70_SW_PATCH_VERSION_HW_H ) \
    )
    #error "Software Version Numbers of Dio.c and Dio_70_HW.h are different"
#endif
 
/* Dio_70_HW.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Dio.h version check start */
 
#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_C    != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_C    != RTE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Dio.c and SchM_Dio.h are different"
#endif
 
/* SchM_Dio.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Det.h version check start */
 
#if ( DIO_DEV_ERROR_DETECT != FALSE )
#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION ) || \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Dio.c and Det.h are different"
#endif
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
 
/* Det.h version check stop */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/*  type definitions                                                          */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define DIO_START_SEC_CODE_LOCAL
#include "Dio_MemMap.h"
 
 
#define DIO_STOP_SEC_CODE_LOCAL
#include "Dio_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/*  static functions and macros                                               */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/*  function prototype declarations                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/*  functions and function style macros                                       */
/*----------------------------------------------------------------------------*/
#define DIO_START_SEC_CODE_GLOBAL
#include "Dio_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : DIO_MODULE_ID (120)                                          */
/* ServiceID   : DIO_REDCHANNEL_ID (0x00)                                     */
/* Name        : Dio_ReadChannel                                              */
/* Param       : (in) ChannelId     reading channel id                        */
/*                                  VARIANT-POST-BUILD.                       */
/* Return      : read value                                                   */
/* Contents    : Returns the value of the specified DIO channel.              */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00133]                                              */
/******************************************************************************/
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
    Dio_PortType            port;                       /* port ID                     */
    Dio_70_PortBitPosType   bitpos;                     /* bit position                */
    Dio_LevelType           level = STD_LOW;            /* read level                  */
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    uint8                   status;                     /* return status from function */
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
 
    /* Convert from channel id to port id and bit position. */
    port    =  DIO_70_PIN_TO_PORT( ChannelId );
    bitpos  =  DIO_70_PIN_TO_BITPOS( ChannelId );
 
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    status = Dio_70_HW_ChannelCheck( port, bitpos );    /* ";" Unnecessary for macros   */
    if ( E_OK != status ) {
        /* [SWS_Dio_91001],[SWS_Dio_00074] */
        ( void )Det_ReportError( ( uint16 )DIO_MODULE_ID, ( uint8 )DIO_INSTANCE_ID,
                                 ( uint8 )DIO_READCHANNEL_ID,
                                 ( uint8 )DIO_E_PARAM_INVALID_CHANNEL_ID );
    } else
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Get the specified port level. (macro of implementation within the Port.h) */
        level = Dio_70_HW_ReadChannel( port, bitpos );
    }
    return  level;
}
 
/******************************************************************************/
/* ModuleID    : DIO_MODULE_ID (120)                                          */
/* ServiceID   : DIO_WRITECHANNEL_ID (0x01)                                   */
/* Name        : Dio_WriteChannel                                             */
/* Param       : (in) ChannelId     reading channel id                        */
/*             : (in) Level         writing level                             */
/*                                  VARIANT-POST-BUILD.                       */
/* Return      : None                                                         */
/* Contents    : Service to set a level of a channel.                         */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00134]                                              */
/******************************************************************************/
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
    Dio_PortType            port;               /* port ID                     */
    Dio_70_PortBitPosType   bitpos;             /* bit position                */
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    uint8                   status;             /* return status from function */
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
 
    /* Convert from channel id to port id and bit position. */
    port    = DIO_70_PIN_TO_PORT( ChannelId );
    bitpos  = DIO_70_PIN_TO_BITPOS( ChannelId );
 
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    status = Dio_70_HW_ChannelCheck( port, bitpos );
    if ( E_OK != status ) {
        /* [SWS_Dio_00119],[SWS_Dio_91001],[SWS_Dio_00074] */
        ( void )Det_ReportError( ( uint16 )DIO_MODULE_ID, ( uint8 )DIO_INSTANCE_ID,
                                 ( uint8 )DIO_WRITECHANNEL_ID,
                                 ( uint8 )DIO_E_PARAM_INVALID_CHANNEL_ID );
    } else
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Set Level to the specified channel. (inline Bit Change function) */
        Dio_70_HW_WriteChannel( port, bitpos, Level );
    }
}
 
/******************************************************************************/
/* ModuleID    : DIO_MODULE_ID (120)                                          */
/* ServiceID   : DIO_READPORT_ID (0x02)                                       */
/* Name        : Dio_ReadPort                                                 */
/* Param       : (in) PortId         reading port id                          */
/* Return      : read port data                                               */
/* Contents    : Returns the level of all channels of that port.              */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00135]                                              */
/******************************************************************************/
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
{
    Dio_PortLevelType   level = STD_LOW;            /* read level                  */
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    uint8               status;                     /* return status from function */
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
 
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    status = Dio_70_HW_PortCheck( PortId );
    if ( E_OK != status ) {
        /* [SWS_Dio_91001],[SWS_Dio_00075] */
        ( void )Det_ReportError( ( uint16 )DIO_MODULE_ID, ( uint8 )DIO_INSTANCE_ID,
                                 ( uint8 )DIO_READPORT_ID,
                                 ( uint8 )DIO_E_PARAM_INVALID_PORT_ID );
    } else
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Get level from the specified port. (macro of implementation within Port.h) */
        level = Dio_70_HW_ReadPort( PortId );
    }
    return  ( level ) ;
}
 
/******************************************************************************/
/* ModuleID    : DIO_MODULE_ID (120)                                          */
/* ServiceID   : DIO_WRITEPORT_ID (0x03)                                      */
/* Name        : Dio_WritePort                                                */
/* Param       : (in) portId        reading port id                           */
/*             : (in) Level         writing level                             */
/* Return      : None                                                         */
/* Contents    : Service to set a value of the port.                          */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00136]                                              */
/******************************************************************************/
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )
{
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    uint8       status;                         /* return status from function */
#endif /* #endif ( DIO_DEV_ERROR_DETECT != FALSE ) */
 
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    status = Dio_70_HW_PortCheck( PortId );
    if ( E_OK != status ) {
        /* [SWS_Dio_00119],[SWS_Dio_91001],[SWS_Dio_00075] */
        ( void )Det_ReportError( ( uint16 )DIO_MODULE_ID, ( uint8 )DIO_INSTANCE_ID,
                                 ( uint8 )DIO_WRITEPORT_ID, ( uint8 )DIO_E_PARAM_INVALID_PORT_ID );
    } else
#endif /* #endif ( DIO_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Set level to the specified port. (macro of implementation within the Port.h) */
        Dio_70_HW_WritePort( PortId, Level );
    }
}
 
/******************************************************************************/
/* ModuleID    : DIO_MODULE_ID (120)                                          */
/* ServiceID   : DIO_READCHANNELGROUP_ID (0x04)                               */
/* Name        : Dio_ReadChannelGroup                                         */
/* Param       : (in) ChannelGroupIdPtr pointer to channel group id           */
/* Return      : level of channel group                                       */
/* Contents    : This Service reads a subset of the adjoining bits of a port. */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00137]                                              */
/******************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
    Dio_PortType        portId;             /* port id                     */
    uint8               offset;             /* offset                      */
    Dio_70_PortMaskType mask;               /* mask                        */
    Dio_PortLevelType   level = STD_LOW;    /* read level                  */
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    uint8               status;             /* return status from function */
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
 
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    if ( NULL_PTR == ChannelGroupIdPtr ) {
        /* [SWS_Dio_91001] */
        ( void )Det_ReportError( ( uint16 )DIO_MODULE_ID, ( uint8 )DIO_INSTANCE_ID,
                                 ( uint8 )DIO_READCHANNELGROUP_ID, ( uint8 )DIO_E_PARAM_POINTER );
    } else
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Get channel group configuration data */
        portId  = (Dio_PortType)( ChannelGroupIdPtr->DioChannelGroupIdentification ) ;
        offset  = ChannelGroupIdPtr->DioPortOffset ;
        mask    = ChannelGroupIdPtr->DioPortMask ;
#if ( DIO_DEV_ERROR_DETECT != FALSE )
        status = Dio_70_HW_ChannelGroupCheck( portId, mask );
        if ( E_OK != status ) {
            /* [SWS_Dio_91001],[SWS_Dio_00114] */
            ( void )Det_ReportError( ( uint16 )DIO_MODULE_ID, ( uint8 )DIO_INSTANCE_ID,
                                     ( uint8 )DIO_READCHANNELGROUP_ID,
                                     ( uint8 )DIO_E_PARAM_INVALID_GROUP );
        } else
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
        {
            /* Get level from the specified port. (implementation within the PORT module) */
            level = Dio_70_HW_ReadChannelGroup( portId, offset, mask );
        }
    }
    return level;
}
 
/******************************************************************************/
/* ModuleID    : DIO_MODULE_ID (120)                                          */
/* ServiceID   : DIO_WRITECHANNELGROUP_ID (0x05)                              */
/* Name        : Dio_WriteChannelGroup                                        */
/* Param       : (in) ChannelGroupIdPtr   pointer to channel group id         */
/*             : (in) Level               level of channel group              */
/* Return      : None                                                         */
/* Contents    : Service to set a subset of the adjoining bits of a port to a */
/*             : specified level.                                             */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00138]                                              */
/******************************************************************************/
void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )
{
    Dio_PortType        portId;             /* port id                     */
    uint8               offset;             /* offset                      */
    Dio_70_PortMaskType mask;               /* mask                        */
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    uint8               status;             /* return status from function */
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
 
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    if ( NULL_PTR == ChannelGroupIdPtr ) {
        /* [SWS_Dio_00119],[SWS_Dio_91001] */
        ( void )Det_ReportError( ( uint16 )DIO_MODULE_ID, ( uint8 )DIO_INSTANCE_ID,
                                 ( uint8 )DIO_WRITECHANNELGROUP_ID, ( uint8 )DIO_E_PARAM_POINTER );
                                    /* Return due to the error */
    } else
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Get channel group configuration data */
        portId      = ( Dio_PortType )( ChannelGroupIdPtr->DioChannelGroupIdentification ) ;
        offset      = ChannelGroupIdPtr->DioPortOffset ;
        mask        = ChannelGroupIdPtr->DioPortMask ;
 
#if ( DIO_DEV_ERROR_DETECT != FALSE )
        status = Dio_70_HW_ChannelGroupCheck( portId, mask );
        if ( E_OK != status ) {
            /* [SWS_Dio_00119],[SWS_Dio_91001],[SWS_Dio_00114] */
            ( void )Det_ReportError( ( uint16 )DIO_MODULE_ID, ( uint8 )DIO_INSTANCE_ID,
                                     ( uint8 )DIO_WRITECHANNELGROUP_ID,
                                     ( uint8 )DIO_E_PARAM_INVALID_GROUP);
        } else
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
        {
            /* set level to the specified port. (implementation within the PORT module) */
            Dio_70_HW_WriteChannelGroup( Level, portId, offset, mask );
        }
    }
}
 
/******************************************************************************/
/* ModuleID    : DIO_MODULE_ID (120)                                          */
/* ServiceID   : DIO_VERSIONINFO_ID (0x12)                                    */
/* Name        : Dio_GetVersionInfo                                           */
/* Param       : (out)  Versioninfo     Std_VersionInfoType*                  */
/* Return      : None                                                         */
/* Contents    : Dio Get Version info processing                              */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00139]                                              */
/******************************************************************************/
#if ( DIO_VERSION_INFO_API != FALSE )
void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo )
{
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    if ( NULL_PTR == VersionInfo ) {
        /* [SWS_Dio_91001] */
        ( void )Det_ReportError( ( uint16 )DIO_MODULE_ID, ( uint8 )DIO_INSTANCE_ID,
                                 ( uint8 )DIO_GET_VERSION_INFO_ID, ( uint8 )DIO_E_PARAM_POINTER );
    } else
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
    {
        VersionInfo->vendorID         = (uint16)DIO_VENDOR_ID;          /* Vendor ID */
        VersionInfo->moduleID         = (uint16)DIO_MODULE_ID;          /* Module ID */
        VersionInfo->sw_major_version = (uint8 )DIO_SW_MAJOR_VERSION;   /* Software Major Version */
        VersionInfo->sw_minor_version = (uint8 )DIO_SW_MINOR_VERSION;   /* Software Minor Version */
        VersionInfo->sw_patch_version = (uint8 )DIO_SW_PATCH_VERSION;   /* Software Patch Version */
    }
}
#endif /* #if ( DIO_VERSION_INFO_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : DIO_MODULE_ID (120)                                          */
/* ServiceID   : DIO_FLIPCHANNEL_ID (0x11)                                    */
/* Name        : Dio_FlipChannel                                              */
/* Param       : (in) channelID       the channel to flip                     */
/* Return      : the level of the channel after flip                          */
/* Contents    : Service to flip(change from 1 to 0 or from 0 to 1) the level */
/*             : of a channel and return the level of the channel after flip. */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00190]                                              */
/******************************************************************************/
#if ( DIO_FLIPCHANNEL_API != FALSE )
Dio_LevelType Dio_FlipChannel( const Dio_ChannelType ChannelId )
{
    Dio_PortType            port;               /* port ID                     */
    Dio_70_PortBitPosType   bitpos;             /* bit position                */
    Dio_LevelType           level = STD_LOW;    /* read level                  */
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    uint8                   status;             /* return status from function */
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
 
    /* Convert from channel id to port id and bit position. */
    port    = (uint8)DIO_70_PIN_TO_PORT( ChannelId );
    bitpos  = (uint8)DIO_70_PIN_TO_BITPOS( ChannelId );
 
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    status = Dio_70_HW_ChannelCheck( port, bitpos );
    if ( E_OK != status ) {
        /* [SWS_Dio_91001] */
        ( void )Det_ReportError( ( uint16 )DIO_MODULE_ID, ( uint8 )DIO_INSTANCE_ID,
                                 ( uint8 )DIO_FLIPCHANNEL_ID,
                                 ( uint8 )DIO_E_PARAM_INVALID_CHANNEL_ID );
    } else
#endif /* #if ( DIO_DEV_ERROR_DETECT != FALSE ) */
    {
        /* flip the value from the specified port register (Bit change Type Function) */
        level = Dio_70_HW_FlipChannel( port, bitpos );
    }
    return level;
}
#endif /* #if ( DIO_FLIPCHANNEL_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : DIO_MODULE_ID (120)                                          */
/* ServiceID   : DIO_MASKEDWRITEPORT_ID (0x13)                                */
/* Name        : Dio_MaskedWritePort                                          */
/* Param       : (in) portId        reading port id                           */
/*             : (in) Level         writing level                             */
/*             : (in) Mask          Channels to be masked in the port         */
/* Return      : None                                                         */
/* Contents    : Service to set the value of a given port with required mask. */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00300]                                              */
/******************************************************************************/
#if ( DIO_MASKED_WRITE_PORT_API != FALSE )
void Dio_MaskedWritePort( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask )
{
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    uint8               status;                     /* return status from function */
#endif /* #endif ( DIO_DEV_ERROR_DETECT != FALSE ) */
 
#if ( DIO_DEV_ERROR_DETECT != FALSE )
    status = Dio_70_HW_PortCheck( PortId );
    if ( E_OK != status ) {
        /* [SWS_Dio_00075],[SWS_Dio_91001] */
        ( void )Det_ReportError( ( uint16 )DIO_MODULE_ID, ( uint8 )DIO_INSTANCE_ID,
                                 ( uint8 )DIO_MASKEDWRITEPORT_ID,
                                 ( uint8 )DIO_E_PARAM_INVALID_PORT_ID );
    } else
#endif /* #endif ( DIO_DEV_ERROR_DETECT != FALSE ) */
    {
        /* set the value of a given port with required mask */
        Dio_70_HW_MaskedWritePort( PortId, Level, Mask );
    }
}
#endif /* #if ( DIO_MASKED_WRITE_PORT_API != FALSE ) */
 
#define DIO_STOP_SEC_CODE_GLOBAL
#include "Dio_MemMap.h"
 
/* EOF Dio.c ******************************************************************/