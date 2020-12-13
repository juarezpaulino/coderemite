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
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> ent;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	int tt = 1;
	int M;
	map<string,vector<ent> > R;
	while (cin >> M) {
		for (int k = 0; k < M; k++) {
			string u;
			int N;
			cin >> u >> N;
			while (N--) {
				ent v; string a;
				for (int j = 0; j < 5; j++) cin >> a, v.pb(a);
				R[u].pb(v);
			}
		}
		printf("Scenario # %d\n", tt++);
		int N;
		cin >> N;
		for (int qq = 1; qq <= N; qq++) {
			ent u; string a;
			for (int j = 0; j < 5; j++) cin >> a, u.pb(a);
			set<string> V;
			while (1) {
				if (V.count(u[0])) {
					printf("%d -- circular routing detected by %s\n", qq, u[0].c_str());
					break;
				}
				V.insert(u[0]);
				string v = ""; bool r = 0;
				for (auto A: R[u[0]]) {
					r = 1;
					for (int j  = 1; r && j < 5; j++) {
						if (u[j]=="*" || A[j]=="*") continue;
						if (u[j] != A[j]) r = 0;	
					} 
					if (r) { v = A[0]; break; }
				}
				if (r) {
					if (u[0] == v) {
						printf("%d -- delivered to %s\n", qq, u[0].c_str());
						break;
					}
					u[0] = v;
				}
				else {
					printf("%d -- unable to route at %s\n", qq, u[0].c_str());
					break;
				}
			}
		}
		cout << endl;
	}

    return 0;
}