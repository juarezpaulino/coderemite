/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3F3F3F3F;

int N;
int V[100][100];
int DP[100][100];

int go(int a, int b) {
    int &ret = DP[a][b];
    if (ret != -1) return ret;
    if (a==b) return ret = 0;
    ret = INF;
    for (int i = a; i < b; i++)
        ret = min(ret, V[a][i]*V[i+1][b] + go(a,i) + go(i+1,b));
    return ret;
}

int main() {

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) scanf("%d", &V[i][i]);

        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++)
            V[i][j] = (V[i][j-1] + V[j][j]) % 100;
        memset(DP,-1,sizeof(DP));

        int ret = go(0,N-1);
        printf("%d\n", ret);
    }

    return 0;
}
