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
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int N, n;
#define mirror(i) (n-i-1)
#define I mirror(i)
vs cw_rotate(const vs &A) {
	vs ret(n,string(n,0));
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		ret[j][i]=A[I][j];
	return ret;
}

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N >> n && N+n) {
		vs A(N), B(n);
		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 0; i < n; i++) cin >> B[i];
		for (int k = 0; k < 4; k++, cout << ((k<4)?" ":"")) {
			int ret = 0;
			for (int i = 0; i <= N-n; i++) for (int j = 0; j <= N-n; j++) {
				int ok = 1;
				for (int l = 0; l < n && ok; l++)
					ok &= (A[i+l].substr(j,n) == B[l]);
				ret += ok;
			}
			cout << ret;
			B = cw_rotate(B);
		}
		cout << endl;
	} 

    return 0;
}