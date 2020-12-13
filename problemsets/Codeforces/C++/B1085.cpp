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
	int n, k; cin >> n >> k;
	int p = k-1;
	while (n%p) p--;
	cout << n/p*k+p;
}