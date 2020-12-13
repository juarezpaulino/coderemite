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
  string a; cin >> a;
  sort(begin(a), end(a));
  int ret = 0, l = 'a'-2;
  for (int i = 0; i < n && k; i++) {
    if (a[i] <= l+1) continue;
    l = a[i]; k--;
    ret += l-'a'+1;
  }
  cout << (k ? -1 : ret);
}
