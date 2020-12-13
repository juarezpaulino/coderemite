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

inline string lin(vs &A) { return A[0]+A[1]+A[2]; }

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void go(vs &A) {
	vs ret(3,string(3,'0'));
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
		int c = 0;
		for (int k = 0; k < 4; k++) {
			int ny = i+dy[k], nx = j+dx[k];
			if (ny < 0 || nx < 0 || ny > 2 || nx > 2) continue;
			c += A[ny][nx]=='1';
		}
		ret[i][j] = (c%2?'1':'0');
	}
	A = ret;
}


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int TT; cin >> TT;
	while (TT--) {
		vs A(3);
		for (int i = 0; i < 3; i++) cin >> A[i];
		int ret = 0;
		set<string> S;
		S.insert(lin(A));
		string a;
		while (1) {
			go(A);
			a = lin(A);
			if (S.count(a)) break;
			S.insert(a);
			ret++;
		}
		cout << ((ret!=0 && a==string(9,'0'))?ret-1:-1) << endl;
	}

    return 0;
}