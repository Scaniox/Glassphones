#ifndef commands_h
#define commands_h

#include "IS2020.h"
#include <Arduino.h>

#define CMD_Make_Call 0x00
#define CMD_Make_Extension_Call 0x01
#define CMD_MMI_Action 0x02
#define CMD_Event_Mask_Setting  0x03
#define CMD_Music_Control 0x04
#define CMD_Change_Device_Name  0x05
#define CMD_Change_PIN_Code 0x06
#define CMD_BTM_Parameter_Setting 0x07
#define CMD_Read_BTM_Version  0x08
#define CMD_Get_PB_By_AT_Cmd  0x09
#define CMD_Vendor_AT_Command 0x0A
#define CMD_AVRCP_Specific_Cmd  0x0B
#define CMD_AVRCP_Group_Navigation  0x0C
#define CMD_AVRCP_Group_NavigationNext 0x00
#define CMD_AVRCP_Group_NavigationPrevious 0x01
#define CMD_Read_Link_Status  0x0D
#define CMD_Read_Paired_Device_Record 0x0E
#define CMD_Read_Local_BT_Address 0x0F
#define CMD_Read_Local_Device_Name  0x10
#define CMD_Set_Access_PB_Method  0x11
#define CMD_Send_SPP_iAP_Data 0x12
#define CMD_BTM_Utility_Function  0x13
#define CMD_Event_ACK 0x14
#define CMD_Additional_Profiles_Link_Setup  0x15
#define CMD_Read_Linked_Device_Information  0x16
#define CMD_Profile_Link_Back  0x17
#define CMD_Disconnect  0x18
#define CMD_MCU_Status_Indication 0x19
#define CMD_User_Confirm_SPP_Req_Reply  0x1A
#define CMD_Set_HF_Gain_Level 0x1B
#define CMD_EQ_Mode_Setting 0x1C
#define CMD_DSP_NR_CTRL 0x1D
#define CMD_GPIO_Control  0x1E
#define CMD_MCU_UART_Rx_Buffer_Size 0x1F
#define CMD_Voice_Prompt_Cmd  0x20
#define CMD_MAP_REQUEST 0x21
#define CMD_Security_Bonding_Req  0x22
#define CMD_Set_Overall_Gain  0x23

#define CRLDI_query_device_name 0x00
#define CRLDI_query_in_band_ringtone_status 0x01
#define CRLDI_query_if_remote_device_is_iAP_device 0x02
#define CRLDI_query_if_remote_device_support_AVRCP_v13 0x03
#define CRLDI_query_HF_A2DP_gain 0x04
#define CRLDI_query_Line_In_gain 0x05

#define LAST_DEVICE 0x00	//connect to last device : if last device supports HF/HS, then initiate HF/HS connection, otherwise initiate A2DP connection
#define INIT_HF_HS_CONNECTION 0x01	//initiate HF/HS connection to last HF/HS device
#define INIT_A2DP_CONNECTION 0x02	//initiate A2DP connection to last A2DP device
#define INIT_SPP_iAP_CONNECTION 0x03	//initiate SPP/iAP connection to last SPP/iAP device
#define INIT_DEDICATED_CONNECTION 0x04	//initiate connection to dedicate device.

#endif
