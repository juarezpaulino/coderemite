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
    int h, m;
    h = N/3600; N%=3600;
    m = N/60; N%=60;
    printf("%d:%d:%d\n", h, m, N);

    return 0;
}
