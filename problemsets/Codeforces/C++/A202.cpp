/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  string a;
  cin >> a;
  char l = *max_element(begin(a), end(a));
  cout << string(count(begin(a), end(a), l), l);
}
