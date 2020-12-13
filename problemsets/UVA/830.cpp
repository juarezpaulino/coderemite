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
typedef vector<pii> vpii;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int M, N;
string A[101];
bool V[101][101];
int U,D,L,R;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void dfs(int y, int x, char c) {
	V[y][x] = 1;
	if (y < U) U = y;
	if (y > D) D = y;
	if (x < L) L = x;
	if (x > R) R = x;
	for (int i = 0; i < 4; i++) {
		int ny = y+dy[i], nx = x+dx[i];
		if (ny<0||nx<0||ny>=M||nx>=N) continue;
		if (V[ny][nx]) continue;
		if (A[ny][nx]!=c) continue;
		dfs(ny,nx,c);
	}
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		if (tt!=1) cout << endl;
		cin >> M >> N;
		for (int i = 0; i < M; i++) cin >> A[i];
		memset(V,0,sizeof(V));
		int ret[10] = {0};
		for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if (!V[i][j] && A[i][j]!='.') {
			U = D = i; L = R = j;
			dfs(i,j,A[i][j]);
			bool s = 0;
			for (int k = U; !s && k <= D; k++) for (int l = L; !s && l <= R; l++) if (A[k][l] != A[i][j]) s = 1;
			int w = R-L+1, h = D-U+1;
			if (s) ret[7]++;
			else if (w==1&&h==1) ret[0]++;
			else if (w==1&&h==2) ret[1]++;
			else if (h==1&&w==2) ret[1]++;
			else if (h==1||w==1) ret[2]++;
			else if (w==2&&h>2) ret[3]++;
			else if (h==2&&w>2) ret[3]++;
			else if (h==w) ret[4]++;
			else if (h==3&&w>3) ret[5]++;
			else if (w==3&&h>3) ret[5]++;
			else if (w==4&&h>4) ret[6]++;
			else if (h==4&&w>4) ret[6]++;
		}
		for (int i = 0; i < 8; i++) cout << (i?" ":"\0") << ret[i];
		cout << endl;

	}

    return 0;
}