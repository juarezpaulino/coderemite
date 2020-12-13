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

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int dy[] = { 0, -1, 0, 1, 0 };
int dx[] = { 0, 0, -1, 0, 1 };

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	string s;
	while (getline(cin, s)) {
		cout << "Case #" << tt++ << ":";
		vvi ret(3,vi(3,0));
		for (int i = 0; i < sz(s); i++) {
			int v = s[i]-'a', y = v/3, x = v%3;
			for (int k = 0; k < 5; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (ny < 0 || nx < 0 || ny > 2 || nx > 2) continue;
				ret[ny][nx]++;
				ret[ny][nx]%=10;
			}
		}
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
			cout << ((j)?' ':'\n') << ret[i][j];
		cout << endl;
	}

    return 0;
}