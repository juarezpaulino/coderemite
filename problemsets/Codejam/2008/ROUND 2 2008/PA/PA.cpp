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

const int INF = 0x3F3F3F3F;
const double EPS = 1E-14;

const int MAXV = 10101;

int M, V;
int G[MAXV], C[MAXV], I[MAXV];
int DP[MAXV][2];

inline int apply(int a, int b, int op) {
    return (op) ? (a&b) : (a|b);
}

int go(int u, int v) {
    if (u > (M-1)/2) return (v==I[u])?0:INF;
    int &ret = DP[u][v];
    if (ret != -1) return ret;
    ret = INF;
    // All possible children combination.
    FOR(a,0,2) FOR(b,0,2) {
        if (apply(a,b,G[u])==v)
            ret = min(ret, go(u*2,a) + go(u*2+1,b));
        if (C[u] && apply(a,b,G[u]^1)==v)
            ret = min(ret, 1 + go(u*2,a) + go(u*2+1,b));
    }
    return ret;
}


int main() {
    
//	freopen("A.in","r",stdin);
//	freopen("A-small-practice.in","r",stdin);freopen("A-small-practice.out","w",stdout);
	freopen("A-large-practice.in","r",stdin);freopen("A-large-practice.out","w",stdout);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        scanf("%d%d", &M, &V);
        int i;
        for (i = 1; i <= (M-1)/2; i++) scanf("%d%d", &G[i], &C[i]);
        for (; i <= M; i++) scanf("%d", &I[i]);

        memset(DP, -1, sizeof(DP));
        int ret = go(1, V);
        if (ret == INF) printf("Case #%d: IMPOSSIBLE\n", tc);
        else printf("Case #%d: %d\n", tc, ret);
    }

	return 0;
}
