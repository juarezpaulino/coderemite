/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, c = 0;
  cin >> n >> k;
  while (n--) {
    string x;
    cin >> x;
    if (count(x.begin(), x.end(), '4') + count(x.begin(), x.end(), '7') <= k) c++;
  }
  cout << c;
}

