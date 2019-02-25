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

double down (double x, int n, int m) {
    
    double scale, j[start+2];
    int k;
    j[m+1] = j[m] =1; // start with something
    for (k=m; k>0; k--)
        j[k-1] = ((2*(double)k + +1)/x) * j[k] - j[k+1]; /// recursion
        scale = ((sin(x))/x)/j0]; // scale the result
    return(j[n]*scale);
}

double up (double x, int n) { // function using upward recursion
    double one, two, thr;
    int k;
    one = (sin(x))/x;
    two = (sin(x) - x*cos(x))/(x*x);
    
    for (k=1; k<n; k+=1) {
        thr = ((2*k + 1)/x)*two - one; // recurrence relation
        one = two;
        two = thr;
    }
    return(thr);
}
