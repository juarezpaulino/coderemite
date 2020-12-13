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
typedef tuple<string,set<string>,int> tc;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		int N; cin >> N;
		map<int,int> A;
		vector<set<int>> F(N);
		int t = 0;
		for (int i = 0; i < N; i++) {
			int M; cin >> M;
			while (M--) {
				int x; cin >> x;
				if (!F[i].count(x)) A[x]++, F[i].insert(x);
			}
		}
		cout << "Case " << tt << ":";
		for (auto u: A) if (u.se==1) t++;
		for (int i = 0; i < N; i++) {
			int ret = 0;
			for (auto u: F[i]) if (A[u]==1) ret++;
			cout << " " << fixed << setprecision(6) << ret*100./t << "%";
		}
		cout << endl;
	}	

	return 0;
}