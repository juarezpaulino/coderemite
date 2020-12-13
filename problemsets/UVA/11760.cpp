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

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	int tt = 1;
	int R, C, N;
	while (cin >> R >> C >> N && R+C+N) {
		set<int> r, c;
		int y, x;
		for (int i = 0; i < N; i++) cin >> y >> x, r.insert(y), c.insert(x);
		cin >> y >> x;
		int ret = !r.count(y) && !c.count(x);
		for (int k = 0; !ret && k < 4; k++) {
			int ny = y+dy[k], nx = x+dx[k];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			ret |= !r.count(ny) && !c.count(nx);
		}
		cout << "Case " << tt++ << ": ";
		if (ret) cout << "Escaped again! More 2D grid problems!" << endl;
		else cout << "Party time! Let's find a restaurant!" << endl;
	}

	return 0;
}