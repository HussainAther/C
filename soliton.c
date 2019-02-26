// soliton.c : solves KdV equation using finite difference method
// saves output to 3D grid format used by gnuplot

#include <stdio.h>
#include <math.h>
#define ds .4 // delta s
#define dt .1 // delta t
#define max 2000 // time steps
#define mu .1 // mu from KdeV equation
#define eps .2 // epsilon (accuracy) from KdeV equation
