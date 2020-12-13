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
const double DINF = 1E16;
const double EPS = 1E-7;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////////////////////////////////////////////////////////////

const int MAXV = 600;
const int MOD = 10000;

string S1, S2;
int DP[MAXV][MAXV];

int main() {
    
//	freopen("C.in","r",stdin);
//	freopen("C-small-practice.in","r",stdin);freopen("C-small-practice.out","w",stdout);
	freopen("C-large-practice.in","r",stdin);freopen("C-large-practice.out","w",stdout);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.ans","w",stdout);

    int TC;
    scanf("%d ", &TC);
    S1 = "welcome to code jam";
    for (int tc = 1; tc <= TC; tc++) {
        
        getline(cin, S2);
        
        FOR(i,0,SI(S1)+1) DP[i][0] = 0;
        FOR(j,0,SI(S2)+1) DP[0][j] = 1;
        FOR(i,1,SI(S1)+1) FOR(j,1,SI(S2)+1) {
            DP[i][j] = DP[i][j-1];
            if (S1[i-1] == S2[j-1]) DP[i][j] = (DP[i][j] + DP[i-1][j-1]) % MOD;
        }
        
        printf("Case #%d: %04d\n", tc, DP[SI(S1)][SI(S2)]);
    }

	return 0;
}
