/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


int main() {

    int N, E[1010], S[1010];
    while (scanf("%d", &N) != EOF) {
        if (!N) break;
        priority_queue<int> q;
        for (int i = 0; i < N; i++) scanf("%d", E+i);
        for (int i = 0; i < N; i++) {
            scanf("%d", S+i);
            if (S[i]) q.push(S[i]);
        }
        sort(E, E+N, greater<int>());
        bool ok = 1;
        for (int i = 0; i < N; i++) {
            queue<int> next;
            for (int j = 0; j < E[i]; j++) {
                if (q.empty()) { ok = 0; break; }
                int u = q.top(); q.pop();
                u--; if (u) next.push(u);
            }
            if (!ok) break;
            while (!next.empty()) q.push(next.front()), next.pop();
        }
        if (!q.empty()) ok = 0;
        if (ok) puts("E");
        else puts("N");
    }

    return 0;
}
