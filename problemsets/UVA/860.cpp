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
inline int szb(int a) { int ret = 1; while(a>>=1) ret++; return ret; }

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

char tok[] = " ,.:;!?\"()\n\t";

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	while (1) {
		char S[101];
		map<string,int> M;
		int t = 0;
		while (gets(S)) {
			if (string(S) == "****END_OF_TEXT****") break;
			if (string(S) == "****END_OF_INPUT****") return 0;
			transform(S, S+strlen(S), S, ::tolower);
			char *p = strtok(S, tok);
			while (p != NULL) M[string(p)]++, t++, p = strtok(NULL, tok);
		}
		double Emax = log10(t);
		double Et = 0.;
		for (auto w: M) Et += w.second * (Emax - log10(w.second));
		Et /= t;
		printf("%d %.1lf %.0lf\n", t, Et+EPS, Et*100./Emax+EPS);
	}

	return 0;
}