// dla.c: Diffusion−limited aggregation simulation (fractals)
#include <stdio .h>
#include <stdlib .h>
#include <math.h>

// if you don’t have drand48 uncomment the following two lines
// #define drand48 1.0/RAND_MAX*rand
// #define srand48 srand

#define max 40000 // iterations
#define size 401 // size of grid array
#define PI 3.1415926535897932385 E0
#define seed 68111 //seed for rng
main ( ) {
    double angle , rad = 180.0;
    int i,j, x, y, dist,step, trav;
    int grid[size][size], hit;
    int gauss_ran () ;
    FILE *output; // gaussian random number
    output = fopen ("dla.dat" ,"w") ;  // save data in dla.dat
                                        // clear
    for (i=0; i<size; i++) for (j=0; j<size; j++) grid[i][j] = 0;
    grid[200][200] = 1; // one particle at the center
    
    srand48 ( seed ) ; // seed rng
    for (i=0; i<max; i++) { // choose starting point
        hit=0;
        angle = (2*PI*drand48() ) ; // random angle
        x = (200+rad*cos(angle));  // coordinates
        y = (200+rad*sin(angle));
        dist = gauss_ran () ; // random number gaussian dist
        
        if (dist<0) step = −1; // move forwards or backwards
            else step = 1;
        trav =0;
        while (( hit == 0) && (x<399) && (x>1) && (y<399) && (y>1) &&
            (trav<abs(dist))) {
        if (grid[x+1][y]+grid[x−1][y]+grid[x][y+1]+grid[x][y−1]>= 1) { // one neighbor is occupied
    hit=1; grid[x][y] = 1;   // particle sticks, walk is over
    } else if (drand48() < 0.5) x+=step; // move horizontally
    else y+=step; // move vertically
trav++; }
}

for (i=0; i<size; i++)
    for (j=0; j<size; j++)
        if (grid[i][j] == 1) fprintf(output,"%d\t%d\n", i, j);
    printf ("data stored in dla.dat\n") ;
fclose (output) ;


