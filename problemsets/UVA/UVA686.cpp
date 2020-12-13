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

#define MAX (1<<16)+10

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
        if (N==4) { printf("1\n"); continue; }
        int i, ret = 0;
        for (i = 1; 2*pr[i] <= N && i < npr; i++) {
            if (!prime[((N-pr[i])-3)>>1]) ret++;
        }
        printf("%d\n", ret);
    }

    return 0;
}
