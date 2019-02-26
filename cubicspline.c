// cubespline.c: cubic spline fit to data bsaed on input array
// x[n], y[n] = tabulation function y(x), x0 < 1,
// output yout for given xout yp1 and ypn: 1st derivatives at endpoints,
// evaluated internally, y2[n]: array of 2nd derivatievs

#include <stdio.h>
#include <math.h>
#define n 9
#define np 15
#define Nfit 3000 // enter number of points to fit

main() {

    FILE *output1, *output2;
    output1 = fopen("Spline.dat", "w");
    output2 = fopen("Input.dat", "w");
    // input data, enter data here
    double x[] = {0, .12, .25, .37, .5, .62, .75, .87, .99};
    double y[] = {108.6, 16., 845, 883.5, 52.8, 19.9, 10.8, 88.25, 84.7};
    double xout, yout;
    double y2[0];
    int i, klo, khi, k;
    double h, b, a, p, qn, sig, un, yp1, ypn, u[n];
}
