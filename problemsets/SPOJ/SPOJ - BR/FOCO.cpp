/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

pair<int,int> V[1010101];


int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            V[i] = make_pair(B, A);
        }
        sort(V, V+N);
        int ret = 1;
        int l = V[0].first;
        for (int i = 0; i < N; i++) {
            if (V[i].second <= l) continue;
            l = V[i].first;
            ret++;
        }
        printf("%d\n", ret);
    }

    return 0;
}
