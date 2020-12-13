/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch>='0' && ch<='9'; ch = getchar()) i = 10 * i + (ch - '0');
    return i;
}


int main() {

    int n, s, r, t;
    register int i, j, k, x;
    int p[10000], raio[10000], nr, size[10000];
    set<int> vert;
    while (n = get_int()) {
        vert.clear(); vert.insert(0); p[0] = 0;
        for (i = 1, s = 0; i <= n; i++) { p[i] = s += get_int(); vert.insert(s); }
        for (i = n, nr = 0; i > 2; i--) if (!(s%i)) raio[nr] = s/i, size[nr++] = i;
        for (k = 0; k < nr; k++) {
            r = raio[k]; t = size[k];
            for (i = 0; i <= n && p[i] < r; i++) {
                x = p[i];
                for (j = 0; j < t; j++) { x = (x+r)%s; if (!vert.count(x)) break; }
                if (j == t) goto HELL;
            }
        }
        puts("-1"); continue;
HELL:   printf("%d\n", n-t);
    }
    return 0;
}

