/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int V[9090];

int main() {

    int N;
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        V[N] = 0;
        sort(V, V+N+1);
        V[N+1] = V[N]+(1422-V[N])*2;
        bool ok = 1;
        for (int i = 1; i < N+2; i++)
            if (V[i]-V[i-1] > 200) { ok = 0; break; }
        if (ok) puts("POSSIBLE");
        else puts("IMPOSSIBLE");
    }

    return 0;
}
