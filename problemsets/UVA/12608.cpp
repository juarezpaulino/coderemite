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

	int w[1010], x[1010];
	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		int W, N;
		cin >> W >> N;
		for (int i = 0; i < N; i++) cin >> x[i] >> w[i];
		int ret = 0;
		for (int i = 0; i < N; i++) {
			int a = 0;
			while (i < N && a + w[i] < W) a += w[i++];
			ret += (i < N) ? (x[i]<<1) : (x[i-1]<<1);
			if (i < N && a+w[i] > W) i--;
		}
		cout << ret << endl;
	}

    return 0;
}