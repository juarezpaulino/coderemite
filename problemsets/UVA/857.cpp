/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

struct note { int c, n, m, b, t, ord; };

note N[2020];

bool comp(const note &A, const note &B) {
    if (A.m != B.m) return A.m < B.m;
    if (A.b != B.b) return A.b < B.b;
    if (A.t != B.t) return A.t < B.t;
    if (A.n != B.n) return A.n < B.n;
    return A.c > B.c;
}

bool comp2(const note &A, const note &B) {
    return A.ord < B.ord;
}

int main() {

    int T;
    while (scanf("%d", &T) != EOF) {
        if (T == -1) { puts("-1"); break; }
        for (int i = 0; i < T; i++) {
            int c, n, m, b, t;
            scanf("%d %d %d %d %d", &c, &n, &m, &b, &t);
            int a = t/60*60, d = (t+59)/60*60;
            t = (t-a < d-t)?a:d;
            if (t == 480) {
                b++, t = 0;
                if (b == 5) m++, b = 1;
            }
            N[i] = (note){c,n,m,b,t,i};
        }
        sort(N, N+T, comp);
        int k = 0;
        for (int i = 0; i < T; i++) {
            if (i < T && N[i+1].c == 0 && N[i].n==N[i+1].n && N[i].m==N[i+1].m && N[i].b==N[i+1].b && N[i].t==N[i+1].t) {
                i++; continue;
            }
            N[k++] = N[i];
        }
        sort(N, N+k, comp2);
        printf("%d\n", k);
        for (int i = 0; i < k; i++)
            printf("%d %d %d %d %d\n", N[i].c, N[i].n, N[i].m, N[i].b, N[i].t);
    }

    return 0;
}
