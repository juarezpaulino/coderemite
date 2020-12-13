/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>

using namespace std;

int I[1010];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int ret = 0;
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            char S[100];
            scanf("%s", S);
            if (S == string("LEFT")) { I[i] = -1; ret--; }
            else if (S == string("RIGHT")) { I[i] = 1; ret++; }
            else {
                int j;
                scanf("%*s %d", &j);
                I[i] = I[j];
                ret += I[i];
            }
        }
        printf("%d\n", ret);
    }

    return 0;
}
