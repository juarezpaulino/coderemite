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

int go(string a, string b) {
	int ret = 0;
	int m = min(sz(a),sz(b));
	for (int i = 0; i < m; i++) ret += a[i]==b[i];
	return ret;
}

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int TT; cin >> TT;
	while (TT--) {
		int n; cin >> n;
		vs A(n);
		for (int i = 0; i < n; i++) cin >> A[i];
		int ret = 0;
		for (auto a = A.begin(); a != A.end(); a++) for (auto b = a+1; b != A.end(); b++) {
			int k = sz(*b), m = sz(*a);
			for (int j = 0; j < m; j++) ret = max(ret, go(a->substr(j),*b));
			for (int j = 0; j < k; j++) ret = max(ret, go(*a,b->substr(j)));
		}
		cout << ret << endl;
	}

	
	return 0;
}