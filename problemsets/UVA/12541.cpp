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

int M[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};

int get_day(int m, int d, int y, int by = 0) {
    int ret = d, i;
    for (i = by; i < y; i++) ret += 365 + ((i%4==0&&i%100) || i%400==0 ? 1 : 0);
    for (i = 1; i < m; i++) ret += M[i] + (i==2 && ((y%4==0&&y%100) || y%400==0) ? 1 : 0);
    return ret;
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	int y = 1<<30, o = -1;
	string ry, ro;
	int TT; cin >> TT;
	while (TT--) {
		string a; int dd, mm, yy;
		cin >> a >> dd >> mm >> yy;
		int u = get_day(mm, dd, yy);
		if (u < y) ry = a, y = u;
		if (u > o) ro = a, o = u;
	}
	cout << ro << endl << ry << endl;
		        	
	return 0;
}