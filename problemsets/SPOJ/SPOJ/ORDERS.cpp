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

vector<int> BIT;

inline void bit_init(int K) { BIT = VI(K+2, 0); }

inline void bit_add(size_t x, int v) {
    x++;
    while (x < BIT.size()) { BIT[x] += v; x += x & -x; }
}

inline int bit_get(size_t x) {
    x++;
    int ans = 0;
    while (x) { ans += BIT[x]; x &= x - 1; }
    return ans;
}

inline int bit_find(int s) {
    int l = -1, r = BIT.size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        (bit_get(m) >= s) ? r = m : l = m;
    }
    return r;
}


int T, N;
int V[200010];
int RET[200010];

int main() {

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N); bit_init(N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", V+i);
            bit_add(i,1);
        }

        for (int i = N; i > 0; i--) {
            RET[i] = bit_find(i-V[i]);
            bit_add(RET[i],-1);
        }

        printf("%d", RET[1]);
        for (int i = 2; i <= N; i++) printf(" %d", RET[i]);
        putchar('\n');
    }


    return 0;
}
