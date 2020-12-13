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
typedef tuple<int,char,int> tii;
typedef vector<tii> vtii;
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

	int tt = 1;
	int L[20], N;
	char S[101010];
	while (gets(S)) {
		istringstream is(S);
		N = 0;
		priority_queue<tii, vtii, greater<tii>> q;
		while (is >> L[N]) q.push(mt(L[N]-5,1,N)), N++;
		int G = N;
		int ret = 0;
		while (!q.empty()) {
			tii u = q.top(); q.pop();
			int p = get<2>(u);
			char v = get<1>(u);
			ret = get<0>(u);
			
			if (v == 2) G++, q.push(mt(ret+L[p]-5,1,p));
			else if (v == 1) G--, q.push(mt(ret+5,0,p));
			else q.push(mt(ret+L[p],2,p));
			
			if (G == N) break;
		}
		cout << "Set " << tt++ << " ";
		if (G == N && ret <= 3600)
			cout << "synchs again at " << ret/60 << " minute(s) and "\
				 << ret%60 << " second(s) after all turning green." << endl;
		else cout << "is unable to synch after one hour." << endl;
	}

    return 0;
}