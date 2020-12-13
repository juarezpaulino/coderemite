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
	string s; getline(cin, s);
	while (TT--) {
		map<string,string> A = read(), B = read();
		bool ok = 0, change = 0;
		for (auto u: B) if (!A.count(u.fi)) {
			cout << (ok?",":"+") << u.fi;
			change = ok = 1;
		}
		if (ok) cout << endl; ok = 0;
		for (auto u: A) if (!B.count(u.fi)) {
			cout << (ok?",":"-") << u.fi;
			change = ok = 1;
		}
		if (ok) cout << endl; ok = 0;
		for (auto u: B) if (A.count(u.fi) && A[u.fi] != u.se) {
			cout << (ok?",":"*") << u.fi;
			change = ok = 1;
		}
		if (ok) cout << endl; ok = 0;
		if (!change) cout << "No changes" << endl;
		cout << endl;
	}

	return 0;
}