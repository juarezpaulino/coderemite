/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;

#define MAXN 50001

int phi[MAXN];


int main() {

    phi[0] = 1;
    for (int i=1; i<=MAXN; ++i) phi[i]=i;

    for (int i=2; i<=MAXN; ++i) if(phi[i]==i)
        for(int j=i; j<=MAXN; j+=i)
            phi[j] = phi[j] / i * (i-1);

    for (int i = 2; i <= MAXN; i++) phi[i] += phi[i-1];

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        printf("%d\n", 2*phi[N]-1);
    }

    return 0;
}
