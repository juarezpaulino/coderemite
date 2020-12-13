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

struct team {
	string name;
	int points, games, score, against, diff;
	team() { name = ""; points = games = score = against = diff = 0; }
	bool operator<(const team &a) {
		if(points != a.points) return points > a.points;
        if(diff != a.diff) return diff > a.diff;
        if(score != a.score) return score > a.score;
        string a1 = name; transform(all(name), a1.begin(), ::tolower);
        string a2 = a.name; transform(all(a.name), a2.begin(), ::tolower);
        return a1 < a2;
	}
	bool operator==(const team &B) {
		return points == B.points && diff == B.diff && score == B.score;
	}
};

int get_points(int a, int b) { return (a>b)?3:(a<b)?0:1; }

int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	char a[101], b[101];
	int T, G;
	bool f = 1;
	while (scanf("%d %d", &T, &G)!=EOF && T+G) {
		map<string, int> M;
		if (!f) putchar('\n');
		f = 0;
		vector<team> A(T, team());
		for (int t = 0; t < T; t++) { scanf("%s", a); A[t].name = a; M[a] = t; }
		for (int g = 0; g < G; g++) {
			int ga, gb;
			scanf("%s %d - %d %s", a, &ga, &gb, b);
			A[M[a]].points+=get_points(ga,gb); A[M[a]].games++; A[M[a]].score+=ga; A[M[a]].against += gb; A[M[a]].diff+=(ga-gb);
			A[M[b]].points+=get_points(gb,ga); A[M[b]].games++; A[M[b]].score+=gb; A[M[b]].against += ga; A[M[b]].diff+=(gb-ga);
		}
		sort(all(A));
		for (int i = 0; i < sz(A); i++) {
			if (A[i].games) sprintf(a, "%7.2lf", (A[i].points*100.) / (A[i].games * 3));
			else sprintf(a, "    N/A");			
			if (!i || A[i-1].points != A[i].points || A[i-1].diff != A[i].diff || A[i-1].score != A[i].score)
				printf("%2d.%16s%4d%4d%4d%4d%4d%s\n", i+1, A[i].name.c_str(), A[i].points, A[i].games, A[i].score, A[i].against, A[i].diff, a);
			else printf("   %16s%4d%4d%4d%4d%4d%s\n", A[i].name.c_str(), A[i].points, A[i].games, A[i].score, A[i].against, A[i].diff, a);
		}
	}
		        	
	return 0;
}