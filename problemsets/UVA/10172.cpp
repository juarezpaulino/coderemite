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
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int TT; cin >> TT;
	while (TT--) {
		int N, S, Q; cin >> N >> S >> Q;
		int ret = 0, T = 0;
		vector<queue<int> > B(N, queue<int>());
		stack<int> C;
		for (int k = 0; k < N; k++) {
			int b; cin >> b; T += b;
			while (b--) { int x; cin >> x; B[k].push(x-1); }
		}
		int p = 0;
		while (T) {
			while (sz(C)) {
				if (C.top() == p) T--, C.pop();
				else if (sz(B[p]) < Q) B[p].push(C.top()), C.pop();
				else break;
				ret++;
			}
			for (int i = sz(C); sz(B[p]) && i < S; i++) C.push(B[p].front()), B[p].pop(), ret++;
			if (T) p = (p+1)%N, ret+=2;
		}
		cout << ret << endl;
	}

	return 0;
}