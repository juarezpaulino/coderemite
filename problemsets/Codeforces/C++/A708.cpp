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
	string a; cin >> a;
	int k = 0;
	while (k < a.size() && a[k] == 'a') k++;
	if (k == a.size()) { a.back() = 'z', cout << a; return 0; }
	while (k < a.size() && a[k]!='a') a[k++]-=1;
	cout << a;
}