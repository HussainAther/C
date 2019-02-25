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
main ( ) {
    double angle , rad = 180.0;
    int i,j, x, y, dist,step, trav;
    int grid[size][size], hit;
    int gauss_ran () ;
    FILE *output; // gaussian random number
    output = fopen ("dla.dat" ,"w") ;  // save data in dla.dat
                                        // clear
    for (i=0; i<size; i++) for (j=0; j<size; j++) grid[i][j] = 0;
    grid[200][200] = 1;
    
    srand48 ( seed ) ; // seed rng
for (i=0; i<max; i++) {
hit=0;
angle = (2*PI*drand48() ) ;
x = (200+rad*cos(angle));
y = (200+rad*sin(angle));
dist = gauss_ran () ;
if (dist<0) step = −1; else step = 1;
// one particle at the center // seed number generator
// choose starting point
// random angle // coordinates
// random number gaussian dist // move forwards or backwards
                                                trav =0;
