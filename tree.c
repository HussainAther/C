// tree.c: creates a fractal pattern that looks like a tree
// plot data without connecting datapoints with lines

#include <stdio.h>
#include <stdlib.h>

// if you don't have drand48, uncomment the following two lines
//#define drand48 1.0/RAND_MAX*rand;
//#define srand48 srand
#define max 30000 // iterations
#define seed 68111 // seed for rng

main() {
    int i;
    double x, y ,r, xn, yn;
    FILE *output;
    output = fopen("tree.dat", "w");
    srand48(seed);
    x = .5;
    y = 0;
    for (i=1; i<=max; i++) {
        r = drand48();
        if (r <= .1) {
            xn = .05 * x;
            yn = .5 * y;
        }
    else if ((r > 0.1) && (r < 0.2)) {
        xn = .05 * x;
        yn = -.5 * y+1;
    }
    else if ((r > 0.2) && (r < .4)) {
        xn = .46 * x - .32 * y;
        yn = .39 * x + .38 * y + 6;
    }
    else if ((r > 0.4) && (r < .6)) {
        xn = .47 * x - .15 * y;
        yn = .17 * x + .42 * y + 6;
    }
    else if ((r > 0.6) && (r < .8)) {
        xn = .43 * x + .28 * y;
        yn = -.25 * x + .45 * y + 1;
    }
    else {
        xn = .42 * x + .26 * y;
        yn = -.35 * x + .31 * y + .7;
    }
    fprintf(output, "%f %f\n", xn, yn);
    x = xn;
    y = yn;
    }
    printf("data stored in tree.dat\n");
    fclose(output);
}
