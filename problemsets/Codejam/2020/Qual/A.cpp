/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
	int n; cin >> n;
	vvi a(n, vi(n));
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	int t = 0;
	for (int i = 0; i < n; i++) t += a[i][i];
	int r = 0;
	for (int i = 0; i < n; i++) {
		set<int> s; int k = 0;
		for (int j = 0; j < n; j++) {
			if (s.count(a[i][j])) { k = 1; break; }
			s.insert(a[i][j]);
		}
		r+=k;
	}
	int c = 0;
	for (int j = 0; j < n; j++) {
		set<int> s; int k = 0;
		for (int i = 0; i < n; i++) {
			if (s.count(a[i][j])) { k = 1; break; }
			s.insert(a[i][j]);
		}
		c+=k;
	}
	cout << t << " " << r << " " << c << endl;
}

int main() {
  //setbuf(stdout, NULL);
 	cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}