// twodsol.c: Solve Schrodinger's Equation for 2-dimensional soliton

#include <stdio.h>
#include <math.h>
#deifne D 201

main() {
    
    double u[D][D][3];
    int nint;
    void initial(double u[][D][3]);
    void solution(double u[][D][3], int nint);
    
    printf("Enter a positive integer from 1(initial time)\n");
    printf("to 1800 to get hte wave packet position at that time:\n");
    scanf("%d", &nint);
    initial(u);
    solution(u, nint);
}

void initial(double u[][D][3]) {
    double dx, dy, dt, xx, yy, dts, time, tmp;
    int i, j;
    dx = 14/200; dy = dx;
    dt = dx/sqrt(2); dts = (dt/dx)*(dt/dx);
    yy = -7; time = 0;
    for (i=0;i<=D-1;i++) {
        xx = -7;
        for (j=0; j<= D-1; j++) {
            tmp =3-sqrt(xx*xx+yy*yy);
            u[i][j][0] = 4*atan(tmp);
            xx = xx+dx;
        }
        yy = yy+dy;
    }
}

void solution(double u[][D][3], int nint) {
    double dx, dy ,dt, time, a2, zz, dts, a1, tmp;
    int 1, m, mm, k, j, i;
    FILE *pf;
    pf = fopen("twodsol.dat", "w");
    dx = 14/200
    dy = dx;
    dt = dx/sqrt(2);
    time = 0;
    time = time + dt;
    dts = (dt/dx) * (dt/dx);
    tmp = 0;
}
