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
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef pair<int, int> pii;
typedef long long ll;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

typedef pair<double,double> pdd;

int W[110], H[110];
double U[110], V[110];

int main() {

    int TT;

    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        printf("Case #%d: ", tt);

    	int N, P;
    	scanf("%d %d", &N, &P);         
    	double Q = P/2.;
		for (int i = 0; i < N; i++) {
			scanf("%d %d", W+i, H+i);
			U[i] = min(W[i], H[i]);
			V[i] = sqrt(sqr(W[i])+sqr(H[i]));
			Q -= W[i]+H[i];
		}
		assert(cmp(Q)>=0);
		vector<pdd> A, B;
		A.pb(mp(0.,0.));
		for (int i = 0; i < N; i++) {
			B.clear();
			
			for (int j = 0; j < sz(A); j++) {
				B.pb(A[j]);
				double l = A[j].fi+U[i];
				double r = A[j].se+V[i];
				if (cmp(l,Q)<=0)	
					B.pb(mp( l, min(Q,r) ));
			}

			sort(all(B));
			
			A.clear();
			for (int j = 0; j < sz(B); j++) {
				double u = B[j].fi, v = B[j].se;
				while (j+1 < sz(B) && cmp(u, B[j+1].fi) <= 0 && cmp(B[j+1].fi, v) <= 0)
					v = max(v, B[j+1].se), j++;
				A.pb(mp(u,v));
			}
		}
		printf("%.6lf\n", 2.*(P/2.-Q+A.back().se));
    }
    return 0;
}
