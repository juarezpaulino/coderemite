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

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int v1, v0;
	while (cin >> v1 >> v0 && v1+v0) {
		double V1 = v1, V0 = v0;
		int D = v1/V0 - EPS;
		int ret = 0; double maxi = 0.;
		for (int i = 1; i <= D; i++) {
			double l = i * 0.3 * sqrt(V1/i - V0);
			int c = cmp(maxi,l);
			if (c==0) { ret = 0; break; }
			else if (c > 0) break;
			maxi = l; ret = i;
		}
		cout << ret << endl;
	}

	return 0;
}