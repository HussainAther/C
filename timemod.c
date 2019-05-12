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

