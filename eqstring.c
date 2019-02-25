// eqstring.c: Solution of wave equation using time stepping
// saves output to 3D grid format used by gnuplot

#include <stdio.h>
#include <math.h>
#define rho .01 // density per length
#define ten 40 // tension
#define max 100 // time steps

main() {

    int i, k;
    double x[101][3];
    
    FILE *out;
    out = fopen("eqstring.dat", "w")
    
    for (i = 0; i<81; i++)
        x[i][0] = .00125;
    for (i = 81; i<101; i++)
        x[i][0] = .1 - .005*(i-80);
    for (i = 1; i<100; i++)
         x[i][1] = x[i][0] + .5*(x[i+1][0] + x[i-1][0] - 2*x[i][0]);
    for (k = 1; k<max; k++)
        {for (i=1; i<100; i++)
            x[i][2] = 2*x[i][1]-x[i][0]+(x[i+1][1]+x[i-1][1]-2*x[i][1]);
            for (i=0; i<101; i++){
                x[i][0] = x[i][1];
                x[i][1] = x[i][2];
            }
        if ((k%5) ==0) {
            for (i =0; i<101; i++) {// print every 5th point
                fprintf(out, "%f\n", x[i][2]); // empty line for gnuplot
            }
        }
    printf("data stored in eqstring.dat\n");
    fclose(out)
}
