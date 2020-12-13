/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>


using namespace std;

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define ALL(M) (M).begin(), (M).end()
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)(V.size())
#define PB push_back

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;

const int INF = 0x3F3F3F3F;
const double EPS = 1E-14;

template<class T> T SQR(T x) { return x*x; }

////////////////////////////////////////////////////////////////////////////////

const int MAXV = 41;

double DP[MAXV];
double P[MAXV][MAXV];
int C, N;

double solve(int R) {
    double &ret = DP[R];
    if (ret > -EPS) return ret;
    ret = 0;
    double tmp, p = 0;
    FOR(i,1,N+1) {
        tmp = P[R][i] * P[C-R][N-i] / P[C][N];
        if (R-i >= 0) ret += tmp * solve(R-i), p += tmp;
    }
    ret = (ret + 1.) / p;
    return ret;
}

int main() {
    
//	freopen("C.in","r",stdin);
//	freopen("C-small-practice.in","r",stdin);freopen("C-small-practice.out","w",stdout);
  freopen("C-large-practice.in","r",stdin);freopen("C-large-practice.out","w",stdout);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.ans","w",stdout);

    FOR(j,0,MAXV) P[0][j] = 0.;
    P[0][0] = 1.;
    FOR(i,0,MAXV) {
        P[i][0] = 1.; FOR(j,1,MAXV) P[i][j]=P[i-1][j]+P[i-1][j-1];
    }

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        scanf("%d %d", &C, &N);
        
        // Compute.
        FOR(i,1,C+1) DP[i] = -1; DP[0] = 0;
        double ret = solve(C);
        
        // Prints result.
        printf("Case #%d: %.8lf\n", tc, ret);
    }

	return 0;
}
