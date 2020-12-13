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

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		cout << "Case #" << tt << ":" << endl;
		vvi U(3,vi());
		for (int k = 0; k < 3; k++) {
			int N;
			cin >> N;
			U[k].resize(N);
			for (int i = 0; i < N; i++) cin >> U[k][i];
			sort(all(U[k]));
		}
		vvi rU(3,vi());
		int ret = 0;
		for (int k = 0; k < 3; k++) {
			rU[k] = vi(U[k]);
			rU[k].resize(set_difference(all(rU[k]),all(U[(k+1)%3]),rU[k].begin()) - rU[k].begin());
			rU[k].resize(set_difference(all(rU[k]),all(U[(k+2)%3]),rU[k].begin()) - rU[k].begin());
			ret = max(ret,sz(rU[k]));
		}
		for (int k = 0; k < 3; k++) if (sz(rU[k])==ret) {
			cout << k+1 << " " << ret;
			for (int i = 0; i < ret; i++) cout << " " << rU[k][i];
			cout << endl;
		}
	}

    return 0;
}