/********************************************************************
  File Information:
    FileName:       app_cfg_audio_mcu.h
    Processor:      8051
    Hardware:
    Complier:       Keil C51
    Company:        Microchip Technology, Inc.

    Software License Agreement:

    The software supplied herewith by Microchip Technology Incorporated
    (the "Company") for 8051 Microcontroller is intended and supplied
    to you, the Company's customer, for use solely and exclusively on
    Microchip 8051 Microcontroller products. The software is owned by
    the Company and/or its supplier, and is protected under applicable
    copyright laws. All rights are reserved. Any use in violation of
    the foregoing restrictions may subject the user to criminal
    sanctions under applicable laws, as well as to civil liability for
    the breach of the terms and conditions of this license.

    THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
    WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
    TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
    IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
    CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

********************************************************************/

#ifndef APP_CFG_AUDIO_MCU_H
#define APP_CFG_AUDIO_MCU_H
/** \cond NON_DOC 

\#BUILD_TARGET : MSPKv2_App_Basic
\#BUILD_TARGET : MSPKv2_GFP
\#BUILD_TARGET : MSPKv2_SPP
\#BUILD_TARGET : MSPKv2_PBAP
\#BUILD_TARGET : AT_App
\#TARGET_START
\#REMOVE_BIT : ENABLE_LDAC_DECODE
\#REMOVE_PARAM : AUD_MCU_CFG_KEY_RESERVED1
\#REMOVE_PARAM : AUD_MCU_CFG_KEY_H_RX_EQ_MODE
\#REMOVE_PARAM : AUD_MCU_CFG_KEY_RESERVED2
\#REMOVE_PARAM : AUD_MCU_CFG_KEY_RESERVED3
\#REMOVE_PARAM : AUD_MCU_CFG_KEY_RESERVED4
\#REMOVE_BIT : ENABLE_LINE_IN_SILENCE_DETECTION
\#REMOVE_BIT : ENABLE_LR_SOUND_CHANNEL_SWAP
\#REMOVE_PARAM : AUD_MCU_CFG_KEY_RESERVED5
\#REMOVE_PARAM : AUD_MCU_CFG_KEY_RESERVED6
\#REMOVE_PARAM : AUD_MCU_CFG_KEY_SBC_ENCODE_FRAME_NUM
\#REMOVE_PARAM : AUD_MCU_CFG_KEY_MSPK_EXTRA_A2DP_LATENCY
\#TARGET_END
\endcond
*/

/**
  @addtogroup MODULE_AUD_MCU AUDIO_MCU Configuration
  @{
  @brief Definitions and prototypes for the AUDIO_MCU Configuration.
 */


//Config Key definiton of MODULE_AUD_MCU(0x03)
/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_AUD_MCU.
 *  */
typedef enum _AUD_MCU_CFG_Key_IdDefinition_T
{
    AUD_MCU_CFG_KEY_A2DP_LATENCY               = 0x01,  /**<\#PARAM_NAME : AUD_MCU_CFG_KEY_A2DP_LATENCY \n
                                                            \#ALIAS : A2DP Latency \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : a2dp latency, unit: ms \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x01 \n
                                                        */
                                                                
    AUD_MCU_CFG_KEY_SUPPORT_CODEC_TYPE         = 0x02,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_SUPPORT_CODEC_TYPE\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x02 \n
                                                             Bit Options:
                                                            \par
                                                        	\#BIT_PARAM : ENABLE_SBC_DECODE \n
                                                        	\#BIT_ALIAS : Enable SBC DECODE \n
                                                        	\#BIT_POS : 0 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Enable SBC DECODE.\n
                                                        	\#DESC_END
                                                        	
                                                        	\par
                                                        	\#BIT_PARAM : ENABLE_AAC_DECODE \n
                                                        	\#BIT_ALIAS : Enable AAC DECODE \n
                                                        	\#BIT_POS : 1 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Enable AAC DECODE.\n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : ENABLE_LDAC_DECODE \n
                                                        	\#BIT_ALIAS : Enable LDAC DECODE \n
                                                        	\#BIT_POS : 2 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Enable LDAC DECODE.\n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : RESERVED \n
                                                        	\#BIT_ALIAS : reserved \n
                                                        	\#BIT_POS : 3 \n
                                                        	\#BIT_SIZE : 5 \n
                                                        	\#BIT_DESC : reserved.\n
                                                        	\#DESC_END
                                                        */
                                                                
    AUD_MCU_CFG_KEY_RESERVED1          = 0x03,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_RESERVED1\n
                                                            \#ALIAS : AUD_MCU_CFG_KEY_RESERVED1\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x03 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_TX_EQ_MODE                 = 0x04,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_TX_EQ_MODE\n
                                                            \#ALIAS :  TX EQ MODE\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : default equalizer mode for audio \n
                                                                            0:EQ_MODE_OFF, \n
                                                                            1:EQ_MODE_SOFT,\n
                                                                            2:EQ_MODE_BASS,\n
                                                                            3:EQ_MODE_TREBLE,\n
                                                                            4:EQ_MODE_CLASSICAL,\n
                                                                            5:EQ_MODE_ROCK,\n
                                                                            6:EQ_MODE_JAZZ,\n
                                                                            7:EQ_MODE_POP,\n
                                                                            8:EQ_MODE_DANCE,\n
                                                                            9:EQ_MODE_RNB,\n
                                                                            10:EQ_MODE_USER.\n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x04 \n
                                                        */
                                                         
	AUD_MCU_CFG_KEY_H_RX_EQ_MODE			   = 0x05,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_H_RX_EQ_MODE\n
                                                            \#ALIAS :  H RX EQ MODE\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : not implemented \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x05 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_RESERVED2                 = 0x06,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_RESERVED2\n
                                                            \#ALIAS :  AUD_MCU_CFG_KEY_RESERVED2\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x06 \n
                                                        	\#PARAM_DESC :\n
                                                        	\#DESC_END
                                                        	
                                                        */
                                                         
    AUD_MCU_CFG_KEY_DEVICE_SPEAKER_GAIN        = 0x07,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_DEVICE_SPEAKER_GAIN\n
                                                            \#ALIAS :  DEVICE SPEAKER GAIN\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : speaker gain level for each paired device setting. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x07 \n
                                                            Bit Options:
                                                            \par
                                                        	\#BIT_PARAM : THE_GAIN_LEVEL_FOR_AUDIO.\n
                                                        	\#BIT_ALIAS : the gain level for audio.\n
                                                        	\#BIT_POS : 0 \n
                                                        	\#BIT_SIZE : 4 \n
                                                        	\#BIT_DESC : the gain level for audio.\n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : THE_GAIN_LEVEL_FOR_VOICE. \n
                                                        	\#BIT_ALIAS : the gain level for voice. \n
                                                        	\#BIT_POS : 4 \n
                                                        	\#BIT_SIZE : 4 \n
                                                        	\#BIT_DESC : the gain level for voice. \n
                                                        	\#DESC_END
                                                        */
                                                         
    AUD_MCU_CFG_KEY_LINE_IN_GAIN               = 0x08,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_LINE_IN_GAIN\n
                                                            \#ALIAS :  Initial Line In SPK Gain \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : default gain level for line in mode \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x08 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_RESERVED3                  = 0x09,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_RESERVED3\n
                                                            \#ALIAS :  AUD_MCU_CFG_KEY_RESERVED3\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x09 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_AUDIO_GAIN_TABLE           = 0x0A,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_AUDIO_GAIN_TABLE\n
                                                            \#ALIAS :  AUDIO GAIN TABLE\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Audio speaker gain \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x0A \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_DEFAULT_SPK_GAIN_LEVEL     = 0x0B,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_DEFAULT_SPK_GAIN_LEVEL\n
                                                            \#ALIAS :  SPK GAIN LEVEL\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Default audio  speaker gain. \n
                                                                           Bit0 ~ bit3: the gain level for audio \n
                                                                           Bit4 ~ bit7: the gain level for voice \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x0B \n
                                                            Bit Options:
                                                            \par
                                                        	\#BIT_PARAM : THE_GAIN_LEVEL_FOR_AUDIO. \n
                                                        	\#BIT_ALIAS : the gain level for audio \n
                                                        	\#BIT_POS : 0 \n
                                                        	\#BIT_SIZE : 4 \n
                                                        	\#BIT_DESC : the gain level for audio \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : THE_GAIN_LEVEL_FOR_VOICE. \n
                                                        	\#BIT_ALIAS : the gain level for voice \n
                                                        	\#BIT_POS : 4 \n
                                                        	\#BIT_SIZE : 4 \n
                                                        	\#BIT_DESC : the gain level for voice \n
                                                        	\#DESC_END
                                                        */
                                                         
    AUD_MCU_CFG_KEY_EQ_MASK                    = 0x0C,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_EQ_MASK\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x0C \n

                                                            \par
                                                        	\#BIT_PARAM : EQ_MODE_OFF \n
                                                        	\#BIT_ALIAS : Off\n
                                                        	\#BIT_POS : 0 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Off mode. 0: disabled, 1: enabled \n
                                                        	\#DESC_END

                                                            \par
                                                        	\#BIT_PARAM : EQ_MODE_SOFT \n
                                                        	\#BIT_ALIAS : Soft\n
                                                        	\#BIT_POS : 1 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Soft mode. 0: disabled, 1: enabled \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : EQ_MODE_BASS  \n
                                                        	\#BIT_ALIAS : Bass \n
                                                        	\#BIT_POS : 2 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Bass mode. 0: disabled, 1: enabled \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : EQ_MODE_TREBLE \n
                                                        	\#BIT_ALIAS : Treble \n
                                                        	\#BIT_POS : 3 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Treble mode. 0: disabled, 1: enabled \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : EQ_MODE_CLASSICAL \n
                                                        	\#BIT_ALIAS : Classic \n
                                                        	\#BIT_POS : 4 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Classical mode. 0: disabled, 1: enabled \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : EQ_MODE_ROCK \n
                                                        	\#BIT_ALIAS : Rock \n
                                                        	\#BIT_POS : 5 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Rock mode. 0: disabled, 1: enabled \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : EQ_MODE_JAZZ \n
                                                        	\#BIT_ALIAS : Jazz \n
                                                        	\#BIT_POS : 6 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Jazz mode. 0: disabled, 1: enabled \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : EQ_MODE_POP \n
                                                        	\#BIT_ALIAS : Pop mode \n
                                                        	\#BIT_POS : 7 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Pop mode. 0: disabled, 1: enabled \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : EQ_MODE_DANCE \n
                                                        	\#BIT_ALIAS : Dance \n
                                                        	\#BIT_POS : 8 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Dance mode. 0: disabled, 1: enabled \n
                                                        	\#DESC_END

                                                            \par
                                                        	\#BIT_PARAM : EQ_MODE_RNB \n
                                                        	\#BIT_ALIAS : RnB \n
                                                        	\#BIT_POS : 9 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : R&B mode. 0: disabled, 1: enabled \n
                                                        	\#DESC_END

                                                            \par
                                                        	\#BIT_PARAM : EQ_MODE_USER \n
                                                        	\#BIT_ALIAS : Custom \n
                                                        	\#BIT_POS : 10 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Customized EQ by users. 0: disabled, 1: enabled \n
                                                        	\#DESC_END
                                                        */
                                                         
    AUD_MCU_CFG_KEY_RESERVED4                  = 0x0D,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_RESERVED4\n
                                                            \#ALIAS :  AUD_MCU_CFG_KEY_RESERVED4\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x0D \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_VOICE_GAIN_TABLE           = 0x0E,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_VOICE_GAIN_TABLE\n
                                                            \#ALIAS :  VOICE GAIN TABLE\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : voice speaker gain \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x0E \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_AUDIO_RPU_STATUS           = 0x0F,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_AUDIO_RPU_STATUS\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x0F \n
                                                            \par
                                                            \#BIT_PARAM : ENABLE_AUDIO_TX_EQ \n
                                                            \#BIT_ALIAS : Equalizer Function Enable\n
                                                            \#BIT_POS : 5 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Audio TX equalizer. 0: disabled, 1: enabled \n
                                                                         Audio equalizer does not support LDAC codec even this function is enabled. \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_AUDIO_RX_EQ  \n
                                                            \#BIT_ALIAS : RX Equalizer Function Enable \n
                                                            \#BIT_POS : 6 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Audio TX equalizer. 0: disabled, 1: enabled (not implement) \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_SOUND_EFFECT \n
                                                            \#BIT_ALIAS : Sound Effect \n
                                                            \#BIT_POS : 7 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Aduio effect. 0: disabled, 1: enabled \n
                                                                         Audio effect does not support LDAC codec even this function is enabled. \n
                                                            \#DESC_END
                                                        */
                                                         
    AUD_MCU_CFG_KEY_AEC_MODE                   = 0x10,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_AEC_MODE\n
                                                            \#ALIAS :  AEC MODE\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Modified on enabling/disabling AEC. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x10 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_MSBC_RPU_STATUS            = 0x11,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_MSBC_RPU_STATUS\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x11 \n

                                                            \par
                                                            \#BIT_PARAM : ENABLE_MSBC_AEC \n
                                                            \#BIT_ALIAS : AEC Mode\n
                                                            \#BIT_POS : 0 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Voice AEC funciton. 0: disabled, 1: enabled \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_MSBC_RX_NR  \n
                                                            \#BIT_ALIAS : NR Function Enable \n
                                                            \#BIT_POS : 1 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Voice NR function. 0: disabled, 1: enabled \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_MSBC_TX_NR \n
                                                            \#BIT_ALIAS : NR Function Enable \n
                                                            \#BIT_POS : 2 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Voice NR function. 0: disabled, 1: enabled \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_MSBC_TX_EQ \n
                                                            \#BIT_ALIAS : Voice TX EQ Enable \n
                                                            \#BIT_POS : 5 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Voice TX EQ function. 0: disabled, 1: enabled \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_MSBC_RX_EQ \n
                                                            \#BIT_ALIAS : Voice RX EQ Enable \n
                                                            \#BIT_POS : 6 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Voice RX EQ function. 0: disabled, 1: enabled \n
                                                            \#DESC_END
                                                        */
                                                         
    AUD_MCU_CFG_KEY_CVSD_RX_EQ_MODE            = 0x12,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_CVSD_RX_EQ_MODE\n
                                                            \#ALIAS :  CVSD MIC EQ\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : MIC EQ index. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x12 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_CVSD_TX_EQ_MODE            = 0x13,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_CVSD_TX_EQ_MODE\n
                                                            \#ALIAS :  CVSD Speaker EQ\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Speaker EQ index. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x13 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_MSBC_RX_EQ_MODE            = 0x14,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_MSBC_RX_EQ_MODE\n
                                                            \#ALIAS :  mSBC MIC EQ \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : MIC EQ index. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x14 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_MSBC_TX_EQ_MODE            = 0x15,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_MSBC_TX_EQ_MODE\n
                                                            \#ALIAS :  mSBC Speaker EQ \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Speaker EQ index. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x15 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_AMPLIFIER_CTRL_TIME        = 0x16,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_AMPLIFIER_CTRL_TIME\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x16 \n
                                                            \par
                                                            \#BIT_PARAM : AMP_CTRL_TIME_2 \n
                                                            \#BIT_ALIAS : Amplifier Control Time 2\n
                                                            \#BIT_POS : 0 \n
                                                            \#BIT_SIZE : 3 \n
                                                            \#BIT_DESC : When AMP_CTRL_T1 expired, then wait at least this time to start play audio, if this value is 0, then wait at least 100ms.\n
                                                                         unit in 100ms \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : AMP_CTRL_TIME_1  \n
                                                            \#BIT_ALIAS : Amplifier Control Time 1 \n
                                                            \#BIT_POS : 3 \n
                                                            \#BIT_SIZE : 3 \n
                                                            \#BIT_DESC : When config codec ACTIVE, wait this time to turn on amplifier, if this value is 0, then wait 100ms.\n
                                                                         unit in 100ms \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : AMP_CTRL_TIME_0 \n
                                                            \#BIT_ALIAS : Amplifier Control Time 0 \n
                                                            \#BIT_POS : 6 \n
                                                            \#BIT_SIZE : 2 \n
                                                            \#BIT_DESC : When codec mute, set this timer to turn off amplifier, if this value set to 0, then turn off amplifier directly.\n
                                                                         unit in 1s \n
                                                            \#DESC_END

                                                        */
                                                         
    AUD_MCU_CFG_KEY_VOICE_RPU_STATUS           = 0x17,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_VOICE_RPU_STATUS\n
                                                            \#ALIAS :  VOICE RPU STATUS\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x17 \n

                                                            \par
                                                            \#BIT_PARAM : ENABLE_CVSD_AEC \n
                                                            \#BIT_ALIAS : AEC Mode\n
                                                            \#BIT_POS : 0 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Voice AEC funciton. 0: disabled, 1: enabled \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_CVSD_RX_NR  \n
                                                            \#BIT_ALIAS : NR Function Enable \n
                                                            \#BIT_POS : 1 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Voice NR function. 0: disabled, 1: enabled \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_CVSD_TX_NR \n
                                                            \#BIT_ALIAS : NR Function Enable \n
                                                            \#BIT_POS : 2 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Voice NR function. 0: disabled, 1: enabled \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_CVSD_TX_EQ \n
                                                            \#BIT_ALIAS : Voice TX EQ Enable \n
                                                            \#BIT_POS : 5 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Voice TX EQ function. 0: disabled, 1: enabled \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_CVSD_RX_EQ \n
                                                            \#BIT_ALIAS : Voice RX EQ Enable \n
                                                            \#BIT_POS : 6 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Voice RX EQ function. 0: disabled, 1: enabled \n
                                                            \#DESC_END
                                                        */
                                                         
    AUD_MCU_CFG_KEY_RESERVED7                   = 0x18,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_RESERVED7\n
                                                            \#ALIAS :  reserved\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC :  reserved
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x18 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_OPTION1                    = 0x19,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_OPTION1\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x19 \n
                                                            Bit Options:
                                                            \par
                                                        	\#BIT_PARAM : reserved \n
                                                        	\#BIT_ALIAS : reserved \n
                                                        	\#BIT_POS : 0 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : reserved \n
                                                        	\#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_LINE_IN_SILENCE_DETECTION  \n
                                                            \#BIT_ALIAS :  Line In Silence Detect \n
                                                            \#BIT_POS : 1 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Detect silence status for Aux-in signal if this option is enabled. \n
                                                                         The duration to determine the Aux-in is silence is about 33 seconds. \n
                                                                         0: disabled \n
                                                                         1: enabled \n
                                                            \#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : reserved \n
                                                        	\#BIT_ALIAS : reserved \n
                                                        	\#BIT_POS : 2 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : reserved \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : ENABLE_LINE_IN_SUPPRESS_SBC \n
                                                        	\#BIT_ALIAS : Line In / SBC Priority \n
                                                        	\#BIT_POS : 3 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Enable this option to set the priority of Aux-in is higher than A2DP. \n
                                                        	             When Aux-in and A2DP streaming coexist, \n
                                                                         the speaker will output the audio with higher priority. \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : LINE_IN_MUTE_UNMUTE_CONTROL_ENABLE \n
                                                        	\#BIT_ALIAS : Line In Mute/Unmute \n
                                                        	\#BIT_POS : 4 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : set this bit to 1 to mute/unmute the music from line-in when the priority of line-in is higher than A2DP or it has no A2DP link. \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : reserved \n
                                                        	\#BIT_ALIAS : reserved \n
                                                        	\#BIT_POS : 5 \n
                                                        	\#BIT_SIZE : 2 \n
                                                        	\#BIT_DESC : reserved \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : DSP_CODEC_ALWAYS_ON_ENABLE \n
                                                        	\#BIT_ALIAS : DSP CODEC Always On Enable \n
                                                        	\#BIT_POS : 7 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : If this option is enabled (set to 1), it will never ask codec and DSP power down. \n
                                                        	\#DESC_END
                                                        */
     
    AUD_MCU_CFG_KEY_OPTION2                    = 0x1A,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_OPTION2\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x1A \n
                                                             Bit Options:
                                                            \par
                                                        	\#BIT_PARAM : ENABLE_CONCERT_MODE_RESYNC \n
                                                        	\#BIT_ALIAS : Concert Mode Resync \n
                                                        	\#BIT_POS : 0 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Enable audio resync function in Concert Mode. \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : ENABLE_LR_SOUND_CHANNEL_SWAP \n
                                                        	\#BIT_ALIAS : Enable LR Sound Channel Swap \n
                                                        	\#BIT_POS : 1 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Swap left and right audio channel (only for A2DP) if this option is enabled (set to 1). \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : reserved \n
                                                        	\#BIT_ALIAS : reserved \n
                                                        	\#BIT_POS : 2 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : reserved \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : ENABLE_CODEC_MUTE_TURN_OFF_AMP \n
                                                        	\#BIT_ALIAS : Cut Off Amplifier When Mute \n
                                                        	\#BIT_POS : 3 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : When the speaker stop outputing sound, the codec state will change from ACTIVE state to MUTE state and then wait about 10 seconds to enter RESET state. \n
                                                                         It will cut off amplifier when codec enters MUTE state if this option is enabled (set to 1). \n
                                                                         Otherwise, the speaker cuts off amplifier when CODEC is changing to RESET state. \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : reserved \n
                                                        	\#BIT_ALIAS : reserved \n
                                                        	\#BIT_POS : 4 \n
                                                        	\#BIT_SIZE : 2 \n
                                                        	\#BIT_DESC : reserved \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : SCO_SUSPEND_STREAM_ENABLE \n
                                                        	\#BIT_ALIAS : Suspend Stream When SCO Estabblished \n
                                                        	\#BIT_POS : 6 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : The option is used in multiple link. When the speaker has a SCO link with one phone, \n
                                                                         it will send AVDTP_SUSPEND to the other phone that is playing music. 1: enabled, 0: disabled. \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : reserved \n
                                                        	\#BIT_ALIAS : reserved \n
                                                        	\#BIT_POS : 7 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : reserved. \n
                                                        	\#DESC_END
                                                        */

    AUD_MCU_CFG_KEY_OPTION3                    = 0x1B,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_OPTION3\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x1B \n
                                                            Bit Options:
                                                            \par
                                                            \#BIT_PARAM : AUDIO_SRC_ENABLE  \n
                                                            \#BIT_ALIAS : Audio SRC \n
                                                            \#BIT_POS : 0 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : 44.1K to 48K for A2DP audio \n
                                                            \#DESC_END
                                                            \par
                                                            \#BIT_PARAM : VOICE_SRC_ENABLE \n
                                                            \#BIT_ALIAS : Voice SRC \n
                                                            \#BIT_POS : 1 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : 8K/16K to 48K for ring tone or SCO voice \n
                                                            \#DESC_END
                                                            \par
                                                            \#BIT_PARAM : VOICE_STEREO_ENABLE \n
                                                            \#BIT_ALIAS : Voice Stereo \n
                                                            \#BIT_POS : 2 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Enable the function that voice outputs both of L and R channel. \n
                                                            \#DESC_END
                                                            \par
                                                            \#BIT_PARAM : TONE_STEREO_ENABLE \n
                                                            \#BIT_ALIAS : Tone Stereo \n
                                                            \#BIT_POS : 3 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Enable the function that single tone and VP output both of L and R channel. \n
                                                            \#DESC_END
                                                            \par
                                                            \#BIT_PARAM : Reserved \n
                                                            \#BIT_ALIAS : Reserved \n
                                                            \#BIT_POS : 4 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Reserved. \n
                                                            \#DESC_END
                                                            \par
                                                            \#BIT_PARAM : CODEC_OUTPUT_TYPE \n
                                                            \#BIT_ALIAS : CODEC Type \n
                                                            \#BIT_POS : 5 \n
                                                            \#BIT_SIZE : 2 \n
                                                            \#BIT_DESC :0: external codec with I2S0 output. \n
                                                                        1: external codec with I2S1 output. \n
                                                                        2: internal codec. \n
                                                            \#DESC_END
                                                            \par
                                                            \#BIT_PARAM : Reserved \n
                                                            \#BIT_ALIAS : reserved \n
                                                            \#BIT_POS : 7 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Reserved \n
                                                            \#DESC_END
                                                        */
                                                         
    AUD_MCU_CFG_KEY_AUDIO_OUTPUT_CHANNEL_STYLE = 0x1C,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_AUDIO_OUTPUT_CHANNEL_STYLE \n
                                                            \#ALIAS :  Enable LR Sound Mix \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : 0x00 : The speaker outputs the audio from source without process. \n
                                                                           0x01 : The speaker outputs left channel of audio source in both channels. \n
                                                                           0x02 : The speaker outputs right channel of audio source in both channels. \n
                                                                           0x03 : The speaker output the mixed audio of left and right channel. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x1C \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_RESERVED5        = 0x1D,            /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_RESERVED5 \n
                                                            \#ALIAS :  CODEC MONO DAC PATH \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : reference to DSP document \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x1D \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_CODEC_ADC_PATH             = 0x1E,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_CODEC_ADC_PATH \n
                                                            \#ALIAS :  ADC Path \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : reference to DSP document \n
                                                                           Bit 0~3:dolphin DAC output selection \n
                                                                           0:none(ADC off) \n
                                                                           1:Reserved \n
                                                                           2:Reserved \n
                                                                           3:Single channel(MIC2 to L). \n
                                                                           4:Dual channel(MIC2 to L, MIC1 to R). \n
                                                                           5:Single channel(MIC1 to L). \n
                                                                           6:Dual channel(MIC1 to L, MIC2 to R). \n
                                                                           7:Codec Bypass: MIC1 to L channel MIC2 to R channel. \n
                                                                           8:Codec Bypass: MIC2 to L channel MIC1 to R channel.  \n
                                                                           Bit 4:ADC off. \n
                                                                           Bit 5: 0. \n
                                                                           Bit 6:switch on the Mic bias current \n
                                                                               (Set as 0 in case of digital mic; Set as 1 in case of analog mic) \n
                                                                           Bit:7: 0. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x1E \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_RESERVED6                 = 0x1F,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_RESERVED6\n
                                                            \#ALIAS :  AUD_MCU_CFG_KEY_RESERVED6\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Reserved. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x1F \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_EFFECT_MASK                = 0x20,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_EFFECT_MASK\n
                                                            \#ALIAS :  EFFECT MASK\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x20 \n
                                                            \par
                                                            \#BIT_PARAM : ALL_AUDIO_EFFECT_OFF \n
                                                            \#BIT_ALIAS : All Off\n
                                                            \#BIT_POS : 0 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : All audio effect are disabled. \n
                                                            \#DESC_END
                                                            \par
                                                            \#BIT_PARAM : ENABLE_AUDIO_EFFECT_MBDRC \n
                                                            \#BIT_ALIAS : MB-DRC \n
                                                            \#BIT_POS : 1 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Enable MB-DRC function. \n
                                                            \#DESC_END
                                                            \par
                                                            \#BIT_PARAM : ALL_AUDIO_EFFECT_ON \n
                                                            \#BIT_ALIAS : All On \n
                                                            \#BIT_POS : 2 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : All audio effect are enabled. \n
                                                            \#DESC_END
                                                            \par
                                                            \#BIT_PARAM : ENABLE_AUDIO_EFFECT_AW \n
                                                            \#BIT_ALIAS : Tone Stereo \n
                                                            \#BIT_POS : 3 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Enable AW function. \n
                                                            \#DESC_END
                                                        */
                                                         
    AUD_MCU_CFG_KEY_EFFECT                     = 0x21,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_EFFECT\n
                                                            \#ALIAS :  AUD MCU EFFECT\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Bit 0~1 : default sound effect mode  \n
                                                                           0x0: all off \n
                                                                           0x1: MBDRC on, 3D surround off  \n
                                                                           0x2: all on  \n
                                                                           0x3: MBDRC off, 3D surround \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x21 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_LINE_IN_LATENCY            = 0x22,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_LINE_IN_LATENCY\n
                                                            \#ALIAS :  Line In Latency\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Line-in latency adjustment (unit: 16 audio samples, 1/3 ms in 48K sample rate). \n
                                                                           ex: 0xF0 => 240 * 1/3 = 80 ms \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x22 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_CLOSE_CODEC_TIME           = 0x23,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_CLOSE_CODEC_TIME\n
                                                            \#ALIAS :  Close CODEC Time \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : when DSP in SBC decode state, and FW do not receive any stream data,\n
                                                                           FW will set this timer to cut off codec(unit in 640ms) \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x23 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_CODEC_PARAMETERS           = 0x24,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_CODEC_PARAMETERS\n
                                                            \#ALIAS :  CODEC PARAMETERS\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Please see the CODEC parameters definition. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x24 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_SBC_ENCODE_FRAME_NUM       = 0x25,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_SBC_ENCODE_FRAME_NUM\n
                                                            \#ALIAS :  SBC ENCODE FRAME NUM\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC :  \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x25 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_MICROPHONE_GAIN_LEVEL      = 0x26,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_MICROPHONE_GAIN_LEVEL\n
                                                            \#ALIAS :  Analog Microphone Gain Level \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Microphone gain level \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x26 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_MICROPHONE_DIGITAL_GAIN_LEVEL = 0x27,   /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_MICROPHONE_DIGITAL_GAIN_LEVEL\n
                                                            \#ALIAS :  Digital Microphone Gain Level \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Microphone digital gain level \n
                                                                           Range: 0x00 ~0x0F (16 levels); 0x00 means mute. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x27 \n
                                                            \#VALID_MAX : 0x0F \n
                                                	        \#VALID_MIN : 0x00 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_DIGITAL_MICROPHONE_SETTING   = 0x28,  /**<\#PARAM_NAME :  AUD_MCU_CFG_KEY_DIGITAL_MICROPHONE_SETTING\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC :  (The same with the 10th byte of  AUD_MCU_CFG_KEY_CODEC_PARAMETER)\n
                                                                            Controlled for digital mic enabling and configuring the modes\n
                                                                            bit 0 =  1-> digital mic enabled\n
                                                                                  =  0-> digital mic disabled\n
                                                                            bit 1:3 = 0 to 7  (Mode selection)\n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x28 \n
                                                            
                                                            \#BIT_PARAM : ENABLE_DIGITAL_MIC \n
                                                            \#BIT_ALIAS : Digital Mic   \n
                                                            \#BIT_POS : 0 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Enable/Disable digital microphone. 0:digital mic disabled, 1:digital mic enabled \n
                                                            \#DESC_END
                                                            \par
                                                            \#BIT_PARAM : DIGITAL_MIC_MODE \n
                                                            \#BIT_ALIAS : Digital Mic Mode \n
                                                            \#BIT_POS : 1 \n
                                                            \#BIT_SIZE : 3 \n
                                                            \#BIT_DESC : The same with the 10th byte of  AUD_MCU_CFG_KEY_CODEC_PARAMETER. \n
                                                                         0b000 : Mono Raising \n
                                                                         0b001 : Mono Falling \n
                                                                         0b100 : L Rising - R Falling stereo \n
                                                                         0b101 : L Falling - R Rising stereo \n
                                                            \#DESC_END
                                                            \par
                                                            \#BIT_PARAM : reserved \n
                                                            \#BIT_ALIAS : reserved \n
                                                            \#BIT_POS : 4 \n
                                                            \#BIT_SIZE : 4 \n
                                                            \#BIT_DESC : reserved. \n
                                                            \#DESC_END
                                                        */
    AUD_MCU_CFG_KEY_MSPK_EXTRA_A2DP_LATENCY     = 0x29, /**<\#PARAM_NAME : AUD_MCU_CFG_KEY_MSPK_EXTRA_A2DP_LATENCY \n
                                                            \#ALIAS : Extra MSPK A2DP Latency \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Extra MSPK a2dp latency for MSPK audio performance tuning, unit: ms \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x03 \n
                                                            \#KEY_ID : 0x29 \n
                                                        */
                                                         
    AUD_MCU_CFG_KEY_END       
}AUD_MCU_CFG_Key_IdDefinition_T;


/**@defgroup MODULE_AUD_MCU_KEY_DEFAULT_VALUE   AUD MCU Configuration Default Value
 * @brief Default value definition of the module @ref CFG_MODULE_ID_AUD_MCU.
 * @{ */


//Module AUDIO_MCU
#define AUD_MCU_CFG_KEY_A2DP_LATENCY_LEN                        0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_A2DP_LATENCY. */
#define AUD_MCU_CFG_KEY_A2DP_LATENCY_DEFAULT_VALUE              0xF0    /**< The default value of @ref AUD_MCU_CFG_KEY_A2DP_LATENCY. */

#define AUD_MCU_CFG_KEY_SUPPORT_CODEC_TYPE_LEN                  0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_SUPPORT_CODEC_TYPE. */
#define AUD_MCU_CFG_KEY_SUPPORT_CODEC_TYPE_DEFAULT_VALUE        0x03    /**< The default value of @ref AUD_MCU_CFG_KEY_SUPPORT_CODEC_TYPE. */

#define AUD_MCU_CFG_KEY_RESERVED1_LEN                           0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_RESERVED1. */
#define AUD_MCU_CFG_KEY_RESERVED1_DEFAULT_VALUE                 0x01    /**< The default value of @ref AUD_MCU_CFG_KEY_RESERVED1. */

#define AUD_MCU_CFG_KEY_TX_EQ_MODE_LEN                          0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_TX_EQ_MODE. */
#define AUD_MCU_CFG_KEY_TX_EQ_MODE_DEFAULT_VALUE                0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_TX_EQ_MODE. */

#define AUD_MCU_CFG_KEY_H_RX_EQ_MODE_LEN                        0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_H_RX_EQ_MODE. */
#define AUD_MCU_CFG_KEY_H_RX_EQ_MODE_DEFAULT_VALUE              0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_H_RX_EQ_MODE. */

#define AUD_MCU_CFG_KEY_RESERVED2_LEN                           0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_RESERVED2. */
#define AUD_MCU_CFG_KEY_RESERVED2_DEFAULT_VALUE                 0xFF    /**< The default value of @ref AUD_MCU_CFG_KEY_RESERVED2. */

#define AUD_MCU_CFG_KEY_DEVICE_SPEAKER_GAIN_LEN                 0x08    /**< The default length of @ref AUD_MCU_CFG_KEY_DEVICE_SPEAKER_GAIN. */
#define AUD_MCU_CFG_KEY_DEVICE_SPEAKER_GAIN_DEFAULT_VALUE       0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99  /**< The default value of @ref AUD_MCU_CFG_KEY_DEVICE_SPEAKER_GAIN. */

#define AUD_MCU_CFG_KEY_LINE_IN_GAIN_LEN                        0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_LINE_IN_GAIN. */
#define AUD_MCU_CFG_KEY_LINE_IN_GAIN_DEFAULT_VALUE              0x0A    /**< The default value of @ref AUD_MCU_CFG_KEY_LINE_IN_GAIN. */

#define AUD_MCU_CFG_KEY_RESERVED3_LEN                           0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_RESERVED3. */
#define AUD_MCU_CFG_KEY_RESERVED3_DEFAULT_VALUE                 0xF0    /**< The default value of @ref AUD_MCU_CFG_KEY_RESERVED3. */

#define AUD_MCU_CFG_KEY_AUDIO_GAIN_TABLE_LEN                    0x10    /**< The default length of @ref AUD_MCU_CFG_KEY_AUDIO_GAIN_TABLE. */
#define AUD_MCU_CFG_KEY_AUDIO_GAIN_TABLE_DEFAULT_VALUE          0x00, 0xA2, 0xA5, 0xC2, 0xC5, 0xE2, 0xE5, 0xE8, 0xEB, 0xEE, 0xF1, 0xF4, 0xF7, 0xFA, 0xFB, 0xFC  /**< The default value of @ref AUD_MCU_CFG_KEY_AUDIO_GAIN_TABLE. */

#define AUD_MCU_CFG_KEY_DEFAULT_SPK_GAIN_LEVEL_LEN              0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_DEFAULT_SPK_GAIN_LEVEL. */
#define AUD_MCU_CFG_KEY_DEFAULT_SPK_GAIN_LEVEL_DEFAULT_VALUE    0x99    /**< The default length of @ref AUD_MCU_CFG_KEY_DEFAULT_SPK_GAIN_LEVEL. */

#define AUD_MCU_CFG_KEY_EQ_MASK_LEN                             0x02    /**< The default length of @ref AUD_MCU_CFG_KEY_EQ_MASK. */
#define AUD_MCU_CFG_KEY_EQ_MASK_DEFAULT_VALUE                   0x07, 0xFF  /**< The default value of @ref AUD_MCU_CFG_KEY_EQ_MASK. */

#define AUD_MCU_CFG_KEY_RESERVED4_LEN                          0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_RESERVED4. */
#define AUD_MCU_CFG_KEY_RESERVED4_DEFAULT_VALUE                0x11    /**< The default value of @ref AUD_MCU_CFG_KEY_RESERVED4. */

#define AUD_MCU_CFG_KEY_VOICE_GAIN_TABLE_LEN                    0x10    /**< The default length of @ref AUD_MCU_CFG_KEY_VOICE_GAIN_TABLE. */
#define AUD_MCU_CFG_KEY_VOICE_GAIN_TABLE_DEFAULT_VALUE          0x00, 0xA2, 0xA5, 0xC2, 0xC5, 0xE2, 0xE5, 0xE8, 0xEB, 0xEE, 0xF1, 0xF4, 0xF7, 0xFA, 0xFB, 0xFC  /**< The default value of @ref AUD_MCU_CFG_KEY_VOICE_GAIN_TABLE. */

#define AUD_MCU_CFG_KEY_VOICE_RPU_STATUS_LEN                    0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_VOICE_RPU_STATUS. */
#define AUD_MCU_CFG_KEY_VOICE_RPU_STATUS_DEFAULT_VALUE          0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_VOICE_RPU_STATUS. */

#define AUD_MCU_CFG_KEY_AEC_MODE_LEN                            0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_AEC_MODE. */
#define AUD_MCU_CFG_KEY_AEC_MODE_DEFAULT_VALUE                  0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_AEC_MODE. */

#define AUD_MCU_CFG_KEY_MSBC_RPU_STATUS_LEN                     0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_MSBC_RPU_STATUS. */
#define AUD_MCU_CFG_KEY_MSBC_RPU_STATUS_DEFAULT_VALUE           0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_MSBC_RPU_STATUS. */

#define AUD_MCU_CFG_KEY_CVSD_RX_EQ_MODE_LEN                     0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_CVSD_RX_EQ_MODE. */
#define AUD_MCU_CFG_KEY_CVSD_RX_EQ_MODE_DEFAULT_VALUE           0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_CVSD_RX_EQ_MODE. */

#define AUD_MCU_CFG_KEY_CVSD_TX_EQ_MODE_LEN                     0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_CVSD_TX_EQ_MODE. */
#define AUD_MCU_CFG_KEY_CVSD_TX_EQ_MODE_DEFAULT_VALUE           0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_CVSD_TX_EQ_MODE. */

#define AUD_MCU_CFG_KEY_MSBC_RX_EQ_MODE_LEN                     0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_MSBC_RX_EQ_MODE. */
#define AUD_MCU_CFG_KEY_MSBC_RX_EQ_MODE_DEFAULT_VALUE           0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_MSBC_RX_EQ_MODE. */

#define AUD_MCU_CFG_KEY_MSBC_TX_EQ_MODE_LEN                     0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_MSBC_TX_EQ_MODE. */
#define AUD_MCU_CFG_KEY_MSBC_TX_EQ_MODE_DEFAULT_VALUE           0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_MSBC_TX_EQ_MODE. */

#define AUD_MCU_CFG_KEY_AMPLIFIER_CTRL_TIME_LEN                 0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_AMPLIFIER_CTRL_TIME. */
#define AUD_MCU_CFG_KEY_AMPLIFIER_CTRL_TIME_DEFAULT_VALUE       0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_AMPLIFIER_CTRL_TIME. */

#define AUD_MCU_CFG_KEY_AUDIO_RPU_STATUS_LEN                    0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_AUDIO_RPU_STATUS. */
#define AUD_MCU_CFG_KEY_AUDIO_RPU_STATUS_DEFAULT_VALUE          0x20    /**< The default value of @ref AUD_MCU_CFG_KEY_AUDIO_RPU_STATUS. */

#define AUD_MCU_CFG_KEY_RESERVED7_LEN                           0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_RESERVED7. */
#define AUD_MCU_CFG_KEY_RESERVED7_DEFAULT_VALUE                 0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_RESERVED7. */

#define AUD_MCU_CFG_KEY_OPTION1_LEN                             0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_OPTION1. */
#define AUD_MCU_CFG_KEY_OPTION1_DEFAULT_VALUE                   0x0E    /**< The default value of @ref AUD_MCU_CFG_KEY_OPTION1. */

#define AUD_MCU_CFG_KEY_OPTION2_LEN                             0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_OPTION2. */
#define AUD_MCU_CFG_KEY_OPTION2_DEFAULT_VALUE                   0x01    /**< The default value of @ref AUD_MCU_CFG_KEY_OPTION2. */

#define AUD_MCU_CFG_KEY_OPTION3_LEN                             0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_OPTION3. */
#define AUD_MCU_CFG_KEY_OPTION3_DEFAULT_VALUE                   0x2E    /**< The default value of @ref AUD_MCU_CFG_KEY_OPTION3. */

#define AUD_MCU_CFG_KEY_AUDIO_OUTPUT_CHANNEL_STYLE_LEN            0x01  /**< The default length of @ref AUD_MCU_CFG_KEY_AUDIO_OUTPUT_CHANNEL_STYLE. */
#define AUD_MCU_CFG_KEY_AUDIO_OUTPUT_CHANNEL_STYLE_DEFAULT_VALUE  0x01  /**< The default value of @ref AUD_MCU_CFG_KEY_AUDIO_OUTPUT_CHANNEL_STYLE. */

#define AUD_MCU_CFG_KEY_RESERVED5_LEN                           0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_RESERVED5. */
#define AUD_MCU_CFG_KEY_RESERVED5_DEFAULT_VALUE                 0x93    /**< The default value of @ref AUD_MCU_CFG_KEY_RESERVED5. */

#define AUD_MCU_CFG_KEY_CODEC_ADC_PATH_LEN                      0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_CODEC_ADC_PATH. */
#define AUD_MCU_CFG_KEY_CODEC_ADC_PATH_DEFAULT_VALUE            0x45    /**< The default value of @ref AUD_MCU_CFG_KEY_CODEC_ADC_PATH. */

#define AUD_MCU_CFG_KEY_RESERVED6_LEN                           0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_RESERVED6. */
#define AUD_MCU_CFG_KEY_RESERVED6_DEFAULT_VALUE                 0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_RESERVED6. */

#define AUD_MCU_CFG_KEY_EFFECT_MASK_LEN                         0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_EFFECT_MASK. */
#define AUD_MCU_CFG_KEY_EFFECT_MASK_DEFAULT_VALUE               0x01    /**< The default value of @ref AUD_MCU_CFG_KEY_EFFECT_MASK. */

#define AUD_MCU_CFG_KEY_EFFECT_LEN                              0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_EFFECT. */
#define AUD_MCU_CFG_KEY_EFFECT_DEFAULT_VALUE                    0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_EFFECT. */

#define AUD_MCU_CFG_KEY_LINE_IN_LATENCY_LEN                     0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_LINE_IN_LATENCY. */
#define AUD_MCU_CFG_KEY_LINE_IN_LATENCY_DEFAULT_VALUE           0xF0    /**< The default value of @ref AUD_MCU_CFG_KEY_LINE_IN_LATENCY. */

#define AUD_MCU_CFG_KEY_CLOSE_CODEC_TIME_LEN                    0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_CLOSE_CODEC_TIME. */
#define AUD_MCU_CFG_KEY_CLOSE_CODEC_TIME_DEFAULT_VALUE          0x08    /**< The default value of @ref AUD_MCU_CFG_KEY_CLOSE_CODEC_TIME. */

#define AUD_MCU_CFG_KEY_CODEC_PARAMETERS_LEN                    0x0B    /**< The default length of @ref AUD_MCU_CFG_KEY_CODEC_PARAMETERS. */
#define AUD_MCU_CFG_KEY_CODEC_PARAMETERS_DEFAULT_VALUE          0x01, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x07, 0x00, 0x01, 0x00    /**< The default value of @ref AUD_MCU_CFG_KEY_CODEC_PARAMETERS. */

#define AUD_MCU_CFG_KEY_SBC_ENCODE_FRAME_NUM_LEN                0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_SBC_ENCODE_FRAME_NUM. */
#define AUD_MCU_CFG_KEY_SBC_ENCODE_FRAME_NUM_DEFAULT_VALUE      0x05    /**< The default value of @ref AUD_MCU_CFG_KEY_SBC_ENCODE_FRAME_NUM. */

#define AUD_MCU_CFG_KEY_MICROPHONE_GAIN_LEVEL_LEN               0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_MICROPHONE_GAIN_LEVEL. */
#define AUD_MCU_CFG_KEY_MICROPHONE_GAIN_LEVEL_DEFAULT_VALUE     0x09    /**< The default value of @ref AUD_MCU_CFG_KEY_MICROPHONE_GAIN_LEVEL. */

#define AUD_MCU_CFG_KEY_MICROPHONE_DIGITAL_GAIN_LEVEL_LEN               0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_MICROPHONE_DIGITAL_GAIN_LEVEL. */
#define AUD_MCU_CFG_KEY_MICROPHONE_DIGITAL_GAIN_LEVEL_DEFAULT_VALUE     0x0C    /**< The default value of @ref AUD_MCU_CFG_KEY_MICROPHONE_DIGITAL_GAIN_LEVEL. */

#define AUD_MCU_CFG_KEY_DIGITAL_MICROPHONE_SETTING_LEN                  0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_DIGITAL_MICROPHONE_SETTING. */
#define AUD_MCU_CFG_KEY_DIGITAL_MICROPHONE_SETTING_DEFAULT_VALUE        0x01    /**< The default value of @ref AUD_MCU_CFG_KEY_DIGITAL_MICROPHONE_SETTING. */

#define AUD_MCU_CFG_KEY_MSPK_EXTRA_A2DP_LATENCY_LEN             0x01    /**< The default length of @ref AUD_MCU_CFG_KEY_MSPK_EXTRA_A2DP_LATENCY. */
#define AUD_MCU_CFG_KEY_MSPK_EXTRA_A2DP_LATENCY_DEFAULT_VALUE   0x64    /**< The default value of @ref AUD_MCU_CFG_KEY_MSPK_EXTRA_A2DP_LATENCY. */
/** @} */
/** @} */

/** \cond NON_DOC */

#define CFG_AUD_MCU_MODULE_TOTAL_NUM_KEYS   (AUD_MCU_CFG_KEY_END - 1) /**< The total key number of this module. */

#define CFG_AUD_MCU_MODULE_TOTAL_SIZE   ((CFG_AUD_MCU_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) +        \
                                        AUD_MCU_CFG_KEY_A2DP_LATENCY_LEN +                     \
                                        AUD_MCU_CFG_KEY_SUPPORT_CODEC_TYPE_LEN +               \
                                        AUD_MCU_CFG_KEY_RESERVED1_LEN +                        \
                                        AUD_MCU_CFG_KEY_TX_EQ_MODE_LEN +                       \
                                        AUD_MCU_CFG_KEY_H_RX_EQ_MODE_LEN +                     \
                                        AUD_MCU_CFG_KEY_RESERVED2_LEN +                            \
                                        AUD_MCU_CFG_KEY_DEVICE_SPEAKER_GAIN_LEN +              \
                                        AUD_MCU_CFG_KEY_LINE_IN_GAIN_LEN +                     \
                                        AUD_MCU_CFG_KEY_RESERVED3_LEN +                        \
                                        AUD_MCU_CFG_KEY_AUDIO_GAIN_TABLE_LEN +                 \
                                        AUD_MCU_CFG_KEY_DEFAULT_SPK_GAIN_LEVEL_LEN +           \
                                        AUD_MCU_CFG_KEY_EQ_MASK_LEN +                          \
                                        AUD_MCU_CFG_KEY_RESERVED4_LEN +                        \
                                        AUD_MCU_CFG_KEY_VOICE_GAIN_TABLE_LEN +                 \
                                        AUD_MCU_CFG_KEY_VOICE_RPU_STATUS_LEN +                 \
                                        AUD_MCU_CFG_KEY_AEC_MODE_LEN +                         \
                                        AUD_MCU_CFG_KEY_MSBC_RPU_STATUS_LEN +                  \
                                        AUD_MCU_CFG_KEY_CVSD_RX_EQ_MODE_LEN +                  \
                                        AUD_MCU_CFG_KEY_CVSD_TX_EQ_MODE_LEN +                  \
                                        AUD_MCU_CFG_KEY_MSBC_RX_EQ_MODE_LEN +                  \
                                        AUD_MCU_CFG_KEY_MSBC_TX_EQ_MODE_LEN +                  \
                                        AUD_MCU_CFG_KEY_AMPLIFIER_CTRL_TIME_LEN +              \
                                        AUD_MCU_CFG_KEY_AUDIO_RPU_STATUS_LEN +                       \
                                        AUD_MCU_CFG_KEY_RESERVED7_LEN +               \
                                        AUD_MCU_CFG_KEY_OPTION1_LEN +                          \
                                        AUD_MCU_CFG_KEY_OPTION2_LEN +                          \
                                        AUD_MCU_CFG_KEY_OPTION3_LEN +                          \
                                        AUD_MCU_CFG_KEY_AUDIO_OUTPUT_CHANNEL_STYLE_LEN +             \
                                        AUD_MCU_CFG_KEY_RESERVED5_LEN +              \
                                        AUD_MCU_CFG_KEY_CODEC_ADC_PATH_LEN +                   \
                                        AUD_MCU_CFG_KEY_RESERVED6_LEN +        \
                                        AUD_MCU_CFG_KEY_EFFECT_MASK_LEN +                      \
                                        AUD_MCU_CFG_KEY_EFFECT_LEN +                           \
                                        AUD_MCU_CFG_KEY_LINE_IN_LATENCY_LEN +                  \
                                        AUD_MCU_CFG_KEY_CLOSE_CODEC_TIME_LEN +                 \
                                        AUD_MCU_CFG_KEY_CODEC_PARAMETERS_LEN +                 \
                                        AUD_MCU_CFG_KEY_SBC_ENCODE_FRAME_NUM_LEN +             \
                                        AUD_MCU_CFG_KEY_MICROPHONE_GAIN_LEVEL_LEN +            \
                                        AUD_MCU_CFG_KEY_MICROPHONE_DIGITAL_GAIN_LEVEL_LEN +    \
                                        AUD_MCU_CFG_KEY_DIGITAL_MICROPHONE_SETTING_LEN +               \
                                        AUD_MCU_CFG_KEY_MSPK_EXTRA_A2DP_LATENCY_LEN)

//Audio_MCU Config keys definition
#define CFG_AUD_MCU_MODULE_DEFAULT_VALUE    CFG_MODULE_ID_AUD_MCU,               /*moduleID*/   \
                                            CFG_AUD_MCU_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/    \
                                            (CFG_AUD_MCU_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/  \
                                            CFG_AUD_MCU_MODULE_TOTAL_SIZE,                      \
                                            /*CFG_KEYs[numKeys]*/                               \
                                            /*    //ID                                                                  //Len                                                                                    //Value    */                                      \
                                            AUD_MCU_CFG_KEY_A2DP_LATENCY,               AUD_MCU_CFG_KEY_A2DP_LATENCY_LEN,                   AUD_MCU_CFG_KEY_A2DP_LATENCY_DEFAULT_VALUE,                 \
                                            AUD_MCU_CFG_KEY_SUPPORT_CODEC_TYPE,         AUD_MCU_CFG_KEY_SUPPORT_CODEC_TYPE_LEN,             AUD_MCU_CFG_KEY_SUPPORT_CODEC_TYPE_DEFAULT_VALUE,           \
                                            AUD_MCU_CFG_KEY_RESERVED1,                  AUD_MCU_CFG_KEY_RESERVED1_LEN,                      AUD_MCU_CFG_KEY_RESERVED1_DEFAULT_VALUE,                    \
                                            AUD_MCU_CFG_KEY_TX_EQ_MODE,                 AUD_MCU_CFG_KEY_TX_EQ_MODE_LEN,                     AUD_MCU_CFG_KEY_TX_EQ_MODE_DEFAULT_VALUE,                   \
                                            AUD_MCU_CFG_KEY_H_RX_EQ_MODE, 				AUD_MCU_CFG_KEY_H_RX_EQ_MODE_LEN, 					AUD_MCU_CFG_KEY_H_RX_EQ_MODE_DEFAULT_VALUE,					\
                                            AUD_MCU_CFG_KEY_RESERVED2,                  AUD_MCU_CFG_KEY_RESERVED2_LEN,                      AUD_MCU_CFG_KEY_RESERVED2_DEFAULT_VALUE,                    \
                                            AUD_MCU_CFG_KEY_DEVICE_SPEAKER_GAIN,        AUD_MCU_CFG_KEY_DEVICE_SPEAKER_GAIN_LEN,            AUD_MCU_CFG_KEY_DEVICE_SPEAKER_GAIN_DEFAULT_VALUE,          \
                                            AUD_MCU_CFG_KEY_LINE_IN_GAIN,               AUD_MCU_CFG_KEY_LINE_IN_GAIN_LEN,                   AUD_MCU_CFG_KEY_LINE_IN_GAIN_DEFAULT_VALUE,                 \
                                            AUD_MCU_CFG_KEY_RESERVED3,                  AUD_MCU_CFG_KEY_RESERVED3_LEN,                      AUD_MCU_CFG_KEY_RESERVED3_DEFAULT_VALUE,                    \
                                            AUD_MCU_CFG_KEY_AUDIO_GAIN_TABLE,           AUD_MCU_CFG_KEY_AUDIO_GAIN_TABLE_LEN,               AUD_MCU_CFG_KEY_AUDIO_GAIN_TABLE_DEFAULT_VALUE,             \
                                            AUD_MCU_CFG_KEY_DEFAULT_SPK_GAIN_LEVEL,     AUD_MCU_CFG_KEY_DEFAULT_SPK_GAIN_LEVEL_LEN,         AUD_MCU_CFG_KEY_DEFAULT_SPK_GAIN_LEVEL_DEFAULT_VALUE,       \    
                                            AUD_MCU_CFG_KEY_EQ_MASK,                    AUD_MCU_CFG_KEY_EQ_MASK_LEN,                        AUD_MCU_CFG_KEY_EQ_MASK_DEFAULT_VALUE,                      \
                                            AUD_MCU_CFG_KEY_RESERVED4,                  AUD_MCU_CFG_KEY_RESERVED4_LEN,                      AUD_MCU_CFG_KEY_RESERVED4_DEFAULT_VALUE,                    \    
                                            AUD_MCU_CFG_KEY_VOICE_GAIN_TABLE,           AUD_MCU_CFG_KEY_VOICE_GAIN_TABLE_LEN,               AUD_MCU_CFG_KEY_VOICE_GAIN_TABLE_DEFAULT_VALUE,             \
                                            AUD_MCU_CFG_KEY_VOICE_RPU_STATUS,           AUD_MCU_CFG_KEY_VOICE_RPU_STATUS_LEN,         AUD_MCU_CFG_KEY_VOICE_RPU_STATUS_DEFAULT_VALUE,             \    
                                            AUD_MCU_CFG_KEY_AEC_MODE,                   AUD_MCU_CFG_KEY_AEC_MODE_LEN,                       AUD_MCU_CFG_KEY_AEC_MODE_DEFAULT_VALUE,                     \
                                            AUD_MCU_CFG_KEY_MSBC_RPU_STATUS,            AUD_MCU_CFG_KEY_MSBC_RPU_STATUS_LEN,                AUD_MCU_CFG_KEY_MSBC_RPU_STATUS_DEFAULT_VALUE,              \
                                            AUD_MCU_CFG_KEY_CVSD_RX_EQ_MODE,            AUD_MCU_CFG_KEY_CVSD_RX_EQ_MODE_LEN,                AUD_MCU_CFG_KEY_CVSD_RX_EQ_MODE_DEFAULT_VALUE,              \
                                            AUD_MCU_CFG_KEY_CVSD_TX_EQ_MODE,            AUD_MCU_CFG_KEY_CVSD_TX_EQ_MODE_LEN,                AUD_MCU_CFG_KEY_CVSD_TX_EQ_MODE_DEFAULT_VALUE,              \
                                            AUD_MCU_CFG_KEY_MSBC_RX_EQ_MODE,            AUD_MCU_CFG_KEY_MSBC_RX_EQ_MODE_LEN,                AUD_MCU_CFG_KEY_MSBC_RX_EQ_MODE_DEFAULT_VALUE,              \
                                            AUD_MCU_CFG_KEY_MSBC_TX_EQ_MODE,            AUD_MCU_CFG_KEY_MSBC_TX_EQ_MODE_LEN,                AUD_MCU_CFG_KEY_MSBC_TX_EQ_MODE_DEFAULT_VALUE,              \
                                            AUD_MCU_CFG_KEY_AMPLIFIER_CTRL_TIME,        AUD_MCU_CFG_KEY_AMPLIFIER_CTRL_TIME_LEN,            AUD_MCU_CFG_KEY_AMPLIFIER_CTRL_TIME_DEFAULT_VALUE,          \
                                            AUD_MCU_CFG_KEY_AUDIO_RPU_STATUS,           AUD_MCU_CFG_KEY_AUDIO_RPU_STATUS_LEN,               AUD_MCU_CFG_KEY_AUDIO_RPU_STATUS_DEFAULT_VALUE,                   \    
                                            AUD_MCU_CFG_KEY_RESERVED7 ,                 AUD_MCU_CFG_KEY_RESERVED7_LEN,                      AUD_MCU_CFG_KEY_RESERVED7_DEFAULT_VALUE,           \
                                            AUD_MCU_CFG_KEY_OPTION1,                    AUD_MCU_CFG_KEY_OPTION1_LEN,                        AUD_MCU_CFG_KEY_OPTION1_DEFAULT_VALUE,                      \
                                            AUD_MCU_CFG_KEY_OPTION2,                    AUD_MCU_CFG_KEY_OPTION2_LEN,                        AUD_MCU_CFG_KEY_OPTION2_DEFAULT_VALUE,                      \
                                            AUD_MCU_CFG_KEY_OPTION3,                    AUD_MCU_CFG_KEY_OPTION3_LEN,                        AUD_MCU_CFG_KEY_OPTION3_DEFAULT_VALUE,                      \
                                            AUD_MCU_CFG_KEY_AUDIO_OUTPUT_CHANNEL_STYLE, AUD_MCU_CFG_KEY_AUDIO_OUTPUT_CHANNEL_STYLE_LEN,     AUD_MCU_CFG_KEY_AUDIO_OUTPUT_CHANNEL_STYLE_DEFAULT_VALUE,         \
                                            AUD_MCU_CFG_KEY_RESERVED5,                  AUD_MCU_CFG_KEY_RESERVED5_LEN,                      AUD_MCU_CFG_KEY_RESERVED5_DEFAULT_VALUE,          \
                                            AUD_MCU_CFG_KEY_CODEC_ADC_PATH,             AUD_MCU_CFG_KEY_CODEC_ADC_PATH_LEN,                 AUD_MCU_CFG_KEY_CODEC_ADC_PATH_DEFAULT_VALUE,               \    
                                            AUD_MCU_CFG_KEY_RESERVED6,                  AUD_MCU_CFG_KEY_RESERVED6_LEN,                      AUD_MCU_CFG_KEY_RESERVED6_DEFAULT_VALUE,    \
                                            AUD_MCU_CFG_KEY_EFFECT_MASK,                AUD_MCU_CFG_KEY_EFFECT_MASK_LEN,                    AUD_MCU_CFG_KEY_EFFECT_MASK_DEFAULT_VALUE,                  \
                                            AUD_MCU_CFG_KEY_EFFECT,                     AUD_MCU_CFG_KEY_EFFECT_LEN,                         AUD_MCU_CFG_KEY_EFFECT_DEFAULT_VALUE,                       \
                                            AUD_MCU_CFG_KEY_LINE_IN_LATENCY,            AUD_MCU_CFG_KEY_LINE_IN_LATENCY_LEN,                AUD_MCU_CFG_KEY_LINE_IN_LATENCY_DEFAULT_VALUE,              \
                                            AUD_MCU_CFG_KEY_CLOSE_CODEC_TIME,           AUD_MCU_CFG_KEY_CLOSE_CODEC_TIME_LEN,               AUD_MCU_CFG_KEY_CLOSE_CODEC_TIME_DEFAULT_VALUE,             \
                                            AUD_MCU_CFG_KEY_CODEC_PARAMETERS,           AUD_MCU_CFG_KEY_CODEC_PARAMETERS_LEN,               AUD_MCU_CFG_KEY_CODEC_PARAMETERS_DEFAULT_VALUE,             \
                                            AUD_MCU_CFG_KEY_SBC_ENCODE_FRAME_NUM,       AUD_MCU_CFG_KEY_SBC_ENCODE_FRAME_NUM_LEN,           AUD_MCU_CFG_KEY_SBC_ENCODE_FRAME_NUM_DEFAULT_VALUE,         \
                                            AUD_MCU_CFG_KEY_MICROPHONE_GAIN_LEVEL,      AUD_MCU_CFG_KEY_MICROPHONE_GAIN_LEVEL_LEN,          AUD_MCU_CFG_KEY_MICROPHONE_GAIN_LEVEL_DEFAULT_VALUE,        \
                                            AUD_MCU_CFG_KEY_MICROPHONE_DIGITAL_GAIN_LEVEL,      AUD_MCU_CFG_KEY_MICROPHONE_DIGITAL_GAIN_LEVEL_LEN,          AUD_MCU_CFG_KEY_MICROPHONE_DIGITAL_GAIN_LEVEL_DEFAULT_VALUE,   \
                                            AUD_MCU_CFG_KEY_DIGITAL_MICROPHONE_SETTING,         AUD_MCU_CFG_KEY_DIGITAL_MICROPHONE_SETTING_LEN,             AUD_MCU_CFG_KEY_DIGITAL_MICROPHONE_SETTING_DEFAULT_VALUE,    \
                                            AUD_MCU_CFG_KEY_MSPK_EXTRA_A2DP_LATENCY,    AUD_MCU_CFG_KEY_MSPK_EXTRA_A2DP_LATENCY_LEN,        AUD_MCU_CFG_KEY_MSPK_EXTRA_A2DP_LATENCY_DEFAULT_VALUE

typedef struct _APP_Cfg_AudioMcuOption3_T
{
    uint8_t enableAudioSrc : 1;
    uint8_t enableVoiceSrc : 1;
    uint8_t enableVoiceStereo : 1;
    uint8_t enableToneStereo : 1;
    uint8_t reserved2 : 1;
    uint8_t codecOutputType : 2;
    uint8_t reserved : 1;
} APP_Cfg_AudioMcuOption3_T;

typedef struct _APP_Cfg_AudioMcuOption2_T
{
    uint8_t enableConcertModeResync : 1;
    uint8_t enableA2dpChannelSwap : 1;
    uint8_t reserved0 : 1;
    uint8_t enableTurnOffAmpInCodecMute : 1;
    uint8_t reserved1 : 2;
    uint8_t enableSuspendStreamBeforeSco : 1;
    uint8_t reserved2 : 1;
} APP_Cfg_AudioMcuOption2_T;


typedef struct _APP_Cfg_AudioMcuOption1_T
{
    uint8_t reserved0 : 1;
    uint8_t enableLineInSilenceDetection : 1;
    uint8_t reserved1 : 1;
    uint8_t enableLineInSuppressA2dp : 1;
	uint8_t enableLineInMuteUnmuteByPlayPause : 1;
    uint8_t reserved2 : 2;
    uint8_t enableDspCodecAlwaysOn : 1;
} APP_Cfg_AudioMcuOption1_T;


typedef struct _APP_Cfg_AudioRpuStatus_T
{
    uint8_t reserved : 5;
    uint8_t enableAudioTxEq : 1;
    uint8_t enableAudioRxEq : 1;
    uint8_t enableAudioEffect : 1;
} APP_Cfg_AudioRpuStatus_T;

typedef struct _APP_Cfg_VoiceRpuStatus_T
{
    uint8_t enableAec : 1;
    uint8_t enableRxNr : 1;
    uint8_t enableTxNr : 1;
    uint8_t enableTxFirFilterReserved : 1;
    uint8_t enableRxFirFilterReserved : 1;
    uint8_t enableVoiceTxEq : 1;
    uint8_t enableVoiceRxEq : 1;
    uint8_t Reserved : 1;
} APP_Cfg_VoiceRpuStatus_T;

typedef struct _APP_Cfg_DigitalMicSetting_T
{
    uint8_t enableDigMic : 1;
    uint8_t mode : 3;
    uint8_t reserved : 4;
} APP_Cfg_DigitalMicSetting_T;

typedef struct _APP_Cfg_ExtAmpCtrlTime_T
{
    uint8_t aduioOutputMinDelayTime : 3;
    uint8_t turnOnAmpDelayTime : 3;
    uint8_t offAmpDelayTime : 2;              
} APP_Cfg_ExtAmpCtrlTime_T;
void APP_CFG_ReadDevSpkGain(uint8_t XDATA *p_len, uint8_t XDATA *p_devSpkGain) large;
void APP_CFG_WriteDevSpkGain(uint8_t len, uint8_t XDATA *p_devSpkGain) large;
void APP_CFG_ReadLineinGain(uint8_t XDATA *p_lineinGain) large;
void APP_CFG_WriteLineinGain(uint8_t lineinGain) large;
void APP_CFG_ReadSupportCodecType(uint8_t XDATA *p_codecType) large;
void APP_CFG_WriteSupportCodecType(uint8_t codecType) large;
void APP_CFG_ReadAudioMcuOption3(APP_Cfg_AudioMcuOption3_T XDATA *p_option) large;
void APP_CFG_ReadAudioMcuOption2(APP_Cfg_AudioMcuOption2_T XDATA *p_option) large;
void APP_CFG_ReadAudioMcuOption1(APP_Cfg_AudioMcuOption1_T XDATA *p_option) large;
void APP_CFG_ReadAudioMcuDefaultSpkGain(uint8_t XDATA *p_gain) large;
void APP_CFG_WriteAudioMcuDefaultSpkGain(uint8_t gain) large;
void APP_CFG_ReadCodecParameter(uint8_t XDATA *p_len, uint8_t XDATA *p_param) large;
void APP_CFG_ReadAudioEffectMask(uint8_t XDATA *p_audioEffectMask) large;
void APP_CFG_ReadAudioEffectIndex(uint8_t XDATA *p_audioEffectIndex) large;
void APP_CFG_WriteAudioEffectIndex(uint8_t audioEffectIndex) large;
void APP_CFG_WriteAudioTxEqMode(uint8_t audioTxEqMode) large;
void APP_CFG_ReadAudioTxEqMode(uint8_t XDATA *p_eqMode) large;
void APP_CFG_ReadVoiceTxEqMode(uint8_t XDATA *p_eqMode) large;
void APP_CFG_ReadVoiceRxEqMode(uint8_t XDATA *p_eqMode) large;
void APP_CFG_ReadMsbcTxEqMode(uint8_t XDATA *p_eqMode) large;
void APP_CFG_ReadMsbcRxEqMode(uint8_t XDATA *p_eqMode) large;
void APP_CFG_ReadAudioRpuStatus(APP_Cfg_AudioRpuStatus_T XDATA *p_rpuStatus) large;
void APP_CFG_ReadVoiceRpuStatus(APP_Cfg_VoiceRpuStatus_T XDATA *p_rpuStatus) large;
void APP_CFG_ReadMsbcRpuStatus(APP_Cfg_VoiceRpuStatus_T XDATA *p_rpuStatus) large;
void APP_CFG_ReadCloseCodecTime(uint8_t XDATA *p_closeCodecTime) large;
void APP_CFG_ReadMicGainLevel(uint8_t XDATA *p_gainLevel) large;
void APP_CFG_ReadAudioOutputChannelStyle(uint8_t XDATA *p_channelStyle) large;
void APP_CFG_ReadDigitalMicGainLevel(uint8_t XDATA *p_digMicGainLevel) large;
void APP_CFG_ReadAdcPathSetting(uint8_t XDATA *p_adcPath) large;
void APP_CFG_ReadDigitalMicSetting(APP_Cfg_DigitalMicSetting_T XDATA *p_setting) large;
void APP_CFG_ReadAudioTxEqMask(uint8_t XDATA *p_eqMask) large;
void APP_CFG_ReadA2dpLatency(uint8_t XDATA *p_a2dpLatency) large;
void APP_CFG_ReadMspkExtraA2dpLatency(uint8_t XDATA *p_a2dpLatency) large;
void APP_CFG_ReadExtAmpCtrlTime(APP_Cfg_ExtAmpCtrlTime_T XDATA *p_ampCtrlTime) large;
void APP_CFG_ReadLineInLatency(uint8_t XDATA *p_lineInLatency) large;
void APP_CFG_ReadAudioGainTable(uint8_t XDATA *p_gainTable) large;
void APP_CFG_ReadVoiceGainTable(uint8_t XDATA *p_gainTable) large;

/// \endcond

#endif	//APP_CFG_AUDIO_MCU_H

