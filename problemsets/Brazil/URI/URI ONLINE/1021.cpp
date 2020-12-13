/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int N, M;
    scanf("%d.%d",&N,&M);
    N = N*100+M;
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", N/10000); N%=10000;
    printf("%d nota(s) de R$ 50.00\n", N/5000); N%=5000;
    printf("%d nota(s) de R$ 20.00\n", N/2000); N%=2000;
    printf("%d nota(s) de R$ 10.00\n", N/1000); N%=1000;
    printf("%d nota(s) de R$ 5.00\n", N/500); N%=500;
    printf("%d nota(s) de R$ 2.00\n", N/200); N%=200;
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", N/100); N%=100;
    printf("%d moeda(s) de R$ 0.50\n", N/50); N%=50;
    printf("%d moeda(s) de R$ 0.25\n", N/25); N%=25;
    printf("%d moeda(s) de R$ 0.10\n", N/10); N%=10;
    printf("%d moeda(s) de R$ 0.05\n", N/5); N%=5;
    printf("%d moeda(s) de R$ 0.01\n", N);

    return 0;
}
