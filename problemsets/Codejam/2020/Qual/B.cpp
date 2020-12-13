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

typedef vector<int> vi;

void solve() {
	string a; cin >> a;
	int l = 0;
	for (auto c: a) {
		int d = c-'0';
		while (l < d) cout << '(', l++;
		while (l > d) cout << ')', l--;
		cout << c;
	}
	while (l--) cout << ')';
	cout << endl;
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