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

    int N, M;
    while (scanf("%d %d", &N, &M) && (N || M)) {
        set<int> mapa;
        for (int i = 0; i < N; i++) {
            int x; scanf("%d", &x);
            mapa.insert(x);
        }
        int ret = 0;
        for (int i = 0; i < M; i++) {
            int x; scanf("%d", &x);
            if (mapa.count(x)) ret++;
        }
        printf("%d\n", ret);
    }

    return 0;
}
