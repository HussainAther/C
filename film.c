// film.c: Ballistic deposition simulation (fractal)
// plot data wihtout connecting datapoints with lines
#include <stdio.h>
#include <stdlib.h>

// if you don't have drand48, uncomment the following two lines
    #define drand48 1.0/RAND_MAX*rand
    #define srand48 srand
#define max 30000 // number of iterations
#define seed 68111 // seed for number generator
