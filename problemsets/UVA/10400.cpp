/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cstring>

using namespace std;

int N, V[151], T, t;
string sol;
int VIS[2031][151];

inline void bitset(int v, int k) { VIS[v/32][k] |= (1<<(v%32)); }
inline int bitget(int v, int k) { return VIS[v/32][k] & (1<<(v%32)); }

bool go(int u, int k, string ret) {
    char S[10];
    bitset(u+32000, k);
    if (k == N) {
        if (u == t) { sprintf(S, "=%d", t); sol = ret+S; return 1; }
        else return 0;
    }
    int v;
    v = u+V[k]; if (v >= -32000 && v <= 32000 && !bitget(v+32000,k+1)) {
        sprintf(S, "+%d", V[k]);
        bool ok = go(v, k+1, ret+S);
        if (ok) return 1;
    }
    v = u-V[k]; if (v >= -32000 && v <= 32000 && !bitget(v+32000,k+1)) {
        sprintf(S, "-%d", V[k]);
        bool ok = go(v, k+1, ret+S);
        if (ok) return 1;
    }
    v = u*V[k]; if (v >= -32000 && v <= 32000 && !bitget(v+32000,k+1)) {
        sprintf(S, "*%d", V[k]);
        bool ok = go(v, k+1, ret+S);
        if (ok) return 1;
    }
    if (V[k] != 0 && u%V[k]==0) {
        v = u/V[k]; if (v >= -32000 && v <= 32000 && !bitget(v+32000,k+1)) {
            sprintf(S, "/%d", V[k]);
            bool ok = go(v, k+1, ret+S);
            if (ok) return 1;
        }
    }
    return 0;
}

int main() {

    scanf("%d", &T); T++;
    while (--T >= 1) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        scanf("%d", &t);
        char S[10]; sprintf(S, "%d", V[0]);
        memset(VIS,0,sizeof(VIS));
        if (!go(V[0], 1, S)) puts("NO EXPRESSION");
        else puts(sol.c_str());
    }

    return 0;
}
