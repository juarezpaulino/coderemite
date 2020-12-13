/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>


using namespace std;

int main() {

    int T = 1;
    int B;
    while (scanf("%d", &B)) {
        if (!B) break;
        printf("Output for data set %d, %d bytes:\n", T++, B);
        int b = 0;
        int k = 0;
        while (b < B) {
            int l = 0;
            int i;
            for (i = 0; b < B && i < 5; i++) {
                int x;
                scanf("%d", &x);
                b += x;
                l += x;
                k++;
            }
            if (i < 5) break;
            if (l == 0) {
                puts("   Time remaining: stalled");
            }
            else {
                double u = (B-b)/(l/5.);
                int r = (int)(u+1.-1E-8);
                printf("   Time remaining: %d seconds\n", r);
            }
        }
        printf("Total time: %d seconds\n\n", k);
    }

    return 0;
}
