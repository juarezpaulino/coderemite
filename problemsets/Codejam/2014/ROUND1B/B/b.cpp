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

ll dp[32][2][2][2];

ll go(int i, int lessA, int lessB, int lessK, int A, int B, int K) {
	if (i < 0) return lessA && lessB && lessK;
	ll &ret = dp[i][lessA][lessB][lessK];
	if (ret != -1) return ret;
	ret = 0;
	int maxA = max(lessA,(A>>i)&1);
	int maxB = max(lessB,(B>>i)&1);
	int maxK = max(lessK,(K>>i)&1);
	ret += go(i-1, maxA, maxB, maxK, A, B, K);
	if (maxA) ret += go(i-1, lessA, maxB, maxK, A, B, K);
	if (maxB) ret += go(i-1, maxA, lessB, maxK, A, B, K);
	if (maxA && maxB && maxK) ret += go(i-1, lessA, lessB, lessK, A, B, K);
	return ret;
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);
	
	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		cout << "Case #" << tt << ": ";
		int A, B, K;
		cin >> A >> B >> K;
		memset(dp,-1,sizeof(dp));
		ll ret = go(30,0,0,0,A,B,K);
		cout << ret << endl;
	}

    return 0;
}