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
  cout << n/7*2 + max(0,n%7-5) << " " << n/7*2 + min(2, n%7);
}
