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
   
   unsigned char buff[1024];
   int i,j=0;
   int RecvLen;
   int loop=1;
   int Num;
   char c;

   int port=58914;
   int sin_len;
   int socket_descriptor;
   struct sockaddr_in sin,servaddr;
   bzero(&sin,sizeof(sin));
   sin.sin_family=AF_INET;
   sin.sin_addr.s_addr=inet_addr("192.168.1.201");
   sin.sin_port=htons(port);
   sin_len=sizeof(servaddr);
   socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);
   bind(socket_descriptor,(struct sockaddr *)&sin,sizeof(sin));

   i=0;
   RecvLen=0;
   Num=0;
   printf("Waiting for data.\n");
   while(loop)
   {
     RecvLen=RecvLen+recvfrom(socket_descriptor,buff,512,0,(struct sockaddr *)&servaddr,&sin_len);
     c=buff[1023];
     c++;
     if(buff[0]!=c)
         Num++;
     
     
     if(RecvLen>10485760)
     {
         printf("receive  %d  Mbytes from : %s , port:%d\n",RecvLen>>20,inet_ntoa(servaddr.sin_addr),servaddr.sin_port);
         printf("buff[0] = %d , buff[1023] = %d ,found missed times = %d.\n",buff[0],buff[1023],Num);
         RecvLen=0;
     }

     if(Num >1000)
        loop=0; 
      
     if(loop)
     for(i=512;i<1024;i++)
         buff[i]=buff[i-512]; 
       
       
   }
   

   printf("data missed and exit ,found missed times = %d.\n",Num);
   printf("buff[0] = %d , buff[1023] = %d .\n",buff[0],buff[1023]);
   close(socket_descriptor);
}
                               