/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}

int adj[110][110];
int P[110][110];
string edge[110][110];
map<string,int> mapa;
vector<string> rmapa;
char S[1010101];

void go(int u, int v) {
    int k = P[u][v];
    if (k == -1) return;
    if (u==k||v==k) {
        printf("%-20s %-20s %-10s %5d\n", rmapa[u].c_str(), rmapa[v].c_str(), edge[u][v].c_str(), adj[u][v]);
        return;
    }
    go(u,k);
    go(k,v);
}

int main() {

    for (int i = 0; i < 100; i++) for (int j = 0; j < 100; j++) adj[i][j] = (i==j) ? 0 : 1<<29, P[i][j] = -1;
    while (gets(S)) {
        if (*S==0) break;
        vector<string> tok = tokenize(S,",");
        int u, v, c;
        if (mapa.count(tok[0]))
            u = mapa[tok[0]];
        else {
            u = rmapa.size();
            mapa[tok[0]] = u;
            rmapa.push_back(tok[0]);
        }
        if (mapa.count(tok[1]))
            v = mapa[tok[1]];
        else {
            v = rmapa.size();
            mapa[tok[1]] = v;
            rmapa.push_back(tok[1]);
        }
        c = atoi(tok[3].c_str());
        if (c < adj[u][v]) {
            adj[u][v] = adj[v][u] = c;
            edge[u][v] = edge[v][u] = tok[2];
            P[u][v] = v;
            P[v][u] = u;
        }
    }
    int N = rmapa.size();
    for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int d = adj[i][k]+adj[k][j];
        if (d < adj[i][j]) {
            adj[i][j] = d;
            P[i][j] = k;
        }
    }
    while (gets(S)) {
        if (*S==0) break;
        vector<string> tok = tokenize(S,",");
        int u = mapa[tok[0]], v = mapa[tok[1]];
        printf("\n\n");
        printf("From                 To                   Route      Miles\n");
        printf("-------------------- -------------------- ---------- -----\n");
        go(u,v);
        printf("                                                     -----\n");
        printf("                                          Total      %5d\n", adj[u][v]);

    }

    return 0;
}
