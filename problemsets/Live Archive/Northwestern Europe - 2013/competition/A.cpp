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
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int,int> pii;

const int MAX_SET = 2020;

int up[MAX_SET];

void init(int n) { for (int i = 0; i < n; i++) up[i] = -1; }

int root(int k) { return up[k] < 0 ? k : (up[k] = root(up[k])); }

bool join(int k, int m) {
    if ((k = root(k)) == (m = root(m))) return false;
    if (up[k] < up[m]) up[k] += up[m], up[m] = k;
    else up[m] += up[k], up[k] = m;
    return true;
}

int C[2020][2020];
vector<int> adj[2020];

int cost(int u, int v, int p) {
    int ret;
    if (u == v) return ret = 0;
    ret = 1<<30;
    for (int i = 0; i < adj[u].size(); i++) {
        int a = adj[u][i];
        if (a == p) continue;
        ret = min(ret, C[u][a] + cost(a, v, u));
    }
    return ret;
}


int main() {

    int N;
    bool f = 1;
    while (scanf("%d", &N) != EOF) {
        if (!f) putchar('\n');
        f = 0;

        vector<pair<int,pii> > v;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            int x;
            scanf("%d", &x);
            C[i][j] = x;
            if (i == j) continue;
            v.push_back(make_pair(x,pii(i,j)));
        }

        sort(v.begin(), v.end());

        init(N);
        for (int i = 0; i < N; i++) {
            adj[i].clear();
        }

        vector<bool> U(v.size(), 0);
        for (int i = 0; i < v.size(); i++) {
            int a = v[i].second.first, b = v[i].second.second;
            if (join(a,b)) {
                adj[a].push_back(b);
                adj[b].push_back(a);
                U[i] = 1;
            }
        }

        bool ok = 0;
        for (int i = 0; i < v.size(); i++) if (!U[i]) {
            int a = v[i].second.first,
                b = v[i].second.second;
            if (cost(a,b,-1) > C[a][b]) {
                U[i] = 1;
                ok = 1;
                break;
            }
        }
        for (int i = 0; i < v.size(); i++) if (U[i])
            printf("%d %d %d\n", v[i].second.first+1, v[i].second.second+1, v[i].first);
        if (!ok) printf("%d %d %d\n", v[0].second.first+1, v[0].second.second+1, v[0].first);
    }

    return 0;
}
