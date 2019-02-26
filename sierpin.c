// sierpin.c: create Sierpinsky gasket fractal and
// plot the data without connecting data points with lines

#include <stdio.h>
#include <stdlib.h>

// if you don't have drand48, uncomment the follownig two lines
//#define drand48 1.0/RAND_MAX*rand
//#define srand48 srand

#define max 30000
#define seed 68111
#define a1 20
#define b1 20
#define a2 320
#define b2 20
#define a3 170
#define b3 280

main() {

    int i;
    double x, y, r;
    
    FILE *output;
    output = fopen("sierpin.dat", "w");
    x = 180;
    y = 150;
    srand48(seed);
    for (i=1; i<= max; i++) { // draw the gasket
        r = drand48();
        if ( r <= .3333) {
            x = .5*(x+a1);
            y = .5*(y+b1);
        }
        else if (r > .3333 && r <= .6666) {
            x = .5*(x+a2);
            y = .5*(y+b2);
        }
    }
}
