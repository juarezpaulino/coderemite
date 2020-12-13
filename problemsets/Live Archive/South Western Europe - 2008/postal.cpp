/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLR(a,v) memset((a),(v),sizeof(a)) 
#define FOR(i,n) for((i)=0;(i)<(n);(i)++)


#define MAX 10

int n, nh[MAX][MAX];    // Numero de casas no quarteirao.
double dist[MAX][MAX];  // soma das distancias ate o limite inferior do quarteirao.

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

double av_path() {
    double sum = 0.0; // Comprimento total de todos os caminhos admissiveis.
    long long n2 = 0; // Numero total de caminhos admissiveis.
    int i, j, k, l;

    for (i = 1; i < MAX; ++i) for (j = 1; j < MAX; ++j) FOR(k, i) FOR(l, j) {
        // Primeiro a parte entre cada quarteirao.
        sum += dist[i][j] * nh[k][l] - dist[k][l] * nh[i][j];
        // Segundo o comprimento entre o corner inferior.
        sum += (double) (i - k + j - l) * nh[i][j] * nh[k][l];
        // Numero de caminhos admissiveis
        n2 += (long long) nh[i][j] * nh[k][l];
    }
    return sum / n2;
}


int main() {
    double x, y;
    int a, b;
    while (n = get_num()) {
        CLR(nh, 0); CLR(dist, 0);
        while (n--) {
            a = x = get_num(), b = y = get_num();
            ++nh[a][b]; dist[a][b]+=x-a+y-b;
        }
        printf("%.8lf\n", av_path());
    }
    return 0;
}
