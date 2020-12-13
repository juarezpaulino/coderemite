/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d = 0, s = 0; cin >> n;
  while (n) s+=(1<<d)*(n%10==4?0:1), n/=10, d++;
  cout << (1<<d)+s-1;
}
