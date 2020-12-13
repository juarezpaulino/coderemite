/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int T;
    char S[1010];
    scanf("%d", &T);
    while (T--) {
        scanf("%s", S);
        int ret = 0, t = 0;
        for (int i = 0; S[i]; i++)
            if (S[i]=='O') ret += ++t;
            else t = 0;
        printf("%d\n", ret);
    }

    return 0;
}
