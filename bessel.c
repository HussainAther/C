// bessel.c: spherical bessel functions via up and down recursion

#include <stdio.h>
#include <math.h>

#define xmax 40.0 // max of x
#define xmin .25 // min of x > 0
#define step .1 // delta x
#define order 10 // order of Bessel function
#define start 50 // used for downward algorithm

main() {
    
    double x;
    double down(double x, int n, int m); // downward alg
    double up(double x, int n); // upward alg
    
    FILE *out;
    out = fopen("bessel.dat", "w");
    
    for (x=xmin; x<=xmax; x+=step) fprintf(out, "%f\t%f\t%f\n",
                                x, down(x, order, start), up(x, order));
    printf("data stored in bessel.dat\n");
    fclose(out);

}

