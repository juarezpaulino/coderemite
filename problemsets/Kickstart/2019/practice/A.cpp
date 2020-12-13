/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b; cin >> a >> b; a++;
  int n; cin >> n;
  string ret;
  while (a <= b) {
    int m = a + (b-a)/2;
    cout << m << endl; cin >> ret;
    if (ret == "CORRECT") break;
    ret == "TOO_BIG" ? b = m-1 : a = m+1;
  }
}

int main() {
  ios::sync_with_stdio(0);
  setbuf(stdout, NULL);
  
  int t; cin >> t;
  while (t--) {
      solve();
  }
}