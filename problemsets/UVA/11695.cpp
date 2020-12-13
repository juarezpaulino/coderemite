/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<int,int> pii;

int N;
vector<int> adj[2505], adj1[2505], adj2[2505];
int deg[2505], D[2505], vis[2505], par[2505];

vector<int> tree_center(vector<int> adj[], set<int> &in, int &diam, pii &far) {
    if (in.size()==1) {
        diam = 0;
        return vector<int>(1,*in.begin());
    }
    queue<int> q;
    for (int i = 0; i < N; i++) {
        deg[i] = adj[i].size(), D[i] = 0, par[i] = -1;
        if (deg[i]==1 && in.count(i)) q.push(i), par[i] = i;
    }
    vector<int> ret;
    int l = q.size(), k = 1, e = 0;
    while (!q.empty()) {
        int m = 0;
        ret.clear();
        while (l--) {
            int u = q.front(), v; q.pop();
            deg[u] = 0;
            ret.push_back(u);
            for (int i = 0; i < adj[u].size(); i++) if (deg[(v = adj[u][i])] >= 1 && in.count(v)) {
                far = pii(par[u],par[v]);
                diam = D[v]+k;
                D[v] = k;
                if (--deg[v]==1) q.push(v), par[v] = par[u], m++;
            }
        }
        l = m;
        k++;
    }
    return ret;
}

void dfs_diam(int u, int a, int b, int d, vector<pii> &E) {
    vis[u] = 1;
    if (d >= 2) return;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v] && (par[v]==a||par[v]==b)) {
            par[v] = u;
            E.push_back(pii(u,v));
            dfs_diam(v,a,b,d+1,E);
        }
    }
}

void dfs(vector<int> G[], set<int> &in, int u, int out) {
    vis[u] = 1;
    in.insert(u);
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != out && !vis[v]) {
            G[u].push_back(v);
            G[v].push_back(u);
            dfs(G,in,v,out);
        }
    }
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        set<int> in, in1, in2;
        int diam, diam1, diam2;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) adj[i].clear(), in.insert(i);
        for (int i = 0; i < N-1; i++) {
            int u, v;
            scanf("%d %d", &u, &v); u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        pii far;
        vector<int> c = tree_center(adj,in,diam,far);
        for (int i = 0; i < N; i++) vis[i] = 0;
        vector<pii> E;
        dfs_diam(c[0], far.first, far.second, 0, E);
        int ret = 1<<29;
        pii retout, retin;
        for (int k = 0; k < E.size(); k++) {
            in1.clear(); in2.clear();
            for (int i = 0; i < N; i++) vis[i] = 0, adj1[i].clear();
            dfs(adj1,in1,E[k].first,E[k].second);
            vector<int> c1 = tree_center(adj1,in1,diam1,far);
            for (int i = 0; i < N; i++) vis[i] = 0, adj2[i].clear();
            dfs(adj2,in2,E[k].second,E[k].first);
            vector<int> c2 = tree_center(adj2,in2,diam2,far);
            for (int i = 0; i < N; i++) {
                adj1[i].clear();
                for (int j = 0; j < adj[i].size(); j++) {
                    int v = adj[i][j];
                    if ((i==E[k].first&&v==E[k].second) || (i==E[k].second&&v==E[k].first)) continue;
                    adj1[i].push_back(v);
                }
            }
            adj1[c1[0]].push_back(c2[0]);
            adj1[c2[0]].push_back(c1[0]);
            tree_center(adj1,in,diam,far);
            if (diam < ret) { ret = diam; retout = E[k]; retin = make_pair(c1[0], c2[0]); }
        }
        if (retout.first > retout.second) swap(retout.first,retout.second);
        if (retin.first > retin.second) swap(retin.first,retin.second);
        printf("%d\n", ret);
        printf("%d %d\n", retout.first+1, retout.second+1);
        printf("%d %d\n", retin.first+1, retin.second+1);
    }

    return 0;
}
