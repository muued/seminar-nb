#include <stdio.h>
#include <float.h>
#include <nag.h>
#include <nag_stdlib.h>
#include <nagg01.h>
#include <nagg08.h>

int main(void)
{
	NagError fail;
	INIT_FAIL(fail);

	Integer n = 20, nclass = 4;
	double x[] = {14.6, 15.4, 15.2, 15.8, 17.3, 18.0, 18.7, 19.5, 19.7, 19.9, 20.1, 21.1, 21.7, 22.6, 23.1, 23.2, 24.4, 24.7, 24.8, 25.3};
	Integer *ifreq = 0;

	// Paul's values
	double par[] = {20.0, 11.0};
	double cint[] = {20-sqrt(11)*0.6745, 20, 20+sqrt(11)*0.6745};
	Integer npest = 0;

	// parameters
	double chisq, *chisqi = 0, *eval = 0, p, *prob;

	if (!(ifreq = NAG_ALLOC(nclass, Integer))
			|| !(chisqi = NAG_ALLOC(nclass, double))
			|| !(eval = NAG_ALLOC(nclass, double))
			|| !(prob = NAG_ALLOC(nclass, double)))
	{
		printf("Allocation failure\n");
		return -1;
	}

	{
		double xmin, xmax;
		nag_frequency_table(n, x, nclass, Nag_ClassBoundaryUser, cint, ifreq, &xmin, &xmax, &fail);
		if (fail.code != NE_NOERROR)
		{
			printf("Error from nag_frequency_table (g01aec).\n%s\n", fail.message);
			return 1;
		}
		Integer ndf;
		nag_chi_sq_goodness_of_fit_test(nclass, ifreq, cint, Nag_Normal, par, npest, prob, &chisq, &p, &ndf, eval, chisqi, &fail);
		if (fail.code != NE_NOERROR)
		{
			printf("Error from nag_chi_sq_goodness_of_fit_test (g08cgc).\n%s\n",fail.message);
			return 1;
		}
		printf("Paul's hypothesis is ");
		if (6.251389 > chisq) {
			printf("not ");
		}
		printf("rejected!\n");
	}

	// Fritz's values
	par[0] = 20.26;
	par[1] = 11.297;
	cint[0] = 20.26-sqrt(11.297)*0.6745;
	cint[1] = 20.26;
	cint[2] = 20.26+sqrt(11.297)*0.6745;
	npest = 2;

	{
		double xmin, xmax;
		nag_frequency_table(n, x, nclass, Nag_ClassBoundaryUser, cint, ifreq, &xmin, &xmax, &fail);
		if (fail.code != NE_NOERROR)
		{
			printf("Error from nag_frequency_table (g01aec).\n%s\n", fail.message);
			return 1;
		}
		Integer ndf;
		nag_chi_sq_goodness_of_fit_test(nclass, ifreq, cint, Nag_Normal, par, npest, prob, &chisq, &p, &ndf, eval, chisqi, &fail);
		if (fail.code != NE_NOERROR)
		{
			printf("Error from nag_chi_sq_goodness_of_fit_test (g08cgc).\n%s\n",fail.message);
			return 1;
		}
		printf("Fritz's hypothesis is ");
		if (2.705543 > chisq) {
			printf("not ");
		}
		printf("rejected!\n");
	}
}

