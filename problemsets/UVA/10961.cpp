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

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

pii walk(pii a, int vx, int vy, int t) {
	if (vx) vx/=abs(vx);
	if (vy) vy/=abs(vy);
	return mp(a.fi+vy*t,a.se+vx*t);
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);
	int TT;
	cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		pii g, l;
		cin >> g.fi >> g.se >> l.fi >> l.se;
		int N;
		cin >> N;
		vector<pii> L(N);
		for (int i = 0; i < N; i++) cin >> L[i].fi >> L[i].se;
		cin >> N;
		vector<pii> G(N);
		for (int i = 0; i < N; i++) cin >> G[i].fi >> G[i].se;
		bool safe = 1;
		int a = 0, b = 0;
		while (a != sz(G) && b != sz(L)) {
			int dgx = G[a].se-g.se, dlx = L[b].se-l.se,
			    dgy = G[a].fi-g.fi, dly = L[b].fi-l.fi;
			int t = min(	max(abs(dgx), abs(dgy)),
							max(abs(dlx), abs(dly)) 	);
			
			int d = (g.fi==l.fi)?abs(g.se-l.se):(g.se==l.se)?abs(g.fi-l.fi):2*abs(g.fi-l.fi);
			if ((d+1)/2 <= t && walk(g,dgx,dgy,d/2)==walk(l,dlx,dly,(d+1)/2)) {
				l = walk(l,dlx,dly,(d+1)/2);
				safe = 0;
				break;
			}

			g = walk(g,dgx,dgy,t);
			l = walk(l,dlx,dly,t);
			if (g==G[a]) a++;
			if (l==L[b]) b++;
		}
		if (b==sz(L)-1 && l==L.back()) safe = 1;
		if (safe) cout << "Yes" << endl;
		else cout << "No" << endl;
	 	if (tt != TT) cout << endl;
	}

    return 0;
}