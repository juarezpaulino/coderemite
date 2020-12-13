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

#define MAX 100

vector<bool> prime((MAX>>1)+100);
int pr[100], npr;

void sieve() {
    for(int i = 3; i <= 10; i+=2)
        if(!prime[(i-3)>>1])
            for(int j = i*i, k = i+i; j < MAX; j+=k) if(j&1)
                prime[(j-3)>>1] = 1;
    pr[npr++] = 2;
    for(int i = 0; 2*i < MAX; i++)
        if(!prime[i])
            pr[npr++] = 2*i + 3;
}


int main() {

    int N;
    sieve();
    while (scanf("%d", &N)) {
        if (!N) break;
        int k = 0;
        printf("%3d! =", N);
        while (k < npr && pr[k] <= N) {
            if (k && k%15==0) printf("\n%6c", ' ');
            int t = 0;
            for (int i = 2; i <= N; i++) {
                int j = i;
                while (j%pr[k]==0) t++, j/=pr[k];
            }
            printf("%3d", t);
            k++;
        }
        putchar('\n');
    }

    return 0;
}
