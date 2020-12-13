/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MAX        = 100000000;
const unsigned MAXV  = (unsigned)sqrt(MAX)+.5;
const int MAXP       = 100000;

//char f[MAXV], fd[MAXP];
char PR[(MAX+63)>>6];
vector<int> pr;
int mpr;

inline void setbit(int v) { PR[v>>6] |= 1<<(v/2&31); }
inline int getbit(int v) { return PR[v>>6]&(1<<(v/2&31)); }

void sieve_update(int l, int r) {
//    memset(fd, 0, sizeof(fd));

    for (int i = 1; i < mpr && pr[i] * pr[i] <= r; i++) {
        int j = l / pr[i] * pr[i];
        if (j < l) j += pr[i];
        if (j <= pr[i]) j = pr[i] * 2;
        if (j%2 == 0) j += pr[i];
        for (int k = 2 * pr[i]; j <= r; j += k)
//          fd[j-l] = 1;
            setbit(j);
    }

    int i = l;
    if (i%2 == 0) i++;
    for (; i <= r; i += 2)
//      if (!fd[i-l]) pr.push_back(i);
        if (!getbit(i)) pr.push_back(i);
}

void sieve() {
    for (int i = 3; i*i <= MAXV; i+=2)
//      if (!f[i])
        if (!getbit(i))
            for (int j = i*i, k = 2*i; j <= MAXV; j+=k)
//              f[j] = 1;
                setbit(j);

    pr.push_back(2);
    for (int i = 3; i <= MAXV; i+=2)
//      if (!f[i])
        if (!getbit(i))
            pr.push_back(i);

    mpr = pr.size();
    for (int i = MAXV + 1; i <= MAX; i+=MAXP) sieve_update(i, min(MAX, i+MAXP-1));
}

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    if (ch == EOF) exit(0);
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {

    sieve();
    int N;
    while (N = get_int()) {
        if (N < 5) printf("%d is not the sum of two primes!\n", N);
        else if (N%2) {
            if (!getbit(N-2)) printf("%d is the sum of 2 and %d.\n", N, N-2);
            else printf("%d is not the sum of two primes!\n", N);
        }
        else {
            bool ok = 0;
            int i = lower_bound(pr.begin(), pr.end(), N/2) - pr.begin() - 1;
            for (; i > 0; i--)
                if (!getbit(N-pr[i])) {
                    printf("%d is the sum of %d and %d.\n", N, pr[i], N-pr[i]);
                    ok = 1;
                    break;
                }
            if (!ok) printf("%d is not the sum of two primes!\n", N);
        }
    }

    return 0;
}
