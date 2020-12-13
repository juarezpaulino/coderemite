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
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef pair<int, int> pii;
typedef long long ll;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

	int TT;
	cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		bool ok = 1;
		int h1, m1, h2, m2, t[4];
		scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2); t[0] = h1*60+m1, t[1] = h2*60+m2;
		scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2); t[2] = h1*60+m1, t[3] = h2*60+m2;
		if (t[0] <= t[2] && t[2] <= t[1]) ok = 0;
		if (t[0] <= t[3] && t[3] <= t[1]) ok = 0;
		if (t[2] <= t[0] && t[0] <= t[3]) ok = 0;
		if (t[2] <= t[1] && t[1] <= t[3]) ok = 0;
		if (ok) printf("Case %d: Hits Meeting\n", tt);
		else printf("Case %d: Mrs Meeting\n", tt);
	}

	return 0;
}