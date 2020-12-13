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

#define C(r,c,q) (M.count(A[r][c]) && M[A[r][c]] < q)


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int V[4], A[5][5];
	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		int N, L; cin >> N >> L;
		map<int,int> M;
		int x;
		for (int i = 0; i < N; i++) cin >> x, M[x] = i;
		for (int i = 0; i < 4; i++) cin >> V[i];
		if (tt > 1) cout << endl;
		cout << "Case " << tt << ":" << endl;
		for (int l = 0; l < L; l++) {
			for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) 
				cin >> A[i][j];
			int ret = 0, i, j, ok;
			if (C(0,0,35) && C(0,4,35) && C(4,0,35) && C(4,4,35))
				ret+=V[0];
			for (ok = 1, j = 0; ok && j < 5; j++) ok &= C(2,j,40);
			if (ok) ret += V[1];
			for (ok = 1, i = 0; ok && i < 5; i++) ok &= C(i,i,45) & C(i,4-i,45);
			if (ok) ret += V[2];
			for (ok = 1, i = 0; ok && i < 5; i++) for (j = 0; ok && j < 5; j++) ok &= C(i,j,100);
			if (ok) ret += V[3];
			cout << ret << endl;
		}
	}
	
	return 0;
}