/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define MAX 505050

int sieve[MAX];

int main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);
  for (int i = 5; i < MAX; i*=5) {
    for (int j = i; j < MAX; j+=i) sieve[j]++;
  }
  for (int i = 1; i < MAX; i++) sieve[i] += sieve[i-1];
  int m; cin >> m;
  int *v = lower_bound(sieve, sieve+MAX, m);
  if (*v != m) cout << "0";
  else {
    cout << 5 << endl;
    for (int i = 0; i < 5; i++) cout << (v-sieve)+i << " ";
  }
}