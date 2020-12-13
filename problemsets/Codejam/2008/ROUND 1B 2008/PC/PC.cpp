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

const int MAXV = 1<<20;
const int MAXQ = 110;

VI BIT;

inline void bit_add(size_t x, int v) {
    x++; while (x < BIT.size()) { BIT[x] += v; x += x & -x; }
}

inline int bit_get(size_t x) {
    x++; int ans = 0;
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


int DECK[MAXV];
int K, N, M, D[110];

        
int main() {
    
//	freopen("C.in","r",stdin);
//	freopen("C-small-practice.in","r",stdin);freopen("C-small-practice.out","w",stdout);
	freopen("C-large-practice.in","r",stdin);freopen("C-large-practice.out","w",stdout);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        scanf("%d%d", &K, &N);
        for (int i = 0; i < N; i++) scanf("%d", &D[i]), D[i]--;
        
        fill(DECK, DECK+K, -1);
        BIT = VI(K+2, 0);
        for (int i = 0; i < K; i++) bit_add(i, 1);
        
        int p = 0;
        for (int i = 0; i < K; i++) {
            p += i;
            p %= K - i;
            int k = bit_find(p + 1);
            DECK[k] = i + 1;
            bit_add(k, -1);
        }

        printf("Case #%d:", tc);
        for (int i = 0; i < N; i++) printf(" %d", DECK[D[i]]);
        putchar('\n');
    }

	return 0;
}
