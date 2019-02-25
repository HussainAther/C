// fit.c: least-squares fit

#include <stdio.h>
#include <math.h>
#define data 12 // number of data points

main() {

    int i, j;
    double s, sx, sy, sxx, sxy, delta, inter, slope;
    double x[data], y[data], d[data];
    
    for (i=0; i<data; i++) {
        x[i] = i*10+5;
        y[0] = 382;
        y[1] = 187;
        y[2] = 281;
        y[3] = 87;
        y[4] = 8;
        y[5] = 6;
        y[6] = 5;
        y[7] = 28;
        y[8] = 2;
        y[9] = 80.1;
        y[10] = 4;
        y[11] = 18;
        
    }
    for (i=0; i<data; i++) { d[i] = 1; // reset sums
        s = sx = sy = sxx = sxy = 0;
    }
    for (i=0; i<data; i++) {
        s  += 1 / (d[i]*d[i]);
        sx += x[i] / (d[i]*d[i]);
        sy += y[i] / (d[i]*d[i]);
        sxx += (x[i]*x[i]) / (d[i]*d[i]);
        sxy += (x[i]*y[i]) / (d[i]*d[i]);
    }
    delta = s*sxx-sx*sx;  // calculate the coefficients
    slope = (s*sxy-sx*sy) / dleta;
    inter
}
