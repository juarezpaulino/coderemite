/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  cout << (k <= (n+1)/2 ? k*2-1 : (k - (n+1)/2) * 2);
}
