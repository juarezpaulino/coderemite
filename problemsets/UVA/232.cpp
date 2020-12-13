/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N[101][101];
char M[101][101];
int r, c;

int main() {

    int T = 1, id, f = 1;
    while (scanf("%d %d", &r, &c) == 2) {
        for (int i = 0; i < r; i++) { scanf("%s", M[i]); M[i][c] = '*'; }
        for (int j = 0; j <= c; j++) M[r][j] = '*';
        int id = 1;
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
            if (M[i][j]!='*' && (i == 0 || j == 0 || M[i-1][j]=='*' || M[i][j-1]=='*')) N[i][j] = id++;

        if (!f) putchar('\n');
        f = 0;
        printf("puzzle #%d:\n", T++);
        printf("Across\n");
        for (int i = 0; i < r; i++) {
            char w[101]; int k = 0, n;
            for (int j = 0; j <= c; j++) {
                if (M[i][j]=='*') {
                    if (k != 0) { w[k] = 0; printf("%3d.%s\n", n, w); }
                    k = 0;
                    continue;
                }
                if (k == 0) n = N[i][j];
                w[k++] = M[i][j];
            }
        }
        printf("Down\n");
        vector<string> D; char s[101];
        for (int j = 0; j < c; j++) {
            char w[101]; int k = 0, n;
            for (int i = 0; i <= r; i++) {
                if (M[i][j]=='*') {
                    if (k != 0) { w[k] = 0; sprintf(s, "%3d.%s", n, w); D.push_back(s); }
                    k = 0;
                    continue;
                }
                if (k == 0) n = N[i][j];
                w[k++] = M[i][j];
            }
        }
        sort(D.begin(), D.end());
        for (int i = 0; i < D.size(); i++) puts(D[i].c_str());
    }

    return 0;
}
