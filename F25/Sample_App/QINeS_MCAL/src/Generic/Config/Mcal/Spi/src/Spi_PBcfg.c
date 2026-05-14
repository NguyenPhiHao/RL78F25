/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Spi_PBcfg.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : SPI Post Build Configuration data                            */
/*               The SPI Handler/Driver provides services for reading from    */
/*               and writing to devices connected via SPI busses.             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include header                                                             */
/*----------------------------------------------------------------------------*/
#include "Spi.h"                                /* [SPI274] */
#include "Spi_70_RL78F2X_Callout.h"
#include "Spi_Externals.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_PBCFG_C                      (70U)
#define SPI_70_MODULE_ID_PBCFG_C                      (83U)

#define SPI_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_PBCFG_C       (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0U)

#define SPI_70_SW_MAJOR_VERSION_PBCFG_C               (1U)
#define SPI_70_SW_MINOR_VERSION_PBCFG_C               (0U)
#define SPI_70_SW_PATCH_VERSION_PBCFG_C               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Spi.h version check start */

#if ( SPI_70_VENDOR_ID_PBCFG_C != SPI_VENDOR_ID )
    #error "VENDOR ID for Spi_PBcfg.c and Spi.h are different"
#endif

#if ( SPI_70_MODULE_ID_PBCFG_C != SPI_MODULE_ID )
    #error "MODULE ID for Spi_PBcfg.c and Spi.h are different"
#endif

#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MAJOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MINOR_VERSION ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Spi_PBcfg.c and Spi.h are different"
#endif

#if ( ( SPI_70_SW_MAJOR_VERSION_PBCFG_C != SPI_SW_MAJOR_VERSION ) || \
      ( SPI_70_SW_MINOR_VERSION_PBCFG_C != SPI_SW_MINOR_VERSION ) || \
      ( SPI_70_SW_PATCH_VERSION_PBCFG_C != SPI_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Spi_PBcfg.c and Spi.h are different"
#endif

/* Spi.h version check end */
 
/* Spi_70_RL78F2X_Callout.h version check start */

#if ( SPI_70_VENDOR_ID_PBCFG_C != SPI_70_VENDOR_ID_RL78F2X_CALLOUT_H )
    #error "VENDOR ID for Spi_PBcfg.c and Spi_70_RL78F2X_Callout.h are different"
#endif

#if ( SPI_70_MODULE_ID_PBCFG_C != SPI_70_MODULE_ID_RL78F2X_CALLOUT_H )
    #error "MODULE ID for Spi_PBcfg.c and Spi_70_RL78F2X_Callout.h are different"
#endif

#if ( ( SPI_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_CALLOUT_H ) || \
      ( SPI_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_CALLOUT_H ) || \
      ( SPI_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_CALLOUT_H ) \
    )
    #error "AUTOSAR Version Numbers of Spi_PBcfg.c and Spi_70_RL78F2X_Callout.h are different"
#endif

#if ( ( SPI_70_SW_MAJOR_VERSION_PBCFG_C != SPI_70_SW_MAJOR_VERSION_RL78F2X_CALLOUT_H ) || \
      ( SPI_70_SW_MINOR_VERSION_PBCFG_C != SPI_70_SW_MINOR_VERSION_RL78F2X_CALLOUT_H ) || \
      ( SPI_70_SW_PATCH_VERSION_PBCFG_C != SPI_70_SW_PATCH_VERSION_RL78F2X_CALLOUT_H ) \
    )
    #error "Software Version Numbers of Spi_PBcfg.c and Spi_70_RL78F2X_Callout.h are different"
#endif

/* Spi_70_RL78F2X_Callout.h version check end */

/*----------------------------------------------------------------------------*/
/*  data declarations                                                         */
/*----------------------------------------------------------------------------*/
/* internal buffer */
/* for SPI_70_CH_ID_0 width=8, nBuffers=1 */
#define SPI_START_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
uint8 QL_70_FAR spi_ibTx6[ 2 ] = {
    0, 0
};
#define SPI_STOP_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
uint8 QL_70_FAR spi_ibRx6[ 2 ] = {
    0, 0
};
#define SPI_STOP_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"

/* for SPI_70_CH_ID_1 width=8, nBuffers=3 */
#define SPI_START_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
uint8 QL_70_FAR spi_ibTx7[ 14 ] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0
};
#define SPI_STOP_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
uint8 QL_70_FAR spi_ibRx7[ 14 ] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0
};
#define SPI_STOP_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"

/* for SPI_70_CH_ID_2 width=8, nBuffers=2 */
#define SPI_START_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
uint8 QL_70_FAR spi_ibTx8[ 4 ] = {
    0, 0, 0, 0
};
#define SPI_STOP_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
uint8 QL_70_FAR spi_ibRx8[ 4 ] = {
    0, 0, 0, 0
};
#define SPI_STOP_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"

/* for SPI_70_CH_ID_3 width=8, nBuffers=7 */
#define SPI_START_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
uint8 QL_70_FAR spi_ibTx9[ 14 ] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0
};
#define SPI_STOP_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"
uint8 QL_70_FAR spi_ibRx9[ 14 ] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0
};
#define SPI_STOP_SEC_VAR_INIT_LOCAL_8
#include "Spi_MemMap.h"

/*----------------------------------------------------------------------------*/
/*  const data declarations                                                   */
/*----------------------------------------------------------------------------*/

#define SPI_START_SEC_CONFIG_DATA_8
#include "Spi_MemMap.h"

const Spi_70_ChannelIBLinkType Spi_ChIBLink[ SPI_70_NUM_OF_CHIBLINK ] = {
    { SPI_70_CH_ID_6,    (Spi_DataBufferType QL_70_FAR *)spi_ibTx6,     (Spi_DataBufferType QL_70_FAR *)spi_ibRx6  },
    { SPI_70_CH_ID_7,    (Spi_DataBufferType QL_70_FAR *)spi_ibTx7,     (Spi_DataBufferType QL_70_FAR *)spi_ibRx7  },
    { SPI_70_CH_ID_8,    (Spi_DataBufferType QL_70_FAR *)spi_ibTx8,     (Spi_DataBufferType QL_70_FAR *)spi_ibRx8  },
    { SPI_70_CH_ID_9,    (Spi_DataBufferType QL_70_FAR *)spi_ibTx9,     (Spi_DataBufferType QL_70_FAR *)spi_ibRx9  },
};

#define SPI_STOP_SEC_CONFIG_DATA_8
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_16
#include "Spi_MemMap.h"

const Spi_ChannelConfigurationType Spi_ChConfig[ SPI_MAX_CHANNEL ] = {
    {    /* [0] */ /* EB:WREN */
        SPI_70_CH_ID_0,         /* SpiChannelId */
        SPI_70_BUFFER_EB,       /* SpiChannelType */
        8U,                    /* SpiDataWidth */
        0x00U,                  /* SpiDefaultData */
        2U,                    /* SpiEbMaxLength */
        0U,                     /* SpiIbNBuffers */
        SPI_70_START_MSB        /* SpiTransferStart */
    },
    {   /* [1] */ /* EB:READ */
        SPI_70_CH_ID_1,         /* SpiChannelId */
        SPI_70_BUFFER_EB,       /* SpiChannelType */
        8U,                     /* SpiDataWidth */
        0x001U,                 /* SpiDefaultData */
        14U,                /* SpiEbMaxLength */
        0U,                     /* SpiIbNBuffers */
        SPI_70_START_MSB        /* SpiTransferStart */
    },
    {   /* [2] */ /* EB:RDSR */
        SPI_70_CH_ID_2,         /* SpiChannelId */
        SPI_70_BUFFER_EB,       /* SpiChannelType */
        8U,                     /* SpiDataWidth */
        0xFFU,                  /* SpiDefaultData */
        4U,                     /* SpiEbMaxLength */
        0U,                     /* SpiIbNBuffers */
        SPI_70_START_MSB        /* SpiTransferStart */
    },
    {   /* [3] */ /* EB:WRITE */
        SPI_70_CH_ID_3,         /* SpiChannelId */
        SPI_70_BUFFER_EB,       /* SpiChannelType */
        8U,                     /* SpiDataWidth */
        0xFFU,                  /* SpiDefaultData */
        14U,                /* SpiEbMaxLength */
        0U,                     /* SpiIbNBuffers */
        SPI_70_START_MSB        /* SpiTransferStart */
    },
    {   /* [4] */
        SPI_70_CH_ID_4,         /* SpiChannelId */
        SPI_70_BUFFER_EB,       /* SpiChannelType */
        8U,                     /* SpiDataWidth */
        0x5AU,                  /* SpiDefaultData */
        16U,                /* SpiEbMaxLength */
        0U,                     /* SpiIbNBuffers */
        SPI_70_START_MSB        /* SpiTransferStart */
    },
    {   /* [5] */
        SPI_70_CH_ID_5,         /* SpiChannelId */
        SPI_70_BUFFER_EB,       /* SpiChannelType */
        8U,                     /* SpiDataWidth */
        0xA5U,                  /* SpiDefaultData */
        14U,                /* SpiEbMaxLength */
        0U,                     /* SpiIbNBuffers */
        SPI_70_START_MSB        /* SpiTransferStart */
    },
    {   /* [6] */  /* IB:WREN/WRDI */
        SPI_70_CH_ID_6,         /* SpiChannelId */
        SPI_70_BUFFER_IB,       /* SpiChannelType */
        8U,                    /* SpiDataWidth */
        0x00U,                  /* SpiDefaultData */
        0U,                    /* SpiEbMaxLength */
        1U,                     /* SpiIbNBuffers */
        SPI_70_START_MSB        /* SpiTransferStart */
    },
    {   /* [7] */  /* IB:READ */
        SPI_70_CH_ID_7,         /* SpiChannelId */
        SPI_70_BUFFER_IB,       /* SpiChannelType */
        8U,                     /* SpiDataWidth */
        0x001U,                 /* SpiDefaultData */
        0U,                /* SpiEbMaxLength */
        7U,                     /* SpiIbNBuffers */
        SPI_70_START_MSB        /* SpiTransferStart */
    },
    {   /* [8] */  /* IB:RDSR */
        SPI_70_CH_ID_8,         /* SpiChannelId */
        SPI_70_BUFFER_IB,       /* SpiChannelType */
        8U,                     /* SpiDataWidth */
        0xFFU,                  /* SpiDefaultData */
        0U,                /* SpiEbMaxLength */
        2U,                     /* SpiIbNBuffers */
        SPI_70_START_MSB        /* SpiTransferStart */
    },
    {   /* [9] */  /* IB:WRITE */
        SPI_70_CH_ID_9,         /* SpiChannelId */
        SPI_70_BUFFER_IB,       /* SpiChannelType */
        8U,                     /* SpiDataWidth */
        0xFFU,                  /* SpiDefaultData */
        0U,                /* SpiEbMaxLength */
        7U,                     /* SpiIbNBuffers */
        SPI_70_START_MSB        /* SpiTransferStart */
    },
};

#define SPI_STOP_SEC_CONFIG_DATA_16
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_32
#include "Spi_MemMap.h"

const Spi_ExternalDeviceType Spi_ExtDevConfig[ SPI_70_MAX_EX_DEVICE ] = {
    { /* [0] */
        SPI_70_DEV0,                            /* SpiDeviceId */
        100000U,                                /* SpiBaudrate */
        SPI_70_CS_KEEP_ASSERTED,                /* SpiCsBehavior */
        SPI_70_CS_DEV0,                         /* SpiCsIdentifier */
        SPI_70_POLARITY_LOW,                    /* SpiCsPolarity */
        SPI_70_CS_VIA_GPIO,                     /* SpiCsSelection */
        SPI_70_EDGE_TRAILING,                   /* SpiDataShiftEdge */
        TRUE,                                   /* SpiEnableCs */
        SPI_70_CSIB2,                           /* SpiHwUnit */
        SPI_70_IDLE_LOW,                        /* SpiShiftClockIdleLevel */
        1U,                                     /* SpiTimeClk2Cs */
        1U,                                     /* SpiTimeCs2Clk */
        1U,                                     /* SpiTimeCs2Cs */
        Spi_70_RL78F2X_WaitClk2Cs_Callout,      /* Spi_70_Clk2Cs_Callout */
        Spi_70_RL78F2X_WaitCs2Clk_Callout,      /* Spi_70_Cs2Clk_Callout */
        Spi_70_RL78F2X_WaitCs2Cs_Callout        /* Spi_70_Cs2Cs_Callout */
    }
};

#define SPI_STOP_SEC_CONFIG_DATA_32
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_8
#include "Spi_MemMap.h"

const Spi_70_HW_CsConfType Spi_CsConf[ SPI_70_NUM_OF_CS_CONF ] = {
    { /* [0] */
        SPI_70_CS_DEV0,         /* SpiCsIdentifier */
        3U,                     /* SpiCsPort */
        1U/*0U*/                      /* SpiCsBitPos */
    }
};

const Spi_ChannelListType Spi_ChList_0[ SPI_70_CH_NUM_JOB_ID_0 ] = {
    { 0U, &Spi_ChConfig[ SPI_70_CH_ID_0 ] }
};

const Spi_ChannelListType Spi_ChList_1[ SPI_70_CH_NUM_JOB_ID_1 ] = {
    { 0U, &Spi_ChConfig[ SPI_70_CH_ID_1 ] },
};

const Spi_ChannelListType Spi_ChList_2[ SPI_70_CH_NUM_JOB_ID_2 ] = {
    { 0U, &Spi_ChConfig[ SPI_70_CH_ID_2 ] },
};

const Spi_ChannelListType Spi_ChList_3[ SPI_70_CH_NUM_JOB_ID_3 ] = {
    { 0U, &Spi_ChConfig[ SPI_70_CH_ID_3 ] },
};

const Spi_ChannelListType Spi_ChList_4[ SPI_70_CH_NUM_JOB_ID_4 ] = {
    { 0U, &Spi_ChConfig[ SPI_70_CH_ID_4 ] },
};

const Spi_ChannelListType Spi_ChList_5[ SPI_70_CH_NUM_JOB_ID_5 ] = {
    { 0U, &Spi_ChConfig[ SPI_70_CH_ID_5 ] },
};

const Spi_ChannelListType Spi_ChList_6[ SPI_70_CH_NUM_JOB_ID_6 ] = {
    { 0U, &Spi_ChConfig[ SPI_70_CH_ID_6 ] },
};

const Spi_ChannelListType Spi_ChList_7[ SPI_70_CH_NUM_JOB_ID_7 ] = {
    { 0U, &Spi_ChConfig[ SPI_70_CH_ID_7 ] },
};

const Spi_ChannelListType Spi_ChList_8[ SPI_70_CH_NUM_JOB_ID_8 ] = {
    { 0U, &Spi_ChConfig[ SPI_70_CH_ID_8 ] },
};

const Spi_ChannelListType Spi_ChList_9[ SPI_70_CH_NUM_JOB_ID_9 ] = {
    { 0U, &Spi_ChConfig[ SPI_70_CH_ID_9 ] },
};

#define SPI_STOP_SEC_CONFIG_DATA_8
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_16
#include "Spi_MemMap.h"

const Spi_JobConfigurationType Spi_JobConfig[ SPI_MAX_JOB ] = {
    { /* [0] */
        Spi_JobEndNotification_0,           /* SpiJobEndNotification */
        SPI_70_JOB_ID_0,                    /* SpiJobId */
        &Spi_ExtDevConfig[ SPI_70_DEV0 ],   /* SpiDeviceAssignment */
        SPI_70_CH_NUM_JOB_ID_0,             /* Spi_70_NumOfChannelList */
        Spi_ChList_0                        /* SpiChannelList */
    },
    { /* [1] */
        Spi_JobEndNotification_1,           /* SpiJobEndNotification */
        SPI_70_JOB_ID_1,                    /* SpiJobId */
        &Spi_ExtDevConfig[ SPI_70_DEV0 ],   /* SpiDeviceAssignment */
        SPI_70_CH_NUM_JOB_ID_1,             /* Spi_70_NumOfChannelList */
        Spi_ChList_1                        /* SpiChannelList */
    },
    { /* [2] */
        Spi_JobEndNotification_2,           /* SpiJobEndNotification */
        SPI_70_JOB_ID_2,                    /* SpiJobId */
        &Spi_ExtDevConfig[ SPI_70_DEV0 ],   /* SpiDeviceAssignment */
        SPI_70_CH_NUM_JOB_ID_2,             /* Spi_70_NumOfChannelList */
        Spi_ChList_2                        /* SpiChannelList */
    },
    { /* [3] */
        Spi_JobEndNotification_3,           /* SpiJobEndNotification */
        SPI_70_JOB_ID_3,                    /* SpiJobId */
        &Spi_ExtDevConfig[ SPI_70_DEV0 ],   /* SpiDeviceAssignment */
        SPI_70_CH_NUM_JOB_ID_3,             /* Spi_70_NumOfChannelList */
        Spi_ChList_3                        /* SpiChannelList */
    },
    { /* [4] */
        Spi_JobEndNotification_4,           /* SpiJobEndNotification */
        SPI_70_JOB_ID_4,                    /* SpiJobId */
        &Spi_ExtDevConfig[ SPI_70_DEV0 ],   /* SpiDeviceAssignment */
        SPI_70_CH_NUM_JOB_ID_4,             /* Spi_70_NumOfChannelList */
        Spi_ChList_4                        /* SpiChannelList */
    },
    {/* [5] */
        Spi_JobEndNotification_5,           /* SpiJobEndNotification */
        SPI_70_JOB_ID_5,                    /* SpiJobId */
        &Spi_ExtDevConfig[ SPI_70_DEV0 ],   /* SpiDeviceAssignment */
        SPI_70_CH_NUM_JOB_ID_5,             /* Spi_70_NumOfChannelList */
        Spi_ChList_5                        /* SpiChannelList */
    },
    {/* [6] */
        Spi_JobEndNotification_6,           /* SpiJobEndNotification */
        SPI_70_JOB_ID_6,                    /* SpiJobId */
        &Spi_ExtDevConfig[ SPI_70_DEV0 ],   /* SpiDeviceAssignment */
        SPI_70_CH_NUM_JOB_ID_6,             /* Spi_70_NumOfChannelList */
        Spi_ChList_6                        /* SpiChannelList */
    },
    {/* [7] */
        Spi_JobEndNotification_7,           /* SpiJobEndNotification */
        SPI_70_JOB_ID_7,                    /* SpiJobId */
        &Spi_ExtDevConfig[ SPI_70_DEV0 ],   /* SpiDeviceAssignment */
        SPI_70_CH_NUM_JOB_ID_7,             /* Spi_70_NumOfChannelList */
        Spi_ChList_7                        /* SpiChannelList */
    },
    {/* [8] */
        Spi_JobEndNotification_8,           /* SpiJobEndNotification */
        SPI_70_JOB_ID_8,                    /* SpiJobId */
        &Spi_ExtDevConfig[ SPI_70_DEV0 ],   /* SpiDeviceAssignment */
        SPI_70_CH_NUM_JOB_ID_8,             /* Spi_70_NumOfChannelList */
        Spi_ChList_8                        /* SpiChannelList */
    },
    {/* [9] */
        Spi_JobEndNotification_9,           /* SpiJobEndNotification */
        SPI_70_JOB_ID_9,                    /* SpiJobId */
        &Spi_ExtDevConfig[ SPI_70_DEV0 ],   /* SpiDeviceAssignment */
        SPI_70_CH_NUM_JOB_ID_9,             /* Spi_70_NumOfChannelList */
        Spi_ChList_9                        /* SpiChannelList */
    },
};

#define SPI_STOP_SEC_CONFIG_DATA_16
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

const Spi_JobConfigurationType* const Spi_JobList0[ SPI_70_JOB_NUM_SEQ_ID_0 ] = {
    &Spi_JobConfig[ SPI_70_JOB_ID_0 ],
};

const Spi_JobConfigurationType* const Spi_JobList1[ SPI_70_JOB_NUM_SEQ_ID_1 ] = {
    &Spi_JobConfig[ SPI_70_JOB_ID_1 ]
};

const Spi_JobConfigurationType* const Spi_JobList2[ SPI_70_JOB_NUM_SEQ_ID_2 ] = {
    &Spi_JobConfig[ SPI_70_JOB_ID_2 ]
};

const Spi_JobConfigurationType* const Spi_JobList3[ SPI_70_JOB_NUM_SEQ_ID_3 ] = {
    &Spi_JobConfig[ SPI_70_JOB_ID_3 ]
};

const Spi_JobConfigurationType* const Spi_JobList4[ SPI_70_JOB_NUM_SEQ_ID_4 ] = {
    &Spi_JobConfig[ SPI_70_JOB_ID_4 ]
};

const Spi_JobConfigurationType* const Spi_JobList5[ SPI_70_JOB_NUM_SEQ_ID_5 ] = {
    &Spi_JobConfig[ SPI_70_JOB_ID_4 ],
    &Spi_JobConfig[ SPI_70_JOB_ID_5 ]
};

const Spi_JobConfigurationType* const Spi_JobList6[ SPI_70_JOB_NUM_SEQ_ID_6 ] = {
    &Spi_JobConfig[ SPI_70_JOB_ID_6 ]
};

const Spi_JobConfigurationType* const Spi_JobList7[ SPI_70_JOB_NUM_SEQ_ID_7 ] = {
    &Spi_JobConfig[ SPI_70_JOB_ID_7 ]
};

const Spi_JobConfigurationType* const Spi_JobList8[ SPI_70_JOB_NUM_SEQ_ID_8 ] = {
    &Spi_JobConfig[ SPI_70_JOB_ID_8 ]
};

const Spi_JobConfigurationType* const Spi_JobList9[ SPI_70_JOB_NUM_SEQ_ID_9 ] = {
    &Spi_JobConfig[ SPI_70_JOB_ID_9 ]
};

const Spi_JobConfigurationType* const Spi_JobList10[ SPI_70_JOB_NUM_SEQ_ID_10 ] = {
    &Spi_JobConfig[ SPI_70_JOB_ID_4 ],
    &Spi_JobConfig[ SPI_70_JOB_ID_8 ]
};

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_16
#include "Spi_MemMap.h"

const Spi_SequenceConfigurationType Spi_SeqConfig[ SPI_MAX_SEQUENCE ] = {
    { /* [0] */  /*WREI/WRDI*/
        Spi_SeqEndNotification_0,                       /* SpiSeqEndNotification */
        SPI_70_SEQ_ID_0,                                /* SpiSequenceId */
        SPI_70_JOB_NUM_SEQ_ID_0,                        /* Spi_70_NumOfJobAssignment */
        (const Spi_JobConfigurationType**)Spi_JobList0  /* SpiJobAssignment */
    },
    { /* [1] */  /*READ*/
        Spi_SeqEndNotification_1,                       /* SpiSeqEndNotification */
        SPI_70_SEQ_ID_1,                                /* SpiSequenceId */
        SPI_70_JOB_NUM_SEQ_ID_1,                        /* Spi_70_NumOfJobAssignment */
        (const Spi_JobConfigurationType**)Spi_JobList1  /* SpiJobAssignment */
    },
    { /* [2] */  /*RDSR*/
        Spi_SeqEndNotification_2,                       /* SpiSeqEndNotification */
        SPI_70_SEQ_ID_2,                                /* SpiSequenceId */
        SPI_70_JOB_NUM_SEQ_ID_2,                        /* Spi_70_NumOfJobAssignment */
        (const Spi_JobConfigurationType**)Spi_JobList2  /* SpiJobAssignment */
    },
    { /* [3] */  /*WRITE*/
        Spi_SeqEndNotification_3,                       /* SpiSeqEndNotification */
        SPI_70_SEQ_ID_3,                                /* SpiSequenceId */
        SPI_70_JOB_NUM_SEQ_ID_3,                        /* Spi_70_NumOfJobAssignment */
        (const Spi_JobConfigurationType**)Spi_JobList3  /* SpiJobAssignment */
    },
    { /* [4] */  /*DUMMY_EB1*/
        Spi_SeqEndNotification_4,                       /* SpiSeqEndNotification */
        SPI_70_SEQ_ID_4,                                /* SpiSequenceId */
        SPI_70_JOB_NUM_SEQ_ID_4,                        /* Spi_70_NumOfJobAssignment */
        (const Spi_JobConfigurationType**)Spi_JobList4  /* SpiJobAssignment */
    },
    { /* [5] */  /*DUMMY2*/
        Spi_SeqEndNotification_5,                       /* SpiSeqEndNotification */
        SPI_70_SEQ_ID_5,                                /* SpiSequenceId */
        SPI_70_JOB_NUM_SEQ_ID_5,                        /* Spi_70_NumOfJobAssignment */
        (const Spi_JobConfigurationType**)Spi_JobList5  /* SpiJobAssignment */
    },
    { /* [6] */
        Spi_SeqEndNotification_6,                       /* SpiSeqEndNotification */
        SPI_70_SEQ_ID_6,                                /* SpiSequenceId */
        SPI_70_JOB_NUM_SEQ_ID_6,                        /* Spi_70_NumOfJobAssignment */
        (const Spi_JobConfigurationType**)Spi_JobList6  /* SpiJobAssignment */
    },
    { /* [7] */
        Spi_SeqEndNotification_7,                       /* SpiSeqEndNotification */
        SPI_70_SEQ_ID_7,                                /* SpiSequenceId */
        SPI_70_JOB_NUM_SEQ_ID_7,                        /* Spi_70_NumOfJobAssignment */
        (const Spi_JobConfigurationType**)Spi_JobList7  /* SpiJobAssignment */
    },
    { /* [8] */
        Spi_SeqEndNotification_8,                       /* SpiSeqEndNotification */
        SPI_70_SEQ_ID_8,                                /* SpiSequenceId */
        SPI_70_JOB_NUM_SEQ_ID_8,                        /* Spi_70_NumOfJobAssignment */
        (const Spi_JobConfigurationType**)Spi_JobList8  /* SpiJobAssignment */
    },
    { /* [9] */
        Spi_SeqEndNotification_9,                       /* SpiSeqEndNotification */
        SPI_70_SEQ_ID_9,                                /* SpiSequenceId */
        SPI_70_JOB_NUM_SEQ_ID_9,                        /* Spi_70_NumOfJobAssignment */
        (const Spi_JobConfigurationType**)Spi_JobList9  /* SpiJobAssignment */
    },
    { /* [9] */
        Spi_SeqEndNotification_10,                       /* SpiSeqEndNotification */
        SPI_70_SEQ_ID_10,                                /* SpiSequenceId */
        SPI_70_JOB_NUM_SEQ_ID_10,                        /* Spi_70_NumOfJobAssignment */
        (const Spi_JobConfigurationType**)Spi_JobList10  /* SpiJobAssignment */
    },
 
};

const Spi_70_HW_HwUnitConfType Spi_HwUnitConfig[ SPI_70_MAX_HW_UNIT_USING ] = {
    { /* [0] SPI_70_CSIB0 */
        SPI_70_RL78F2X_CSIB1_0, /* SpiHwUnit */
        PORT_70_P76,            /* SpiPortClock */
        PORT_70_P75,            /* SpiPortIn : PORT_70_P75 */
        PORT_70_P74             /* SpiPortOut : PORT_70_P74 */
    }
};

const Spi_ConfigType Spi_ConfigData = {
    {   /* Spi_DriverType */
        SPI_MAX_CHANNEL,                                /* SpiMaxChannel */
        SPI_MAX_JOB,                                    /* SpiMaxJob */
        SPI_MAX_SEQUENCE,                               /* SpiMaxSequence */
        Spi_ChConfig,                                   /* SpiChannel */
        Spi_ExtDevConfig,                               /* SpiExternalDevice */
        Spi_JobConfig,                                  /* SpiJob */
        Spi_SeqConfig,                                  /* SpiSequence */
        (Spi_70_HW_HwUnitConfType *)Spi_HwUnitConfig,   /* SpiHwUnitConf */
        (Spi_70_HW_CsConfType *)Spi_CsConf,             /* Spi_70_CsConf */
        Spi_ChIBLink                                    /* Spi_70_ChIBLink */
    }
};

#define SPI_STOP_SEC_CONFIG_DATA_16
#include "Spi_MemMap.h"

/************************ End Of File Spi_PBcfg.c ****************************/