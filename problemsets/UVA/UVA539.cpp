/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <cctype>
    #include <cmath>
    #include <string>
    #include <algorithm>
    #include <sstream>
    #include <map>
    #include <set>
    #include <queue>
    #include <numeric>

    using namespace std;

    int N, M;
    int dest[50];
    int adj[25][25], nadj[25];

    map<pair<int,int>, int> DP;

    int go(int m, int k) {
        pair<int,int> node = make_pair(m,k);
        if (DP.count(node)) return DP[node];
        int ret = 0;
        for (int i = 0; i < nadj[k]; i++) if (!(m & (1<<(adj[k][i]/2)))) {
            int v = dest[adj[k][i]];
            ret = max(ret, go(m|(1<<(adj[k][i]/2)), v));
        }
        return DP[node] = ret + 1;
    }

    int main() {

        while (scanf("%d %d", &N, &M)) {
            if (!(N|M)) break;
            DP.clear();
            for (int i = 0; i < N; i++) nadj[i] = 0;
            for (int i = 0; i < M; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                adj[u][nadj[u]++] = 2*i;
                dest[2*i] = v;
                adj[v][nadj[v]++] = 2*i+1;
                dest[2*i+1] = u;
            }
            int ret = 0;
            for (int i = 0; i < N; i++) ret = max(ret,go(0,i));
            printf("%d\n", ret-1);
        }

        return 0;
    }
