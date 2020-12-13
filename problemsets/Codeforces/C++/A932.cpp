/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  string a, b;
  cin >> a;
  b = a; reverse(begin(b), end(b));
  cout << b+a;
}

