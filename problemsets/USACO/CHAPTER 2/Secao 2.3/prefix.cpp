/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: prefix
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

const int MAXV = 200010;
const int MAXL = 10;

string S; int N;
int ret;
char V[MAXV];

/*char vis[MAXV];

void go(int k) {
    vis[k] = 1;
    ret = max(ret, k);
    FOR(i,0,M) if (SI(P[i]) <= N-k) {
        bool ok = true;
        FOR(j,0,SI(P[i])) if (P[i][j]!=S[k+j]) { ok = false; break; }
        if (ok && !vis[k + SI(P[i])]) go(k + SI(P[i]));
    }
}*/

const int MAXD = 26;

struct Trie {
    int count;
    Trie *next[MAXD];
};

// Return new node.
Trie *trie_new() {
	Trie *t = new Trie;
	FOR(i,0,MAXD) t->next[i] = NULL;
	t->count = 0;
	return t;
}

// Delete entire trie if passed a pointer for root.
void trie_delete(Trie *R) {
	if (R) {
	    FOR(i,0,MAXD) trie_delete(R->next[i]);
		delete(R);
	}
}

// Add node by running word from root until reach some leaf.
void trie_add(Trie *R, char *W) {
    while (*W) {
        int v = *W-'A';
        if (!R->next[v]) R->next[v] = trie_new();
        R = R->next[v];
        W++;
	}
	R->count++;
}

Trie *T = trie_new();

int main() {

    char R[80];
    Trie *U;

    freopen("prefix.in","r",stdin);freopen("prefix.out","w",stdout);

    while (1) {
        scanf("%s", R);
        if (R[0]=='.') break;
        int l = strlen(R); reverse(R, R+l);
        trie_add(T,R);
    }
    while (scanf("%s", R) != EOF) S += R;

    N = SI(S);
    ret = 0;
    FOR(i,0,N) {
        U = T;
        int k = i;
        while (1) {
            U = U->next[S[k]-'A'];
            k--;
            if (!U) break;
            if (U->count && (k < 0 || V[k])) {
                V[i] = 1; ret = i+1;
                break;
            }
            if (k < 0) break;
        }
        if (i-ret > MAXL) break;
    }

    printf("%d\n", ret);

    trie_delete(T);

    return 0;
}
