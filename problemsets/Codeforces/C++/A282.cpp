/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x = 0;
  cin >> n;
  string a;
  while (n--) cin >> a, a.find("+")!=string::npos?x++:x--;
  cout << x;
}
