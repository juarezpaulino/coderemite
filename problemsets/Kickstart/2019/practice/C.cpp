/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;

ll modpow(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b%2) ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}

ll solve() {
  int n, k;
  long long x1, y1, x, c, d, e1, e2, f;
  cin >> n >> k >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;
  vector<ll> a(n+1);
  for (int i = 1; i <= n; i++) {
    a[i] = (x1+y1)%f;
    tie(x1,y1) = make_pair( (c*x1 + d*y1 + e1) % f, (d*x1 + c*y1 + e2) % f );
  }
  ll total = 0;
  ll gps = k;
  for (int i = 2; i <= n+1; i++) {
    total = (total+(n-i+2)*a[i-1]%mod*gps%mod)%mod;
    gps = (gps+(modpow(i,k+1)-1)*modpow(i-1,mod-2)%mod)%mod-1;
    if (gps < 0) gps += mod;
  }
  return total;
}

int main() {
  ios::sync_with_stdio(0);
  int t; cin >> t;
  for (int i = 1; i <= t; i++) 
    cout << "Case #" << i << ": " << solve() << endl;
}