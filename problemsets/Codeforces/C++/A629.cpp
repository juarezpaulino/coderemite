/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, ret = 0, t;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i], t = count(begin(a[i]), end(a[i]),'C'), ret += t!=1?t==2?1:t*(t-1)/2:0;
  for (int i = 0, t = 0; i < n; i++, t = 0) {
    for (int j = 0; j < n; j++)
      if (a[j][i]=='C') t++;
    ret += t!=1?t==2?1:t*(t-1)/2:0;
  }
  cout << ret;
}

