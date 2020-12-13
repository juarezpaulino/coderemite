/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int &u: a) cin >> u;
  ll x = accumulate(begin(a), end(a), 0LL);
  for (int i = 0; i < n-1; i++) cin >> a[i];
  ll y = accumulate(begin(a), end(a)-1, 0LL);
  for (int i = 0; i < n-2; i++) cin >> a[i];
  ll z = accumulate(begin(a), end(a)-2, 0LL);
  cout << x-y << endl;
  cout << y-z;
} 
