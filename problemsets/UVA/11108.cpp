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
#define clz(x) (__builtin_clz(x))
#define szb(x) (sizeof(int)*8 - clz(x))

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<double> vd;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	string s;
	bool u, v;
	while (cin >> s && s != "0") {
		bool ret = 1;
		for (int m = 0; ret && m < (1<<5); m++) {
			stack<bool> A;
			for (int i = sz(s)-1; i >= 0; i--) {
				if (islower(s[i])) A.push(m&(1<<s[i]-'p'));
				else if (s[i]=='N') u = A.top(), A.pop(), A.push(!u);
				else {
					u = A.top(), A.pop();
					v = A.top(), A.pop();
					if (s[i]=='K') A.push(u&v);
					else if (s[i]=='A') A.push(u|v);
					else if (s[i]=='C') A.push(!u|v);
					else if (s[i]=='E') A.push(!u^v);
				}
			}
			ret &= A.top();
		}
		if (ret) cout << "tautology" << endl;
		else cout << "not" << endl;
	}
	
	return 0;
}