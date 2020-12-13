/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int p = 0;
  for (int j = 0; j < t.size(); j++) {
    if (s[p]==t[j]) p++;
  }
  cout << p+1;
}

