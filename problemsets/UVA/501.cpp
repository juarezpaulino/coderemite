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

char filter(char c) {
	return (c>='a'&&c<='z') || (c>='0'&&c<='9')? c : ' ';
}

map<string,string> read() {
	map<string, string> ret;
	string s;
	getline(cin,s);
	transform(all(s), s.begin(), filter);
	istringstream is(s);
	string a, v;
	while (is >> a >> v) ret[a] = v;
	return ret;
}


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int TT; cin >> TT;
	while (TT--) {
		int M, N; cin >> M >> N;
		vi A(M), U(N);
		for (int i = 0; i < M; i++) cin >> A[i];
		for (int i = 0; i < N; i++) cin >> U[i];
		int u = 0, s = 1;
		multiset<int> S;
		S.insert(A[0]);
		auto it = S.begin();
		for (int i = 0; i < N; i++) {
			while (s < U[i]) {
				S.insert(A[s++]);
				if (*it > A[s-1]) it--;
            }
            if (i) it++;
            cout << *it << endl;
		}
		if (TT) cout << endl;
	}

	return 0;
}