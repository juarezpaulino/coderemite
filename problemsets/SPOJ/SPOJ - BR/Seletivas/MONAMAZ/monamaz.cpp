/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

#define INF 0x3F3F3F3F

struct point { 
    int x, y;
    int ord; 
};

#define sqrd(a, b) (((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))

int n, nc;
int posl[1000], posd[1000];
point down[1000], left[1000];
point s;
char in[1000];
queue<int> q;

int cmp_left(const void *x, const void *y) {
    point *a = (point *)x, *b = (point *)y;
    if (a->x != b->x) return (a->x-b->x);
    return (a->y-b->y);    
}

int cmp_down(const void *x, const void *y) {
    point *a = (point *)x, *b = (point *)y;
    if (a->y != b->y) return (a->y-b->y);
    return (a->x-b->x);    
}

int cmp_loc(const void *x, const void *y) {
    point *a = (point *)x, *b = (point *)y;
    int d1 = sqrd(*a, s), d2 = sqrd(*b, s);
    if (d1 < d2) return -1; else if (d2 < d1) return 1;
    if (a->x != b->x) return (a->x-b->x);
    return (a->y-b->y);
}

int get_int() {

    int ch, i, sign;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    if (ch == '-') { sign = 1; ch = getchar(); } else sign = 0;

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    if (sign) return (i * -1);
    return i;
}


int main() {
    
    int i, j;
    int x, y, z, k;
    point locale[8];
    int nl;
    
    while (n = get_int()) { 
        if (!n) break;
        for (i = 0; i < n; i++) {
            x = get_int(); y = get_int();
            down[i].x = left[i].x = x; down[i].y = left[i].y = y;
            down[i].ord = left[i].ord = i;
            in[i] = 0;
        }
        if (n == 1) { puts("All stations are reachable."); continue; }
        
        qsort(down, n, sizeof(point), cmp_down);
        qsort(left, n, sizeof(point), cmp_left);
        
        for (i = 0; i < n; i++) { posd[down[i].ord] = i; posl[left[i].ord] = i; }
        
        q.push(0); nc = 1;
        in[0] = 1; 
        while (!q.empty()) {
            x = q.front(); q.pop();
            nl = 0;
            for (i = 1; i <= 2; i++) {
                if (posd[x]-i >= 0) locale[nl++] = down[posd[x]-i];
                if (posd[x]+i < n) locale[nl++] = down[posd[x]+i];
                if (posl[x]-i >= 0) locale[nl++] = left[posl[x]-i];
                if (posl[x]+i < n) locale[nl++] = left[posl[x]+i];
            }
            s = left[posl[x]];
            qsort(locale, nl, sizeof(point), cmp_loc);
            y = locale[0].ord;
            for (i = 1; i < nl; i++)
                if (y != locale[i].ord) { z = locale[i].ord; break; }
            if (!in[y]) { q.push(y); in[y] = 1; nc++; }
            if (i<n && !in[z]) { in[z] = 1; nc++; q.push(z); }
        }
        
        if (nc == n) puts("All stations are reachable.");
        else puts("There are stations that are unreachable.");

    }
    
    return 0;
}
