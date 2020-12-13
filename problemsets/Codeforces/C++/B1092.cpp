/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int ret = 0;
	for (int i = 0; i < n; i+=2) ret += a[i+1]-a[i];
	cout << ret;
}