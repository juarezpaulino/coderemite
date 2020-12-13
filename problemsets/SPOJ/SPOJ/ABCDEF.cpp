/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

#define IT(V) (__typeof(V.begin()))
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(M) (M).begin(), (M).end()

///////////////////////////////////////////////////////////////////////////////
// - EXTENSION GCC LIB HASH
//
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

struct Hash {
    int v;
    int c1, c2;
    int next;
};

const int MAXH = 2341571;

int first[MAXH];
int nHASH;
Hash HASH[MAXH];

int find_hash(int v) {
    int h = abs(1357908642+v) % MAXH, p;
    for (p = first[h]; p; p = HASH[p].next) if (HASH[p].v==v) return p;
    HASH[++nHASH] = (Hash){v,0,0,first[h]};
    return first[h] = nHASH;
}

int N;
int S[110];

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}

int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", S+i);

    nHASH = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) {
        int v1 = S[i]*S[j] + S[k];
        HASH[find_hash(v1)].c1++;
        if (!S[i]) continue;
        int v2 = S[i] * (S[j] + S[k]);
        HASH[find_hash(v2)].c2++;
    }
    long long ret = 0;
    for (int i = 1; i <= nHASH; i++) ret += HASH[i].c1 * HASH[i].c2;
    printf("%lld\n", ret);

    return 0;
}
