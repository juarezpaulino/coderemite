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
#include <numeric>

using namespace std;

char S[100];
char A[30], B[30];
int DP[30][30];

int main() {

    while (gets(S)) {
        int M = 0, N = 0;

        int k = 0;
        while (S[k] && S[k] != ' ') A[++M] = S[k++];
        if (S[k]==' ') k++;
        while (S[k] && S[k] != ' ') B[++N] = S[k++];
        if (A[1]=='#') break;

        DP[0][0] = 0;
        for (int i = 1; i <= M; i++) DP[i][0] = i;
        for (int j = 1; j <= N; j++) DP[0][j] = j;
        for (int i = 1; i <= M; i++) for (int j = 1; j <= N; j++) {
            DP[i][j] = min(DP[i][j-1], DP[i-1][j]) + 1;
            DP[i][j] = min(DP[i][j], DP[i-1][j-1] + (A[i]!=B[j]) );
        }

        string ret;
        int i = M, j = N;
        while (i > 0 || j > 0) {
            // Deleting.
            if (i && DP[i][j]==DP[i-1][j]+1) sprintf(S, "D%c%02d", A[i], j+1), i--;
            // Inserting.
            else if (j && DP[i][j]==DP[i][j-1]+1) sprintf(S, "I%c%02d", B[j], j), j--;
            // Changing.
            else if (i && j && DP[i][j]==DP[i-1][j-1]+1) sprintf(S, "C%c%02d", B[j], j), i--, j--;
            // Equal.
            else *S = 0, i--, j--;
            ret = S + ret;
        }

        ret += "E";
        printf("%s\n", ret.c_str());
    }

    return 0;
}
