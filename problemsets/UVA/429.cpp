/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> mapa;
vector<int> adj[210];
int D[210];
char W[210][20];
int L[210];
int M;

int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        M = 0;
        mapa.clear();
        while (1) {
            scanf("%s ", W[M]);
            if (*W[M] == '*') break;
            L[M] = strlen(W[M]);
            adj[M].clear();
            mapa[W[M]] = M;
            M++;
        }
        for (int i = 0; i < M; i++) for (int j = i+1; j < M; j++) if (L[i]==L[j]) {
            int d = 0;
            for (int k = 0; k < L[i]; k++) if (W[i][k] != W[j][k]) d++;
            if (d == 1) adj[i].push_back(j), adj[j].push_back(i);
        }
        char S[101];
        while (gets(S)) {
            if (*S == 0) break;
            char A[20], B[20];
            sscanf(S, "%s %s", A, B);
            int s = mapa[A], t = mapa[B];
            queue<int> q;
            q.push(s);
            memset(D, 0x3F3F3F3F, sizeof(D));
            D[s] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i];
                    if (D[v] == 0x3F3F3F3F) {
                        D[v] = D[u] + 1;
                        q.push(v);
                    }
                }
            }
            printf("%s %s %d\n", A, B, D[t]);
        }
        if (T) putchar('\n');
    }

    return 0;
}
