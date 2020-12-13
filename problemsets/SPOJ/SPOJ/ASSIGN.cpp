/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int C, N;
int V[20];
int VALID[20];

typedef long long i64;

i64 DP[1<<20];

i64 go(int k, int M) {
    if (k == N) return 1;
    i64 &ret = DP[M];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < N-k; i++) if (!(M&(1<<VALID[i])) && (V[k]&(1<<VALID[i]))) {
        int v = VALID[i];
        swap(VALID[i], VALID[N-k-1]);
        ret += go(k+1, M | (1<<v));
        swap(VALID[i], VALID[N-k-1]);
    }
    return ret;
}


int main() {

    scanf("%d", &C);
    while (C--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            V[i] = 0;
            for (int j = 0; j < N; j++) {
                char ch;
                while ((ch = getchar()) != '0' && ch != '1');
                if (ch == '1') V[i] |= 1<<j;
            }
        }

        memset(DP,-1,sizeof(DP));
        for (int i = 0; i < N; i++) VALID[i] = i;

        i64 ret = go(0,0);
        printf("%lld\n", ret);
    }

    return 0;
}
