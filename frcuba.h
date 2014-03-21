/* A more friendly user interface to the Cuba integration library */

#ifndef FRCUBA_H__

#define FRCUBA_H__


#include <cuba.h>


#ifdef __cplusplus
extern "C" {
#endif
/*
 * Please refer the manual of Cuba to see the meaning of each member of this
 * structure.
 */
typedef struct struct_cuba_inte_info
{
    int             ndim;
    int             ncomp;

    integrand_t     integrand;
    void*           userdata;
    int             nvec;
    double          epsrel;
    double          epsabs;
    int             flags;
    int             seed;
    int             mineval;
    int             maxeval;
    const char*     statefile;

    /* Vegas specific options */
    struct
    {
        int             nstart;
        int             nincrease;
        int             nbatch;
        int             gridno;
    } vegas;

    /* Divonne specific options */
    struct
    {
        int             key1;
        int             key2;
        int             key3;
        int             maxpass;
        double          border;
        double          maxchisq;
        double          mindeviation;
        int             ngiven;
        int             ldxgiven;
        double *        xgiven;
        int             nextra;
        peakfinder_t    peakfinder;
    } divonne;

    /* Suave specific options */
    struct
    {
        int             nnew;
        double          flatness;
    } suave;

    /* Cuhre specific options */
    struct
    {
        int             key;
    } cuhre;

    /* Output. */
    struct
    {
        int             nregions;
        int             neval;
        int             fail;
        double *        integral;
        double *        error;
        double *        prob;
    } out;
} cuba_inte_info;

cuba_inte_info * init_cuba_inte_info(cuba_inte_info * cii);
void FR_Cuhre(cuba_inte_info * cii);
void FR_Vegas(cuba_inte_info * cii);
void FR_Suave(cuba_inte_info * cii);
void FR_Divonne(cuba_inte_info * cii);

#ifdef __cplusplus
}
#endif

#endif /* end of include guard: FRCUBA_H__ */
