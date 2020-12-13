/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  cout << (n%7==0 || n%4==0 || n%47==0 || n%447==0 || n%477==0 ? "YES" : "NO"); 
}
