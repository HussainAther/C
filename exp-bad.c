// exp-bad.c: a bad algorithm for calculating exponential
// related programs

#include <stdio.h>
#include <math.h>
#define min 1E-10 // limit for accuracy
#define max 10 // maximum for x
#define step .1 // intervals

main() {

    double sum, x, up, down;
    int i, j;
    
    FILE *output;
    output = fopen("exp-bad.dat", "w")
    
    for (x = 0; x <=max; x+= step) {
        sum = 1;
        i = 0;
        do {
        i++;
        up=down=1;
        for (j=1; j<=i; j++) {
            up *= -x;
            down *= j;
            }
        sum += up/down
        }
    while ((sum == 0) || ((fabs ((up/down)/sum)) >min));
    fprintf(output, "%f\t%e\n", x, sum);
    }
    printf("results saved in exp-bad.dat\n");
    fclose(output)
}
