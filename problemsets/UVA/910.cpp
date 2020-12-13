/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
char S[35];
vector<int> G[35];
int DP[35][35];

int go(int u, int k) {
    int &ret = DP[u][k];
    if (ret != -1) return ret;
    ret = 0;
    if (k == M) {
        if (S[u]) return ret = 1;
        return ret;
    }
    for (int i = 0; i < G[u].size(); i++) ret += go(G[u][i], k+1);
    return ret;
}

int main() {

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) G[i].clear(), S[i] = 0;
        for (int i = 0; i < N; i++) {
            char a, b, c, d;
            scanf(" %c %c %c %c ", &a, &b, &c, &d);
            if (d == 'x') S[a-'A'] = 1;
            G[a-'A'].push_back(b-'A');
            G[a-'A'].push_back(c-'A');
        }
        scanf("%d", &M);
        for (int i = 0; i < N; i++) for (int j = 0; j <= M; j++) DP[i][j] = -1;
        int ret = go(0,0);
        printf("%d\n", ret);
    }

    return 0;
}
