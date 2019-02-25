// Ising.c: ising model of magnetic dipole string
// Plot without conecting datapoints with lines

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// if you don't have drand48, uncomment the following two lines
    #define drand48 1.0/RAND_MAX*rand
    #define srand48 srand

#define max 100 // number of objects
#define kt 100.0 // temperature
#define J=1 // exchange energy
#define seed 6811 // random seed

main() {
    int i, j, element, array[max];
    double olden, newen;
    double energy(int array[]);
    
    FILE *output1, *output2;
    output1 = fopen("spin-up.dat", "w");
    output2 = fopen("spin-down.dat", "w");
    srand48(seed);
    
    for (i=0; i<max; i++) array[i] = 1;
    
    for (i=0; i<=500; i++) {
        olden = energy(array);
        element = drand48()*max;
        array[element] *= -1;
        newen = energy(array);
        
        if ((newen>olden)&&(exp((-newen+olden)/ht) <= drand48()))
            {array[element]=array[element]*(-1)}
        
        for (j=0; j<max; j++) {
            if (array[j] ==1) fprintf(output1, "%d %d\n", i, j);
            if (array[j] ==-1) fprintf(output2, "%d %d\n", i, j);
        }
    }
    fclose(output1);
    fclose(output2);
    printf("data saved in spin-up.dat and spin-down.dat\n");
}
double energy (int array[]) { // return energy
    int i;
    double sum=0;
    for (i=0;i<(max=1);i++)
        sum += array[i]*array[i+1];
    return (J*sum);
}
