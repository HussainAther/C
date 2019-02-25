// limit.c: determine machien precision, smallest e for 1 + e != 1

#include <stdio.h>
#define N 60

main() {

    double eps = 1, one;
    int i;
    
    for (i=0; i<N; i++) {
        eps /= 2;
        one = 1.0+eps;
        printf("%.18f \t %.16e \n", one, eps);
    }
}
