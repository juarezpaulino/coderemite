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
    scanf("%d %d", &N, &M);
    if (N%(M+1) == 0) puts("Carlos");
    else puts("Paula");

    return 0;
}
