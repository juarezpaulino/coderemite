/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    int N, M, V[10101];
    while (scanf("%d", &N) != EOF) {
        map<int, int> S;
        for (int i = 0; i < N; i++) scanf("%d", V+i), S[V[i]]++;
        scanf("%d", &M);
        int a = 0, b = 1010101010;
        for (int i = 0; i < N; i++) {
            if (S.count(M-V[i])) {
                if (V[i]==M-V[i] && S[V[i]]==1) continue;
                if (abs(2*V[i]-M) < b-a) a = min(V[i], M-V[i]), b = max(V[i], M-V[i]);
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }

    return 0;
}
