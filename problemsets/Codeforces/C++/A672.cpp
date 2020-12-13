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
  string ret;
  for (int i = 0; i < 1000; i++)
    ret += to_string(i);
  cout << ret[n];
}

