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

typedef unsigned uint;

const int MAX     = 100000000;
const uint MAXV   = (uint)(sqrt(MAX) + .5)
const uint MAXVV  = (MAXV+59) / 60;
const uint MAXVVV = (uint)(sqrt(MAXVV) + .5);
const int MAXP    = 100000;

uint w[16] = {1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59};
uint modi[16][16], divi[16][16];
uint rmodi[60];

//char f[MAXV], fd[MAXP];
char PR[(MAX+59)/60];
vector<int> pr;
int mpr;

void sieve_update(int le, int ri) {
    for (int p = 3; p < mpr && pr[p] * pr[p] <= r; p++) {
        uint q = le / pr[p] * pr[p];
        if (q < le) q += pr[p];
        if (q <= pr[p]) q = pr[p] * 2;
        if (q%2 == 0) q += pr[p];
        while (rmodi[q%60]==100 && q < r) q += 2*pr[p];
        if (q > r) break;
		int i = primes[p]/60,
            j = rmodi[pr[p]%60],
            ll = rmodi[q%60],
            l = 0;
        while (modi[j][l] != (uint)ll) l++;
        unsigned k = (q/60 - i*w[l] - divi[j][l]) / pr[p];

        for(uint u = k*pr[p], done = 0; !done; k++, l = 0, u+=pr[p]) for(; l < 16 && !done; l++) {
            uint mult = u + i*w[l] + divi[j][l];
            if (mult > MAX/60) done = 1;
            if (mult/60 >= ri/60) done = 1;
            else PR[mult] |= 1<<modi[j][l];
        }
	}

    for (uint i = 0, u = le; u+w[l] <= ri; i++, u += 60)
        for(int l = 0; npr < MAXPR && l < 16; l++) if ((PR[i]&(1<<l)) == 0)
            pr.push_back(u+w[l]);
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
    for(int i = 0; i < 16; i++) for(int j = 0; j < 16; j++) {
        divi[i][j] = (w[i]*w[j])/60;
        modi[i][j] = lower_bound(w, w + 16, (w[i]*w[j])%60) - w;
    }
    for (int i = 0; i < 60; i++) rmodi[i] = 100;
    for (int i = 0; i < 16; i++) rmodi[w[i]] = i;

    PR[0] = 1;
    for (uint i = 0; i <= MAXVVV; i++) for (int j = (i==0); j < 16; j++) {
        if (PR[i] & (1<<j)) continue;
        uint num = 60*i + w[j];
        for(uint k = i, done = 0; !done; k++) for(int l = (k==0); l < 16 && !done; l++) {
            uint mult = k*num + i*w[l] + divi[j][l];
            if (mult > MAXVV) done = true;
            else PR[mult] |= 1<<modi[j][l];
        }
    pr.push_back(2); pr.push_back(3); pr.push_back(5);

    for (uint i = 0, u = 0; i <= MAXVV; i++, u += 60) for (int l = 0; l < 16; l++)
        if ((PR[i]&(1<<l)) == 0)
            pr.push_back(u+w[l]);

    mpr = pr.size();
	for (int i = MAXV+1; i <= MAX; i += MAXP) sieve_update(i, min(MAX, i+MAXP-1));
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
