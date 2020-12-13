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
  sort(begin(a), end(a));
  if (a[0]==a[n/2-1] && a[n/2]==a[n-1] && a[0]!=a[n-1])
    cout << "YES\n" << a[0] << " " << a[n-1];
  else cout << "NO";
}
