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
#define on(x) (__builtin_popcount(x))
#define ctz(x) (__builtin_ctz(x))
#define clz(x) (__builtin_clz(x))
#define szb(x) (sizeof(int)*8 - clz(x))

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<double> vd;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int A[10101];

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int N, x;
	while (scanf("%d:", &N) && N) {
		for (int i = 0; i < N; i++) scanf("%d", &x), A[x] = i;
		x = 1;
		for (int i = 0; x && i < N; i++)
			for (int z=1, j=i+z, k=j+z; x && k < N; ++z, j=i+z, k=j+z) {
				if ((A[i]<A[j] && A[j]<A[k]) ||
						(A[i]>A[j] && A[j]>A[k])) x = 0;
			}
		if (x) puts("yes");
		else puts("no");
	}

	return 0;
}