
#include "vxWorks.h"

#include "fw_roppc.h"
#include "inetLib.h"
#include "sd_cgem.h"
#include "sd_cgem_cfg.h"
#include "fw_dcgvas.h"
#include "sd_cgem_actions.h"
#include "sd_cgem_runtasks.h"

      const int GEMROC_CMD_LV_Num_of_params=31;
      const int GEMROC_CMD_LV_Num_Of_PktWords = 12;
      const int GEMROC_CMD_DAQ_Num_of_params= 15;
      const int GEMROC_CMD_DAQ_Num_Of_PktWords= 5;
      const unsigned int command_code_shift = 11;
      const unsigned int target_TIGER_ID_shift = 8;
      unsigned int default_arg_needed = 0;
      unsigned int TARGET_GEMROC_ID_param = 0;
      unsigned int TARGET_FEB_PWR_PATTERN_param = 0;
      const unsigned int IVT_LOG_PERIOD_SECONDS = 20;
      unsigned int IVT_LOG_ENABLE = 1;
      unsigned int GEMROC_ID;
      unsigned int FEB_PWR_EN_pattern;

      char DEST_IP_ADDRESS[14];
      unsigned int DEST_PORT_NO ;
      int sin_len;
      int socket_descriptor,socket_descriptor1;
      struct sockaddr_in sin_dest,send_addr,recv_addr;

      char line[128];
      char cmd_string[32];
      unsigned int cmd_para[10];
      int    sockfd;
      struct sockaddr_in    servaddr;



      const unsigned int g_reg_array[37]={0, 0, 0, 55, 10, 30, 20, 0, 10, 7, 27, 8, 55, 0, 0, 55, 25, 15, 0, 26, 15, 39, 1, 0, 0, 9, 1, 6, 0, 0, 7, 0, 0, 0, 2, 0, 1};
      const unsigned int ch_reg_array[30]={1, 2, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 6, 6, 1, 0, 1, 1, 0, 0, 0, 0, 10, 31, 0, 0, 0, 0, 0};
      const unsigned int gemroc_array[31]={255, 511, 511, 255, 511, 511, 255, 511, 511, 255, 511, 511, 511, 511, 511, 511, 511, 511, 511, 511, 63, 0, 0, 0, 0, 0, 1, 10, 10, 10, 10};
      const unsigned int DAQ_array[15]={201, 2, 300, 8, 200, 256, 1, 100, 512, 1, 1, 0, 0, 1, 255};
      const char   gemroc_command_list[6][32] = {"NONE",
                            "CMD_GEMROC_LV_CFG_WR",
                            "CMD_GEMROC_LV_CFG_RD",
                            "CMD_GEMROC_LV_IVT_UPDATE",
                            "CMD_GEMROC_LV_IVT_READ",
                            "CMD_GEMROC_TIMING_DELAYS_UPDATE"};
      const char   DAQ_command_list[10][35] ={"NONE",
                            "CMD_GEMROC_DAQ_CFG_WR",
                            "CMD_GEMROC_DAQ_CFG_RD",
                            "CMD_GEMROC_DAQ_TIGER_GCFGREG_RESET",
                            "CMD_GEMROC_DAQ_TIGER_SYNCH_RST",
                            "CMD_GEMROC_DAQ_TCAM_SYNCH_RST",
                            "CMD_GEMROC_DAQ_TP_GEN",
                            "CMD_GEMROC_DAQ_L1_GEN",
                            "CMD_GEMROC_DAQ_ACK_SEQ_ERROR",
                            "CMD_GEMROC_DAQ_XCVR_LPBCK_TEST"};



struct g_reg_para g_reg;
struct ch_reg_para ch_reg;
struct gemroc_para gemroc;
struct DAQ_para DAQ;

void CGEMLinkRtns()
{
	g_pfnInitializedLOAD 	= cgemInitializedLOAD ;
  	g_pfnLoadedPRCF 		= cgemLoadedPRCF ;
  	g_pfnPreconfigedCONF 	= cgemPreconfigedCONF;
  	g_pfnConfigedSYN1 		= cgemConfigedSYN1 ;
  	g_pfnSynchronized1SYN2  = cgemSynchronized1SYN2 ;
  	g_pfnSynchronized2SYN3  = cgemSynchronized2SYN3 ;
  	g_pfnSynchronized3SYN4  = cgemSynchronized3SYN4 ;
  	g_pfnSynchronized4PREP  = cgemSynchronized4PREP ;
  	g_pfnReadySATR  		= cgemReadySATR;
  	g_pfnRunningSPTR  		= cgemRunningSPTR;
  	g_pfnReadySTOP  		= cgemReadySTOP;
  	g_pfnConfigedUNCF 		= cgemConfigedUNCF;
  	g_pfnPreconfigedUNPC 	= cgemPreconfigedUNPC ;
  	g_pfnLoadedUNLD 		= cgemLoadedUNLD;
  	g_pfnAnyEXIT 			= cgemAnyEXIT;


	g_pfnFWEnteringCbltTrans 	= cgemEnteringCbltTrans ;
	g_pfnFWBeforeInterrupt 		= cgemBeforeInterrupt ;
	g_pfnFWBeforeDMARun 		= cgemBeforeDMARun ;
	g_pfnFWAfterDMARun 		= cgemAfterDMARun ;

}

