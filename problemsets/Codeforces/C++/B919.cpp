/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int k; cin >> k;
  string a = "00000000019";
  auto next = [](string &a) {
    for (int i = a.size()-1; i >= 0; i--) {
      if (a[i]=='0') continue;
      if (a[i-1]=='9') { a.replace(i-2, 3, "100"); a[a.size()-1] = '9'; }
      else {
        a[i-1]++;
        a[a.size()-1] = a[i]-1;
        if (i != a.size()-1) a[i] = '0';
      }
      break;
    }
  };
  while (--k) next(a);
  cout << stoi(a);
}
