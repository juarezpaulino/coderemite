/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

using namespace std;

int V[202];
int N, Q, D, M;
long long DP[202][50][11];

long long go(int i, int j, int k) {
    long long &ret = DP[i][j+25][k];
    if (ret != -1) return ret;
    if (k == M) return ret = (j == 0) ? 1 : 0;
    if (i == N) return ret = 0;
    ret = go(i+1, j, k);
    ret += go(i+1, (j+(V[i]%D))%D, k+1);
    return ret;
}


int main() {

    int T = 1;
    while (scanf("%d %d", &N, &Q) && (N|Q)) {
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        printf("SET %d:\n", T++);
        for (int q = 1; q <= Q; q++) {
            scanf("%d %d", &D, &M);
            memset(DP, -1, sizeof(DP));
            printf("QUERY %d: %lld\n", q, go(0, 0, 0));
        }
    }

    return 0;
}
