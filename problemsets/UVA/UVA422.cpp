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

int N;
char P[110][110];
char W[110];

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%s", P[i]);
    while (scanf("%s", W)) {
        bool found = false;
        if (!W[1] && *W=='0') break;
        int M = strlen(W);
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int d = 0; d < 8; d++) {
            int y = i, x = j;
            bool ok = true;
            int k = 0;
            while (1) {
                if (y < 0 || y >= N || x < 0 || x >= N) { ok = false; break; }
                if (W[k] != P[y][x]) { ok = false; break; }
                k++;
                if (k == M) break;
                y = y+dy[d];
                x = x+dx[d];
            }
            if (ok) { printf("%d,%d %d,%d\n", i+1, j+1, y+1, x+1); found = true; goto OUT; }
        }
OUT:
        if (!found) puts("Not found");
    }

    return 0;
}
