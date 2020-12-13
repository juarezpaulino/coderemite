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

set<int> RET;
int x[7];

bool check(int k) {
	int m = 0;
	for (int i=x[0]%k, u=0; m < k && !(u&(1<<i)); i=(i+x[i])%k, m++)
		u |= 1<<i;
	return m==k;
}

void go(int k, int u, int y) {
	for (int i = 0; i < 10; i++) if (!(u&(1<<i))) {
		int z = (y<<3) + (y<<1) + i;
		x[k] = i;
		if (check(k+1)) RET.insert(z);
		if (k < 7) go(k+1, u|(1<<i), z);
	}
}


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	go(0,0,0);

	int n, tt = 1;
	while (cin >> n && n != 0)
		cout << "Case " << tt++ << ": " << *lower_bound(all(RET), n) << endl;

	return 0;
}