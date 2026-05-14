/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Spi.h                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/
#ifndef SCHM_SPI_H
#define SCHM_SPI_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(void, RTE_CODE) SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );

extern FUNC(void, RTE_CODE) SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );

#endif /* SCHM_SPI_H */

/* EOF SchM_Spi.h *************************************************************/
