/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int P[1010101];
int mapa[100];
int id = 1;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        for (int i = 0; i < A; i++) P[i] = 1;
        for (int i = 0; i < B; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            mapa[x] = (id<<8) | y;
        }
        bool fini = false;
        int p = A-1;
        for (int i = 0; i < C; i++) {
            int x;
            p = (p+1)%A;
            scanf("%d", &x);
            if (fini) continue;
            x = P[p] += x;
            if ((mapa[x] >> 8) == id) P[p] = mapa[x] & ((1<<8)-1);
            if (P[p] >= 100) {
                P[p] = 100;
                fini = true;
            }
        }
        for (int i = 0; i < A; i++)
            printf("Position of player %d is %d.\n", i+1, P[i]);
        id++;
    }

    return 0;
}
