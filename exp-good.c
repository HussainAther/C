// exp-good.c: good algorithm for calculating exponential
// related programs

#include <stdio.h>
#include <math.h>
#define min 1E-10 // limit for accuracy
#define max 10 // maximum for x
#define step .1 // interval

main () {

    double x, sum, element;
    int n;
    
    FILE *output;
    output = fopen("exp-good.dat", "w");
    for (x = 0; x <= max; x += step) {
        sum = element = 1;
        n = 0;
        do {n++;
            element *= -x/n;
            sum += element;
        }
        while ((sum ==0) || (fabs(element/sum) > min));
            fprintf(output, "%f\t%e\n", x, sum);
    }
    printf("results saved in exp-good.dat\n");
    fclose(output)
}
