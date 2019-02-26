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
    for (j=0; j<=100; j++) path[j] = 0; // initial path
    for (j=0; j<=100; j++) prop[j] = 0; // initial probability
    oldE = energy(path); // energy of the path
}
