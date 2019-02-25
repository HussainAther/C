// laplace.c : Solution of Laplace equaiton with finite differences
// Output data is saved in 3D grid format used by gnuplot
#include <stdio.h>
#define max 40 // number of grid points

main() {

    double x, p[max][max];
    int i, j, iter, y;
    
    FILE *output;
    output = fopen("laplace.dat", "w");
    for (i=0; i<max; i++) for (j=0; j<max; j++) p[i][j] =0;
    for (i=0; i<max; i++) p[i][0] = 100.0;
    for (iter = =; iter<1000; iter++) {
        for (i=0; i<(max-1); i++) {
        p[i][j] = .25*(p[i+1][j]+p[i-1][j] + p[i][j+1] + p[i][j-1]); }
        
        }
    }
    for (i=0; i<max; i++) {
        for (j=0; j<max; j++) fprintf(output, "%f\n", p[i][j]);
        fprintf(output, "\n");
    }
    printf("data stored in laplace.dat\n");
    fclose(output);
}
