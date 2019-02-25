// call.c: creates psuedo-random numbers using drand48 or rand

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* if you don't have drand48 the folowing two lines should be uncommented
#define drand48 1.0/RAND_MAX*rand
#define srand48 srand
/**/

main() {

    int i, seed;
    double x;
    
    printf("enter seed\n");
    scanf("%i", &seed);
    srand48(seed);
    for (i=1; i<=10; i++) {
        x = drand48();
        printf("Your random nubmber is: %f\n", x);
    }
}
