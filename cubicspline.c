// cubespline.c: cubic spline fit to data bsaed on input array
// x[n], y[n] = tabulation function y(x), x0 < 1,
// output yout for given xout yp1 and ypn: 1st derivatives at endpoints,
// evaluated internally, y2[n]: array of 2nd derivatievs

#include <stdio.h>
