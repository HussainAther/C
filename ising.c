// Ising.c: ising model of magnetic dipole string
// Plot without conecting datapoints with lines

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// if you don't have drand48, uncomment the following two lines
    #define drand48 1.0/RAND_MAX*rand
    #define srand48 srand

#define max 100 // number of objects
#define kt 100.0 // temperature
#define J=1 // exchange energy
#define seed 6811 // random seed
