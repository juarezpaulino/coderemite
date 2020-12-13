/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k; cin >> n >> k;
  vector<pair<int,int> > a(n);
  for (auto &u: a) cin >> u.first, u.second = &u-&a[0]+1;
  sort(begin(a), end(a));
  int s = 0;
  vector<int> ret;
  for (auto &u: a) {
    s += u.first;
    if (s > k) break;
    ret.emplace_back(u.second);
  }
  sort(begin(ret),end(ret));
  cout << ret.size() << endl;
  for (int &u: ret) cout << u << " ";
}
