/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : CanIf_Types.h                                                */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef uint8 CanIf_ControllerModeType;
#define CANIF_CS_UNINIT                    ( ( CanIf_ControllerModeType )0x00U )
#define CANIF_CS_SLEEP                     ( ( CanIf_ControllerModeType )0x01U )
#define CANIF_CS_STARTED                   ( ( CanIf_ControllerModeType )0x02U )
#define CANIF_CS_STOPPED                   ( ( CanIf_ControllerModeType )0x03U )

#endif /* CANIF_TYPES_H */

/* EOF CanIf_Types.h **********************************************************/
