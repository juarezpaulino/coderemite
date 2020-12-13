/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define MAX 1000000

vector<bool> prime((MAX>>1)+100);
int pr[500000], npr;

void sieve() {
    for(int i = 3; i <= 1000; i+=2)
        if(!prime[(i-3)>>1])
            for(int j = i*i, k = i+i; j < MAX; j+=k) if(j&1)
                prime[(j-3)>>1] = 1;
    pr[npr++] = 2;
    for(int i = 0; 2*i < MAX; i++)
        if(!prime[i])
            pr[npr++] = 2*i + 3;
}

int main() {

    sieve();

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        int i;
        for (i = 1; pr[i] < N && i < npr; i++) {
            if (!prime[((N-pr[i])-3)>>1]) {
                printf("%d = %d + %d\n", N, pr[i], N-pr[i]);
                break;
            }
        }
        if (i == npr) puts("Goldbach's conjecture is wrong.");
    }

    return 0;
}
