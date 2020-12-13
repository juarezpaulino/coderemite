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
const int MOD = 1000000007;
int SUM_BIT[MAXV];
inline void sum_bit_init() { memset(SUM_BIT, 0, sizeof(SUM_BIT)); }
int sum_bit_get(int x) {
    int ret = 0;
    for(int i = x | MAXV; i < 2 * MAXV; i += i & -i)
        ret = (ret + SUM_BIT[i ^ MAXV]) % MOD;
    return ret;
}
void sum_bit_add(int x, int v) {
    for(int i = x | MAXV; i; i &= i - 1)
        SUM_BIT[i ^ MAXV] = (SUM_BIT[i ^ MAXV] + v) % MOD;
}

int S[MAXV], S2[MAXV];
i64 X, Y, Z, A[100];
int n, m;

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

        scanf("%d%d%lld%lld%lld", &n, &m, &X, &Y, &Z);
        for (int i = 0; i < m; i++) scanf("%lld", &A[i]);
        
        // Generates S.
        for (int i = 0; i < n; i++) {
            S[i] = A[i%m];
            A[i%m] = (X*A[i%m] + Y*(i+1)) % Z;
        }

        // Normalize S
        memcpy(S2, S, sizeof(S));
        sort(S2, S2+n);
        for(int i = 0; i < n; i++)
            S[i] = lower_bound(S2, S2+n, S[i]) - S2;

        // Calculate f(i) and sum them in to result.
        int ret = 0;
        sum_bit_init();
        for(int i = n - 1; i >= 0; i--) {
            int add = 1 + sum_bit_get(S[i] + 1);
            sum_bit_add(S[i], add);
            ret = (ret + add) % MOD;
        }
 
        printf("Case #%d: %d\n", tc, ret);
    }

	return 0;
}
