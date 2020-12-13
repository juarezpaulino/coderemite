/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)


struct point {
    double x, y, z;
    point(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}
};

double get_num() {
    int ch; double i, j, k;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch==EOF) exit(0);
    for (i = 0.; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i*10)+(ch-'0');
    j = 0.;
    if (ch=='.') {
        for (k = 10., ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar(), k*=10)
            j = j+(ch-'0')/k;
    }
    return i+j;
}

double volume_tetraedro(point p[4]) {
    int i;
    double a[3][3], s1, s2, s3, s4, s5, s6;
    FOR(i, 3)
        a[i][0] = p[0].x-p[i+1].x,
        a[i][1] = p[0].y-p[i+1].y,
        a[i][2] = p[0].z-p[i+1].z;
    // Calcula o determinante da matriz 3x3, regra de Sarrus
    s1 = a[0][0] * a[1][1] * a[2][2];
    s2 = a[0][1] * a[1][2] * a[2][0];
    s3 = a[0][2] * a[1][0] * a[2][1];
    s4 = a[0][2] * a[1][1] * a[2][0];
    s5 = a[0][0] * a[2][1] * a[1][2];
    s6 = a[2][2] * a[1][0] * a[0][1];
    return fabs((s1 + s2 + s3 - s4 - s5 - s6) / 6.0);    
}


int main() {
    
    point p[4];
    for (int t = get_num(); t--; ) {
        p[0].x = get_num(); p[0].y = get_num(); p[0].z = get_num();
        p[1].x = get_num(); p[1].y = get_num(); p[1].z = get_num();
        p[2].x = get_num(); p[2].y = get_num(); p[2].z = get_num();
        p[3].x = get_num(); p[3].y = get_num(); p[3].z = get_num();
        printf("%.6lf\n", volume_tetraedro(p));
    }
    
    return 0;
}

