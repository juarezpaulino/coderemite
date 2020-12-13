/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
///////////////////////////////////////////////////////////////////////////////
// Just perform the required multiplication in the paper to see the pattern.
//

#include <cstdio>

using namespace std;


int main() {

    int B, D, F;
    while (scanf("%d %d %d", &B, &D, &F) != EOF) {
        int s = D*F;
        int ret = 1;
        while (s != D) {
            s = (s%B)*F+s/B;
            ret++;
        }
        printf("%d\n", ret);
    }

}
