/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (auto &u: a) cin >> u;
	int dp[16][370];
	memset(dp, -1, sizeof(dp));
	function<bool(int,int)> findLock = [&](int k, int u) {
	  if (k == n) return u == 0;
	  int &ret = dp[k][u];
	  if (ret != -1) return (bool)ret;
	  ret = 0;
	  if (!ret) ret = findLock(k+1, (u+a[k])%360);
	  if (!ret) ret = findLock(k+1, (u+360-a[k])%360);
	  return (bool)ret;
	};
	cout << (findLock(0,0)?"YES":"NO");
}