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
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef vector<int> vi;

string x, ret;
int B, b;
vi p;

inline int v(char c) { return c-'0'; }
inline void t2(string &a) { for (auto &c: a) c=(v(c)^1)+'0'; }
inline void t3(string &a) { reverse(all(a)); }
inline void t4(string &a) { t2(a); t3(a); }

void check() {
	for (int i = 0; i < b; i++)
		p[v(ret[i])^v(ret[B-1-i])] = i;
}

void quantum() {
	int k = 10;
	int u[2] = {-1,-1};
	for (int i = 0; i < 2; i++) if (p[i] > -1) {
		int z = i ? B-1-p[i] : p[i];
		cout << z+1 << endl; cin >> x;
		u[i] = v(ret[p[i]])^v(x[0]);
		k--;
	}
	if (p[0]<0) {
		if (!u[1]) t2(ret);
	}
	else if (p[1]<0) {
		if (u[0]) t2(ret);
	}
	else {
		if      (u[0]&&u[1]) t4(ret);
		else if (u[0]&&!u[1]) t2(ret);
		else if (!u[0]&&!u[1]) t3(ret);
	}
	if (k%2) { cout << 1 << endl; cin >> x; }
	for (int i = 0; b<(B+1)/2 && i < k/2; i++, b++) {
		cout << b+1 << endl; cin >> x; ret[b]=x[0];
		cout << B-b << endl; cin >> x; ret[B-b-1]=x[0];
	}	
}

void solve() {
	b=0;
	p = vi(2,-1);
	ret = string(B,'0');

	for (int i = 0; i < 5; i++, b++) {
		cout << b+1 << endl; cin >> x; ret[b]=x[0];
		cout << B-b << endl; cin >> x; ret[B-b-1]=x[0];
	}
	while (1) {
		check();
		quantum();
		if (b >= (B+1)/2) {
			cout << ret << endl; cin >> x;
			if (x == "N") exit(0);
			return;
		}
	}
}

int main() {
  setbuf(stdout, NULL);
 	//cin.tie(0);
  ios::sync_with_stdio(0);

int t; cin >> t >> B;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}