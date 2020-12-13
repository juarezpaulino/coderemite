/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a[3] = {0}, p = 0, x;
  cin >> n;
  while (n--) cin >> x, a[p]+=x, p = (p+1)%3;
  if (a[0] > a[1] && a[0] > a[2]) cout << "chest";
  else if (a[1] > a[2]) cout << "biceps";
  else cout << "back";
}


