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

double C[10000];
int N;
double A0, AN1;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        scanf("%lf %lf", &A0, &AN1);
        for (int i = 0; i < N; i++) scanf("%lf", C+i);
        double ret = N*A0 + AN1;
        for (int i = 0; i < N; i++) ret -= 2*(N-i)*C[i];
        printf("%.2lf\n", ret/(N+1));
        if (T) putchar('\n');
    }

    return 0;
}
