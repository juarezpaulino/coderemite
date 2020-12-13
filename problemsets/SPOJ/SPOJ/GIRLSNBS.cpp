/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>


using namespace std;

int G, B;

bool check(int k) {
    int a = min(G,B), b = max(G,B);
    return (b-1)/k <= a;
}

int main() {

    while (1) {
        scanf("%d%d", &G, &B);
        if (G == -1 || B == -1) break;
        int lo = 0, hi = max(G,B), m;
        while (lo+1 < hi) {
            m = (hi+lo)/2;
            if (check(m)) hi = m;
            else lo = m;
        }
        printf("%d\n", hi);
    }

    return 0;
}
