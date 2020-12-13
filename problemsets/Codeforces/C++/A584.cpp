/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t; cin >> n >> t;
  if (t == 10 && n == 1) cout << -1;
  else if (t == 10) cout << "1" + string(n-1,'0');
  else cout << string(n,'0'+t);
}
