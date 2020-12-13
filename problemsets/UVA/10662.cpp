/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>


using namespace std;

int t[25], r[25], h[25];
int A1[25][25], A2[25][25], A3[25][25];


int main() {

    int T, R, H;
    while (scanf("%d %d %d", &T, &R, &H) != EOF) {
        for (int i = 0; i < T; i++) {
            scanf("%d", t+i);
            for (int j = 0; j < R; j++) {
                int x;
                scanf("%d", &x);
                A1[i][j] = ((x==0)?1:0);
            }
        }
        for (int i = 0; i < R; i++) {
            scanf("%d", r+i);
            for (int j = 0; j < H; j++) {
                int x;
                scanf("%d", &x);
                A2[i][j] = ((x==0)?1:0);
            }
        }
        for (int i = 0; i < H; i++) {
            scanf("%d", h+i);
            for (int j = 0; j < T; j++) {
                int x;
                scanf("%d", &x);
                A3[i][j] = ((x==0)?1:0);
            }
        }
        int rt, rr, rh, ret = 1<<30;
        for (int k = 0; k < T; k++) for (int i = 0; i < R; i++) for (int j = 0; j < H; j++) if (A1[k][i] && A2[i][j] && A3[j][k]) {
            int x = t[k]+r[i]+h[j];
            if (x < ret) {
                rt = k;
                rr = i;
                rh = j;
                ret = x;
            }
        }
        if (ret == 1<<30) puts("Don't get married!");
        else printf("%d %d %d:%d\n", rt, rr, rh, ret);
    }

    return 0;
}
