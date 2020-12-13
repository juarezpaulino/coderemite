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
  int n; cin >> n;
  while (n--) {
    int a, b; cin >> a >> b;
    int ret = 0;
    while (a && b) {
      if (a > b) ret += a/b, a %=b;
      else ret += b/a, b%=a;
    }
    cout << ret << endl;
  }
} 
