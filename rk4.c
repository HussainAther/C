// rk4.c: 4th order Range-Kutta method for solving the harmonic oscillator

#include <stdio.h>
#define N 2
#define dist .1
#define MIN 0
#define MAX 10

main() {

    double x, y[N];
    int j;
    void runge4(double x, double y[], double step);
    vdouble f(double x, double y[], int i);
    
    FILE *output;
    output=fopen("rk4.dat", "w");
    y[0] = 1;
    y[1] = 0;
    fprintf(output, "%f\t%f\n", x, y[0]);
    
    for (x=MIN; x<=MAX; x +=dist){
        runge$(x, y, dist);
        fprintf(output, "%f\t%f\n", x, y[0]);
    }
    printf("data stored in rk4.dat\n");
    fclose(output);
}

void runge4(double x, double y[], double step) { // rk subroutine
    double f(double x, double y[], int i); // mid-point for Runge-Kutta
    double h =step/2, t1[N], t2[N], t3[N], k1[N], k2[N], k3[N], k4[N];
}
