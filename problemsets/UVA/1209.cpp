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

int min_distance(string a) {
	if (sz(a)==1) return 0;
	int ret = 1<<30;
	for (int i = 1; i < sz(a); i++) ret = min(ret, abs(a[i]-a[i-1]));
	return ret;
}

int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	string a;
	while (cin >> a) {
		string ret = a;
		int m = min_distance(a);
		string b = a;
		for (int i = 0; i < 10; i++) {
			prev_permutation(all(b));
			next_permutation(all(a));
			int u = min_distance(b),
				v = min_distance(a);
			if (v > m || (v == m && a < ret)) { m = v; ret = a; }
			if (u > m || (u == m && b < ret)) { m = u; ret = b; }
		}
		cout << ret << m << endl;
	}
		        	
	return 0;
}