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
	int n, x, s = 0; cin >> n;
	while (n--) {
	  cin >> x;
	  if (x == 0 && s%2) { cout << "NO"; return 0; }
	  s += x%2;
	}
	cout << (s%2?"NO":"YES");
}