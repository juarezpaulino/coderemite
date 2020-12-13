/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vpii;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int L[101010], R[101010];

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);

	int N, B;
	while (cin >> N >> B && N+B) {
		for (int i = 1; i <= N; i++) L[i] = i-1, R[i] = i+1;
		for (int k = 0; k < B; k++) {
			int a, b; cin >> a >> b;
			int l = L[a], r = R[b];
			R[l] = r; L[r] = l;
			if (l < 1) cout << "*";  else cout << l;
			if (r > N) cout << " *"; else cout << " " << r;
			cout << endl; 
		}
		cout << "-" << endl;
	}

    return 0;
}