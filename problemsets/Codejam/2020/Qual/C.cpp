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

typedef pair<int,int> pii;
typedef vector<pii> vpi;

void solve() {
	int n; cin >> n;
	vpi a(n);
	string ret(n,' ');
	char v[] = " CJ";
	priority_queue<pii> q;
	for (auto &u: a) cin >> u.fi >> u.se;
	for (int i = 0; i < n; i++) q.push(mp(-a[i].fi, -i));
	int z[3]={0};
	while (!q.empty()) {
		int y = q.top().se;
		q.pop();
		if (y > 0) { z[y] = 0; continue; }
		int k = !z[1] ? 1 : !z[2] ? 2 : -1;
		if (k == -1) { cout << "IMPOSSIBLE" << endl; return; }
		ret[-y] = v[k];
		z[k] = 1;
		q.push(mp(-a[-y].se,k));
	}
	cout << ret << endl;
}

int main() {
  //	setbuf(stdout, NULL);
 	cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}