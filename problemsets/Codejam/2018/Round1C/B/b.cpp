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

int S, D[101010], A[101010], B[101010];

int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		cout << "Case #" << tt << ": ";

		cin >> S;
		for (int i = 0; i < S; i++) cin >> D[i] >> A[i] >> B[i];
	
	    set<pii> RET;

	    int maxS = 0;
	    int a = 0, b = 0, M = D[0]+A[0], N = D[0]-B[0];
	    while (a < S) {
	    	b = a;
	    	while (b < S && (D[b]+A[b]==M || D[b]-B[b]==N)) {
	    		b++;
	    		if (b-a > maxS) {
	    			maxS = b-a;
	    			RET.clear(); 
	    			RET.insert(mp(a,b));
	    		}
	    		else if (b-a == maxS) {
	    			RET.insert(mp(a,b));
	    		}
	    	}
	    	a++;
	    	M = D[a]+A[a]; N = D[a]-B[a];
	    }

	    a = 0, b = 0, M = D[0]+A[0], N = D[0]-B[0];
	    while (a < S) {
	    	b = a;
	    	while (b < S && D[b]+A[b]==M) {
	    		b++;
	    		if (b-a > maxS) { 
	    			maxS = b-a;
	    			RET.clear(); 
	    			RET.insert(mp(a,b));
	    		}
	    		else if (b-a == maxS) RET.insert(mp(a,b));
	    	}
	    	if (b < S) {
	    		N = D[b]-B[b];
	    		while (b < S && (D[b]+A[b]==M || D[b]-B[b]==N)) {
	    			b++;
	    			if (b-a > maxS) { 
	    				maxS = b-a; 
	    				RET.clear(); 
	    				RET.insert(mp(a,b));
	    			}
	    			else if (b-a == maxS) RET.insert(mp(a,b));
	    		}
	    	}
	    	a++;
	    	M = D[a]+A[a]; N = D[a]-B[a];
	    }

	   	a = 0, b = 0, M = D[0]+A[0], N = D[0]-B[0];
	    while (a < S) {
	    	b = a;
	    	while (b < S && D[b]-B[b]==N) {
	    		b++;
	    		if (b-a > maxS) { 
	    			maxS = b-a;
	    			RET.clear(); 
	    			RET.insert(mp(a,b));
	    		}
	    		else if (b-a == maxS) RET.insert(mp(a,b));
	    	}
	    	if (b < S) {
	    		M = D[b]+A[b];
	    		while (b < S && (D[b]+A[b]==M || D[b]-B[b]==N)) {
	    			b++;
	    			if (b-a > maxS) {
	    				maxS = b-a;
	    				RET.clear(); 
	    				RET.insert(mp(a,b));
	    			}
	    			else if (b-a == maxS) RET.insert(mp(a,b));
	    		}
	    	}
	    	a++;
	    	M = D[a]+A[a]; N = D[a]-B[a];
	    }

	    cout << maxS << " " << sz(RET) << endl;
	}

    return 0;
}