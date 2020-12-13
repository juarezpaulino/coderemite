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


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	auto s = vector<string>({"vaporeon","jolteon","flareon","espeon","umbreon","leafeon","glaceon","sylveon"});
	int n; cin >> n;
	string p; cin >> p;
	for (auto &u: s) if (sz(u) == n && regex_match(u, regex(p))) cout << u << endl; 
}