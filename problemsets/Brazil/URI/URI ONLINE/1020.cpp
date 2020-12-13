/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int N;
    scanf("%d",&N);
    printf("%d ano(s)\n", N/365); N%=365;
    printf("%d mes(es)\n", N/30); N%=30;
    printf("%d dia(s)\n", N);

    return 0;
}
