/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int V[3000];
int DP[2000][2000];

int go(int k, int a, int b) {
    int &ret = DP[a][b];
    if (a==b) return ret = k*V[a];
    if (ret != -1) return ret;
    return ret = max(V[a]*k + go(k+1, a+1, b), V[b]*k + go(k+1, a, b-1));
}

int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", V+i);

    memset(DP,-1,sizeof(DP));

    int ret = go(1,0,N-1);
    printf("%d\n", ret);

    return 0;
}
