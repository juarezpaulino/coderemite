/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
long long power2[40];
int main() {
  for (int p = 1, i = 0; i <= 30; i++, p<<=1, power2[i] = power2[i-1]) power2[i] += p;
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << (long long)n*(n+1)/2 - 2*power2[31-__builtin_clz(n)] << endl;
  }
}
