/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct agency {
    string s;
    int a, b, c;
    bool operator<(const agency &B) const {
        if (c != B.c) return c < B.c;
        return s < B.s;
    }
};

agency A[110];


int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, M, L;
        scanf("%d %d %d ", &N, &M, &L);
        for (int i = 0; i < L; i++) {
            char S[20];
            scanf("%[^:]:%d,%d ", S, &A[i].a, &A[i].b);
            A[i].s = S;
            A[i].c = 0;
            int d = N;
            while (d/2 >= M) {
                int u = (d+1)/2;
                if (A[i].b > A[i].a*u) break;
                A[i].c += A[i].b;
                d /= 2;
            }
            A[i].c += (d-M)*A[i].a;
        }
        sort(A, A+L);
        printf("Case %d\n", t);
        for (int i = 0; i < L; i++) {
            printf("%s %d\n", A[i].s.c_str(), A[i].c);
        }
    }

    return 0;
}
