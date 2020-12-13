/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long i64;

int V[100100];

int main() {

    int M, N;
    scanf("%d %d", &M, &N);

    i64 t = 0, ret = 0;
    for (int i = 0; i < N; i++) { scanf("%d", V+i); t += V[i]; }
    t -= M;

    sort(V, V+N);

    for (int i = 0; i < N; i++) {
        i64 k = min((i64)V[i], t/(N-i));
        ret += k*k;
        t -= k;
    }
    printf("%lld\n", ret);

    return 0;
}
