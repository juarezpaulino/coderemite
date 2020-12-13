/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, v;
  cin >> n >> v;
  cout << (v >= n-1 ? n-1 : v + (n-v)*(1+n-v)/2 -1);
}
