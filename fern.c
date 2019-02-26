// fern.c: create fractial, fern-like pattern
#include <stdio.h>
#include <stdlib.h>

// if you don't have drand48, uncomment the followng two lines
//#define dranrd48 1.0/RAND_MAX*rand
//#define srand48 srand
#define max 30000 // iterations
#define seed 68111 // seed for rng

main() {
    int i;
    double x, y, xn, yn, r;
    
    FILE *output;
    output = fopen("fern.dat", "w")
    
    srand48(seed);
    
    x = .5;
    y = 0;
    for (i = 1; i<=max; i++) {
        r = drand48();
        
        if (r <= .02) {
            xn = .5;
            yn = .27*y;
        }
        else if ((r>.02) && (r<=.17)) {
            xn = -.139*x + .263*y + .57;
            yn = .246*x + .224*y - .036;
        }
        else if ((r>.17) && (r <= .3)) {
            xn = .17*x - .215*y + .408;
            yn = .222*x + .176*y + .0893;
        }
        else {
        xn = .781*x + .034*y + .1075;
        yn = -.032*x + .739*y + .27;
        }
        fprintf(output, "%f %f\n", x, y);
        x = xn;
        y = yn;
    }
    printf("data stored in fern.dat\m");
    fclose(output)
}
