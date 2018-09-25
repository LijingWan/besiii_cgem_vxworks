#include "vxWorks.h"
#include "inetLib.h"
#include "stdioLib.h"
#include "sockLib.h"
#include "taskLib.h"
#include "strLib.h"
#include "hostLib.h"
#include "ioLib.h"

void udp()
{
   unsigned char buff[512];
   int i,j,data_len;
   
   long long H1;
  
   
   int port;
   int sin_len;
   int socket_descriptor;
   struct sockaddr_in sin,cliaddr; 
   port=58914;

   
   bzero(&sin,sizeof(sin));
   sin.sin_family=AF_INET;
   sin.sin_addr.s_addr=inet_addr("192.168.1.201");
   sin.sin_port=htons(port);
   sin_len=sizeof(sin);
   socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);
   bind(socket_descriptor,(struct sockaddr *)&sin,sizeof(sin));
   
   data_len=recvfrom(socket_descriptor,buff,512,0,(struct sockaddr *)&cliaddr,&sin_len);
   printf("receive %d bytes data from:%s,port:%d\n",data_len,inet_ntoa(cliaddr.sin_addr),cliaddr.sin_port);
   
    for(i=0;i<data_len-6;i=i+8)
     {
       H1=0;
       for(j=i+7;j>i;j--)
       {
         H1=H1+buff[j];
         H1=H1<<8;
       }
       H1=H1+buff[j];
       printf("H1=%016X,%08X %08X\n",H1,H1>>32,H1&0xffffffff);
     }
   printf("exit.\n");                                      
   close(socket_descriptor);
}
                   