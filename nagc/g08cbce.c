/* nag_1_sample_ks_test (g08cbc) Example Program.
 *
 * Copyright 2000 Numerical Algorithms Group.
 *
 * Mark 6, 2000.
 */

#include <stdio.h>
#include <nag.h>
#include <nag_stdlib.h>
#include <nagg08.h>

int main(void)
{
  Integer            exit_status = 0;
  Integer            i, n, np;
  double             d, p, *par = 0, *x = 0, z;
  char               nag_enum_arg[40];
  Nag_TestStatistics ntype;
  NagError           fail;

  INIT_FAIL(fail);

  printf("nag_1_sample_ks_test (g08cbc) Example Program Results\n");

  /* Skip heading in data file */
  scanf("%*[^\n]");

  scanf("%"NAG_IFMT"", &n);
  x = NAG_ALLOC(n, double);

  printf("\n");
  for (i = 1; i <= n; ++i)
    scanf("%lf", &x[i - 1]);
  scanf("%"NAG_IFMT"", &np);
  if (!(par = NAG_ALLOC(np, double)))
    {
      printf("Allocation failure\n");
      exit_status = -1;
      goto END;
    }

  for (i = 1; i <= np; ++i)
    scanf("%lf", &par[i - 1]);
  scanf("%s", nag_enum_arg);
  /* nag_enum_name_to_value(x04nac).
   * Converts NAG enum member name to value
   */
  ntype = (Nag_TestStatistics) nag_enum_name_to_value(nag_enum_arg);

  /* nag_1_sample_ks_test (g08cbc).
   * Performs the one-sample Kolmogorov-Smirnov test for
   * standard distributions
   */
  nag_1_sample_ks_test(n, x, Nag_Uniform, par, Nag_ParaSupplied, ntype, &d,
                       &z, &p, &fail);
  if (fail.code != NE_NOERROR)
    {
      printf("Error from nag_1_sample_ks_test (g08cbc).\n%s\n",
              fail.message);
      exit_status = 1;
      goto END;
    }
  printf("Test against uniform distribution on (0,2)\n");
  printf("\n");
  printf("Test statistic D = %8.4f\n", d);
  printf("Z statistic      = %8.4f\n", z);
  printf("Tail probability = %8.4f\n", p);
  printf("\n");
  scanf("%"NAG_IFMT"", &np);
  for (i = 1; i <= np; ++i)
    scanf("%lf", &par[i - 1]);
  scanf("%s", nag_enum_arg);
  ntype = (Nag_TestStatistics) nag_enum_name_to_value(nag_enum_arg);

  /* nag_1_sample_ks_test (g08cbc), see above. */
  nag_1_sample_ks_test(n, x, Nag_Normal, par, Nag_ParaEstimated, ntype, &d,
                       &z, &p, &fail);
  if (fail.code != NE_NOERROR)
    {
      printf("Error from nag_1_sample_ks_test (g08cbc).\n%s\n",
              fail.message);
      exit_status = 1;
      goto END;
    }

  printf("Test against Normal distribution with parameters estimated"
          " from the data\n\n");
  printf("Mean = %6.4f  and variance = %6.4f\n", par[0], par[1]);
  printf("Test statistic D = %8.4f\n", d);
  printf("Z statistic      = %8.4f\n", z);
  printf("Tail probability = %8.4f\n", p);

 END:
  if (x) NAG_FREE(x);
  if (par) NAG_FREE(par);

  return exit_status;
}
