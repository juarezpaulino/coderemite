/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  string a;
  cin >> a;
  int one = count(begin(a), end(a), '1'),
       two = count(begin(a), end(a), '2'),
       three = count(begin(a), end(a), '3');
  string ret;
  for (int i = 0; i < one; i++) ret += "1+";
  for (int i = 0; i < two; i++) ret += "2+";
  for (int i = 0; i < three; i++) ret += "3+";
  cout << ret.substr(0, ret.size()-1);
}
