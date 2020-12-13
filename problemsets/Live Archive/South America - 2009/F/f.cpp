/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/***********************************************************************************************************/
/*                                 Declarations, macros, parser functions                                  */
/***********************************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define FOR(i,m,n) for((i)=(m);(i)<(n);(i)++)
#define FORE(i,m,n) for((i)=(m);(i)<=(n);(i)++)
#define ROF(i,m,n) for((i)=(m);(i)>=(n);(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a))
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())


inline string ITOA(int a) {
    char c[500]; sprintf(c, "%d", (a)); return string(c);
}

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PII;
typedef signed long long i64;
typedef unsigned long long u64;

#define EPS 1E-9
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1
#define PI 3.1415926535897932384626433832795

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define ALPH 65
#define MAXSTR 100100
#define MAXLG 25

////////////////////////////////////////////////////////////////////////////////
// Suffix tree linear implementation - Ukkonen.
//
// Alocar a árvore T com 2n+1 elementos. Iniciar todos os 2n+1 nós com
// Node(0,0,0) e então treeExtend em cada posição de caracteres da string S de
// entrada.
//
/*
inline int charInd(char c) {
	if ('a' <= c && c <= 'z') return c-'a';
	if ('A' <= c && c <= 'Z') return 26+c-'A';
	if ('0' <= c && c <= '9') return 52+c-'0';
	if (c == '.') return 62;
	if (c == ',') return 63;
	return 64;
}

struct Node {
	int l, r, parent, link;
	int next[ALPH];
	Node(int l = 0, int r = 0, int parent = 0) : l(l), r(r), parent(parent) {
        int i; link = -1; FOR(i,0,ALPH) next[i] = -1;
	}
};

struct State {
	int v, pos;
	State (int v, int pos) : v(v), pos(pos) {}
};

State ptr(0, 0);
int size = 1;
Node *T;
char S[MAXSTR];
int n;

inline int len(int k) { return T[k].r - T[k].l; }



State go(State st, int l, int r) {
	while (l < r) if (st.pos == len(st.v)) {
		st = State(T[st.v].next[charInd(S[l])], 0);
		if (st.v == -1) return st;
	} else {
		if (S[l] != S[T[st.v].l + st.pos]) return State(-1, -1);
		int d = min(r-l, len(st.v)-st.pos);
		l += d; st.pos += d;
	}
	return st;
}

int split(State st) {
	if (st.pos == len(st.v)) return st.v;
    if (st.pos == 0) return T[st.v].parent;
	int nv = size++;
	T[nv] = Node(T[st.v].l, T[st.v].l + st.pos, T[st.v].parent);
	T[T[st.v].parent].next[charInd(S[T[st.v].l])] = nv;
	T[nv].next[charInd(S[T[st.v].l + st.pos])] = st.v;
	T[st.v].parent = nv;
	T[st.v].l += st.pos;
	return nv;
}

int link(int v) {
	if (T[v].link != -1) return T[v].link;
	if (v == 0) return 0;
	int p = T[v].parent;
	State st = go(State(link(p), len(link(p))), T[v].l + (T[v].parent==0?1:0), T[v].r);
	T[v].link = split(st);
	return T[v].link;
}

void treeExtend(int i) {
	while (1) {
		State nptr = go(ptr, i, i+1);
		if (nptr.v != -1) { ptr = nptr; break; }
		int mid = split(ptr);
		T[size] = Node(i, n, mid);
		T[mid].next[charInd(S[i])] = size++;
		ptr = State(link(mid), len(link(mid)));
		if (mid == 0) break;
	}
}
*/

////////////////////////////////////////////////////////////////////////////////
// Suffix Array - O(nlog^2n) implementation
//
/*
char S[MAXSTR];

struct entry { int nr[2], p; } L[MAXSTR];
int P[MAXLG][MAXSTR], N, stp;

int cmp_entry(struct entry a, struct entry b) {
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) :
                                (a.nr[0] < b.nr[0] ? 1 : 0);
}

void build_suffix() {
    int i, cnt;
    N = strlen(S);
    FOR(i,0,N) P[0][i] = S[i]-'a';
    for (stp = cnt = 1; (cnt>>1) < N; stp++, cnt<<=1) {
        FOR(i,0,N) {
            L[i].nr[0] = P[stp-1][i];
            L[i].nr[1] = (i + cnt < N) ? P[stp-1][i+cnt] : -1;
            L[i].p = i;
        }
        sort(L, L + N, cmp_entry);
        FOR(i,0,N)
            P[stp][L[i].p] = (i>0 && L[i].nr[0]==L[i-1].nr[0] &&
                             L[i].nr[1]==L[i-1].nr[1]) ? P[stp][L[i-1].p] : i;
    }
    stp--;
}
*/

// Input: text, N
// Output: sa[] is a sorted list of offsets to all non-empty suffixes,
// lcp[i] = length of longest common prefix of text+sa[i] and text+sa[i+1]
char text[MAXSTR];
i64 key[MAXSTR];
int N, sa[MAXSTR], rank[MAXSTR], *lcp=(int*)key;

int cmp_suffix(int i, int j) { return key[i]<key[j]; };

void build() {
    for (int i = 0; i < N; i++) { sa[i] = i; key[i] = text[i]; }
    sort(sa, sa+N, cmp_suffix);
    for (int K = 1; ; K *= 2) {
        for (int i = 0; i < N; i++)
            rank[sa[i]] = i>0 && key[sa[i-1]]==key[sa[i]] ? rank[sa[i-1]] : i;
        if (K >= N) break;
        for (int i = 0; i < N; i++)
            key[i] = rank[i] * (N+1LL) + (i+K < N ? rank[i+K]+1 : 0);
        sort(sa, sa+N, cmp_suffix);
    }
    for (int i = 0, k = 0; i < N; i++) {
        if (k > 0) k--;
        if (rank[i] == N-1) { lcp[N-1] = -1; k = 0; continue; }
        int j = sa[rank[i]+1];
        while (text[i+k] == text[j+k]) k++;
        lcp[rank[i]] = k;
    }
}

int main() {
    int tot, i, r;
    for(; gets(text), strcmp(text,"*"); ) {
        N = strlen(text); build(); r = tot = lcp[N-1] = 0;
        FOR(i,0,N) {
            if (lcp[i]<r) tot+=r-lcp[i];
            r = lcp[i];
        }
        printf("%d\n", tot);
    }
    return 0;
}
