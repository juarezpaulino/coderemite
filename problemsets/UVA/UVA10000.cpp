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

const int INF = 0x3F3F3F3F;

vector<int> rev[100];
int D[100], L[100], DEG[100];
int N, S;

int main() {

    int T = 1;

    while (scanf("%d", &N)) {

        if (!N) break;

        for (int i = 0; i < N; i++)
            D[i] = -1,
            L[i] = -1,
            DEG[i] = 0,
            rev[i].clear();
        scanf("%d", &S);

        int u, v;
        while (scanf("%d %d", &u, &v)) {
            if (!(u|v)) break;
            rev[v-1].push_back(u-1);
            DEG[u-1]++;
        }

        // Get the leaves.
        queue<int> Q;
        for (int i = 0; i < N; i++)
            if (DEG[i] == 0)
                Q.push(i), D[i] = 0, L[i] = i;

        // Process in toporder.
        while (!Q.empty()) {
            u = Q.front(); Q.pop();
            if (u == S-1) break;
            for (int i = 0; i < rev[u].size(); i++) {
                v = rev[u][i];
                if (D[v] < D[u]+1 || (D[v] == D[u]+1 && L[v] > L[u])) {
                    D[v] = D[u]+1;
                    L[v] = L[u];
                }
                DEG[v]--;
                if (DEG[v]==0) Q.push(v);
            }
        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", T++, S, D[S-1], L[S-1]+1);
    }

    return 0;
}
