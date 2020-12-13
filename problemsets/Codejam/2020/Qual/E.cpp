/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

struct tup {
	int a, b, na, nb;
};

int row[110][110], col[110][110], id = 1;
int A[110][110];

void solve() {
	int n, k; cin >> n >> k;
	map<int,tup> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		for (int u = 0; u < n; u++) {
			int v = n-u;
			m[u*i+v*j] = {i,j,u,v};
		}
	if (!m.count(k)) { cout << "IMPOSSIBLE" << endl; return; }
	int a, b, na, nb;
	a = m[k].a;
	b = m[k].b;
	na = m[k].na;
	nb = m[k].nb;
	cout << a << " " << b << " " << na << " " << nb << endl;
	for (int i = 0; i < (n+1)/2; i++) {
		if (i < na) {
			if (a != b && n%2==0)
				A[i][n-1-i] = A[n-1-i][i] = b, row[i][b] = row[n-1-i][b] = col[i][b] = col[n-1-i][b] = id;
			A[i][i] = A[n-1-i][n-1-i] = a, row[i][a] = row[n-1-i][a] = col[i][a] = col[n-1-i][a] = id;
		}
		else {
			if (a != b && n%2==0)
				A[i][n-1-i] = A[n-1-i][i] = a, row[i][a] = row[n-1-i][a] = col[i][a] = col[n-1-i][a] = id;
			A[i][i] = A[n-1-i][n-1-i] = b, row[i][b] = row[n-1-i][b] = col[i][b] = col[n-1-i][b] = id;
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i!=j) {
		if (n%2==0 && i==n-1-j) continue;
		for (int u = 1; u <= n; u++) if (row[i][u]!=id && col[j][u]!=id) {
			A[i][j] = u, row[i][u] = col[j][u] = id;
			break;
		}
	}
	cout << "POSSIBLE" << endl;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cout << A[i][j] << " \n"[j==n-1];
}

int main() {
  setbuf(stdout, NULL);
 	cin.tie(0);
  //ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
  	id++;
    cout << "Case #" << i << ": ";
    solve();
  }
}