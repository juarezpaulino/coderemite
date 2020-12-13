/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int C[100] = {0};
int V[100][20] = {0};

int main() {

    char S[100];
    int TT;

    fgets(S, 100, stdin);
    sscanf(S, "%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {

        int A;

        fgets(S, 100, stdin);
        sscanf(S, "%d", &A);
        int K = (A+2)/3;
        priority_queue<pair<int,int> > q;
        for (int i = 2; i <= K-1; i++) q.push(make_pair((C[i] = 9), i));
        for (int i = 1; i <= K; i++) V[i][9] = V[i][10] = V[i][11] = 0;

        while (!q.empty()) {
            int v = q.top().first,
                p = q.top().second;
            if (v > C[p]) { q.pop(); continue; }

            printf("%d %d\n", p, 10);
            fflush(stdout);

            int y, x;
            fgets(S, 100, stdin);
            sscanf(S, "%d %d", &y, &x);
            if (!y && !x) break;
            if (y == -1 && x == -1) return 1;

            if (V[y][x]==tt) continue;
            V[y][x] = tt;
            if (y-1 > 1 && y-1 < K) q.push(make_pair(--C[y-1], y-1));
            if (y   > 1 &&   y < K) q.push(make_pair(--C[y],   y));
            if (y+1 > 1 && y+1 < K) q.push(make_pair(--C[y+1], y+1));
        }
    }
    return 0;
}
