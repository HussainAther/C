// rk45.c: Solve ordinary differential equations of the RUnge-Kutta-Fehlberg Method with
// variations in step size.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {

    FILE *output;
    out1 = fopen("rk45.dat", "w");
    
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
    h = (b-a)/n
    
}
