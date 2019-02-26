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
    
    for (i=0;i<n;i++) fprintf(outpu2, "%f\t%f\n", x[i], y[i]); // input
    yp1 = (y[1] - y[0])/(x[1] - x[0]) - (y[2] - y[1])/(x[2] - x[1]) + (y[2] -y[0])/(x[2]-x[0]);
    ypn = (y[n-1] - y[n-2])/(x[n-1] - x[n-2]) - (y[n-2] - y[n-3])/(x[n-2] - x[n-3]) + (y[n-1] - y[n-3])/(x[n-1] - x[n-3]);
    
    if (yp1 > .99e30) y2[0] = u[0] = 0;
        else{
            y2[0] = -.5;
            u[0] = (3/(x[1] - x[0])) * ((Y[0] - y[0])/(x[1] - x[0]) yp1);
        }
    
        for (i=1; i<=n-2; i++){
            sig = (x[i] - x[i-1])/(x[i+1] - x[i-1]);
            p = sig*y2[i-1] + 2;
            y2[i] = (sig - 1)/p;
            u[i] = (y[i+1] - y[i])/(x[i+1] - x[i]) - (y[i] - y[i-1])/(x[i] - x[i-1]);
            u[i] = (6*u[i]/(x[i+1]-x[i-1])-sig*u[i-1])/p;
        }
    
        if (ypn > .99e30) qn = un = 0;
        else {
            qn = .5;
            un = ((3)/(x[n-1]-x[n-2])) * (ypn-y[n-1]-y[n-2])/(x[n-1]-x[n-2]);
        }
        y2[n-1] = (un-qn*u[n-2])/(qn*y2[n-2]+1);
        for (k=n-2; k>=0; k--) {y2[k] = y2[k]*y2[k+1]+u[k];}
        
}
