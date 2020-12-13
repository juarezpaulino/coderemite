/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, distress = 0;
  long long x, d;
  char c;
  scanf("%d %lld ", &n, &x);
  for (int i = 0; i < n; i++) {
    scanf("%c %lld ", &c, &d);
    if (c=='-' && x < d) {
      distress++;
      continue;
    }
    x += (c=='+') ? d : -d;
  }
  cout << x << " " << distress;
}
