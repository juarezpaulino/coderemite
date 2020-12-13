/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int n = 0;
    int x, y;
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    while (scanf("%d %d", &x, &y)) {
        n++;
        a += x;
        b += y;
        if (x > y) c++;
        else if (y > x) d++;
        else e++;
        puts("Novo grenal (1-sim 2-nao)");
        scanf("%d", &x);
        if (x == 1) continue;
        else if (x == 2) break;
    }
    printf("%d grenais\n", n);
    printf("Inter:%d\n", c);
    printf("Gremio:%d\n", d);
    printf("Empates:%d\n", e);
    if (c > d) printf("Inter venceu mais\n");
    else if (d > c) printf("Gremio venceu mais\n");
    else printf("Nao houve vencedor\n");

    return 0;
}
