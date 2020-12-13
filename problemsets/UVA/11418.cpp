/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

string P[30][30];

vector<int> adj[70];
int par[70], disc[70], id = 1;

int augment(int u) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (disc[v]==id) continue;
        disc[v] = id;
        if (par[v]==-1 || augment(par[v]))
            return (par[v]=u, par[u]=v, 1);
    }
    return 0;
}

int bpm(int M, int N) {
    int ret = 0;
    for (int i = 0; i < M+N; i++) par[i] = -1;
    for (int i = 0; i < M; i++) if (adj[i].size() && par[i]==-1) ++id, ret += augment(i);
    return ret;
}

int main() {

    char S[1010];
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:\n", t);
        int M;
        scanf("%d", &M);
        for (int i = 0; i < 26; i++) adj[M+i].clear();
        for (int i = 0; i < M; i++) {
            adj[i].clear();
            for (int j = 0; j < 26; j++) P[i][j] = "";
            int k; scanf("%d", &k);
            while (k--) {
                scanf("%s", S); S[0] = toupper(S[0]);
                if (S[0]-'A' >= M) continue;
                for (int j = 1; S[j]; j++) S[j] = tolower(S[j]);
                P[i][S[0]-'A'] = S;
                adj[i].push_back(M+S[0]-'A');
                adj[M+S[0]-'A'].push_back(i);
            }
        }
        bpm(M,26);
        vector<string> ret;
        for (int i = 0; i < M; i++) ret.push_back(P[i][par[i]-M]);
        sort(ret.begin(), ret.end());
        for (int i = 0; i < ret.size(); i++) puts(ret[i].c_str());
    }

    return 0;
}
