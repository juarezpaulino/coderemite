/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) (int)((a).size())
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m; cin >> m;
	vi c(m);
	for (auto &u: c) cin >> u;
	int x, y; cin >> x >> y;
	int sum = accumulate(all(c),0);
	int ret = 0, s = 0;
	for (int i = 0; i < m; i++) {
	  s += c[i];
	  if (x <= s && s <= y &&
	      x <= sum-s && sum-s <= y)
	      ret = i+2;
	}
	cout << ret;
}