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

string a, b;
string ret;
stack<char> P;

void go(int k, int i, int o) {
	if (i == sz(a) && o == sz(b)) {
		cout << ret[0];
		for (int i = 1; i < sz(ret); i++) cout << " " << ret[i];
		cout << endl;
		return; 
	}
	if (i < sz(a)) {
		P.push(a[i]); ret[k] = 'i';
		go(k+1, i+1, o);
		P.pop();
	}
	if (o < i) {
		if (P.top() == b[o]) {
			P.pop(); ret[k] = 'o';
			go(k+1, i, o+1);
			P.push(b[o]);
		}
	}
}

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	while (cin >> a >> b) {
		string sa = a; sort(all(sa));
		string sb = b; sort(all(sb));
		if (sa != sb) { cout << "[\n]\n"; continue; }
		cout << "[" << endl;
		ret.resize(sz(a)<<1);
		go(0,0,0);
    	cout << "]" << endl;
	}

	return 0;
}