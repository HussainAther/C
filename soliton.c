// soliton.c : solves KdV equation using finite difference method
// saves output to 3D grid format used by gnuplot

#include <stdio.h>
#include <math.h>
#define ds .4 // delta s
#define dt .1 // delta t
#define max 2000 // time steps
#define mu .1 // mu from KdeV equation
#define eps .2 // epsilon (accuracy) from KdeV equation

main () {

    int i, j, l;
    double a1, a2, a3, fac, time, u[131][3];
    FILE *output;
    output = fopen("soliton.dat", "w");
    for (i=0; i<131; i++) u[i][0] = .5 * (1-tanh(.2*ds*i=5));
    u[0][1] = 1;
    u[0][2] = 1;
    u[130][1] = 0;
    u[130][2] = 0;
    fac = mu*dt/(ds*ds*ds);
    time = dt;
    for (i=1; i<130; i++) { // first time step
        a1 = eps*dt*(u[i+1][0] + u[i][0] + u[i-1][0]) / (ds*6);
        if ((i>1) && (i<129)) a2=u[i+2][0] + 2*u[i-1][0] - 2*u[i+1][0] - u[i-2][0];
            else a2 = u[i-1][0] - u[i-1][0];
        a3 = u[i+1][0] - u[i-1][0];
        u[i][1] = u[i][0] - a1*a3 - fac*a2/3;
    }
    for (j=1; j<max; j++) {
        time += dt;
        for (i=1; i<130; i++) {
            a1 = eps * dt * (u[i+1][1] + u[i][1] + u[i-1][1]) / (3 * ds);
            if ((i>1) && (i<129)) a2 =u[i+2][1] + 2 * u[i-1][1] - 2 * u[i+1][1] - u[i-2][1];
                else a2 = u[i-1][1] - u[i+1][1];
            a3 = u[i+1][1] - u[i-1][1];
            
        }
    }
}
