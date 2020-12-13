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
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef vector<string> vs;
typedef vector<pis> vpis;
typedef map<string, bool> msb;
typedef map<string, vpis> msvs;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

vs wmx;
msvs lmx;
msb up;

void add_mx(string a, vpis aux) {
    up[a] = 1;
	if (a[0]=='*') a = a.substr(1), wmx.pb(a);
	if (lmx.count(a)) lmx[a].insert(lmx[a].end(), all(aux));
	else lmx[a] = aux;
}

int main() {

	string a = "", b;
	int p;
	vpis aux;

	int N; cin >> N;
	while (N--) {
		cin >> b;
		if (isdigit(b[0])) { p = stoi(b); cin >> b; up[b] = 1; aux.pb(mp(p,b)); }
		else {
			add_mx(a, aux);
			a = b; cin >> p >> b; up[b] = 1;
			aux.clear(); aux.pb(mp(p,b));
		}
	}
	add_mx(a, aux);

	char op;
	while ((cin >> op) && op != 'X') {
		cin >> a;
		if (op=='A') {
            int m = 1<<30;
			string ret = " => ";
			if (lmx.count(a)) { for (auto s: lmx[a]) if (up[s.se] && s.fi < m) { m = s.fi, ret = " => " + s.se; } }
			for (auto s: wmx)
				if (sz(a) >= sz(s) && a.substr(sz(a)-sz(s))==s)
					for (auto s2: lmx[s])
                        if (up[s2.se] && s2.fi < m) { m = s2.fi, ret = " => " + s2.se; }
			cout << a << ret << endl;
		}
		else if (op == 'D') up[a] = 0;
		else if (op == 'U') up[a] = 1;
	}

	return 0;
}
