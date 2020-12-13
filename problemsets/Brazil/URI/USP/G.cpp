/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;

int hyper[2010102];
int count[2010102];

int main() {

    for (int i = 0; i < 2010101; i++) hyper[i] = 1;

    for (int i=2; i<=2010101; i++)
        if(hyper[i] == 1)
            for (int j=2*i; j<=2010101; j+=i ) {
                int c = 0;
                for (int x = j; x%i == 0 ;  x/=i ) c++;
                hyper[j] *= (c+1);
            }

    count[0] = count[1] = 0;
    for (int i = 2; i <= 2010101; i++)
        count[i] = count[i-1] + ((hyper[i] == 1 || hyper[ hyper[i] ] == 1) ? 1 : 0);


    int N;
    while (scanf("%d", &N) != EOF) {
        printf("%d\n", count[N]);
    }

    return 0;
}
