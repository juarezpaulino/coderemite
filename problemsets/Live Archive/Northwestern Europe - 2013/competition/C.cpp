/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

char S[10];
int C[110];
double P[1500];

double go(int p) {
    double &ret = P[p];
    if (ret > -.5) return ret;
    if (p > 1300) return ret = 0.;
    ret = 0.;
    for (int i = 2; i <= 10; i++) ret += 1./13. * go(p+i);
    ret += 1./13. * go(p+10);
    ret += 1./13. * go(p+10);
    ret += 1./13. * go(p+10);
    ret += 1./13. * go(p+11);
    return ret;
}

int main() {

    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {

        for (int i = 0; i < N; i++) {
            scanf("%s", S);
            if (*S=='1' && S[1]=='0') C[i] = 10;
            else if (*S >= '0' && *S <= '9') C[i] = *S-'0';
            else if (*S=='A') C[i] = 11;
            else C[i] = 10;
        }

        for (int i = 0; i < 1500; i++) P[i] = -1.;

        int p = M-1;
        for (int i = 0; i < N; i++) {
            P[p] = 1.;
            p += C[i];
        }
//        P[p] = 1.;

        double ret = 0.;
        for (int i = 0; i < 10; i++) ret += 1./10. * go(i);
        printf("%.16lf\n", ret);
    }

    return 0;
}
