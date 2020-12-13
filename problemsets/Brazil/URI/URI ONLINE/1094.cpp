/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int n, p = 0, c = 0, r = 0, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        char c1;
        scanf("%d %c", &x, &c1);
        if (c1 == 'C') c += x;
        else if (c1 == 'R') r += x;
        else if (c1 == 'S') s += x;
        p += x;
    }
    printf("Total: %d cobaias\nTotal de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\nPercentual de coelhos: %.2lf %%\nPercentual de ratos: %.2lf %%\nPercentual de sapos: %.2lf %%\n", p, c, r, s, c*100./p, r*100./p, s*100./p);

    return 0;
}
