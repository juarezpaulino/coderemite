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

	int TT; cin >> TT;
	while (TT--) {
		int I, D, K; cin >> I;
		vi C(I+1);
		for (int i = 0; i <= I; i++) cin >> C[i];
		cin >> D >> K;
		int n = (sqrt(1+8*K/D) - 1) / 2. - EPS; n++;
		ll ret = C[I];
		for (int i = I-1; i >= 0; i--) ret = ret*n + C[i];
		cout << ret << endl;
	}

	return 0;
}