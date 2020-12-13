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
typedef pair<string,string> pss;
typedef vector<pss> vss;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	vss L;
	char S[101010];
	char t[1010], a[1010];
	while (gets(S)) {
		if (string(S)=="END") break;
		sscanf(S, "\"%[^\"]\" by %[^\r\n]", t, a);
		L.pb(mp(a,t));
	}
	sort(all(L));
	vss B, R;
	while (gets(S)) {
		if (string(S)=="END") break;
		if (string(S)=="SHELVE") {
			sort(all(R));
			for (auto r: R) {
				auto it = L.begin();
				while (it != L.end() && r > *it) it++;
				if (it == L.begin()) cout << "Put \"" << r.se << "\" first" << endl;
				else cout << "Put \"" << r.se << "\" after \"" << (it-1)->se << "\"" << endl;
				L.insert(it,r);
			}
			R.clear();
			cout << "END" << endl;
			continue;
		}
		sscanf(S, "%*s \"%[^\"]\"", t);
		if (*S=='B') {
			for (auto it = L.begin(); it != L.end(); it++)
				if (it->se == t) { B.pb(*it); L.erase(it); break; }
			continue;
		}
		else if (*S=='R') {
			for (auto it = B.begin(); it != B.end(); it++)
				if (it->se == t) { R.pb(*it); B.erase(it); break; }			
		}
	}

    return 0;
}