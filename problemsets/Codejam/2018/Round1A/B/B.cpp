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
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sqr(x) ((x)*(x))

typedef pair<int, int> pii;
typedef long long ll;


int R, B, C;
int Mi[1010], Si[1010], Pi[1010];

bool check(ll m) {
	vector<ll> M;
	for (int i = 0; i < C; i++) if (m > Pi[i])
		M.pb( min( (ll)Mi[i], (m-Pi[i])/Si[i] ) );
	sort(all(M), greater<ll>());
	ll ret = 0;
	for (int i = 0; ret < B && i < R; i++) ret += M[i];
	return ret >= B;
}

int main() {

    int TT;
    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        printf("Case #%d: ", tt);

        cin >> R >> B >> C;
        for (int i = 0; i < C; i++)
        	cin >> Mi[i] >> Si[i] >> Pi[i];
        
        ll lo, hi = 1, m;
        while (!check(hi)) hi<<=1;
        lo = hi>>1;
        while (hi > lo+1) {
    		m = (hi+lo)/2;
    		if (check(m)) hi = m;
    		else lo = m;
    	}
    	cout << hi << endl;
    }
    return 0;
}