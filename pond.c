// pond.c: Monte Carlo integration to determine pi
// (stone throwing, sampling, or Buffon's needle method)

#include <stdio.h>
#include <stdlib.h>

// if you don't have drand48, uncomment the following two lines
//#define drand48 1.0/RAND_MAX*rand
//#define srand48 srand

#define max 1000 // number of stones to be thrown
#define seed 68111 // seed for rng
