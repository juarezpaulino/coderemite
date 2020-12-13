/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <set>

using namespace std;

int main() {

    int V[101];
    int N;
    int id = 1;
    while (scanf("%d", &N) != EOF) {
        bool ok = 1;
        for (int i = 0; i < N; i++) {
            scanf("%d", V+i);
            if (V[i] < 1) ok = 0;
            if (i && V[i] <= V[i-1]) ok = 0;
        }
        set<int> S;
        for (int i = 0; ok && i < N; i++) for (int j = i; ok && j < N; j++) {
            if (S.count(V[i]+V[j])) ok = 0;
            else S.insert(V[i]+V[j]);
        }
        if (ok) printf("Case #%d: It is a B2-Sequence.\n\n", id++);
        else printf("Case #%d: It is not a B2-Sequence.\n\n", id++);
    }

    return 0;
}
