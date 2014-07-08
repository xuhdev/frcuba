/* test file for FrCuba */

#include <stdio.h>
#include <stdlib.h>
#include <frcuba.h>

#define NDIM  2

/*
 * Integral kernel x1^2 x2^2 ... xi^2 ... xn^2 from limits[2*i] to limits[2*i+1]
 */
static int integral_kernel(const int * ndim, const double x[],
        const int * ncomp, double f[], void * p)
{
    int         i;
    double *    limits = p;
    double *    w = (double *) calloc(*ndim, sizeof(double));

    for (i = 0; i < *ndim; ++ i)
        w[i] = x[i] * (limits[2 * i + 1] - limits[2 * i]) + limits[2 * i];

    *f = w[0] * w[0];

    for (i = 1; i < *ndim; ++ i)
        *f *= w[i] * w[i];

    for (i = 0; i < *ndim; ++ i)
        *f *= (limits[2 * i + 1] - limits[2 * i]);

    free(w);

    return 0;
}

/* empty peak finder */
static void peakfinder(const int * ndim, const double b[], int * n, double x[])
{
    /* do nothing */
}

int main(void)
{
    cuba_inte_info cii;
    double         integral, error, prob;
    double         limits[4] = {-1.0, 1.0, -1.0, 1.0};

    puts("The answer should be 4/9.");

    init_cuba_inte_info(&cii);

    cii.ndim = NDIM;
    cii.ncomp = 1;
    cii.integrand = integral_kernel;
    cii.userdata = limits;
    cii.nvec = 1;
    cii.epsrel = 1e-2;
    cii.epsabs = 0;
    cii.flags = 0;
    cii.mineval = 1;
    cii.maxeval = 10000000;
    cii.statefile = "inte_tmp";
    cii.out.integral = &integral;
    cii.out.error = &error;
    cii.out.prob = &prob;

    cii.statefile = "inte-tmp-cuhre";
    cii.cuhre.key = 9;
    FR_Cuhre(&cii);
    printf("Cuhre: integral: %e\terror: %e\tprob: %e\tfail: %d\n", integral, error, prob, cii.out.fail);

    cii.statefile = "inte-tmp-vegas";
    cii.vegas.gridno = 0;
    cii.vegas.nstart = 1000;
    cii.vegas.nincrease = 500;
    cii.vegas.nbatch = 1000;
    FR_Vegas(&cii);
    printf("Vegas: integral: %e\terror: %e\tprob: %e\tfail: %d\n", integral, error, prob, cii.out.fail);

    cii.statefile = "inte-tmp-suave";
    cii.suave.nnew = 1000;
    cii.suave.flatness = 50;
    FR_Suave(&cii);
    printf("Suave: integral: %e\terror: %e\tprob: %e\tfail: %d\n", integral, error, prob, cii.out.fail);

    cii.statefile = "inte-tmp-divonne";
    cii.divonne.key1 = 9;
    cii.divonne.key2 = 9;
    cii.divonne.key3 = 1;
    cii.divonne.maxpass = 5;
    cii.divonne.border = 0;
    cii.divonne.maxchisq = 10;
    cii.divonne.mindeviation = 0.25;
    cii.divonne.ngiven = 0;
    cii.divonne.xgiven = 0;
    cii.divonne.xgiven = NULL;
    cii.divonne.nextra = 0;
    cii.divonne.peakfinder = peakfinder;

    FR_Divonne(&cii);
    printf("Divonne: integral: %e\terror: %e\tprob: %e\tfail: %d\n", integral, error, prob, cii.out.fail);

    return 0;
}
