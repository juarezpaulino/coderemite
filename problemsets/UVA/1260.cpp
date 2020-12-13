/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>

using namespace std;

vector<int> BIT;
vector<int> FREQ;

inline void bit_init(int K) { BIT = vector<int>(K+2, 0); FREQ = vector<int>(K+2, 0); }

inline void bit_add(size_t x, int v) {
    FREQ[x] += v;
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

inline void bit_scale(int c) {
    for (int i = 0; i < (int)BIT.size(); i++) BIT[i] *= c;
}

inline void bit_set(int x, int v) {
    int d = v-FREQ[x];
    bit_add(x, d);
    FREQ[x] = v;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        bit_init(5050);
        int ret = 0;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            ret += bit_get(x);
            bit_add(x, 1);
        }
        printf("%d\n", ret);
    }

    return 0;
}
