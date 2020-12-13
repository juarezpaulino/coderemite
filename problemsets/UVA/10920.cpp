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
typedef vector<vi> vvi;
typedef vector<string> vs;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int dy[] = {1,0,-1,0};
int dx[] = {0,-1,0,1};

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	ll P;
	while (cin >> N >> P && N+P) {
		pii ret = mp((N+1)/2,(N+1)/2);
		if (P != 1) {
			ll u = (int)sqrt(P)+.5;
			ret = mp(ret.fi + (u%2==0?-(u-1)/2:u/2), ret.se + (u%2==0?-u/2:u/2));
			if (u*u != P) {
				int d = (u%2) ? 0 : 2;
				int y = ret.fi + (u-1)*dy[2-d],
					x = ret.se + (u-1)*dx[2-d];
				ll p = u*u-(u-1);
				for (; p < P; u++) {
					for (int k = 0; k < 2 && p < P; k++, d = (d+1)%4) {
						if (p + u >= P) y += (P-p)*dy[d], x += (P-p)*dx[d], ret = mp(y,x), p = P;
						else p += u, y += u*dy[d], x += u*dx[d];
					}
				}
			}
		}
		cout << "Line = " << ret.fi << ", column = " << ret.se << "." << endl;
	}

    return 0;
}