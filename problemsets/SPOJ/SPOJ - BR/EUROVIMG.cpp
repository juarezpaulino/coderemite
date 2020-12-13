/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

map<string,int> M;

inline int get_nome(char *S) {
    int x = M.size();
    if (!M.count(S)) return M[S] = x;
    else return M[S];
}

int main() {

    int T, N;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        M.clear();
        set<int> adj[10];
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            char S[100];
            scanf("%s", S);
            int u = get_nome(S);
            int k; scanf("%d", &k);
            while (k--) {
                scanf("%s", S);
                adj[u].insert(get_nome(S));
            }
        }

        int p[10], ret = 0;
        for (int i = 0; i < N; i++) p[i] = i;
        do {
            bool ok = 1;
            for (int i = 0; ok && i < N; i++) {
                if (i > 0 && adj[p[i]].count(p[i-1])) ok = 0;
                if (i < N-1 && adj[p[i]].count(p[i+1])) ok = 0;
            }
            if (ok) ret++;
        } while (next_permutation(p, p+N));
        printf("Teste #%d: %d\n", t, ret);
    }

    return 0;
}
