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


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	int TT;
    cin >> TT;
    while (TT--) {
    	int N, K;
    	cin >> N >> K;
    	set<int> C;
    	for (int i = 1; i <= N; i++) C.insert(i);
    	set<int> L, G;
    	for (int i = 0; i < K; i++) {
			vi I;
			int x, k; cin >> k;
			for (int i = 0; i < 2*k; i++) cin >> x, I.pb(x);
			char v; cin >> v;
			if (v == '=') for (int i = 0; i < 2*k; i++) C.erase(I[i]);
			else if (v=='<') {
				set<int> S(I.begin(),I.end());
				for (int i = 1; i <= N; i++) if (S.count(i)==0) C.erase(i);
				for (int i = 0; i < k; i++) L.insert(I[i]);
				for (int i = k; i < 2*k; i++) G.insert(I[i]);
			}
			else if (v=='>') {
				set<int> S(I.begin(),I.end());
				for (int i = 1; i <= N; i++) if (S.count(i)==0) C.erase(i);
				for (int i = 0; i < k; i++) G.insert(I[i]);
				for (int i = k; i < 2*k; i++) L.insert(I[i]);
			}
    	}
		for (int i = 1; i <= N; i++) if (L.count(i) && G.count(i)) C.erase(i);
		if (sz(C)==1) cout << *C.begin() << endl;
		else cout << "0" << endl;
    	if (TT) cout << endl;
    }

    return 0;
}