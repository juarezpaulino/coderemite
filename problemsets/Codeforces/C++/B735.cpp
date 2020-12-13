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
	int n, n1, n2; cin >> n >> n1 >> n2;
	vector<int> a(n); for (int &u: a) cin >> u;
	sort(begin(a), end(a), greater<int>());
	if (n1 > n2) swap(n1,n2);
	double s1 = 0, s2 = 0;
	int m1 = n1, m2 = n2;
	for (int i = 0; (m1 || m2) && i < n; i++) {
	  if (m1) s1 += a[i], m1--;
	  else if (m2) s2 += a[i], m2--;
	}
	cout << setprecision(10) << fixed << s1/n1 + s2/n2;
}