#ifndef SD_CGEM_H_INCLUDED
#define SD_CGEM_H_INCLUDED

struct g_reg_para{
      unsigned int TARGET_GEMROC_ID;
      unsigned int parameter_array[37];
      unsigned int BufferBias;
      unsigned int TDCVcasN;
      unsigned int TDCVcasP;
      unsigned int TDCVcasPHyst;
      unsigned int DiscFE_Ibias;
      unsigned int BiasFE_PpreN;
      unsigned int AVcasp_global;
      unsigned int TDCcompVcas;
      unsigned int TDCIref_cs;
      unsigned int DiscVcasN;
      unsigned int IntegVb1;
      unsigned int BiasFE_A1;
      unsigned int Vcasp_Vth;
      unsigned int TAC_I_LSB;
      unsigned int TDCcompVbias;
      unsigned int Vref_Integ;
      unsigned int IBiasTPcal;
      unsigned int TP_Vcal ;
      unsigned int ShaperIbias;
      unsigned int IPostamp;
      unsigned int TP_Vcal_ref;
      unsigned int Vref_integ_diff;
      unsigned int Sig_pol;
      unsigned int FE_TPEnable;
      unsigned int DataClkDiv;
      unsigned int TACrefreshPeriod;
      unsigned int TACrefreshEnable;
      unsigned int CounterPeriod;
      unsigned int CounterEnable;
      unsigned int StopRampEnable;
      unsigned int RClkEnable;
      unsigned int TDCClkdiv;
      unsigned int VetoMode ;
      unsigned int Ch_DebugMode;
      unsigned int TxMode;
      unsigned int TxDDR ;
      unsigned int TxLinks;
      unsigned int is_a_write;
      unsigned int target_TIGER_ID;
      unsigned int command_code;
      unsigned int command_words[12];} __attribute__((packed));

struct  ch_reg_para{
      unsigned int TARGET_GEMROC_ID;
      unsigned int DisableHyst ;
      unsigned int T2Hyst ;
      unsigned int T1Hyst;
      unsigned int Ch63ObufMSB;
      unsigned int TP_disable_FE;
      unsigned int TDC_IB_E ;
      unsigned int TDC_IB_T ;
      unsigned int Integ ;
      unsigned int PostAmpGain;
      unsigned int FE_delay;
      unsigned int Vth_T2;
      unsigned int Vth_T1 ;
      unsigned int QTx2Enable;
      unsigned int MaxIntegTime;
      unsigned int MinIntegTime;
      unsigned int TriggerBLatched;
      unsigned int QdcMode ;
      unsigned int BranchEnableT;
      unsigned int BranchEnableEQ;
      unsigned int TriggerMode2B ;
      unsigned int TriggerMode2Q;
      unsigned int TriggerMode2E;
      unsigned int TriggerMode2T;
      unsigned int TACMinAge;
      unsigned int TACMaxAge;
      unsigned int CounterMode;
      unsigned int DeadTime;
      unsigned int SyncChainLen;
      unsigned int Ch_DebugMode;
      unsigned int TriggerMode;
      unsigned int is_a_write;
      unsigned int target_TIGER_ID;
      unsigned int command_code;
      unsigned int TO_ALL_enable;
      unsigned int channel_ID;
      unsigned int command_words[10];
      unsigned int parameter_array[30];
                    } __attribute__((packed));

struct gemroc_para{
      unsigned int number_of_repetitions;
      unsigned int TARGET_GEMROC_ID;
      unsigned int parameter_array[31];
      unsigned int TIMING_DLY_FEB0;
      unsigned int TIMING_DLY_FEB1;
      unsigned int TIMING_DLY_FEB2;
      unsigned int TIMING_DLY_FEB3;
      unsigned int FEB_PWR_EN_pattern;
      unsigned int FEB_OVC_EN_pattern;
      unsigned int FEB_OVV_EN_pattern;
      unsigned int FEB_OVT_EN_pattern;
      unsigned int ROC_OVT_EN;
      unsigned int XCVR_LPBCK_TST_EN;
      unsigned int ROC_OVT_LIMIT;
      unsigned int A_OVC_LIMIT_FEB0;
      unsigned int A_OVV_LIMIT_FEB0;
      unsigned int A_OVC_LIMIT_FEB1;
      unsigned int A_OVV_LIMIT_FEB1;
      unsigned int A_OVC_LIMIT_FEB2 ;
      unsigned int A_OVV_LIMIT_FEB2;
      unsigned int A_OVC_LIMIT_FEB3;
      unsigned int A_OVV_LIMIT_FEB3;
      unsigned int D_OVC_LIMIT_FEB0;
      unsigned int D_OVV_LIMIT_FEB0;
      unsigned int OVT_LIMIT_FEB0 ;
      unsigned int D_OVC_LIMIT_FEB1;
      unsigned int D_OVV_LIMIT_FEB1;
      unsigned int OVT_LIMIT_FEB1;
      unsigned int D_OVC_LIMIT_FEB2;
      unsigned int D_OVV_LIMIT_FEB2;
      unsigned int OVT_LIMIT_FEB2;
      unsigned int D_OVC_LIMIT_FEB3;
      unsigned int D_OVV_LIMIT_FEB3;
      unsigned int OVT_LIMIT_FEB3;
      char*        command_string;
      unsigned int is_a_write;
      unsigned int gemroc_cmd_code;
      unsigned int command_words[12]; } __attribute__((packed));

struct DAQ_para {
      unsigned int TARGET_GEMROC_ID;
      unsigned int parameter_array[15];
      unsigned int EN_TM_TCAM_pattern;
      unsigned int TP_Pos_nNeg;
      unsigned int AUTO_TP_EN_pattern;
      unsigned int AUTO_L1_EN_pattern;
      unsigned int TL_nTM_ACQ;
      unsigned int Periodic_TP_EN_pattern;
      unsigned int TP_period ;
      unsigned int LowerDataScanWindowOffset;
      unsigned int Periodic_L1_EN_pattern;
      unsigned int L1_period;
      unsigned int UpperDataScanWindowOffset;
      unsigned int TP_width;
      unsigned int L1_latency;
      unsigned int UDP_DATA_DESTINATION_IPPORT;
      unsigned int UDP_DATA_DESTINATION_IPADDR;
      char*        command_string;
      unsigned int target_TCAM_ID;
      unsigned int to_ALL_TCAM_enable;
      unsigned int number_of_repetitions;

      unsigned int is_a_write;
      unsigned int gemroc_cmd_code;
      unsigned int command_words[5];  } __attribute__((packed));

      extern struct g_reg_para g_reg;
      extern struct ch_reg_para ch_reg;
      extern struct gemroc_para gemroc;
      extern struct DAQ_para DAQ;


      extern const int GEMROC_CMD_LV_Num_of_params;
      extern const int GEMROC_CMD_LV_Num_Of_PktWords;
      extern const int GEMROC_CMD_DAQ_Num_of_params;
      extern const int GEMROC_CMD_DAQ_Num_Of_PktWords;
      extern const unsigned int command_code_shift ;
      extern const unsigned int target_TIGER_ID_shift;
      extern unsigned int default_arg_needed;
      extern unsigned int TARGET_GEMROC_ID_param ;
      extern unsigned int TARGET_FEB_PWR_PATTERN_param ;
      extern const unsigned int IVT_LOG_PERIOD_SECONDS ;
      extern unsigned int IVT_LOG_ENABLE ;
      extern unsigned int GEMROC_ID;
      extern unsigned int FEB_PWR_EN_pattern;

      extern char DEST_IP_ADDRESS[14];
      extern unsigned int DEST_PORT_NO ;
      extern int sin_len;
      extern int socket_descriptor,socket_descriptor1;
      extern struct sockaddr_in sin_dest,send_addr,recv_addr;

      extern char line[128];
      extern char cmd_string[32];
      extern unsigned int cmd_para[10];
      extern int    sockfd;
      extern struct sockaddr_in    servaddr;

      extern const unsigned int g_reg_array[37];
      extern const unsigned int ch_reg_array[30];
      extern const unsigned int gemroc_array[31];
      extern const unsigned int DAQ_array[15];
      extern const char   gemroc_command_list[6][32] ;
      extern const char   DAQ_command_list[10][35];


#endif 
