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


int main() {

	int TT;
	cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		int A, B, d;
		char S[20];
		string m;
		scanf("%s%d,%d", S, &d, &A); m = S; 
		if (m == "January" || (m == "February" && d <= 29)) A--;
		scanf("%s%d,%d", S, &d, &B); m = S; 
		if (m == "January" || (m == "February" && d < 29)) B--;
		A = A/4-A/100+A/400;
		B = B/4-B/100+B/400;
		printf("Case %d: %d\n", tt, B-A);
	}

	return 0;
}