/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  k--;
  cout << k/2/m+1 << " " << k/2%m+1 << " " << (k%2 ? "R" : "L");
}
