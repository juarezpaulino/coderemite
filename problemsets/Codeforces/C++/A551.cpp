/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int a[2020], c[2020];
int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], c[a[i]]++;
  for (int i = 2000; i >= 0; i--) c[i] += c[i+1];
  for (int i = 0; i < n; i++) cout << c[a[i]+1]+1 << " ";
}
