/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int N, B, M;
int S[30], T[30], P[30];
int SUM[30], U[30];
int ret;

void go(int k, int v) {
    if (k == M) {
        if (v > ret) ret = v;
        return;
    }
    if (v + SUM[k] < ret) return;
    bool ok = 1;
    for (int i = S[k]; i < T[k]; i++) {
        U[i] += P[k];
        if (U[i] > N) ok = 0;
    }
    if (ok) go(k+1, v + (T[k]-S[k])*P[k]);
    for (int i = S[k]; i < T[k]; i++) U[i] -= P[k];
    go(k+1, v);
}

int main() {

    while (scanf("%d %d %d", &N, &B, &M)) {
        if (!(N|B|M)) break;
        int perm[30];
        for (int i = 0; i < 30; i++) perm[i] = i, SUM[i] = 0;
        random_shuffle(perm, perm+M);
        for (int i = 0; i < M; i++) scanf("%d %d %d", S+perm[i], T+perm[i], P+perm[i]);
        SUM[M-1] = (T[M-1]-S[M-1])*P[M-1]; for (int i = M-2; i >= 0; i--) SUM[i] = (T[i]-S[i])*P[i] + SUM[i+1];
        ret = 0;
        for (int i = 0; i <= B; i++) U[i] = 0;
        go(0, 0);
        printf("%d\n", ret);
    }

    return 0;
}
