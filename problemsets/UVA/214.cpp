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

char S[1010101];

bool isop(char c) { return c=='+'||c=='-'||c=='*'||c=='/'||c=='@'; }
char toass(char c) { return c=='+'?'A':c=='-'?'S':c=='*'?'M':c=='/'?'D':-1; }

int main() {

	bool first = 1;
	while (gets(S)) {
		if (!first) putchar('\n');
		first = 0;

		int r = 0;
		bool M = 0;
		int pc = 0, pr = 0;
		while (S[pc]) {
			while (S[pr] && isop(S[pr])) pr++;
			while (S[pc] && !isop(S[pc])) pc++;

			if (M && (pc-pr > 1 || S[pc]=='@')) printf("ST $%d\n", r), r++;
			
			while (pc-pr > 2 || (pc-pr == 2 && S[pc]=='@'))
				printf("L %c\nST $%d\n", S[pr], r), pr++, r++;
			
			if (S[pc]=='@') printf("L %c\nN\n", S[pr]), pc++, pr++, M = 1;
			else if (pc-pr==2) printf("L %c\n%c %c\n", S[pr], toass(S[pc]), S[pr+1]), pc++, pr+=2, M = 1;
			else if (pc-pr==1 && M) printf("%c %c\n", toass(S[pc]), S[pr]), pc++, pr++;
				
			while (isop(S[pc])) {
				if (S[pc]=='@') puts("N"), pc++;
				else if (S[pc]=='+'||S[pc]=='*') printf("%c $%d\n", toass(S[pc]), r-1), pc++, r--;
				else if (S[pc]=='-') printf("N\nA $%d\n", r-1), pc++, r--;
				else printf("ST $%d\nL $%d\nD $%d\n", r, r-1, r), pc++, r--;
			}
		}
		while (S[pr] && !isop(S[pr])) printf("L %c\n", S[pr]), pr++;
	}

	return 0;
}