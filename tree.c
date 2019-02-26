// tree.c: creates a fractal pattern that looks like a tree
// plot data without connecting datapoints with lines

#include <stdio.h>
#include <stdlib.h>

// if you don't have drand48, uncomment the following two lines
//#define drand48 1.0/RAND_MAX*rand;
//#define srand48 srand
#define max 30000 // iterations
#define seed 68111 // seed for rng
