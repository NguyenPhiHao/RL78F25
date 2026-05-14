/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Dio_Cfg.h                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : Dio configuration header                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of DIO Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define DIO_70_VENDOR_ID_CFG_H                   ( 70U )
#define DIO_70_MODULE_ID_CFG_H                   (120U )

#define DIO_70_AR_RELEASE_MAJOR_VERSION_CFG_H    ( 22U )
#define DIO_70_AR_RELEASE_MINOR_VERSION_CFG_H    ( 11U )
#define DIO_70_AR_RELEASE_REVISION_VERSION_CFG_H (  0U )

#define DIO_70_SW_MAJOR_VERSION_CFG_H            (  1U )
#define DIO_70_SW_MINOR_VERSION_CFG_H            (  0U )
#define DIO_70_SW_PATCH_VERSION_CFG_H            (  0U )

#define DIO_DEV_ERROR_DETECT                     ( TRUE ) /* [ECUC_Dio_00142] */
#define DIO_VERSION_INFO_API                     ( TRUE ) /* [ECUC_Dio_00143] */
#define DIO_FLIPCHANNEL_API                      ( TRUE ) /* [ECUC_Dio_00153] */
#define DIO_MASKED_WRITE_PORT_API                ( TRUE ) /* [ECUC_Dio_00155] */

/* configuration of DIO channel number */
#define DIO_70_NUM_OF_DIOCHANNEL  ( DIO_70_NUM_OF_DIOCHANNEL_PORT0  + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT1  + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT2  + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT3  + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT4  + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT5  + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT6  + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT7  + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT8  + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT9  + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT10 + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT11 + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT12 + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT13 + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT14 + \
                                   DIO_70_NUM_OF_DIOCHANNEL_PORT15 )

#define DIO_70_NUM_OF_DIOCHANNEL_PORT0   ( 1U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT1   ( 1U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT2   ( 1U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT3   ( 1U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT4   ( 1U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT5   ( 1U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT6   ( 1U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT7   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT8   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT9   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT10  ( 0U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT11  ( 2U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT12  ( 1U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT13  ( 0U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT14  ( 0U )
#define DIO_70_NUM_OF_DIOCHANNEL_PORT15  ( 0U )

/* configuration of DIO port number */
#define DIO_70_NUM_OF_DIOPORT            ( 14U )

/* configuration of DIO channel group number */
#define DIO_70_NUM_OF_DIOCHANNELGROUP  ( DIO_70_NUM_OF_DIOCHANNELGROUP_PORT0  + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT1  + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT2  + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT3  + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT4  + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT5  + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT6  + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT7  + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT8  + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT9  + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT10 + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT11 + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT12 + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT13 + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT14 + \
                                        DIO_70_NUM_OF_DIOCHANNELGROUP_PORT15 )

#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT0   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT1   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT2   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT3   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT4   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT5   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT6   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT7   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT8   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT9   ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT10  ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT11  ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT12  ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT13  ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT14  ( 0U )
#define DIO_70_NUM_OF_DIOCHANNELGROUP_PORT15  ( 0U )

/* configuration of DIO channels */
/* Sample Board LED1 W */
#define DioConf_DioChannel_DioChannel_SampleBoard_LED1            ( DIO_70_CHANNEL_P02 )
/* CAN Transceiver Mode */
#define DioConf_DioChannel_DioChannel_CAN0_TRANSCEIVER_MODE       ( DIO_70_CHANNEL_P54 )
#define DioConf_DioChannel_DioChannel_CAN1_TRANSCEIVER_MODE       ( DIO_70_CHANNEL_P64 )
#define DioConf_DioChannel_DioChannel_CAN0_TRANSCEIVER_MODE_ALT   DioConf_DioChannel_DioChannel_CAN0_TRANSCEIVER_MODE

/* SPI Chip select */
#define DioConf_DioChannel_DioChannel_SPI_IC1_CS                  ( DIO_70_CHANNEL_P31 )
/* LIN Transceiver Sleep Control */
#define DioConf_DioChannel_DioChannel_LIN_TRANSCEIVER_SLEEP       ( DIO_70_CHANNEL_P53 )
/* LED1 */
#define DioConf_DioChannel_DioChannel_LED1                        ( DIO_70_CHANNEL_P66 )
/* LED2 */
#define DioConf_DioChannel_DioChannel_LED2                        ( DIO_70_CHANNEL_P67 )
/* Sample Board LED3 R */
#define DioConf_DioChannel_DioChannel_SampleBoard_LED3            ( DIO_70_CHANNEL_P126 )
/* Sample Board LED2 G */
#define DioConf_DioChannel_DioChannel_SampleBoard_LED2            ( DIO_70_CHANNEL_P127 )
/* Board Specified SW */
#define DioConf_DioChannel_DioChannel_SW                          ( DIO_70_CHANNEL_P137 )

#if ( 0U != DIO_70_NUM_OF_DIOCHANNELGROUP )
/* configuration of DIO channel groups */
#define DIO_70_CHANNELGROUP_0  ( (Dio_ChannelGroupType)( (Dio_PortTypeType)&Dio_Config.DioPort[7] )->DioChannelGroup )
#define DIO_70_CHANNELGROUP_1  ( (Dio_ChannelGroupType)( (Dio_PortTypeType)&Dio_Config.DioPort[8] )->DioChannelGroup )
#endif

#endif /* DIO_CFG_H_ */
