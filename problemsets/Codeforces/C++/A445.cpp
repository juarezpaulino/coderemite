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
	int n, m; cin >> n >> m;
	string a;
	bool b = 0;
	for (int i = 0; i < n; i++) {
	  cin >> a; bool c = 1-b;
	  for (int j = 0; j < m; j++, c^=1) if (a[j]=='.') a[j] = c ? 'B' : 'W';
	  cout << a << endl; b = 1-b;
	}
}