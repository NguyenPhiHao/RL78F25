/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Dio.h                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    : DIO Module header                                            */
/*               The DIO is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of DIO Module header                                         */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef DIO_H_
#define DIO_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Dio_70_Types.h"
#include "Port.h"               /* Port driver header              */
#include "Dio_Cfg.h"            /* DIO configuration header        */

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define DIO_VENDOR_ID                   ( 70U )
#define DIO_MODULE_ID                   ( 120U )

#define DIO_AR_RELEASE_MAJOR_VERSION    ( 22U )
#define DIO_AR_RELEASE_MINOR_VERSION    ( 11U )
#define DIO_AR_RELEASE_REVISION_VERSION ( 0U )

#define DIO_SW_MAJOR_VERSION            ( 1U )
#define DIO_SW_MINOR_VERSION            ( 0U )
#define DIO_SW_PATCH_VERSION            ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Dio_70_Types.h version check start */

#if ( DIO_VENDOR_ID != DIO_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Dio.h and Dio_70_Types.h are different"
#endif

#if ( DIO_MODULE_ID != DIO_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Dio.h and Dio_70_Types.h are different"
#endif

#if ( ( DIO_AR_RELEASE_MAJOR_VERSION    != DIO_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    )  ||  \
      ( DIO_AR_RELEASE_MINOR_VERSION    != DIO_70_AR_RELEASE_MINOR_VERSION_TYPES_H    )  ||  \
      ( DIO_AR_RELEASE_REVISION_VERSION != DIO_70_AR_RELEASE_REVISION_VERSION_TYPES_H )      \
    )
    #error "AUTOSAR Version Numbers of Dio.h and Dio_70_Types.h are different"
#endif
 
#if ( ( DIO_SW_MAJOR_VERSION != DIO_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( DIO_SW_MINOR_VERSION != DIO_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( DIO_SW_PATCH_VERSION != DIO_70_SW_PATCH_VERSION_TYPES_H )    \
    )
    #error "Software Version Numbers of Dio.h and Dio_70_Types.h are different"
#endif
 
/* Dio_70_Types.h version check end */
 
/* Dio_Cfg.h version check start */
 
#if ( DIO_VENDOR_ID != DIO_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Dio.h and Dio_Cfg.h are different"
#endif
 
#if ( DIO_MODULE_ID != DIO_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Dio.h and Dio_Cfg.h are different"
#endif
 
#if ( ( DIO_AR_RELEASE_MAJOR_VERSION    != DIO_70_AR_RELEASE_MAJOR_VERSION_CFG_H    )  ||  \
      ( DIO_AR_RELEASE_MINOR_VERSION    != DIO_70_AR_RELEASE_MINOR_VERSION_CFG_H    )  ||  \
      ( DIO_AR_RELEASE_REVISION_VERSION != DIO_70_AR_RELEASE_REVISION_VERSION_CFG_H )      \
    )
    #error "AUTOSAR Version Numbers of Dio.h and Dio_Cfg.h are different"
#endif
 
#if ( ( DIO_SW_MAJOR_VERSION != DIO_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( DIO_SW_MINOR_VERSION != DIO_70_SW_MINOR_VERSION_CFG_H ) || \
      ( DIO_SW_PATCH_VERSION != DIO_70_SW_PATCH_VERSION_CFG_H )    \
    )
    #error "Software Version Numbers of Dio.h and Dio_Cfg.h are different"
#endif
 
/* Dio_Cfg.h version check end */
 
/* Port.h version check start */
#if ( ( DIO_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION ) || \
      ( DIO_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION )    \
    )
    #error "AUTOSAR Version Numbers of Dio.h and Port.h are different"
#endif
 
/* Port.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
#define DIO_INSTANCE_ID                 ( 0U )
 
#define DIO_70_PIN_TO_PORT( x )         ( (x) >> 3U    )
#define DIO_70_PIN_TO_BITPOS( x )       ( (x) &  0x07U )
 
/* --- DIO Service ID---- --------------------------------------------------- */
#define DIO_READCHANNEL_ID              ( 0x00U )
#define DIO_WRITECHANNEL_ID             ( 0x01U )
#define DIO_READPORT_ID                 ( 0x02U )
#define DIO_WRITEPORT_ID                ( 0x03U )
#define DIO_READCHANNELGROUP_ID         ( 0x04U )
#define DIO_WRITECHANNELGROUP_ID        ( 0x05U )
#define DIO_GET_VERSION_INFO_ID         ( 0x12U )
#define DIO_FLIPCHANNEL_ID              ( 0x11U )
#define DIO_MASKEDWRITEPORT_ID          ( 0x13U )
 
/* --- DET Error code defineE ------------------------------------------------ */
#define DIO_E_PARAM_INVALID_CHANNEL_ID  ( 0x0AU )
#define DIO_E_PARAM_CONFIG              ( 0x10U )
#define DIO_E_PARAM_INVALID_PORT_ID     ( 0x14U )
#define DIO_E_PARAM_INVALID_GROUP       ( 0x1FU )
#define DIO_E_PARAM_POINTER             ( 0x20U )
 
/* definition of the port */ /* [ECUC_Dio_00144] */ /* [ECUC_Dio_00145] */
#define DIO_70_PORT_P00              ( PORT_70_00 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P01              ( PORT_70_01 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P03              ( PORT_70_03 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P04              ( PORT_70_04 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P05              ( PORT_70_05 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P06              ( PORT_70_06 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P07              ( PORT_70_07 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P08              ( PORT_70_08 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P09              ( PORT_70_09 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P10              ( PORT_70_10 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P12              ( PORT_70_12 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P13              ( PORT_70_13 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P14              ( PORT_70_14 )        /* sample definition of a DIO port */
#define DIO_70_PORT_P15              ( PORT_70_15 )        /* sample definition of a DIO port */
 
/* definition of the channel */ /* [ECUC_Dio_00146] */ /* [ECUC_Dio_00147]  */
#define DIO_70_CHANNEL_P00  ( uint8 )( PORT_70_P00 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P01  ( uint8 )( PORT_70_P01 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P02  ( uint8 )( PORT_70_P02 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P03  ( uint8 )( PORT_70_P03 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P04  ( uint8 )( PORT_70_P04 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P05  ( uint8 )( PORT_70_P05 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P06  ( uint8 )( PORT_70_P06 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P07  ( uint8 )( PORT_70_P07 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P10  ( uint8 )( PORT_70_P10 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P11  ( uint8 )( PORT_70_P11 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P12  ( uint8 )( PORT_70_P12 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P13  ( uint8 )( PORT_70_P13 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P14  ( uint8 )( PORT_70_P14 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P15  ( uint8 )( PORT_70_P15 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P16  ( uint8 )( PORT_70_P16 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P17  ( uint8 )( PORT_70_P17 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P20  ( uint8 )( PORT_70_P20 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P21  ( uint8 )( PORT_70_P21 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P22  ( uint8 )( PORT_70_P22 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P23  ( uint8 )( PORT_70_P23 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P24  ( uint8 )( PORT_70_P24 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P25  ( uint8 )( PORT_70_P25 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P26  ( uint8 )( PORT_70_P26 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P27  ( uint8 )( PORT_70_P27 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P30  ( uint8 )( PORT_70_P30 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P31  ( uint8 )( PORT_70_P31 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P32  ( uint8 )( PORT_70_P32 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P33  ( uint8 )( PORT_70_P33 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P34  ( uint8 )( PORT_70_P34 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P35  ( uint8 )( PORT_70_P35 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P36  ( uint8 )( PORT_70_P36 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P37  ( uint8 )( PORT_70_P37 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P40  ( uint8 )( PORT_70_P40 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P41  ( uint8 )( PORT_70_P41 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P42  ( uint8 )( PORT_70_P42 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P43  ( uint8 )( PORT_70_P43 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P44  ( uint8 )( PORT_70_P44 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P45  ( uint8 )( PORT_70_P45 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P46  ( uint8 )( PORT_70_P46 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P47  ( uint8 )( PORT_70_P47 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P50  ( uint8 )( PORT_70_P50 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P51  ( uint8 )( PORT_70_P51 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P52  ( uint8 )( PORT_70_P52 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P53  ( uint8 )( PORT_70_P53 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P54  ( uint8 )( PORT_70_P54 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P55  ( uint8 )( PORT_70_P55 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P56  ( uint8 )( PORT_70_P56 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P57  ( uint8 )( PORT_70_P57 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P60  ( uint8 )( PORT_70_P60 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P61  ( uint8 )( PORT_70_P61 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P62  ( uint8 )( PORT_70_P62 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P63  ( uint8 )( PORT_70_P63 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P64  ( uint8 )( PORT_70_P64 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P65  ( uint8 )( PORT_70_P65 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P66  ( uint8 )( PORT_70_P66 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P67  ( uint8 )( PORT_70_P67 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P70  ( uint8 )( PORT_70_P70 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P71  ( uint8 )( PORT_70_P71 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P72  ( uint8 )( PORT_70_P72 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P73  ( uint8 )( PORT_70_P73 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P74  ( uint8 )( PORT_70_P74 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P75  ( uint8 )( PORT_70_P75 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P76  ( uint8 )( PORT_70_P76 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P77  ( uint8 )( PORT_70_P77 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P80  ( uint8 )( PORT_70_P80 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P81  ( uint8 )( PORT_70_P81 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P82  ( uint8 )( PORT_70_P82 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P83  ( uint8 )( PORT_70_P83 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P84  ( uint8 )( PORT_70_P84 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P85  ( uint8 )( PORT_70_P85 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P86  ( uint8 )( PORT_70_P86 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P87  ( uint8 )( PORT_70_P87 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P90  ( uint8 )( PORT_70_P90 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P91  ( uint8 )( PORT_70_P91 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P92  ( uint8 )( PORT_70_P92 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P93  ( uint8 )( PORT_70_P93 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P94  ( uint8 )( PORT_70_P94 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P95  ( uint8 )( PORT_70_P95 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P96  ( uint8 )( PORT_70_P96 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P97  ( uint8 )( PORT_70_P97 )       /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P100 ( uint8 )( PORT_70_P100 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P101 ( uint8 )( PORT_70_P101 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P102 ( uint8 )( PORT_70_P102 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P103 ( uint8 )( PORT_70_P103 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P104 ( uint8 )( PORT_70_P104 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P105 ( uint8 )( PORT_70_P105 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P106 ( uint8 )( PORT_70_P106 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P107 ( uint8 )( PORT_70_P107 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P110 ( uint8 )( PORT_70_P110 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P111 ( uint8 )( PORT_70_P111 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P112 ( uint8 )( PORT_70_P112 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P113 ( uint8 )( PORT_70_P113 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P114 ( uint8 )( PORT_70_P114 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P115 ( uint8 )( PORT_70_P115 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P116 ( uint8 )( PORT_70_P116 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P117 ( uint8 )( PORT_70_P117 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P120 ( uint8 )( PORT_70_P120 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P121 ( uint8 )( PORT_70_P121 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P122 ( uint8 )( PORT_70_P122 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P123 ( uint8 )( PORT_70_P123 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P124 ( uint8 )( PORT_70_P124 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P125 ( uint8 )( PORT_70_P125 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P126 ( uint8 )( PORT_70_P126 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P127 ( uint8 )( PORT_70_P127 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P130 ( uint8 )( PORT_70_P130 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P131 ( uint8 )( PORT_70_P131 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P132 ( uint8 )( PORT_70_P132 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P133 ( uint8 )( PORT_70_P133 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P134 ( uint8 )( PORT_70_P134 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P135 ( uint8 )( PORT_70_P135 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P136 ( uint8 )( PORT_70_P136 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P137 ( uint8 )( PORT_70_P137 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P140 ( uint8 )( PORT_70_P140 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P141 ( uint8 )( PORT_70_P141 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P142 ( uint8 )( PORT_70_P142 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P143 ( uint8 )( PORT_70_P143 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P144 ( uint8 )( PORT_70_P144 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P145 ( uint8 )( PORT_70_P145 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P146 ( uint8 )( PORT_70_P146 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P147 ( uint8 )( PORT_70_P147 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P150 ( uint8 )( PORT_70_P150 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P151 ( uint8 )( PORT_70_P151 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P152 ( uint8 )( PORT_70_P152 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P153 ( uint8 )( PORT_70_P153 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P154 ( uint8 )( PORT_70_P154 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P155 ( uint8 )( PORT_70_P155 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P156 ( uint8 )( PORT_70_P156 )      /* sample definition of a DIO channel */
#define DIO_70_CHANNEL_P157 ( uint8 )( PORT_70_P157 )      /* sample definition of a DIO channel */
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
 
typedef struct
{
    uint16                      DioChannelGroupIdentification;
    Dio_70_PortMaskType         DioPortMask;    /* [SWS_Dio_00184] positions of the channel group */
    uint8                       DioPortOffset;
} Dio_ChannelGroupType;                         /* [SWS_Dio_00184] */
 
typedef struct
{
    Dio_ChannelType         DioChannelId;
} Dio_ChannelConfigurationType;
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
#ifndef DIO_CFG_C_
#if ( 0U != DIO_70_NUM_OF_DIOCHANNELGROUP )
extern const Dio_ChannelGroupType  DioChannelGroupData[ DIO_70_NUM_OF_DIOCHANNELGROUP ];
#endif
#endif  /* #ifndef __DIO_CFG_C__ */
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
 
/* [SWS_Dio_00133] */
extern  Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );
 
/* [SWS_Dio_00134] */
extern  void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );
 
/* [SWS_Dio_00135] */
extern  Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );
 
/* [SWS_Dio_00136] */
extern  void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );
 
/* [SWS_Dio_00137] */
extern  Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr );
 
/* [SWS_Dio_00138] */
extern  void Dio_WriteChannelGroup( const Dio_ChannelGroupType *ChannelGroupIdPtr,
                                    Dio_PortLevelType Level );
 
#if ( DIO_VERSION_INFO_API != STD_OFF)
extern  void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo );           /* [SWS_Dio_00139] */
#endif /* #if ( DIO_VERSION_INFO_API != STD_OFF ) */
 
#if ( DIO_FLIPCHANNEL_API != FALSE )
extern  Dio_LevelType Dio_FlipChannel( const Dio_ChannelType ChannelId );      /* [SWS_Dio_00190] */
#endif /* #if ( DIO_FLIPCHANNEL_API != FALSE ) */
 
#if ( DIO_MASKED_WRITE_PORT_API != FALSE )
extern void Dio_MaskedWritePort( Dio_PortType PortId, Dio_PortLevelType Level,
                                 Dio_PortLevelType Mask );        /* [SWS_Dio_00300] */
#endif /* #if ( DIO_MASKED_WRITE_PORT_API != FALSE ) */
 
#endif /* #ifndef DIO_H_ */
 
/* EOF Dio.h ******************************************************************/