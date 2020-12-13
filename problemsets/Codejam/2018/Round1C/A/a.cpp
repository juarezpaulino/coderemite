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

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vpii;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool rounded(int A, int N) {
	return (A*1000/N)%10 >= 5;
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	int C[101010], N, L, K;
	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		cout << "Case #" << tt << ": ";
		cin >> N >> L; K = N;
		
		vi R;
		vpii U;
	    for (int i = 1; i <= N; i++) if (rounded(i,N)) R.pb(i);
		for (int i = 0; i < L; i++) cin >> C[i], K -= C[i];
		int m = (sz(R)) ? R[lower_bound(all(R),0)-R.begin()] : 1<<30;
		
		for (int i = 0; i < L; i++)
			if (sz(R) && C[i] <= R.back()) {
				int p = lower_bound(all(R),C[i])-R.begin();
				U.pb(mp(R[p]-C[i],C[i]));
			}
			else U.pb(mp(1<<30,C[i]));
		sort(all(U));
		
		int ret = 0;
		for (int i = 0; i < sz(U); i++) {
			if (U[i].fi <= K && U[i].fi <= m) ret+=(U[i].se+U[i].fi)*100/N+1, K-=U[i].fi;
			else ret+=U[i].se*100/N;
		}
		while (m <= K) ret += m*100/N+1, K-=m;
		ret += K*100/N;
		cout << ret << endl;
	}

    return 0;
}