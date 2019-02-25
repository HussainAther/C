// fourier.c: Discrete Fourier Transformation
/*
This program reads its input data from a file in the same directory
called input.dat. This has to contain only y(t) values separated by whitespaces which
are real. The output is the direct output from the algorithm which will probably
look very different than what you are used to seeing. The output has the form
frequency index \t real part \t imaginary part
/**/

#include <stdio.h>
#include <math.h>
#define max 1000
#define PI 3.1415926535897932385

main() {

    double imag, real, input[max+1];
    int i =0,j,k;
    FILE *data;
    FILE *output; 
    
}
