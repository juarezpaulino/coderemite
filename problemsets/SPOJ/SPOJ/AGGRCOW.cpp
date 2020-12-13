/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int N, C;
int V[100000];

bool check(int d) {
    int p = V[0];
    int i = 1;
    for (int c = 2; c <= C; c++) {
        while (i < N && V[i]-p < d) i++;
        if (i >= N) return false;
        p = V[i++];
    }
    return true;
}

bool comp(const int &A, const int &B) {
    return A < B;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &C);
        for (int i = 0; i < N; i++) scanf("%d", V+i);

        sort(V, V+N, comp);

        int hi = 1000000010, lo = 0, m;
        while (hi > lo+1) {
            if (hi <= lo) break;
            m = (hi+lo)/2;
            if (check(m)) lo = m;
            else hi = m;
        }
        printf("%d\n", lo);
    }

    return 0;
}
