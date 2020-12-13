/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  string a;
  int ret = 0, t = 0;
  while (d--) {
    cin >> a;
    if (a.find("0")!=-1) ret = max(ret, ++t);
    else t = 0;
  }
  cout << ret;
}

