/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int t, n, I[11];
double total, x[11], h[11], r[11], R[11];

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


double dh(int i, int j) {
    if (r[i] > R[j]) return h[j];
    else if (R[i] <= r[j]) return 0;
    else return
        max ( r[i] > r[j] ? (r[i]-r[j]) * h[j] / (R[j]-r[j]) : 0,
              R[i] < R[j] ? (R[i]-r[j]) * h[j] / (R[j]-r[j]) - h[i] :
              R[i] > r[i] ? h[j] - (R[j]-r[i]) * h[i] / (R[i]-r[i]) : 0
        );
}

double H() {
    int i, j;
    double pt;
    for (pt = i = 0; i < n && pt < total; ++i) {
        x[i] = 0;
        for (j = 0; j < i; ++j) x[i] = max(x[i],x[j]) + dh(I[i], I[j]);
        pt = max(pt, x[i]+h[I[i]]);
    }
    return pt;
}


int main() {
    int i;
    t = get_int();
    while (t--) {
        n = get_int(); total = 1E99;
        for (i = 0; i < n; ++i) I[i] = i, h[i] = get_int(), r[i] = get_int(), R[i] = get_int();
        do total = min(total,H()); while (next_permutation(I, I+n));
        printf("%d\n", (int)total);
    }
    return 0;
}
