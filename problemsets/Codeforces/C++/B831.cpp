/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  char m[300];
  for (int i = 0; i < 300; i++) m[i] = i;
  string a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i < 26; i++) m[a[i]] = b[i], m[toupper(a[i])] = toupper(b[i]);
  for (int i = 0; i < c.size(); i++) cout << m[c[i]];
}

