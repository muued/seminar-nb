/* nag_chi_sq_goodness_of_fit_test (g08cgc) Example Program.
 *
 * Copyright 2000 Numerical Algorithms Group.
 *
 * Mark 6, 2000.
 *
 * Mark 8 revised, 2004
 *
 */

#include <stdio.h>
#include <nag.h>
#include <nag_stdlib.h>
#include <nagg01.h>
#include <nagg05.h>
#include <nagg08.h>

int main(void)
{
  /* Integer scalar and array declarations */
  Integer           exit_status = 0, i, n, nclass, ndf, npest, lstate;
  Integer           *ifreq = 0, *state = 0;

  /* NAG structures */
  Nag_ClassBoundary class;
  Nag_Distributions cdist;
  NagError          fail;

  /* Double scalar and array declarations */
  double            chisq, *chisqi = 0, *cint = 0, *eval = 0, p, *par = 0;
  double            *prob = 0, *x = 0, xmax, xmin;

  /* Character array declarations */
  char              nag_enum_arg[40];

  /* Choose the base generator */
  Nag_BaseRNG       genid = Nag_Basic;
  Integer           subid = 0;

  /* Set the seed */
  Integer           seed[] = { 1762543 };
  Integer           lseed = 1;

  INIT_FAIL(fail);

  printf(
          "nag_chi_sq_goodness_of_fit_test (g08cgc) Example Program Results\n");

  /* Get the length of the state array */
  lstate = -1;
  nag_rand_init_repeatable(genid, subid, seed, lseed, state, &lstate, &fail);
  if (fail.code != NE_NOERROR)
    {
      printf("Error from nag_rand_init_repeatable (g05kfc).\n%s\n",
              fail.message);
      exit_status = 1;
      goto END;
    }

  /* Skip heading in data file */
  scanf("%*[^\n]");
  scanf("%"NAG_IFMT" %"NAG_IFMT"  %s %*[^\n] ", &n, &nclass,
         nag_enum_arg);

  /* nag_enum_name_to_value(x04nac).
   * Converts NAG enum member name to value
   */
  cdist = (Nag_Distributions) nag_enum_name_to_value(nag_enum_arg);

  if (!(x = NAG_ALLOC(n, double))
     || !(state = NAG_ALLOC(lstate, Integer))
     || !(cint = NAG_ALLOC(nclass-1, double))
     || !(par = NAG_ALLOC(2, double))
     || !(ifreq = NAG_ALLOC(nclass, Integer)))
    {
      printf("Allocation failure\n");
      exit_status = -1;
      goto END;
    }

  for (i = 1; i <= 2; ++i)
    scanf("%lf", &par[i - 1]);
  npest = 0;

  /* Initialise the generator to a repeatable sequence */
  nag_rand_init_repeatable(genid, subid, seed, lseed, state, &lstate, &fail);
  if (fail.code != NE_NOERROR)
    {
      printf("Error from nag_rand_init_repeatable (g05kfc).\n%s\n",
              fail.message);
      exit_status = 1;
      goto END;
    }

  /* Generate random numbers from a uniform distribution */
  nag_rand_uniform(n, par[0], par[1], state, x, &fail);
  if (fail.code != NE_NOERROR)
    {
      printf("Error from nag_rand_uniform (g05sqc).\n%s\n",
              fail.message);
      return 1;
    }

  class = Nag_ClassBoundaryComp;
  /* Determine suitable intervals */
  if (cdist == Nag_Uniform)
    {
      class = Nag_ClassBoundaryUser;
      cint[0] = par[0] + (par[1] - par[0]) / nclass;
      for (i = 2; i <= nclass - 1; ++i)
        cint[i - 1] = cint[i - 2] + (par[1] - par[0]) / nclass;
    }

  /* nag_frequency_table (g01aec).
   * Frequency table from raw data
   */
  nag_frequency_table(n, x, nclass, class, cint, ifreq, &xmin, &xmax,
                      &fail);
  if (fail.code != NE_NOERROR)
    {
      printf("Error from nag_frequency_table (g01aec).\n%s\n",
              fail.message);
      return 1;
    }

  if (!(chisqi = NAG_ALLOC(nclass, double))
     || !(eval = NAG_ALLOC(nclass, double))
     || !(prob = NAG_ALLOC(nclass, double)))
    {
      printf("Allocation failure\n");
      exit_status = -1;
      goto END;
    }
  /* nag_chi_sq_goodness_of_fit_test (g08cgc).
   * Performs the chi^2 goodness of fit test, for standard
   * continuous distributions
   */
  nag_chi_sq_goodness_of_fit_test(nclass, ifreq, cint, cdist, par, npest,
                                  prob, &chisq, &p, &ndf, eval, chisqi, &fail);
  if (fail.code != NE_NOERROR)
    {
      printf(
              "Error from nag_chi_sq_goodness_of_fit_test (g08cgc).\n%s\n",
              fail.message);
      exit_status = 1;
      goto END;
    }
  printf("\n");
  printf("%s%10.4f\n", "Chi-squared test statistic   = ", chisq);
  printf("%s%5"NAG_IFMT"\n", "Degrees of freedom.          = ", ndf);
  printf("%s%10.4f\n", "Significance level           = ", p);
  printf("\n");
  printf("%s\n", "The contributions to the test statistic are :-");
  for (i = 1; i <= nclass; ++i)
    printf("%10.4f\n", chisqi[i - 1]);
 END:
  if (x) NAG_FREE(x);
  if (cint) NAG_FREE(cint);
  if (par) NAG_FREE(par);
  if (ifreq) NAG_FREE(ifreq);
  if (chisqi) NAG_FREE(chisqi);
  if (eval) NAG_FREE(eval);
  if (prob) NAG_FREE(prob);
  if (state) NAG_FREE(state);
  return exit_status;
}
