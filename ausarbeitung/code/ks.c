#include <stdio.h>
#include <nag.h>
#include <nag_stdlib.h>
#include <nagg08.h>

int main(void){
	int n = 20;
	double x[]={1, 1.1, 1.2, 1.6, 1.7, 2.1, 2.1, 2.4, 2.4, 2.5, 2.6, 2.6, 2.6, 2.7, 2.8, 3, 3.3, 3.5, 3.8, 4.2};
	Nag_Distributions dist = Nag_Normal;
	double par_franz[2]={3.5,1};
	double par_paul[2]={3,0.7};
	Nag_ParaEstimates estima = Nag_ParaSupplied;
	Nag_TestStatistics dtype = Nag_TestStatisticsDAbs;
	double d,z,p;
	NagError fail;
	
	INIT_FAIL(fail);
	
	nag_1_sample_ks_test(n,x,dist,par_franz,estima,dtype,&d,&z,&p,&fail);
	if (fail.code != NE_NOERROR){
		printf("Error from nag_1_sample_ks_test (g08cbc).\n%s\n",fail.message);
	}else{	
		printf("Franz' values:\n");
		printf("Statistic :%8.4f\n",d);
		printf("p-value :%8.4f\n",p);
	}
	printf(" \n");
	nag_1_sample_ks_test(n,x,dist,par_paul,estima,dtype,&d,&z,&p,&fail);
	if (fail.code != NE_NOERROR){
		printf("Error from nag_1_sample_ks_test (g08cbc).\n%s\n",fail.message);
	}else{	
		printf("Pauls values:\n");
		printf("Statistic :%8.4f\n",d);
		printf("p-value :%8.4f\n",p);
	}
	return 1;
}