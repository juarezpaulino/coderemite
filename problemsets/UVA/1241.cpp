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

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int O[2020];
int N, M;

int go(int a, int b) {
	if (a+1 == b) return (O[a]&O[b])?-1:O[a]^O[b];
	int c = go(a, (a+b)/2);
	int d = go((a+b)/2+1, b);
	if (c == -1 && d == -1) return -1;
	if (c == -1) return d+1;
	if (d == -1) return c+1;
	return c+d;
}

int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	int TT; cin >> TT;
	while (TT--) {
		cin >> N >> M;
		fill(O, O+(1<<N), 0);
		for (int i = 0; i < M; i++) { int x; cin >> x; O[x-1] = 1; }
		int ret = max(0, go(0, (1<<N)-1));
		cout << ret << endl;
	}
		        	
	return 0;
}