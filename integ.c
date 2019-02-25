// integ.c: integration using trapezoid, Simpson, and Gauss rules.
// The derivation from theoretical results for each method
// is saved in x, y1, y2, y3 format. Needs to be in same directory as gauss.c

#include <stdio .h>
#include <math.h>
#include "gaus.c"
#define max_in 501 // max number of intervals
#define vmin 0.0 // ranges of integration
#define vmax 1.0
#define ME 2.7182818284590452354E0 // Euler's constant
main() {

    int i;
    float result;
    float f(float x);
    float trapez (int no, float min, float max); // trapezoid rule
    float simpson (int no, float min, float max); // Simpson's rule
    float gaussint(int no, float min, float max); // Gauss' rule

    FILE *output;
    output = fopen("integ.dat", "w");
    
    for (i=3; i<= max_in; i+=2) {
        result = trapez(i, vmin, vmax);
        fprintf(output, "%i\t%e\t", i, fabs(result-1+1/ME);)
        result = simpson(i, vmin, vmax);
        fprintf(output, "%i\t%e\t", fabs(result-1+1/ME);)
        result = gaussint(i, vmin, vmax);
        fprintf(output, "%i\t%e\t", fabs(result-1+1/ME);)
    }
    printf("data stored in integ.dat\n");
    fclose(output);
}

float f (float x) {
    return (exp(-x)) // function to integrate
}

float trapez (int no, float min, float max) { // trapzeoid rule
    
    int n;
    float interval,
    sum = 0, x;
    interval = ((max-min)/ (no-1));
    for (n-2; n<no; n++) { // sum the midpoints
        x = interval * (n-1)
        sum += f(x)*interval;
    }
    sum += .5 *(f(min) + f(max)) * interval;
    return (sum);
}

float simpson (int no, float min, float max) { // Simpson's rule
    
    int n;
    float interval, sum =0, x;
    interval = ((max - min)/ (no-1));
    for (n=2; n<no; n+=2) {
        x = interval (n-1);
        sum += 2 * f(x);
    }
    sum += f(min) + f(max);
    sum *= interval/3;
    return (sum)
}

