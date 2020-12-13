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

#define mirr(i) (N-i-1)
#define R mirr(L)
#define I mirr(i)

int N;

void go(vvi &A, int x, int L) {
	if (x == 1) {
		for (int i = L; i <= R; i++) swap(A[L][i], A[R][i]);
		for (int i = L+1; i < I; i++)
			swap(A[i][L], A[I][L]),
			swap(A[i][R], A[I][R]);
	}
	else if (x == 2) {
		for (int i = L; i <= R; i++) swap(A[i][L], A[i][R]);
		for (int i = L+1; i < I; i++)
			swap(A[L][i], A[L][I]),
			swap(A[R][i], A[R][I]);
	}
	else if (x == 3) {
		for (int i = L+1; i <= R; i++) swap(A[i][L],A[L][i]);
		for (int i = L+1; i < R; i++) swap(A[R][i],A[i][R]);
	}
	else if (x == 4) {
		for (int i = L+1; i <= R; i++) swap(A[L][I],A[i][R]);
		for (int i = L+1; i < R; i++) swap(A[i][L],A[R][I]);
	}
}


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int TT; cin >> TT;
	while (TT--) {
		cin >> N;
		vvi A(N,vi(N));
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];
		for (int k = 0; k < (N+1)/2; k++) {
			int T; cin >> T;
			while (T--) { int x; cin >> x; go(A,x,k); }
		}
		for (int i = 0; i < N; i++, cout << endl) for (int j = 0; j < N; j++, cout << (j&&j<N?" ":""))
			cout << A[i][j];
	}

    return 0;
}