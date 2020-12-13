/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
 long long n; cin >> n; n++;
 cout << (n==1 ? 0 : n%2 ? n : n/2);
}
