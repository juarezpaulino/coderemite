/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, ret = 0;
  char c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if ((c-'0')%2==0)
      ret += i+1;
  }
  cout << ret;
}
