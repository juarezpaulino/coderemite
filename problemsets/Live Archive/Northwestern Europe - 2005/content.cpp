/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct ingr {
    char name[35]; int lo, hi, mhi, mlo;
    ingr() : lo(1), hi(100), mhi(0), mlo(100) {}
};

ingr prod[10][100];
char prodname[10][35];
int p, n[10], q;
int possible[101][101][101];
int id = 0;

int check(int np, int v, int mx, int sum) {
    int i, &ret = possible[v][mx][sum];
    if (sum<0) return 0;
    if (sum==0 && v==n[np]) return 1;
    if ((ret>>16) != (v?id:++id))
        for (ret = id<<16, i = prod[np][v].lo; i <= min(prod[np][v].hi, mx); i++)
            if (check(np, v+1, i, sum-i)) ret|=1, prod[np][v].mhi>?=i, prod[np][v].mlo<?=i;
    return ret&1;
}


int main() {
    
    char str[100], op[10];
    int i, j, k, x, y, f;
    int minhi, maxlo;
    
    while (scanf("%d", &p), p) {
        for (i = 0; i < p; i++) {
            scanf("%s %d ", prodname[i], &n[i]);
            for (j = 0; j < n[i]; j++) {
                prod[i][j] = ingr();
                gets(str); if (sscanf(str, "%s %d", prod[i][j].name, &x) == 2)
                    prod[i][j].lo = prod[i][j].hi = x;
            }
            check(i, 0, 100, 100);
        }
        scanf("%d", &q);
        for (k = 0; maxlo = 0, minhi = 100, k < q; k++) {
            scanf("%s %s", op, str);
            for (i = 0; x = y = 0, i < p; minhi<?=x, maxlo>?=y, i++) for (j = 0; j < n[i]; j++)
                if (!strcmp(prod[i][j].name, str)) {
                    x=prod[i][j].mhi, y=prod[i][j].mlo; break;
                }
            for (i = f = 0; x = y = 0, i < p; i++) {
                for (j = 0; j < n[i]; j++)
                    if (!strcmp(prod[i][j].name, str)) { x = prod[i][j].mhi, y = prod[i][j].mlo; break; }
                if (!strcmp(op, "most")) {
                    if (x >= maxlo) { if (f) putchar(' '); printf("%s", prodname[i]); f = 1; }
                }
                else {
                    if (y <= minhi) { if (f) putchar(' '); printf("%s", prodname[i]); f = 1; }
                }
            }
            putchar('\n');
        }
    }
    
    return 0;
}
