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

int V[1000001];

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int N, M, tt = 0;
	while (cin >> N >> M && N+M) {
		bool ok = 1;
		tt++;
		for (int i = 0; i < N; i++) {
			int a, b; cin >> a >> b;
			for (int j = a; ok && j < b; j++) ok &= (V[j]!=tt), V[j] = tt; 
		}
		for (int i = 0; i < M; i++) {
			int a, b, p; cin >> a >> b >> p;
			for (int k = 0; ok && k < 1000000; k+=p)
				for (int j = k+a; ok && j < min(1000000,k+b); j++) ok &= (V[j]!=tt), V[j] = tt; 
		}
		if (ok) cout << "NO CONFLICT" << endl;
		else cout << "CONFLICT" << endl;
	}

	return 0;
}