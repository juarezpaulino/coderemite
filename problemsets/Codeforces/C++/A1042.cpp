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
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int &u: a) cin >> u;
	sort(begin(a), end(a));
	int maxi = a[n-1]+m;
  for (int i = 0; m && i < n-1; i++)
    m -= min(m, a[n-1]-a[i]);
  cout << a[n-1]+(m+n-1)/n << " " << maxi;
}