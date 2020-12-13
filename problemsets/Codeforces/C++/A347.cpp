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


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int &u: a) cin >> u;
	int ret = 0, sw = 0;
	for (int i = 0; i < n; i++) {
	  if (!sw && i != a[i] && i == a[a[i]]) ret+=2, sw = 1;
	  else ret += i == a[i];
	}
	if (!sw && ret < n) ret++;
	cout << ret; 
}