// film.c: Ballistic deposition simulation (fractal)
// plot data wihtout connecting datapoints with lines
#include <stdio.h>
#include <stdlib.h>

// if you don't have drand48, uncomment the following two lines
    #define drand48 1.0/RAND_MAX*rand
    #define srand48 srand
#define max 30000 // number of iterations
#define seed 68111 // seed for number generator

main() {
    
    int i, hit[200], r;
    
    FILE *output;
    output = fopen("film.data", "w");
    srand48(seed);
    
    for (i=0; i<200; i++) hit[i] = 0;
    for (i=1; i<=max; i++) {
        r=(int)(199*drand48());
        if ((hit[r] >=hit[r-1]) && (hit[r] >= hit[r+1])) hit[r]++;
        else if (hit[r-1] > hit[r+1]) hit[r] = hit[r-1];
        else hit[r] = hit[r+1];
        fprintf(output, "%d\t%d\n", r, hit[r]);
    }
    printf("data stored in film.dat\n");
    fclose(output);
}
