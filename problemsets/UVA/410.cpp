/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int main() {

    int C, S;
    int M[10], V[10];
    int id = 1;
    while (scanf("%d %d", &C, &S) != EOF) {
        for (int i = 0; i < S; i++) scanf("%d", M+i);
        for (int i = S; i < 2*C; i++) M[i] = 0;
        sort(M, M+2*C, greater<int>());

        double ret = 0., m = 0.;
        printf("Set #%d\n", id++);
        for (int i = 0; i < C; i++) {
            printf("%2d:", i);
            int a = M[i], b = M[2*C-1-i];
            if (a) printf(" %d", a);
            if (b) printf(" %d", b);
            putchar('\n');
            V[i] = a+b;
            m += V[i];
        }
        m /= C;
        for (int i = 0; i < C; i++) ret += fabs(V[i]-m);
        printf("IMBALANCE = %.5lf\n", ret);
        putchar('\n');
    }

    return 0;
}
