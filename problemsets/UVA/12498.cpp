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
#define clz(x) (__builtin_clz(x))
#define szb(x) (sizeof(int)*8 - clz(x))

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<double> vd;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int eval(int k, int l, int r) { return l==-1?r-k:r==-1?k-l:min(r-k,k-l); }


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	string M[110];
	int L[110][110], R[110][110];
	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		cout << "Case " << tt << ": ";
		int r, c; cin >> r >> c;
		bool ok = 1;
		for (int i = 1; i <= r; i++) {
			cin >> M[i]; M[i] = "x" + M[i];
			L[i][0] = R[i][c+1] = -1;
			for (int j = 1; ok && j <= c; j++) L[i][j]=(M[i][j]=='0')?j:L[i][j-1];
			for (int j = c; ok && j >= 1; j--) R[i][j]=(M[i][j]=='0')?j:R[i][j+1];
			if (R[i][1]==-1) ok = 0;
		}
		if (!ok) { cout << "-1" << endl; continue; }
		int ret = -1;
		for (int j = 1; j <= c; j++) {
			int c = 0;
			for (int i = 1; i <= r; i++) c += eval(j, L[i][j], R[i][j]);
			if (ret == -1 || c < ret) ret = c;
		}
		cout << ret << endl;
	}
	
	return 0;
}