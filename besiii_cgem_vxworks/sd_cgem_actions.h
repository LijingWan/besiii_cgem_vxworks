#ifndef SD_CGEM_ACTIONS_H_INCLUDED
#define SD_CGEM_ACTIONS_H_INCLUDED
int	    cgemInitializedLOAD 		(int nArg) ;
int  	cgemLoadedPRCF 			(int nArg) ;
int  	cgemPreconfigedCONF 		(int nArg) ;
int  	cgemConfigedSYN1 			(int nArg) ;
int  	cgemSynchronized1SYN2 	(int nArg) ;
int  	cgemSynchronized2SYN3 	(int nArg) ;
int  	cgemSynchronized3SYN4 	(int nArg) ;
int  	cgemSynchronized4PREP 	(int nArg) ;
int  	cgemReadySATR  			(int nArg) ;
int  	cgemRunningSPTR  			(int nArg) ;
int  	cgemReadySTOP  			(int nArg) ;
int  	cgemConfigedUNCF 		(int nArg) ;
int  	cgemPreconfigedUNPC 		(int nArg) ;
int  	cgemLoadedUNLD 			(int nArg) ;
int  	cgemAnyEXIT 			(int nArg) ;


#endif // SD_CGEM_ACTIONS_H_INCLUDED
