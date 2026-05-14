/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Spi_70_Types.h                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : SPI module type definition header file                       */
/*               The SPI Handler/Driver provides services for reading         */
/*               from and writing to devices connected via SPI busses.        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef SPI_70_TYPES_H_
#define SPI_70_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Spi_70_HW_Types.h"
#include "QiNeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_TYPES_H               (70U)
#define SPI_70_MODULE_ID_TYPES_H               (83U)

#define SPI_70_AR_RELEASE_MAJOR_VERSION_TYPES_H   (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_TYPES_H   (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_TYPES_H (0U)

#define SPI_70_SW_MAJOR_VERSION_TYPES_H        (1U)
#define SPI_70_SW_MINOR_VERSION_TYPES_H        (0U)
#define SPI_70_SW_PATCH_VERSION_TYPES_H        (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Spi_70_HW_Types.h version check start */
#if ( SPI_70_VENDOR_ID_TYPES_H  != SPI_70_VENDOR_ID_HW_TYPES_H )
    #error "VENDOR ID for Spi_70_Types.h and Spi_70_HW_Types.h are different"
#endif

#if ( SPI_70_MODULE_ID_TYPES_H  != SPI_70_MODULE_ID_HW_TYPES_H )
    #error "MODULE ID for Spi_70_Types.h and Spi_70_HW_Types.h are different"
#endif

#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != SPI_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != SPI_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_TYPES_H != SPI_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Spi_70_Types.h and Spi_70_HW_Types.h are different"
#endif

#if ( ( SPI_70_SW_MAJOR_VERSION_TYPES_H  != SPI_70_SW_MAJOR_VERSION_HW_TYPES_H ) || \
      ( SPI_70_SW_MINOR_VERSION_TYPES_H  != SPI_70_SW_MINOR_VERSION_HW_TYPES_H ) || \
      ( SPI_70_SW_PATCH_VERSION_TYPES_H  != SPI_70_SW_PATCH_VERSION_HW_TYPES_H ) \
    )
    #error "Software Version Numbers of Spi_70_Types.h and Spi_70_HW_Types.h are different"
#endif

/* Spi_70_HW_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef uint8 Spi_70_BufferType;
#define SPI_70_BUFFER_IB                     (uint8)(0U)
#define SPI_70_BUFFER_EB                     (uint8)(1U)

typedef uint8 Spi_70_TransferStartType;
#define SPI_70_START_LSB                     (uint8)(0U)
#define SPI_70_START_MSB                     (uint8)(1U)

typedef uint8 Spi_70_CsBehaviorType;
#define SPI_70_CS_KEEP_ASSERTED              (uint8)(0U)
#define SPI_70_CS_TOGGLE                     (uint8)(1U)

typedef uint8 Spi_70_PolarityType;
#define SPI_70_POLARITY_HIGH                 (uint8)(0U)
#define SPI_70_POLARITY_LOW                  (uint8)(1U)

typedef uint8 Spi_70_CsSelectionType;
#define SPI_70_CS_VIA_GPIO                   (uint8)(0U)
#define SPI_70_CS_VIA_PERIPHERAL_ENGINE      (uint8)(1U)

typedef uint8 Spi_70_DataShiftEdgeType;
#define SPI_70_EDGE_LEADING                  (uint8)(0U)
#define SPI_70_EDGE_TRAILING                 (uint8)(1U)

typedef Spi_70_HW_IdleLevelType Spi_70_IdleLevelType;
#define SPI_70_IDLE_HIGH                     (SPI_70_HW_IDLE_HIGH)
#define SPI_70_IDLE_LOW                      (SPI_70_HW_IDLE_LOW)

typedef uint8 Spi_70_FuncModeType;
#define SPI_70_SYNC                      (uint8)(0U)
#define SPI_70_ASYNC_POLLING             (uint8)(1U)
#define SPI_70_ASYNC_INTERRUPT           (uint8)(2U)
#define SPI_70_ASYNC_INTERRUPT_MAIN      (uint8)(3U)

/* [SWS_Spi_00373] */
typedef uint8 Spi_StatusType;
#define SPI_UNINIT                       (uint8)(0U)
#define SPI_IDLE                         (uint8)(1U)
#define SPI_BUSY                         (uint8)(2U)

/* [SWS_Spi_00374] */
typedef uint8 Spi_JobResultType;
#define SPI_JOB_OK                       (uint8)(0U)
#define SPI_JOB_PENDING                  (uint8)(1U)
#define SPI_JOB_FAILED                   (uint8)(2U)
#define SPI_JOB_QUEUED                   (uint8)(3U)

/* [SWS_Spi_00375] */
typedef uint8 Spi_SeqResultType;
#define SPI_SEQ_OK                       (uint8)(0U)
#define SPI_SEQ_PENDING                  (uint8)(1U)
#define SPI_SEQ_FAILED                   (uint8)(2U)
#define SPI_SEQ_CANCELED                 (uint8)(3U)

typedef uint8 Spi_70_SeqResultType;
#define SPI_70_SEQ_PENDING_SYNC          (uint8)(4U)
#define SPI_70_SEQ_PENDING_ASYNC         (uint8)(5U)
#define SPI_70_SEQ_CANCELED_NOT_NOTIFIED (uint8)(6U)
#define SPI_70_SEQ_CANCELED_NOTIFIED     (uint8)(7U)

/* [SWS_Spi_00376] */
typedef uint8 Spi_DataBufferType;

/* [SWS_Spi_00377] */
typedef uint16 Spi_NumberOfDataType;

/* [SWS_Spi_00378] */
typedef uint8 Spi_ChannelType;

/* [SWS_Spi_00379] */
typedef uint16 Spi_JobType;

/* [SWS_Spi_00380] */
typedef uint8 Spi_SequenceType;

/* [SWS_Spi_00381] */
typedef uint8 Spi_HWUnitType;

#if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) )
/* [SWS_Spi_00382] */
typedef uint8 Spi_AsyncModeType;
#define SPI_POLLING_MODE     (uint8)(0U)
#define SPI_INTERRUPT_MODE   (uint8)(1U)
#endif /* if ( ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_1 ) || ( SPI_LEVEL_DELIVERED == SPI_70_LEVEL_2 ) ) */

/* [ECUC_Spi_00104] */
typedef struct {
    Spi_ChannelType             SpiChannelId;        /* [ECUC_Spi_00200] */
    Spi_70_BufferType           SpiChannelType;      /* [ECUC_Spi_00201] */
    uint8                       SpiDataWidth;        /* [ECUC_Spi_00202] */
    uint16                      SpiDefaultData;      /* [ECUC_Spi_00203] */
    uint16                      SpiEbMaxLength;      /* [ECUC_Spi_00204] */
    uint16                      SpiNbBuffers;        /* [ECUC_Spi_00205] */
    Spi_70_TransferStartType    SpiTransferStart;    /* [ECUC_Spi_00206] */
} Spi_ChannelConfigurationType;

/* [ECUC_Spi_00233] */
typedef struct {
    uint8                                   SpiChannelIndex;      /* [ECUC_Spi_00234] */
    const Spi_ChannelConfigurationType*     SpiChannelAssignment; /* [ECUC_Spi_00215] */
} Spi_ChannelListType;

/* [ECUC_Spi_00207] */
typedef struct {
    uint8                     SpiDeviceId;           /* index of external device */
    uint32                    SpiBaudrate;           /* [ECUC_Spi_00208] */
    Spi_70_CsBehaviorType     SpiCsBehavior;         /* [ECUC_Spi_00209] */
    uint8                     SpiCsIdentifier;       /* [ECUC_Spi_00209] */
    Spi_70_PolarityType       SpiCsPolarity;         /* [ECUC_Spi_00210] */
    Spi_70_CsSelectionType    SpiCsSelection;        /* [ECUC_Spi_00211] */
    Spi_70_DataShiftEdgeType  SpiDataShiftEdge;      /* [ECUC_Spi_00212] */
    boolean                   SpiEnableCs;           /* [ECUC_Spi_00213] */
    Spi_HWUnitType            SpiHwUnit;             /* [ECUC_Spi_00217] */
    Spi_70_IdleLevelType      SpiShiftClockIdleLevel;/* [ECUC_Spi_00218] */
    uint32                    SpiTimeClk2Cs;         /* [ECUC_Spi_00214] */
    uint32                    SpiTimeCs2Clk;         /* [ECUC_Spi_00247] */
    uint32                    SpiTimeCs2Cs;          /* [ECUC_Spi_00248] */
    void (*Spi_70_Clk2Cs_Callout)(uint32 timeClk2Cs);
    void (*Spi_70_Cs2Clk_Callout)(uint32 timeCs2Clk);
    void (*Spi_70_Cs2Cs_Callout)(uint32 timeCs2Cs);
} Spi_ExternalDeviceType;

/* [ECUC_Spi_00105] */
typedef struct {
    void (*SpiJobEndNotification)(void);                /* [ECUC_Spi_00218] */
    Spi_JobType SpiJobId;                               /* [ECUC_Spi_00219] */
    const Spi_ExternalDeviceType* SpiDeviceAssignment;  /* [ECUC_Spi_00216] */
    uint8 Spi_NumOfChannelList;                         /* number of SpiChannelList. */
    const Spi_ChannelListType* SpiChannelList;
} Spi_JobConfigurationType;

/* [ECUC_Spi_00106] */
typedef struct {
    void (*SpiSeqEndNotification)(void);                /* [ECUC_Spi_00223] */
    Spi_SequenceType SpiSequenceId;                     /* [ECUC_Spi_00224] */
    uint16 Spi_NumOfJobAssignment;                      /* number of SpiJobAssignment. */
    const Spi_JobConfigurationType* const* SpiJobAssignment; /* [ECUC_Spi_00221] */
} Spi_SequenceConfigurationType;

/* channel and IB link information */
typedef struct {
    Spi_ChannelType                   SpiChannelId;     /* channel id. */
    QL_70_FAR Spi_DataBufferType*     ChTxBufferPtr;    /* channel transmit buffer pointer. */
    QL_70_FAR Spi_DataBufferType*     ChRxBufferPtr;    /* channel receive buffer pointer. */
} Spi_70_ChannelIBLinkType;

/* [ECUC_Spi_00091] */
typedef struct {
    uint8                             SpiMaxChannel;    /* [ECUC_Spi_00197] */
    uint16                            SpiMaxJob;        /* [ECUC_Spi_00198] */
    uint8                             SpiMaxSequence;   /* [ECUC_Spi_00199] */
    const Spi_ChannelConfigurationType* SpiChannel;      /* [ECUC_Spi_00200] */
    const Spi_ExternalDeviceType*       SpiExternalDevice;
    const Spi_JobConfigurationType*     SpiJob;
    const Spi_SequenceConfigurationType* SpiSequence;
    const Spi_70_RL78F2X_HwUnitConfType* Spi_70_HwUnitConfPtr; /* list of H/W units */
    const Spi_70_RL78F2X_CsConfType*      Spi_70_CsConfPtr;    /* list of CS configurations */
    const Spi_70_ChannelIBLinkType*      Spi_70_ChIBLink;      /* list of IB channels */
} Spi_DriverType;

/* [ECUC_Spi_00103] */
typedef struct {
    Spi_DriverType SpiDriver;                          /* Configuration of 1 instance of a SPI driver. */
} Spi_ConfigType;

/* sequence information */
typedef struct {
    Spi_SequenceType                       SeqId;       /* sequence id */
    const Spi_SequenceConfigurationType*   SeqConfPtr;  /* sequence configuration pointer */
    Spi_70_SeqResultType                   SeqResult;   /* sequence result */
    uint16                                 JobIndex;    /* job index of running */
} Spi_70_SeqInfoType;

/* job information */
typedef struct {
    Spi_JobType                            JobId;       /* job id */
    const Spi_JobConfigurationType*        JobConfPtr;  /* job configuration pointer */
    Spi_JobResultType                      JobResult;   /* job result */
    uint16                                 ChIndex;     /* channel index */
} Spi_70_JobInfoType;

/* channel information */
typedef struct {
    Spi_ChannelType                        ChId;            /* channel id */
    const Spi_ChannelConfigurationType*    ChConfPtr;       /* channel configuration pointer */
    QL_70_FAR Spi_DataBufferType*          ChTxBufferPtr;   /* channel transmit buffer pointer */
    QL_70_FAR Spi_DataBufferType*          ChRxBufferPtr;   /* channel receive buffer pointer */
    Spi_NumberOfDataType                   ChDataNum;       /* channel data number */
} Spi_70_ChInfoType;

/* hardware unit information */
typedef struct {
    Spi_HWUnitType                         HwUnitId;       /* HW unit ID */
    const Spi_70_RL78F2X_HwUnitConfType*   HwUnitConfPtr;  /* HW unit configuration */
    uint8                                  ChIndex;        /* channel index of running */
    Spi_70_HW_ChStatusType                 ChStatus;       /* channel transfer status */
    Spi_NumberOfDataType                   ChDataCnt;      /* channel data counter of transfer */
} Spi_70_HwUnitInfoType;

/*----------------------------------------------------------------------------*/
/* external constant                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

#endif    /* #ifndef SPI_70_TYPES_H_ */

/****************** End Of File Spi_70_Types.h ********************/
