// bound.c: bound states in momentum space of delta shell potential
/* using the LAPACK dgeev and Gaussian integration. LAPACK has to be installed
 on your system and the file gauss.c has to be in the same directory. The energy
 eigenvalue is printed to standard output and
 the corresponding eigenvector to the file bound.dat.
*/

#include <stdio.h>
#include <math.h>
#include "gauss.c"

#define min 0
#define max 200
#define size 64
#define lambda -1
#define u .5
#define b 2
#define PI 3.1415926535897932385E0

main() {

    int i, j, c1, c2, c5, ok;
    char c3, c4;
    
}
