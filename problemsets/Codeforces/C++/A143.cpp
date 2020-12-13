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
	int r1, r2; cin >> r1 >> r2;
	int c1, c2; cin >> c1 >> c2;
	int d1, d2; cin >> d1 >> d2;
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	bool ok = 0;
	do {
	  if (a[0]+a[1] == r1 && a[2]+a[3] == r2 &&
	      a[0]+a[2] == c1 && a[1]+a[3] == c2 &&
	      a[0]+a[3] == d1 && a[1]+a[2] == d2) {
	      ok = 1; break;
	  }
	  reverse(a+4, a+9);
	} while (next_permutation(a, a+9));
	if (ok) cout << a[0] << " " << a[1] << endl << a[2] << " " << a[3];
	else cout << "-1";
}