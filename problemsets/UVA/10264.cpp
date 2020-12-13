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


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	int N;
	int V[1<<16], P[1<<16];
	while (cin >> N) {
		for (int i = 0; i < (1<<N); i++) cin >> V[i], P[i] = 0;
		for (int i = 0; i < (1<<N); i++) for (int j = 0; j < N; j++) P[i^(1<<j)] += V[i];
		int ret = -1;
		for (int i = 0; i < (1<<N); i++) for (int j = 0; j < N; j++) ret = max(ret, P[i]+P[i^(1<<j)]);
		cout << ret << endl;
	}

	return 0;
}