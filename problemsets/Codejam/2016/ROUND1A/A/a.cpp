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
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> ent;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		cout << "Case #" << tt << ": ";
		string S;
		cin >> S;
		string ret = string(1,S[0]);
		for (int i = 1; i < sz(S); i++) ret = (S[i]>=ret.front()) ? S[i] + ret : ret + S[i];
		cout << ret << endl;
	}

    return 0;
}