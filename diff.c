#include <stdio .h>
#include <math.h>
#define h 1e−5 // stepsize for all methods
#define xmax 7 // range for calculation
#define xmin 0
#define xstep 0.01 // stepsize in x
main() {
    double dc, result, x;
    double f(double); // function we differentiate

    FILE *output;
    output = fopen ("diff.dat" ,"w") ;  // save data in diff.dat
    for (x = xmin; x<= xmax; x+= xstep) {
        fprintf (output ,"%f\t", x) ; // forward difference
        result = (f(x+h)−f(x))/h;
        fprintf (output , "%.10f\t", result ) ; // central difference
        result = (f(x+h/2)−f(x−h/2))/h;
        fprintf (output , "%.10f\t", result ) ;
        result = (8*( f (x+h/4.)−f (x−h/4.) )−(f (x+h/2)−f (x−h/2.) ) ) /(3.*h) ; // extrapolated diff
        fprintf (output , "%.10f\n", result ) ; }
    printf ("data stored in diff.dat\n") ; fclose (output) ;
    } // end of main
double f(double x) // function to differentiate
{ return(cos(x)); }

