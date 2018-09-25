#include "vxWorks.h"
#include "inetLib.h"
#include "stdioLib.h"
#include "sockLib.h"
#include "taskLib.h"
#include "semLib.h"
#include "strLib.h"
#include "hostLib.h"
#include "ioLib.h"

#define g_nMaxCbltBytes 1024
SEM_ID	g_sidInterrupt=NULL ;
SEM_ID  BufSem=NULL;
int g_nBytesCblted=0;
char frombuff[1024];
char tobuff[1032];


int  UDPrun(char*frombuff,char*tobuff,int datalen);
void udp_recv();
void data_print();



int UDPrun(char*frombuff,char*tobuff,int datalen)
{
    int i;
    for(i=0;i<datalen;i++)
      tobuff[i]=frombuff[i];
    printf("UDPrun copy %d bytes.\n",datalen);
    return datalen;
}

void udp_recv()
{

   int i,j=0;
   int data_len;
   char n;
   int port=58915;
   int sin_lenx;
   int socket_descriptor;
   struct sockaddr_in sin,cli;
   bzero(&sin,sizeof(sin));
   sin.sin_family=AF_INET;
   sin.sin_addr.s_addr=inet_addr("192.168.1.201");
   sin.sin_port=htons(port);
   sin_lenx=sizeof(sin);
   socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);
   bind(socket_descriptor,(struct sockaddr *)&sin,sizeof(sin));

   printf("enter task: udp_recv.\n");

   while(1)
   {
     semTake(BufSem, WAIT_FOREVER) ;
     data_len=0;
     while(data_len < g_nMaxCbltBytes)
     {
       i=recvfrom(socket_descriptor,frombuff+data_len,g_nMaxCbltBytes-data_len,0,(struct sockaddr *)&cli,&sin_lenx);
       data_len+=i;
     }

    printf("receive  %d  bytes from : %s, port:%d\n",data_len,inet_ntoa(cli.sin_addr),cli.sin_port);
    g_nBytesCblted=data_len;
    semGive(BufSem);
   }
   close(socket_descriptor);
   printf("exit task: udp_recv.\n");
}



void data_print()
{
    int i;
    printf("enter task: data_print.\n");
    semGive(BufSem);
    while(1)
    {
 /**     semTake(g_sidInterrupt, WAIT_FOREVER);  **/
      semTake(BufSem, WAIT_FOREVER) ;
      g_nBytesCblted=UDPrun(frombuff,tobuff + 2 * 4 ,g_nBytesCblted);
      for(i=8;i<g_nBytesCblted+8;i=i+256)
        printf("  %d",tobuff[i]);
      printf("\n");
      semGive(BufSem);
    }
    printf("exit task: data_print.\n");

}


void hahaha()
{
    int taskid_1,taskid_2;
    BufSem = semBCreate(SEM_Q_FIFO , SEM_FULL );
    g_sidInterrupt= semCCreate(SEM_Q_FIFO, 0);
    semTake(BufSem, WAIT_FOREVER) ;
    taskid_1=taskSpawn("UDP_recv", 50, 0, 2048, (FUNCPTR)udp_recv,0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    taskid_2=taskSpawn("data_print", 50, 0, 2048, (FUNCPTR)data_print,0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    printf("task hahaha exit.\n");
}































