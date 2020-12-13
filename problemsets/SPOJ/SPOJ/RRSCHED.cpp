/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define SI(V) (int)(V.size())

typedef vector<int> VI;

struct Task { int p, v; };

int N;
Task T[50010];
long long RET[50010];

int BIT[50010];

inline void bit_add(int x, int v) {
    x++;
    while (x < N+2) { BIT[x] += v; x += x & -x; }
}

inline int bit_get(int x) {
    x++;
    int ans = 0;
    while (x) { ans += BIT[x]; x &= x - 1; }
    return ans;
}

bool comp(const Task &A, const Task &B) {
    if (A.v != B.v) return A.v < B.v;
    return A.p < B.p;
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &T[i].v);
        T[i].p = i;
        bit_add(i,1);
    }
    sort(T+1, T+N+1, comp);

    long long tot = 0;
    int l = 1, lp = 0;;
    for (int i = 1; i <= N; i++) {
        if (T[i].v!=l)
            tot = tot + bit_get(N) * (long long)(T[i].v-l);
        tot = tot + bit_get(T[i].p) - bit_get(lp);

        RET[T[i].p] = tot;

        bit_add(T[i].p, -1);
        l = T[i].v;
        lp = T[i].p;
    }

    for (int i = 1; i <= N; i++) printf("%lld\n", RET[i]);

    return 0;
}
