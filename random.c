// random.c: a simple random number generator, not for serious work
#include <stdio.h>
#define max 1000
#define seed 11

main() {

    int i, old, newx, newy;

    FILE *output;
    output = fopen("badrand.dat", "w");
    old = seed;
    for (i=0; i<max; i++) {
        newx = (57*old+1) %256;
        newy = (57*newx+1) % 256;
        fprintf(output, "%i\t%i\n", newx, newy);
        old = newy;
    }
    printf("data stored in badrand.dat\n");
    fclose(output);
}
