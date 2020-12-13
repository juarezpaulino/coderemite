/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: contact
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
const double DINF = 1E16;
const double EPS = 1E-14;
const double PI = 3.1415926535897932384626433832795;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template<class T> T SQR(T x) { return x*x; }

template <class T> T gcd(T a, T b) { return (b!=0) ? gcd(b, a % b) : a; }

inline string ITOA(int a) { char c[500]; sprintf(c,"%d",(a)); return string(c); }

inline int POPC(int a) { return __builtin_popcount(a); }

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

int A, B, N;

struct Seq {
    int seq, c;
    bool operator<(const Seq &B) const {
        if (c != B.c) return c > B.c;
        return seq < B.seq;
    }
};

Seq S[1<<13];

string T;

void add(int b, int n) {
    int v = b & ((1<<n)-1);
    v |= 1<<n;
    S[v].c++;
}

void print(int b) {
    if (b == 1) return;
    print(b/2);
    putchar('0'+(b%2));
}

int main() {

    freopen("contact.in","r",stdin);freopen("contact.out","w",stdout);

    FOR(i,0,(1<<13)) S[i].seq = i;

    scanf("%d%d%d", &A, &B, &N);
    string t;
    while (cin >> t) T += t;

    int bit = 0, nbit = 0;
    FOR(i,0,SI(T)) {
        bit <<= 1;
        if (T[i]=='1') bit |= 1;

        if (nbit < B) nbit++;

        FOR(j,A,nbit+1) add(bit,j);
    }

    sort(S, S+(1<<13));

    int i = 0;
    FOR(k,0,N) {
        int c = S[i].c;
        if (c == 0) continue;
        printf("%d\n", c);
        char *l = "";
        for (int j = 0; S[i].c == c; j++) {
            printf(l);
            print(S[i].seq);
            (j%6==5) ? l = "\n" : l = " ";
            i++;
        }
        putchar('\n');
    }

    return 0;
}
