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

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	ll B[50];

	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		int N, M, S;
		cin >> N >> M >> S;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			B[i] = 0;
			for (int j = 0; j < sz(s); j++) B[i] = (B[i]<<1)+(s[j]=='*'?1:0);
		}
		for (int k = 0; k < S; k++) {
			int n, m;
			cin >> n >> m;
			ll p[50];
			int mini = 100, maxi = 0, n1 = 0, n2 = 0;
			for (int i = 0; i < n; i++) {
				string s;
				cin >> s;
				if (s.find("*")==string::npos) { if (!n1) continue; }
				else n2 = n1+1;
				p[n1] = 0;
				for (int j = 0; j < sz(s); j++) p[n1] = (p[n1]<<1)+(s[j]=='*'?maxi=max(maxi,j),mini=min(mini,j),1:0);
				n1++;
			}
			n = n2;
			for (int i = 0; i < n; i++) p[i] = (p[i]>>(m-maxi-1));
			m = maxi-mini+1;
			bool ok = 0;
			for (int i = 0; !ok && i <= N-n; i++) for (int j = 0; !ok && j <= M-m; j++) {
				ok = 1;
				for (int l = 0; ok && l < n; l++) {
					if ( (((B[i+l]>>(M-m-j)) & ((1LL<<m)-1))&p[l]) != p[l])
						ok = 0;
				}
			}
			cout << (ok?"Yes":"No") << endl;
		}
		cout << endl;
	}

    return 0;
}