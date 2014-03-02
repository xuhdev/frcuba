#include <stdlib.h>
#include <string.h>
#include "frcuba.h"

/* Initialize a cuba_inte_info object */
cuba_inte_info * init_cuba_inte_info(cuba_inte_info * cii, int ndim, int ncomp)
{
    int         i;

    /* zero the memory first */
    memset(cii, 0, sizeof(cuba_inte_info));

    /* allocate space for integral, error, prob, limit_low, and limit_high*/
    cii->dim.ndim = ndim;
    cii->dim.ncomp = ncomp;
    cii->out.integral = (double *) calloc(ncomp, sizeof(double));
    cii->out.error = (double *) calloc(ncomp, sizeof(double));
    cii->out.prob = (double *) calloc(ncomp, sizeof(double));

    return cii;
}


/* Finalize a cuba_inte_info object */
void destroy_cuba_inte_info(cuba_inte_info * cii)
{
    free(cii->out.integral);
    free(cii->out.error);
    free(cii->out.prob);
}


/* Cuhre, using cuba_inte_info */
void FR_Cuhre(cuba_inte_info * cii)
{
    Cuhre(cii->dim.ndim, cii->dim.ncomp, cii->integrand, cii->userdata, cii->nvec,
            cii->epsrel, cii->epsabs, cii->flags, cii->mineval, cii->maxeval,
            cii->key, cii->statefile, &cii->out.nregions, &cii->out.neval, &cii->out.fail,
            cii->out.integral, cii->out.error, cii->out.prob);
}
