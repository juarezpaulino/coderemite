/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n, l; cin >> n >> l;
  vector<int> a(n);
  for (int &u: a) cin >> u;
  sort(begin(a), end(a));
  double ret = -1.;
  for (int i = 1; i < n; i++)
    ret = max(ret, (a[i]-a[i-1])/2.);
  ret = max(ret, 1.*a[0]);
  ret = max(ret, 1.*l-a[n-1]);
  cout << setprecision(10) << ret << endl;
} 
