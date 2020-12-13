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

bool comp(const vi &a, const int &b) { return a[0]<b; }
bool comp2(const int &a, const vi &b) { return a<b[0]; }


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	vvi ret;
	for (int a = 1; 3*a <= 25600; a++)
		for (int b = a; a+2*b <= 25600; b++) {
			int s = a+b, p = a*b;
			if (p <= 10000) continue;
			int c = (s * 10000) / (p - 10000);
			s += c;
			if (s > 25600 || c < b) continue;
			if (s == p*ll(c)/10000) ret.pb({s,a,b,c});
		}
	sort(all(ret));

	int l, l1, r, r1;
	while (scanf("%d.%d %d.%d", &l, &l1, &r, &r1) != EOF) {
		l = l*100 + l1;
		r = r*100 + r1;
		int k1 = lower_bound(all(ret),l,comp)-ret.begin();
		int k2 = upper_bound(all(ret),r,comp2)-ret.begin();
		while (k1 < k2) {
			int s = ret[k1][0], a = ret[k1][1], b = ret[k1][2], c = ret[k1++][3];
			printf("%d.%02d = %d.%02d + %d.%02d + %d.%02d = %d.%02d * %d.%02d * %d.%02d\n",
							s/100, s%100,
							a/100, a%100, b/100, b%100, c/100, c%100,
							a/100, a%100, b/100, b%100, c/100, c%100);
		}
	}
	
	return 0;
}