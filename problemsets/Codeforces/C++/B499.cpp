/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  map<string,string> notebook;
  while (m--) {
    string a, b;
    cin >> a >> b;
    notebook[a] = a.size() <= b.size() ? a : b;
  }
  while (n--) {
    string a; cin >> a;
    cout << notebook[a] << " ";
  }
}
