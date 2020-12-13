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

int V[10000];
int P[10010];
int N, Q;

int main() {

    int T = 1;
    while (scanf("%d %d", &N, &Q)) {
        if (!(N|Q)) break;
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        sort(V, V+N);
        for (int i = 0; i <= 10000; i++) P[i] = -1;
        for (int i = 0; i < N; i++) if (P[V[i]]==-1) P[V[i]] = i+1;
        printf("CASE# %d:\n", T++);
        for (int i = 0; i < Q; i++) {
            int x;
            scanf("%d", &x);
            if (P[x]!=-1) printf("%d found at %d\n", x, P[x]);
            else printf("%d not found\n", x);
        }
    }

    return 0;
}
