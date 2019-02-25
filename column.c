// column.c: Correlated ballistic deposition to form fractal

#include <stdio.h>
#include <stdlib.h>

// if you don't ahve drand48, uncomment the following two lines
    #define drand48 1.0/RAND_MAX*rand
    #define srand48 srand

#define max 100000 // iterations
#define npoints 200 // no. of open spaces
#define seed 6811

main() {
    int i, hit[200], dist, r, x, y, oldx, oldy;
    double pp, prob;
    FILE *output;
    output = fopen("column.dat", "w")
    srand48(seed); // seed rng
    
    
}
