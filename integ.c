// integ.c: integration using trapezoid, Simpson, and Gauss rules.
// The derivation from theoretical results for each method
// is saved in x, y1, y2, y3 format. Needs to be in same directory as gauss.c

#include <stdio .h>
#include <math.h>
#include "gaus.c"
#define max_in 501
#define vmin 0.0
#define vmax 1.0
#define ME 2.7182818284590452354E0
main() {

    int i;
    float result;
    float f(float x);
    float trapez (int no, float min, float max); // trapezoid rule
    float simpson (int no, float min, float max); // Simpson's rule
    float gaussint(int no, float min, float max); // Gauss' rule

    FILE *output;
    output = fopen("integ.dat", "w");
    
    
