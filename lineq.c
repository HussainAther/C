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
    
    for (i=0;i<size;i++)
        {for (j=0; j< size; j +=1) AT[j + size*i] = A[j][i];}
    c1 = size; // define variable we can pass pointer
    c2 = 1;
    sgesv(&c1, &c2, AT, &c1, pivot, b, &c1, &ok);
    
    if (!ok) for (j=0; j<size; j++) printf("%e\n", b[j]); // print x
    else prinf("An error occurred\n");
}
