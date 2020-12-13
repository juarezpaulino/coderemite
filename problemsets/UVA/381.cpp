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
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<char> vc;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline double round10(double a) { return (int)(a*10.+.5)/10.; }

int main() {

    puts("MAKING THE GRADE OUTPUT");
    int TT; cin >> TT;
    while (TT--) {
        int B[50], A[50];
        double D[50];
        char G[50];
        int S, T; cin >> S >> T;
        for (int i = 0; i < S; i++) {
            int m = 1<<30, d = 0;
            for (int j = 0; j < T; j++) {
                int x; cin >> x;
                d += x;
                if (m > x) m = x;
            }
            cin >> B[i] >> A[i];
            if (T > 2) d -= m;
            D[i] = round10(d/(double)(T>2?T-1:T));
        }
        double M = 0.;
        for (int i = 0; i < S; i++) M += D[i];
        M = round10(M/S);
        double dev = 0.;
        for (int i = 0; i < S; i++) dev += sqr(D[i]-M);
        dev = round10(sqrt(dev / S));
        for (int i = 0; i < S; i++) D[i] = round10(D[i] * pow(1.03,B[i]/2));

        double ret = 0.;
        for (int i = 0; i < S; i++) {
      	    G[i] = cmp(D[i],M+dev) >= 0 ? 'A' :
        		   cmp(D[i],M) >= 0 ? 'B' :
        		   cmp(D[i],M-dev) >= 0 ? 'C' : 'D';
        	if (A[i] == 0) G[i] = (G[i]=='A')?'A': G[i]-1;
        	else G[i] = (G[i]+A[i]/4 > 'D')?'F':G[i]+A[i]/4;
        	ret += (G[i]=='A')?4:(G[i]=='B')?3:(G[i]=='C')?2:(G[i]=='D')?1:0;
        }
		ret = round10(ret/S);
		printf("%.1lf\n", ret);        
    }
    puts("END OF OUTPUT");

    return 0;
}