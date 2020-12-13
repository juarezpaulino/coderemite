/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int m, n;
  cin >> n >> m;
  vector<int> u(n);
  for (auto &x: u) cin >> x;
  sort(u.begin(), u.end(), greater<int>());
  int p = 0;
  while (m > 0) m-=u[p++];
  cout << p << endl;
}

