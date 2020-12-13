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

inline int bit_get_interval(int a, int b) {
    return bit_get(b) - bit_get(a-1);
}

inline int bit_find(int s) {
    int l = -1, r = BIT.size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        (bit_get(m) >= s) ? r = m : l = m;
    }
    return r;
}

int N;
int RET[20100];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        bit_init(N);
        for (int i = 0; i < N; i++) bit_add(i,1);
        int p = 0;
        for (int i = 0; i < N; i++) {
            p += i+1;
            p %= N - i;
            int k = bit_find(p+1);
            RET[k] = i + 1;
            bit_add(k, -1);
        }
        printf("%d", RET[0]);
        for (int i = 1; i < N; i++) printf(" %d", RET[i]);
        putchar('\n');
    }

    return 0;
}
