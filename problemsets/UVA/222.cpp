/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;


int N;
double P[60];
double D[60];
double cap, aut;
double s, ret;

void go(int k, double c, double tot) {
    if (k == N+1) { ret = min(ret, tot); return; }

    if (k == 0) tot += s, c = cap;
    else tot += P[k]*(cap-c)/100. + 2., c = cap;

    for (int i = k+1; i <= N+1; i++) {
        c -= (D[i]-D[i-1])*aut;
        if (c < 1E-10) break;
        if (i == N+1 || c < cap/2.+1E-10 || (i+1 < N+1 && c-(D[i+1]-D[i])*aut < 1E-10))
            go(i,c,tot);
    }
}

int main() {

    double d;
    int id = 1;
    while (scanf("%lf", &d)!=EOF) {
        if (d < 0) break;
        scanf("%lf %lf %lf %d", &cap, &aut, &s, &N);
        aut = 1./aut;
        D[N+1] = d;
        for (int i = 1; i <= N; i++) scanf("%lf %lf", &D[i], &P[i]);

        ret = 1E10; go(0, 0, 0);
        printf("Data Set #%d\nminimum cost = $%.2lf\n", id++, ret);
    }

    return 0;
}
