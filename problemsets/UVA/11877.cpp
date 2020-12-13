/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        if (!N) break;
        printf("%d\n", (N-1)/2 + (N%2==0));
    }

    return 0;
}
