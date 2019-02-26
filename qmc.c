// qmc.c: Feynman path integral for ground state wave function

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// if you don't have drand48, uncomment the next two lines
//#define drand48 1.0/RAND_MAX*rand
//#define srand48 srand

#define max 250000  // number of trials
#define seed 68111 // seed for rng

main() {
    double change, newE, oldE, path [101];
    int i, j, element, prop [101];
    double energy (double array[]);
    FILE *output;
    output = fopen("qmc.dat", "w");
    srand48(seed);
}
