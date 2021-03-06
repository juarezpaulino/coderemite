/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: namenum
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

const int MAXV = 5000;

int main() {

    map<char, int> MAPA;
    MAPA['A'] = 2; MAPA['B'] = 2; MAPA['C'] = 2;
    MAPA['D'] = 3; MAPA['E'] = 3; MAPA['F'] = 3;
    MAPA['G'] = 4; MAPA['H'] = 4; MAPA['I'] = 4;
    MAPA['J'] = 5; MAPA['K'] = 5; MAPA['L'] = 5;
    MAPA['M'] = 6; MAPA['N'] = 6; MAPA['O'] = 6;
    MAPA['P'] = 7; MAPA['R'] = 7; MAPA['S'] = 7;
    MAPA['T'] = 8; MAPA['U'] = 8; MAPA['V'] = 8;
    MAPA['W'] = 9; MAPA['X'] = 9; MAPA['Y'] = 9;

    freopen("namenum.in","r",stdin);freopen("namenum.out","w",stdout);

    string NUM; cin >> NUM;

    freopen("dict.txt","r",stdin);

    bool NONE = true;
    string S;
    while (cin >> S) {
        if (SI(S) != SI(NUM)) continue;
        bool ok = true;
        FOR(i,0,SI(S)) if (MAPA[S[i]]!=NUM[i]-'0') { ok = false; break; }
        if (ok) NONE = false, cout << S << endl;
    }

    if (NONE) cout << "NONE" << endl;

    return 0;
}
