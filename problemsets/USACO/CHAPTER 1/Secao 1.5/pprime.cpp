/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: pprime
 LANG: C++
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
#define FI first
#define SE second
#define SORT(M) sort(ALL(M))
template<class T> inline void SORTG(vector<T> &M) { sort(ALL(M), greater<T>()); }
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())

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

inline string ITOA(int a) { char c[500]; sprintf(c,"%d",(a)); return string(c); }

/*******************************************************************************
 * HASH
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

int A, B;
VI RET;

#define MAXV 10000010
char PR[MAXV];
vector<int> pr;
void GENPR() {
    fill(PR+2, PR+MAXV, 1);
    for (int i = 4; i < MAXV; i+=2) PR[i] = 0;
    for (i64 i = 3; i < MAXV; i+=2) if (PR[i]) {
        for (i64 j = i*i; j < MAXV; j += 2*i) PR[j] = 0;
    }
}


////////////////////////////////////////////////////////////////////////////////
// Generate Palindromic numbers.
////////////////////////////////////////////////////////////////////////////////
const int MAXD = 7;             // Max digits on palindrome.
void GENPAL() {
    int l;
    // Generate all even palindromes.
    l = atoi(string(MAXD/2,'9').c_str());
    FOR(i,1,l+1) {
        int p, x; p = i; x = i;
        while (x) { p = p*10 + x%10; x/=10; }
        // do stuff with even digit palindrome p.
        if (p > B) break;
        if (p >= A && p <= B && PR[p]) RET.PB(p);
    }

    // Generate all odd palindromes.
    l = atoi(string((MAXD+1)/2,'9').c_str());
    FOR(i,0,l+1) {
        int p, x; p = i/10; x = i;
        while (x) { p = p*10 + x%10; x/=10; }
        // do stuff with odd digit palindrome p.
        if (p > B) break;
        if (p >= A && p <= B && PR[p]) RET.PB(p);
    }
}

int main() {

    freopen("pprime.in","r",stdin);freopen("pprime.out","w",stdout);

    scanf("%d%d", &A, &B);

    GENPR();
    GENPAL();

    SORT(RET);
    FOR(i,0,SI(RET)) printf("%d\n", RET[i]);

    return 0;
}
