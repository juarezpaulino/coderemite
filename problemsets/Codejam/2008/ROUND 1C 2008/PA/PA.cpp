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

const int MAXV = 1000;

int P, K, L;
i64 F[MAXV];
        
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

        scanf("%d%d%d", &P, &K, &L);
        FOR(i,0,L) scanf("%lld", &F[i]);
        sort(F, F+L, greater<i64>());
        
        i64 ret = 0;
        FOR(i,0,L) ret += (i/K + 1) * F[i];
        printf("Case #%d: %lld\n", tc, ret);
    }

	return 0;
}
