/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int V[10010];

int main() {

    int K = 0;
    while (scanf("%d", V+K) != EOF) {
        for (int j = K-1; j >= 0; j--) {
            if (V[j] > V[j+1]) swap(V[j], V[j+1]);
            else break;
        }
        K++;
        if (K%2==1) printf("%d\n", V[K/2]);
        else printf("%d\n", (V[K/2]+V[K/2-1])/2);
    }

    return 0;
}
