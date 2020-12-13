/* Stargates */

#include <stdio.h>
#include <ctype.h>

int n;
int color;
int yes, no;
int t[6000001];
int pt[2000000];

void define(int x) {

    int i;

    n = x;
    color = 0;
    for (i = 1; i <= n; i++) t[i] = -1;
}

void connect(int x, int y) {

    int a, b;

    if ((t[x] == -1) && (t[y] == -1)) { t[x] = t[y] = color; pt[color] = color++; }
    else if (t[x] == -1) t[x] = t[y];
    else if (t[y] == -1) t[y] = t[x];
    else if (t[x] == t[y]) return;
    else {
        a = t[x];
        while (pt[a] != a) a = pt[a];
        if (t[x] != a) t[x] = a;

        b = t[y];
        while (pt[b] != b) b = pt[b];
        if (t[y] != b) t[y] = b;

        if (a > b) { pt[b] = a; t[y] = a; }
        else { pt[a] = b; t[x] = b; }
    }
}

void check(int x, int y) {

    int a, b;

    a = t[x];
    if (a == -1) { no++; return; }
    while (pt[a] != a) a = pt[a];
    if (t[x] != a) t[x] = a;

    b = t[y];
    if (b == -1) { no++; return; }
    while (pt[b] != b) b = pt[b];
    if (t[y] != b) t[y] = b;

    if (a == b) yes++;
    else no++;
}


int main() {

    char c;
    char str[100];
    int v, w, x, y, z;
    int r;
    int i;

    n = -1;
    while (gets(str)) {
        r = sscanf(str, "%c %d %d %d %d %d", &c, &v, &w, &x, &y, &z);
        if (isupper(c)) c = c-'A'+'a';

        if (c == 'd') define(v);
        else if (c == 'c') {
            if (r == 3) connect(v, w);
            else if (r == 4) for (i = 0; i < x; i++) connect(v, (w+i)%n);
            else if (r == 5) for (i = 0; i < x; i++) connect(v, (w+(i*y))%n);
            else if (r == 6) for (i = 0; i < x; i++) connect((v+(i*z))%n, (w+(i*y))%n);
        }
        else if (c == 'q') {
            if ((n == -1) && (r == 3)) { printf("0 - 1\n"); continue; }
            if ((n == -1) && (r > 3)) { printf("0 - %d\n", x); continue; }

            yes = no = 0;
            if (r == 3) check(v, w);
            else if (r == 4) for (i = 0; i < x; i++) check(v, (w+i)%n);
            else if (r == 5) for (i = 0; i < x; i++) check(v, (w+(i*y))%n);
            else if (r == 6) for (i = 0; i < x; i++) check((v+(i*z))%n, (w+(i*y))%n);
            printf("%d - %d\n", yes, no);
        }
    }

    return 0;
}
