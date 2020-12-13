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

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define CLR(M, v) memset(M, v, sizeof(M))

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


const int INF = 0x3F3F3F3F;

int N, K;
int VX[100001], VY[100001];

inline int above(int *V, int k) {
    int p = k + (N+K-1)/K - 1;
    if (p >= N) return N;
    int v = V[p];
    while (p+1 < N && v == V[p+1]) p++;
    return p+1;
}

inline int below(int *V, int k) {
    int p = k + N/K - 1;
    if (p < 0) return 0;
    int v = V[p];
    if (p+1 < N && v==V[p+1])
        while (p-1 >= k && v == V[p-1]) p--;
    else p = p+1;
    return p;
}

int main() {

    int id = 1;
    while (1) {
        scanf("%d %d", &N, &K);
        if (!N && !K) break;
        for (int i = 0; i < N; i++) {
            int x, y; scanf("%d %d", &x, &y);
            VX[i] = x; VY[i] = y;
        }

        sort(VX, VX+N); sort(VY, VY+N);

        int ret = INF, k, t;

        // Check VX.
        for (int i = 0; i < 1<<K; i++) {
            t = k = 0;
            for (int j = 0; j < K; j++) {
                if (j == K-1) {
                    t += abs((N-k)*K - N);
                    break;
                }
                bool ab = i&(1<<j);

                int p;
                if (ab) p = above(VX, k);
                else p = below(VX, k);

                t += abs(max(p-k,0)*K - N);
                k = p;
            }
            ret = min(ret, t);
        }

        // Check VY.
        for (int i = 0; i < 1<<K; i++) {
            t = k = 0;
            for (int j = 0; j < K; j++) {
                if (j == K-1) {
                    t += abs((N-k)*K - N);
                    break;
                }
                bool ab = i&(1<<j);

                int p;
                if (ab) p = above(VY, k);
                else p = below(VY, k);

                t += abs(max(p-k,0)*K - N);
                k = p;
            }
            ret = min(ret, t);
        }

        int d = gcd(ret, K*K);
        printf("%d. %d/%d\n", id++, ret/d, (K*K)/d);
    }

    return 0;
}
