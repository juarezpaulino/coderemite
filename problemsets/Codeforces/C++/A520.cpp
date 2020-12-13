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
  cin >> n >> a;
  transform(begin(a), end(a), begin(a), [](char c){return tolower(c);});
  sort(begin(a), end(a));
  cout << (unique(begin(a), end(a))-begin(a)==26?"YES":"NO");
}
