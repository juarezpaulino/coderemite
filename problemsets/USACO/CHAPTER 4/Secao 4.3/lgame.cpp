/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: lgame
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
const double EPS = 1E-10;
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
    template<> struct hash<VI> {
		size_t operator()(const VI& S) const {
            size_t p = 0;
            FOR(i,0,SI(S)) p = (p*10) + S[i];
            return p;
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

string IN;

string WORD[40000]; int nword;
hash_set<string> HASH;
vector<pair<string, string> > RET; int B = 0;

int VAL[] = { 2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7 };

inline int score(string S) {
    int ret = 0;
    for (int i = 0; i < SI(S); i++) ret += VAL[S[i]-'a'];
    return ret;
}

bool fit(string S, string T, string &R) {
    int k = 0;
    SORT(S); SORT(T); R = "";
    for (int i = 0; i < SI(S); i++) {
        while (k < SI(T) && S[i] != T[k]) R += T[k++];
        if (k >= SI(T)) return false;
        k++;
    }
    while (k < SI(T)) R += T[k++];
    return true;
}

void insert(pair<string, string> V) {
    FOR(i,0,SI(RET)) {
        if (RET[i] == V)
            return;
    }
    RET.PB(V);
}

void insert(int s, string S1, string S2) {
    if (s > B) RET.clear();
    if (s > B || s==B) {
        B = s;
        if (S2 == "" || S1 < S2)
            insert(MP(S1, S2));
        else insert(MP(S2, S1));
    }
}


int main() {

    char str[10];

    // Read dictionary.
    freopen("lgame.dict","r",stdin);
    while (1) {
        scanf("%s", str);
        if (str[0]=='.') break;
        WORD[nword] = str;
        HASH.insert(WORD[nword]);
        nword++;
    }

    freopen("lgame.in","r",stdin);freopen("lgame.out","w",stdout);

    // Read input letters.
    scanf("%s", str); IN = str;

    // Fixes first word and check permutation on remaining letters.
    for (int i = 0; i < nword; i++) {
        string R, R2;
        if (fit(WORD[i], IN, R)) {
            insert(score(WORD[i]), WORD[i], "");
            if (SI(R) < 3 || SI(R) > 4) continue;
            do {
                if (HASH.count(R)) insert(score(WORD[i]) + score(R), WORD[i], R);
                else if (SI(R) == 4) {
                    R2 = R[0]; R2 += R[1]; R2 += R[2];
                    if (HASH.count(R2)) insert(score(WORD[i]) + score(R2), WORD[i], R2);
                    R2 = R[0]; R2 += R[1]; R2 += R[3];
                    if (HASH.count(R2)) insert(score(WORD[i]) + score(R2), WORD[i], R2);
                    R2 = R[0]; R2 += R[2]; R2 += R[3];
                    if (HASH.count(R2)) insert(score(WORD[i]) + score(R2), WORD[i], R2);
                    R2 = R[1]; R2 += R[2]; R2 += R[3];
                    if (HASH.count(R2)) insert(score(WORD[i]) + score(R2), WORD[i], R2);
                }
            } while (next_permutation(ALL(R)));
        }
    }

    SORT(RET);

    printf("%d\n", B);
    FOR(i,0,SI(RET)) {
        printf("%s", RET[i].first.c_str());
        if (RET[i].second != "") printf(" %s", RET[i].second.c_str());
        putchar('\n');
    }

    return 0;
}
