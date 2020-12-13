/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <sstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int MAXV = 5010;

int cap[MAXV][MAXV];
int adj[MAXV][MAXV], deg[MAXV];
int prev[MAXV];
int dinic(int N, int S, int T) {
    int flow = 0;
    for (int i = 0; i < N; i++) deg[i] = 0;
    for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++)
        if (cap[i][j] || cap[j][i])
            adj[i][deg[i]++] = j, adj[j][deg[j]++] = i;
    while(1) {
        // an augmenting path
        for (int i = 0; i < N; i++) prev[i] = -1;
        queue<int> q;
        q.push(S); prev[S] = -2;
        while(!q.empty() && prev[T]==-1) {
            int u = q.front(), v; q.pop();
            for (int i = 0; i < deg[u]; i++)
                if (prev[v=adj[u][i]]==-1 && cap[u][v])
                    q.push(v), prev[v] = u;
        }
        // done?
        if (prev[T] == -1) break;
        // try finding more paths
        for (int z = 0; z < N; z++) if (cap[z][T] && prev[z]!=-1) {
            int bot = cap[z][T];
            for (int v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                bot = min(bot,cap[u][v]);
            if (!bot) continue;
            cap[z][T]-=bot; cap[T][z]+=bot;
            for (int v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                cap[u][v]-=bot, cap[v][u]+=bot;
            flow+=bot;
        }
    }
    return flow;
}


int main() {

    char S[10101];
    int T;
    scanf("%d ", &T);
    while (T--) {
        vector<pair<int,pair<int, vector<int> > > > input;
        vector<string> M, P, C;
        map<string,int> mapM, mapP, mapC;
        while (gets(S)) {
            if (*S == 0) break;
            istringstream is(S);
            int u, v, w;
            int k = 0;
            while (is >> S) {
                if (k == 0) {
                    u = M.size(); mapM[S] = u; M.push_back(S);
                    input.push_back(pair<int,pair<int, vector<int> > >());
                    int l = input.size();
                    input[l-1].first = u;
                }
                else if (k == 1) {
                    if (!mapP.count(S)) { v = P.size(); mapP[S] = v; P.push_back(S); }
                    else v = mapP[S];
                    int l = input.size();
                    input[l-1].second.first = v;
                }
                else {
                    if (!mapC.count(S)) { w = C.size(); mapC[S] = w; C.push_back(S); }
                    else w = mapC[S];
                    int l = input.size();
                    input[l-1].second.second.push_back(w);
                }
                k++;
            }
        }

        int m = M.size(), p = P.size(), c = C.size();
        int n = p+m+c+2;
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) cap[i][j] = cap[j][i] = 0;
        for (int i = 0; i < p; i++) cap[n-2][i] = (c-1)/2;
        for (int i = 0; i < input.size(); i++) {
            int u = input[i].first, v = input[i].second.first;
            cap[v][p+u] = 1;
            for (int j = 0; j < input[i].second.second.size(); j++) {
                int w = input[i].second.second[j];
                cap[p+u][p+m+w] = 1;
            }
        }
        for (int i = 0; i < c; i++) cap[p+m+i][n-1] = 1;
        if (dinic(n,n-2,n-1) < c) puts("Impossible.");
        else {
            for (int i = 0; i < m; i++) {
                int u = p+i;
                for (int j = 0; j < c; j++) {
                    int w = p+m+j;
                    if (cap[u][w]==0 && cap[w][u])
                    printf("%s %s\n", M[i].c_str(), C[j].c_str());
                }
            }
        }

        if (T) putchar('\n');
    }

    return 0;
}
