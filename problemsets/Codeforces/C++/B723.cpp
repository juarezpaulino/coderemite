/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> longestWords(string &a) {
  int s = 0;
  auto ret = vector<int>(2,0);
  bool p = 0;
  for (char &c: a)
    if (!p && c=='(') p = 1, s = 0;
    else if (p && c==')') p = 0, ret[1] += s ? 1 : 0, s = 0;
    else if (isalpha(c)) {
      s++;
      if (!p) ret[0] = max(ret[0], s);
    }
    else {
      if (p) ret[1] += s ? 1 : 0;
      s = 0;
    }
  return ret;
}
int main() {
  int n; cin >> n;
  string a; cin >> a;
  auto ret = longestWords(a);
  cout << ret[0] << " " << ret[1] << endl;
}
