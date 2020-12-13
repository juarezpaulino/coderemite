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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x; cin >> n;
	bool odd = 0;
	long long s = 0;
	while (n--) cin >> x, s += x, odd |= x%2;
	cout << (s%2 || odd ? "First" : "Second"); 
}