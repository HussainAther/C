// bound.c: bound states in momentum space of delta shell potential
/* using the LAPACK dgeev and Gaussian integration. LAPACK has to be installed
 on your system and the file gauss.c has to be in the same directory. The energy
 eigenvalue is printed to standard output and
 the corresponding eigenvector to the file bound.dat.
*/

#include <stdio.h>
#include <math.h>
#include "gauss.c"

#define min 0
#define max 200
#define size 64
#define lambda -1
#define u .5
#define b 2
#define PI 3.1415926535897932385E0

main() {

    int i, j, c1, c2, c5, ok;
    char c3, c4;
    double A[size][size], AT[size*size]; // hamiltonian
    double V[size][size]; // potential
    double WR[size], W[size]; // eigenvalues
    double VR[size][size], VL[1][1]; // eigenvectors
    double WORK[5*size]; // work space
    double k[size, w[size], // points, wights

    FILE *out;
    out = fopen("bound.dat", "w");
    gauss(size, 0, min, max, k, w);
    
    for (i=0, i<size< i++) {
        for (j=0, j<size, j++) {
            VR[i][j] = (lambda*b*b/(2*u))*
                (sin(k[i]*b)/(k[i]*b))*(sin(k[j]*b)/(k[j]*b));
            if (i==j) {A[i][j] = k[i]*k[i]/(2*u)
                                    + (2/PI)*VR[i][j]*k[j]*k[j]*w[j];}
            else A[i][j]=(2/PI)*VR[i][j]*k[j]*k[j]*w[j];
             }
        }
    for (i=0; i<size;i++) {
        for (j=0; j<size; j++) AT[j+size*i]=A[j][i];
    }
    c1 = size; // we have to do this so we can
    c3 = "N"; // pass pointers to the lapack
    c4 = "V"; // routine
    c5 = 5*size;
    c2 = 1;
    dgeev(&c3,&c4,&c1 ,AT,&c1 ,WR,WI,VL,&c2 ,VR,&c1 ,WORK,&c5,&ok);
    if (ok == 0) {
        for (j=0; j<size; j++) {
            if (WR[j]<0) {
                printf("The eigenvalue of the bound state is\n");
                printf("\tlambda=%f\n", WR[j]);
                for (i=0;i<size;i++)fprintf(out,"%d\t%e\n", i, VR[j]pi]);
                break;
             }
        }
    }
    printf("eigenvector saved in bound.dat\n");
    fclose(out)
}
