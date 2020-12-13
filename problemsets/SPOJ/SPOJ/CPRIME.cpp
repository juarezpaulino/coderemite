/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 100000000

int primes[6000000], npr;
int mark[65536>>4];

///////////////////////////////////////////////////////////////////////////////
// Segmented Sieve
//finds primes in each interval
void update_sieve(int seed) {
	int i, j;

	for (i = 0; i < 1024; i++) mark[i] = 0;

	// start from prime number 3 not 2
	for (i = 1; i < npr; i++)
	{
		j = primes[i] * primes[i];
		if (j >= seed+65536) break;

		// find first odd multiple of this prime[i] in this interval
		if (j < seed)
		{
			j = (seed / primes[i]) * primes[i];
			if (j < seed) j += primes[i];
			if ((j&1) == 0) j += primes[i];
		}
		// mark all multiples of this prime[i]
		for (j = (j-seed); j < 65536; j += (primes[i]<<1))
			mark[j>>6] |= (1<<((j>>1)&31));
	}
	// add primes found in this interval
	for (i = seed+1; npr < MAX && i < seed+65536; i += 2)
	{
		j = i - seed;
		if ( (mark[j>>6] & (1<<((j>>1)&31))) == 0 ) primes[npr++] = i;
	}
}

void sieve(int N) {

	int i, j;
	for (i = 3; i*i <= 65535; i += 2)
		if ((mark[i>>4] & (1<<((i>>1)&7))) == 0)
			for (j = i*i; j <= 65535; j += i<<1) mark[j>>4] |= (1<<((j>>1)&7));
	primes[npr++] = 2;
	for (i = 3; i <= 65535; i += 2)
		if ((mark[i>>4]&(1<<((i>>1)&7))) == 0) primes[npr++] = i;


	// find primes for each interval
	for (int seed = 65536; seed < N; seed += 65536) update_sieve(seed);
}

int main() {

    sieve(MAX);

    int N;
    while (1) {
        scanf("%d", &N);
        if (!N) break;
        int tot = (upper_bound(primes, primes + npr, N) - primes);
        double ret = fabs(((double)N / log(N)) - tot) / (double) tot * 100.;
        printf("%.1lf\n", ret);
    }

    return 0;
}
