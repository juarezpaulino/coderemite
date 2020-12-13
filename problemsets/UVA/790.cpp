/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))
#define on(x) (__builtin_popcount(x))
#define ctz(x) (__builtin_ctz(x))

inline int szb(int a) { int ret = 1; while(a>>=1) ret++; return ret; }

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
typedef pair<int, string> pis;
typedef vector<pis> vpis;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define on(x) (__builtin_popcount(x))

bool comp(const ti &A, const ti &B) {
	if (get<0>(A) != get<0>(B)) return get<0>(A) > get<0>(B);
	if (get<1>(A) != get<1>(B)) return get<1>(A) < get<1>(B);
	return get<2>(A) < get<2>(B);
}

bool comp2(const ti &A, const ti &B) {
	if (get<0>(A) != get<0>(B)) return get<0>(A) > get<0>(B);
	return get<1>(A) < get<1>(B);
}

int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	char S[1010];
	int TT; cin >> TT;
	gets(S);
	gets(S);
	while (TT--) {
		vpis I;
		while (gets(S) && *S) {
			int h, m;
			sscanf(S, "%*d %*c %d:%d %*c", &h, &m);
			I.pb(mp(h*60+m, S));
		}
		sort(all(I));

		cout << "RANK TEAM PRO/SOLVED TIME" << endl;
		int e, h, m, L = 0;
		char p, s;
		int P[100] = {0},
			T[100][30] = {0};
		for (int i = 0; i < sz(I); i++) {
			sscanf(I[i].se.c_str(), "%d %c %d:%d %c", &e, &p, &h, &m, &s);
			L = max(L, e);
			if (P[e]&(1<<(p-'A'))) continue;
			if (s == 'N') { T[e][p-'A'] += 20; continue; }
			P[e] |= (1<<(p-'A'));
			T[e][p-'A'] += h*60+m;
		}
		vti ret;
		for (int i = 1; i <= L; i++) {
			for (int j = 0; j < 30; j++) if ((P[i]&(1<<j)) == 0) T[i][j] = 0;
			ret.pb(mt(on(P[i]),accumulate(&T[i][0], &T[i+1][0], 0), i));
		}
		sort(all(ret), comp);
		int r = 1;
		for (int i = 0; i < sz(ret); i++) {
			if (i && comp2(ret[i-1], ret[i])) r = i+1;
			printf("%4d %4d", r, get<2>(ret[i]));
			if (get<0>(ret[i])) printf(" %4d       %4d\n", get<0>(ret[i]), get<1>(ret[i]));
			else putchar('\n');
		}
		if (TT) cout << endl;
	}
		        	
	return 0;
}