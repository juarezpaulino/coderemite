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
	int x, y; cin >> x >> y;
	cout << (x==y||pii(minmax(x,y))==pii(2,4) ? "=" :
	         x<y ? (x==1||x==2&&y==3) ? "<" : ">" :
	               (y==1||y==2&&x==3) ? ">" : "<");
}