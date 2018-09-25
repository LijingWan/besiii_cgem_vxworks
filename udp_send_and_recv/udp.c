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
   
   unsigned char buff[48];
   int sin_len;
   int socket_descriptor,socket_descriptor1;
   struct sockaddr_in sin_dest,send_addr,recv_addr;
   int i,j=0;
   

   
     
    bzero(&sin_dest,sizeof(sin_dest));
    sin_dest.sin_family=AF_INET;
    sin_dest.sin_addr.s_addr=inet_addr("192.168.1.200");
    sin_dest.sin_port=htons(58913);
    sin_len=sizeof(sin_dest);

    bzero(&send_addr,sizeof(send_addr));
    send_addr.sin_family=AF_INET;
    send_addr.sin_addr.s_addr=inet_addr("192.168.1.201");
    send_addr.sin_port=htons(54820);
    socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);
    bind(socket_descriptor,(struct sockaddr *)&send_addr,sizeof(send_addr)); 

    bzero(&recv_addr,sizeof(recv_addr));
    recv_addr.sin_family=AF_INET;
    recv_addr.sin_addr.s_addr=inet_addr("192.168.1.201");
    recv_addr.sin_port=htons(58916);
    socket_descriptor1=socket(AF_INET,SOCK_DGRAM,0);
    bind(socket_descriptor1,(struct sockaddr *)&recv_addr,sizeof(recv_addr));
   

   
   i=0;
   while(i<10)
   { i=i+1;
     for(j=0;j<48;j++)
       buff[j]=i+j;
    sendto(socket_descriptor,buff,48,0,(struct sockaddr *)&sin_dest,sin_len);
    recvfrom(socket_descriptor1,buff,48,0,NULL,NULL);
    printf("recv : i=%d\n",i);
    
   }
   close(socket_descriptor);
   close(socket_descriptor1);
   printf("finished\n");
   
}
                               