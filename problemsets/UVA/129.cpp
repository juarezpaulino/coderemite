/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

using namespace std;

bool done;
char ret[501];
int N, L;

void go(int k) {
    if (k) {
        N--;
        if (!N) {
            for (int i = 0; i < k; i+=4) {
                if (i / 4 == 16) putchar('\n');
                else if (i != 0) putchar(' ');
                putchar(ret[i]);
                if (i+1 < k) putchar(ret[i+1]);
                if (i+2 < k) putchar(ret[i+2]);
                if (i+3 < k) putchar(ret[i+3]);
            }
            printf("\n%d\n", k);
            done = 1;
        }
    }
    for (int i = 0; !done && i < L; i++) {
        ret[k] = 'A'+i;
        bool ok = 1;
        for (int l = k-1; k-l <= l+1; l--) {
            bool diff = 0;
            for (int p = k, q = l; !diff && p > l; p--, q--) if (ret[p] != ret[q]) diff = 1;
            if (!diff) ok = 0;
        }
        if (ok) go(k+1);
    }
}

int main() {

    while (scanf("%d %d", &N, &L) != EOF) {
        if (!(N|L)) break;
        done = 0;
        go(0);
    }

    return 0;
}
