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
  cin >> n;
  auto ret = vector<string>(n, string(n,'D'));
  for (int i = 0; i < n/2; i++) for (int j = 0; j < n/2-i; j++)
    ret[i][j] = ret[n-1-i][j] = ret[i][n-1-j] = ret[n-1-i][n-1-j] = '*';
  for (int i = 0; i < n; i++) cout << ret[i] << endl;
}

