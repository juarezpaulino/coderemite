/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  m %= n*(n+1)/2;
  int x = (sqrt(1 + 8*m) - 1) / 2;
  x = min(x, n);
  cout << m - x*(x+1)/2;
}

