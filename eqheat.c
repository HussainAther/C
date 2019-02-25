// eqheat.c: Solution of heat equations using finite differences

#include <stdllib.h>
#include <stdio.h>
#define size 101 // grid size
#define max 30000 // iterations
#define thc .12 // thermal conductivity
#define sph .113 // specific heat
#define rho 7.8 // density

main() {
    
    int i, j;
    double cons, u[101][2];
    
    FILE *output // save data to eqheat.dat
    output = fopen("eqheat.dat", "w")
    
    for (i = 0; i<size; i++) u[i][0] = 100;
    
    for (j = 0; j<2; j++) {
        u[0][j] = 0;
        u[size-1][j] = 0;
    }
    cons = thc/(sph*rho); // material constants
    for (i = 1; i <=max; i++) { // loop over space
        for (j =1; j<(size-1); j++)
        {u[j][1] = u[j][0] + cons*(u[j+1][0]+u[j-1][0]-2*u[j][0]);} // save every 1000 steps
        if ((i%1000 == 0) || (i ==1)) {
            for (j =0; j<size; j++) fprintf(output, "%f\n", u[j][1]);
            fprintf(output, "\n"); // empty lien for gnuplot
        }
        for (j=0; j<size; j++) u[j][0] = u[j][1]
    }
    printf("data stored in eqheat.dat\n")
    fclose(output)
}
