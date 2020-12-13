/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, ret = 0; cin >> a >> b;
  while (a > 0 && b>0) {
    if (a < b) a++, b-=2;
    else a-=2, b++;
    ret++;
  }
  if (a < 0 || b < 0) ret--;
  cout << ret;
}
