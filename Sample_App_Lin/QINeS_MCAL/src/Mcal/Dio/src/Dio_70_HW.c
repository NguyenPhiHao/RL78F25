/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Dio_70_HW.c                                                  */
/* Version     : v1.00.01                                                     */
/* Contents    : DIO Module wrapper                                           */
/*               The DIO is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of DIO Module wrapper                                        */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Dio.h"
#include "Dio_70_HW.h"

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define DIO_70_VENDOR_ID_HW_C                   ( 70U )
#define DIO_70_MODULE_ID_HW_C                   ( 120U )

#define DIO_70_AR_RELEASE_MAJOR_VERSION_HW_C    ( 22U )
#define DIO_70_AR_RELEASE_MINOR_VERSION_HW_C    ( 11U )
#define DIO_70_AR_RELEASE_REVISION_VERSION_HW_C ( 0U )

#define DIO_70_SW_MAJOR_VERSION_HW_C            ( 1U )
#define DIO_70_SW_MINOR_VERSION_HW_C            ( 0U )
#define DIO_70_SW_PATCH_VERSION_HW_C            ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Dio.h version check start */

#if ( DIO_70_VENDOR_ID_HW_C != DIO_VENDOR_ID )
    #error "VENDOR ID for Dio_70_HW.c and Dio.h are different"
#endif

#if ( DIO_70_MODULE_ID_HW_C != DIO_MODULE_ID )
    #error "MODULE ID for Dio_70_HW.c and Dio.h are different"
#endif

#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_HW_C    != DIO_AR_RELEASE_MAJOR_VERSION    )  || \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_HW_C    != DIO_AR_RELEASE_MINOR_VERSION    )  || \
      ( DIO_70_AR_RELEASE_REVISION_VERSION_HW_C != DIO_AR_RELEASE_REVISION_VERSION )     \
    )
    #error "AUTOSAR Version Numbers of Dio_70_HW.c and Dio.h are different"
#endif

#if ( ( DIO_70_SW_MAJOR_VERSION_HW_C != DIO_SW_MAJOR_VERSION ) || \
      ( DIO_70_SW_MINOR_VERSION_HW_C != DIO_SW_MINOR_VERSION ) || \
      ( DIO_70_SW_PATCH_VERSION_HW_C != DIO_SW_PATCH_VERSION )    \
    )
    #error "Software Version Numbers of Dio_70_HW.c and Dio.h are different"
#endif

/* Dio.h version check end */

/* Dio_70_HW.h version check start */

#if ( DIO_70_VENDOR_ID_HW_C != DIO_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Dio_70_HW.c and Dio_70_HW.h are different"
#endif

#if ( DIO_70_MODULE_ID_HW_C != DIO_70_MODULE_ID_HW_H )
    #error "MODULE ID for Dio_70_HW.c and Dio_70_HW.h are different"
#endif

#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_HW_C    != DIO_70_AR_RELEASE_MAJOR_VERSION_HW_H    )  ||  \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_HW_C    != DIO_70_AR_RELEASE_MINOR_VERSION_HW_H    )  ||  \
      ( DIO_70_AR_RELEASE_REVISION_VERSION_HW_C != DIO_70_AR_RELEASE_REVISION_VERSION_HW_H )      \
    )
    #error "AUTOSAR Version Numbers of Dio_70_HW.c and Dio_70_HW.h are different"
#endif

#if ( ( DIO_70_SW_MAJOR_VERSION_HW_C != DIO_70_SW_MAJOR_VERSION_HW_H )  ||  \
      ( DIO_70_SW_MINOR_VERSION_HW_C != DIO_70_SW_MINOR_VERSION_HW_H )  ||  \
      ( DIO_70_SW_PATCH_VERSION_HW_C != DIO_70_SW_PATCH_VERSION_HW_H )      \
    )
    #error "Software Version Numbers of Dio_70_HW.c and Dio_70_HW.h are different"
#endif

/* Dio_70_HW.h version check end */

/*----------------------------------------------------------------------------*/
/*  type definitions                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Initial value of the variables                                             */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*  Local functions and macros                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*  Global functions                                                          */
/*----------------------------------------------------------------------------*/
#define DIO_START_SEC_CODE_LOCAL
#include "Dio_MemMap.h"
/******************************************************************************/
/* ModuleID    : MODULE_ID_DIO (120)                                          */
/* ServiceID   : --                                                           */
/* Name        : Dio_70_HW_ReadChannelGroup                                   */
/* Param       : (in) portId ID of DIO Port                                   */
/*             : (in) offset The shifting valuel                              */
/*             : (in) mask   The masking value of the channel group           */
/* Return      : This Service reads a subset of the adjoining bits of a port. */
/* Contents    : Read value of channel group                                  */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00137]                                              */
/******************************************************************************/
Dio_PortLevelType Dio_70_HW_ReadChannelGroup( Dio_PortType portId, uint8 offset,
                                              Dio_70_PortMaskType mask )
{
    Dio_PortLevelType   level;    /* read level */
 
    /* Get level from the specified port. (implementation within the PORT module) */
    level = Port_70_RL78F2X_GetReg( PORT_70_RL78F2X_DIO_Px( portId ) );
    level = ( level & mask ) >> offset;
 
    return level;
}

/******************************************************************************/
/* ModuleID    : MODULE_ID_DIO (120)                                          */
/* ServiceID   : --                                                           */
/* Name        : Dio_70_HW_WriteChannelGroup                                  */
/* Param       : (in) Level  level of channel group                           */
/*             : (in) portId ID of DIO Port                                   */
/*             : (in) offset The shifting valuel                              */
/*             : (in) mask   The masking value of the channel group           */
/* Return      : void                                                         */
/* Contents    : Service to set a subset of the adjoining bits of a port to a */
/*             : specified level.                                             */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00138]                                              */
/******************************************************************************/
void  Dio_70_HW_WriteChannelGroup( Dio_PortLevelType Level, Dio_PortType portId, uint8 offset,
                                   Dio_70_PortMaskType mask )
{
    uint8               readVal;            /* read  value */
    Dio_PortLevelType   writeVal;           /* write value */
 
    /* Get level from the specified port. (implementation within the PORT module) */
    readVal  = Port_70_RL78F2X_GetReg( PORT_70_RL78F2X_DIO_Px( portId ) );
    writeVal = ( readVal & ( uint8 )(~mask) ) | ( ( uint8 )( Level << offset ) & mask );
    /* set level to the specified port. (implementation within the PORT module) */
    Port_70_RL78F2X_SetReg( PORT_70_RL78F2X_DIO_Px( portId ), writeVal );
}

/******************************************************************************/
/* ModuleID    : MODULE_ID_DIO (120)                                          */
/* ServiceID   : --                                                           */
/* Name        : Dio_70_HW_MaskedWritePort                                    */
/* Param       : (in) PortId ID of DIO Port                                   */
/*             : (in) Level  Value to be written                              */
/*             : (in) Mask Channels to be masked in the port                  */
/* Return      : void                                                         */
/* Contents    : Service to set the value of a given port with required mask. */
/* Author      : --                                                           */
/* Note        : [SWS_Dio_00300]                                              */
/******************************************************************************/
#if ( DIO_MASKED_WRITE_PORT_API != FALSE )
void  Dio_70_HW_MaskedWritePort( Dio_PortType PortId, Dio_PortLevelType Level,
                                 Dio_PortLevelType Mask )
{
    uint8               readVal;            /* read  value */
    Dio_PortLevelType   writeVal;           /* write value */
 
    /* Get level from the specified port. (implementation within the PORT module) */
    /* [SWS_Dio_00200],[SWS_Dio_00202],[SWS_Dio_00201],[SWS_Dio_00203],[SWS_Dio_00204] */
    readVal  = Port_70_RL78F2X_GetReg( PORT_70_RL78F2X_DIO_Px( PortId ) );
    /* Calculate the new value based on the mask and level */
    writeVal = ( readVal & ( uint8 )( ~Mask ) ) | ( Level & Mask );
    /* set level to the specified port. (implementation within the PORT module) */
    Port_70_RL78F2X_SetReg( PORT_70_RL78F2X_DIO_Px( PortId ), writeVal );
}
#endif /* #if ( DIO_MASKED_WRITE_PORT_API != FALSE ) */
#define DIO_STOP_SEC_CODE_LOCAL
#include "Dio_MemMap.h"

/* EOF Dio_70_HW.c  ***********************************************************/