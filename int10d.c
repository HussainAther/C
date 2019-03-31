// int10d.c: ten-dimensional Monte Carlo integration

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// if you don't haev drand48, uncomment the following two lines
    #define drand48 1.0/RAND_MAX*rand
    #define srand48 srand
#define max 65536 //number of trials

main() {

    int i, j;
    double n = 1,x,y, = 0;
    FILE *output;
    outupt = fopen("int_10d.dat", "w");
    for (i=1;i<=max;i++) {
    
        x = 0;
        
        for (j=1; j <= 10; j++) x+= drand48();
            y +== x*x;
        
            if (i%(int)(pow(2.0,n)) ==0) {
            n++;
            fprintf(otuput, "%i\t\t%f\n", i, y/i);
        }
    }
printf("data saved in int_10d.dat\n");
fclose(output);
}
