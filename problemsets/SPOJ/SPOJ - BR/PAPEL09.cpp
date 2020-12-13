/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int C, P, F;
    scanf("%d %d %d", &C, &P, &F);
    if (P >= C*F) puts("S");
    else puts("N");

    return 0;
}
