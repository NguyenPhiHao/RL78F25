/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Os.h                                                         */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef _OS_DUMMY_H_
#define _OS_DUMMY_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef signed char            OS_SINT8_t;
typedef OS_SINT8_t             OsObjectType_t;
typedef OsObjectType_t         AppModeType;
typedef uint32                 TickType;
typedef TickType*              TickRefType;

typedef uint32                 CounterType;
#define HARDWARE               ((CounterType)0U)
#define SOFTWARE               ((CounterType)1U)

typedef uint8                  StatusType;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern void DisableAllInterrupts( void );
extern void EnableAllInterrupts( void );
extern StatusType GetCounterValue( CounterType CounterID, TickRefType Value );
extern StatusType GetElapsedValue( CounterType CounterID, TickRefType Value, TickRefType ElapsedValue );

#endif /* _DUMMY_H_ */

/* EOF Os.h *******************************************************************/
