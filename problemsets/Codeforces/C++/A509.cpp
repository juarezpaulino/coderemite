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
	function<int(int,int)> go = [&](int r, int c) {
		if (r == 1 || c == 1) return 1;
		return go(r-1,c)+go(r,c-1);
	};
	int n; cin >> n;
	cout << go(n,n);
}