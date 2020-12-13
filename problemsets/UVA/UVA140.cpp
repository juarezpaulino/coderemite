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

using namespace std;

char S[300];
map<char,int> MAPA;
char V[10];
int N;
vector< vector<int> > adj;
int O[10];
int P[10];

int main() {

    while (gets(S)) {
        if (*S=='#') break;
        MAPA.clear();
        adj.clear();
        N = 0;
        for (int i = 0; S[i]; ) {
            int u, v;
            if (!MAPA.count(S[i])) { u = MAPA.size(); MAPA[S[i]] = u; V[u] = S[i]; adj.push_back(vector<int>()); N++; }
            else u = MAPA[S[i]];
            i += 2;
            while (S[i] && S[i]!=';') {
                if (!MAPA.count(S[i])) { v = MAPA.size(); MAPA[S[i]] = v; V[v] = S[i]; adj.push_back(vector<int>()); N++; }
                else v = MAPA[S[i]];
                adj[u].push_back(v);
                i++;
            }
            if (S[i]) i++;
        }
        string ret;
        int m = 20;
        for (int i = 0; i < N; i++) O[i] = i;
        do {
            for (int i = 0; i < N; i++) P[O[i]] = i;
            int t = 0;
            for (int i = 0; i < N; i++) if (adj[O[i]].size()) {
                int k = 0;
                int u = O[i], v;
                for (int j = 0; j < adj[u].size(); j++) {
                    v = adj[u][j];
                    k = max(k, abs(P[v]-i));
                    if (k > m) break;
                }
                if (k > t) t = k;
                if (t > m) break;
            }
            string s;
            s = V[O[0]];
            for (int i = 1; i < N; i++) s += " " + string(1, V[O[i]]);
            if (t < m || (t==m && s < ret)) m = t, ret = s;
        } while (next_permutation(O, O+N));

        printf("%s -> %d\n", ret.c_str(), m);
    }

    return 0;
}
