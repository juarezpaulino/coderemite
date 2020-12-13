/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> u(n,2);
  for (int i = 0; i < a; i++) cin >> b, u[b-1] = 1;
  for (auto x: u) cout << x << " ";
}
