/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int N, k, m;


int V[100];

void josephus(int N, int k, int m) {
    int p1 = -1, p2 = N;
    int M = N;
    for (int i = 0; i < N; i++) V[i] = i+1;
    bool f = false;
    do {
        p1 = (p1 + k) % M;
        p2 = (p2 + M*100 - m) % M;

        if (f) putchar(',');

        if (p1 == p2) {
            printf("%3d", V[p1]);

            copy(V+p1+1, V+M, V+p1);
            M--;

            if (!M) break;

            p1 = (p1 + 100*M - 1) % M;
        }
        else {
            printf("%3d%3d", V[p1], V[p2]);

            int i = min(p1, p2), j = max(p1, p2);
            copy(V+i+1, V+j, V+i);
            copy(V+j+1, V+M, V+j-1);
            M-=2;

            if (!M) break;

            if (p2 < p1) p1 = (p1 + 100*M - 1) % M;
            else p2 = (p2 + 100*M - 1) % M;
            p1 = (p1 + 100*M - 1) % M;
        }

//        for (int i = 0; i < M; i++) printf("%d ", V[i]); putchar('\n');
//        printf("%d %d\n", p1, p2);

        f = true;

    } while (1);
    printf("\n");
}


int main() {

    while (scanf("%d %d %d", &N, &k, &m)) {
        if (!(N|k|m)) break;
        josephus(N,k,m);
    }

    return 0;
}
