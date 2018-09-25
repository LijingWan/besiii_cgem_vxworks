#ifndef SD_CGEM_CFG_H_INCLUDED
#define SD_CGEM_CFG_H_INCLUDED
int char_type(char c);
void extract_para_from_line(char*line,int line_strlen,char*cmd_string,unsigned int*cmd_para);
unsigned int swap_order_N_bits(unsigned int Hex_data,unsigned int N_bits);
void DAQ_init(  unsigned int TARGET_GEMROC_ID_param,
                char* command_string_param,
                unsigned int TCAM_ID_param,
                unsigned int number_of_repetitions_param,
                unsigned int to_ALL_TCAM_enable_param);
unsigned int DAQ_cmd_words_array_size();
void DAQ_print_command_words();
void DAQ_set_target_GEMROC (unsigned int GEMROC_ID_param);
void DAQ_set_target_TCAM_ID(unsigned int target_TA_param,unsigned int to_ALL_TCAM_EN_param);
void DAQ_set_TP_width(unsigned int target_TP_width_param);

void DAQ_set_TP_period(unsigned int TP_period_param);


void DAQ_set_AUTO_TP_EN_pattern(unsigned int target_AUTO_TP_EN_param);

void DAQ_set_Periodic_TP_EN_pattern(unsigned int Periodic_TP_EN_pattern_param);
void DAQ_set_TL_nTM_ACQ(unsigned int TL_nTM_ACQ_param);
void DAQ_set_EN_TM_TCAM_pattern(unsigned int EN_TM_TCAM_pattern_param);
void DAQ_set_TP_Pos_nNeg(unsigned int TP_Pos_nNeg_param);

void DAQ_set_gemroc_cmd_code( char* command_string_param,unsigned int no_of_executions_param);

void DAQ_update_command_words();

void gemroc_init(unsigned int TARGET_GEMROC_ID_param,char*command_string_param,unsigned int number_of_repetitions_param);

unsigned int gemroc_cmd_words_array_size();

void gemroc_print_command_words();
void gemroc_set_target_GEMROC (unsigned int GEMROC_ID_param);

void gemroc_set_FEB_PWR_EN_pattern(unsigned int target_FEB_PWR_EN_pattern);

void gemroc_set_timing_toFEB_delay(unsigned int FEB3dly_param, unsigned int FEB2dly_param,
                                   unsigned int FEB1dly_param,unsigned int  FEB0dly_param);

void gemroc_set_gemroc_cmd_code(char*command_string_param, unsigned int no_of_executions_param);

void gemroc_update_command_words();


void ch_reg_init(unsigned int TARGET_GEMROC_ID_param);
void ch_reg_reload_chcfg_settings_from_file();


   unsigned int ch_reg_command_words_array_size();

void ch_reg_print_command_words();

void ch_reg_set_target_GEMROC(unsigned int GEMROC_ID_param);
void ch_reg_set_target_TIGER(unsigned int target_TIGER_param);
void ch_reg_set_target_channel(unsigned int target_channel_param);
void ch_reg_set_Vth_T1(unsigned int Vth_T1_param);
void ch_reg_set_to_ALL_param(unsigned int to_ALL_param);
void ch_reg_set_command_code(char*command_code_param);

void ch_reg_set_TP_disable_FE(unsigned int TP_disable_FE_param);

void ch_reg_update_command_words();

void g_reg_init(int TARGET_GEMROC_ID_param);

void g_reg_reload_gcfg_settings_from_file();

unsigned int g_reg_command_words_array_size();

void g_reg_print_command_words();
void g_reg_set_target_GEMROC(unsigned int GEMROC_ID_param);
void g_reg_set_target_TIGER(unsigned int target_TIGER_param);
void g_reg_set_FE_TPEnable(unsigned int FE_TPEnable_param);
void g_reg_set_AVcasp_global(unsigned int AVcasp_global_param);
void g_reg_set_command_code(char* command_code_param);

void g_reg_update_command_words();


void send_GEMROC_CFG_CMD_PKT( unsigned int TARGET_GEMROC_ID_param,
                              void*array_to_send_param, int cmdlen,char*DEST_IP_ADDRESS_PARAM, unsigned int DEST_PORT_NO_PARAM);
void send_TIGER_GCFG_Reg_CMD_PKT(unsigned int TIGER_ID_param, void*array_to_send_param, int cmdlen,
                                 char*DEST_IP_ADDRESS_PARAM, unsigned int DEST_PORT_NO_PARAM);

void send_TIGER_Ch_CFG_Reg_CMD_PKT(unsigned int TIGER_ID_param,void*array_to_send_param,int cmdlen,
                                   char*DEST_IP_ADDRESS_PARAM, unsigned int DEST_PORT_NO_PARAM);

void GEMROC_IVT_read_and_log(unsigned int GEMROC_ID_param, unsigned int display_enable_param,
                             unsigned int log_enable_param);

void send_GEMROC_LV_CMD (unsigned int GEMROC_ID_param, char*COMMAND_STRING_PARAM);
void FEBPwrEnPattern_set(unsigned int GEMROC_ID_param, unsigned int FEB_PWREN_pattern_param);

void set_FEB_timing_delays(unsigned int GEMROC_ID_param, unsigned int FEB3_TDly, unsigned int FEB2_TDly,
                           unsigned int FEB1_TDly, unsigned int FEB0_TDly);
void send_GEMROC_DAQ_CMD(unsigned int GEMROC_ID_param,char*COMMAND_STRING_PARAM);
void  ResetTgtGEMROC_ALL_TIGER_GCfgReg(unsigned int GEMROC_ID_param);

void WriteTgtGEMROC_TIGER_GCfgReg_fromfile(unsigned int GEMROC_ID_param, unsigned int TIGER_ID_param);

void set_FE_TPEnable(unsigned int GEMROC_ID_param, unsigned int TIGER_ID_param,
                      unsigned int FE_TPEnable_param);

void ReadTgtGEMROC_TIGER_GCfgReg (unsigned int  GEMROC_ID_param,
                                   unsigned int TIGER_ID_param);
void WriteTgtGEMROC_TIGER_ChCfgReg_fromfile (unsigned int  GEMROC_ID_param,
          unsigned int TIGER_ID_param, unsigned int channel_ID_param);

void ReadTgtGEMROC_TIGER_ChCfgReg ( unsigned int GEMROC_ID_param, unsigned int TIGER_ID_param,
                                    unsigned int channel_ID_param, unsigned int verbose_mode);

void Set_GEMROC_TIGER_ch_TPEn ( unsigned int GEMROC_ID_param, unsigned int TIGER_ID_param,
          unsigned int  Channel_ID_param, unsigned int TP_disable_FE_param, unsigned int TriggerMode_param);


void Set_Vth_T1 ( unsigned int GEMROC_ID_param, unsigned int TIGER_ID_param,
            unsigned int Channel_ID_param, unsigned int VthT1_param);
void set_AVcasp_global( unsigned int GEMROC_ID_param, unsigned int TIGER_ID_param,
                        unsigned int AVcasp_global_param);
void SynchReset_to_TgtFEB( unsigned int GEMROC_ID_param, unsigned int TargetFEB_param, unsigned int To_ALL_param);
void SynchReset_to_TgtTCAM( unsigned int GEMROC_ID_param, unsigned int TargetTCAM_param, unsigned int To_ALL_param);

void DAQ_set_and_TL_start(unsigned int GEMROC_ID_param,
                           unsigned int TCAM_Enable_pattern_param, unsigned int Per_FEB_TP_Enable_pattern_param);
void Set_OV_OC_OT_PWR_CUT_EN_FLAGS( unsigned int GEMROC_ID_param, unsigned int FEB_OVC_EN_pattern_param,
       unsigned int FEB_OVV_EN_pattern_param, unsigned int FEB_OVT_EN_pattern_param,unsigned int ROC_OVT_EN_param);

void Set_OVVA_LIMIT( unsigned int GEMROC_ID_param, unsigned int FEB3_OVVA_thr_param, unsigned int FEB2_OVVA_thr_param,
             unsigned int  FEB1_OVVA_thr_param, unsigned int FEB0_OVVA_thr_param);

void Set_OVVD_LIMIT( unsigned int GEMROC_ID_param, unsigned int FEB3_OVVD_thr_param, unsigned int FEB2_OVVD_thr_param,
                           unsigned int  FEB1_OVVD_thr_param, unsigned int FEB0_OVVD_thr_param);
void Set_OVCA_LIMIT(unsigned int GEMROC_ID_param, unsigned int FEB3_OVCA_thr_param, unsigned int FEB2_OVCA_thr_param,
                    unsigned int  FEB1_OVCA_thr_param, unsigned int FEB0_OVCA_thr_param);
void Set_OVCD_LIMIT( unsigned int GEMROC_ID_param, unsigned int FEB3_OVCD_thr_param, unsigned int FEB2_OVCD_thr_param,
                     unsigned int  FEB1_OVCD_thr_param,unsigned int  FEB0_OVCD_thr_param);

void Set_OVTF_LIMIT(int GEMROC_ID_param, int FEB3_OVTF_thr_param,int FEB2_OVTF_thr_param,
                     int FEB1_OVTF_thr_param, int FEB0_OVTF_thr_param);
void set_ROC_OVT_LIMIT( int GEMROC_ID_param, int ROC_OVT_thr_param);
void Read_GEMROC_LV_CfgReg(int GEMROC_ID_param);
void Read_GEMROC_DAQ_CfgReg( int GEMROC_ID_param);
void cgem();


#endif // SD_CGEM_CFG_H_INCLUDED
