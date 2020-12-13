/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 1000001;

int FAC[MAX];

void GENPR() {
    for (int i = 2; i < MAX/2; i++) {
        if (FAC[i]==0) FAC[i] = 1;
        for (int j = 2, k = i*j; j <= i && k < MAX; j++, k+=i)
            if (FAC[k]==0 && FAC[j]==1)
                FAC[k] = FAC[i]+1;
    }
    for (int i = 2; i < MAX; i++) {
        if (FAC[i]==0) FAC[i] = 1;
        FAC[i] += FAC[i-1];
    }
}



int main() {

    GENPR();
    int N;
    while (scanf("%d", &N) != EOF) {
        printf("%d\n", FAC[N]);
    }

    return 0;
}
