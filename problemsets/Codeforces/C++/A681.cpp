/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n) {
    string h;
    int b, a;
    cin >> h >> b >> a;
    if (b >= 2400 && a > b) break;
    n--;
  }
  cout << (n ? "YES" : "NO");
}

