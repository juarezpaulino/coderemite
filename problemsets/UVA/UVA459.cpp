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

int adj[30][100];
int nadj[30], V[30];
int N;

void DFS(int u) {
    V[u] = 1;
    for (int i = 0; i < nadj[u]; i++) {
        int v = adj[u][i];
        if (!V[v]) DFS(v);
    }
}


int main() {

    int T;
    char S[100];
    scanf("%d ", &T);
    while (T--) {
        char u, v;
        if (!gets(S) || !*S) return 0;
        sscanf(S, "%c", &u);
        N = u-'A'+1;
        while (gets(S)) {
            if (!*S) break;
            sscanf(S, "%c%c", &u, &v);
            adj[u-'A'][nadj[u-'A']++] = v-'A';
            adj[v-'A'][nadj[v-'A']++] = u-'A';
        }
        int ret = 0;
        for (int i = 0; i < N; i++) V[i] = 0;
        for (int i = 0; i < N; i++) if (!V[i]) DFS(i), ret++;
        printf("%d\n", ret);
        if (T) putchar('\n');
        for (int i = 0; i < N; i++) nadj[i] = 0;
    }

    return 0;
}
