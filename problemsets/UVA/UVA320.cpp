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

char D[] = "NWSE";
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};
int py[] = {0,0,-1,-1};
int px[] = {0,-1,-1,0};

char MAPA[33][33];

int main() {

    int T;
    char S[1000];
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int x, y;
        scanf("%d %d ", &x, &y);
        scanf("%s", S);
        for (int i = 0; i < 32; i++) for (int j = 0; j < 32; j++) MAPA[i][j] = '.';
        for (int i = 0; S[i] && S[i]!='.'; i++) {
            int d;
            for (d = 0; S[i] != D[d]; d++);
            MAPA[y + py[d]][x + px[d]] = 'X';
            y = y+dy[d];
            x = x+dx[d];
        }
        printf("Bitmap #%d\n", t);
        for (int i = 31; i >= 0; i--) puts(MAPA[i]);
        putchar('\n');
    }

    return 0;
}
