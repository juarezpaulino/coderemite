/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

double X[5010], Y[5010], Z[5010];
double D[15];
int N;

const double EPS = 1E-10;

int main() {

    int H[10] = {0};

    int N = 0;
    for (int i = 1; i <= 10; i++) D[i-1] = i*i;
    while (scanf("%lf %lf %lf", X+N, Y+N, Z+N)) {
        if ((fabs(X[N])<1E-10) && (fabs(Y[N])<1E-10) && (fabs(Z[N])<1E-10)) break;
        N++;
    }

    for (int i = 0; i < N; i++) {
        double d = 1e20;
        for (int j = 0; j < N; j++) if (i != j) {
            double dx = X[i]-X[j];
            double dy = Y[i]-Y[j];
            double dz = Z[i]-Z[j];
            d = min(d, dx*dx+dy*dy+dz*dz);
        }
        for (int k = 0; k < 10; k++) if (d < D[k]-EPS) {  H[k]++;  break; }
    }

    for (int i = 0; i < 10; i++) printf("%4d", H[i]);
    putchar('\n');

    return 0;
}
