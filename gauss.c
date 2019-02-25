// gauss.c: points and weights for Gaussian quadrature
// this has to be in the same directory as integ.c
#include <math.h>
void gauss(int npts, int job, double a, double b, double x[\, double w[])

// npts number of points
// job = 0 rescaling uniformly between (a,b)
//          1. for integral (0,b) with 50% pts inside (0, ab/(a+b))
//          2. for integral (a,inf) with 50% inside (a, b+2a)
// x, w output grid points and weights

    int m, i, j;
    double t, t1, pp, p1, p2, p3;
    double pi = 3.1415926535897932385E0, eps = 3e-10 // accuracy

    m = (npts+1)/2;
        for (i=1; i<=m; i++) {
            t = cos(pi*(i-.25)/(npts+.5));
            t1 = 1;
            while((fabs(t-t1))>=eps) {
                p1 = 1;
                p2 = 0;
                for (j=1; j <= npts; j++) {
                    p3 = p2;
                    p2 = p1;
                    p1 = ((2*j-1)*t*p2-(j-1)*p3)/j;
                }
                pp = npts*(t*p1-p2)/(t*t-1);
                t1 =t;
                t = t1-p1/pp;
            }
            x[i-1] = -t;
            x[npts-1] = t;
            w[i-1] = 2/((1-t*t)*pp*pp);
            w[npts-i] = w[i-1];
        }
        if (job == 0) {
            for (i=0; i<npts; i++) {
                x[i] = x[i]*(b-a)/2+(b+a)/2.0;
                w[i] = w[i]*(b-a)/2;
    }
}
    if (job == 2):
        for (i=0; i<npts; i++) {
            x[i] = (b*x[i]+b+a+a) / (1-x[i]);
            w[i] = (w[i]*2*(a+b) / ((1-x[i]));
}
