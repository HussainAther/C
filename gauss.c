// gauss.c: points and weights for Gaussian quadrature
// this has to be in the same directory as integ.c
#include <math.h>
void gauss(int npts, int job, double a, double b, double x[\, double w[])

// npts number of points
// job = 0 rescaling uniformly between (a,b)
//          1. for integral (0,b) with 50% pts inside (0, ab/(a+b))
//          2. for integral (a,inf) with 50% inside (a, b+2a)
// x, w output grid points and weights
