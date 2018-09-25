#include "vxWorks.h"
#include "inetLib.h"
#include "stdioLib.h"
#include "sockLib.h"
#include "taskLib.h"
#include "strLib.h"
#include "hostLib.h"
#include "ioLib.h"
#include "time.h"

void udp()
{
   
   unsigned char buff[128];
   int i,j=0;
   int port=58914;

   int sin_len;
   int socket_descriptor;
   struct sockaddr_in sin,cliaddr;
   bzero(&sin,sizeof(sin));
   sin.sin_family=AF_INET;
   sin.sin_addr.s_addr=inet_addr("192.168.1.201");
   sin.sin_port=htons(port);
   sin_len=sizeof(sin);
   socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);
   bind(socket_descriptor,(struct sockaddr *)&sin,sizeof(sin));
   i=0;
   while(i<100)
   {
     j=recvfrom(socket_descriptor,buff,128,0,(struct sockaddr *)&cliaddr,&sin_len);
     buff[j]=0;
     i++;
     printf("i=%d\n",i);
     printf("receive data from:%s,port:%d\n",inet_ntoa(cliaddr.sin_addr),cliaddr.sin_port);
     printf("%s\n",buff);
   }
   
   printf("finished\n");
   close(socket_descriptor);
}
                               