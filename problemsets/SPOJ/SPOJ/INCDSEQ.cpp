/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>


using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define SI(V) (int)V.size()
#define PB push_back

typedef long long i64;
typedef vector<int> VI;

const double EPS = 1E-14;

const int MAXV = 1<<14;

const int MOD = 5000000;

int SUM_BIT[60][MAXV];
int RED[60][MAXV];


inline void sum_bit_init() { memset(SUM_BIT, 0, sizeof(SUM_BIT)); }

int sum_bit_get(int k, int x) {
    int ret = 0;
    for(int i = x | MAXV; i < 2 * MAXV; i += i & -i)
        ret = (ret + SUM_BIT[k][i ^ MAXV]) % MOD;
    return ret;
}

void sum_bit_add(int k, int x, int v) {
    for(int i = x | MAXV; i; i &= i - 1)
        SUM_BIT[k][i ^ MAXV] = (SUM_BIT[k][i ^ MAXV] + v) % MOD;
}

int S[MAXV], S2[MAXV];
int N, K;

int main() {

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) scanf("%d", &S[i]);

    // Normalize S
    memcpy(S2, S, sizeof(S));
    sort(S2, S2+N);
    for(int i = 0; i < N; i++)
        S[i] = lower_bound(S2, S2+N, S[i]) - S2;

    int ret = 0;
    for(int i = N-1; i >= 0; i--) {
        for (int k = K; k >= 1; k--) {
            if (k == 1 && RED[k][S[i]]) continue;
            int add = (k==1) ? 1 : sum_bit_get(k-1, S[i] + 1);
            int r = RED[k][S[i]];
            RED[k][S[i]] = add;
            if (k > 1) add = (add - r + MOD) % MOD;
            sum_bit_add(k, S[i], add);
            if (k == K) ret = (ret + add) % MOD;
        }
    }

    printf("%d\n", ret);

	return 0;
}
