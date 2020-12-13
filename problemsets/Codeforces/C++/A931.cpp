/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int m = (a+b)/2;
  a = abs(m-a);
  b = abs(m-b);
  cout << a*(a+1)/2 + b*(b+1)/2;
}

