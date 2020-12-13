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
typedef vector<vi> vvi;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);

	int TT; cin >> TT;
	while (TT--) {
		int K; cin >> K;
		vi F(K), R(K);
		vi vF(K), vR(K);
		for (int i = 0; i < K; i++) cin >> F[i];
		for (int i = 0; i < K; i++) cin >> R[i];
		int N = 0, M = 0;                                  
		for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) {
			if (F[i]==R[j] && !vF[i] && !vR[j])
				N += F[i], vF[i] = 1, vR[j] = 1;
			M += min(F[i],R[j]);
		}
		for (int i = 0; i < K; i++) if (!vF[i]) N += F[i];
		for (int i = 0; i < K; i++) if (!vR[i]) N += R[i];
		cout << "Matty needs at least " << N << " blocks, and can add at most " << M-N << " extra blocks." << endl;
	}

    return 0;
}