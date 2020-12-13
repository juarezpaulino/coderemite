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
	int n, m, minA, minB, maxA, maxB;
	minA = minB = INT_MAX;
	maxA = maxB = INT_MIN;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  int x, y; cin >> x >> y;
	  minA = min(y, minA);
	  maxA = max(x, maxA);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
	  int x, y; cin >> x >> y;
	  minB = min(y, minB);
	  maxB = max(x, maxB);
	}
  cout << max({0,maxA-minB,maxB-minA});
}