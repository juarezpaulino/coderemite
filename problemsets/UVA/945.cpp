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
typedef vector<vi> vvi;
typedef tuple<int,int,int> tiii;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int M, N;
int C[1010], P[1010];


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	int tt = 1;
	while (cin >> M) {
		if (tt!=1) cout << endl;
		tt++;
		
		int X = 0, Y = 0, Z = 0;
		
		for (int i = 0; i < M; i++) cin >> C[i], X+=C[i];
		
		cin >> N;
		for (int i = 0; i < N; i++) cin >> P[i], Y+=P[i];
		
		priority_queue<tiii,vector<tiii>,greater<tiii> > q;
		for (int i = 0; i < M; i++) q.push(mt(0,-C[i],i));
		
		vvi ret(M, vi());
		int maxP = 0;
		for (int k = 0; k < N; k++) {
			int x = P[k];
			if (q.empty()) break;
			int p = get<0>(q.top());
			int c = -get<1>(q.top());
			int u = get<2>(q.top());
			q.pop();
			if (x > c) break;
			ret[u].pb(x);
			maxP = max(maxP, p+1);
			q.push(mt(p+1,-c+x,u));
		}
		for (int i = 0; i < M; i++) for (int j = sz(ret[i]); j <= maxP; j++) ret[i].pb(-1);
		
		for (int i = maxP-1; i >= 0; i--) {
			bool first = 1;
			for (int j = 0; j < M; j++) {
				if (!first) cout << " ";
				first = 0;
				if (ret[j][i]==-1) cout << ":";
				else cout << ret[j][i], Z+=ret[j][i];
			}
			cout << endl;
		}
		cout << string(M+M-1,'=') << endl;
		bool first = 1;
		for (int i = 1; i <= M; i++) {
			if (!first) cout << " ";
			first = 0;
			cout << i;
		}
		cout << endl << endl;
		cout << "cargo weight: " << Z << endl;
		cout << "unused weight: " << X-Z << endl;
		cout << "unloaded weight: " << Y-Z << endl;
	}

    return 0;
}