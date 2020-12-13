/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string M[40];
double P[40][40];
double DP[40][40];


double go(int p, int k) {
    double &ret = DP[p][k];
    if (ret > -.5) return ret;
    if (k >= 16) return ret = (p == k) ? 1. : 0.;
    ret = 0;
    for (int i = 16; i < 32; i++) if (p != i)
        ret += go(p,k*2)*go(i,k*2+1)*P[p][i] +
               go(p,k*2+1)*go(i,k*2)*P[p][i];
    return ret;
}


int main() {

    char S[1000];
    int x;
    for (int i = 16; i < 32; i++) scanf("%s", S), M[i] = S;
    for (int i = 16; i < 32; i++) for (int j = 16; j < 32; j++) {
        scanf("%d", &x);
        P[i][j] = x/100.;
    }
    for (int i = 0; i < 32; i++) for (int j = 0; j < 32; j++) DP[i][j] = -1.;
    for (int i = 16; i < 32; i++) go(i, 1);
    for (int i = 16; i < 32; i++) printf("%-10s p=%.2lf%%\n", M[i].c_str(), DP[i][1]*100.);

    return 0;
}
