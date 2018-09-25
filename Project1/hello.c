#include <stdio.h>

#include <vxworks.h>

int firstTest(void)

{

  printf("Thisis firstTest\n");

}

void helloWorld()

{

  printf("Thisis helloWorld\n");

}
void int64_test()
{
   int a;
   long b;
   long long c;
   a=0x1234567810105622;
   b=0x1234567810105622;
   c=0x1234567810105622;
   printf("a= %x =%x %x \n",a,a>>32,a&0xffffffff);
   printf("b= %x =%x %x \n",b,b>>32,b&0xffffffff);
   printf("a= %x =%x %x \n",c,c>>32,c&0xffffffff);


}