/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) (int)((a).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int findDivisor(int n) {
  if (n%2==0) return 2;
  if (n%3==0) return 3;
  for (int i = 5; i*i <= n; i+=6)
    if (n%i==0) return i;
    else if (n%(i+2)==0) return i+2;
  return n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int ret = n, c;
	while ((c = findDivisor(n)) != 1) ret+=n/=c;
	cout << ret;
}