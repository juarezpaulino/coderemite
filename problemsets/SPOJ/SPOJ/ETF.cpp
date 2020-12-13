/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define MAXN 1000001

int phi[MAXN];

int main(){

    phi[0] = 1;
    for (int i=1; i<=MAXN; ++i) phi[i]=i;

    for (int i=2; i<=MAXN; ++i) if(phi[i]==i)
        for(int j=i; j<=MAXN; j+=i)
            phi[j] = phi[j] / i * (i-1);

    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", phi[N]);
    }

}
