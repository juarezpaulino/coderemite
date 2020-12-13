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


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	string A[1010];
	int M, Q;
	while (cin >> M >> Q) {
		for (int i = 0; i < M; i++) cin >> A[i];
		while (Q--) {
			int ret = -1, c = 0, c2;
			string a; cin >> a; int na = sz(a);
			for (int i = 0; i < M; i++) {
				int m = sz(A[i]);
				for (int j = 0; j <= m-na; j++) {
					c2 = 0;
					for (int k = 0; k < na; k++) c2 += A[i][j+k]!=a[k];
					if (ret == -1 || c2 < c) ret = i+1, c = c2;
				}
			}
			cout << ret << endl;
		}
	}
	
	return 0;
}