void int64_test()
{
   int a;
   long b;
   long long c;
   a=0x1234567898765432;
   b=0x1234567898765432;
   c=0x1234567898765432;
   printf("int       a= %016x  =%x %x \n",a,a>>32,a&0xffffffff);
   printf("long      b= %016x  =%x %x \n",b,b>>32,b&0xffffffff);
   printf("long long c= %016x  =%x %x \n",c,c>>32,c&0xffffffff);


}