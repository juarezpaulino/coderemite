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
	int a, b, c; cin >> a >> b >> c;
	unordered_set<int> vis;
	queue<int> q; q.push(0);
	while (!q.empty()) {
	  int u = q.front(); q.pop();
	  if (u > c) continue;
	  if (!vis.count(u+a)) q.push(u+a), vis.insert(u+a);
	  if (!vis.count(u+b)) q.push(u+b), vis.insert(u+b);
	}
	cout << (vis.count(c)?"YES":"NO");
}