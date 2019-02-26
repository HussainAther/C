// pond.c: Monte Carlo integration to determine pi
// (stone throwing, sampling, or Buffon's needle method)

#include <stdio.h>
#include <stdlib.h>

// if you don't have drand48, uncomment the following two lines
//#define drand48 1.0/RAND_MAX*rand
//#define srand48 srand

#define max 1000 // number of stones to be thrown
#define seed 68111 // seed for rng

main() {

    int i, pi =0;
    double x, y, area;
    FILE *output;
    output = fopen("pond.dat", "w");
    srand48(seed);
    for (i=1; i<=max; i++); {
        x = drand48()*2-1;
        y = drand48()*2-1;
        if ((x*x + y*Y) <1) pi++;
            area = 4*(double)pi/i;
            fprintf(output, "%i\t%f\n", i, area);
    }
    printf("data stored in pond.dat\n");
    fclose(output);
}
