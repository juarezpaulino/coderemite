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

#define M 2000

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	for (int a = 1; 4*a <= M; a++) for (int b = a; a+3*b <= M; b++) for (int c = b; a+b+2*c <= M; c++) {
		int s = a+b+c;
		if (s > M) break;
		ll p = a*b*c;
		if (p <= 1000000) continue;
		int d = (ll)1000000 * s / (p-1000000);
		s += d;
		if (s > M || d < c) continue;
		if (s == d*p/1000000)
			printf("%d.%02d %d.%02d %d.%02d %d.%02d\n",
							a/100, a%100,
							b/100, b%100,
							c/100, c%100,
							d/100, d%100);
	}
	
	return 0;
}