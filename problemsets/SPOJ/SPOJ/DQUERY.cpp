/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define SI(V) (int)(V.size())

typedef vector<int> VI;

struct Query { int a, b, p; };

Query Q[200100];
int A[30100];
int N, q;
int L[1000100];
int RET[200100];

int BIT[30100];

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

bool comp(const Query &A, const Query &B) {
    if (A.b != B.b) return A.b < B.b;
    return A.a < B.a;
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", A+i);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        Q[i] = (Query){a,b,i};
    }
    sort(Q+1, Q+q+1, comp);

    int j = 0;
    for (int i = 1; i <= q; i++) {
        while (j < Q[i].b) {
            j++;
            if (L[A[j]]) bit_add(L[A[j]],-1);
            bit_add(j,1);
            L[A[j]] = j;
        }
        RET[Q[i].p] = bit_get(Q[i].b) - bit_get(Q[i].a-1);
    }

    for (int i = 1; i <= q; i++) printf("%d\n", RET[i]);

    return 0;
}
