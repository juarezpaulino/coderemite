/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>


using namespace std;

typedef pair<int,int> PII;

int main() {

    PII V[100];
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:", t);
        int N, T = 0, x;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &x), T+=x, V[i] = PII(x,i);
        sort(V, V+N);
        for (int i = N-1; i >= 0; i--) {
            x = (i > 0) ? V[i-1].first : 0;
            while (V[i].first > x) {
                int j = i;
                if ((N-j)%2) printf(" %c", 'A'+V[j].second), V[j].first--, j++;
                for (; j < N; j+=2)
                    printf(" %c%c", 'A'+V[j].second, 'A'+V[j+1].second), V[j].first--, V[j+1].first--;
            }
        }
        putchar('\n');
    }

    return 0;
}
