/* pendulum.c Solution of the pendulum equation using improved Euler
method */

# include <stdio.h>
# include <stdlib.h> /* needed for error function */
# include <math.h>

double f(double theta, double omega, double t); /* function prototype */
main(){
    int i, n;
    double h, k1a, k1b, k2a, k2b, theta, omega, t;
    
    FILE *Oscp; // declare file
    char filedat[20]; // declare string of characters for filename
    
    h=0.1; // time step
    n=100; // number of steps
    theta=0; // initial angle
    omega=1; // initial angular velocity
    t=0; // initial time

    printf("Enter the name of the data file to be written\n"); // write to file
    scanf("%s", filedat);
        if ((Oscp = fopen(filedat,"w")) == NULL) {
            fprintf(stderr,"Error opening file %s",filedat);
            exit(1);
    }
    printf("%lf\t%lf\t%lf\n", t, theta, omega);
    fprintf(Oscp,"%lf\t%lf\t%lf\n", t, theta, omega);
    
    // Implement the algorithm:
    for(i=1;i<=n;i++){
        k1a = h * omega;
        k1b = h * f(theta,omega,t);
        k2a = h * (omega+k1b);
        k2b = h * f(theta+k1a,omega+k1b,t+h);
        theta = theta + (k1a + k2a)/2;
        omega = omega + (k1b + k2b)/2;
        t=t+h;
        printf("%lf\t%lf\t%lf\n", t, theta, omega);
        fprintf(Oscp,"%lf\t%lf\t%lf\n", t, theta, omega);
        }
 fclose(Oscp); // close file
}

double f(double theta, double omega, double t)
{
    double deriv;
    deriv = -theta;
    return deriv;
}
