// dla.c: Diffusion−limited aggregation simulation (fractals)
#include <stdio .h>
#include <stdlib .h>
#include <math.h>

// if you don’t have drand48 uncomment the following two lines
// #define drand48 1.0/RAND_MAX*rand
// #define srand48 srand

#define max 40000 // iterations
#define size 401 // size of grid array
#define PI 3.1415926535897932385 E0
#define seed 68111 //seed for rng
