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

int W, H, N;
int B[505][505];

int main() {

    int id = 1;
    while (scanf("%d %d %d", &W, &H, &N)) {
        if (!(H|W|N)) break;
        for (int i = 0; i < N; i++) {
            int x1, x2, y1, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if (x1 > x2) swap(x1,x2);
            if (y1 > y2) swap(y1,y2);
            for (int i = x1; i <= x2; i++) for (int j = y1; j <= y2; j++) B[i][j] = id;
        }
        int ret = 0;
        for (int i = 1; i <= W; i++) for (int j = 1; j <= H; j++) if (B[i][j]!=id) ret++;
        if (ret == 0) puts("There is no empty spots.");
        else if (ret == 1) puts("There is one empty spot.");
        else printf("There are %d empty spots.\n", ret);
        id++;
    }

    return 0;
}
