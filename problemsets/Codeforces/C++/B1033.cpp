/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long n) {
  if (n == 2 || n == 3) return 1;
  if (n%2==0 || n%3==0) return 0;
  for (long long p = 5; p*p <= n; p+=6)
    if (n%p==0 || n%(p+2)==0) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  int t; cin >> t;
  long long a, b;
  while (t--) {
    cin >> a >> b;
    cout << (a-b==1 && is_prime(a+b)?"YES":"NO") << endl;
  }
}