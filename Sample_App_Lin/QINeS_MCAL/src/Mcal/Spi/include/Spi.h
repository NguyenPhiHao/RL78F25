/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Spi.h                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    : This is header file for AUTOSAR SPI Driver module            */
/*               The SPI Handler/Driver provides services for reading from    */
/*               and writing to devices connected via SPI busses.             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */
 
#ifndef SPI_H_
#define SPI_H_
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Spi_Cfg.h"
#include "Spi_70_Types.h"
#include "Spi_70_HW.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_VENDOR_ID                      (70U)
#define SPI_MODULE_ID                      (83U)
 
#define SPI_AR_RELEASE_MAJOR_VERSION       (22U)
#define SPI_AR_RELEASE_MINOR_VERSION       (11U)
#define SPI_AR_RELEASE_REVISION_VERSION    (0U)
 
#define SPI_SW_MAJOR_VERSION               (1U)
#define SPI_SW_MINOR_VERSION               (0U)
#define SPI_SW_PATCH_VERSION               (0U)
 
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/* Std_Types.h version check start */
 
#if ( ( SPI_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Spi.h and Std_Types.h are different"
#endif
 
/* Std_Types.h version check end */
 
/* Spi_Cfg.h version check start */
 
#if ( SPI_VENDOR_ID != SPI_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Spi.h and Spi_Cfg.h are different"
#endif
 
#if ( SPI_MODULE_ID != SPI_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Spi.h and Spi_Cfg.h are different"
#endif
 
#if ( ( SPI_AR_RELEASE_MAJOR_VERSION    != SPI_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( SPI_AR_RELEASE_MINOR_VERSION    != SPI_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( SPI_AR_RELEASE_REVISION_VERSION != SPI_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Spi.h and Spi_Cfg.h are different"
#endif
 
#if ( ( SPI_SW_MAJOR_VERSION != SPI_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( SPI_SW_MINOR_VERSION != SPI_70_SW_MINOR_VERSION_CFG_H ) || \
      ( SPI_SW_PATCH_VERSION != SPI_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Spi.h and Spi_Cfg.h are different"
#endif
 
/* Spi_Cfg.h version check end */
 
/* Spi_70_Types.h version check start */
 
#if ( SPI_VENDOR_ID != SPI_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Spi.h and Spi_70_Types.h are different"
#endif
 
#if ( SPI_MODULE_ID != SPI_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Spi.h and Spi_70_Types.h are different"
#endif
 
#if ( ( SPI_AR_RELEASE_MAJOR_VERSION    != SPI_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( SPI_AR_RELEASE_MINOR_VERSION    != SPI_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( SPI_AR_RELEASE_REVISION_VERSION != SPI_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Spi.h and Spi_70_Types.h are different"
#endif
 
#if ( ( SPI_SW_MAJOR_VERSION != SPI_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( SPI_SW_MINOR_VERSION != SPI_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( SPI_SW_PATCH_VERSION != SPI_70_SW_PATCH_VERSION_TYPES_H ) \
    )
    #error "Software Version Numbers of Spi.h and Spi_70_Types.h are different"
#endif
 
/* Spi_70_Types.h version check end */
 
/* Spi_70_HW.h version check start */
 
#if ( SPI_VENDOR_ID != SPI_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Spi.h and Spi_70_HW.h are different"
#endif
 
#if ( SPI_MODULE_ID != SPI_70_MODULE_ID_HW_H )
    #error "MODULE ID for Spi.h and Spi_70_HW.h are different"
#endif
 
#if ( ( SPI_AR_RELEASE_MAJOR_VERSION    != SPI_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( SPI_AR_RELEASE_MINOR_VERSION    != SPI_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( SPI_AR_RELEASE_REVISION_VERSION != SPI_70_AR_RELEASE_REVISION_VERSION_HW_H ) \
    )
    #error "AUTOSAR Version Numbers of Spi.h and Spi_70_HW.h are different"
#endif
 
#if ( ( SPI_SW_MAJOR_VERSION != SPI_70_SW_MAJOR_VERSION_HW_H ) || \
      ( SPI_SW_MINOR_VERSION != SPI_70_SW_MINOR_VERSION_HW_H ) || \
      ( SPI_SW_PATCH_VERSION != SPI_70_SW_PATCH_VERSION_HW_H ) \
    )
    #error "Software Version Numbers of Spi.h and Spi_70_HW.h are different"
#endif
 
/* Spi_70_HW.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* SPI module instance Id */
#define     SPI_INSTANCE_ID                     ( 0U )
 
/* API service ID's */
#define SPI_INIT_ID                             ( 0x00U )
#define SPI_DEINIT_ID                           ( 0x01U )
#define SPI_WRITEIB_ID                          ( 0x02U )
#define SPI_ASYNCTRANSMIT_ID                    ( 0x03U )
#define SPI_READIB_ID                           ( 0x04U )
#define SPI_SETUPEB_ID                          ( 0x05U )
#define SPI_GETSTATUS_ID                        ( 0x06U )
#define SPI_GETJOBRESULT_ID                     ( 0x07U )
#define SPI_GETSEQUENCERESULT_ID                ( 0x08U )
#define SPI_GETVERSIONINFO_ID                   ( 0x09U )
#define SPI_SYNCTRANSMIT_ID                     ( 0x0AU )
#define SPI_GETHWUNITSTATUS_ID                  ( 0x0BU )
#define SPI_CANCEL_ID                           ( 0x0CU )
#define SPI_SETASYNCMODE_ID                     ( 0x0DU )
#define SPI_MAINFUNCTION_HANDLING_ID            ( 0x10U )
 
/* DET errors that the SPI can produce. */
#define SPI_E_PARAM_CHANNEL                     ( 0x0AU )
#define SPI_E_PARAM_JOB                         ( 0x0BU )
#define SPI_E_PARAM_SEQ                         ( 0x0CU )
#define SPI_E_PARAM_LENGTH                      ( 0x0DU )
#define SPI_E_PARAM_UNIT                        ( 0x0EU )
#define SPI_E_PARAM_POINTER                     ( 0x10U )
#define SPI_E_UNINIT                            ( 0x1AU )
#define SPI_E_SEQ_PENDING                       ( 0x2AU )
#define SPI_E_SEQ_IN_PROCESS                    ( 0x3AU )
#define SPI_E_ALREADY_INITIALIZED               ( 0x4AU )
 
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* external constant                                                          */
/*----------------------------------------------------------------------------*/
extern const Spi_ConfigType   Spi_ConfigData;
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern void Spi_Init( const Spi_ConfigType* ConfigPtr );
extern Std_ReturnType Spi_DeInit( void );
 
#if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IB ) || \
      ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) )
extern Std_ReturnType Spi_WriteIB( Spi_ChannelType Channel, const Spi_DataBufferType* DataBufferPtr );
extern Std_ReturnType Spi_ReadIB( Spi_ChannelType Channel, Spi_DataBufferType* DataBufferPtr );
#endif /* #if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IB ) ||
                ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) ) */
 
#if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_EB ) || \
      ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) )
extern Std_ReturnType Spi_SetupEB( Spi_ChannelType Channel, const Spi_DataBufferType* SrcDataBufferPtr,
                                   Spi_DataBufferType* DesDataBufferPtr, Spi_NumberOfDataType Length );
#endif /* #if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_EB ) ||
                ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) ) */
 
extern Spi_StatusType Spi_GetStatus( void );
extern Spi_JobResultType Spi_GetJobResult( Spi_JobType Job );
extern Spi_SeqResultType Spi_GetSequenceResult( Spi_SequenceType Sequence );
 
#if ( SPI_VERSION_INFO_API == TRUE )
extern void Spi_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif /* #if ( SPI_VERSION_INFO_API == TRUE ) */
 
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_0 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
extern Std_ReturnType Spi_SyncTransmit( Spi_SequenceType Sequence );
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_0 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
 
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
extern Std_ReturnType Spi_AsyncTransmit( Spi_SequenceType Sequence );
#if ( SPI_CANCEL_API == TRUE )
extern void Spi_Cancel( Spi_SequenceType Sequence );
#endif /* #if ( SPI_CANCEL_API == TRUE ) */
extern Std_ReturnType Spi_SetAsyncMode( Spi_AsyncModeType Mode );
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
 
#if ( SPI_HW_STATUS_API == TRUE )
extern Spi_StatusType Spi_GetHWUnitStatus( Spi_HWUnitType HWUnit );
#endif /* #if ( SPI_HW_STATUS_API == TRUE ) */
 
extern void Spi_MainFunction_Handling ( void );
extern void Spi_70_SndRcvIntr( Spi_HWUnitType HWUnit );
 
extern void Spi_70_Isr_HW00_SndRcvIntr( void );
extern void Spi_70_Isr_HW01_SndRcvIntr( void );
extern void Spi_70_Isr_HW10_SndRcvIntr( void );
extern void Spi_70_Isr_HW11_SndRcvIntr( void );
#endif      /* #ifndef SPI_H_ */
 
/* EOF Spi.h *****************************************************************/