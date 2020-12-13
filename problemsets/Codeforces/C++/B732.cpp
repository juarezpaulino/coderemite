/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n+2); a[0] = a[n+1] = k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    int add = max(0, k-a[i-1]-a[i]);
    ret += add; a[i] += add;
  }
  cout << ret << endl;
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
