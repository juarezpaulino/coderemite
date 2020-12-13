/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int v[8];
        for (int i = 0; i < 8; i++) scanf("%d", v+i);
        int max1 = max(v[0], v[4]), max2 = max(v[1], v[5]);
        int min1 = min(v[2], v[6]), min2 = min(v[3], v[7]);
        if (max1 >= min1 || max2 >= min2) puts("No Overlap");
        else printf("%d %d %d %d\n", max1, max2, min1, min2);
        if (T) putchar('\n');
    }

    return 0;
}
