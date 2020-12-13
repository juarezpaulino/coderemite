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
	while (TT--) {
		int F, SG, SB; cin >> F >> SG >> SB;
		priority_queue<int> G, B;
		int x;
		for (int i = 0; i < SG; i++) cin >> x, G.push(x);
		for (int i = 0; i < SB; i++) cin >> x, B.push(x);
		while (!G.empty() && !B.empty()) {
			vi rG, rB;
			for (int i = 0; !G.empty() && !B.empty() && i < F; i++) {
				int g = G.top(), b = B.top();
				G.pop(); B.pop();
				if (g > b) rG.pb(g-b);
				else if (b > g) rB.pb(b-g);
			}
			for (auto u: rG) G.push(u);
			for (auto u: rB) B.push(u);
		}
		if (G.empty() && B.empty()) cout << "green and blue died" << endl;
		else if (!G.empty()) {
			cout << "green wins" << endl;
			while (!G.empty()) {
				cout << G.top() << endl;
				G.pop();
			}
		}
		else {
			cout << "blue wins" << endl;
			while (!B.empty()) {
				cout << B.top() << endl;
				B.pop();
			}
		}
		if (TT) cout << endl;
	}

	return 0;
}