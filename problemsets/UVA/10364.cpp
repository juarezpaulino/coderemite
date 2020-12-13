/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int M;
int V[21], S, used[21], SUM[21], side = -1, total;
bool ret;

void go(int s, int k, int done) {
    if (done == 4) { ret = 1; return; }

    if (done == 3) {
        if (S-total == side) { ret = 1; return; }
    }

    if (!used[k]) {
        used[k] = 1;

        int t = s+V[k];
        if (t == side)
            go(0,M-1,done+1);
        else if (s+SUM[k] >= side && t < side)
            go(t,k-1,done);

        if (ret) return;

        used[k] = 0;
    }

    if (k-1 >= 0 && s+SUM[k-1] >= side)
        go(s,k-1,done);
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &M);

        for (int i = 0; i < M; i++) scanf("%d", V+i);
        sort(V, V+M);
        S = SUM[0] = V[0]; for (int i = 1; i < M; i++) SUM[i] = (S += V[i]);
        side = S/4;

        if (S%4 != 0) { puts("no"); continue; }
        {
            bool ok = 1;
            for (int i = 0; i < M; i++) if (V[i] > side) ok = 0;
            if (!ok) { puts("no"); continue; }
        }

        ret = 0; total = 0;
        for (int i = 0; i < M; i++) used[i] = 0;
        int done = 0;
        for (int i = 0; i < M; i++) if (V[i] == side) { used[i] = 1; done++; total += side; }
        go(0,M-1,done);

        if (ret) puts("yes");
        else puts("no");
    }

    return 0;
}
