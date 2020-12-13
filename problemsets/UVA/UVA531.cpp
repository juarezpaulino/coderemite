/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

map<string, int> D;
string R[210];

int T1[110], T2[110];
int M, N;
int DP[110][110];

int main() {

    char S[100];
    while (1) {
        M = N = 1;
        D.clear();
        while (1) {
            if (scanf("%s", S) == EOF) return 0;
            if (*S=='#') break;
            int w;
            if (D.count(S)) w = D[S];
            else { w = D.size(); R[w] = S; D[S] = w; }
            T1[M++] = w;
        }
        while (1) {
            if (scanf("%s", S) == EOF) return 0;
            if (*S=='#') break;
            int w;
            if (D.count(S)) w = D[S];
            else { w = D.size(); R[w] = S; D[S] = w; }
            T2[N++] = w;
        }
        for (int i = 0; i < M; i++) DP[i][0] = 0;
        for (int i = 0; i < N; i++) DP[0][i] = 0;
        for (int i = 1; i < M; i++) for (int j = 1; j < N; j++) {
            int d = max(DP[i-1][j], DP[i][j-1]);
            if (T1[i]==T2[j]) d = max(d, DP[i-1][j-1]+1);
            DP[i][j] = d;
        }
        vector<string> RET;
        int i = M-1, j = N-1;
        while (DP[i][j]) {
            if (DP[i][j]==DP[i-1][j]) i--;
            else if (DP[i][j]==DP[i][j-1]) j--;
            else if (DP[i][j]==DP[i-1][j-1]+1) { RET.push_back(R[T1[i]]); i--; j--; }
        }
        reverse(RET.begin(), RET.end());
        bool f = false;
        for (int i = 0; i < RET.size(); i++) {
            if (f) putchar(' ');
            f = true;
            printf("%s", RET[i].c_str());
        }
        putchar('\n');
    }

    return 0;
}
