/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int V[1010];
long long S[1010], T[1010];

int main() {

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        sort(V, V+N);
        for (int i = 0; i < N; i++) S[i] = 0, T[i] = 0;
        for (int i = 1; i < N; i++) {
            S[i] = S[i-1];
            for (int j = 0; j < i; j++) S[i] += abs(V[i] - V[j]);
        }
        for (int i = N-2; i >= 0; i--) {
            T[i] = T[i+1];
            for (int j = i+1; j < N; j++) T[i] += abs(V[i] - V[j]);
        }
        long long ret = S[0] + T[1];
        for (int k = 1; k < N-1; k++) {
            if (ret > S[k]+T[k+1]) ret = S[k]+T[k+1];
        }
        printf("%lld\n", ret);
    }

    return 0;
}
