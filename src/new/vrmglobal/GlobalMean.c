/*
** general linear regression using pre-coloring
**
**
** G.Lohmann, Nov 2004
*/

#include <viaio/Vlib.h>
#include <viaio/VImage.h>
#include <viaio/mu.h>
#include <viaio/option.h>
#include <viaio/headerinfo.h>

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <gsl/gsl_cblas.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl_utils.h>


#define NSLICES 2500   /* max number of image slices */


/*
** get global mean per time step
*/
gsl_vector_float *
VGlobalMean(VAttrList list, VShort minval, VImage mask) {
    VAttrListPosn posn;
    int nslices = 0, nbands = 0, nrows = 0, ncols = 0, slice, row, col;
    VImage xsrc, src[NSLICES];
    int   i, k, m = 0;
    double x, y, sum = 0, nx = 0, mean = 0;
    double sum1, sum2, sigma, *ptr;
    gsl_vector *z;
    gsl_vector_float *mean_vec = NULL;
    gsl_set_error_handler_off();
    /* get image dimensions */
    m = k = nbands = nrows = ncols = nslices = 0;
    for(VFirstAttr(list, & posn); VAttrExists(& posn); VNextAttr(& posn)) {
        if(VGetAttrRepn(& posn) != VImageRepn)
            continue;
        VGetAttrValue(& posn, NULL, VImageRepn, & xsrc);
        if(VPixelRepn(xsrc) != VShortRepn)
            continue;
        if(VImageNBands(xsrc) > nbands)
            nbands = VImageNBands(xsrc);
        if(VImageNRows(xsrc) > nrows)
            nrows = VImageNRows(xsrc);
        if(VImageNColumns(xsrc) > ncols)
            ncols = VImageNColumns(xsrc);
        src[k] = xsrc;
        if(k >= NSLICES)
            VError(" too many slices, max is %d", NSLICES);
        k++;
    }
    nslices = k;
    m = nbands;
    z = gsl_vector_calloc(m);
    for(i = 0; i < m; i++) {
        sum = nx = 0;
        for(slice = 0; slice < nslices; slice++) {
            if(VImageNRows(src[slice]) < 2)
                continue;
            for(row = 1; row < nrows - 1; row++) {
                for(col = 1; col < ncols - 1; col++) {
                    if(VPixel(src[slice], 0, row, col, VShort) < minval)
                        continue;
                    if(mask && VGetPixel(mask, slice, row, col) < 0.5)
                        continue;
                    x = VPixel(src[slice], i, row, col, VShort);
                    sum  += x;
                    nx++;
                }
            }
        }
        mean = sum / nx;
        gsl_vector_set(z, i, mean);
    }
    /* normalize */
    sum1 = sum2 = nx = 0;
    ptr = z->data;
    for(i = 0; i < m; i++) {
        x = *ptr++;
        sum1 += x;
        sum2 += x * x;
        nx++;
    }
    mean = sum1 / nx;
    sigma = sqrt((double)((sum2 - nx * mean * mean) / (nx - 1.0)));
    mean_vec = gsl_vector_float_calloc(m);
    ptr = z->data;
    for(i = 0; i < m; i++) {
        x = (double)(*ptr++);
        y = (x - mean) / sigma;
        gsl_vector_float_set(mean_vec, i, (float)y);
    }
    return mean_vec;
}



