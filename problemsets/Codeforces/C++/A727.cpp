/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  int a, b; cin >> a >> b;
  unordered_set<ll> vis;
  vector<ll> ret;
  function<bool(ll)> findPath = [&](ll u) {
    if (u > b) return false;
    vis.insert(u);
    if (u == b) { ret.emplace_back(u); return true; }
    bool found = false;
    if (!vis.count(u*10+1) && (found=findPath(u*10+1))) ret.emplace_back(u);
    else if (!vis.count(u*2) && (found=findPath(u*2))) ret.emplace_back(u);
    return found;
  };
  findPath(a);
  if (ret.size() == 0) { cout << "NO"; return 0; }
  reverse(begin(ret), end(ret));
  cout << "YES" << endl;
  cout << ret.size() << endl;
  for (ll &u: ret) cout << u << " ";
}