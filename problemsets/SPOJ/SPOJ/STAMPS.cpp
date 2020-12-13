/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M;
int C[1000];

int main() {

    int id = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) scanf("%d", C+i);
        sort(C, C+M, greater<int>());
        int ret = 0;
        while (N>0 && ret<M) {
            N -= C[ret];
            ret++;
        }
        if (N <= 0) printf("Scenario #%d:\n%d\n\n", id, ret);
        else printf("Scenario #%d:\nimpossible\n\n", id);
        id++;
    }

    return 0;
}
