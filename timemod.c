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

#define maxmac(a, b) ((a) > (b) ? (a) : (b))

int maxfunc(int a, int b)
{       return a > b ? a : b; }


#define T(s) printf("%s (n=%d)\n", s, n);
#define TRIALS 5
#define M(op)
        printf(" %-22s", #op);
        k = 0;
        timesum = 0;
        for (ex = 0; ex < TRIALS; ex++) {
                start = clock();
                for (i = 1; i <= n; i++) {
			fi = (float) i;
			for (j = 1; j <= n; j++) {
				op; 
			} t = clock()-start; 
		}
		printf("%6d", t); 
		timesum += t; 
	} nans = 1e9 * timesum / ((double) 
                n*n * TRIALS * CLOCKS_PER_SEC); 
        printf("%8.0f\n", nans);

