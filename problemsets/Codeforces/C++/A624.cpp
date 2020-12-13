/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int d, L, v1, v2;
  cin >> d >> L >> v1 >> v2;
  printf("%.8lf", (L-d) / (double)(v1+v2));
}
