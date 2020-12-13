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


int read(vi &A, int &N) {
	int ret = 0;
	int n = N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		if (s == string(N,'.')) continue;
		int a = 0;
		for (int j = 0; j < sz(s); j++) a = (a<<1)+(s[j]=='*');
		n = min(n, ctz(a));
		ret += on(a);
		A.pb(a);
	}
	for (int i = 0; i < sz(A); i++) A[i] >>= n;
	N = sz(A);
	return ret;
}

bool remove(vi &B, vi &A) {
	for (int j = 0; j <= szb(A[0])-szb(B[0]); j++) {
		bool ok = 1;
		for (int i = 0; ok && i < sz(B); i++) if (((A[i]>>j)&B[i]) != B[i]) ok = 0;
		if (ok) {
			for (int i = 0; ok && i < sz(B); i++) A[i]^=(B[i]<<j);
			return true;
		}
	}
	return false;
}

bool find(vi &B, vi &A) {
	for (int i = 0; i <= sz(A)-sz(B); i++) for (int j = 0; j <= szb(A[i])-szb(B[0]); j++) {
		bool ok = 1;
		for (int l = 0; ok && l < sz(B); l++) if (((A[i+l]>>j)&B[l]) != B[l]) ok = 0;
		if (ok) return true;
	}
	return false;
}

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, TT = 1;
	while (cin >> N >> M && N+M) {
		vi A, B;
		int onA = read(A, N);
		int onB = read(B, M);
		if (onA != onB*2 || M > N) { cout << "0" << endl; continue; }
		for (int i = 0; i < M; i++) if (A[i] < B[i]) { cout << "0" << endl; goto END; }
		if (!remove(B, A)) { cout << "0" << endl; continue; }
		cout << (find(B, A)?"1":"0") << endl;
END:
		TT++;
	}

    return 0;
}