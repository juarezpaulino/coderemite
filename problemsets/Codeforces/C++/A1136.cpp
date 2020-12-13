/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, l, r[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> l >> r[i];
  cin >> k;
  cout << n-(lower_bound(r, r+n, k)-r);
}
