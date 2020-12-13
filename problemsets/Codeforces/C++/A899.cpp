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
  string a;
  cin >> n; cin.get();
  getline(cin, a);
  int two = count(begin(a), end(a), '2'), one = n-two;
  int m = min(one, two);
  one -= m;
  cout << m + (one > 2 ? one/3 : 0);
}
