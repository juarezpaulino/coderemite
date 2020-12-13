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

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(M) (M).begin(), (M).end()
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)(V.size())
#define PB push_back
#define MP make_pair

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = 0x3F3F3F3F;
const i64 LINF = 0x3F3F3F3F3F3F3F3FLL;
const double DINF = 1E14;
const double EPS = 1E-14;
const double PI = 3.1415926535897932384626433832795;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template<class T> T SQR(T x) { return x*x; }

template <class T> T gcd(T a, T b) { return (b!=0) ? gcd(b, a % b) : a; }

/*******************************************************************************
 * HASH
 * Primos
 * Médios: 5011 8837 8839 8849 8861 8863 8867 8887 8893 8923 8929 8933
 *         8941 8951 8963 8969 8971 8999 9001 9007 9011 9013 9029
 *         9041 9043 9049 9059 9067 9091 9103 9109 9127 9133 9137
 * Grandes: 80963,127597,263911,263927,413683,567899,713681
 *          37625701, 236422117, 9589487273, 9589487329, 694622169483311
 *
 ******************************************************************************/
struct STATE {
    int X[20], Y[20], deg;
    bool operator==(const STATE& S) const {
        for (int i = 0; i < 20; i++)
            if (X[i]!=S.X[i] || Y[i]!=S.Y[i]) return false;
        return true;
    }
};
#ifdef VCC
#include<hash_map>
#include<hash_set>
using namespace stdext;
#else
#include<ext/hash_map>
#include<ext/hash_set>
using namespace __gnu_cxx;
namespace __gnu_cxx {
	template<> struct hash<string> {
		size_t operator()(const string& X) const {
			return hash<const char*>() (X.c_str());
		}
	};
	template<> struct hash<STATE> {
		size_t operator()(const STATE& S) const {
            size_t p = 0;
            for (int i = 0; i < 20; i++) { p |= 1<<(S.Y[i]*6 + S.X[i]); }
            return p;
		}
	};
}
#endif

////////////////////////////////////////////////////////////////////////////////

const int MAXS = 50505;
const int MAXV = 16; 

char S[MAXS];
char B[MAXS][MAXV];
int K, NB, L;

////////////////////////////////////////////////////////////////////////////////
// Hamiltonian Cycle (TSP) - O(N*2^N) - Cycle starting and ending at final.
// 
// - N vertices.
// - Weight on adj[][].
// - pre-init DP[][] with -1.
//
int N;
int adj[MAXV][MAXV];
int DP[1<<MAXV][MAXV];
int solve(int used, int last, int final) {
    if (used == (1<<N)-1) return adj[last][final];
    int &ret = DP[used][last];
    if (ret != -1) return ret;
    ret = INF;
    FOR(i,0,N) if (!(used&(1<<i)))
        ret = min(ret, solve(used|(1<<i), i, final) + adj[last][i]);
    return ret;
}


int main() {
    
//	freopen("D.in","r",stdin);
//	freopen("D-small-practice.in","r",stdin);freopen("D-small-practice.out","w",stdout);
	freopen("D-large-practice.in","r",stdin);freopen("D-large-practice.out","w",stdout);
//	freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
//	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
//	freopen("D-small-attempt2.in","r",stdin);freopen("D-small-attempt2.out","w",stdout);
//	freopen("D-large.in","r",stdin);freopen("D-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        scanf("%d", &K); scanf("%s", S);
        
        // Construct block of k elements.
        L = strlen(S); NB = L / K;
        FOR(i,0,NB) FOR(j,0,K) B[i][j] = S[i*K + j];
        
        // Build adjacency weight matrix.
        CLR(adj,0);
        FOR(i,0,K) FOR(j,0,K) FOR(k,0,NB) adj[i][j] += B[k][i]!=B[k][j];
        
        // Try every possible last element and every first element as fixed
        // cost parameter. For each possibility sum up the hamiltonian cycle
        // excluding this two nodes.
        int ret = INF;
        N = K;
        FOR(i,0,N) FOR(j,0,N) if (i!=j) {
            int r = 0;
            FOR(k,0,NB-1) r += B[k][i]!=B[k+1][j];
            CLR(DP,-1); r += solve((1<<i)|(1<<j), j, i);
            ret = min(ret, r);
        }
        
        // Prints result.
        printf("Case #%d: %d\n", tc, ret+1);
    }

	return 0;
}
