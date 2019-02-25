// bessel.c: spherical bessel functions via up and down recursion

#include <stdio.h>
#include <math.h>

#define xmax 40.0
#define xmin .25
#define step .1
#define order 10 // order of Bessel function
#define start 50 // used for downward algorithm
