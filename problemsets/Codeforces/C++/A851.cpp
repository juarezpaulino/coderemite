/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, t;
  cin >> n >> k >> t;
  cout << (t<k?t:t<=n?k:k-(t-n));
}
