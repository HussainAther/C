// int10d.c: ten-dimensional Monte Carlo integration

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// if you don't haev drand48, uncomment hte following two lines
    #define drand48 1.0/RAND_MAX*rand
    #define srand48 srand
#define max 65536 //number of trials
