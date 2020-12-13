/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

char C[1010101];

int main() {

    scanf("%*d %s", C);
    int ret = 0;
    for (int i = 0; C[i]; i++) ret += (C[i]=='P')?2:(C[i]=='C')?2:(C[i]=='A')?1:0;
    printf("%d\n", ret);

    return 0;
}
