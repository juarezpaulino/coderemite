/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int R, C, H, V;
int S[110][110];


int main() {

    int TT;
    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        printf("Case #%d: ", tt);

        cin >> R >> C >> H >> V;
        H++; V++;
        for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) {
        	char c;
        	cin >> c;
        	S[i][j] = S[i-1][j]+S[i][j-1]-S[i-1][j-1] + (c=='@'?1:0);
        }
        int K = S[R][C], k = K / (H * V);
        vector<pii> h, v;
        if (K == 0) { puts("POSSIBLE"); continue; }
        if (K % (H * V)) { puts("IMPOSSIBLE"); continue; }
		
        bool ok = 1;
		int i = 1, j = 1;

		int L = V*k;
		while (ok && h.size() != H) {
			int s = 0, u = i;
			while (i <= R && s < L) s += S[i][C]-S[i-1][C], i++;
			if (s > L) ok = 0;
			else h.push_back(make_pair(u, i-1));
		}
		
		L = H*k;
		while (ok && v.size() != V) {
			int s = 0, u = j;
			while (j <= C && s < L) s += S[R][j]-S[R][j-1], j++;
			if (s > L) ok = 0;
			else v.push_back(make_pair(u, j-1));
		}

		for (i = 0; ok && i < h.size(); i++) for (j = 0; ok && j < v.size(); j++) {
			int a, b, c, d;
			a = h[i].first, b = h[i].second;
			c = v[j].first, d = v[j].second;
			if (S[b][d] - S[b][c-1] - S[a-1][d] + S[a-1][c-1] != k) ok = 0;
		}

		if (!ok) puts("IMPOSSIBLE");
		else puts("POSSIBLE");
    }
    return 0;
}
        