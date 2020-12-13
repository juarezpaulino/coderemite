/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

#define MAX 86029000

int primes[5000100], npr;
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

inline void print(int N) {
    char R[10];
    int k = 0;
    if (N == 0) { puts("0");return;}
    while (N) {
        R[k++] = (N%10) + '0'; N/=10;
    }
    R[k] = 0;
    for (int i = 0; i < k/2; i++) R[i]^=R[k-i-1]^=R[i]^=R[k-i-1];
    puts(R);
}

int main() {
    sieve(MAX);
    int T, k;
    for(scanf("%d",&T); T; T--) scanf("%d",&k), print(primes[k-1]);
}
