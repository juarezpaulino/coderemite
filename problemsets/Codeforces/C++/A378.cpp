/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int c = (a+b-1)/2, d = 7 - (a+b+2)/2;
  if (a == b) cout << "0 6 0";
  else if (a < b)
    cout << c << " " << ((a+b)%2==0) << " " << d;
  else 
    cout << d << " " << ((a+b)%2==0) << " " << c;

}




