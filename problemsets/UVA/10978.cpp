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
typedef vector<string> vs;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	int N;
	while (cin >> N && N) {
		vs ret(N,"");
		int p = -1;
		for (int k = 0; k < N; k++) {
			string a, b;
			cin >> a >> b;
			for (int i = 0; i < sz(b); i++) {
				p = (p+1)%N;
				while (ret[p]!="") p = (p+1)%N;
			}
			ret[p] = a;
		}
		cout << ret[0];
		for (int i = 1; i < N; i++) cout << " " << ret[i];
		cout << endl;
	}

    return 0;
}