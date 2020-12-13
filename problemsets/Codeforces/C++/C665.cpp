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

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	int n = sz(s);
	s = "." + s + ".";
	int ret = 0;
	auto next = [](char c) { return (c-'a'+1)%26+'a'; };
	for (int i = 1; i <= n; i++) {
	  if (s[i] == s[i-1]) {
	    char c = next(s[i]);
	    s[i] = c==s[i+1]?next(c):c;
	  }
	}
	cout << s.substr(1,n);
}