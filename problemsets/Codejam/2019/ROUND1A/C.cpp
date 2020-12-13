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

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void solve() {
  int n; cin >> n;
  vector<map<char,int>> trie;
  vector<int> visited;
  vector<int> parent;
  vector<int> used;
  trie.eb();
  visited.eb(0);
  parent.eb(-1);
  used.eb(0);
  while (n--) {
    string w; cin >> w;
    int cur = 0;
    for (auto c: string(rbegin(w), rend(w))) {
      if (!trie[cur].count(c)) {
        trie[cur][c] = sz(trie);
        trie.eb();
        visited.eb(0);
        parent.eb(cur);
        used.eb(0);
      }
      cur = trie[cur][c];
      visited[cur]++;
    }
  }
  int pairs = 0;
  for (int i = sz(trie)-1; i >= 0; i--) {
    if (visited[i]-used[i] >= 2) {
      pairs++;
      used[i] += 2;
    }
    if (i) used[parent[i]] += used[i];
  }
  cout << pairs * 2 << endl;
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