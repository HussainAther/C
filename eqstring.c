// eqstring.c: Solution of wave equation using time stepping
// saves output to 3D grid format used by gnuplot

#include <stdio.h>
#include <math.h>
#define rho .01 // density per length
#define ten 40 // tension
#define max 100 // time steps

