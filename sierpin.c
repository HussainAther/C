// sierpin.c: create Sierpinsky gasket fractal and
// plot the data without connecting data points with lines

#include <stdio.h>
#include <stdlib.h>

// if you don't have drand48, uncomment the follownig two lines
//#define drand48 1.0/RAND_MAX*rand
//#define srand48 srand

#define max 30000
#define seed 68111
#define a1 20
#define b1 20
#define a2 320
#define b2 20
