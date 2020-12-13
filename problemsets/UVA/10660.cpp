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

#define FOR(i,n,N) for (i = n; i < N; i++)

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int V[25][3], A[5], B[5];
	int TT; cin >> TT;
	while (TT--) {
		int N, i, k; cin >> N;
		FOR(i,0,N) cin >> V[i][0] >> V[i][1] >> V[i][2];
		int ret = 1<<30;
		FOR(A[0],0,21) FOR(A[1],A[0]+1,22) FOR(A[2],A[1]+1,23) FOR(A[3],A[2]+1,24) FOR(A[4],A[3]+1,25) {
			int t = 0;
			FOR(k,0,N) {
				int c = 1<<30;
				FOR(i,0,5) c = min(c,abs(A[i]/5-V[k][0])+abs(A[i]%5-V[k][1]));
				t += c*V[k][2];
			}
			if (t < ret) ret = t, copy(A, A+5, B);
		}
		for (int i = 0; i < 5; i++) cout << B[i] << (i==4?"\n":" ");
	}	
	
	return 0;
}