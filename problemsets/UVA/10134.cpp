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
	char S[1010];
	int TT; cin >> TT; gets(S); gets(S);
	for (int tt = 1; tt <= TT; tt++) {
		int b = 0, B = 0, F = 3, op = 7;
		int ret = 0;
	    while (gets(S)) {
	    	istringstream is(S);
	    	string s;
	    	is >> s;
	    	op++;
	    	if (s == "fish") {
	    		if (!b) continue;
	    		F++;
	    		if (op < 7) continue;
	    		if (F < 3) continue;
	    		ret++; b--; op = 0; F = 0;
	    	}
	    	else if (s == "bait") {
	    		if (b == 3) continue;
	    		B++;
	    		if (B==2) b++, B = 0;
	    	}
	    	else if (s == "lunch");
	    	else break;
	    }
	    cout << ret << endl;
		if (tt != TT) cout << endl;
	}

    return 0;
}