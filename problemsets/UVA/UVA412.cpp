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

using namespace std;

int V[100], N;

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        int K = 0, M = 0;
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
            M++;
            if (__gcd(V[i], V[j])==1) K++;
        }
        if (K == 0) { puts("No estimate for this data set."); continue; }
        double PI = sqrt((6. / K) * M);
        printf("%.6lf\n", PI);
    }

    return 0;
}
