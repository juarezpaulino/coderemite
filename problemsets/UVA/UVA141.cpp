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

int N;

typedef vector<string> VS;

VS cw_rotate(VS &S) {
    int h = S.size(), w = S[0].size();
    VS T(w, string(h,0));
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
        T[j][i] = S[h-i-1][j];
    return T;
}

void PRINT(VS &S) {
    int h = S.size();
    for (int i = 0; i < h; i++) printf("%s\n", S[i].c_str());
    putchar('\n');
}


int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        VS MAT(N,string(N,'0'));
        set<VS> VIS;
        VIS.insert(MAT);
        int p = 0, c = 0;
        for (int i = 0; i < 2*N; i++) {
            int x, y;
            char t;
            scanf("%d %d %c ", &x, &y, &t);
            x--; y--;
            if (p > 0) continue;

            MAT[y][x] = (t == '+') ? '1' : '0';
            VS rot = MAT;
            if (VIS.count(rot)) p = 2-(i%2);
            for (int j = 0; j < 3; j++) {
                rot = cw_rotate(rot);
                if (VIS.count(rot)) p = 2-(i%2);
            }
            c++;
            VIS.insert(MAT);
        }
        if (p > 0) printf("Player %d wins on move %d\n", p, c);
        else puts("Draw");
    }

    return 0;
}
