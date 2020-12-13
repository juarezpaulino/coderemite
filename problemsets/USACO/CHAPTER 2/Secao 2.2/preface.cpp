/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: preface
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

const int MAXS = 7;

int N;
int RET[MAXS];
map<char,int> MAPA;

string fill(char c, int n) {
    string s; while(n--) s += c; return s;
}

string toRoman(int n) {
    if(n < 4) return fill('I', n);
    if(n < 6) return fill('I', 5-n) + "V";
    if(n < 9) return string("V") + fill('I', n-5);
    if(n < 11) return fill('I', 10-n) + "X";
    if(n < 40) return fill('X', n/10) + toRoman(n%10);
    if(n < 60) return fill('X', 5-n/10) + 'L' + toRoman(n%10);
    if(n < 90) return string("L") + fill('X', n/10-5) + toRoman(n%10);
    if(n < 110) return fill('X', 10-n/10) + "C" + toRoman(n%10);
    if(n < 400) return fill('C', n/100) + toRoman(n%100);
    if(n < 600) return fill('C', 5-n/100) + 'D' + toRoman(n%100);
    if(n < 900) return string("D") + fill('C', n/100-5) + toRoman(n%100);
    if(n < 1100) return fill('C', 10-n/100) + "M" + toRoman(n%100);
    if(n < 4000) return fill('M', n/1000) + toRoman(n%1000);
    return "?";
}


int main() {

    MAPA['I'] = 0;
    MAPA['V'] = 1;
    MAPA['X'] = 2;
    MAPA['L'] = 3;
    MAPA['C'] = 4;
    MAPA['D'] = 5;
    MAPA['M'] = 6;

    freopen("preface.in","r",stdin);freopen("preface.out","w",stdout);

    scanf("%d", &N);

    FOR(P,1,N+1) {
        string V = toRoman(P);
        FOR(i,0,SI(V)) RET[MAPA[V[i]]]++;
    }

    if (RET[0]!=0) printf("I %d\n", RET[0]);
    if (RET[1]!=0) printf("V %d\n", RET[1]);
    if (RET[2]!=0) printf("X %d\n", RET[2]);
    if (RET[3]!=0) printf("L %d\n", RET[3]);
    if (RET[4]!=0) printf("C %d\n", RET[4]);
    if (RET[5]!=0) printf("D %d\n", RET[5]);
    if (RET[6]!=0) printf("M %d\n", RET[6]);

    return 0;
}
