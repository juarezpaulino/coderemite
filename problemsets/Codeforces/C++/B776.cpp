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

#define MAX 100010
bool comp[MAX];
vector<int> prime;
void sieve (int n) {
	comp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!comp[i]) prime.eb(i);
		for (int p: prime) {
			if (i*p > n) break;
			comp[i*p] = 1;
			if (i%p == 0) break;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	sieve(n+1);
	cout << (n<3?1:2) << endl;
	for (int i = 2; i <= n+1; i++)
	  cout << (!comp[i] ? 1 : 2) << " ";
}