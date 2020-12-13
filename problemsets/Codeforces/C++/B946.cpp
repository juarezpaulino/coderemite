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
typedef pair<int,int> pii;

#define sqr(x) (x)*(x)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b; cin >> a >> b;
	while (a && b && (a >= b<<1 || b >= a<<1))
	  tie(a,b) = make_pair(a%(b<<1), b%(a<<1));
	cout << a << " " << b;
}