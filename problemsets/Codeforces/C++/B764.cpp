/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int &u: a) cin >> u;
  for (int i = 0; i < n/2; i+=2) swap(a[i], a[n-i-1]);
  for (int i = 0; i < n; i++) cout << a[i] << " ";
}
