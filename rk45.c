// rk45.c: Solve ordinary differential equations of the RUnge-Kutta-Fehlberg Method with
// variations in step size.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {

    FILE *output;
    out1 = fopen("rk45.dat", "w"); // output file name
    
    double h, t, s, s1, hmin, hmax;
    double y[2], fReturn[2], ydumb[2];
    double k1[2], k2[2], k3[2];
    double k4[2], k5[2], k6[2];
    double err[2];
    double Tol = 1.0E-8; // error control tlerance
    double a = 0; // endpoints in calculation
    double b = 10;
    int i, j, n = 20;
    void f(double t, double y[], double fReturn[]);
    
    y[0] = 1; y[1] = 0;
    h = (b-a)/n;
    hmin = h/64;
    hmax = h*64;
    t = a;
    j = 0;
    fprintf(out1, "%f\t%f\t%f\n", t, y[0], y[1]); // output to file
    
    while (t<b) {
        if ((t + h) > b) h = b - t; // last step
        f(t, y, fReturn);
        k1[0] = h*fReturn[0];
        k1[1] = h*fReturn[1];
        
        for (i=0; i<=1;i++) ydumb[i] = y[i] + k1[i]/4;
        f(t + h/4, ydumb, fReturn);
        k2[0] = h*fReturn[0];
        k2[1] = h*fReturn[1];
        
        for (i=0; i<=1;i++) ydumb[i] = y[i] + 3*k1[i]/32 + 9*k2[i]/32;
        f(t + 3*h/8, ydumb, fReturn);
        k3[0] = h*fReturn[0];
        k3[1] = h*fReturn[1];
        
        for (i=0; i<=1;i++) ydumb[i] = y[i] + 1932*k1[i]/2197 - 7200*k2[i]/2197 + 7296*k3[i]/2197;
        f(t + 12*h/13, ydumb, fReturn);
        k4[0] = h*fReturn[0];
        k4[1] = h*fReturn[1];
    }
}
