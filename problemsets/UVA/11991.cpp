/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>

using namespace std;

int U[1010101];

int main() {

    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {
        for (int i = 1; i <= 1000000; i++) U[i] = 1;
        map<pair<int,int>, int> mapa;
        int k, v;
        for (int i = 0; i < N; i++) {
            scanf("%d", &v);
            mapa[make_pair(U[v],v)] = i+1;
            U[v]++;
        }
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &k, &v);
            if (mapa.count(make_pair(k,v)))
                printf("%d\n", mapa[make_pair(k,v)]);
            else printf("0\n");
        }
    }

    return 0;
}
