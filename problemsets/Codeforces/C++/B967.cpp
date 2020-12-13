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
  int n, A, B; cin >> n >> A >> B;
  long long sum = 0;
  int x, s[101010]; cin >> x; sum = x;
  for (int i = 0; i < n-1; i++) cin >> s[i], sum += s[i];
  sort(s, s+n-1, greater<int>());
  int ret = 0;
  for (int i = 0; i < n-1; i++) { 
    if (x*A >= (long long)sum*B) break;
    sum -= s[i]; ret++;
  }
  cout << ret;
}
