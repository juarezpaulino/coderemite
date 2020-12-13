/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
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

#define ALPH 65
#define MAXN 100100

////////////////////////////////////////////////////////////////////////////////
// Suffix tree linear implementation - Ukkonen.
//
// Just read string on "s" and call build_tree. Reminds to check if '$' do not
// appear anywhere else on the string.
//

inline int charInd(char c) {
	if ('a' <= c && c <= 'z') return c-'a';
	if ('A' <= c && c <= 'Z') return 26+c-'A';
	if ('0' <= c && c <= '9') return 52+c-'0';
	if (c == '.') return 62;
	if (c == ',') return 63;
	return 64;
}

char s[MAXN];
int n;

struct node {
	int l, r, par, link;
	int next[ALPH];
	node (int l=0, int r=0, int par=-1)
		: l(l), r(r), par(par), link(-1) { for (int i = 0; i < ALPH; i++) next[i] = -1; }
	int len()  {  return r - l;  }
	int &get (char c) {
	    return next[charInd(c)];
	}
};

node t[MAXN*2 + 1];
int sz;

struct state {
	int v, pos;
	state (int v = 0, int pos = 0) : v(v), pos(pos)  {}
};

state ptr;

state go (state st, int l, int r) {
	while (l < r)
		if (st.pos == t[st.v].len()) {
			st = state (t[st.v].get( s[l] ), 0);
			if (st.v == -1)  return st;
		}
		else {
			if (s[ t[st.v].l + st.pos ] != s[l])
				return state (-1, -1);
			if (r-l < t[st.v].len() - st.pos)
				return state (st.v, st.pos + r-l);
			l += t[st.v].len() - st.pos;
			st.pos = t[st.v].len();
		}
	return st;
}

int split (state st) {
	if (st.pos == t[st.v].len()) return st.v;
	if (st.pos == 0) return t[st.v].par;
	node v = t[st.v];
	int id = sz++;
	t[id] = node (v.l, v.l+st.pos, v.par);
	t[v.par].get( s[v.l] ) = id;
	t[id].get( s[v.l+st.pos] ) = st.v;
	t[st.v].par = id;
	t[st.v].l += st.pos;
	return id;
}

int get_link (int v) {
	if (t[v].link != -1)  return t[v].link;
	if (t[v].par == -1)  return 0;
	int to = get_link (t[v].par);
	return t[v].link = split (go (state(to,t[to].len()), t[v].l + (t[v].par==0), t[v].r));
}

void tree_extend (int pos) {
	while (1) {
		state nptr = go (ptr, pos, pos+1);
		if (nptr.v != -1) { ptr = nptr; return; }

		int mid = split (ptr);
		int leaf = sz++;
		t[leaf] = node (pos, n, mid);
		t[mid].get( s[pos] ) = leaf;

		ptr.v = get_link (mid);
		ptr.pos = t[ptr.v].len();
		if (!mid)  break;
	}
}

void build_tree() {
    n = strlen(s);
    s[n++] = '$';
	sz = 1;
    ptr = state(0,0);
    for (int i = 0; i < 2*n+1; i++) t[i] = node();
	for (int i=0; i<n; ++i)
		tree_extend (i);
}

void print_tree() {
    for (int i = 0; i < sz; i++) printf("%d %d %d %d\n", t[i].l, t[i].r, t[i].par, t[i].link);
}


int main() {
    for(; gets(s), strcmp(s,"*"); ) {
        build_tree();
        int ret = 0;
        for (int i = 0; i < sz; i++) if (t[i].r != n) ret += t[i].len();
        printf("%d\n", ret);
    }
    return 0;
}

