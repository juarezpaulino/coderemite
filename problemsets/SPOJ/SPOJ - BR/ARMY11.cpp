/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

int L[101010], R[101010];

int main() {

    int S, B;
    while (scanf("%d %d", &S, &B)) {
        if (!(S|B)) break;
        for (int i = 1; i <= S; i++) L[i] = i-1, R[i] = i+1;
        while (B--) {
            int l, r;
            scanf("%d %d", &l, &r);
            if (L[l] == 0) printf("* "); else printf("%d ", L[l]);
            if (R[r] == S+1) printf("*\n"); else printf("%d\n", R[r]);
            L[R[r]] = L[l];
            R[L[l]] = R[r];
        }
        printf("-\n");
    }

    return 0;
}
