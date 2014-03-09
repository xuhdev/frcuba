#include <stdlib.h>
#include <string.h>
#include "frcuba.h"

/* Initialize a cuba_inte_info object */
cuba_inte_info * init_cuba_inte_info(cuba_inte_info * cii)
{
    /* zero the memory first */
    memset(cii, 0, sizeof(cuba_inte_info));

    return cii;
}


/* Cuhre, using cuba_inte_info */
void FR_Cuhre(cuba_inte_info * cii)
{
    Cuhre(cii->ndim,
            cii->ncomp,
            cii->integrand,
            cii->userdata,
            cii->nvec,
            cii->epsrel,
            cii->epsabs,
            cii->flags,
            cii->mineval,
            cii->maxeval,
            cii->cuhre.key,
            cii->statefile,
            &cii->out.nregions,
            &cii->out.neval,
            &cii->out.fail,
            cii->out.integral,
            cii->out.error,
            cii->out.prob);
}


/* Vegas, using cuba_inte_info */
void FR_Vegas(cuba_inte_info * cii)
{
    Vegas(cii->ndim,
            cii->ncomp,
            cii->integrand,
            cii->userdata,
            cii->nvec,
            cii->epsrel,
            cii->epsabs,
            cii->flags,
            cii->seed,
            cii->mineval,
            cii->maxeval,
            cii->vegas.nstart,
            cii->vegas.nincrease,
            cii->vegas.nbatch,
            cii->vegas.gridno,
            cii->statefile,
            &cii->out.neval,
            &cii->out.fail,
            cii->out.integral,
            cii->out.error,
            cii->out.prob);

    cii->out.nregions = 0;
}

/* Divonne, using cuba_inte_info */
void FR_Divonne(cuba_inte_info * cii)
{
    Divonne(cii->ndim,
            cii->ncomp,
            cii->integrand,
            cii->userdata,
            cii->nvec,
            cii->epsrel,
            cii->epsabs,
            cii->flags,
            cii->seed,
            cii->mineval,
            cii->maxeval,
            cii->divonne.key1,
            cii->divonne.key2,
            cii->divonne.key3,
            cii->divonne.maxpass,
            cii->divonne.border,
            cii->divonne.maxchisq,
            cii->divonne.mindeviation,
            cii->divonne.ngiven,
            cii->divonne.ldxgiven,
            cii->divonne.xgiven,
            cii->divonne.nextra,
            cii->divonne.peakfinder,
            cii->statefile,
            &cii->out.nregions,
            &cii->out.neval,
            &cii->out.fail,
            cii->out.integral,
            cii->out.error,
            cii->out.prob);

}

/* Suave, using cuba_inte_info */
void FR_Suave(cuba_inte_info * cii)
{
    Suave(cii->ndim,
            cii->ncomp,
            cii->integrand,
            cii->userdata,
            cii->nvec,
            cii->epsrel,
            cii->epsabs,
            cii->flags,
            cii->seed,
            cii->mineval,
            cii->maxeval,
            cii->suave.nnew,
            cii->suave.flatness,
            cii->statefile,
            &cii->out.nregions,
            &cii->out.neval,
            &cii->out.fail,
            cii->out.integral,
            cii->out.error,
            cii->out.prob);
}
