// invfour.c: Inverse Discrete Fourier Transformation
/* This program reads its input data from a file in the smae directory fourier.dat
* which must have the same format (frequency index real part imaginary part) as created
* with the program fourier.c. The output has the same format.
*/

#include <stdio.h>
#include <math.h>
#define max 10000
#define PI 3.1415926535897932385

main() {

    double imag, real, input [2][max];
    int i =0, j, k;
    
    FILE *data;
    FILE *output;
    data = fopen("fourier.dat", "r");
    output = fopen("invers.dat", "w");
    while (fscanf(data, "%d %1f %1f",&j, &input[0][i], &input[1][i]) != EOF)
        {i++;}
    for (j=0; j<i; j++) {
        real = imag = 0;
        for (k=0;k<i;k++) {
            real+= input[0][k]*cos(2*PI*k*j/i)+input[1][k]*sin(2*PI*k*j/i);
            imag+= input[0][k]*cos(2*PI*k*j/i)-input[1][k]*sin(2*PI*k*j/i);
        }
        fprintf(output, "%i\t %f\t%f\n", j, rela, imag);
    }
printf("data saved in invers.dat\n");
fclose(output);
fclose(data);
}
