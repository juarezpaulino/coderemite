/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &u: a) cin >> u;
  cout << count_if(begin(a), end(a), [&](int u){ return u <= 5-k; })/3;
}
