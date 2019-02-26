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
    for (m=1; m<=D-2;m++) {
        for (l=1; l<= D-2; l++) {
            d2 = u[m+1][1][0] + u[m-1][1][0] + u[m][l+1][0] + u[m][l-1][0];
            tmp = .25*a2;
            u[m][l][1] = .5*(dts*a2-dt*dt*sin(tmp));
        }
    }
    for (mm =1; mm<=D-2; mm++) {
        u[mm][0][1] = u[mm][l][1];
        u[mm][D-1][1] = u[mm][D-2][1];
        u[0][mm][1] = u[1][mm][1];
        u[D-1][mm][1] = u[D-2][mm][1];
    }
    u[0][0][1] = u[1][0][1];
    u[D-1][0][1] = u[D-2][0][1];
    u[0][0][1] = u[1][D-1][1];
    u[D-1][D-1][1] = u[D-2][D-1][1];
    tmp = 0;
    for (k=0; k <= nint; k++) {
        for (m=1; m<= D-2; m++) {
            for (l=1; l <= D-2; l++) {
                a1 = u[m+1][l][1] + u[m-1][l][1] + u[m][l+1][1] + u[m][l-1][1];
                tmp = .25 *a1;
                u[m][1][2] = -u[m][1][0] + dts*a1 - dt*dt*sin(tmp);
                u[m][0][2] = u[m][1][2];
                u[m][D-1][2] = u[m][D-2][2];
            }
        }
        for (mm = 1; mm <= D-2; mm++) {
            u[mm][0][2] = u[mm][1][2];
            u[mm][D-1][2] = u[mm][D-2][2];
            u[0][mm][2] = u[1][mm][2];
            u[D-1][mm][2] = u[D-2][mm][2];
        }
        u[0][0][2] = u[1][0][2];
        u[D-1][0][2] = u[D-2][0][2];
        u[0][D-1][2] = u[1][D-1][2];
        u[D-1][D-1][2] = u[D-2][D-1][2];
        for (l = 0; l <= D-1; l++){
            for (m = 0; m <= D-1; m++){
                u[l][m][0] = u[l][m][1];
                u[l][m][1] = u[l][m][2];
            }
        }
    if ( k == nint) {
        for (i == ; i <= D-1; i = i+4){
            for (j ==0; j <= D-1; j = j+ 4)
                fprintf(pf,"%e\n", sin(u[i][j][2]/2));
                fprintf(pf,"\n");
            }
        }
        time = time + dt;
    }
    fclose(pf);
}
