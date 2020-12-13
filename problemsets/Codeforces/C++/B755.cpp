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
	int n, m; cin >> n >> m;
	unordered_set<string> P;
	int common = 0;
	string s;
	for (int i = 0; i < n; i++) cin >> s, P.insert(s); 
  for (int i = 0; i < m; i++) {
    cin >> s;
    if (P.count(s)) common++;
  }
  cout << (n-common/2 > m-(common+1)/2 ? "YES" : "NO");
}