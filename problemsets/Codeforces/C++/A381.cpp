/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, ret[2] = {0}, d = 0, a;
  cin >> n;
  deque<int> q;
  for (int i = 0; i < n; i++) {
    cin >> a;
    q.push_back(a); 
  }
  while (!q.empty()) {
    if (q.front() > q.back()) ret[d] += q.front(), q.pop_front();
    else ret[d] += q.back(), q.pop_back();
    d = 1-d;
  }
  cout << ret[0] << " " << ret[1];
}
