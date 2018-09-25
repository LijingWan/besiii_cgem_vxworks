#ifndef SD_CGEM_RUNTASKS_H_INCLUDED
#define SD_CGEM_RUNTASKS_H_INCLUDED
void  	cgemDataPack();

int cgemEnteringCbltTrans(int nArg);

int cgemBeforeInterrupt(int nArg);

int cgemBeforeDMARun(int nArg);

int cgemAfterDMARun(int nArg);


#endif // SD_CGEM_RUNTASKS_H_INCLUDED
