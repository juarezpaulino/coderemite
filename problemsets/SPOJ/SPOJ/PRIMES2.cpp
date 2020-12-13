/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 50847534;

char R[10000000]; int NR;

int primes[MAX], npr;
int mark[10000];

///////////////////////////////////////////////////////////////////////////////
// Segmented Sieve
//finds primes in each interval
void update_sieve(int seed) {
	int i, j;

	for (i = 0; i < 4000; i++) mark[i] = 0;

	// start from prime number 3 not 2
	for (i = 1; i < npr; i++)
	{
		j = primes[i] * primes[i];
		if (j >= seed+131072) break;

		// find first odd multiple of this prime[i] in this interval
		if (j < seed)
		{
			j = (seed / primes[i]) * primes[i];
			if (j < seed) j += primes[i];
			if ((j&1) == 0) j += primes[i];
		}
		// mark all multiples of this prime[i]
		for (j = (j-seed); j < 131072; j += (primes[i]<<1))
			mark[j>>6] |= (1<<((j>>1)&31));
	}
	// add primes found in this interval
	for (i = seed+1; npr < MAX && i < seed+131072; i += 2)
	{
		j = i - seed;
		if ( (mark[j>>6] & (1<<((j>>1)&31))) == 0 ) primes[npr++] = i;
	}
}

void sieve(int N) {

	int i, j;
	for (i = 3; i*i <= 131071; i += 2)
		if ((mark[i>>4] & (1<<((i>>1)&7))) == 0)
			for (j = i*i; j <= 131071; j += i<<1) mark[j>>4] |= (1<<((j>>1)&7));
	primes[npr++] = 2;
	for (i = 3; i <= 131071; i += 2)
		if ((mark[i>>4]&(1<<((i>>1)&7))) == 0) primes[npr++] = i;


	// find primes for each interval
	for (int seed = 131072; seed < N; seed += 131072) update_sieve(seed);
}


inline void print(int N) {
    int k = 0;
    while (N) {
        R[NR+k++] = (N%10) + '0'; N/=10;
    }
    R[NR+k] = '\n';
    for (int i = 0; i < k/2; i++) R[NR+i]^=R[NR+k-i-1]^=R[NR+i]^=R[NR+k-i-1];
    NR += k+1;
}

int main() {
    sieve(1000000000);
    for(int i = 0; i < npr; i+=500) print(primes[i]);
    puts(R);
}
