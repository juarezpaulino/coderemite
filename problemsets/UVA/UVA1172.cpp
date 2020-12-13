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
    int A, B;
    scanf("%d", &N);
    while (N--) {
        scanf("%d %d", &A, &B);
        if (A < B) printf("<\n");
        else if (A > B) printf(">\n");
        else printf("=\n");
    }

    return 0;
}
