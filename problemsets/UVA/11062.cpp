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
	c = tolower(c);
	return (c>='a'&&c<='z') || c=='-' ? c : ' ';
}

vs tokenize(string s, string ch) {
    vs ret;
    for(int p = 0, p2; p < sz(s); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.pb(s.substr(p, p2-p));
    }
    return ret;
}


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	set<string> S;
	string s, w, l = "";
	bool h = 0;
	while (getline(cin,s)) {
		h = s.back()=='-'?1:0;
		transform(all(s), s.begin(), filter);
		vs tok = tokenize(s, " ");
		for (int i = 0; i < sz(tok); i++) {
			w = tok[i];
			if (l != "" && !i) w = l + w, l = "";
			
			if (i==sz(tok)-1 && h) l = w.substr(0,sz(w)-1);
			else S.insert(w);
		}
	}
	for (auto u: S) cout << u << endl;

	return 0;
}