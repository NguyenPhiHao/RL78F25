/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : LinIf.h                                                      */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/
/* Specification of CAN Interface                                             */
/* AUTOSAR Release R22-11                                                     */

#ifndef LINIF_H
#define LINIF_H

/*----------------------------------------------------------------------------*/
/* Include Files                                                              */
/*----------------------------------------------------------------------------*/
#include "EcuM.h"
#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
/* [SWS_LinIf_00715] */
void LinIf_WakeupConfirmation( EcuM_WakeupSourceType WakeupSource );

/* [SWS_LinIf_91007] */
void LinIf_LinErrorIndication( NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus );

/* [SWS_LinIf_91005] */
void LinIf_RxIndication( NetworkHandleType Channel, uint8* Lin_SduPtr );

/* [SWS_LinIf_91006] */
void LinIf_TxConfirmation( NetworkHandleType Channel );

/* [SWS_LinIf_91004] */
Std_ReturnType LinIf_HeaderIndication( NetworkHandleType Channel, Lin_PduType* PduPtr );

#endif /* LINIF_H */

/* EOF LinIf.h ****************************************************************/
