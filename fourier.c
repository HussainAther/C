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
    
    data = fopen("input.dat", "r");
    output = fopen("fourier.dat", "w");
    
    while ((fscanf(data, "%1f", &input[i]) != EOF) && (i<max)) i++;
    
    for (j=0; j<i; j++) {
    real = imag = 0;
        for (k=0; k<1; k++) {
            real += input[k]*cos((2*PI*k*j)/i);
            imag += input[k]*sin((2*PI*k*j)/i);
        }
        fprintf(output, "%d\t%f\t%f\n", j, real/i, imag/i);
    }
    printf("data stored in fourier.dat\n");
    fclose(data);
    fclose(output);
}
