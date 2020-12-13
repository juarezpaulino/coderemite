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

const int MAXV = 45;
const int MOD = 2*3*5*7;

char S[50];
i64 DP[50][MOD];
        
int main() {
    
//	freopen("B.in","r",stdin);
//	freopen("B-small-practice.in","r",stdin);freopen("B-small-practice.out","w",stdout);
	freopen("B-large-practice.in","r",stdin);freopen("B-large-practice.out","w",stdout);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        scanf("%s", S);
        memset(DP, 0, sizeof(DP));
        
        DP[0][0] = 1;
        int i; for (i = 0; S[i]; i++) for (int s = (i) ? -1 : 1; s <= 1; s+=2) {
            int c = 0;
            for (int j = i; S[j]; j++) {
                c = (c*10 + S[j]-'0') % MOD;
                for (int x = 0; x < MOD; x++)
                    DP[j+1][(x + s*c + MOD)%MOD] += DP[i][x];
            }
        }
        
        i64 ret = 0;
        for (int x = 0; x <= MOD; x++)
            if (x%2==0 || x%3==0 || x%5==0 || x%7==0) ret += DP[i][x];
        printf("Case #%d: %lld\n", tc, ret);
    }

	return 0;
}
