/********************************************************************
  File Information:
    FileName:       app_cfg_dsp.h
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

#ifndef APP_CFG_DSP_H
#define APP_CFG_DSP_H

/**
  @addtogroup APP_CFG_MODULE_AUD_DSP AUD_DSP Configuration
  @{
  @brief Definitions and prototypes for the MODULE_AUD_DSP Configuration.
 */


/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_AUD_DSP.
 *  
 */

//Config Key definiton of MODULE_AUD_DSP(0x0C)
typedef enum _AUD_DSP_CFG_Key_IdDefinition_T
{
    AUD_DSP_CFG_KEY_LINEIN                      = 0x01, /**<\#PARAM_NAME : AUD_DSP_CFG_KEY_LINEIN \n
                                                            \#ALIAS : AUD DSP CFG KEY LINEIN \n
                                                            \#PARAM_TYPE : Private \n
                                                            \#PARAM_DESC : Line in silence detection threshold determines silence power threshold level for line-in signal for auto power off mechanism \n
                                                                           Gain to amplify the external signal source and playback to the speaker \n
                                                                           Byte 0:VOICE_CFG_SUB_KEY_H_LINEIN_TUNNING_SILENCE_MV_THRD \n
                                                                           BYTE1:VOICE_CFG_SUB_KEY_H_LINEIN_ENCODER_DELAY_TIME(Line in Encoder delay time(o to 40 ms) \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0C \n
                                                            \#KEY_ID : 0x01 \n
                                                	    */
                                                	          
    AUD_DSP_CFG_KEY_MBDRC                       = 0x02, /**<\#PARAM_NAME : AUD_DSP_CFG_KEY_MBDRC \n
                                                            \#ALIAS : AUD DSP CFG KEY MBDRC \n
                                                            \#PARAM_TYPE : Private \n
                                                            \#PARAM_DESC : 
                                                                           Byte 1: \n
                                                                            MBDRC compressor_thrd_spkout :CR is a compression ratio which compresses the average sound level, \n
                                                                            exceeding “Knee TH”, of the audio signal \n
                                                                            bit[0:1]: audio_mbdrc_compressor_thrd_spkout_LowBand \n
                                                                            0: -6dBov  1: -12dBov  2: -18dBov  3: -24dBov   \n
                                                                            bit[2:3]: audio_mbdrc_compressor_thrd_spkout_MiddleBand  \n
                                                                            0: -6dBov  1: -12dBov  2: -18dBov  3: -24dBov \n
                                                                            bit[4:5]: audio_mbdrc_compressor_thrd_spkout_HighBand   \n
                                                                            0: -6dBov  1: -12dBov  2: -18dBov  3: -24dBov \n
                                                                            Bit[6:7]: virtual bass enhancement cutoff frequency selections \n
                                                                            0:100Hz  1: 150Hz  2: 200Hz   3:300Hz   \n
                                                                            
                                                                           Byte 2: \n
                                                                            MBDRC compressor_slope_spkout_LowBand  : Slope = (1/ratio) - 1; \n
                                                                            bit[0:1]: audio_mbdrc_compressor_slope_spkout_LowBand (ratio) \n
                                                                            0: 2/3  1:  1/ 2 2: 1/ 3    3:  1/4     \n
                                                                            bit[2:3]: audio_mbdrc_compressor_slope_spkout_MiddleBand  \n
                                                                            0: 2/3  1:  1/ 2 2: 1/ 3    3:  1/4    \n
                                                                            bit[4:5]: audio_mbdrc_compressor_slope_spkout_HighBand    \n
                                                                            0: 2/3  1:  1/ 2 2: 1/ 3    3:  1/4  \n
                                                                            Bit [6]: Virtual bass enhacement \n
                                                                            0: disable VB,   1: enable VB \n
                                                                            Bit [7]: natural smoothing for surround effect \n
                                                                            0: disable   1: enable natural smoothings  \n
                                                                            
                                                                           Byte 3: \n
                                                                            MBDRC compressor_Gain_spkout \n
                                                                            bit[0:3]: audio_mbdrc_compressor_Gain_spkout_LowBand(value range : 0 ~ 11) \n
                                                                            bit[4:7]: audio_mbdrc_compressor_Gain_spkout_MiddleBand (value range : 0 ~ 11) \n
                                                                           
                                                                           Byte 4: \n
                                                                            MBDRC compressor_Gain_spkout      \n
                                                                            bit[0:3]: audio_mbdrc_compressor_Gain_spkout_HighBand    \n
                                                                            value range : 0 ~ 11   \n
                                                                            MBDRC release time constants \n
                                                                            bit[4:5]:  release time for low band \n
                                                                            0:50ms  1: 100ms  2: 200ms   3:700ms     \n
                                                                            bit[6:7]:  release time for middle band \n
                                                                            0:50ms  1: 100ms  2: 200ms   3:700ms     \n
                                                                         
                                                                           Byte 5: \n
                                                                            Bit[3:0]: length of all-pass IIR filter. Length = bit[3:0] * 64 \n
                                                                            Bit[7:4]:APIIR coefficients \n
                                                                            
                                                                           Byte 6: \n
                                                                            Bit[3:0]: Main gain \n
                                                                            Bit[7:4]:Reverberation gain \n
                                                                            
                                                                           Byte 7: \n
                                                                            Bit[1:0]: attack time for low band \n
                                                                            0:10ms  1: 20ms  2: 50ms   3:100ms    \n
                                                                            Bit[3:2]: attack time for middle band \n
                                                                            0:10ms  1: 20ms  2: 50ms   3:100ms  \n
                                                                            Bit[5:4]: attack time for high band \n
                                                                            0:10ms  1: 20ms  2: 50ms   3:100ms  \n
                                                                            Bit[7:6]: Release time for high band \n
                                                                            0:50ms  1: 100ms  2: 200ms   3:700ms    \n
                                                                            
                                                                           Byte 8: \n
                                                                            This parameter controls the level of bass enhancement which is enabled along with the MB-DRC function   \n
                                                                            Range : 0x00~0xFF \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0C \n
                                                            \#KEY_ID : 0x02 \n
                                                	    */
                                                	          
    AUD_DSP_CFG_KEY_H_LDAC_PARAMETER            = 0x03, /**<\#PARAM_NAME : AUD_DSP_CFG_KEY_H_LDAC_PARAMETER \n
                                                            \#ALIAS : AUD DSP CFG KEY H LDAC PARAMETER \n
                                                            \#PARAM_TYPE : Private \n
                                                            \#PARAM_DESC : 
                                                                            LDAC parameters \n
                                                                            Byte 0:Reserved. \n
                                                                            Byte 1:buffer control threshold (upper)=> Usage: Media buffer upper threshold for LDAC buffer control. \n
                                                                            If number of frames in media buffer exceeds this upper threshold, LDAC buffer control will enter SKIP state. \n
                                                                            In SKIP state, frames with low energy will be dropped. 0 ~ 255. \n
                                                                            Byte 2: buffer control threshold (lower) => Usage: Media buffer lower threshold for LDAC buffer control. \n
                                                                            If number of frames in media buffer is below this lower threshold, LDAC buffer control will enter COPY state. \n
                                                                            In COPY state, frames with low energy will be duplicated. 0 ~ 255 \n
                                                                            Byte 3: Reserved. \n
                                                                            Byte 4: Reserved. \n
                                                                            Byte 5: buffer control threshold (target)=> Usage: Media buffer target threshold for LDAC buffer control. \n
                                                                            In SKIP/COPY state, If number of frames in media buffer hit this target threshold, LDAC buffer control will return to NORMAL state. \n
                                                                            In NORMAL state, LDAC buffer control do nothing. \n
                                                                            0 ~ 255 \n
                                                                            Byte 6: Reserved. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0C \n
                                                            \#KEY_ID : 0x03 \n
                                                	    */
                                                	          
	AUD_DSP_CFG_KEY_CUSTOM_EQ_SPK_AUDIO		    = 0x04, /**<\#PARAM_NAME : AUD_DSP_CFG_KEY_CUSTOM_EQ_SPK_AUDIO \n
                                                            \#ALIAS : AUD DSP CFG KEY CUSTOM EQ SPK AUDIO \n
                                                            \#PARAM_TYPE : Private \n
                                                            \#PARAM_DESC : Custom EQ Spk \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0C \n
                                                            \#KEY_ID : 0x04 \n
                                                	    */
                                                	          
    AUD_DSP_CFG_KEY_H_CUSTOM_RX_EQ				= 0x05,  /**<\#PARAM_NAME : AUD_DSP_CFG_KEY_H_CUSTOM_RX_EQ \n
                                                             \#ALIAS : AUD DSP CFG KEY H CUSTOM RX EQ \n
                                                             \#PARAM_TYPE : Private \n
                                                             \#PARAM_DESC : RX Custom EQ, not implemented \n
                                                             \#DESC_END
                                                             \#KEY_ID : 0x05 \n
                                                    	 */
                                                	          

    AUD_DSP_CFG_KEY_END       
}AUD_DSP_CFG_Key_IdDefinition_T;



/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_VOICE_DSP.
 *  
 */


//Config Key definiton of MODULE_VOICE_DSP(0x0D)
typedef enum _VOICE_DSP_CFG_Key_IdDefinition_T
{
    VOICE_DSP_CFG_KEY_CONFIG_WORD                       = 0x01, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_CONFIG_WORD \n
                                                                    \#ALIAS : VOICE DSP CFG KEY CONFIG WORD \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC :  
                                                                                   Byte 1: \n
                                                                                    Bit 0: NE DRC \n
                                                                                    Bit 1: FE DRC \n
                                                                                    Bit 2: NE DC Remover \n
                                                                                    Bit 3: FE DC Remover \n
                                                                                    Bit 4: NE HPF \n
                                                                                    Bit 5: FE HPF \n
                                                                                    Bit 6: DRC_SMOOTHED_LOWER_KNEE_MIC \n
                                                                                    Bit 7: DRC_SMOOTHED_LOWER_KNEE_SPK \n
                                                                                    
                                                                                   Byte 2: \n
                                                                                    Bit 0: AEC \n
                                                                                    Bit 1: BSS \n
                                                                                    Bit 2: AES \n
                                                                                    Bit 3: AES White \n
                                                                                    Bit 4: BSS NL \n
                                                                                    Bit 5: FENR \n
                                                                                    Bit 6: NENR \n
                                                                                    Bit 7: AVC \n
                                                                                    
                                                                                   Byte 3: \n
                                                                                    Bit 0: DRC_AUTO_LOWER_KNEE \n
                                                                                    Bit 1: mSBC Mode (0 is CVSD, 1 is mSBC) \n
                                                                                    Bit 2: Wind Noise Reduction \n
                                                                                    Bit 3: APP Mode (0 is SHS, 1 is SP) \n
                                                                                    Bit 4: WNG \n
                                                                                    Bit 5: Yes/No VR \n
                                                                                    Bit 6: AEC_mSBC \n
                                                                                    Bit 7: I2S_Pin_Test \n
                                                                                    
                                                                                   Byte 4: \n
                                                                                    Bit 0: NE Delay \n
                                                                                    Bit 1: FE Delay \n
                                                                                    Bit 2: Ring-tone mode \n
                                                                                    Bit 3: BSS Calibration \n
                                                                                    Bit 4: FE Digital Gain \n
                                                                                    Bit 5: NE Line Digital Gain \n
                                                                                    Bit 6: NE Mic Digital Gain \n
                                                                                    Bit 7: NE Mic CODEC Gain Control \n
                                                                    
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x01 \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_H_TUNING_AVC                      = 0x02, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_H_TUNING_AVC \n
                                                                    \#ALIAS : VOICE DSP CFG KEY H TUNING AVC \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : An automatic volume control (AVC) automatically adjusts the volume, or loudness, of an audio signal, \n
                                                                                   usually to compensate for ambient noise in an effort to make the audio signal better heard and understood above the noise \n
                                                                                   AVC max gain \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x02 \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_TUNING_WNG                        = 0x03, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_TUNING_WNG \n
                                                                    \#ALIAS : VOICE DSP CFG KEY TUNING WNG \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : provides a constant noise level to prevent the speech codec \n
                                                                                   algorithm of host cellphones from injecting unwanted noise which could degrade speech clarity at the \n
                                                                                   far-end listener side \n
                                                                                   
                                                                                   Weighing factor to level the user selected gain for smoothening the noise level \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x03 \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_TUNING_DIGITAL_AND_CODEC_GAIN     = 0x04, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_TUNING_DIGITAL_AND_CODEC_GAIN \n
                                                                    \#ALIAS : VOICE DSP CFG KEY TUNING DIGITAL AND CODEC GAIN \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : Gain MIC0 \n
                                                                                   Tuning Mic Codec gain Minimum \n
                                                                                   Mic codec gain kickin ratio \n
                                                                                   Mic codec gain hold time \n
                                                                                   Mic codec gain recover window \n
                                                                                   Speaker gain (float value converted Q) \n
                                                                                   Line gain \n
                                                                                   Gian MIC1 \n
                                                                    
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x04 \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_TUNING_AEC_AES                    = 0x05, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_TUNING_AEC_AES \n
                                                                    \#ALIAS : VOICE DSP CFG KEY TUNING AEC AES \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : Taplength should be selected to be longer than the echo tail and it is also a tradeoff \n
                                                                                   between echo cancellation (EC) performance, mega-instructions per second (MIPS). 
                                                                                   If longer taplength is selected, higher MIPS and power consumption by DSP are the result. \n
                                                                                   This parameter determines the maximal non-linear echo suppression capability \n
                                                                                    
                                                                                   This parameter determines the linearity threshold of the returned echo.  \n
                                                                                   Double talk threshold \n
                                                                                   The AEC convergence speed. If fast convergence rate is selected, fewer echo is \n
                                                                                   capable to be cancelled out linearly. On the contrary, better linear echo cancellation can be achieved. \n
                                                                                   This parameter determines the linearity threshold of the returned echo. If \n
                                                                                   selecting toward “Worst linearity”, then AESfunction is configured to more easily kick in and \n
                                                                                   suppress the residual echo while the “Higher Linearity” option allows having better Full-duplex echo \n
                                                                                   cancellation performance but may contain more echo in the returned signal. \n
                                                                                   Echo Retrun loss attenuation threshold. \n
                                                                                   this parameter maps to a threshold that controls the AES to nonlinearly suppress the echo. \n
                                                                                   
                                                                                   Boundary variable to terminate nonlinear echo residues comes from either clipping or saturation  \n
                                                                                   Highfrequncy threshold to control the "calculated gain for non-statioanry noise and/or non-stationary echo residues". \n
                                                                                   Beginning Echo suppression time count \n
                                                                                   Reference line Voice acitivity dection minimum threshold value. \n
                                                                                   Echo Retrun loss attenuation threshold. \n
                                                                                   comfort noise generator threshold \n
                                                                                   comfort noise generator gain in AES case (Maximum to Minimum) \n
                                                                                   
                                                                                   Not used in V38 code. Need to check further. \n
                                                                                   AES suppression coefficients \n
                                                                                   Line-in gain MSBC \n
                                                                    
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x05 \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_TUNING_FENR                       = 0x06,   /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_TUNING_FENR \n
                                                                    \#ALIAS : VOICE DSP CFG KEY TUNING FENR \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : The noise reduction (NR) function suppresses stationary noises present in the far-end/downstream and \n
                                                                                   near-end/up-stream signals. With proprietary intelligent voice activity detection (VAD), the NR module \n
                                                                                   can effectively suppress the unwated noise while maintaining satisfactory quality for the speech \n
                                                                                   communication. This function allows both near-end and far-end talkers to experience benefits. \n
                                                                                    
                                                                                   Far End Music Noise factor gain. Not used in V38 code.  \n
                                                                                   Far end inner  Low frequncy threshold \n
                                                                                   Far end inner  high frequncy threshold \n
                                                                    
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x06 \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_TUNING_NENR                       = 0x07, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_TUNING_NENR \n
                                                                    \#ALIAS : VOICE DSP CFG KEY TUNING NENR \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : The noise reduction (NR) function suppresses stationary noises present in the far-end/downstream and \n
                                                                                   near-end/up-stream signals. With proprietary intelligent voice activity detection (VAD), the NR module \n
                                                                                   can effectively suppress the unwated noise while maintaining satisfactory quality for the speech \n
                                                                                   communication. This function allows both near-end and far-end talkers to experience benefits. \n
                                                                                    
                                                                                   Near End music noise gain calibration factor \n
                                                                                   Near end inner  Low frequncy threshold \n
                                                                                   Near end inner  high frequncy threshold \n
                                                                    
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x07 \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_H_TUNING_DRC_COM                  = 0x08, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_H_TUNING_DRC_COM \n
                                                                    \#ALIAS : VOICE DSP CFG KEY H TUNING DRC COM \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : This parameter corresponds to the compression threshold , A compressor reduces the level of an voice signal if its amplitude exceeds knee threshold \n
                                                                                   Adopting algorithm gain based on spkout threshold \n
                                                                                   Adopting algorithm gain based on mic  threshold \n
                                                                                   Ratio control that allows to tackle the input to output gain to same  level on far end data \n
                                                                                   Ratio control that allows to tackle the input to output gain to same  level on near end data \n
                                                                                   "maximal gain applying to voice signal whose average power is between silence \n
                                                                                   threshold and the compression knee" \n
                                                                                    
                                                                                   This parameter corresponds to the compression threshold , A compressor reduces the level of an voice signal if its amplitude exceeds knee threshold \n
                                                                    
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x08 \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_TUNING_HPF                        = 0x09, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_TUNING_HPF \n
                                                                    \#ALIAS : VOICE DSP CFG KEY TUNING HPF \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : Seven selectable cutoff frequencies are available for HPF which is to filter out unwanted low-frequency \n
                                                                                   signal, such as PCB noise, coupled current noise and wind noise, etc. It is a trade-off between speech \n
                                                                                   signal quality and the noise reduction level. \n
                                                                      
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x09 \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_H_TUNING_LINE_DELAY               = 0x0A, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_H_TUNING_LINE_DELAY \n
                                                                    \#ALIAS : VOICE DSP CFG KEY H TUNING LINE DELAY \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : Integer line delay from 0.5ms to 33ms \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x0A \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_TUNING_BSS                        = 0x0B, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_TUNING_BSS \n
                                                                    \#ALIAS : VOICE DSP CFG KEY TUNING BSS \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : tap length \n
                                                                                   bss nr coeff  \n
                                                                                   Distance between 2mics \n
                                                                                 
                                                                                   BSS delay integer \n
                                                                                   BSS delay fraction \n
                                                                                   This parameter determines the dualmicsuppression level. However, the dualmic suppression level is \n
                                                                                   a tradeoff between noise suppression capability and voice quality. If the higher the suppression level is \n
                                                                                   selected, the easier the voice quality is degraded \n
                                                                                   Denote the convergence time of the dualmic noise suppression algorithm. If choose faster \n
                                                                                   convergence time, then linear noise suppression capability is worse than the slowest convergence time. \n
                                                                                   It is a tradeoff between faster convergence time and better noise suppression \n
                                                                    
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x0B
B \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_H_TUNING_WIND_NOISE_SAMPLE_DELAY  = 0x0C, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_H_TUNING_WIND_NOISE_SAMPLE_DELAY \n
                                                                    \#ALIAS : VOICE DSP CFG KEY H TUNING WIND NOISE SAMPLE DELAY \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC :  Wind Noise sample delay. This is not used.(Wind Noise is diabled) \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x0C \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_H_TUNING_SYS_PARA                 = 0x0D, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_H_TUNING_SYS_PARA \n
                                                                    \#ALIAS : VOICE DSP CFG KEY H TUNING SYS PARA \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : MIDI Mode B tone type control parameter . \n
                                                                                   1.tone type(1) 2.waveform type(2) 3.third harmonic attenuation(16) 4.Tempo type(32) \n
                                                                                   silence data reversion(bit1) and fade-out of data(bit2) \n
                                                                                   silence suppression threshold \n
                                                                                   silence suppression Mean & Variance threshold \n
                                                                                   silence suppression fadeout step. \n
                                                                                   silence suppression tuning counter to disable or enable silence suppression. \n
                                                                                   dynamic range of line-in suppression minimum gain. \n
                                                                                   silence suppression fadein base step. \n
                                                                                   Mono/stereo mode selection \n
                                                                                   24to16bit_trucate \n
                                                                                   I2S codec off switch \n
                                                                                   I2S mode: master/slave \n
                                                                                   Reserved in 5511 (User for I2S PIN test in BT5506) \n
                                                                    
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x0D \n
                                                        	    */
                                                	          
    VOICE_DSP_CFG_KEY_MVDR                              = 0x0E, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_MVDR \n
                                                                    \#ALIAS : VOICE DSP CFG KEY MVDR \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : Distance between mic1  and mic2 in cm \n
                                                                                   Centre of the incident angle \n
                                                                                   Lower bound of the incident angle \n
                                                                                   Upper bound of the incident angle \n
                                                                                   Non linear silence suppression coefficients \n
                                                                                   Linear noise suppression coefficients \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x0E \n
                                                        	    */
                                                	          
	VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_CVSD                = 0x0F, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_CVSD \n
                                                                    \#ALIAS : VOICE DSP CFG KEY CUSTOM EQ SPK CVSD \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : Custom EQ Spk CVSD  \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x0F \n
                                                        	    */
                                                	          
	VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_MSBC		        = 0x10, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_MSBC \n
                                                                    \#ALIAS : VOICE DSP CFG KEY CUSTOM EQ SPK MSBC \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : Custom EQ Spk Msbc \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x10 \n
                                                        	    */
                                                	          
	VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_CVSD		        = 0x11, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_CVSD \n
                                                                    \#ALIAS : VOICE DSP CFG KEY CUSTOM EQ MIC CVSD \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : Custom EQ Mic CVSD \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x11 \n
                                                        	    */
                                                	          
	VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_MSBC		        = 0x12, /**<\#PARAM_NAME : VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_MSBC \n
                                                                    \#ALIAS : VOICE DSP CFG KEY CUSTOM EQ MIC MSBC \n
                                                                    \#PARAM_TYPE : Private \n
                                                                    \#PARAM_DESC : Custom EQ Mic Msbc \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x0D \n
                                                                    \#KEY_ID : 0x12 \n
                                                        	    */
                                                	          

    VOICE_DSP_CFG_KEY_END       
}VOICE_DSP_CFG_Key_IdDefinition_T;

#define CFG_VOICE_DSP_MODULE_TOTAL_NUM_KEYS   (VOICE_DSP_CFG_KEY_END - 1)



/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_I2S_DSP.
 *  
 */

//Config Key definiton of MODULE_I2S_DSP(0x0E)
typedef enum _I2S_DSP_CFG_Key_IdDefinition_T
{
    I2S_DSP_CFG_KEY_I2S_PARA            = 0x01, /**<\#PARAM_NAME : I2S_DSP_CFG_KEY_I2S_PARA \n
                                                    \#ALIAS : I2S DSP CFG KEY I2S PARA \n
                                                    \#PARAM_TYPE : Private \n
                                                    \#PARAM_DESC : I2S parameters \n
                                                    \#DESC_END
                                                    \#GROUP_ID : 0x0E \n
                                                    \#KEY_ID : 0x01 \n
                                        	    */

    I2S_DSP_CFG_KEY_END       
}I2S_DSP_CFG_Key_IdDefinition_T;

#define CFG_I2S_DSP_MODULE_TOTAL_NUM_KEYS   (I2S_DSP_CFG_KEY_END - 1)


/**
  @defgroup MODULE_AUD_DSP_DEFAULT_VALUE   AUDIO_DSP Configuration Default Value
  @{
  @brief Default value definition of the module @ref CFG_MODULE_ID_AUD_DSP.
 */

 
/****************** AUDIO_DSP **********************/

#define AUD_DSP_CFG_KEY_LINEIN_LEN                0x04                      /**< The default length of @ref AUD_DSP_CFG_KEY_LINEIN. */
#define AUD_DSP_CFG_KEY_LINEIN_DEFAULT_VALUE      0x14, 0x09, 0xFF, 0x00    /**< The default value of @ref AUD_DSP_CFG_KEY_LINEIN. */

#define AUD_DSP_CFG_KEY_MBDRC_LEN                                   0x08    /**< The default length of @ref AUD_DSP_CFG_KEY_MBDRC. */
#define AUD_DSP_CFG_KEY_MBDRC_DEFAULT_VALUE                         0x90,0x29,0x35,0x02,0x8F,0xF9,0x15,0xC3    /**< The default value of @ref AUD_DSP_CFG_KEY_MBDRC. */

#define AUD_DSP_CFG_KEY_H_LDAC_PARAMETER_LEN                        0x07    /**< The default length of @ref AUD_DSP_CFG_KEY_H_LDAC_PARAMETER. */
#define AUD_DSP_CFG_KEY_H_LDAC_PARAMETER_DEFAULT_VALUE              0x00,0x50,0x30,0x00,0x00,0x40,0x00    /**< The default value of @ref AUD_DSP_CFG_KEY_H_LDAC_PARAMETER. \n
                                                                    LDAC_parameter[0]	Reserved \n
                                                                    LDAC_parameter[1]	Upper threshold of buffer control (frames)   \n
                                                                    LDAC_parameter[2]	Lower threshold of buffer control (frames)   \n
                                                                    LDAC_parameter[3]	Reserved \n
                                                                    LDAC_parameter[4]	Reserved \n	 
                                                                    LDAC_parameter[5]	Target threshold of buffer control (frames) & number of frames to pre-queue.
                                                                                        Audio latency = LDAC_parameter[5] * 3ms \n
                                                                    LDAC_parameter[6]	Reserved*/

#define AUD_DSP_CFG_KEY_CUSTOM_EQ_SPK_AUDIO_LEN                     0x54    /**< The default length of @ref AUD_DSP_CFG_KEY_CUSTOM_EQ_SPK_AUDIO. */
#define AUD_DSP_CFG_KEY_CUSTOM_EQ_SPK_AUDIO_DEFAULT_VALUE           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                    0x40, 0x00, 0x00, 0x00    /**< The default value of @ref AUD_DSP_CFG_KEY_CUSTOM_EQ_SPK_AUDIO. */

#define AUD_DSP_CFG_KEY_H_CUSTOM_RX_EQ_LEN                          0x54    /**< The default length of @ref AUD_DSP_CFG_KEY_H_CUSTOM_RX_EQ. */
#define AUD_DSP_CFG_KEY_H_CUSTOM_RX_EQ_DEFAULT_VALUE                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                    0x40, 0x00, 0x00, 0x00    /**< The default value of @ref AUD_DSP_CFG_KEY_H_CUSTOM_RX_EQ. */

/** @} */
/****************************************************/

/**
  @defgroup MODULE_VOICE_DSP_DEFAULT_VALUE   VOICE_DSP Configuration Default Value
  @{
  @brief Default value definition of the module @ref CFG_MODULE_ID_VOICE_DSP.
 */
 
/****************** VOICE_DSP **********************/

#define VOICE_DSP_CFG_KEY_CONFIG_WORD_LEN                                   0x04    /**< The default length of @ref VOICE_DSP_CFG_KEY_CONFIG_WORD. */
#define VOICE_DSP_CFG_KEY_CONFIG_WORD_DEFAULT_VALUE                         0x3F,0x65,0x09,0x86    /**< The default value of @ref VOICE_DSP_CFG_KEY_CONFIG_WORD. */

#define VOICE_DSP_CFG_KEY_H_TUNING_AVC_LEN                                  0x03    /**< The default length of @ref VOICE_DSP_CFG_KEY_H_TUNING_AVC. */
#define VOICE_DSP_CFG_KEY_H_TUNING_AVC_DEFAULT_VALUE                        0x01,0x00,0x0A    /**< The default value of @ref VOICE_DSP_CFG_KEY_H_TUNING_AVC. */

#define VOICE_DSP_CFG_KEY_TUNING_WNG_LEN                                    0x03    /**< The default length of @ref VOICE_DSP_CFG_KEY_TUNING_WNG. */
#define VOICE_DSP_CFG_KEY_TUNING_WNG_DEFAULT_VALUE                          0x00,0x04,0x78    /**< The default value of @ref VOICE_DSP_CFG_KEY_TUNING_WNG. */

#define VOICE_DSP_CFG_KEY_TUNING_DIGITAL_AND_CODEC_GAIN_LEN                 0x06    /**< The default length of @ref VOICE_DSP_CFG_KEY_TUNING_DIGITAL_AND_CODEC_GAIN. */
#define VOICE_DSP_CFG_KEY_TUNING_DIGITAL_AND_CODEC_GAIN_DEFAULT_VALUE       0x1D,0x35,0x33,0x0D,0x0D,0x13    /**< The default value of @ref VOICE_DSP_CFG_KEY_TUNING_DIGITAL_AND_CODEC_GAIN. */

#define VOICE_DSP_CFG_KEY_TUNING_AEC_AES_LEN                                0x10    /**< The default length of @ref VOICE_DSP_CFG_KEY_TUNING_AEC_AES. */
#define VOICE_DSP_CFG_KEY_TUNING_AEC_AES_DEFAULT_VALUE                      0x05,0x44,0x7F,0x50,0x24,0x40,0x50,0x30,0x00,0x02,0x20,0x40,0x40,0x14,0x08,0x00    /**< The default value of @ref VOICE_DSP_CFG_KEY_TUNING_AEC_AES. */

#define VOICE_DSP_CFG_KEY_TUNING_FENR_LEN                                   0x03    /**< The default length of @ref VOICE_DSP_CFG_KEY_TUNING_FENR. */
#define VOICE_DSP_CFG_KEY_TUNING_FENR_DEFAULT_VALUE                         0x16,0x20,0x0A    /**< The default value of @ref VOICE_DSP_CFG_KEY_TUNING_FENR. */

#define VOICE_DSP_CFG_KEY_TUNING_NENR_LEN                                   0x03    /**< The default length of @ref VOICE_DSP_CFG_KEY_TUNING_NENR. */
#define VOICE_DSP_CFG_KEY_TUNING_NENR_DEFAULT_VALUE                         0x10,0x16,0x00    /**< The default value of @ref VOICE_DSP_CFG_KEY_TUNING_NENR. */

#define VOICE_DSP_CFG_KEY_H_TUNING_DRC_COM_LEN                              0x07    /**< The default length of @ref VOICE_DSP_CFG_KEY_H_TUNING_DRC_COM. */
#define VOICE_DSP_CFG_KEY_H_TUNING_DRC_COM_DEFAULT_VALUE                    0x1E,0x0F,0x0F,0x55,0x55,0x16,0x0A    /**< The default value of @ref VOICE_DSP_CFG_KEY_H_TUNING_DRC_COM. */

#define VOICE_DSP_CFG_KEY_TUNING_HPF_LEN                                    0x01    /**< The default length of @ref VOICE_DSP_CFG_KEY_TUNING_HPF. */
#define VOICE_DSP_CFG_KEY_TUNING_HPF_DEFAULT_VALUE                          0x54    /**< The default value of @ref VOICE_DSP_CFG_KEY_TUNING_HPF. */

#define VOICE_DSP_CFG_KEY_H_TUNING_LINE_DELAY_LEN                           0x01    /**< The default length of @ref VOICE_DSP_CFG_KEY_H_TUNING_LINE_DELAY. */
#define VOICE_DSP_CFG_KEY_H_TUNING_LINE_DELAY_DEFAULT_VALUE                 0x0B    /**< The default value of @ref VOICE_DSP_CFG_KEY_H_TUNING_LINE_DELAY. */

// hidden parameters are stored first in this cfgKey, to maintain the order in Voice Tuning Parameters
#define VOICE_DSP_CFG_KEY_TUNING_BSS_LEN                                    0x07    /**< The default length of @ref VOICE_DSP_CFG_KEY_TUNING_BSS. */
#define VOICE_DSP_CFG_KEY_TUNING_BSS_DEFAULT_VALUE                          0x04,0x12,0x00,0x00,0x10,0x12,0x07    /**< The default value of @ref VOICE_DSP_CFG_KEY_TUNING_BSS. */

#define VOICE_DSP_CFG_KEY_H_TUNING_WIND_NOISE_SAMPLE_DELAY_LEN              0x01    /**< The default length of @ref VOICE_DSP_CFG_KEY_H_TUNING_WIND_NOISE_SAMPLE_DELAY. */
#define VOICE_DSP_CFG_KEY_H_TUNING_WIND_NOISE_SAMPLE_DELAY_DEFAULT_VALUE    0x00    /**< The default value of @ref VOICE_DSP_CFG_KEY_H_TUNING_WIND_NOISE_SAMPLE_DELAY. */

#define VOICE_DSP_CFG_KEY_H_TUNING_SYS_PARA_LEN                             0x0A    /**< The default length of @ref VOICE_DSP_CFG_KEY_H_TUNING_SYS_PARA. */
#define VOICE_DSP_CFG_KEY_H_TUNING_SYS_PARA_DEFAULT_VALUE                   0x00,0x03,0x16,0xFF,0x40,0xF0,0x00,0x40,0x00,0x00    /**< The default value of @ref VOICE_DSP_CFG_KEY_H_TUNING_SYS_PARA. */

#define VOICE_DSP_CFG_KEY_MVDR_LEN                                          0x0B    /**< The default length of @ref VOICE_DSP_CFG_KEY_MVDR. */
#define VOICE_DSP_CFG_KEY_MVDR_DEFAULT_VALUE                                0x77,0x01,0x5E,0x00,0xf0,0x01,0xE0,0x00,0xC8,0x20,0x4E    /**< The default value of @ref VOICE_DSP_CFG_KEY_MVDRs. */


#define VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_CVSD_LEN                            0x54    /**< The default length of @ref VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_CVSD. */
#define VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_CVSD_DEFAULT_VALUE                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x40, 0x00, 0x00, 0x00    /**< The default value of @ref VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_CVSD. */

#define VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_MSBC_LEN                            0x54    /**< The default length of @ref VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_MSBC. */
#define VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_MSBC_DEFAULT_VALUE                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x40, 0x00, 0x00, 0x00    /**< The default value of @ref VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_MSBC. */


#define VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_CVSD_LEN                            0x54    /**< The default length of @ref VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_CVSD. */
#define VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_CVSD_DEFAULT_VALUE                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x40, 0x00, 0x00, 0x00    /**< The default value of @ref VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_CVSD. */

#define VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_MSBC_LEN                            0x54    /**< The default length of @ref VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_MSBC. */
#define VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_MSBC_DEFAULT_VALUE                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                            0x40, 0x00, 0x00, 0x00    /**< The default value of @ref VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_MSBC. */

/** @} */
/****************************************************/

/**
  @defgroup MODULE_I2S_DSP_DEFAULT_VALUE   I2S_DSP Configuration Default Value
  @{
  @brief Default value definition of the module @ref CFG_MODULE_ID_I2S_DSP.
 */

/****************** I2S_DSP **********************/
//#define DEFAULT_ST_CODEC
#define I2S_DSP_CFG_KEY_I2S_PARA_LEN                0xBE    /**< The default length of @ref I2S_DSP_CFG_KEY_I2S_PARA. */
#ifdef DEFAULT_ST_CODEC
#define I2S_DSP_CFG_KEY_I2S_PARA_DEFAULT_VALUE      \
	0x01,0x00,0x00,0x1F,0x2D,0x5B,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 8K     */\
	0x01,0x00,0x00,0x1F,0x16,0x2D,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 16K    */\
	0x01,0x00,0x00,0x1F,0x07,0x0F,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 44.1K  */\
	0x01,0x00,0x00,0x1F,0x05,0x0B,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 48K    */\
	0x01,0x00,0x00,0x1F,0x07,0x07,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 88.2K  */\
	0x01,0x00,0x00,0x1F,0x05,0x05,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 96K    */\
	0x12,0x03,0xA0,0x1A,0x78,/* 8K     PLL setting*/\
	0x12,0x03,0xA0,0x1A,0x78,/* 16K    */\
	0x11,0x03,0xF4,0x1E,0x78,/* 44.1K  */\
	0x12,0x03,0xE9,0x06,0x40,/* 48K    */\
	0x11,0x03,0xF4,0x1E,0x78,/* 88.2K  */\
	0x12,0x03,0xE9,0x06,0x40,/* 96K    */\
	0x01,0x00,0x00,0x1F,0x07,0x0F,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 44.1K Line-in setting */\
	0x01,0x00,0x00,0x1F,0x05,0x0B,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60 /* 48K    */    /**< The default value of @ref I2S_DSP_CFG_KEY_I2S_PARA. */
/** \cond NON_DOC */
#else //YAMAHA Codec
//#define I2S_DSP_CFG_KEY_I2S_PARA_DEFAULT_VALUE      \
0x01,0x00,0x00,0x1F,0x00,0x45,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 8K     */\
0x01,0x00,0x00,0x1F,0x00,0x22,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 16K    */\
0x01,0x00,0x00,0x1F,0x00,0x0B,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 44.1K  */\
0x01,0x00,0x00,0x1F,0x00,0x0B,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 48K    */\
0x01,0x00,0x00,0x1F,0x00,0x05,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 88.2K  */\
0x01,0x00,0x00,0x1F,0x00,0x05,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 96K    */\
0x12,0x03,0xB9,0x1E,0x40,/* 8K     PLL setting*/\
0x12,0x03,0xB9,0x1E,0x40,/* 16K    */\
0x11,0x03,0xF3,0x1E,0x40,/* 44.1K  */\
0x12,0x03,0xE9,0x06,0x40,/* 48K    */\
0x11,0x03,0xF3,0x1E,0x40,/* 88.2K  */\
0x12,0x03,0xE9,0x06,0x40,/* 96K    */\
0x01,0x00,0x00,0x1F,0x00,0x0B,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60,/* 44.1K Line-in setting */\
0x01,0x00,0x00,0x1F,0x00,0x0B,0xEB,0x5F,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x10,0x10,0x08,0x60   /* 48K  */    /**< The default value of @ref I2S_DSP_CFG_KEY_I2S_PARA. */
#endif
/// \endcond
/** @} */
/** @} */

/** \cond NON_DOC */


/****************************************************/

#define CFG_AUD_DSP_MODULE_TOTAL_NUM_KEYS   (AUD_DSP_CFG_KEY_END - 1)

#define CFG_AUD_DSP_MODULE_TOTAL_SIZE   ((CFG_AUD_DSP_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) + \
                                        AUD_DSP_CFG_KEY_LINEIN_LEN +  \
                                        AUD_DSP_CFG_KEY_MBDRC_LEN +                     \
                                        AUD_DSP_CFG_KEY_H_LDAC_PARAMETER_LEN +          \
                                        AUD_DSP_CFG_KEY_CUSTOM_EQ_SPK_AUDIO_LEN +       \
                                        AUD_DSP_CFG_KEY_H_CUSTOM_RX_EQ_LEN)

#define CFG_VOICE_DSP_MODULE_TOTAL_SIZE     ((CFG_VOICE_DSP_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) + \
                                            VOICE_DSP_CFG_KEY_CONFIG_WORD_LEN +                         \
                                            VOICE_DSP_CFG_KEY_H_TUNING_AVC_LEN +                        \
                                            VOICE_DSP_CFG_KEY_TUNING_WNG_LEN +                          \
                                            VOICE_DSP_CFG_KEY_TUNING_DIGITAL_AND_CODEC_GAIN_LEN +       \
                                            VOICE_DSP_CFG_KEY_TUNING_AEC_AES_LEN +                      \
                                            VOICE_DSP_CFG_KEY_TUNING_FENR_LEN +                         \
                                            VOICE_DSP_CFG_KEY_TUNING_NENR_LEN +                         \
                                            VOICE_DSP_CFG_KEY_H_TUNING_DRC_COM_LEN +                    \
                                            VOICE_DSP_CFG_KEY_TUNING_HPF_LEN +                          \
                                            VOICE_DSP_CFG_KEY_H_TUNING_LINE_DELAY_LEN +                 \
                                            VOICE_DSP_CFG_KEY_TUNING_BSS_LEN +                          \
                                            VOICE_DSP_CFG_KEY_H_TUNING_WIND_NOISE_SAMPLE_DELAY_LEN +    \
                                            VOICE_DSP_CFG_KEY_H_TUNING_SYS_PARA_LEN +                   \
											VOICE_DSP_CFG_KEY_MVDR_LEN +                                \
											VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_CVSD_LEN +                  \
											VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_MSBC_LEN +                  \
											VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_CVSD_LEN +                  \
											VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_MSBC_LEN)

#define CFG_I2S_DSP_MODULE_TOTAL_SIZE   ((CFG_I2S_DSP_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) + \
                                        I2S_DSP_CFG_KEY_I2S_PARA_LEN)

//Audio_DSP Config keys definition
#define CFG_AUD_DSP_MODULE_DEFAULT_VALUE    CFG_MODULE_ID_AUD_DSP,               /*moduleID*/   \
                                            CFG_AUD_DSP_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/    \
                                            (CFG_AUD_DSP_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/  \
                                            CFG_AUD_DSP_MODULE_TOTAL_SIZE,                      \
                                            /*CFG_KEYs[numKeys]*/                               \
                                            /*    //ID                                                                  //Len                                                                                    //Value    */                                      \
                                            AUD_DSP_CFG_KEY_LINEIN,   AUD_DSP_CFG_KEY_LINEIN_LEN,   AUD_DSP_CFG_KEY_LINEIN_DEFAULT_VALUE, \
                                            AUD_DSP_CFG_KEY_MBDRC,                      AUD_DSP_CFG_KEY_MBDRC_LEN,                      AUD_DSP_CFG_KEY_MBDRC_DEFAULT_VALUE,                    \
                                            AUD_DSP_CFG_KEY_H_LDAC_PARAMETER,           AUD_DSP_CFG_KEY_H_LDAC_PARAMETER_LEN,           AUD_DSP_CFG_KEY_H_LDAC_PARAMETER_DEFAULT_VALUE,         \
                                            AUD_DSP_CFG_KEY_CUSTOM_EQ_SPK_AUDIO,        AUD_DSP_CFG_KEY_CUSTOM_EQ_SPK_AUDIO_LEN,        AUD_DSP_CFG_KEY_CUSTOM_EQ_SPK_AUDIO_DEFAULT_VALUE,   \
                                            AUD_DSP_CFG_KEY_H_CUSTOM_RX_EQ,		        AUD_DSP_CFG_KEY_H_CUSTOM_RX_EQ_LEN,		        AUD_DSP_CFG_KEY_H_CUSTOM_RX_EQ_DEFAULT_VALUE


#define CFG_VOICE_DSP_MODULE_DEFAULT_VALUE  CFG_MODULE_ID_VOICE_DSP,               /*moduleID*/   \
                                            CFG_VOICE_DSP_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/    \
                                            (CFG_VOICE_DSP_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/  \
                                            CFG_VOICE_DSP_MODULE_TOTAL_SIZE,                      \
                                            /*CFG_KEYs[numKeys]*/                               \
                                                        /*    //ID                                                                  //Len                                                                                    //Value    */                                      \
                                            VOICE_DSP_CFG_KEY_CONFIG_WORD,                      VOICE_DSP_CFG_KEY_CONFIG_WORD_LEN,                      VOICE_DSP_CFG_KEY_CONFIG_WORD_DEFAULT_VALUE,                        \
                                            VOICE_DSP_CFG_KEY_H_TUNING_AVC,                     VOICE_DSP_CFG_KEY_H_TUNING_AVC_LEN,                     VOICE_DSP_CFG_KEY_H_TUNING_AVC_DEFAULT_VALUE,                       \
                                            VOICE_DSP_CFG_KEY_TUNING_WNG,                       VOICE_DSP_CFG_KEY_TUNING_WNG_LEN,                       VOICE_DSP_CFG_KEY_TUNING_WNG_DEFAULT_VALUE,                         \
                                            VOICE_DSP_CFG_KEY_TUNING_DIGITAL_AND_CODEC_GAIN,    VOICE_DSP_CFG_KEY_TUNING_DIGITAL_AND_CODEC_GAIN_LEN,    VOICE_DSP_CFG_KEY_TUNING_DIGITAL_AND_CODEC_GAIN_DEFAULT_VALUE,                   \
                                            VOICE_DSP_CFG_KEY_TUNING_AEC_AES,                   VOICE_DSP_CFG_KEY_TUNING_AEC_AES_LEN,                   VOICE_DSP_CFG_KEY_TUNING_AEC_AES_DEFAULT_VALUE,                     \
                                            VOICE_DSP_CFG_KEY_TUNING_FENR,                      VOICE_DSP_CFG_KEY_TUNING_FENR_LEN,                      VOICE_DSP_CFG_KEY_TUNING_FENR_DEFAULT_VALUE,                        \
                                            VOICE_DSP_CFG_KEY_TUNING_NENR,                      VOICE_DSP_CFG_KEY_TUNING_NENR_LEN,                      VOICE_DSP_CFG_KEY_TUNING_NENR_DEFAULT_VALUE,                        \
                                            VOICE_DSP_CFG_KEY_H_TUNING_DRC_COM,                 VOICE_DSP_CFG_KEY_H_TUNING_DRC_COM_LEN,                 VOICE_DSP_CFG_KEY_H_TUNING_DRC_COM_DEFAULT_VALUE,                   \
                                            VOICE_DSP_CFG_KEY_TUNING_HPF,                       VOICE_DSP_CFG_KEY_TUNING_HPF_LEN,                       VOICE_DSP_CFG_KEY_TUNING_HPF_DEFAULT_VALUE,                         \
                                            VOICE_DSP_CFG_KEY_H_TUNING_LINE_DELAY,              VOICE_DSP_CFG_KEY_H_TUNING_LINE_DELAY_LEN,              VOICE_DSP_CFG_KEY_H_TUNING_LINE_DELAY_DEFAULT_VALUE,                \
                                            VOICE_DSP_CFG_KEY_TUNING_BSS,                       VOICE_DSP_CFG_KEY_TUNING_BSS_LEN,                       VOICE_DSP_CFG_KEY_TUNING_BSS_DEFAULT_VALUE,                         \
                                            VOICE_DSP_CFG_KEY_H_TUNING_WIND_NOISE_SAMPLE_DELAY, VOICE_DSP_CFG_KEY_H_TUNING_WIND_NOISE_SAMPLE_DELAY_LEN, VOICE_DSP_CFG_KEY_H_TUNING_WIND_NOISE_SAMPLE_DELAY_DEFAULT_VALUE,   \
                                            VOICE_DSP_CFG_KEY_H_TUNING_SYS_PARA,                VOICE_DSP_CFG_KEY_H_TUNING_SYS_PARA_LEN,                VOICE_DSP_CFG_KEY_H_TUNING_SYS_PARA_DEFAULT_VALUE,                    \
                                            VOICE_DSP_CFG_KEY_MVDR,                             VOICE_DSP_CFG_KEY_MVDR_LEN,                             VOICE_DSP_CFG_KEY_MVDR_DEFAULT_VALUE,                 \
                                            VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_CVSD,               VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_CVSD_LEN,               VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_CVSD_DEFAULT_VALUE,   \
                                            VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_MSBC,               VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_MSBC_LEN,               VOICE_DSP_CFG_KEY_CUSTOM_EQ_SPK_MSBC_DEFAULT_VALUE,   \
                                            VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_CVSD,               VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_CVSD_LEN,               VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_CVSD_DEFAULT_VALUE,   \
                                            VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_MSBC,               VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_MSBC_LEN,               VOICE_DSP_CFG_KEY_CUSTOM_EQ_MIC_MSBC_DEFAULT_VALUE


#define CFG_I2S_DSP_MODULE_DEFAULT_VALUE    CFG_MODULE_ID_I2S_DSP,               /*moduleID*/   \
                                            CFG_I2S_DSP_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/    \
                                            (CFG_I2S_DSP_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/  \
                                            CFG_I2S_DSP_MODULE_TOTAL_SIZE,                      \
                                            /*CFG_KEYs[numKeys]*/                               \
                                                /*    //ID                                          //Len                                                                       //Value    */                \
                                            I2S_DSP_CFG_KEY_I2S_PARA,           I2S_DSP_CFG_KEY_I2S_PARA_LEN,               I2S_DSP_CFG_KEY_I2S_PARA_DEFAULT_VALUE

typedef struct _APP_Cfg_DspLineInParam_T
{
    uint8_t lineInDetectThreshold;
    uint8_t adcGainSetting;                                /**< The ADC gain setting for line in.*/  
    uint8_t internalSilenceMvThreshold;                    /**< The DSP tuning parameter for silence detection.*/ 
    uint8_t reserved;
}APP_Cfg_LineInDspParam_T;
void APP_CFG_ReadAudioTxCustomEq(uint8_t XDATA *p_len, uint8_t XDATA *p_param) large;
void APP_CFG_WriteAudioTxCustomEq(uint8_t p_len, uint8_t XDATA *p_param) large;
void APP_CFG_ReadVoiceTxCustomEq(uint8_t XDATA *p_len, uint8_t XDATA *p_param) large;
void APP_CFG_ReadMsbcTxCustomEq(uint8_t XDATA *p_len, uint8_t XDATA *p_param) large;
void APP_CFG_ReadVoiceRxCustomEq(uint8_t XDATA *p_len, uint8_t XDATA *p_param) large;
void APP_CFG_ReadMsbcRxCustomEq(uint8_t XDATA *p_len, uint8_t XDATA *p_param) large;
void APP_CFG_ReadI2sParameter(uint8_t XDATA *p_len, uint8_t XDATA *p_param) large;
void APP_CFG_ReadVoiceTuningParameter(uint8_t XDATA *p_len, uint8_t XDATA *p_param) large;
void APP_CFG_ReadAudioEffectParameter(uint8_t XDATA *p_len, uint8_t XDATA *p_param) large;
void APP_CFG_ReadDspLdacParameter(uint8_t XDATA *p_len, uint8_t XDATA *p_param) large;
void APP_CFG_ReadDspLineInParameter(uint8_t XDATA *p_len, uint8_t XDATA *p_param) large;

/// \endcond

#endif //APP_CFG_DSP_H

