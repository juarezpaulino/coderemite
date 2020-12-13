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

    int T, A, F;
    scanf("%d", &T);
    while (T--) {

        scanf("%d %d", &A, &F);

        for (int k = 0; k < F; k++) {
            for (int i = 1; i <= A; i++) {
                for (int j = 0; j < i; j++) printf("%d", i);
                putchar('\n');
            }
            for (int i = A-1; i >= 1; i--) {
                for (int j = 0; j < i; j++) printf("%d", i);
                putchar('\n');
            }
            if (k < F-1) putchar('\n');
        }

        if (T) putchar('\n');
    }

    return 0;
}
