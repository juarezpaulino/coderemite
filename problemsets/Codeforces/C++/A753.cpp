/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n; cin >> n;
  int m = (sqrt(1+8*n)-1+1E-8)/2, s = 0;
  cout << m << endl;
  for (int i = 1; i < m; i++) cout << i << " ", s+=i;
  cout << n-s;
}