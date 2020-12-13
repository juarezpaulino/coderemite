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


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	int R[1010];
	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		cout << "Case " << tt << ": ";
		int N, I, K;
		cin >> N >> I >> K;
		for (int i = 0; i < N; i++) cin >> R[i];
		int ret1 = 0, ret2 = 0;
		int t = I;
		for (int i = 0; i < N; i++) {
			if (R[i] < t) { t = R[i]+I; continue; }
			ret1++;
			t = R[i]+K;
			while (i+1 < N && R[i+1] < t) ret2++, i++;
			t += I;
		}
		cout << ret1 << " " << ret2 << endl;
	}

    return 0;
}