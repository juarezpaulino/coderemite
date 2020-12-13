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
  cout << (n*n+1)/2 << endl;
  string c = "C.";
  for (int i = 0; i < n; i++, cout << endl) {
    int p = i%2;
    for (int j = 0; j < n; j++, p = (p+1)%2)
      cout << c[p];
  }
}

