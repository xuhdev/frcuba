/* A more friendly user interface to the Cuba integration library */

#ifndef FRCUBA_H__

#define FRCUBA_H__


#include <cuba.h>


/*
 * Please refer the manual of Cuba to see the meaning of each member of this
 * structure.
 */
typedef struct struct_cuba_inte_info
{
    struct
    {
        int             ndim;
        int             ncomp;
    } dim;

    integrand_t     integrand;
    void*           userdata;
    int             nvec;
    double          epsrel;
    double          epsabs;
    int             flags;
    int             seed;
    int             mineval;
    int             maxeval;
    int             key;
    int             nstart;
    int             nincrease;
    int             nbatch;
    int             gridno;
    const char*     statefile;

    /* Output. Should not be written by users. */
    struct
    {
        int             nregions;
        int             neval;
        int             fail;
        double*         integral;
        double*         error;
        double*         prob;
    } out;
} cuba_inte_info;

cuba_inte_info * init_cuba_inte_info(cuba_inte_info * cii, int ndim, int ncomp);
void destroy_cuba_inte_info(cuba_inte_info * cii);
void FR_Cuhre(cuba_inte_info * cii);



#endif /* end of include guard: FRCUBA_H__ */
