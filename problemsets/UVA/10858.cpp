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

vvi RET;
vi ret;
int N;

void go(int k, int l, int m) {
	for (int i = l; i*i <= m; i++) if (m%i==0) { 
		ret[k] = i;
		go(k+1, i, m/i);
	}
	if (m != N) { ret[k] = m; RET.pb(vi(ret.begin(),ret.begin()+k+1)); }
}

void sol() {
	cout << sz(RET) << endl;
	for (int k = 0; k < sz(RET); k++) {
		cout << RET[k][0];
		for (int i = 1; i < sz(RET[k]); i++) cout << " " << RET[k][i];
		cout << endl;
	}
}

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	ret.resize(20);
	while (cin >> N && N) {
		RET.clear();
		go(0,2,N);
		sol();
	}

	return 0;
}