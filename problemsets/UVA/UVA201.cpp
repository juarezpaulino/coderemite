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

int ADJ[10][10][10][10];
int N, M;

int main() {

    int T = 1;
    while (scanf("%d %d ", &N, &M) != EOF) {
        if (T != 1) puts("\n**********************************\n");

        memset(ADJ,0,sizeof(ADJ));

        for (int i = 0; i < M; i++) {
            char c;
            int a, b;
            scanf(" %c %d %d ", &c, &a, &b);
            if (c=='H') ADJ[a][b][a][b+1] = 1;
            else ADJ[b][a][b+1][a] = 1;
        }

        printf("Problem #%d\n\n", T++);
        bool found = false;
        for (int s = 1; s < N; s++) {
            int ret = 0;
            for (int r = 1; r <= N-s; r++) for (int c = 1; c <= N-s; c++) {
                bool ok = true;
                for (int i = 0; i < s; i++)
                    if (!ADJ[r][c+i][r][c+i+1]     ||
                        !ADJ[r+s][c+i][r+s][c+i+1] ||
                        !ADJ[r+i][c][r+i+1][c]     ||
                        !ADJ[r+i][c+s][r+i+1][c+s]  ) {
                        ok = false; break;
                    }
                if (ok) ret++;
            }
            if (ret) printf("%d square (s) of size %d\n", ret, s), found = 1;
        }
        if (!found) puts("No completed squares can be found.");
    }

    return 0;
}
