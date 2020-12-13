/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> retrieveSequence(vector<int> &a) {
  vector<int> b(a.size());
  long long acc = 0;
  for (int i = a.size()-1; i >= 0; i--) {
    b[i] = a[i] + acc;
    acc = b[i] - acc;
  }
  return b;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &u: a) cin >> u;
  auto b = retrieveSequence(a);
  for (int &u: b) cout << u << " ";
}
