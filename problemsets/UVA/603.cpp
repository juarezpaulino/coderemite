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


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);
	
	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		if (tt != 1) puts("");
		map<int,int> ret;
		vi org;
		int x;
		while ((scanf("%d", &x)) && x != 99) org.pb(x-1);
		int s = 0;
		char S[110];
		gets(S);
		while (gets(S) && *S) {
			sscanf(S, "%d", &x); x--;
			int p = -1, b = 20;
			for (int i = 0; i < sz(org); i++) if (!ret.count(org[i]))
				if ((400+x-org[i]-s)%20 < b) b = (400+x-org[i]-s)%20, p = i;
			s += b;
			ret[org[p]] = x;
		}
		for (int i = 0; i < sz(org); i++)
			if (ret.count(org[i])) printf("Original position %d parked in %d\n", org[i]+1, ret[org[i]]+1);
			else printf("Original position %d did not park\n", org[i]+1);
	}

    return 0;
}