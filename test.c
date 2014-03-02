/* test file for FrCuba */

#include <stdio.h>
#include <stdlib.h>
#include <frcuba.h>

static int integral_kernel(const int * ndim, const double x[],
        const int * ncomp, double f[], void * p)
{
    int         i;

    *f = x[0];

    for (i = 1; i < *ndim; ++ i)
        *f *= x[i];

    return 0;
}

int main(void)
{
    cuba_inte_info cii;

    puts("The answer should be 0.25.");

    init_cuba_inte_info(&cii, 2, 1);

    cii.integrand = integral_kernel;
    cii.userdata = NULL;
    cii.nvec = 1;
    cii.epsrel = 1e-7;
    cii.epsabs = 0;
    cii.flags = 0;
    cii.mineval = 1;
    cii.maxeval = 10000;
    cii.key = 9;
    cii.statefile = "inte_tmp";

    FR_Cuhre(&cii);

    printf("Cuhre: %f\n", *cii.out.integral);

    destroy_cuba_inte_info(&cii);
    return 0;
}
