/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int V[3];
char S[105];

int DP[101][4][10];

int go(int u, int t, int c) {
    int &ret = DP[u][t][c];
    if (ret != -1) return ret;
    int s = S[u]=='a' ? 0 : S[u]=='b' ? 1 : 2;
    if (!S[u+1]) return ret = (t == s) ? (V[s]<<c) : V[s];

    ret = go(u+1, t, c);
    ret = max(ret, (t == s) ? (V[s]<<c) + go(u+1,t,min(9,c+1)): V[s] + go(u+1, s, 1));
    return ret;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", V, V+1, V+2);
        scanf("%s", S);
        memset(DP,-1,sizeof(DP));
        int ret = 0;
        ret = go(0,3,0);
        printf("%d\n", ret);
    }

    return 0;
}
