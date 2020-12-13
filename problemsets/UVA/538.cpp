/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


int main() {

    int C = 1;
    int N, T;
    while (scanf("%d %d", &N, &T) != EOF) {
        if (!(N+T)) break;
        char S[1010], R[1010];
        map<string,int> mapa;
        string rev[30];
        int V[30] = {0};
        for (int i = 0; i < N; i++) scanf("%s", S), mapa[S] = i, rev[i] = S;
        for (int i = 0; i < T; i++) {
            int u;
            scanf("%s %s %d", R, S, &u);
            int r = mapa[R], s = mapa[S];
            V[r] += u;
            V[s] -= u;
        }
        printf("Case #%d\n", C++);
        queue<int> pos, neg;
        for (int i = 0; i < N; i++)
            if (V[i] > 0) pos.push(i);
            else neg.push(i);
        while (!pos.empty()) {
            int u = pos.front(); pos.pop();
            while (V[u]) {
                int v = neg.front();
                int k = min(V[u], -V[v]);
                V[u] -= k; V[v] += k;
                if (V[v] == 0) neg.pop();
                printf("%s %s %d\n", rev[v].c_str(), rev[u].c_str(), k);
            }
        }
        putchar('\n');
    }

    return 0;
}
