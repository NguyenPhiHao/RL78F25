/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Spi.c                                                        */
/* Version     : v1.00.01                                                     */
/* Contents    : The SPI Handler/Driver provides services for reading from    */
/*               and writing to devices connected via SPI busses. It provides */
/*               access to SPI communication to several users like EEPROM,    */
/*               Watchdog, I/O ASICs). It also provides the required          */
/*               mechanism to configure the on-chip SPI peripheral. This file */
/*               contains the static code for the SPI Driver                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
 
#include "Spi.h"
 
#if ( SPI_70_DEM_SET_EVENT_STATUS != 0U )
#include "Dem.h"
#endif    /* SPI_70_DEM_SET_EVENT_STATUS != 0U */
#if ( SPI_DEV_ERROR_DETECT != FALSE )
#include "Det.h"
#endif      /* #if ( SPI_DEV_ERROR_DETECT != FALSE ) */
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_C                      (70U)
#define SPI_70_MODULE_ID_C                      (83U)
 
#define SPI_70_AR_RELEASE_MAJOR_VERSION_C       (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_C       (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_C    (0U)
 
#define SPI_70_SW_MAJOR_VERSION_C               (1U)
#define SPI_70_SW_MINOR_VERSION_C               (0U)
#define SPI_70_SW_PATCH_VERSION_C               (0U)
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/* Spi.h version check start */
 
#if ( SPI_70_VENDOR_ID_C != SPI_VENDOR_ID )
    #error "VENDOR ID for Spi.c and Spi.h are different"
#endif
 
#if ( SPI_70_MODULE_ID_C != SPI_MODULE_ID )
    #error "MODULE ID for Spi.c and Spi.h are different"
#endif
 
#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_C    != SPI_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_C    != SPI_AR_RELEASE_MINOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_C != SPI_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Spi.c and Spi.h are different"
#endif
 
#if ( ( SPI_70_SW_MAJOR_VERSION_C != SPI_SW_MAJOR_VERSION ) || \
      ( SPI_70_SW_MINOR_VERSION_C != SPI_SW_MINOR_VERSION ) || \
      ( SPI_70_SW_PATCH_VERSION_C != SPI_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Spi.c and Spi.h are different"
#endif
 
/* Spi.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
#if ( SPI_DEV_ERROR_DETECT != FALSE )
/* Det.h version check start */
 
#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Spi.c and Det.h are different"
#endif
 
/* Det.h version check end */
#endif      /* #if ( SPI_DEV_ERROR_DETECT != FALSE ) */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define SPI_WIDTH_TWO                    ( (uint32)2U )
 
/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* extern variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#define SPI_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Spi_MemMap.h"
 
static const Spi_ConfigType* s_ConfigPtr = NULL_PTR;
 
static Spi_70_SeqInfoType s_SeqInfo[SPI_MAX_SEQUENCE] = { 0 };
static Spi_70_JobInfoType s_JobInfo[SPI_MAX_JOB] = { 0 };
static Spi_70_ChInfoType s_ChannelInfo[SPI_MAX_CHANNEL] = { 0 };
static Spi_70_HwUnitInfoType s_HwUnitInfo[SPI_70_MAX_HW_UNIT_USING] = { 0 };
 
static Spi_StatusType s_ModuleStatus = SPI_UNINIT; /* [SWS_Spi_00011] */
 
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
static Spi_AsyncModeType s_AsyncMode = SPI_POLLING_MODE;
#endif
 
#define SPI_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Spi_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* static function prototype declarations                                     */
/*----------------------------------------------------------------------------*/
static Std_ReturnType spi_startSeq( Spi_70_SeqInfoType* seqInfo, Spi_70_FuncModeType mode );
static Std_ReturnType spi_transmitReceiveSeq( Spi_70_SeqInfoType* seqInfo,
                                              Spi_70_FuncModeType mode );
static void spi_stopSeq( Spi_70_SeqInfoType* seqInfo, Spi_70_SeqResultType seqResult,
                         Spi_70_FuncModeType mode );
static Std_ReturnType spi_transmitReceiveJob( Spi_70_JobInfoType* jobInfo,
                                              Spi_70_FuncModeType mode );
static Std_ReturnType spi_startJob( Spi_70_JobInfoType* jobInfo, Spi_70_FuncModeType mode );
static void spi_stopJob( Spi_70_JobInfoType* jobInfo, Spi_JobResultType JobResult,
                         Spi_70_FuncModeType mode );
static Std_ReturnType spi_startChannel( const Spi_70_ChInfoType* chInfo,
                                        Spi_70_HwUnitInfoType* hwUnitInfo,
                                        const Spi_ExternalDeviceType* exDevConf );
static Std_ReturnType spi_transmitChannel( const Spi_70_ChInfoType* chInfo,
                                           Spi_70_HwUnitInfoType* hwUnitInfo );
static Std_ReturnType spi_receiveChannel( const Spi_70_ChInfoType* chInfo,
                                          Spi_70_HwUnitInfoType* hwUnitInfo );
static void spi_stopChannel( Spi_70_HwUnitInfoType* hwUnitInfo,
                             const Spi_ExternalDeviceType* exDevConf );
 
/*----------------------------------------------------------------------------*/
/* function definitions and function style macros                             */
/*----------------------------------------------------------------------------*/
#define SPI_START_SEC_CODE_LOCAL
#include "Spi_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_INIT_ID (0x00)                                           */
/* Name        : Spi_Init                                                     */
/* Param       : (in) ConfigPtr : Pointer to configuration.                   */
/* Return      : void                                                         */
/* Contents    : Spi Init processing                                          */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00175]                                              */
/*----------------------------------------------------------------------------*/
void Spi_Init( const Spi_ConfigType* ConfigPtr )
{
    uint16_least cnt;
    uint16_least ibCnt;
    const Spi_DriverType* drvPtr;
    const Spi_70_HW_HwUnitConfType* hwUnitConfPtr;
    const Spi_SequenceConfigurationType* seqConfPtr;
    const Spi_JobConfigurationType* jobConfPtr;
    const Spi_ChannelConfigurationType* chConfPtr;
    const Spi_70_ChannelIBLinkType* ibConfPtr;
   
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    if ( SPI_UNINIT != s_ModuleStatus ) {
        /* [SWS_Spi_00233][SWS_Spi_00246] */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                 ( uint8 )SPI_INIT_ID, ( uint8 )SPI_E_ALREADY_INITIALIZED );
        return;
    } else if ( ( Spi_ConfigType* )NULL_PTR == ConfigPtr ) {
        /* [QINeS_SWS_SPI_00044] */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                 ( uint8 )SPI_INIT_ID, ( uint8 )SPI_E_PARAM_POINTER );
        return;
    } else
#endif /* SPI_DEV_ERROR_DETECT */
    {
        /* Save config */
        s_ConfigPtr = ConfigPtr;
       
        drvPtr = &(s_ConfigPtr->SpiDriver);
       
        /* Initialize hw unit information */
        for ( cnt = 0U; cnt < (uint16_least)SPI_70_MAX_HW_UNIT_USING; cnt++ ) {
            hwUnitConfPtr               = &(drvPtr->Spi_70_HwUnitConfPtr[cnt]);
            s_HwUnitInfo[cnt].HwUnit    = hwUnitConfPtr->SpiHwUnitCh;
            s_HwUnitInfo[cnt].HwUnitConfPtr = hwUnitConfPtr;
            s_HwUnitInfo[cnt].ChStatus  = SPI_70_CH_STOP;
            s_HwUnitInfo[cnt].ChDataCnt = 0U;
        }
       
        /* [SWS_Spi_00015] */
        /* Initialize sequence information */
        for ( cnt = 0U; cnt < (uint16_least)SPI_MAX_SEQUENCE; cnt++ ) {
            seqConfPtr = &(drvPtr->SpiSequence[cnt]);
            s_SeqInfo[cnt].SeqId = seqConfPtr->SpiSequenceId;
            s_SeqInfo[cnt].SeqConfPtr = seqConfPtr;
            s_SeqInfo[cnt].SeqResult = SPI_SEQ_OK;
            s_SeqInfo[cnt].JobIndex = 0U;
        }
       
        /* [SWS_Spi_00015] */
        /* Initialize job information */
        for ( cnt = 0U; cnt < SPI_MAX_JOB; cnt++ ) {
            jobConfPtr = &(drvPtr->SpiJob[cnt]);
            s_JobInfo[cnt].JobId      = jobConfPtr->SpiJobId;
            s_JobInfo[cnt].JobConfPtr = jobConfPtr;
            s_JobInfo[cnt].JobResult  = SPI_JOB_OK;
            s_JobInfo[cnt].ChIndex    = 0U;
        }
       
        /* Initialize channel information */
        for ( cnt = 0U; cnt < (uint16_least)SPI_MAX_CHANNEL; cnt++ ) {
            chConfPtr = &(drvPtr->SpiChannel[cnt]);
            s_ChannelInfo[cnt].ChId          = chConfPtr->SpiChannelId;
            s_ChannelInfo[cnt].ChConfPtr     = chConfPtr;
            if ( SPI_70_BUFFER_IB == chConfPtr->SpiChannelType ) {
#if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IB ) || \
      ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) )
                /* Search IB */
                for ( ibCnt = 0U; ibCnt < (uint16_least)SPI_70_NUM_OF_CHIBLINK; ibCnt++ ) {
                    ibConfPtr = &(drvPtr->Spi_70_ChIBLink[ibCnt]);
                    if ( chConfPtr->SpiChannelId == ibConfPtr->SpiChannelId ) {
                        s_ChannelInfo[cnt].ChTxBufferPtr = ibConfPtr->ChTxBufferPtr;
                        s_ChannelInfo[cnt].ChRxBufferPtr = ibConfPtr->ChRxBufferPtr;
                       
                        /* 1 element 16bit */
                        s_ChannelInfo[cnt].ChDataNum     = chConfPtr->SpiIbNBuffers;
                    }
                }
#endif
            } else {
#if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_EB ) || \
      ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) )
                /* EB */
                s_ChannelInfo[cnt].ChTxBufferPtr = NULL_PTR;
                s_ChannelInfo[cnt].ChRxBufferPtr = NULL_PTR;
                s_ChannelInfo[cnt].ChDataNum     = 0U;
#endif
            }
        }
       
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
        s_AsyncMode = SPI_POLLING_MODE;
#endif
       
        /* [SWS_Spi_00013] */
        Spi_70_HW_Init( s_ConfigPtr );
       
        /* [SWS_Spi_00015] */
        s_ModuleStatus = SPI_IDLE;
    }
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_DEINIT_ID (0x01)                                         */
/* Name        : Spi_DeInit                                                   */
/* Param       : void                                                         */
/* Return      : Std_ReturnType:                                              */
/*                     E_OK: command has been accepted.                       */
/*                     E_NOT_OK: command has not been accepted.               */
/* Contents    : Spi De-Init processing                                       */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00176]                                              */
/*----------------------------------------------------------------------------*/
Std_ReturnType Spi_DeInit( void )
{
    Std_ReturnType          rtn = E_NOT_OK;     /* [SWS_Spi_00302] */
    Spi_70_SeqInfoType*     seqInfoPtr;         /* pointer for sequence info. */
    Spi_70_JobInfoType*     jobInfoPtr;         /* pointer for job info. */
    Spi_70_ChInfoType*      chInfoPtr;          /* pointer for sequence info. */
    uint16_least            lcount;            /* loop counter*/
 
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    /* [SWS_Spi_00046] DET error is raised if the module is not already initialized */
    if ( SPI_UNINIT == s_ModuleStatus ) {
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_DEINIT_ID, ( uint8 )SPI_E_UNINIT );
    } else
#endif    /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
    {
        /* check if module is BUSY. */
        if ( SPI_BUSY != s_ModuleStatus ) {
            /* [SWS_Spi_00252] Put all already initialized SPI peripherals */
            /*                 into Power On Reset state                   */
 
            /* De-Initialize H/W unit. */
            Spi_70_HW_DeInit( s_ConfigPtr );
 
            /* De-Initialize H/W unit informations. */
            for ( lcount = 0U; lcount < (uint16_least)SPI_70_MAX_HW_UNIT_USING; lcount++ ) {
                s_HwUnitInfo[lcount].HwUnit        = 0U;
                s_HwUnitInfo[lcount].HwUnitConfPtr = NULL_PTR;
                s_HwUnitInfo[lcount].ChStatus      = SPI_70_CH_UNINIT;
                s_HwUnitInfo[lcount].ChDataCnt     = 0U;
            }
 
            /* De-Initialize sequence informations. */
            /* clear all */
            for ( lcount = 0U; lcount < (uint16_least)SPI_MAX_SEQUENCE; lcount++ ) {
                seqInfoPtr = &s_SeqInfo[ lcount ];
                seqInfoPtr->SeqId           = 0U;             /* sequence id. */
                seqInfoPtr->SeqConfPtr      = NULL_PTR;       /* sequence configuration pointer. */
                seqInfoPtr->SeqResult       = SPI_SEQ_FAILED; /* sequence result. */
                seqInfoPtr->JobIndex        = 0U;             /* job index of running. */
            }
 
            /* De-Initialize job informations. */
            /* clear all */
            for ( lcount = 0U; lcount < SPI_MAX_JOB; lcount++ ) {
                jobInfoPtr = &s_JobInfo[ lcount ];
                jobInfoPtr->JobId           = 0U;             /* job id. */
                jobInfoPtr->JobConfPtr      = NULL_PTR;       /* job configuration pointer. */
                jobInfoPtr->JobResult       = SPI_JOB_FAILED; /* job result. */
                jobInfoPtr->ChIndex         = 0U;             /* channel index of running. */
            }
           
            /* De-Initialize Channel informations. */
            for ( lcount = 0U; lcount < (uint16_least)SPI_MAX_CHANNEL; lcount++ ) {
                /* get top of list */
                chInfoPtr = &s_ChannelInfo[ lcount ];
                chInfoPtr->ChId             = 0U;       /* channel id. */
                chInfoPtr->ChConfPtr        = NULL_PTR; /* channel configuration pointer. */
                chInfoPtr->ChTxBufferPtr    = NULL_PTR; /* channel transmit buffer pointer. */
                chInfoPtr->ChRxBufferPtr    = NULL_PTR; /* channel receive buffer pointer. */
                chInfoPtr->ChDataNum        = 0U;       /* channel data number. */
            }
 
            /* clear configuration */
            s_ConfigPtr = NULL_PTR;
 
            /* [SWS_Spi_00022] set module status to UNINIT. */
            s_ModuleStatus = SPI_UNINIT;
 
            rtn = E_OK;          /* [SWS_Spi_00301] */
        } else {
            /* [SWS_Spi_00253] If Busy. Do Nothing and return E_NOT_OK */
        }
    }
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_WRITEIB_ID (0x02)                                        */
/* Name        : Spi_WriteIB                                                  */
/* Param       : (in) Channel : channel ID.                                   */
/*             : (in) DataBufferPtr : data buffer pointer for write.          */
/* Return      : Std_ReturnType:                                              */
/*                     E_OK: command has been accepted.                       */
/*                     E_NOT_OK: command has not been accepted.               */
/* Contents    : Write data to internal buffer of channel.                    */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00177]                                              */
/*----------------------------------------------------------------------------*/
/* [SWS_Spi_00137] */
#if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IB ) || \
      ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) )
Std_ReturnType Spi_WriteIB( Spi_ChannelType Channel, const Spi_DataBufferType* DataBufferPtr )
{
    Std_ReturnType    rtn = E_NOT_OK;                     /* [SWS_Spi_00306] */
    const Spi_70_ChInfoType *   chInfoPtr;                /* pointer to channel information. */
    const Spi_ChannelConfigurationType* chConfPtr;        /* pointer to channel configuration. */
    uint8                       srcData8;                 /* 8bit source data. */
    Spi_DataBufferType QL_70_FAR * dstPtr8;                /* 8bit destination pointer. */
    uint32_least                lcounti;                  /* loop counter i. */
    uint32                      copyDataNum;              /* total number for copy data. */
    const Spi_DataBufferType*   srcPtr;                   /* source pointer. */
    Spi_DataBufferType QL_70_FAR * dstPtr;                 /* destination pointer. */
   
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    if ( SPI_UNINIT == s_ModuleStatus ) {
        /* [SWS_Spi_00046] Det error is raised if module is not initialized */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_WRITEIB_ID, ( uint8 )SPI_E_UNINIT );
    } else if ( SPI_MAX_CHANNEL <= Channel ) {
        /* [SWS_Spi_00031] Det error is raised if channel-id is unknown. */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                     ( uint8 )SPI_WRITEIB_ID, ( uint8 )SPI_E_PARAM_CHANNEL );
    } else
#endif    /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
    {
        /* Get channel information by channel-id. */
        chInfoPtr = &( s_ChannelInfo[ Channel ] );
 
        /* Get channel configuration from channel information. */
        chConfPtr = chInfoPtr->ChConfPtr;
#if ( SPI_DEV_ERROR_DETECT == TRUE )
        if ( SPI_70_BUFFER_IB != chConfPtr->SpiChannelType ) {
            /* [SWS_Spi_00031] Det error is raised if channel is not for IB. */
            ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                         ( uint8 )SPI_WRITEIB_ID, ( uint8 )SPI_E_PARAM_CHANNEL );
        } else
#endif    /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
        {
            copyDataNum = ( ( uint32 )chConfPtr->SpiIbNBuffers * SPI_WIDTH_TWO );
 
            /* Copy default data to buffer. */
            /* destination is internal source buffer. (for send) */
            if ( ( Spi_DataBufferType* )NULL_PTR == DataBufferPtr ) {
                /* [SWS_Spi_00023]when NULL pointer, copy default data to buffer. */
                dstPtr8 = chInfoPtr->ChTxBufferPtr;
                /* 1 to 8bit : 1byte */
                srcData8 = ( uint8 )( chConfPtr->SpiDefaultData );
 
                for ( lcounti = 0U; lcounti < copyDataNum; lcounti++ ) {
                    dstPtr8[ lcounti ] = srcData8;
                }
            } else {
                /* source is parameter. */
                srcPtr = DataBufferPtr;
                /* destination is internal source buffer. (for send) */
                dstPtr = chInfoPtr->ChTxBufferPtr;
 
                /* Copy the data from the DataBufferPtr pointer */
                /* SpiIbNBuffers is number of data elements. */
                for ( lcounti = 0U; lcounti < copyDataNum; lcounti++ ) {
                    dstPtr[ lcounti ] = srcPtr[ lcounti ];
                }
            }
 
            rtn = E_OK;          /* [SWS_Spi_00305] */
        }
    }
    return rtn;
}
 
#endif /* #if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IB ) ||
                ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) ) */
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_READIB_ID (0x04)                                         */
/* Name        : Spi_ReadIB                                                   */
/* Param       : (in) Channel : channel ID.                                   */
/*             : (in) DataBufferPtr : data buffer pointer for read.           */
/* Return      : Std_ReturnType:                                              */
/*                     E_OK: command has been accepted.                       */
/*                     E_NOT_OK: command has not been accepted.               */
/* Contents    : Read data from internal buffer of channel.                   */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00179]                                              */
/*----------------------------------------------------------------------------*/
/* [SWS_Spi_00138] */
#if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IB ) || \
      ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) )
Std_ReturnType Spi_ReadIB( Spi_ChannelType Channel, Spi_DataBufferType* DataBufferPtr )
{
    Std_ReturnType              rtn = E_NOT_OK;         /* [SWS_Spi_00314] */
    const Spi_70_ChInfoType *   chInfoPtr;              /* pointer to channel information. */
    const Spi_ChannelConfigurationType* chConfPtr;      /* pointer to channel configuration. */
    uint32                      copyDataNum;            /* total number for copy data. */
    const Spi_DataBufferType QL_70_FAR * srcPtr;         /* pointer to source for cppy. */
    Spi_DataBufferType QL_70_FAR *       dstPtr;         /* pointer to destination for cppy. */
    uint32_least                lcounti;                /* loop counter. */
 
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    if ( SPI_UNINIT == s_ModuleStatus ) {
        /* [SWS_Spi_00046] DET error is raised if the module is not initialized previously */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_READIB_ID, ( uint8 )SPI_E_UNINIT );
    } else if ( SPI_MAX_CHANNEL <= Channel ) {
        /* [SWS_Spi_00031] DET error is raised if channel-id is unknown */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_READIB_ID, ( uint8 )SPI_E_PARAM_CHANNEL );
    } else if ( ( Spi_DataBufferType* )NULL_PTR == DataBufferPtr ) {
        /* [QINeS_SWS_SPI_00044] DET error is raised                              */
        /*                       if the parameter DataBufferPtr is a NULL POINTER */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_READIB_ID, ( uint8 )SPI_E_PARAM_POINTER );
    } else
#endif    /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
    {
        /* Get channel information by channel-id. */
        chInfoPtr = &( s_ChannelInfo[ Channel ] );
 
        /* Get channel configuration from channel information. */
        chConfPtr = chInfoPtr->ChConfPtr;
#if ( SPI_DEV_ERROR_DETECT == TRUE )
        if ( SPI_70_BUFFER_IB != chConfPtr->SpiChannelType ) {
            /* [SWS_Spi_00031] DET error is raised if channel is not for IB. */
            ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                      ( uint8 )SPI_READIB_ID, ( uint8 )SPI_E_PARAM_CHANNEL );
        } else
#endif    /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
        {
            /* SpiIbNBuffers is number of data elements. */
            copyDataNum = ( uint32 )chConfPtr->SpiIbNBuffers * SPI_WIDTH_TWO;
 
            /* source is internal destination buffer. (for receive) */
            srcPtr = chInfoPtr->ChRxBufferPtr;
 
            /* destination is DataBufferPtr passed as parameter. */
            dstPtr = DataBufferPtr;
 
            /* Copy data from source to destination */
            for ( lcounti = 0U; lcounti < copyDataNum; lcounti++ ) {
                dstPtr[ lcounti ] = srcPtr[ lcounti ];
            }
 
            /* [SWS_Spi_00314] E_OK is returned when API Spi_WriteIB command has been accepted */
            rtn = E_OK;
        }
    }
    return rtn;
}
#endif /* #if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IB ) ||
              ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) ) */
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_SETUPEBIB_ID (0x05)                                      */
/* Name        : Spi_SetupEB                                                  */
/* Param       : (in) Channel : channel ID.                                   */
/*             : (in) SrcDataBufferPtr : data buffer pointer for send.        */
/*             : (in) DesDataBufferPtr : data buffer pointer for receive.     */
/*             : (in) Length : number of datas.(number of data elements)      */
/* Return      : Std_ReturnType:                                              */
/*                     E_OK: command has been accepted.                       */
/*                     E_NOT_OK: command has not been accepted.               */
/* Contents    : Set data buffer pointer and length of channel.               */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00180]                                              */
/*----------------------------------------------------------------------------*/
/* [SWS_Spi_00139] */
#if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_EB ) || \
      ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) )
Std_ReturnType Spi_SetupEB( Spi_ChannelType Channel, const Spi_DataBufferType* SrcDataBufferPtr,
                            Spi_DataBufferType* DesDataBufferPtr, Spi_NumberOfDataType Length )
{
    Spi_70_ChInfoType*            chInfoPtr;        /* channel information pointer. */
    Std_ReturnType                rtn = E_NOT_OK;   /* [SWS_Spi_00317] */
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    const Spi_ChannelConfigurationType* chConfPtr;  /* channel configuration pointer. */
 
    if ( SPI_UNINIT == s_ModuleStatus ) {
        /* [SWS_Spi_00046] Det error is raised if check module is not initialized. */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_SETUPEB_ID, ( uint8 )SPI_E_UNINIT );
    } else if ( SPI_MAX_CHANNEL <= Channel ) {
        /* [SWS_Spi_00031] Det error is raised if channel-id is unknown. */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_SETUPEB_ID, ( uint8 )SPI_E_PARAM_CHANNEL );
    } else
#endif    /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
    {
        /* Get channel information by channel-id. */
        chInfoPtr = &( s_ChannelInfo[ Channel ] );
 
#if ( SPI_DEV_ERROR_DETECT == TRUE )
        /* Get channel configuration from channel information. */
        chConfPtr = chInfoPtr->ChConfPtr;
 
        if ( SPI_70_BUFFER_IB == chConfPtr->SpiChannelType ) {
            /* [SWS_Spi_00031] Det error is raised if channel is not EB. */
            ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                      ( uint8 )SPI_SETUPEB_ID, ( uint8 )SPI_E_PARAM_CHANNEL );
        } else if ( ( (Spi_NumberOfDataType)0U >= Length )
                 || ( chConfPtr->SpiEbMaxLength < Length ) ) {
            /* [SWS_Spi_00060] Det error is raised if check length. */
            /* The condition check for Length = 0 is a Quines requirement. As per Autosar SWS,
             * 0 value is allowed. But since it will be no meaning, Quines gives a DET error */
            ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                      ( uint8 )SPI_SETUPEB_ID, ( uint8 )SPI_E_PARAM_LENGTH );
        } else
#endif    /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
        {
            /* Set channel data number considered difference of type. */
            chInfoPtr->ChDataNum     = Length / (Spi_NumberOfDataType)SPI_WIDTH_TWO; /* channel data number. */
            /* [SWS_Spi_00067] set parameters for channel information. */
            /* channel transmit buffer pointer. */
            chInfoPtr->ChTxBufferPtr = ( QL_70_FAR Spi_DataBufferType* )SrcDataBufferPtr;
            chInfoPtr->ChRxBufferPtr = DesDataBufferPtr;  /* channel Rx buff pointer. */
            /* [SWS_Spi_00317] Setup command has been accepted */
            rtn = E_OK;
        }
    }
    return rtn;
}
#endif /* #if ( ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_EB ) ||
                ( SPI_CHANNEL_BUFFERS_ALLOWED == SPI_70_BUFFER_ALLOW_IBEB ) ) */
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_GETSTATUS_ID (0x06)                                      */
/* Name        : Spi_GetStatus                                                */
/* Param       : void                                                         */
/* Return      : Std_StatusType:                                              */
/*                     SPI_UNINIT: module is not initialized.                 */
/*                     SPI_IDLE:   module is idle (not transporting).         */
/*                     SPI_BUSY:   module is busy (transporting).             */
/* Contents    : Get module status and return.                                */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00320] [SWS_Spi_00025]                              */
/*----------------------------------------------------------------------------*/
Spi_StatusType Spi_GetStatus( void )
{
    Spi_StatusType rtn = SPI_UNINIT;
 
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    /* [SWS_Spi_00046] */
    if ( SPI_UNINIT == s_ModuleStatus ) {
        ( void )Det_ReportError( (uint16)SPI_MODULE_ID, (uint8)SPI_INSTANCE_ID,
                                  (uint8)SPI_GETSTATUS_ID, (uint8)SPI_E_UNINIT );
    } else
#endif /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
    {
        /* get module status */
        rtn = s_ModuleStatus;
    }
    /* [SWS_Spi_00025] [SWS_Spi_00320] return module status */
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_GETJOBRESULT_ID (0x07)                                   */
/* Name        : Spi_GetJobResult                                             */
/* Param       : (in) Job: ID of job.                                         */
/* Return      : Std_JobResultType:                                           */
/*                     SPI_JOB_OK:      last transmission was success.        */
/*                     SPI_JOB_PENDING: performing the job.                   */
/*                     SPI_JOB_FAILED:  last transmission was failed.         */
/*                     SPI_JOB_QUEUED:  the job is waiting start transmission */
/* Contents    : Get last result of job and return.                           */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00182]                                              */
/*----------------------------------------------------------------------------*/
Spi_JobResultType Spi_GetJobResult( Spi_JobType Job )
{
    Spi_JobResultType          rtn = SPI_JOB_FAILED;
    const Spi_70_JobInfoType * jobInfoPtr;             /* pointer to job information. */
 
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    /* [SWS_Spi_00046]check module is not initialized. */
    if ( SPI_UNINIT == s_ModuleStatus ) {
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_GETJOBRESULT_ID, ( uint8 )SPI_E_UNINIT );
    } else
#endif /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
    {
#if ( SPI_DEV_ERROR_DETECT == TRUE )
        if ( SPI_MAX_JOB <= Job ) {
            /* [SWS_Spi_00032] DET error is raised if job-id is unknown. */
            ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                      ( uint8 )SPI_GETJOBRESULT_ID, ( uint8 )SPI_E_PARAM_JOB );
        } else
#endif /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
        {
            /* Get job information */
            jobInfoPtr = &( s_JobInfo[ Job ] );
            /* [SWS_Spi_00026]Get last result of the job and return. */
            rtn = jobInfoPtr->JobResult;
        }
    }
    return rtn;
}
 
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_GETSEQUENCERESULT_ID (0x08)                              */
/* Name        : Spi_GetSequenceResult                                        */
/* Param       : (in) Sequence: ID of sequence.                               */
/* Return      : Std_SeqResultType:                                           */
/*                     SPI_SEQ_OK: last transmission was success.             */
/*                     SPI_SEQ_PENDING: performing the sequence.              */
/*                     SPI_SEQ_FAILED: last transmission was failed.          */
/*                     SPI_SEQ_CANCELED: the sequence is canceled.            */
/* Contents    : Get last result of sequence and return.                      */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00183]                                              */
/*----------------------------------------------------------------------------*/
Spi_SeqResultType Spi_GetSequenceResult( Spi_SequenceType Sequence )
{
    Spi_SeqResultType           rtn = SPI_SEQ_FAILED;
    const Spi_70_SeqInfoType *  seqInfoPtr;         /* pointer to sequence information. */
    Spi_70_SeqResultType        seqResult;
 
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    if ( SPI_UNINIT == s_ModuleStatus ) {
        /* [SWS_Spi_00046] DET error is raised if the module is not initialized */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_GETSEQUENCERESULT_ID, ( uint8 )SPI_E_UNINIT );
    } else if ( SPI_MAX_SEQUENCE <= Sequence ) {
        /* [SWS_Spi_00032] sequence-id is unknown. */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_GETSEQUENCERESULT_ID, ( uint8 )SPI_E_PARAM_SEQ );
    } else
#endif /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
    {
        /* Get sequence information */
        seqInfoPtr = &( s_SeqInfo[ Sequence ] );
        seqResult = seqInfoPtr->SeqResult;
 
        if ( ( SPI_70_SEQ_PENDING_SYNC == seqResult )
              || ( SPI_70_SEQ_PENDING_ASYNC == seqResult ) ) {
            rtn = SPI_SEQ_PENDING;
        } else if ( ( SPI_70_SEQ_CANCELED_NOT_NOTIFIED == seqResult )
                     || ( SPI_70_SEQ_CANCELED_NOTIFIED == seqResult ) ) {
            rtn = SPI_SEQ_CANCELED;
        } else {
            rtn = seqResult;
        }
    }
    /* [SWS_Spi_00324]Get last result of the sequence and return. */
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_GETVERSIONINFO_ID (0x09)                                 */
/* Name        : Spi_GetVersionInfo                                           */
/* Param       : (out) versioninfo: pointer of version information.           */
/* Return      : void                                                         */
/* Contents    : Return the version information of this module                */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00184]                                              */
/*----------------------------------------------------------------------------*/
#if ( SPI_VERSION_INFO_API == TRUE )
void Spi_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    /* [SWS_Spi_00371] DET error is raised if the parameter versioninfo is a NULL POINTER */
    if ( NULL_PTR == versioninfo ) {
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_GETVERSIONINFO_ID, ( uint8 )SPI_E_PARAM_POINTER );
    } else
#endif /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
    {
        /* copy the version information */
        versioninfo->vendorID = SPI_VENDOR_ID;
        versioninfo->moduleID = SPI_MODULE_ID;
        versioninfo->sw_major_version = SPI_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = SPI_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = SPI_SW_PATCH_VERSION;
    }
}
#endif /* #if ( SPI_VERSION_INFO_API == TRUE ) */
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_SYNCTRANSMIT_ID (0x0A)                                   */
/* Name        : Spi_SyncTransmit                                             */
/* Param       : (in) Sequence: sequence-id for transmit.                     */
/* Return      : Std_ReturnType:                                              */
/*                     E_OK:     command has been accepted.                   */
/*                     E_NOT_OK: command has not been accepted.               */
/* Contents    : Synchronous transmit request for a sequence.                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* [SWS_Spi_00136] */
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_0 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
Std_ReturnType Spi_SyncTransmit( Spi_SequenceType Sequence )
{
    Spi_70_SeqInfoType*             seqInfoPtr;
    bool_t                          hwError;
    uint16                          numOfJobAssignment;
    uint16_least                    jobCnt;
    const Spi_JobConfigurationType* jobConfigPtr;
    Spi_HWUnitType                  hwUnit;
    uint8_least                     seqCnt;
    Std_ReturnType                  rtn = E_NOT_OK;          /* [SWS_Spi_00329] */
   
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    if ( SPI_UNINIT == s_ModuleStatus ) {
        /* [SWS_Spi_00242] */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                 ( uint8 )SPI_SYNCTRANSMIT_ID, ( uint8 )SPI_E_UNINIT );
        return rtn;
    } else if ( SPI_MAX_SEQUENCE <= Sequence ) {
        /* [SWS_Spi_00238] */
        /* [SWS_Spi_00032] */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                 ( uint8 )SPI_SYNCTRANSMIT_ID, ( uint8 )SPI_E_PARAM_SEQ );
        return rtn;
    } else
#endif    /* SPI_DEV_ERROR_DETECT */
    {
        /* [SWS_Spi_00134] */
        s_ModuleStatus = SPI_BUSY;
       
        /* Get sequence information */
        seqInfoPtr = &(s_SeqInfo[Sequence]);
       
        /* Start sequence */
        rtn = spi_startSeq( seqInfoPtr, SPI_70_SYNC );
       
        if ( E_OK == rtn ) {
            /* Transmit and receive sequence */
            rtn = spi_transmitReceiveSeq( seqInfoPtr, SPI_70_SYNC );
        }
       
        hwError = FALSE;
        numOfJobAssignment = seqInfoPtr->SeqConfPtr->Spi_NumOfJobAssignment;
       
        /* Search all Jobs in a sequence */
        for ( jobCnt = 0U; jobCnt < numOfJobAssignment; jobCnt++ ) {
           
            /* Get the HW unit ID configured in the job */
            jobConfigPtr = seqInfoPtr->SeqConfPtr->SpiJobAssignment[jobCnt];
            hwUnit = jobConfigPtr->SpiDeviceAssignment->SpiHwUnit;
           
            /* Check HW errors */
            hwError = Spi_70_HW_GetHWErrorStatus( hwUnit );
           
            if ( TRUE == hwError ) {
                break;
            }
        }
       
#if ( SPI_70_DEM_SET_EVENT_STATUS != FALSE )
        if ( FALSE == hwError ) {
            /* [SWS_Spi_00386] */
            ( void )Dem_SetEventStatus( SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED );
        } else {
                /* [SWS_Spi_00385] */
            ( void )Dem_SetEventStatus( SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED );
        }
#endif    /* SPI_70_DEM_SET_EVENT_STATUS != 0U */
       
        if ( ( E_NOT_OK == rtn ) || ( TRUE == hwError ) ) {
            /* Stop sequence as failed */
            spi_stopSeq( seqInfoPtr, SPI_SEQ_FAILED, SPI_70_SYNC );
           
            rtn = E_NOT_OK;
        } else {
            /* Stop sequence as ok */
            spi_stopSeq( seqInfoPtr, SPI_SEQ_OK, SPI_70_SYNC );
           
            rtn = E_OK; /* [SWS_Spi_00328] */
        }
       
        /* Check the status of all sequences */
        for ( seqCnt = 0U; seqCnt < (uint8_least)SPI_MAX_SEQUENCE; seqCnt++ ) {
            if ( ( SPI_70_SEQ_PENDING_SYNC  == s_SeqInfo[seqCnt].SeqResult )
              || ( SPI_70_SEQ_PENDING_ASYNC == s_SeqInfo[seqCnt].SeqResult ) ) {
                break;
            }
        }
       
        /* If all sequences are stopped */
        if ( (uint8_least)SPI_MAX_SEQUENCE <= seqCnt ) {
            s_ModuleStatus = SPI_IDLE; /* [SWS_Spi_00161][SWS_Spi_00283] */
        }
    }
   
    return rtn;
}
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_0 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
 
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_ASYNCTRANSMIT_ID (0x03)                                  */
/* Name        : Spi_AsyncTransmit                                            */
/* Param       : (in) Sequence: sequence-id for transmit.                     */
/* Return      : Std_ReturnType:                                              */
/*                     E_OK:     command has been accepted.                   */
/*                     E_NOT_OK: command has not been accepted.               */
/* Contents    : Asynchronous transmit request for a sequence.                */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00133][SWS_Spi_00178]                               */
/*----------------------------------------------------------------------------*/
Std_ReturnType Spi_AsyncTransmit( Spi_SequenceType Sequence )
{
    Std_ReturnType      rtn = E_NOT_OK;         /* [SWS_Spi_00310] */
    Spi_70_SeqInfoType* seqInfoPtr;
    uint8_least         seqCnt;
    uint8               asyncMode;
 
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    if ( SPI_UNINIT == s_ModuleStatus ) {
        /* [SWS_Spi_00242] */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                 ( uint8 )SPI_ASYNCTRANSMIT_ID, ( uint8 )SPI_E_UNINIT );
        return rtn;
    } else if ( SPI_MAX_SEQUENCE <= Sequence ) {
        /* [SWS_Spi_00238] */
        /* [SWS_Spi_00032] */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                 ( uint8 )SPI_ASYNCTRANSMIT_ID, ( uint8 )SPI_E_PARAM_SEQ );
        return rtn;
    } else
#endif    /* SPI_DEV_ERROR_DETECT */
    {
        if( SPI_INTERRUPT_MODE == s_AsyncMode ) {
            /* Enable Interrupts function */
            Spi_70_HW_EnableInterrupts();
        }
       
        /* [SWS_Spi_00020] */
        s_ModuleStatus = SPI_BUSY;
 
        /* Get sequence information */
        seqInfoPtr = &( s_SeqInfo[Sequence] );
       
        /* Start sequence */
       
        if( SPI_INTERRUPT_MODE == s_AsyncMode ) {
            asyncMode = SPI_70_ASYNC_INTERRUPT;
        } else {
            asyncMode = SPI_70_ASYNC_POLLING;
        }
        rtn = spi_startSeq( seqInfoPtr, asyncMode );
 
        if ( E_NOT_OK == rtn ) {
            /* [SWS_Spi_00328] */
            /* When spi_startSeq failed, set E_NOT_OK. */
            if ( SPI_POLLING_MODE == s_AsyncMode ) {
                /* Stop sequence as failed */
                spi_stopSeq( seqInfoPtr, SPI_SEQ_FAILED, SPI_70_ASYNC_POLLING );
            } else {
                /* Stop sequence as failed */
                spi_stopSeq( seqInfoPtr, SPI_SEQ_FAILED, SPI_70_ASYNC_INTERRUPT );
            }
            /* Check the status of all sequences */
            for ( seqCnt = 0U; seqCnt < (uint8_least)SPI_MAX_SEQUENCE; seqCnt++ ) {
                if ( ( SPI_70_SEQ_PENDING_SYNC  == s_SeqInfo[seqCnt].SeqResult )
                  || ( SPI_70_SEQ_PENDING_ASYNC == s_SeqInfo[seqCnt].SeqResult ) ) {
                    break;
                }
            }
           
            /* If all sequences are stopped */
            if ( (uint8_least)SPI_MAX_SEQUENCE <= seqCnt ) {
                s_ModuleStatus = SPI_IDLE; /* [SWS_Spi_00161][SWS_Spi_00283] */
            }
        }
    }
   
    return rtn;
}
 
#if ( SPI_CANCEL_API == TRUE )
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_CANCEL_ID (0x0C)                                         */
/* Name        : Spi_Cancel                                                   */
/* Param       : (in) Sequence: sequence-id for transmit.                     */
/* Return      : void                                                         */
/* Contents    : abort Sequence process                                       */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_Cancel( Spi_SequenceType Sequence )
{
    Spi_70_SeqInfoType*           seqInfoPtr;
    Spi_JobType                   jobId;
    const Spi_70_JobInfoType*     jobInfoPtr;
    const Spi_ExternalDeviceType* exDevConfPtr;
    Spi_70_HwUnitInfoType*        hwUnitInfoPtr;
    uint8_least                   hwUnitCnt;
   
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    if ( SPI_UNINIT == s_ModuleStatus ) {
        /* [SWS_Spi_00242] */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                 ( uint8 )SPI_CANCEL_ID, ( uint8 )SPI_E_UNINIT );
    } else if ( SPI_MAX_SEQUENCE <= Sequence ) {
        /* [SWS_Spi_00238] */
        /* [SWS_Spi_00032] */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                 ( uint8 )SPI_CANCEL_ID, ( uint8 )SPI_E_PARAM_SEQ );
    } else
#endif    /* SPI_DEV_ERROR_DETECT */
    {
        /* Get sequence information */
        seqInfoPtr = &(s_SeqInfo[Sequence]);
        seqInfoPtr->SeqResult = SPI_70_SEQ_CANCELED_NOT_NOTIFIED;
       
        /* Get job id */
        jobId = seqInfoPtr->SeqConfPtr->SpiJobAssignment[seqInfoPtr->JobIndex]->SpiJobId;
       
        /* Get job infomation */
        jobInfoPtr = &(s_JobInfo[jobId]);
       
        /* Get external device config */
        exDevConfPtr = jobInfoPtr->JobConfPtr->SpiDeviceAssignment;
       
        /* Get HW unit information */
        for ( hwUnitCnt = 0U ; hwUnitCnt < SPI_70_MAX_HW_UNIT_USING; hwUnitCnt++ ) {
            if ( exDevConfPtr->SpiHwUnit == s_HwUnitInfo[hwUnitCnt].HwUnit ) {
                hwUnitInfoPtr = &(s_HwUnitInfo[hwUnitCnt]);
            }
            else {
                hwUnitInfoPtr = NULL_PTR;
            }
        }
       
        /* Stop channel */
        spi_stopChannel( hwUnitInfoPtr, exDevConfPtr );
    }
}
#endif /* #if ( SPI_CANCEL_API == TRUE ) */
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_SETASYNCMODE_ID (0x0D)                                   */
/* Name        : Spi_SetAsyncMode                                             */
/* Param       : (in) Mode: New mode required.                                */
/* Return      : Std_ReturnType:                                              */
/*                     E_OK:     command has been accepted.                   */
/*                     E_NOT_OK: command has not been accepted.               */
/* Contents    : Get H/W unit status and return.                              */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00154]                                              */
/*----------------------------------------------------------------------------*/
 
Std_ReturnType Spi_SetAsyncMode( Spi_AsyncModeType Mode )
{
    Std_ReturnType rtn = E_NOT_OK;   /* [SWS_Spi_00337] */
    uint16_least cnt;
    bool_t setMode = FALSE;
   
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    if ( SPI_UNINIT == s_ModuleStatus ) {
        /* [SWS_Spi_00242] */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                 ( uint8 )SPI_SETASYNCMODE_ID, ( uint8 )SPI_E_UNINIT );
    } else
#endif    /* SPI_DEV_ERROR_DETECT */
    {
        if ( SPI_BUSY == s_ModuleStatus ) {
            for ( cnt = 0U; cnt < (uint16_least)SPI_MAX_SEQUENCE; cnt++ ) {
                if ( SPI_70_SEQ_PENDING_ASYNC == s_SeqInfo[cnt].SeqResult ) {
                    break;                      /* [SWS_Spi_00171] */
                }
            }
           
            if ( (uint16_least)SPI_MAX_SEQUENCE <= cnt ) {
                setMode = TRUE;         /* [SWS_Spi_00172] */
            }
        } else {
            setMode = TRUE;
        }
       
        if ( TRUE == setMode ) {
            if ( SPI_POLLING_MODE == Mode ) {
                Spi_70_HW_DisableInterrupts();
                s_AsyncMode = SPI_POLLING_MODE;
            } else {
                Spi_70_HW_EnableInterrupts();
                s_AsyncMode = SPI_INTERRUPT_MODE;
            }
            rtn = E_OK;         /* [SWS_Spi_00336] */
        }
    }
   
    return rtn;
}
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
 
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_GETHWUNITSTATUS_ID (0x0B)                                */
/* Name        : Spi_GetHWUnitStatus                                          */
/* Param       : (in) HWUnit: HW unit id.                                     */
/* Return      : Spi_StatusType:                                              */
/*                     SPI_UNINIT: module is not initialized.                 */
/*                     SPI_IDLE:   module is idle (not transporting).         */
/*                     SPI_BUSY:   module is busy (transporting).             */
/* Contents    : Get H/W unit status and return.                              */
/* Author      : --                                                           */
/* Note        : [SWS_Spi_00186]                                              */
/*----------------------------------------------------------------------------*/
#if ( SPI_HW_STATUS_API == TRUE )
Spi_StatusType Spi_GetHWUnitStatus( Spi_HWUnitType HWUnit )
{
    Spi_StatusType                  rtn = SPI_UNINIT;
    const Spi_70_HwUnitInfoType *   hwInfoPtr;
    Spi_70_HW_ChStatusType          chStatus;
 
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    if ( SPI_UNINIT == s_ModuleStatus ) {
        /* [SWS_Spi_00046]check module is not initialized. */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_GETHWUNITSTATUS_ID, ( uint8 )SPI_E_UNINIT );
    } else if ( SPI_70_MAX_HW_UNIT_USING <= HWUnit ) {
        /* [SWS_Spi_00143]HW unit-id is unknown. */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                  ( uint8 )SPI_GETHWUNITSTATUS_ID, ( uint8 )SPI_E_PARAM_UNIT );
    } else
#endif /* #if ( SPI_DEV_ERROR_DETECT == TRUE ) */
    {
        /* Get HwUnit information */
        hwInfoPtr = &( s_HwUnitInfo[ HWUnit ] );
        chStatus = hwInfoPtr->ChStatus;
       
        if ( SPI_70_CH_UNINIT == chStatus ) {
            rtn = SPI_UNINIT;
        } else if ( SPI_70_CH_STOP == chStatus ) {
            rtn = SPI_IDLE;
        } else {
            rtn = SPI_BUSY;
        }
    }
    return rtn;
}
#endif /* #if ( SPI_HW_STATUS_API == TRUE ) */
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : SPI_MAINFUNCTION_HANDLING_ID (0x10)                          */
/* Name        : Spi_MainFunction_Handling                                    */
/* Param       : None                                                         */
/* Return      : void                                                         */
/* Contents    : --                                                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_MainFunction_Handling ( void )
{
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
    Spi_70_SeqInfoType*             seqInfoPtr;
    uint8_least                     seqCnt;
    uint8_least                     statusCnt;
    const Spi_JobConfigurationType* jobConfigPtr;
    uint16_least                    jobCnt;
    Spi_JobType                     jobId;
    bool_t                          hwError;
    Spi_HWUnitType                  hwUnit;
    Std_ReturnType                  txRxSeqrtn;
    uint16                          jobIndex;
    uint16                          numOfJobAssignment;
 
#if ( SPI_CANCEL_API == TRUE )
    /* Check the status of all sequences */
    for ( seqCnt = 0U; seqCnt < (uint8_least)SPI_MAX_SEQUENCE; seqCnt++ ) {
        if ( SPI_70_SEQ_CANCELED_NOT_NOTIFIED == s_SeqInfo[seqCnt].SeqResult ) {
            /* Get sequence information */
            seqInfoPtr = &( s_SeqInfo[seqCnt] );
           
            if ( SPI_INTERRUPT_MODE == s_AsyncMode ) {
                spi_stopSeq( seqInfoPtr,
                             SPI_70_SEQ_CANCELED_NOTIFIED,
                             SPI_70_ASYNC_INTERRUPT_MAIN );
            } else {
                spi_stopSeq( seqInfoPtr, SPI_70_SEQ_CANCELED_NOTIFIED, SPI_70_ASYNC_POLLING );
            }
        }
    }
#endif /* #if ( SPI_CANCEL_API == TRUE ) */
   
    /* Check the status of all sequences */
    for ( seqCnt = 0U; seqCnt < (uint8_least)SPI_MAX_SEQUENCE; seqCnt++ ) {
        if ( SPI_70_SEQ_PENDING_ASYNC == s_SeqInfo[seqCnt].SeqResult ) {
            /* Get sequence information */
            seqInfoPtr = &( s_SeqInfo[seqCnt] );
           
            if ( SPI_INTERRUPT_MODE == s_AsyncMode ) {
                txRxSeqrtn = spi_transmitReceiveSeq( seqInfoPtr, SPI_70_ASYNC_INTERRUPT_MAIN );
            } else {
                txRxSeqrtn = spi_transmitReceiveSeq( seqInfoPtr, SPI_70_ASYNC_POLLING );
            }            
            jobIndex = seqInfoPtr->JobIndex;
            jobConfigPtr = seqInfoPtr->SeqConfPtr->SpiJobAssignment[jobIndex];
            hwUnit = jobConfigPtr->SpiDeviceAssignment->SpiHwUnit;
           
            /* Check HW errors */
            hwError = Spi_70_HW_GetHWErrorStatus( hwUnit );
            if ( ( E_NOT_OK == txRxSeqrtn ) || ( TRUE == hwError ) ) {
#if ( SPI_70_DEM_SET_EVENT_STATUS != 0U )
                /* [SWS_Spi_00385] */
                ( void )Dem_SetEventStatus( SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED );
#endif    /* SPI_70_DEM_SET_EVENT_STATUS != 0U */
                break;
            } else {
                /* Check the status of all jobs */
                numOfJobAssignment = seqInfoPtr->SeqConfPtr->Spi_NumOfJobAssignment;
                for ( jobCnt = 0U; jobCnt < numOfJobAssignment; jobCnt++ ) {
                    /* Get job id */
                    jobId = seqInfoPtr->SeqConfPtr->SpiJobAssignment[jobCnt]->SpiJobId;
                   
                    if ( SPI_JOB_OK != s_JobInfo[jobId].JobResult ) {
                        break;
                    }
                }
                /* If all sequences are stopped */
                if ( numOfJobAssignment <= jobCnt ) {
                    /* Stop sequence as success */
                    if ( SPI_INTERRUPT_MODE == s_AsyncMode ) {
                        spi_stopSeq( seqInfoPtr, SPI_SEQ_OK, SPI_70_ASYNC_INTERRUPT_MAIN );
                    } else {
                        spi_stopSeq( seqInfoPtr, SPI_SEQ_OK, SPI_70_ASYNC_POLLING );
                    }
                }
#if ( SPI_70_DEM_SET_EVENT_STATUS != 0U )
                /* [SWS_Spi_00386] */
                ( void )Dem_SetEventStatus( SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED );
#endif    /* SPI_70_DEM_SET_EVENT_STATUS != 0U */
            }
        }
    }
   
    /* Check the status of all sequences */
    for ( statusCnt = 0U; statusCnt < SPI_MAX_SEQUENCE; statusCnt++ ) {
        if ( ( SPI_70_SEQ_PENDING_SYNC  == s_SeqInfo[statusCnt].SeqResult )
          || ( SPI_70_SEQ_PENDING_ASYNC == s_SeqInfo[statusCnt].SeqResult ) ) {
            break;
        }
    }
   
    /* If all sequences are stopped */
    if ( SPI_MAX_SEQUENCE <= statusCnt ) {
        s_ModuleStatus = SPI_IDLE;
    }
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : Spi_70_SndRcvIntr                                            */
/* Param       : (in) HWUnit: HW unit id.                                     */
/* Return      : void                                                         */
/* Contents    : --                                                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Spi_70_SndRcvIntr( Spi_HWUnitType HWUnit )
{
    Spi_70_SeqInfoType*             seqInfoPtr;
    uint8_least                     seqCnt;
    uint8_least                     statusCnt;
    const Spi_ExternalDeviceType*   exDevConfPtr;
    Std_ReturnType                  txRxSeqrtn;
   
    for ( seqCnt = 0U; seqCnt < SPI_MAX_SEQUENCE; seqCnt++ ) {
        /* Get Sequence Information */
        seqInfoPtr = &( s_SeqInfo[seqCnt] );
       
        /* Get Ex device configuration */
        exDevConfPtr
            = seqInfoPtr->SeqConfPtr->SpiJobAssignment[seqInfoPtr->JobIndex]->SpiDeviceAssignment;
       
        /* Judge Hardware Unit Id */
        if ( exDevConfPtr->SpiHwUnit == HWUnit ) {
            /* Judge Sequence Result */
            if ( SPI_70_SEQ_PENDING_ASYNC == seqInfoPtr->SeqResult ) {
                txRxSeqrtn = spi_transmitReceiveSeq( seqInfoPtr, SPI_70_ASYNC_INTERRUPT );
               
                if ( E_NOT_OK == txRxSeqrtn ) {
                    /* Stop sequence as failed */
                    spi_stopSeq( seqInfoPtr, SPI_SEQ_FAILED, SPI_70_ASYNC_INTERRUPT );
                   
                    /* Check the status of all sequences */
                    for ( statusCnt = 0U; statusCnt < SPI_MAX_SEQUENCE; statusCnt++ ) {
                        if ( ( SPI_70_SEQ_PENDING_SYNC  == s_SeqInfo[statusCnt].SeqResult )
                          || ( SPI_70_SEQ_PENDING_ASYNC == s_SeqInfo[statusCnt].SeqResult ) ) {
                            break;
                        }
                    }
                   
                    /* If all sequences are stopped */
                    if ( SPI_MAX_SEQUENCE <= statusCnt ) {
                        s_ModuleStatus = SPI_IDLE;
                    }
                } else {
                    /* finish interrupt process */
                    break;
                }
            }
        }
    }
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_startSeq                                                 */
/* Param       : (in) seqInfo: pointer to sequence information to start.      */
/*             : (in) mode   : specify mode when this function is called.     */
/* Return      : void                                                         */
/* Contents    : Start sequence for transmit                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType spi_startSeq( Spi_70_SeqInfoType* seqInfo, Spi_70_FuncModeType mode )
{
    uint16_least jobCnt;
    Spi_JobType jobId;
    Std_ReturnType rtn;
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
    Spi_70_JobInfoType* jobInfoPtr;
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
   
#if ( SPI_DEV_ERROR_DETECT == TRUE )
    uint8_least  seqCnt;
    uint16_least cmpJobCnt;
    Spi_JobType cmpJobId;
    const Spi_SequenceConfigurationType* cmpSeqConfPtr;
    const Spi_ExternalDeviceType* exDevConfPtr;
    const Spi_ExternalDeviceType* cmpExDevConfPtr;
   
    if ( ( SPI_70_SEQ_PENDING_SYNC  == seqInfo->SeqResult )
      || ( SPI_70_SEQ_PENDING_ASYNC == seqInfo->SeqResult ) ) {
        /* [SWS_Spi_00081] */
        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID, ( uint8 )SPI_INSTANCE_ID,
                                 ( uint8 )SPI_INIT_ID, ( uint8 )SPI_E_SEQ_PENDING );
        return E_NOT_OK;
    }
   
    /* [SWS_Spi_00086] */
    /* Check if shared job is available */
    for ( jobCnt = 0U; jobCnt < seqInfo->SeqConfPtr->Spi_NumOfJobAssignment; jobCnt++ ) {
        jobId = seqInfo->SeqConfPtr->SpiJobAssignment[jobCnt]->SpiJobId;
        exDevConfPtr = seqInfo->SeqConfPtr->SpiJobAssignment[jobCnt]->SpiDeviceAssignment;
       
        /* Check sequence for SPI_SEQ_PENDING status */
        for ( seqCnt = 0U; seqCnt < SPI_MAX_SEQUENCE; seqCnt++ ) {
            cmpSeqConfPtr = s_SeqInfo[seqCnt].SeqConfPtr;
            if ( ( SPI_70_SEQ_PENDING_SYNC  == s_SeqInfo[seqCnt].SeqResult )
              || ( SPI_70_SEQ_PENDING_ASYNC == s_SeqInfo[seqCnt].SeqResult ) ) {
               
                /* Check all job belonging to sequence */
                for ( cmpJobCnt = 0U;
                      cmpJobCnt < cmpSeqConfPtr->Spi_NumOfJobAssignment;
                      cmpJobCnt++ ) {
                    cmpJobId = cmpSeqConfPtr->SpiJobAssignment[cmpJobCnt]->SpiJobId;
                   
                    /* Check shared job */
                    if ( jobId == cmpJobId ) {
                        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID,
                                                 ( uint8 )SPI_INSTANCE_ID,
                                                 ( uint8 )SPI_INIT_ID,
                                                 ( uint8 )SPI_E_SEQ_PENDING );
                        return E_NOT_OK;
                    }
                   
                    cmpExDevConfPtr
                        = cmpSeqConfPtr->SpiJobAssignment[cmpJobCnt]->SpiDeviceAssignment;
                   
                    /* Check Ex device */
                    if ( exDevConfPtr->SpiDeviceId == cmpExDevConfPtr->SpiDeviceId ) {
                        ( void )Det_ReportError( ( uint16 )SPI_MODULE_ID,
                                                 ( uint8 )SPI_INSTANCE_ID,
                                                 ( uint8 )SPI_INIT_ID,
                                                 ( uint8 )SPI_E_SEQ_PENDING );
                        return E_NOT_OK;
                    }
                }
            }
        }
    }
#endif /* SPI_DEV_ERROR_DETECT */
   
    if ( SPI_70_SYNC == mode ) {
        /* [SWS_Spi_00285] */
        seqInfo->SeqResult = SPI_70_SEQ_PENDING_SYNC;
    } else {
        /* [SWS_Spi_00020] */
        seqInfo->SeqResult = SPI_70_SEQ_PENDING_ASYNC;
       
        /* [SWS_Spi_00194] */
        for ( jobCnt = 0U; jobCnt < seqInfo->SeqConfPtr->Spi_NumOfJobAssignment; jobCnt++ ) {
            /* Get job id */
            jobId = seqInfo->SeqConfPtr->SpiJobAssignment[jobCnt]->SpiJobId;
           
            /* Set job information that Job has not started yet only AsyncTransmit. */
            s_JobInfo[jobId].JobResult = SPI_JOB_QUEUED;
        }
    }
   
    /* Set the job being processed */
    seqInfo->JobIndex = 0U;
   
    rtn = E_OK;
   
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
    if ( SPI_70_ASYNC_INTERRUPT == mode ) {
        /* Get 1st job id */
        jobId = seqInfo->SeqConfPtr->SpiJobAssignment[seqInfo->JobIndex]->SpiJobId;
       
        /* Get 1st job information */
        jobInfoPtr = &(s_JobInfo[jobId]);
       
        /* Start job */
        rtn = spi_startJob( jobInfoPtr, mode );
       
        if ( E_NOT_OK == rtn ) {
            /* Job failed */
            spi_stopJob( jobInfoPtr, SPI_JOB_FAILED, mode );
        }
    }
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
   
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_transmitReceiveSeq                                       */
/* Param       : (in) seqInfo: pointer to sequence information to start.      */
/*             : (in) mode   : specify mode when this function is called.     */
/* Return      : void                                                         */
/* Contents    : transmit and receive sequence.                               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType spi_transmitReceiveSeq( Spi_70_SeqInfoType* seqInfo,
                                              Spi_70_FuncModeType mode )
{
    uint16_least jobCnt;
    Spi_JobType jobId;
    Spi_70_JobInfoType* jobInfoPtr;
    Std_ReturnType rtn = E_NOT_OK;
   
    /* Get job id */
    jobId = seqInfo->SeqConfPtr->SpiJobAssignment[seqInfo->JobIndex]->SpiJobId;
   
    /* Get job infomation */
    jobInfoPtr = &(s_JobInfo[jobId]);
 
   
    if ( ( SPI_70_SYNC == mode ) || ( SPI_70_ASYNC_POLLING == mode ) ) {
        for ( jobCnt = seqInfo->JobIndex;
              jobCnt < seqInfo->SeqConfPtr->Spi_NumOfJobAssignment;
              jobCnt++ ) {
            /* Start job */
            rtn = spi_startJob( jobInfoPtr, mode );
           
            if ( E_OK == rtn ) {
                /* If spi_startJob succeeded */
                /* Transmit and receive job */
                rtn = spi_transmitReceiveJob( jobInfoPtr, mode );
            }
           
            if ( E_OK == rtn ) {
                /* If spi_transmitReceiveJob succeeded */
                /* Job success */
                spi_stopJob( jobInfoPtr, SPI_JOB_OK, mode );
               
                seqInfo->JobIndex++;
               
                /* For SYNC,  start next job in next loop */
                /* For ASYNC, start next job in next main function */
                if ( SPI_70_SYNC != mode ) {
                    break;
                }
            } else {
                /* If spi_startJob or spi_transmitReceiveJob succeeded */
                spi_stopJob( jobInfoPtr, SPI_JOB_FAILED, mode );
                break;
            }
        }
    }
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
    else if ( SPI_70_ASYNC_INTERRUPT == mode ) {
        /* Transmit and receive job */
        rtn = spi_transmitReceiveJob( jobInfoPtr, mode );
       
        if ( E_NOT_OK == rtn ) {
            /* If spi_transmitReceiveJob failed */
            spi_stopJob( jobInfoPtr, SPI_JOB_FAILED, mode );
        }
    } else {
        /* Check if all channels have been processed */
        if ( jobInfoPtr->ChIndex >= jobInfoPtr->JobConfPtr->Spi_NumOfChannelList ) {
            /* Job success */
            spi_stopJob( jobInfoPtr, SPI_JOB_OK, mode );
           
            seqInfo->JobIndex++;
           
            /* Check if all jobs have been processed */
            if ( seqInfo->JobIndex < seqInfo->SeqConfPtr->Spi_NumOfJobAssignment ) {
                /* Get job id */
                jobId = seqInfo->SeqConfPtr->SpiJobAssignment[seqInfo->JobIndex]->SpiJobId;
               
                /* Get job infomation */
                jobInfoPtr = &(s_JobInfo[jobId]);
               
                /* Start job */
                rtn = spi_startJob( jobInfoPtr, mode );
            } else {
                rtn = E_OK;
            }
        } else {
            rtn = E_OK;
        }
       
        if ( E_NOT_OK == rtn ) {
            /* If spi_startJob failed */
            spi_stopJob( jobInfoPtr, SPI_JOB_FAILED, mode );
        }
    }
 
 
 
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
   
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_stopSeq                                                  */
/* Param       : (in) seqInfo   : pointer to sequence information to start.   */
/*             : (in) seqResult : result of sequence for setting.             */
/*             : (in) mode      : specify mode when this function is called.  */
/* Return      : void                                                         */
/* Contents    : Stop sequence for transmit.                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void spi_stopSeq( Spi_70_SeqInfoType* seqInfo, Spi_70_SeqResultType seqResult,
                         Spi_70_FuncModeType mode )
{
    /* Set result */
    seqInfo->SeqResult = seqResult;
   
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
    if ( SPI_70_SYNC != mode ) {
        if ( NULL_PTR != seqInfo->SeqConfPtr->SpiSeqEndNotification ) {
            seqInfo->SeqConfPtr->SpiSeqEndNotification();
        }
    }
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_transmitReceiveJob                                       */
/* Param       : (in) jobInfo: pointer to job information.                    */
/*             : (in) mode   : specify mode when this function is called.     */
/* Return      : void                                                         */
/* Contents    : transmit and receive job.                                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType spi_transmitReceiveJob( Spi_70_JobInfoType* jobInfo,
                                              Spi_70_FuncModeType mode )
{
    const Spi_ExternalDeviceType* exDevConfPtr;
    uint8_least hwUnitCnt;
    Spi_70_HwUnitInfoType* hwUnitInfoPtr = NULL_PTR;
    uint8_least chCnt;
    const Spi_ChannelListType* chListPtr;
    Spi_ChannelType chId;
    const Spi_70_ChInfoType* chInfoPtr;
    uint16_least dataCnt;
   
    Std_ReturnType rtn = E_NOT_OK;
   
    /* Get external device config */
    exDevConfPtr = jobInfo->JobConfPtr->SpiDeviceAssignment;
   
    /* Get HW unit information */
    for ( hwUnitCnt = 0U ; hwUnitCnt < SPI_70_MAX_HW_UNIT_USING; hwUnitCnt++ ) {
        if ( exDevConfPtr->SpiHwUnit == s_HwUnitInfo[hwUnitCnt].HwUnit ) {
            hwUnitInfoPtr = &(s_HwUnitInfo[hwUnitCnt]);
        }
    }
   
    if ( ( SPI_70_SYNC == mode ) || ( SPI_70_ASYNC_POLLING == mode ) ) {
        for ( chCnt = jobInfo->ChIndex;
              chCnt < jobInfo->JobConfPtr->Spi_NumOfChannelList;
              chCnt++ ) {
            /* Get channel Id */
            chListPtr = &(jobInfo->JobConfPtr->SpiChannelList[jobInfo->ChIndex]);
            chId = chListPtr->SpiChannelAssignment->SpiChannelId;
           
            /* Get channel information */
            chInfoPtr = &(s_ChannelInfo[chId]);
           
            /* Start channel */
            rtn = spi_startChannel( chInfoPtr, hwUnitInfoPtr, exDevConfPtr );
           
            if ( E_OK == rtn ) {
                /* If spi_startChannel succeeded */
                for ( dataCnt = 0U; dataCnt < chInfoPtr->ChDataNum; dataCnt++ ) {
                    /* Transmit channel */
                    rtn = spi_transmitChannel( chInfoPtr, hwUnitInfoPtr );
                   
                    if ( E_OK == rtn ) {
                        /* If spi_transmitChannel succeeded */
                        /* Receive channel */
                        rtn = spi_receiveChannel( chInfoPtr, hwUnitInfoPtr );
                    }
                   
                    if ( E_OK == rtn ) {
                        /* If spi_receiveChannel succeeded */
                        /* Check if all data have been processed */
                        hwUnitInfoPtr->ChDataCnt++;
                        if ( hwUnitInfoPtr->ChDataCnt >= chInfoPtr->ChDataNum ) {
                            /* All data have been processed */
                            break;
                        }
                    } else {
                        /* Channel failed */
                        break;
                    }
                }
            }
           
            if ( E_OK == rtn ) {
                /* If all data have been processed */
                /* Stop channel */
                spi_stopChannel( hwUnitInfoPtr, exDevConfPtr );
               
                jobInfo->ChIndex++;
               
                /* Check if all channels have been processed */
                if ( jobInfo->ChIndex < jobInfo->JobConfPtr->Spi_NumOfChannelList ) {
                   
                    if ( ( TRUE == exDevConfPtr->SpiEnableCs )
                      && ( SPI_70_CS_TOGGLE == exDevConfPtr->SpiCsBehavior ) ) {
                        /* If spi_receiveChannel succeeded */
                        /* Check if all data have been processed */
 
                        /* Negate chip select (CS to CS) */
                        Spi_70_HW_PutChipSelect(
                            exDevConfPtr->SpiCsIdentifier,
                            FALSE,
                            exDevConfPtr->SpiCsPolarity,
                            exDevConfPtr->Spi_70_Cs2Cs_Callout,
                            exDevConfPtr->SpiTimeCs2Cs,
                            SPI_70_CS2CS );
                       
                        /* Assert chip select (CS to CS) */
                        Spi_70_HW_PutChipSelect(
                            exDevConfPtr->SpiCsIdentifier,
                            TRUE,
                            exDevConfPtr->SpiCsPolarity,
                            exDevConfPtr->Spi_70_Cs2Cs_Callout,
                            exDevConfPtr->SpiTimeCs2Cs,
                            SPI_70_CS2CS );
                    }
                } else {
                    /* All jobs have been processed */
                    break;
                }
            } else {
                /* If spi_startChannel or spi_transmitChannel or spi_receiveChannel */
                /* failed in SPI_70_SYNC or SPI_70_ASYNC_POLLING                    */
 
                /* Stop channel */
                spi_stopChannel( hwUnitInfoPtr, exDevConfPtr );
               
                /* Disable interrupts */
                Spi_70_HW_DisableInterrupts();
                break;
            }
        }
    }
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
    else {
        /* If mode is SPI_70_ASYNC_INTERRUPT or SPI_70_ASYNC_INTERRUPT_MAIN */
        /* Get channel Id */
        chListPtr = &(jobInfo->JobConfPtr->SpiChannelList[jobInfo->ChIndex]);
        chId = chListPtr->SpiChannelAssignment->SpiChannelId;
       
        /* Get channel information */
        chInfoPtr = &(s_ChannelInfo[chId]);
       
        /* Receive channel */
        rtn = spi_receiveChannel( chInfoPtr, hwUnitInfoPtr );
       
        if ( E_OK == rtn ) {
            hwUnitInfoPtr->ChDataCnt++;
           
            /* If spi_receiveChannel succeeded */
            /* Check if all data have been processed */
            if ( hwUnitInfoPtr->ChDataCnt < chInfoPtr->ChDataNum ) {
                /* Transmit channel */
                rtn = spi_transmitChannel( chInfoPtr, hwUnitInfoPtr );
            } else {
                /* Stop channel */
                spi_stopChannel( hwUnitInfoPtr, exDevConfPtr );
               
                jobInfo->ChIndex++;
               
                /* Check if all channels have been processed */
                if ( jobInfo->ChIndex < jobInfo->JobConfPtr->Spi_NumOfChannelList ) {
                   
                    if ( ( TRUE == exDevConfPtr->SpiEnableCs )
                      && ( SPI_70_CS_TOGGLE == exDevConfPtr->SpiCsBehavior ) ) {
                        /* If SpiCsBehavior is CS_TOGGLE,  */
                        /* the chip select is released after each data frame completion. */
 
                        /* Negate chip select (CS to CS) */
                        Spi_70_HW_PutChipSelect(
                            exDevConfPtr->SpiCsIdentifier,
                            FALSE,
                            exDevConfPtr->SpiCsPolarity,
                            exDevConfPtr->Spi_70_Cs2Cs_Callout,
                            exDevConfPtr->SpiTimeCs2Cs,
                            SPI_70_CS2CS );
                       
                        /* Assert chip select (CS to CS) */
                        Spi_70_HW_PutChipSelect(
                            exDevConfPtr->SpiCsIdentifier,
                            TRUE,
                            exDevConfPtr->SpiCsPolarity,
                            exDevConfPtr->Spi_70_Cs2Cs_Callout,
                            exDevConfPtr->SpiTimeCs2Cs,
                            SPI_70_CS2CS );
                    }
                    /* Start channel */
                    rtn = spi_startChannel( chInfoPtr, hwUnitInfoPtr, exDevConfPtr );
                }
            }
        }
       
        if ( E_NOT_OK == rtn ) {
            /* If spi_receiveChannel or spi_transmitChannel or spi_startChannel */
            /* failed in SPI_70_ASYNC_INTERRUPT or SPI_70_ASYNC_INTERRUPT_MAIN  */
 
            /* Stop channel */
            spi_stopChannel( hwUnitInfoPtr, exDevConfPtr );
           
            /* Disable interrupts */
            Spi_70_HW_DisableInterrupts();
        }
    }
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
   
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_startJob                                                 */
/* Param       : (in) jobInfo: pointer to Job information.                    */
/*             : (in) mode   : specify mode when this function is called.     */
/* Return      : void                                                         */
/* Contents    : Start job for transmit                                       */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType spi_startJob( Spi_70_JobInfoType* jobInfo, Spi_70_FuncModeType mode ) {
   
    const Spi_ExternalDeviceType* exDevConfPtr;
    Std_ReturnType rtn;
   
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
    uint8_least hwUnitCnt;
    Spi_70_HwUnitInfoType* hwUnitInfoPtr = NULL_PTR;
    const Spi_ChannelListType* chListPtr;
    Spi_ChannelType chId;
    const Spi_70_ChInfoType* chInfoPtr;
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
   
    /* [SWS_Spi_00286] */
    jobInfo->JobResult = SPI_JOB_PENDING;
   
    /* Get external device config */
    exDevConfPtr = jobInfo->JobConfPtr->SpiDeviceAssignment;
   
    /* Assert chip select (CS to Clock) */
    if ( TRUE == exDevConfPtr->SpiEnableCs ) {
        Spi_70_HW_PutChipSelect(
            exDevConfPtr->SpiCsIdentifier,
            TRUE,
            exDevConfPtr->SpiCsPolarity,
            exDevConfPtr->Spi_70_Cs2Clk_Callout,
            exDevConfPtr->SpiTimeCs2Clk,
            SPI_70_CS2CLK );
    }
   
    /* Set the channel being processed */
    jobInfo->ChIndex = 0U;
   
    rtn = E_OK;
   
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
    if ( ( SPI_70_ASYNC_INTERRUPT == mode ) || ( SPI_70_ASYNC_INTERRUPT_MAIN == mode ) ) {
        /* Get HW unit information */
        for ( hwUnitCnt = 0U ; hwUnitCnt < SPI_70_MAX_HW_UNIT_USING; hwUnitCnt++ ) {
            if ( exDevConfPtr->SpiHwUnit == s_HwUnitInfo[hwUnitCnt].HwUnit ) {
                hwUnitInfoPtr = &(s_HwUnitInfo[hwUnitCnt]);
            }
        }
       
        /* Get channel Id */
        chListPtr = &(jobInfo->JobConfPtr->SpiChannelList[jobInfo->ChIndex]);
        chId = chListPtr->SpiChannelAssignment->SpiChannelId;
       
        /* Get channel information */
        chInfoPtr = &(s_ChannelInfo[chId]);
       
        /* Start channel */
        rtn = spi_startChannel( chInfoPtr, hwUnitInfoPtr, exDevConfPtr );
       
        if ( E_OK == rtn ) {
            /* Transmit channel */
            rtn = spi_transmitChannel( chInfoPtr, hwUnitInfoPtr );
        }
       
        if ( E_NOT_OK == rtn ) {
            /* Stop channel */
            spi_stopChannel( hwUnitInfoPtr, exDevConfPtr );
           
            /* Disable interrupts */
            Spi_70_HW_DisableInterrupts();
        }
    }
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
   
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_stopJob                                                  */
/* Param       : (in) jobInfo  : pointer to job information to run.           */
/*             : (in) jobResult: result of job for setting.                   */
/*             : (in) mode     : specify mode when this function is called.   */
/* Return      : void                                                         */
/* Contents    : Stop job transmit                                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void spi_stopJob( Spi_70_JobInfoType* jobInfo, Spi_JobResultType JobResult,
                         Spi_70_FuncModeType mode )
{
    const Spi_ExternalDeviceType* exDevConfPtr;
   
    /* Set result */
    jobInfo->JobResult = JobResult;
   
    /* Get external device config */
    exDevConfPtr = jobInfo->JobConfPtr->SpiDeviceAssignment;
   
    /* Negate chip select (Clock to CS) */
    if ( TRUE == exDevConfPtr->SpiEnableCs ) {
        Spi_70_HW_PutChipSelect(
            exDevConfPtr->SpiCsIdentifier,
            FALSE,
            exDevConfPtr->SpiCsPolarity,
            exDevConfPtr->Spi_70_Clk2Cs_Callout,
            exDevConfPtr->SpiTimeClk2Cs,
            SPI_70_CLK2CS );
    }
   
#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
    if ( SPI_70_SYNC != mode ) {
        if ( NULL_PTR != jobInfo->JobConfPtr->SpiJobEndNotification ) {
            jobInfo->JobConfPtr->SpiJobEndNotification();
        }
    }
#endif /* #if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) ||
                ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_startChannel                                             */
/* Param       : (in) chInfo     : pointer to channel information to run.     */
/*             : (in) hwUnitInfo : pointer to HW Unit information to run.     */
/*             : (in) exDevConf  : pointer to external device configuration   */
/*             :                       information to run.                    */
/* Return      : void                                                         */
/* Contents    : Start channel for transmit                                   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType spi_startChannel( const Spi_70_ChInfoType* chInfo,
    Spi_70_HwUnitInfoType* hwUnitInfo, const Spi_ExternalDeviceType* exDevConf )
{
    Std_ReturnType rtn;
   
    /* Start channel */
    rtn = Spi_70_HW_StartChannel(
            exDevConf->SpiHwUnit,
            exDevConf->SpiDeviceId,
            chInfo->ChConfPtr->SpiDataWidth,
            chInfo->ChConfPtr->SpiTransferStart,
            exDevConf->SpiDataShiftEdge,
            exDevConf->SpiShiftClockIdleLevel );
   
    if ( rtn == E_OK ) {
        /* State transition to start */
        hwUnitInfo->ChStatus = SPI_70_CH_START;
        hwUnitInfo->ChDataCnt = 0U;
    }
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_transmitChannel                                          */
/* Param       : (in) chInfo     : pointer to channel information.            */
/*             : (in) hwUnitInfo : pointer to HW unit information.            */
/* Return      : void                                                         */
/* Contents    : transmit channel.                                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType spi_transmitChannel( const Spi_70_ChInfoType* chInfo,
                                           Spi_70_HwUnitInfoType* hwUnitInfo )
{
    uint16 dataPos;
    uint8  dataWidth;
    uint8  txData8bit;
    uint16 txData16bit;
    uint8  mask8bit;
    uint16 mask16bit;
    Std_ReturnType rtn;
 
   
    /* [SWS_Spi_00355] */
    /* The data buffer has to be aligned to 16 bits. */
    dataPos = (uint16)( hwUnitInfo->ChDataCnt * SPI_WIDTH_TWO );
    dataWidth = chInfo->ChConfPtr->SpiDataWidth;
   
    /* [SWS_Spi_00437] */
    /* uint8 for 9 > SpiDataWidth */
    if ( 9U > dataWidth ) {
        /* [SWS_Spi_00023][SWS_Spi_00028] */
        /* Check whether to use default value */
        if ( NULL_PTR != chInfo->ChTxBufferPtr ) {
            txData8bit = chInfo->ChTxBufferPtr[dataPos];
        } else {
            txData8bit = (uint8)chInfo->ChConfPtr->SpiDefaultData;
        }
       
        /* [SWS_Spi_00289] */
        /* [SWS_Spi_00290] */
        /* If SpiDataWidth is not 8bit */
        if ( 8U != dataWidth ) {
            mask8bit = (uint8)1U << ( dataWidth - 1U );
            txData8bit &= mask8bit;
        }
       
        /* Transmit channel */
        rtn = Spi_70_HW_TransmitChannel( hwUnitInfo->HwUnit, &txData8bit, 1U );
       
        if ( E_OK == rtn ) {
            /* State transition to transmit */
            hwUnitInfo->ChStatus = SPI_70_CH_TX;
        }
    } else { /* uint16 for 9 <= SpiDataWidth */
        /* [SWS_Spi_00023][SWS_Spi_00028] */
        /* Check whether to use default value */
        if ( NULL_PTR != chInfo->ChTxBufferPtr ) {
            /* RL78 is little endian */
            txData16bit = chInfo->ChTxBufferPtr[dataPos];
            txData16bit |= ( (uint16)chInfo->ChTxBufferPtr[dataPos + 1U] << 8U );
        } else {
            txData16bit = chInfo->ChConfPtr->SpiDefaultData;
        }
       
        /* [SWS_Spi_00289] */
        /* [SWS_Spi_00290] */
        /* If SpiDataWidth is not 16bit */
        if ( 16U != dataWidth ) {
            mask16bit = ( (uint16)1U << ( dataWidth - 1U ) );
            txData16bit &= mask16bit;
        }
       
        /* Transmit channel */
        rtn = Spi_70_HW_TransmitChannel( hwUnitInfo->HwUnit, (const uint8*)&txData16bit, (uint8)SPI_WIDTH_TWO );
       
        if ( E_OK == rtn ) {
            /* State transition to transmit */
            hwUnitInfo->ChStatus = SPI_70_CH_TX;
        }
    }
   
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_receiveChannel                                           */
/* Param       : (in) chInfo     : pointer to channel information.            */
/*             : (in) hwUnitInfo : pointer to HW unit information.            */
/* Return      : void                                                         */
/* Contents    : receive channel for transmit.                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType spi_receiveChannel( const Spi_70_ChInfoType* chInfo,
                                          Spi_70_HwUnitInfoType* hwUnitInfo ) {
   
    uint16 dataPos;
    uint8  dataWidth;
    uint8  rxData8bit;
    uint16 rxData16bit;
    uint8  mask8bit;
    uint16 mask16bit;
    uint8  rxData[2];
    uint8  len;
    uint16 rightShiftVal;
   
    Std_ReturnType rtn;
   
    /* [SWS_Spi_00030] */
    if ( NULL_PTR != chInfo->ChRxBufferPtr ) {
        /* Until data reception */
        while ( TRUE ) {
            /* Receive channel */
            rtn = Spi_70_HW_ReceiveChannel( hwUnitInfo->HwUnit, &rxData[0], &len );
           
            if ( E_OK == rtn ) {
                /* Received data exists */
                if ( 0U < len ) {
                    /* State transition to receive */
                    hwUnitInfo->ChStatus = SPI_70_CH_RX;
                   
                    /* [SWS_Spi_00355] */
                    /* The data buffer has to be aligned to 16 bits. */
                    dataPos = hwUnitInfo->ChDataCnt * (uint16)SPI_WIDTH_TWO;
                    dataWidth = chInfo->ChConfPtr->SpiDataWidth;
                   
                    /* [SWS_Spi_00437] */
                    /* uint8 for 9 > SpiDataWidth */
                    if ( 9U > dataWidth ) {
                        rxData8bit = rxData[0];
                       
                        /* [SWS_Spi_00289] */
                        /* [SWS_Spi_00290] */
                        /* If SpiDataWidth is not 8bit */
                        if ( 8U != dataWidth ) {
                            mask8bit = (uint8)1U << ( dataWidth - 1U );
                            rxData8bit &= mask8bit;
                        }
                       
                        chInfo->ChRxBufferPtr[dataPos] = rxData8bit;
                        chInfo->ChRxBufferPtr[dataPos + 1U] = 0x00U;
                    } else {
                        /* RL78 is little endian */
                        rxData16bit = rxData[0];
                        rxData16bit |= ( (uint16)rxData[1] << 8U );
                       
                        /* [SWS_Spi_00289] */
                        /* [SWS_Spi_00290] */
                        /* If SpiDataWidth is not 16bit */
                        if ( 16U != dataWidth ) {
                            mask16bit = ( (uint16)1U << ( dataWidth - 1U ) );
                            rxData16bit &= mask16bit;
                        }
                       
                        rightShiftVal = 8U;
                       
                        /* RL78 is little endian */
                        chInfo->ChRxBufferPtr[dataPos] = (uint8)rxData16bit;
                        chInfo->ChRxBufferPtr[dataPos + 1U] = (uint8)( rxData16bit >> rightShiftVal );
                    }
                   
                    break;
                }
            } else {
                break;
            }
        }
    } else {
        /* If chInfo->ChRxBufferPtr is NULL_PTR, */
        /* following [SWS_Spi_00036] and [SWS_Spi_00030], ignore the received data. */
        rtn = E_OK;
       
        /* State transition to receive */
        hwUnitInfo->ChStatus = SPI_70_CH_RX;
    }
   
    return rtn;
}
 
/******************************************************************************/
/* ModuleID    : SPI_MODULE_ID (83)                                           */
/* ServiceID   : --                                                           */
/* Name        : spi_stopChannel                                              */
/* Param       : (in) hwUnitInfo : pointer to HW unit information.            */
/*             : (in) exDevConf  : pointer to external device configuration   */
/*             :                       information to run.                    */
/* Return      : void                                                         */
/* Contents    : Stop channel transmit                                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void spi_stopChannel( Spi_70_HwUnitInfoType* hwUnitInfo,
                             const Spi_ExternalDeviceType* exDevConf )
{
    /* Stop channel */
    Spi_70_HW_StopChannel( hwUnitInfo->HwUnit, exDevConf->SpiShiftClockIdleLevel );
   
    /* State transition to stop */
    hwUnitInfo->ChStatus = SPI_70_CH_STOP;
}
 
#define SPI_STOP_SEC_CODE_LOCAL
#include "Spi_MemMap.h"
 
/* EOF Spi.c ******************************************************************/