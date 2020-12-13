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
  int ret = 1;
  cin >> a;
  for (int i = 1; i < a.size(); i++, ret++) {
    b = a.substr(i) + a.substr(0,i);
    if (a == b) break;
  }
  cout << ret;
}
