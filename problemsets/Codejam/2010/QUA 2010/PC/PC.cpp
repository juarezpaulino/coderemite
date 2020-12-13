/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <string>
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
#include <cstring>
#include <ctime>
#include <cassert>


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

const int MAXV = 1010;

i64 PROFIT[MAXV];
int NEXT[MAXV], PAI[MAXV];
int PC, L; i64 C;

int R, K, N;
int G[MAXV];

int main() {
    
//	freopen("C.in","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.ans","w",stdout);

    int p, q;
    i64 s;

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        scanf("%d%d%d", &R, &K, &N);
        FOR(i,0,N) scanf("%d", &G[i]);
        
        // Initialize.
        CLR(PAI,-1); CLR(NEXT,-1); CLR(PROFIT,0);
        
        // Pre-compute cycle and next values.
        q = 0;
        while (NEXT[q]==-1) {
            s = 0; p = q;
            do { s += G[q]; q = (q+1)%N; } while (s+G[q] <= K && q != p);
            PROFIT[p] = s; NEXT[p] = q; PAI[q] = p;
        }
        PC = q; C = 0; L = 0;
        do { q = PAI[q]; C += PROFIT[q]; L++; } while (q != PC);
        
        // Compute total profit.
        i64 ret = 0;
        for (p = 0; p != PC && R; R--, p = NEXT[p]) ret += PROFIT[p];
        ret += C*(R/L); R -= L*(R/L);
        for (p = PC; R; R--, p = NEXT[p]) ret += PROFIT[p];
        
        // Prints result.
        printf("Case #%d: %lld\n", tc, ret);
    }

	return 0;
}
