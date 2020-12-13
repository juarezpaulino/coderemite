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
    scanf("%d", &N);
    if (N <= 0) puts("E");
    else if (N <= 35) puts("D");
    else if (N <= 60) puts("C");
    else if (N <= 85) puts("B");
    else if (N <= 100) puts("A");


    return 0;
}
