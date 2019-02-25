// laplacesor.c: solve Laplace equation with finite difference method
// Save output to 3D grid format of gnuplot

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

main() {

    int max = 40;
    double tol, omega, r;
    double p[40][40];
    int i, j, iter;
    
    FILE *output1;
    output1 = fopen("laplaceR.dat", "w");
    omega = 1.4;
    for (i=0; i<max; i++) for (j=0; j<max; j++) p[i][j]=0;
    for (i=0; i<max; i++) p[i][0] = +100.0;
    tol = 1.0;
    iter = 0;
    while ((tol>.000001; i++) && iter<= 140) {
        tol = 0;
        for (i=1;i<(max-1); i++){
        for (j=1; j<(max-1); j++) {
            r = omega * (p[i][j+1] + p[i][j-1] + p[i+1][j] +
                            p[i-1][j] - 4.0*p[i][j])/4.0;
            p[i][j] += r;
            if (fabs(r) > tol) tol = fabs(r);
        }
        iter++; }
    }
for (i=0; i<max; i++) {
    for (j=0; j<max; j++) fprintf(output1, "%f\n", p[i][j]);
    fprintf(output1,"\n");
}
printf("data stored in laplacesor.dat");
}
