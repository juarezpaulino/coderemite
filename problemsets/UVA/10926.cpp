/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int DP[110];
int N;
vector<int> adj[110];

int go(int k) {
    int &ret = DP[k];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < adj[k].size(); i++) ret = max(ret, go(adj[k][i])+1);
    return ret;
}

int main() {

    while (scanf("%d", &N) != EOF) {
        if (!N) break;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            int T, x;
            scanf("%d", &T);
            for (int j = 0; j < T; j++) {
                scanf("%d", &x);
                adj[i].push_back(x);
            }
        }
        memset(DP, -1, sizeof(DP));
        int ret = -1, maxi = -1;
        for (int i = 1; i <= N; i++) {
            int x = go(i);
            if (x > maxi) ret = i, maxi = x;
        }
        printf("%d\n", ret);
    }

    return 0;
}
