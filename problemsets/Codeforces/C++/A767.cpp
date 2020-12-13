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

bool vis[100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int cur = n;
	while (n--) {
	  int a; cin >> a; vis[a] = 1;
	  if (a == cur) {
	    while (vis[a]) cout << a-- << " ";
	    cout << endl;
	    cur = a;
	  }
	  else cout << endl;
	}
}