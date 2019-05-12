/* Produce a table of C run time costs

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100000
int x[MAXN];
int startn = 5000;
int n;

/* Functions to time */

int intcmp(int *i, int *j)
{   return *i - *j; }

#define swapmac(i, j) { t = x[i]; x[i] = x[j]; x[j] = t; }

void swapfunc(int i, int j)
 {  int t = x[i];
        x[i] = x[j];
        x[j] = t;
 }
