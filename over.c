// over.c: Determine overflow and underflow limits

#include <stdio.h>
#define N 1024 // i wonder if this is big enough to cause over and underflow

main() {

    doouble under =1, over =1;
    int i;
    
    for (i=0; i<1024; i++) {
        under /= 2;
        over *= 2;
        printf("%d. under: %e over: %e \n" i+1, udner, over);
    }
}
