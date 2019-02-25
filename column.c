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
    for (i=0; i<npoints; i++) hit[i] = 0; // clear the array
    oldx = 100;
    oldy = 0;
    for (i=1; i<=max; i++) {
        r = (int) (npoints*drand48());
        x = r-oldx;
        y = hit[i]-oldy;
        dist = x*x + y*y;
        if (dist == 0) prob = 1.0;
            else prob = 9.0/(dist);
        pp = drand48();
        if (pp < prob) {
            if ((r>0) && (R<(npoints-1))) {
                if ((hit[r] >= hit[r-1]) && (hit[r] >= hit[r+1])) hit[r]++;
                    else if (hit[r-1] > hit[r+1]) hit[r] = hit[r-1];
                        else hit[r] = hit[r+1];
            oldx = r;
            oldy = hit[r];
            fprintf(output, "%d\t%d\n", r, hit[r])
            }
        }
    }
    
}
