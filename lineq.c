// lineq.c: SOlve matrix equation Ax = b using LAPACK

#include<stdio.h>
#define size 3 // matrix dimension

main() {
    
    int i, j, c1, c2, pivot[size], ok;
    float A[size][size], b[size], AT[size*size];
    
    A[0][0] = 3.1; A[0][1] = 1.3; A[0][2] = -5.7; // A matrix
    A[1][0] = 1; A[1][1] = -6.9; A[1][2] = 5.8;
    A[2][0] = 3.4; A[2][1] = 7.2; A[2][2] = -8.8;
    b[0] = -1.3; b[1] = -.01; b[2] = 1.8; // vector b
}
