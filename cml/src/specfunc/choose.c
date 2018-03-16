#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <cml/errno.h>
#include <cml/math.h>
#include <cml/specfunc.h>


/**
 * Compute the binomial coefficient
 *
 *      / n \        n!
 *      |   |  = ---------
 *      \ k /    k! (n-k)!
 *
 * @param double n a non-negative integer
 * @param double p a non-negative integer smaller that n
 *
 * @return double
 */
double cml_sf_choose(int n, int p)
{
        int k = CML_MAX(p, n - p);

        if (n - p < 0 || n < 0 || p < 0)
        {
                return 0.0;
        }

        if (k < MAX_INT_FACT_ARG)
        {
                return cml_sf_fact((double) n) /
                       (cml_sf_fact((double) p) * cml_sf_fact((double) (n - p)));
        }

        double ln_choose = cml_sf_lnfact(n + 1) - cml_sf_lnfact(p + 1)
                           - cml_sf_lnfact(n - p + 1);

        return cml_exp(ln_choose);

}
