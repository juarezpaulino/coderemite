/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  map<string,string> m;
  set<string> newer;
  while (n--) {
    string a, b; cin >> a >> b;
    m[a] = b;
    newer.insert(b);
  }
  vector<pair<string,string>> ret;
  for (auto &u: m) {
    if (newer.count(u.first)) continue;
    string v = u.second;
    while (m.count(v)) v = m[v];
    ret.emplace_back(make_pair(u.first,v));
  }
  cout << ret.size() << endl;
  for (auto &u: ret) cout << u.first << " " << u.second << endl;
}
