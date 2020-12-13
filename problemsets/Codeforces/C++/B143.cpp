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

int deg[101010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a; cin >> a;
	int p, n = sz(a);
	bool minus = a[0]=='-';
	if ((p = a.find('.')) != string::npos) {
	  if (n < p+3) a += '0';
	  else a = a.substr(0,p+3);
	}
	else p = n, a = a + ".00";
	string b = "";
	int c = 0;
	for (int i = p-1; i >= 0 && a[i]!='-'; i--) {
	  if (c == 3) b += ",", c = 0;
	  b += a[i]; c++;
	}
	a = string(b.rbegin(), b.rend()) + a.substr(p);
	if (minus) a = "($" + a + ")";
	else a = "$" + a;
	cout << a;
}