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


vector<int> BA;

inline void bit_init(VI &BIT, int K) { BIT = VI(K+2, 0); }

inline void bit_add(VI &BIT, size_t x, int v) {
    x++;
    while (x < BIT.size()) { BIT[x] += v; x += x & -x; }
}

inline int bit_get(VI &BIT, size_t x) {
    x++;
    int ans = 0;
    while (x) { ans += BIT[x]; x &= x - 1; }
    return ans;
}

int N;
int A[300100], H[300100], ord[300100], OUT[301000];

bool comp(const int &a, const int &b) {
    return A[a] != A[b] ? A[a] < A[b] : H[a] < H[b];
}

int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", A+i, H+i);
        ord[i] = i;
    }
    sort(ord, ord+N, comp);

    bit_init(BA,100100);
    int s = 0;
    for (int i = 0; i < N; i++) {
        if (i && A[ord[i]]==A[ord[i-1]] && H[ord[i]]==H[ord[i-1]]) {
            bit_add(BA, H[ord[i]], 1);
            OUT[ord[i]] = s;
            continue;
        }
        s = bit_get(BA, H[ord[i]]);
        bit_add(BA, H[ord[i]], 1);
        OUT[ord[i]] = s;
    }

    for (int i = 0; i < N; i++) printf("%d\n", OUT[i]);

    return 0;
}
