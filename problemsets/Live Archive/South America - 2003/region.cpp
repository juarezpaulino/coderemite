/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct point { int x, y; point(int x=0, int y=0) : x(x), y(y) {}};


int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch == '-') ? 1, ch = getchar() : 0;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar()) i = (i<<3)+(i<<1)+(ch - '0');
    if (s) return -i; return i;
}

int x1, y1, x2, y2, n;
point mine[310];

int cmpx(const void *a, const void *b) {
    point *x = (point *)a, *y = (point *)b;
    if (x->x!=y->x) return x->x-y->x;
    return x->y-y->y;
}

int cmpy(const void *a, const void *b) {
    point *x = (point *)a, *y = (point *)b;
    if (x->y!=y->y) return x->y-y->y;
    return x->x-y->x;
}



int main() {
   
    int i, j, k, l;
    int x, y;
    int yu, yd, xu, xd, m, m1, m2, a, b;
    while (1) {
        x1=get_int();y1=get_int();x2=get_int();y2=get_int();
        if (!x1&&!x2&&!y1&&!y2) break;
        n = get_int();
        mine[0] = point(x1, y1); mine[1] = point(x2, y2);
        mine[2] = point(x1, y2); mine[3] = point(x2, y1);
        for (k = 4, i = 0; i < n; i++) {
            x = get_int(), y = get_int();
            for (j = 0; j < 4; j++) if (x==mine[j].x&&y==mine[j].y) break;
            if (j==4) { mine[k].x = x; mine[k++].y = y; }
        }
        n = k; qsort(mine, n, sizeof(point), cmpx); m1 = m2 = 0;
        for (i = 0; i < n; i++) {
            k = 1; yu = y2; yd = y1;
            for (j = i+1; j < n; j++) {
                x = mine[j].x-mine[i].x;
                if (!x) continue;
                if (k) {
                    y = yu-yd; if (x < y) a = x, b = y; else a = y, b = x;
                    if (a>m1 || (a==m1 && b>m2)) m1 = a, m2 = b;
                }
                else {
                    if (mine[j].y>=mine[i].y) {
                        y = yu-mine[i].y; if (x < y) a = x, b = y; else a = y, b = x;
                        if (a>m1 || (a==m1 && b>m2)) m1 = a, m2 = b;
                    }
                    if (mine[j].y<=mine[i].y) {
                        y = mine[i].y-yd; if (x < y) a = x, b = y; else a = y, b = x;
                        if (a>m1 || (a==m1 && b>m2)) m1 = a, m2 = b;
                    }
                }
                if (k && mine[i].y==mine[j].y) { k = 0; break; }
                if (mine[j].y>mine[i].y) yu<?=mine[j].y;
                if (mine[j].y<mine[i].y) yd>?=mine[j].y;
            }
        }
        qsort(mine, n, sizeof(point), cmpy); m1 = m2 = 0;
        for (i = 0; i < n; i++) {
            k = 1; xu = x2; xd = x1;
            for (j = i+1; j < n; j++) {
                y = mine[j].y-mine[i].y;
                if (!y) continue;
                if (k) {
                    x = xu-xd; if (x < y) a = x, b = y; else a = y, b = x;
                    if (a>m1 || (a==m1 && b>m2)) m1 = a, m2 = b;
                }
                else {
                    if (mine[j].x>=mine[i].x) {
                        x = xu-mine[i].x; if (x < y) a = x, b = y; else a = y, b = x;
                        if (a>m1 || (a==m1 && b>m2)) m1 = a, m2 = b;
                    }
                    if (mine[j].x<=mine[i].x) {
                        x = mine[i].x-xd; if (x < y) a = x, b = y; else a = y, b = x;
                        if (a>m1 || (a==m1 && b>m2)) m1 = a, m2 = b;
                    }
                }
                if (k && mine[i].x==mine[j].x) { k = 0; break; }
                if (mine[j].x>mine[i].x) xu<?=mine[j].x;
                if (mine[j].x<mine[i].x) xd>?=mine[j].x;
            }
        }
        printf("%d %d\n", m1, m2);
    }
   
    return 0;
}

