/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  int v = *max_element(begin(a), end(a));
  cout << (v<=25?0:v-25);
}
