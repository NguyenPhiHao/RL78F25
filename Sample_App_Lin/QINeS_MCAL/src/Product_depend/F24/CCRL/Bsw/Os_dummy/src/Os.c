/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Os.c                                                         */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Os.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#pragma inline_asm os_disable_all_interrupts
static void os_disable_all_interrupts( void )
{
    di
}

#pragma inline_asm os_enable_all_interrupts
static void os_enable_all_interrupts( void )
{
    ei
}

void DisableAllInterrupts( void )
{
    os_disable_all_interrupts();
}

void EnableAllInterrupts( void )
{
    os_enable_all_interrupts();
}

StatusType GetCounterValue( CounterType CounterID, TickRefType *Value )
{
    (*Value) = 10U;
    return E_OK;
}

StatusType GetElapsedValue( CounterType CounterID,
                           TickRefType    Value,
                           TickRefType   *ElapsedValue )
{
    (*ElapsedValue) = 10U;
    (*Value)       += (*ElapsedValue);
    return E_OK;
}

/* EOF Os.c *******************************************************************/
