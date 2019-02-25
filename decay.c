#include <stdio .h> #include <stdlib .h>
// if you don’t have drand48 uncomment the following two lines
// #define drand48 1.0/RAND_MAX*rand
// #define srand48 srand
#define lambda 0.01 // the decay constant
#define max 1000  // number of atoms at t=0
#define time_max 500 // time range
#define seed 68111  // seed for number generator
main() {
int atom, time, number, nloop;
double decay ;
FILE *output; // save data in decay.dat
output = fopen ("decay.dat" ,"w") ;
number = nloop = max;  // initial value
srand48 ( seed ) ; // seed number generator
for (time=0; time<=time_max; time++) { // time loop
    for (atom=1; atom<=number; atom++) { decay = drand48 ( ) ;  // atom loop
        if (decay < lambda) nloop−−; // an atom decays
}
number = nloop ;
fprintf (output , "%d\t%f\n", time ,
(double)number/max) ;
    }
printf ("data stored in decay.dat\n") ; fclose (output) ;
}
