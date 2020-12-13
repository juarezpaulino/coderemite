/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int ret = 0;
  auto vowels = set<char>{'a','e','i','o','u'};
  auto isvowel = [&](char c) { return vowels.count(c); };
  for (auto c: s)
    ret += isalpha(c) ? isvowel(c) : (c-'0')%2;
  cout << ret;
}
