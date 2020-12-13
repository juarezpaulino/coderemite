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

const int INF = 0x3F3F3F3F;

int M, N;
int S[2][10000];
int INS[2][25000];
int DP[2][25000];

int go(int k, int p) {
    int v;

    if (k==0 && p==M) return 0;
    if (k==1 && p==N) return 0;

    int &ret = DP[k][S[k][p]+10000];
    if (ret != INF) return ret;
    ret = S[k][p] + go(k,p+1);
    if (INS[k^1][S[k][p]+10000]!=-1 && (v = S[k][p]+go(k^1,INS[k^1][S[k][p]+10000]+1)) > ret) ret = v;
    return ret;
}

int main() {

    while (1) {

        memset(INS,-1,sizeof(INS));

        scanf("%d", &M);
        if (!M) break;
        for (int i = 0; i < M; i++) {
            scanf("%d", &S[0][i]);
            INS[0][S[0][i]+10000] = i;
        }
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &S[1][i]);
            INS[1][S[1][i]+10000] = i;
        }

        memset(DP,INF,sizeof(DP));

        int ret = max(go(0,0),go(1,0));
        printf("%d\n", ret);
    }

    return 0;
}
