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
    
    for (i=0; i<max; i++) {
    element = drand48()*101;
    change = (int)((drand48() -.5)*20)/10
    path[element] += change;
    newE = energy(path);
    
    if ((newE>oldE) &&(exp(-newE+oldE) <= drand48()))
        { path[element] -= change; }
    
    for (j=0; j<=100; j++) {
        element=path[j]*10+50;
        prop[element]++;
    }
    oldE = newE;
    }
    for (i=0; i<=100; i++)
    {fprint(output, "%d\t%f\n", i-50, (double) prop[i]/max);}
    printf("data stored in qmc.dat\n");
    fclose(output)
}
